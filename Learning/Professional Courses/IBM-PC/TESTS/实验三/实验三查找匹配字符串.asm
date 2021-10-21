;查找匹配字符串
data segment
	mess1 db 'Enter keyword:$'
    mess2 db 'Enter Sentence:$'
    mess3 db 'Match!$'
    mess4 db 'Match at location:$'
    mess5 db 'H of the sentence.$'
    mess6 db 'No match!$'
    mess7 db 13,10,'$' ;取代四行的回车换行语句
    ;XLAT指令所需，建立表格
    tab db 030h,031h,032h,033h,034h,035h,036h,037h,038h,039h,041h,042h,043h,044h,045h,046h
    keyword label byte ;label伪指令，创建一个keyword，不分配空间
    	max1 db 20     ;keyword的最大空间，命名是max1
    	act1 db ?      ;keyword的实际距离，命名是act1
    	kw db 20 dup(?);keyword的空间创建，20个db的空白空间
    sentence label byte
    	max2 db 120
    	act2 db ?
    	sen db 120 dup(?)
    ;string1 db 120,120 dup(?)该行语句与sentence相同，第一个120表示缓冲区最大容量
    ;string2 db 20,20 dup(?)
data ends

code segment
    assume cs:code,ds:data,es:data
start:
main proc far  
    push ds
    sub ax,ax
    push ax
    mov ax,data
    mov ds,ax
    mov es,ax;数据压栈保存
    
    lea dx,mess1
    mov ah,9
    int 21h;输出提示语句：请输入关键字
    lea dx,keyword
    mov ah,0ah
    int 21h;从键盘读入关键字存在缓冲区，回车结束
    ;sub ch,ch
    ;mov cl,[string2+1];关键字长度
    ;lea si,string2+2;关键字起始字符
    lea dx,mess7
    mov ah,9
    int 21h;回车换行
    
resentence:
    lea dx,mess2
    mov ah,9
    int 21h;输出提示语句：请输入句子。句子可以重复输入，所以该部分可以循环
    lea dx,sentence
    mov ah,0ah
    int 21h;从键盘读入句子存在缓冲区，回车结束
    ;sub ch,ch
    ;mov ch,[string1+1];句子长度
    ;lea di,string1+2;句子起始字符
    lea dx,mess7
    mov ah,9
    int 21h;回车换行
    
    mov ax,0;设置句子开始比较的位置，从头开始
docompare:
    sub cx,cx
    mov cl,act1  ;关键字实际长度，存在cl
    lea si,kw    ;取关键字有效地址，存在si
    lea bx,sen   ;取句子有效地址，存在bx
    add bl,al    ;开始比较的位置
    mov di,bx    ;将句子开始比较的有效地址，存在di
    
    ;下面两行操作前，需要将比较的两个串分别放在si,di，将比较位数放在cl
    cld          ;df=0 正向比较
    repe cmpsb   ;重复串比较操作直到相等，跳到match
    jz domatch   ;相等zf=1,跳到match
    
    inc al       ;ax记录串偏移量，递增
    cmp al,act2  ;判断是否越界，al表示现在所在句子的地方，act2表示句子实际长度
    jnb notmatch ;al不小于act2，越界，跳到没有匹配
    jmp docompare;否则还没比较完成，继续比较

domatch:;字符串匹配，输出十六进制的位置
	lea dx,mess3
    mov ah,9
    int 21h;输出提示语句：匹配！
    lea dx,mess7
    mov ah,9
    int 21h;回车换行
    
	lea dx,mess4
    mov ah,9
    int 21h;输出提示语句
    
    add al,1  ;找到匹配位置，因为计算机默认从0开始计数，所以实际匹配位置是al+1
    sub cx,cx
    mov ch,al ;备份一份匹配位置，该数据是十六进制，需要将其显示在屏幕上
	mov bl,al ;显示第一位十六进制
	mov cl,4
	shr bl,cl ;右移4位，右移位数＞1，将右移量存在cl。右移后高位为0，低位即原来的十六进制高位
	mov al,bl ;将右移后的数据放入al，进行查表操作，得到的结果是十六进制高位对应的数字的ASCII码
	lea bx,tab;将表格偏移地址放入bx，查表操作前操作
	xlat      ;查表指令，将以bx为首地址，偏移地址为al的内容送到al
	mov dl,al ;此时存在al中的是十六进制高位的数字对应的ASCII码
	mov ah,2
	int 21h   ;此时调用输出语句，输出到屏幕上的是原来应该输出到屏幕上的十六进制的高位
	
	and ch,0fh;匹配位置与0fh，得到的结果是应该输出的十六进制的低位，高位为0
	mov al,ch
	lea bx,tab
	xlat
	mov dl,al ;进行和高位一样的查表操作并输出，此时屏幕上显示的是应该输出的十六进制的低位
	mov ah,2
	int 21h
    
    lea dx,mess5
    mov ah,9
    int 21h;输出提示语句
    lea dx,mess7
    mov ah,9
    int 21h;回车换行
	lea dx,mess7
    mov ah,9
    int 21h;回车换行
    jmp resentence;程序要求句子可重复输入，无条件跳转到输入句子部分

notmatch:;字符串不匹配
	lea dx,mess6
    mov ah,9
    int 21h;输出提示语句：字符串不匹配
    lea dx,mess7
    mov ah,09
    int 21h;回车换行
    lea dx,mess7
    mov ah,09
    int 21h;回车换行
    jmp resentence;重复输入句子

exit:ret
    
main endp
code ends
end start


