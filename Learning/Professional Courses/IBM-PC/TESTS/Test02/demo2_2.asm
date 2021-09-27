DATA SEGMENT
	;������mess db 'abcde1234%%^&*',10,13,'12$' ;10,13��ʾ�������,�ַ�����$Ϊ��β
	;mess 		db 'abcde1234%%^&*$' ;10,13��ʾ�������,�ַ�����$Ϊ��β
	;һЩ�����ʾ
	input		db 'input a line:$'
	crlf		db 10,13,'$'
	letter_n 	db 'letterNum:$'
	digit_n 	db 'digitNum:$'
	other_n 	db 'signNum:$'
	
	;������ַ���
	mess		db 0ffh
	line               db  0, 100h  dup(?)
	
	;����һЩ������
	letter_count       db  0
	digit_count        db  0
	other_count        db  0
	
	output_letter_count       db 0dh,0ah,'letter count:$'
DATA ENDS
CODES SEGMENT
    ASSUME CS:CODES, DS:DATA	;����κ����ݶε����ֲ�һ��һ����DATA
START:
;���ݳ�ʼ������0h �����ջ
   push ds
   mov ax,0h
   push ax
   mov ax,DATA          ;��ʼ��ds
   mov ds,ax
   
; ���룬����һ���ַ���ʾ
   lea dx,input
   mov ah,9
   int 21h
   ;����һ���ַ�
   lea dx,mess
   mov ah,10 
   int 21h
	;����ͳ��
	;1. ��������
	mov si,0	;���������±�Ҫ��si
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
	and al,11011111b	;���ַ���ת��Ϊ��д�ַ�
	cmp al, 'A'
	jb other
	cmp al, 'Z'
	ja other
	inc letter_count
	jmp next

other:
	inc other_count ;otherͳ������1
	;������

next: 
	inc si
	dec ah
	jnz read	;û���꣬������
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


