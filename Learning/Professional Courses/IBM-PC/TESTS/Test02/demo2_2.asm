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
	mess		db 0ffh
	line               db  0, 100h  dup(?)
	
	;设置一些计数器
	letter_count       db  0
	digit_count        db  0
	other_count        db  0
	
	output_letter_count       db 0dh,0ah,'letter count:$'
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
   
; 输入，输入一行字符提示
   lea dx,input
   mov ah,9
   int 21h
   ;输入一行字符
   lea dx,mess
   mov ah,10 
   int 21h
	;数据统计
	;1. 读入数据
	mov si,0	;存放数组的下标要用si
	mov ah, 14
	
read:
	mov al, mess[si]
	cmp al, '0'
	jb other
	cmp al, '9'
	ja letterOrdigit
	inc digit_count
	jmp next
	
letterOrdigit:
	and al,11011111b	;将字符串转换为大写字符
	cmp al, 'A'
	jb other
	cmp al, 'Z'
	ja other
	inc letter_count
	jmp next

other:
	inc other_count ;other统计器加1
	;输出结果

next: 
	inc si
	dec ah
	jnz read	;没读完，继续读
break:
	lea dx, letter_n
	mov ah, 9
	int 21h
	add letter_count, 30h
	mov dl, letter_count
	mov ah, 2
	int 21h
	lea dx, crlf
	mov ah, 9
	int 21h
	;
	lea dx, digit_n
	mov ah, 9
	int 21h
	add digit_count, 30h
	mov dl, digit_count
	mov ah, 2
	int 21h
	lea dx, crlf
	mov ah, 9
	int 21h
	;
	lea dx, other_n
	mov ah, 9
	int 21h
	add other_count, 30h
	mov dl, other_count
	mov ah, 2
	int 21h
	lea dx, crlf
	mov ah, 9
	int 21h
	
    MOV AH,4CH
    INT 21H
CODES ENDS
    END START


