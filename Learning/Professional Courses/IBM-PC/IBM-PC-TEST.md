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
    mob ah,2
    int 21h
    sub ch,1
    jnz next
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
    mov ch, 4
    ;<---add--->
    mov bl,20h
    ;<--------->
exit:
    ;输出的循环
    mov dl, bl
    mob ah,2
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
输出单行的ASCII对应字符
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
    mob ah,2
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