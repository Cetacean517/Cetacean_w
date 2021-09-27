DATA SEGMENT
	mess db 'Your Hex number is:$'
	bb db 00110100b, 00010010b
DATA ENDS
CODES SEGMENT
    ASSUME CS:CODES, DS:DATA	;代码段和数据段的名字不一定一定是DATA
START:
	mov ax, DATA
	mov ds, ax
	lea dx, mess
	mov ah, 9
	int 21h
	
    MOV AH,4CH
    INT 21H
CODES ENDS
    END START
