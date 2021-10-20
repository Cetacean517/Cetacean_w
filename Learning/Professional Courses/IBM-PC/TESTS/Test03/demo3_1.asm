DATAS SEGMENT
    SENTENCE DB 13,10,'Enter Sentence:','$'
    KEYWORD DB 13,10,'Enter Keyword:','$'
    ERROR DB 13,10,'Input error!','$'
    
    ; LABEL伪指令给变量设置别名，共享内存位置
    BUFFER LABEL BYTE
    	   MAX1 DB 80
    	   ACT1 DB ?
    	   STOKN1 DB 80 DUP(?)
    	   
    KEY	LABEL BYTE
    	MAX2 DB 80
    	ACT2 DB ?
    	STOKN2 DB 80 DUP(?)	 
    
    TEMP LABEL BYTE
    	MAX3 DB 80
    	ACT3 DB ?
    	STOKN3 DB 80 DUP(?)
    	
    DIVIDING_LINE_1 DB 13,10,'++++++++++++++++++++++++++++++++++',13,10,'$'	;此处分割线
    DIVIDING_LINE_2 DB 13,10,'----------------------------------','$'	;此处分割线
   	
    ASK_1 DB 13,10,'Whether to perform string matching?','$'
    ASK_2 DB 13,10,'Please input Y/N:','$'
    
    
    MATCH  DB 13,10,'Match Successfully!','$'
    NOMATCH DB 13,10,'Failed.No Match','$'
    LOCATION_1 DB 13,10,'Keyword location (Hex) is:','$'
    LOCATION_2 DB 13,10,'Keyword location (Decimal) is:','$'
    RESULT DB 13,10,'The content of the new string is:','$'
    CRLF DB 13,10,'$'
    CHAR DB '$'
DATAS ENDS

STACKS SEGMENT
    ;此处输入堆栈段代码
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,SS:STACKS,ES:DATAS
START:
    MOV AX,DATAS
    MOV DS,AX
    MOV ES,AX
    
    LEA DX,DIVIDING_LINE_1		;回车换行
   	MOV AH,09H
   	INT 21H
   	
    LEA DX,ASK_1
   	MOV AH,09H
   	INT 21H
    
    LEA DX,ASK_2
   	MOV AH,09H
   	INT 21H
   	
   	MOV AH,01H			;设置带回显的键盘输入
   	INT 21H
   	   	
   	CMP AL,'Y'
   	JE BEGIN_1
   	
   	CMP AL,'N'
   	JE END_0
   	JNE ERROR_1
   	
BEGIN_1:
   	LEA DX,SENTENCE	;提示输入
   	MOV AH,09H
   	INT 21H
   	
   	MOV AH, 8
	INT 33
	
   	
   	LEA DX,BUFFER	;输入字符串
   	MOV AH,0AH
   	INT 21H
   	 
   	LEA DX,KEYWORD	;提示输入
   	MOV AH,09H
   	INT 21H
   	
   	LEA DX,KEY		;输入关键字
   	MOV AH,0AH
   	INT 21H
   	
   	LEA DX,DIVIDING_LINE_2		;回车换行
   	MOV AH,09H
   	INT 21H
   	
   	MOV CL,ACT2		;CL存放关键字长度
   	
   	MOV AH,ACT1
   	SUB AH,CL
   	JB ERROR_1		;字符串长度小于关键字长度，直接error
   	
   	MOV DH,AH		;字符串长度减关键字长度作为循环次数
   	ADD DH,1
   	
   	LEA DI,STOKN1	;初始化DI,为字符串指针
   	LEA SI,STOKN2	;初始化SI,为关键字指针
	MOV BX,0		;初始化字符串偏移量

CMP_SEG:
	CLD				;设置SI,DI移动方向为+1
   	REPZ CMPSB		;比较字符串和关键字
   	JZ MATCH_1		;匹配成功,跳转至MATCH_1
   	JNZ LOOP_1		;匹配失败，循环继续匹配
   	
