   ;assume cs:code
   ;code segment
;;Ҫ�����ڴ�0:200~0:23F��������0~63(3FH)
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
;Ҫ�����ڴ�0:200~0:23F��������0~63(3FH)
	mov ax,0
	mov ds,ax		; ds�ĳ�ʼ��ַ�������ڴ����ds����
	mov bx,0200h    ; ds��ƫ�Ƶ�ַ
	mov dx,0h		; ��������ݴ�0��ʼ
	
	mov cx,64
s:	mov ds:[bx],dl
	inc bx
	inc dx
	loop s

	mov ax,4c00H	; ����21H�жϣ���ȫ�˳�
	int 21H
code ends
end
