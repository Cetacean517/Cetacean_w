;AscTran
CODES SEGMENT
    ASSUME CS:CODES
START:
    mov ch, 128
    mov bl, 10h ;ASCII����ʼֵ
    mov bh, 10h ;ÿ������ĸ��� 16������ʮ�����Ʊ�ʾ
    mov dh, 1	;�ո����Ļ���
    mov cl, 1

next:
    ;�����ѭ��
    mov dl, bl
    mov ah,2
    int 21h
    ;
    add bl,1
    sub bh,1
    jnz skip
    ;
    mov dl,10
    mov ah,2
    int 21h
    ;
    mov dl,13
    mov ah,2
    int 21h
    ;
    add dh,1
    mov bh,10h
    mov cl,dh
    cmp cl,0h; �������0������ת
    ja blank
blank:
	sub cl,1
	mov dl, 20h
	mov ah,2
	int 21h
	jnz blank
	jz next
skip:
    sub ch,1
    jnz next

    MOV AH,4CH
    INT 21H
CODES ENDS
    END START