LOOP_1:
	INC BX			;字符串偏移量
	LEA DI,STOKN1	;重置DI
   	LEA SI,STOKN2	;重置SI
   	MOV CL,ACT2		;CL存放关键字长度
   	ADD DI,BX		;确定新的字符串起始位置
	DEC DH 			;循环次数减一
   	CMP DH,0		;判断循环是否终止
   	JE NO_MATCH		;若循环终止还未匹配，则跳转至NO_MATCH
	JNE CMP_SEG 	;否则继续匹配
   	
MATCH_1:
	LEA DX,MATCH	;匹配成功
	MOV AH,09H
	INT 21H
	
	LEA DX,LOCATION_1
	MOV AH,09H
	INT 21H
	
	MOV AX,BX
	PUSH BX				;进栈保护数据
	INC AX				;使起始位置从一开始
	CALL PRINT_2		;将关键字所在位置以十六进制数形式打印
	
	LEA DX,LOCATION_2
	MOV AH,09H
	INT 21H
	
	POP BX				;出栈恢复数据
	MOV AX,BX
	PUSH BX
	INC AX
	CALL PRINT_1		;将关键字所在位置以十进制数形式打印
	
	POP BX
	CALL DELETE_KEY
	
	
	JMP START
	
NO_MATCH:
	LEA DX,NOMATCH		;匹配失败
	MOV AH,09H
	INT 21H
	
	
	JMP START
ERROR_1:
	LEA DX,ERROR		;输入错误
	MOV AH,09H
	INT 21H
	
	
	JMP START

PRINT_1:    	;两位十进制输出
	MOV AH,0  	;对于超过9个数的字符，ASCII中并没有直接与之对应的字符，因此应分别输出两位数的各位和十位。
	MOV BL,10
	DIV BL    	;将AX中内容除以10，商放在AL,余数放在AH
	ADD AL,30H  ;将个位数+30H转化为数字字符
	MOV BH,AH
	MOV DL,AL
	MOV AH,02H  ;打印个位数
	INT 21H
	MOV AL,BH 
	ADD AL,30H  ;将十位数转化为数字字符
	MOV DL,AL 
	MOV AH,02H  ;打印十位数
	INT 21H
	RET

PRINT_2:
	MOV AH,0  ;对于超过9个数的字符，ASCII中并没有直接与之对应的字符，因此应分别输出两位数的各位和十位。
	MOV BL,16
	DIV BL    ;将AX中内容除以16，商放在AL,余数放在AH
	MOV BH,AH
	CMP AL,10
	JB NUMBER_1
	JAE LETTER_1
  NUMBER_1:
	ADD AL,30H  ;将个位数+30H转化为数字字符
	JMP OUTPUT_1
  LETTER_1:
  	ADD AL,37H	;将个位数+37H转化为字母字符
  OUTPUT_1:
	MOV DL,AL
	MOV AH,02H  ;打印个位数
	INT 21H
	
	MOV AL,BH 
	CMP AL,10
	JB NUMBER_2
	JAE LETTER_2
  NUMBER_2:
	ADD AL,30H  ;将个位数+37H转化为字母字符
	JMP OUTPUT_2
  LETTER_2:
  	ADD AL,37H
  OUTPUT_2:
	MOV DL,AL 
	MOV AH,02H  ;打印十位数
	INT 21H
	RET
	
	
DELETE_KEY:			;删除字符串中关键字
	LEA SI,STOKN1	;复制原字符串到STOKN3
	LEA DI,STOKN3
	MOV CL,ACT1
	MOV CH,0
	CLD
	REP MOVSB
	
	LEA DI,STOKN3	;删除字符串中关键字
	ADD DI,BX		;确定删除位置
	
	LEA SI,STOKN1	;确定删除位置字符
	ADD SI,BX
	MOV DL,ACT2
	MOV DH,0
	ADD SI,DX
	
	MOV CL,ACT1
	SUB CL,DL
	SUB CX,BX
	
	CLD
	REP MOVSB
	
	MOV BYTE PTR[DI],'$'	;在删除之后字符串尾加'$',表示字符串终止
	
	LEA DX,RESULT			;回车换行
	MOV AH,09H
	INT 21H
	
	LEA DX,STOKN3			;输出删除关键字后字符串
	MOV AH,09H
	INT 21H
	
	RET
END_0:
	MOV AH,4CH
	INT 21H
CODES ENDS
    END START
    





