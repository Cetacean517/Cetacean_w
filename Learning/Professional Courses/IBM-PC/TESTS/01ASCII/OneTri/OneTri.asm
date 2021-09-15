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
	mov ch, 1h ; 设置循环的位数
	mov dh, 5h	; 设置循环的行数
	mov bl, 18h ;
	call printit
newline:
	dec dh
	mov dl, 0Ah
	mov ah,2
	int 21h
	jnz printit
	call endloop
	
printit:
	mov dl, bl	;输出bl
	mov ah,2
	int 21h
	add bl, 1	;bl+1
	sub ch, 1
	jnz printit
	call newline;循环输出19个，输出换行
endloop:
	mov ah, 4ch	; 以下两行类似于return
	int 21h
CODES ENDS
    END START


