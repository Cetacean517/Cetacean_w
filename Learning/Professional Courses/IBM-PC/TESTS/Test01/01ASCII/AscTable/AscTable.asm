;AscTable
CODES SEGMENT
    ASSUME CS:CODES
START:
    mov ch, 120
    mov bl, 10h ;ASCII����ʼֵ
    mov dh, 1
    mov bh, 01h ;ÿ������ĸ��� 16������ʮ�����Ʊ�ʾ
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
    add dh,1
    mov bh,dh
    ;
skip:
    sub ch,1
    jnz next

    MOV AH,4CH
    INT 21H
CODES ENDS
    END START

