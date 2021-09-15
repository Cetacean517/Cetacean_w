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




