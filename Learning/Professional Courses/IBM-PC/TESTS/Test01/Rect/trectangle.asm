CODES SEGMENT
    ASSUME CS:CODES
START:
    mov ch, 4
    ;<---add--->
    mov bl,20h
    ;<--------->
next:
    ;Êä³öµÄÑ­»·
    mov dl, bl
    mo ah,2
    int 21h
    ;<---add--->
    add bl,1
    ;<--------->
    sub ch,1
    jnz next
    MOV AH,4CH
    INT 21H
CODES ENDS
    END START
