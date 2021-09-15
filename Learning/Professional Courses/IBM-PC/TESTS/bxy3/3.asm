data segment
string db 'The data is Jan.$10!$'
mylength equ $-string
data ends

code segment
assume cs:code,ds:data

START:
	push ds
	sub ax,ax	
	push ax
	mov ax,data
	mov ds,ax
	lea dx,string
	mov ah,09h
	int 21h
	mov ah,02h
	mov dl,0ah
	int 21h
	mov dl,0dh
	int 21h
	lea si,string
	mov cx,mylength
	mov al,'$'
CONT:
	cmp al,[si]
	jnz next
	mov byte ptr[si],' '
	jz done
next: 
	inc si
	loop CONT
done:
	lea dx,string
	mov ah,09h
	int 21h
	mov ah,4ch
	int 21h
code ends
	END START



