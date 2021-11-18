# IBM-PC 实验
## 2021.09.22
### 代码模板
起始代码模板
```
// 堆栈段的代码
DATAS SEGMENT
    ;此处输入数据段代码  
DATAS ENDS

STACKS SEGMENT
    ;此处输入堆栈段代码
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES, DS:DATAS,SS:STACKS
START:
    MOV AX,DATAS
    MOV DS,AX
    ;此处输入代码段代码
    MOV AH,4CH
    INT 21H
CODES ENDS
    END START
```
不用堆栈段的代码模板
```
CODES SEGMENT
    ASSUME CS:CODES
START:
    MOV AX,DATAS
    MOV DS,AX
    ;此处输入代码段代码
    ; 结束语句
    MOV AH,4CH
    INT 21H
CODES ENDS
    END START
```
输出4个a
```
CODES SEGMENT
    ASSUME CS:CODES
START:
    mov ch, 4
exit:
    ;输出的循环
    mov dl, 'a'
    mov ah,2
    int 21h
    sub ch,1
    jnz exit
    ; 结束语句
    MOV AH,4CH
    INT 21H
CODES ENDS
    END START
```
输出单行的ASCII对应字符
```
CODES SEGMENT
    ASSUME CS:CODES
START:
    mov ch, 128
    ;<---add--->
    mov bl,20h
    ;<--------->
next:
    ;输出的循环
    mov dl, bl
    mov ah,2
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
```
输出ASCII对应字符
```
CODES SEGMENT
    ASSUME CS:CODES
START:
    mov ch, 128
    mov bl, 00h
    mov bh, 10h
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
    int 21
    ;
    mov dl,13
    mov ah,2
    int 21
    mov bh,10h
    ;
skip:
    sub ch,1
    jnz next

    MOV AH,4CH
    INT 21H
CODES ENDS
    END START
```

ASCII码平行四边形输出
```
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
```

## 2021.09.26
### 字符串的输出
```
DATA SEGMENT
	;样例：mess db 'abcde1234%%^&*',10,13,'12$' ;10,13表示输出换行,字符串以$为结尾
	mess db 'Input:abcde1234%%^&*$' ;10,13表示输出换行,字符串以$为结尾
	crlf db 10,13,'$'
	letter db 'letterNum:$'
	num db 'numNum:$'
	sign db 'signNum:$'
	bb db 00110100b, 00010010b
DATA ENDS
CODES SEGMENT
    ASSUME CS:CODES, DS:DATA	;代码段和数据段的名字不一定一定是DATA
START:
	mov ax, DATA
	mov ds, ax
	;输出输入字符串
	lea dx, mess
	mov ah, 9
	int 21h
	lea dx, crlf
	mov ah, 9
	int 21h
	;数据统计
	
	;输出结果
	lea dx, letter
	mov ah, 9
	int 21h
	lea dx, crlf
	mov ah, 9
	int 21h
	;
	lea dx, num
	mov ah, 9
	int 21h
	lea dx, crlf
	mov ah, 9
	int 21h
	;
	lea dx, sign
	mov ah, 9
	int 21h
	lea dx, crlf
	mov ah, 9
	int 21h
	;
    MOV AH,4CH
    INT 21H
CODES ENDS
    END START
```






## 实验一
#### 输出矩形的ASCII码表
```
DATAS SEGMENT
    ;此处输入数据段代码  
DATAS ENDS

STACKS SEGMENT
    ;此处输入堆栈段代码
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,SS:STACKS
START:
	;push ds
	;sub ax, ax
	;push ax
	mov ch, 10h ; 设置循环的位数
	mov dh, 15	; 设置循环的行数
	mov bl, 10h ;
	;ASCII 打印不了向左箭头
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
	mov dl, bl	;输出bl
	mov ah,2
	int 21h
	mov dl, 20h	;输出空格
	mov ah,2
	int 21h
	add bl, 1	;bl+1
	sub ch, 1
	jnz printit
	call newline;循环输出16个，输出换行
endloop:
	mov ah, 4ch	; 以下两行类似于return
	int 21h
CODES ENDS
    END START
```
#### 输出直角三角形的ASCII码表
```
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
```

