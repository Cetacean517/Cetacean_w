DATAS SEGMENT
    KEY	LABEL BYTE
	MAX2 DB 80
	ACT2 DB ?
	STOKN2 DB 80 DUP(?)	  
DATAS ENDS

STACKS SEGMENT
    ;�˴������ջ�δ���
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,SS:STACKS
START:
    MOV AX,DATAS
    MOV DS,AX
    
    MOV AH,01
    INT 21H
    
    MOV AH,0AH
    INT 21H
    
    LEA DX,ACT2
    MOV AH,09H
    INT 21H
    
    MOV AH,4CH
    INT 21H
CODES ENDS
    END START


