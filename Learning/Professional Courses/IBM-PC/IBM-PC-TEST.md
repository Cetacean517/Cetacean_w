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