## 实验二
#### 输出存在DS中的字符串
```
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
```
#### 输入字符串 并统计字符，字母，数字个数 
```
DATA SEGMENT
	;样例：mess db 'abcde1234%%^&*',10,13,'12$' ;10,13表示输出换行,字符串以$为结尾
	;mess 		db 'abcde1234%%^&*$' ;10,13表示输出换行,字符串以$为结尾
	;一些输出提示
	input		db 'input a line:$'
	crlf		db 10,13,'$'
	letter_n 	db 'letterNum:$'
	digit_n 	db 'digitNum:$'
	other_n 	db 'signNum:$'
	
	;输入的字符串

	line        db  80	;预定义80字节的空间
				db  ?	;待输入完成后，自动获得输入的字符个数
				db  80 dup(?)
	
	len  equ  $ - line	;获取字符串的长度
	
	;设置一些计数器
	letter_count       db  ?
	digit_count        db  ?
	other_count        db  ?
	
DATA ENDS
CODES SEGMENT
    ASSUME CS:CODES, DS:DATA	;代码段和数据段的名字不一定一定是DATA
START:
;数据初始化，把0h 放入堆栈
   push ds
   mov ax,0h
   push ax
   mov ax,DATA          ;初始化ds
   mov ds,ax
   mov letter_count,0
   mov digit_count,0
   mov other_count,0
 
; 输入，输入一行字符提示
   lea dx,input
   mov ah,9
   int 21h
;输入一行字符
   lea dx,line
   mov ah,10 
   int 21h
;数据统计
;1. 读入数据
	mov si,2	;存放数组的下标要用si
	mov cl, [line+1]
	mov ah, len
	
read:
	mov al, line[si]
	cmp al, '0'
	jb other
	cmp al, '9'
	ja letterOrdigit
	add digit_count,1
	jmp next
	
letterOrdigit:
	and al,11011111b	;将字符串转换为大写字符
	cmp al, 'A'
	jb other
	cmp al, 'Z'
	ja other
	add letter_count,1
	jmp next

other:
	add other_count,1 ;other统计器加1
	;输出结果

next: 
	add si,1
	sub ah,1
	dec cl
	cmp cl,0
	jz break
	jnz read	;没读完，继续读

break:
	;输出输入的字符串
	LEA DX, crlf                         ;另取一行                  
    MOV AH, 09H							 
    INT 21H
    MOV AL, line+1                     ;对字符串进行处理
    ADD AL, 2
    MOV AH, 0
    MOV SI, AX
    MOV line[SI], '$'
    LEA DX, crlf                        ;另取一行                   
    MOV AH, 09H
    LEA DX, line+2                     ;输出输入的字符串
    MOV AH, 09H							 
    INT 21H
    LEA DX, crlf                         ;另取一行                  
    MOV AH, 09H							 
    INT 21H
;
	lea dx, crlf
	mov ah, 9
	int 21h
	lea dx, letter_n
	mov ah, 9
	int 21h
	lea dx, letter_count
	mov al, letter_count
	call disp
	lea dx, crlf
	mov ah, 9
	int 21h
	;
	lea dx, digit_n
	mov ah, 9
	int 21h
	lea dx, digit_count
	mov al, digit_count
	call disp
    LEA DX, crlf                         ;另取一行                  
    MOV AH, 09H							 
    INT 21H
;
	lea dx, other_n
	mov ah, 9
	int 21h
	lea dx, other_count
	mov al, other_count
	call disp
	lea dx, crlf
	mov ah, 9
	int 21h

exit:
    MOV AH,4CH
    INT 21H

disp:                 ;十进制数形式显示AL中的内容.
       mov  ah, 0
       mov  bl, 10
       div  bl        ;div 无符号:div src 16位操作:商ax=(dx,ax)/src,余数dx
       add  al, 30h    ;比如说al=15h,即21，表示letter数量，然后，这个过程就是，ax=0015h(21),除以bl，bl值为10
       mov  dl, al      ;则除完了的结果为2余1，则ah=01,al=02,即ax=0102h;,那么al+30h即为表示该数字的ASCII码值，因为0的ASCII值为30h
       mov  bh, ah       ;则ax=0132h,dl=32,bh=01;
       mov  ah, 02h      ;显示输出dx,则显示32码对应的数字，2
       int  21h           
       mov  al, bh        ;把01给al,然后算出ASCII码，然后给dx，然后显示
       add  al, 30h
       mov  dl, al        ;除数B有 8位和16位两种，保存在一个reg寄存器里 或是内存单元中。
 
                          ;被除数A 默认存放在AX中（16位以内） 或 AX和DX中（32位，DX存放高16位，AX存放低16位）
 
                          ;结果： 如果除数B是8位，那么除法的结果AL保存商，AH保存余数，
                          ;如果除数B是16位，那么除法的结果 AX保存商，DX保存余数。
       mov  ah, 02h
       int  21h     
       ret

CODES ENDS
    END START
```

