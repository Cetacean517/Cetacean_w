datasg segment
    mess1 db 'Enter keyword:','$'
    mess2 db 'Enter Sentence:','$'
    mess3 db 'Match at location:','$'
    mess4 db 'No match.',13,10,'$'
    mess5 db 'H of the sentence',13,10,'$'
    mess6 db 13,10,'$'
    keyword label byte
        max1 db 20
        act1 db ?
        kw db 20 dup(?)
    sentence label byte
        max2 db 120
        act2 db ?
        sen db 120 dup(?)
datasg ends

codesg segment
    assume cs:codesg,ds:datasg,es:datasg
start:
main proc far
    push ds
    xor ax,ax
    push ax
    mov ax,datasg
    mov ds,ax
    mov es,ax
    ;;;;;;开始自定义代码
    lea dx,mess1
    mov ah,09
    int 21h         ;调用09号中断输出mess1
    lea dx,keyword
    mov ah,0ah
    int 21h         ;调用0a号中断进行keyword的输入
    lea dx,mess6    ;换行/回车
    mov ah,09
    int 21h
recome:
    lea dx,mess2    ;调用09号中断输出mess1
    mov ah,09
    int 21h
    lea dx,sentence ;调用0a号中断进行sentence的输入
    mov ah,0ah
    int 21h
    lea dx,mess6    ;换行/回车
    mov ah,09h
    int 21h

    mov ax,0
loop1:
    sub cx,cx   ;;;;
    mov cl,act1  ;关键字长度赋值cl
    lea si,kw    ;原串首地址kw
    lea bx,sen
    add bl,al
    mov di,bx    ;目的串首地址(不断变化，ax记录目的串偏移量)
    cld          ;df=0 正向比较
    repe cmpsb   ;
    jz match     ;相等zf=1,match
    ;
    inc al       ;ax记录串偏移量
    cmp al,act2  ;判断是否越界,注意要对齐(调试了半天，写成ax就不行)
    jnb loop2     ;no match
    jmp loop1    ;还没比较完成

match:
    mov bx,0
    mov bl,al
    add bx,1    ;需要从1开始计数
    lea dx,mess3
    mov ah,09
    int 21h
    ;;;输出bx中的十六进制数
    mov cl,4
    rol bx,cl
    rol bx,cl
    mov ch,2     ;ch用于循环移位
rotate:          ;这里使用到了循环
    mov cl,4     ;cl用于每次移4位,rol的操作数不能是立即数
    rol bx,cl    ;循环右移4位
    mov ax,bx    
    and al,0fh   ;取低四位
    add al,30H   ;’0’-’9’ ASCII 30H-39H 转化为
    cmp al,3aH   ;比3a小的是数字，则直接跳转输出
    jb printf    ;这里使用到了分支
    add al,07h   ;否则再加上07h  ’A’-’F’ ASCII 41H-46H
printf: 
    mov dl,al        
    mov ah,2     ;调用2号中断输出字符串
    int 21h
    dec ch       ;ch-1
    jnz rotate   ;如果ch不等于0，继续循环
    ;;;;
    lea dx,mess5
    mov ah,09
    int 21h
    lea dx,mess6
    mov ah,09
    int 21h
    jmp recome
    
loop2:
    lea dx,mess4  ;;输出NO match
    mov ah,09
    int 21h
    jmp recome
exit:
    ret
main endp
codesg ends
end start

