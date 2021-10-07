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

	line        db  80	;Ԥ����80�ֽڵĿռ�
				db  ?	;��������ɺ��Զ����������ַ�����
				db  80 dup(?)
	
	len  equ  $ - line	;��ȡ�ַ����ĳ���
	
	;����һЩ������
	letter_count       db  ?
	digit_count        db  ?
	other_count        db  ?
	
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
   mov letter_count,0
   mov digit_count,0
   mov other_count,0
 
; ���룬����һ���ַ���ʾ
   lea dx,input
   mov ah,9
   int 21h
;����һ���ַ�
   lea dx,line
   mov ah,10 
   int 21h
;����ͳ��
;1. ��������
	mov si,2	;���������±�Ҫ��si
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
	and al,11011111b	;���ַ���ת��Ϊ��д�ַ�
	cmp al, 'A'
	jb other
	cmp al, 'Z'
	ja other
	add letter_count,1
	jmp next

other:
	add other_count,1 ;otherͳ������1
	;������

next: 
	add si,1
	sub ah,1
	dec cl
	cmp cl,0
	jz break
	jnz read	;û���꣬������

break:
	;���������ַ���
	LEA DX, crlf                         ;��ȡһ��                  
    MOV AH, 09H							 
    INT 21H
    MOV AL, line+1                     ;���ַ������д���
    ADD AL, 2
    MOV AH, 0
    MOV SI, AX
    MOV line[SI], '$'
    LEA DX, crlf                        ;��ȡһ��                   
    MOV AH, 09H
    LEA DX, line+2                     ;���������ַ���
    MOV AH, 09H							 
    INT 21H
    LEA DX, crlf                         ;��ȡһ��                  
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
    LEA DX, crlf                         ;��ȡһ��                  
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

disp:                 ;ʮ��������ʽ��ʾAL�е�����.
       mov  ah, 0
       mov  bl, 10
       div  bl        ;div �޷���:div src 16λ����:��ax=(dx,ax)/src,����dx
       add  al, 30h    ;����˵al=15h,��21����ʾletter������Ȼ��������̾��ǣ�ax=0015h(21),����bl��blֵΪ10
       mov  dl, al      ;������˵Ľ��Ϊ2��1����ah=01,al=02,��ax=0102h;,��ôal+30h��Ϊ��ʾ�����ֵ�ASCII��ֵ����Ϊ0��ASCIIֵΪ30h
       mov  bh, ah       ;��ax=0132h,dl=32,bh=01;
       mov  ah, 02h      ;��ʾ���dx,����ʾ32���Ӧ�����֣�2
       int  21h           
       mov  al, bh        ;��01��al,Ȼ�����ASCII�룬Ȼ���dx��Ȼ����ʾ
       add  al, 30h
       mov  dl, al        ;����B�� 8λ��16λ���֣�������һ��reg�Ĵ����� �����ڴ浥Ԫ�С�
 
                          ;������A Ĭ�ϴ����AX�У�16λ���ڣ� �� AX��DX�У�32λ��DX��Ÿ�16λ��AX��ŵ�16λ��
 
                          ;����� �������B��8λ����ô�����Ľ��AL�����̣�AH����������
                          ;�������B��16λ����ô�����Ľ�� AX�����̣�DX����������
       mov  ah, 02h
       int  21h     
       ret

CODES ENDS
    END START









