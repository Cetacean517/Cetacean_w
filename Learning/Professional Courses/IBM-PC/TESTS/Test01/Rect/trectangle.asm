;AscTran
CODES SEGMENT
    ASSUME CS:CODES
START:
    mov ch, 128
    mov bl, 10h ;ASCII的起始值
    mov bh, 10h ;每行输出的个数 16个，用十六进制表示
    mov dh, 1	;空格数的基数
    mov cl, 1

next:
    ;输出的循环
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
    cmp cl,0h; 如果大于0，则跳转
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


