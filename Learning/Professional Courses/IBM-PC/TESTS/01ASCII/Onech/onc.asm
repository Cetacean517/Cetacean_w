DATAS SEGMENT
    ;�˴��������ݶδ���  
DATAS ENDS

STACKS SEGMENT
    ;�˴������ջ�δ���
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,SS:STACKS
START:
	;push ds
	;sub ax, ax
	;push ax
	mov ch, 10h ; ����ѭ����λ��
	mov dh, 15	; ����ѭ��������
	mov bl, 10h ;
	;ASCII ��ӡ���������ͷ
	;mov dl, 1Bh
	;mov ah, 2
	;int 21h
	;call endloop
	call printit
newline:
	dec dh
	mov dl, 0Ah
	mov ah,2
	int 21h
	mov ch, 16
	jnz printit
	call endloop
	
printit:
	mov dl, bl	;���bl
	mov ah,2
	int 21h
	mov dl, 20h	;����ո�
	mov ah,2
	int 21h
	add bl, 1	;bl+1
	sub ch, 1
	jnz printit
	call newline;ѭ�����16�����������
endloop:
	mov ah, 4ch	; ��������������return
	int 21h
CODES ENDS
    END START




