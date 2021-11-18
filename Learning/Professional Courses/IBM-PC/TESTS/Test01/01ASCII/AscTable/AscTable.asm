;AscTable
CODES SEGMENT
    ASSUME CS:CODES
START:
    mov ch, 120
    mov bl, 10h ;ASCII的起始值
    mov dh, 1
    mov bh, 01h ;每行输出的个数 16个，用十六进制表示
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

