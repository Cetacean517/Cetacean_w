DATAS SEGMENT
    SENTENCE DB 13,10,'Enter Sentence:','$'
    KEYWORD DB 13,10,'Enter Keyword:','$'
    ERROR DB 13,10,'Input error!','$'
    
    ; LABELαָ����������ñ����������ڴ�λ��
    BUFFER LABEL BYTE
    	   MAX1 DB 80	;��󳤶�
    	   ACT1 DB ?	;ʵ�����볤��
    	   STOKN1 DB 80 DUP(?)	;�ռ�Ĵ���
    	   
    KEY	LABEL BYTE
    	MAX2 DB 80
    	ACT2 DB ?
    	STOKN2 DB 80 DUP(?)	 
    
    TEMP LABEL BYTE
    	MAX3 DB 80
    	ACT3 DB ?
    	STOKN3 DB 80 DUP(?)
    	
    DIVIDING_LINE_1 DB 13,10,'++++++++++++++++++++++++++++++++++',13,10,'$'	;�˴��ָ���
    DIVIDING_LINE_2 DB 13,10,'----------------------------------','$'	;�˴��ָ���
   	
    ASK_1 DB 13,10,'Whether to perform string matching?','$'
    ASK_2 DB 13,10,'Please input Y/N:','$'
    
    
    MATCH  DB 13,10,'Match Successfully!','$'
    NOMATCH DB 13,10,'Failed.No Match','$'
    LOCATION_1 DB 13,10,'Match location at:','$'
    RESULT DB 13,10,'The content of the new string is:','$'
    CRLF DB 13,10,'$'
    CHAR DB '$'
DATAS ENDS

STACKS SEGMENT
    ;�˴������ջ�δ���
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,SS:STACKS,ES:DATAS
START:
    MOV AX,DATAS
    MOV DS,AX
    MOV ES,AX
    
    LEA DX,DIVIDING_LINE_1		;�س�����
   	MOV AH,09H
   	INT 21H
   	
    LEA DX,ASK_1
   	MOV AH,09H
   	INT 21H
    
    LEA DX,ASK_2
   	MOV AH,09H
   	INT 21H
   	
   	MOV AH,01H			;���ô����Եļ�������
   	INT 21H
   	   	
   	CMP AL,'Y'
   	JE BEGIN_1
   	
   	CMP AL,'N'
   	JE END_0
   	JNE ERROR_1
   	
BEGIN_1:
   	LEA DX,SENTENCE	;��ʾ����
   	MOV AH,09H
   	INT 21H
   	
   	MOV AH, 8
	INT 33
	
   	
   	LEA DX,BUFFER	;�����ַ���
   	MOV AH,0AH
   	INT 21H
   	 
   	LEA DX,KEYWORD	;��ʾ����
   	MOV AH,09H
   	INT 21H
   	
   	LEA DX,KEY		;����ؼ���
   	MOV AH,0AH
   	INT 21H
   	
   	LEA DX,DIVIDING_LINE_2		;�س�����
   	MOV AH,09H
   	INT 21H
   	
   	MOV CL,ACT2		;CL��Źؼ��ֳ���
   	
   	MOV AH,ACT1
   	SUB AH,CL
   	JB ERROR_1		;�ַ�������С�ڹؼ��ֳ��ȣ�ֱ��error
   	
   	MOV DH,AH		;�ַ������ȼ��ؼ��ֳ�����Ϊѭ������
   	ADD DH,1
   	
   	LEA DI,STOKN1	;��ʼ��DI,Ϊ�ַ���ָ��
   	LEA SI,STOKN2	;��ʼ��SI,Ϊ�ؼ���ָ��
	MOV BX,0		;��ʼ���ַ���ƫ����

CMP_SEG:
	CLD				;����SI,DI�ƶ�����Ϊ+1
   	REPZ CMPSB		;�Ƚ��ַ����͹ؼ���
   	JZ MATCH_1		;ƥ��ɹ�,��ת��MATCH_1
   	JNZ LOOP_1		;ƥ��ʧ�ܣ�ѭ������ƥ��
   	
LOOP_1:
	INC BX			;�ַ���ƫ����
	LEA DI,STOKN1	;����DI
   	LEA SI,STOKN2	;����SI
   	MOV CL,ACT2		;CL��Źؼ��ֳ���
   	ADD DI,BX		;ȷ���µ��ַ�����ʼλ��
	DEC DH 			;ѭ��������һ
   	CMP DH,0		;�ж�ѭ���Ƿ���ֹ
   	JE NO_MATCH		;��ѭ����ֹ��δƥ�䣬����ת��NO_MATCH
	JNE CMP_SEG 	;�������ƥ��
   	
MATCH_1:
	LEA DX,MATCH	;ƥ��ɹ�
	MOV AH,09H
	INT 21H
	
	LEA DX,LOCATION_1
	MOV AH,09H
	INT 21H
	
	MOV AX,BX
	PUSH BX				;��ջ��������
	INC AX				;ʹ��ʼλ�ô�һ��ʼ
	CALL PRINT_2		;���ؼ�������λ����ʮ����������ʽ��ӡ
	
	POP BX
	
	
	JMP START
	
NO_MATCH:
	LEA DX,NOMATCH		;ƥ��ʧ��
	MOV AH,09H
	INT 21H
	
	
	JMP START
ERROR_1:
	LEA DX,ERROR		;�������
	MOV AH,09H
	INT 21H
	
	
	JMP START

PRINT_2:
	MOV AH,0  ;���ڳ���9�������ַ���ASCII�в�û��ֱ����֮��Ӧ���ַ������Ӧ�ֱ������λ���ĸ�λ��ʮλ��
	MOV BL,16
	DIV BL    ;��AX�����ݳ���16���̷���AL,��������AH
	MOV BH,AH
	CMP AL,10
	JB NUMBER_1
	JAE LETTER_1
  NUMBER_1:
	ADD AL,30H  ;����λ��+30Hת��Ϊ�����ַ�
	JMP OUTPUT_1
  LETTER_1:
  	ADD AL,37H	;����λ��+37Hת��Ϊ��ĸ�ַ�
  OUTPUT_1:
	MOV DL,AL
	MOV AH,02H  ;��ӡ��λ��
	INT 21H
	
	MOV AL,BH 
	CMP AL,10
	JB NUMBER_2
	JAE LETTER_2
  NUMBER_2:
	ADD AL,30H  ;����λ��+37Hת��Ϊ��ĸ�ַ�
	JMP OUTPUT_2
  LETTER_2:
  	ADD AL,37H
  OUTPUT_2:
	MOV DL,AL 
	MOV AH,02H  ;��ӡʮλ��
	INT 21H
	RET
	
	
END_0:
	MOV AH,4CH
	INT 21H
CODES ENDS
    END START
    






