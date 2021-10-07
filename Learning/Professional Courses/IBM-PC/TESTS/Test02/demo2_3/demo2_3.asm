DATA SEGMENT
	;样例：mess db 'abcde1234%%^&*',10,13,'12$' ;10,13表示输出换行,字符串以$为结尾
	;mess 		db 'abcde1234%%^&*$' ;10,13表示输出换行,字符串以$为结尾
	;一些输出提示
	input		db 'input a line:$'
	crlf		db 10,13,'$'
	letter_n 	db 'letterNum:$'
	digit_n 	db 'digitNum:$'
	other_n 	db 'signNum:$'
	
	;输入的字符串

	line        db  80	;预定义80字节的空间
				db  ?	;待输入完成后，自动获得输入的字符个数
				db  80 dup(?)
	
	len  equ  $ - line	;获取字符串的长度
	
	;设置一些计数器
	letter_count       db  ?
	digit_count        db  ?
	other_count        db  ?
	
DATA ENDS
CODES SEGMENT
    ASSUME CS:CODES, DS:DATA	;代码段和数据段的名字不一定一定是DATA
START:
;数据初始化，把0h 放入堆栈
   push ds
   mov ax,0h
   push ax
   mov ax,DATA          ;初始化ds
   mov ds,ax
   mov letter_count,0
   mov digit_count,0
   mov other_count,0
 
; 输入，输入一行字符提示
   lea dx,input
   mov ah,9
   int 21h
;输入一行字符
   lea dx,line
   mov ah,10 
   int 21h
;数据统计
;1. 读入数据
	mov si,2	;存放数组的下标要用si
	mov cl, [line+1]
	mov ah, len
	
read:
	mov al, line[si]
	cmp al, '0'
	jb other
	cmp al, '9'
	ja letterOrdigit
	add digit_count,1
	jmp next
	
letterOrdigit:
	and al,11011111b	;将字符串转换为大写字符
	cmp al, 'A'
	jb other
	cmp al, 'Z'
	ja other
	add letter_count,1
	jmp next

other:
	add other_count,1 ;other统计器加1
	;输出结果

next: 
	add si,1
	sub ah,1
	dec cl
	cmp cl,0
	jz break
	jnz read	;没读完，继续读

break:
	;输出输入的字符串
	LEA DX, crlf                         ;另取一行                  
    MOV AH, 09H							 
    INT 21H
    MOV AL, line+1                     ;对字符串进行处理
    ADD AL, 2
    MOV AH, 0
    MOV SI, AX
    MOV line[SI], '$'
    LEA DX, crlf                        ;另取一行                   
    MOV AH, 09H
    LEA DX, line+2                     ;输出输入的字符串
    MOV AH, 09H							 
    INT 21H
    LEA DX, crlf                         ;另取一行                  
    MOV AH, 09H							 
    INT 21H
;
	lea dx, crlf
	mov ah, 9
	int 21h
	lea dx, letter_n
	mov ah, 9
	int 21h
	lea dx, letter_count
	mov al, letter_count
	call disp
	lea dx, crlf
	mov ah, 9
	int 21h
	;
	lea dx, digit_n
	mov ah, 9
	int 21h
	lea dx, digit_count
	mov al, digit_count
	call disp
    LEA DX, crlf                         ;另取一行                  
    MOV AH, 09H							 
    INT 21H
;
	lea dx, other_n
	mov ah, 9
	int 21h
	lea dx, other_count
	mov al, other_count
	call disp
	lea dx, crlf
	mov ah, 9
	int 21h

exit:
    MOV AH,4CH
    INT 21H

disp:                 ;十进制数形式显示AL中的内容.
       mov  ah, 0
       mov  bl, 10
       div  bl        ;div 无符号:div src 16位操作:商ax=(dx,ax)/src,余数dx
       add  al, 30h    ;比如说al=15h,即21，表示letter数量，然后，这个过程就是，ax=0015h(21),除以bl，bl值为10
       mov  dl, al      ;则除完了的结果为2余1，则ah=01,al=02,即ax=0102h;,那么al+30h即为表示该数字的ASCII码值，因为0的ASCII值为30h
       mov  bh, ah       ;则ax=0132h,dl=32,bh=01;
       mov  ah, 02h      ;显示输出dx,则显示32码对应的数字，2
       int  21h           
       mov  al, bh        ;把01给al,然后算出ASCII码，然后给dx，然后显示
       add  al, 30h
       mov  dl, al        ;除数B有 8位和16位两种，保存在一个reg寄存器里 或是内存单元中。
 
                          ;被除数A 默认存放在AX中（16位以内） 或 AX和DX中（32位，DX存放高16位，AX存放低16位）
 
                          ;结果： 如果除数B是8位，那么除法的结果AL保存商，AH保存余数，
                          ;如果除数B是16位，那么除法的结果 AX保存商，DX保存余数。
       mov  ah, 02h
       int  21h     
       ret

CODES ENDS
    END START