## 实验三
#### 输入字符串 查找匹配
```
DATAS SEGMENT
    SENTENCE DB 13,10,'Enter Sentence:','$'
    KEYWORD DB 13,10,'Enter Keyword:','$'
    ERROR DB 13,10,'Input error!','$'
    
    ; LABEL伪指令给变量设置别名，共享内存位置
    BUFFER LABEL BYTE
    	   MAX1 DB 80	;最大长度
    	   ACT1 DB ?	;实际输入长度
    	   STOKN1 DB 80 DUP(?)	;空间的创建
    	   
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
    LOCATION_1 DB 13,10,'Match location at:','$'
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
	
	POP BX
	
	
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
	
	
END_0:
	MOV AH,4CH
	INT 21H
CODES ENDS
    END START
```

## 实验四
#### 电话表
```
;********************************************************************
data  segment
;提示信息
mess1    db    'Your name:','$'
mess2    db    'Your telephone number:','$'
mess3    db    'Do you want to search?(y/n)','$'
mess4    db    0dh,0ah,'Please enter the name you want to search?','$'
mess5    db    'Failed. No match',0dh,0ah,'$'
mess6    db    'Please enter the number you want to store:','$'
crlf     db     0dh,0ah,'$'
;需要输入信息
stokin1  label  byte
		 max1      db     21
		 act1      db     ?
	  	 stokn1    db     21 dup(?)
stokin2  label  word
		 max2      db     12
		 act2      db     ?
		 stokn2    db     12 dup(?)
;一些标记信息
numtable   db     50 dup(28 dup(?))
name_count dw    0
endaddr   dw     ?
swapped   dw     ?
totalnum dw   ?
savenp    db     28 dup(?),0dh,0ah,'$'
searchaddr dw    ?
flag      db     ?
flagb      db     ?
show      db     'name                phone',0dh,0ah,'$'
data  ends
;********************************************************************
code  segment
   assume ds:data,cs:code,es:data
main    proc    far
       mov ax,data
       mov ds,ax
       mov es,ax
       lea di,numtable     ;di must be protected
       lea dx,mess6        ;显示信息，请输入想存入的电话号码总数
       mov ah,09   
       int 21h
       mov bx,0
  newchar:                ;这个是参考书上例2.6，从键盘接收数字，然后转换成ASCII码
       mov ah,1          ;从键盘接收totalnum,并回显AL=输入字符
       int 21h
       sub al,30h         ;ascii to binary
       jl next             ;jump if<0
       cmp al,9            ;is it >9d?
       jg next             ;yes jump
       cbw                 ;byte in AL to word in AX
	   	;(digit is now in AX)
       xchg ax,bx            ;交换
       mov cx,10             ;put 10 dec in CX
       mul cx                  ;number times 10 （DX,AX）<-(AX)*src
       xchg ax,bx               ;交换
       add bx,ax              ;add digit to number
       jmp newchar                ;get next digit
   next:
       mov totalnum,bx
       lea dx,crlf
       mov ah,09
       int 21h
 a10:                              
       lea dx,mess1                ;显示请输入名字
       mov ah,09
       int 21h
       call input_name  
       inc  name_count
       call stor_name 
       
       lea dx,mess2                 ;显示请输入电话
       mov ah,09
       int 21h
       call inphone
       call stor_phone
       
       cmp  name_count,0
       je  exit
       
       mov bx,totalnum
       cmp  name_count,bx         ;输入与之前输入总数相等的姓名，电话
       jnz  a10
       call name_sort
 a20:
       lea dx,mess3                 ;显示是否需要查找电话号码
       mov ah,09
       int 21h
       mov ah,08                     ;键盘输入，无回显，检测ctrl-break 或 Ctrl-C,AL=输入字符
       int 21h
       cmp al,'y'
       jz  a30
       cmp al,'n'
       jz  exit
       jmp a20                          
 a30:
       mov ah,09
       lea dx,mess4             ;显示询问名字
       int 21h
       call input_name
 a40:
       call name_search
       ;call printline
	   ;dec flag
	   ;sub flag,0  ;要是没结束的话
       ;jnz  a40
       jmp a20
 exit:
       mov ax,4c00h            ;;;;带返回码终止，AL=子出口码，AH=返回代码，00=正常终止，01=用Ctrl-c终止，02=严重设备错误终止，03=用功能调用31H终止
       int 21h
 main endp
;--------------------------------------------------------------------
input_name  proc  near
     mov ah,0ah			;将键盘输入至缓冲区。dx = 缓冲区首
     lea dx,stokin1
     int 21h
     
     mov ah,09			;输出回车
     lea dx,crlf
     int 21h
     
     sub bh,bh			;bx高位清零
     mov bl,act1		;把输入名字的字符长度存入bl
     mov cx,21			;最大长度存入cx
     sub cx,bx          ;dst<-dst-src,cx为计数功能寄存器,cx存入剩余字符的个数，为填充空格做准备
b10:
     mov stokn1[bx],' '   ;补全空格
     inc bx
     loop b10
    ret
input_name endp
;--------------------------------------------------------------------
stor_name     proc   near
      lea  si,stokin1
      mov  cx,17
      rep  movsb
      ret
stor_name  endp
;--------------------------------------------------------------------
inphone   proc   near
     mov ah,0ah
     lea dx,stokin2
     int 21h
     mov ah,09
     
     lea dx,crlf
     int 21h
     
     sub bh,bh
     mov bl,act2
     mov cx,12
     sub cx,bx
c10:
     mov stokin2[bx],' '
     inc bx
     loop c10
     ret 
inphone endp
;--------------------------------------------------------------------
stor_phone  proc near
     lea  si,stokin2
     mov  cx,11
     rep  movsb   ;movs 串传送指令 cmps 串比较操作
     ret
stor_phone endp
;--------------------------------------------------------------------
name_sort  proc near
     sub  di,28
     mov  endaddr,di  ;endaddr中存放的是numtable中手机号结束的位置
 c1:
     mov  swapped,0
     lea  si,numtable
 c2:
     mov  cx,17
     mov  di,si
     add  di,28
     mov  ax,di
     mov  bx,si   ;cmpsb si-di  movsb di<-si
     repz cmpsb   ;repz 当为0时重复串操作；repe 当相等时重复串操作；rep 重复串操作直至计数寄存器count reg 的内容为0为止
     jbe  c3     ;CF与ZF=1，小于等于则转移
 ;chang order 
     mov si,bx
     lea di,savenp
     mov cx,28
     rep movsb
     mov cx,28
     mov di,bx
     rep movsb
     mov cx,28
     lea si,savenp
     rep movsb
     mov swapped,1
 c3:
     mov  si,ax
     cmp  si,endaddr
     jb   c2        ;CF=1，则转移，小于等于则转移
     cmp  swapped,0
     jnz  c1    ;结果不为0则转移
     ret
name_sort endp
;--------------------------------------------------------------------
name_search proc near
      lea  bx,numtable
	  mov  flag,0      ;;;立个flag
   d: 
      mov  cx,17
	  lea si,stokin1
      mov  di,bx
      repz cmpsb
      jz  d2
      
      add bx,28            ;下一条
      cmp  bx,endaddr   
      jbe  d             ;未结束，继续找

	  sub flag,0  ;要是没有找到的话
      jz  nof
      jmp  dexit         ;结束，退出
      
 nof:  lea dx,mess5
       mov ah,09
       int 21h 
  d2:
      mov searchaddr,bx
	  inc flag
	  call printline
	  add bx,28            ;下一条
      cmp  bx,endaddr   
      jbe  d             ;未结束，继续找
      jmp  dexit         ;结束，退出
      jnz  d
      
 dexit:
        ret
name_search endp
;--------------------------------------------------------------------
printline proc  near
       sub flag,0  ;要是没有找到的话
       jz  no
p10:
       mov ah,09
       lea dx,show
       int 21h
       
       mov cx,28
       mov si,searchaddr
       lea di,savenp
       rep movsb
       
       lea dx,savenp
       mov ah,09
       int 21h
       jmp fexit
       
no:    lea dx,mess5
       mov ah,09
       int 21h 
fexit:  
       ret
printline endp
;--------------------------------------------------------------------
code ends
;--------------------------------------------------------------------
end main       
```
## 实验五
#### 交互界面
```
DATAS SEGMENT
	;光标的初始位置
    inity 	db	15
    initx	db	50
    
    ;记录左窗口当前的光标位置，初始化为做窗口的初始位置
    leftx	db	10
    lefty   db  15 
  
    ;记录右窗口当前的光标位置，初始化为做窗口的初始位置
    rightx	db	50
    righty  db  15     
    
    ;记录下窗口当前的光标位置，初始化为下窗口初始位置
	nowx    db   15
	nowy    db   22  
	
	ulrow  	db  0
	ulcow  	db  0
	lrrow  	db  0
	lrcol  	db  0
	windowstat  db   1      ;=1，右边窗口，=2，左边窗口
DATAS ENDS

;宏指令clear清屏（左上行，左上列，右下行，右下列）
clear  macro a,b,c,d
         mov  al,0  ;整个窗口空白（设置上卷行数）
		 mov  bh,7  ;卷入行属性为07，是正常属性（设置卷入行属性）
		 mov  ch,a  ;左上角行号
		 mov  cl,b  ;左上角列号
		 mov  dh,c  ;右下角行号
		 mov  dl,d  ;右下角列号
		 mov  ah,6  ;设置BIOS的功能号
		 int 10h	;显示器驱动程序
endm

;-------------------------------------------------------------宏指令 scroll向上卷动一行 
scroll macro cont,ulrow,ulcol,lrrow,lrcol     
         mov al,cont                ;上卷行数 
		 mov bh,70h                 ;卷入行属性  
		 mov ch,ulrow               ;左上角行号 
         mov cl,ulcol               ;左上角列号 
         mov dh,lrrow               ;右下角行号  
         mov dl,lrcol               ;右下角列号  
         mov ah,6 
         int 10h                    ;BIOS调用，上卷		 
endm 

;--------------------------------------------------------------宏指令locate_n 光标定位
locate_n macro y,x   ;设置光标在 (y，x)位置，设置光标行列位置
					 ;注意这里坐标是（行号，列号）的形式，行号是y，列号是x）
    mov bh,0         ;显示页号
	mov ah,2         
	mov dh,y         ;int10h中，ah=2时，设置光标位置，dh为行号，dl为列号
	mov dl,x         
	int 10h         
	endm
	
;---------------------------------------------------------------在当前窗口和下窗口显示 
show macro 
    mov bh,0     			;显示页
	mov cx,1 				;cx = 字符重复个数，即重复一次
    mov ah,0ah              ;在当前的窗口的光标位置处打印字符和属性 
	int 10h   
	
    locate_n nowy,nowx      ;重新设置当前光标位置到下窗口的正确位置处
	mov bh,0     
	mov cx,1 
    mov ah,0ah              ;在下窗口输出     
	int 10h 
endm 

;----------------------------------------------------------------接收字符并判断 
getchar macro 					;一个一个读入，判断，输出
   input:                    	;输入键盘上的字符  
       mov ah,0 
       int 16h                 	;BIOS调用，从键盘读字符    

       cmp ah,4bh              	;判断输入字符是否为左向键扫描码
       jnz no_left				;输入为左向键时，继续执行；否则跳转no_left  			
       locate_n lefty,leftx  	;向左：光标重新定位到左窗口
       mov windowstat,2     	;更新窗口状态
       jmp input  				;继续输入
       
   no_left:   					;不跳转：已跳转至左窗口/保持在右窗口
       cmp ah,4dh				;判断输入字符是否为右向键
	   jnz no_right             ;输入为右向键时，继续执行；否则跳转no_right
	   locate_n righty,rightx  	;向右：光标重新定位到有窗口
	   mov windowstat,1     	;更新窗口状态
	   jmp input				;继续输入
	   
   no_right: 
       cmp ah,01h               ;判断输入字符是否为ESC     
	   jnz  continue			;没有结束，继续执行
       clear 0,0,24,79          ;屏幕总大小：25*80
	   ret
	   
	continue:
       show  					;不是左右键和ESC,则嵌套调用宏show（显示输入的可打印的字符）
	   inc nowx   				;先显示字符，再将下窗口该行的光标的列号加1，再来比较是否要上卷
	   
       cmp nowx,65              ;判断下窗口是否上卷    
	   jle goright              ;<=65: isright表示下窗口中当前光标行可以向右走
       scroll 1,18,15,22,65     ;>65:  到了一行的最右端，要向上卷一行
	   mov nowx,15              ;置位：上卷一行后，当前列号变为当前窗口最左边的列的列号
	   
   goright:            			;判断左窗口/右窗口的右侧输入         
       cmp windowstat,1         ;判断是否在右窗口     
	   jnz showleft				;在右窗口：showright;否则，showleft
	
   showright:                   ;判断右窗口是否上卷     
       inc rightx				;列数+1
	   cmp rightx,70			
	   jle rightexit            ;<= 70: rightexit表示右窗口中当前光标行可以向右走，不用上卷
       scroll 1,5,50,15,70 		;> 70 : 上卷一行  
	   mov rightx,50   				;置位，恢复列号
	   
   rightexit:                   ;右窗口输出     
      locate_n righty,rightx     	;定位到右窗口的光标位置
	  jmp input 				;继续输入
	  
   showleft:                    ;判断左窗口是否上卷  （同right的操作）   
      inc leftx     				
	  cmp leftx,30     
	  jle leftexit 
      scroll 1,5,10,15,30     
	  mov leftx,10
	      
   leftexit:                    ;左窗口输出     
      locate_n lefty,leftx     
	  jmp input					;继续输入
 
      endm        ;getchar macro endm
CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS
START:
	main proc far
		push ds
		sub ax,ax
		push ax
		mov ax,DATAS
		mov ds,ax
		;初始化显示
		clear 0,0,24,79
		
		;利用scroll设置登录时的三个窗口
		scroll 10,5,10,15,30  
		scroll 10,5,50,15,70  
		scroll 4,18,15,22,65 ;上卷4行，是因为下窗口一共能容纳4行，得到一个空内容的窗口
		locate_n inity,initx	;设置初始化的光标位置
		getchar
		ret
	main endp
CODES ENDS
    END START
```