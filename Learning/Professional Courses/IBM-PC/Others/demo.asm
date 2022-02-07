   ;assume cs:code
   ;code segment
;;要求：向内存0:200~0:23F传送数据0~63(3FH)
	;mov ax,0
	;mov es,ax
	;mov bx,0
	;mov cx,64
;s:	mov es:[bx],bl
	;inc bl
	;loop s
;
	;mov ax,4c00H
	;int 21H
;code ends
;end


   assume cs:code
   code segment
;要求：向内存0:200~0:23F传送数据0~63(3FH)
	mov ax,0
	mov ds,ax		; ds的初始地址，存入内存放在ds里面
	mov bx,0200h    ; ds的偏移地址
	mov dx,0h		; 存入的数据从0开始
	
	mov cx,64
s:	mov ds:[bx],dl
	inc bx
	inc dx
	loop s

	mov ax,4c00H	; 调用21H中断，安全退出
	int 21H
code ends
end
