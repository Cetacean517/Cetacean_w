DATA SEGMENT
	;样例：mess db 'abcde1234%%^&*',10,13,'12$' ;10,13表示输出换行,字符串以$为结尾
	mess db 'abcde1234%%^&*$' ;10,13表示输出换行,字符串以$为结尾
	crlf db 10,13,'$'
	letter_n db 'letterNum:$'
	digit_n db 'digitNum:$'
	other_n db 'signNum:$'
	;设置一些存取数据逇值
	letter_count       db  0
	digit_count        db  0
	other_count        db  0
	;bb db 00110100b, 00010010b
	output_letter_count       db 0dh,0ah,'letter count:$'
DATA ENDS
CODES SEGMENT
    ASSUME CS:CODES, DS:DATA	;代码段和数据段的名字不一定一定是DATA
START:
	mov ax, DATA
	mov ds, ax
	;输出输入字符串
	lea dx, mess
	mov ah, 9
	int 21h
	lea dx, crlf
	mov ah, 9
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


