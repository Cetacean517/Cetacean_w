;********************************************************************
data  segment
mess1    db    'Your name:','$'
mess2    db    'Your telephone number:','$'
mess3    db    'Do you want to search?(y/n)','$'
mess4    db    0dh,0ah,'Please enter the name you want to search?','$'
mess5    db    'Failed. No match',0dh,0ah,'$'
mess6    db    'Please enter the number you want to store:','$'
crlf     db     0dh,0ah,'$'
stokin1  label  byte
		 max1      db     21
		 act1      db     ?
	  	 stokn1    db     21 dup(?)
stokin2  label  word
		 max2      db     9
		 act2      db     ?
		 stokn2    db     9 dup(?)
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
codesg  segment
   assume ds:data,cs:codesg,es:data
main    proc    far
       mov ax,data
       mov ds,ax
       mov es,ax
       lea di,numtable     ;di must be protected
       lea dx,mess6        ;��ʾ��Ϣ�������������ĵ绰��������
       mov ah,09   
       int 21h
       mov bx,0
  newchar:                ;����ǲο�������2.6���Ӽ��̽������֣�Ȼ��ת����ASCII��
       mov ah,1          ;�Ӽ��̽���totalnum,������AL=�����ַ�
       int 21h
       sub al,30h         ;ascii to binary
       jl next             ;jump if<0
       cmp al,9            ;is it >9d?
       jg next             ;yes jump
       cbw                 ;byte in AL to word in AX
	   	;(digit is now in AX)
       xchg ax,bx            ;����
       mov cx,10             ;put 10 dec in CX
       mul cx                  ;number times 10 ��DX,AX��<-(AX)*src
       xchg ax,bx               ;����
       add bx,ax              ;add digit to number
       jmp newchar                ;get next digit
   next:
       mov totalnum,bx
       lea dx,crlf
       mov ah,09
       int 21h
 a10:                              
       lea dx,mess1                ;��ʾ����������
       mov ah,09
       int 21h
       call input_name  
       inc  name_count
       call stor_name 
       
       lea dx,mess2                 ;��ʾ������绰
       mov ah,09
       int 21h
       call inphone
       call stor_phone
       
       cmp  name_count,0
       je  exit
       
       mov bx,totalnum
       cmp  name_count,bx         ;������֮ǰ����������ȵ��������绰
       jnz  a10
       call name_sort
 a20:
       lea dx,mess3                 ;��ʾ�Ƿ���Ҫ���ҵ绰����
       mov ah,09
       int 21h
       mov ah,08                     ;�������룬�޻��ԣ����ctrl-break �� Ctrl-C,AL=�����ַ�
       int 21h
       cmp al,'y'
       jz  a30
       cmp al,'n'
       jz  exit
       jmp a20                          
 a30:
       mov ah,09
       lea dx,mess4             ;��ʾѯ������
       int 21h
       call input_name
 a40:
       call name_search
       ;call printline
	   ;dec flag
	   ;sub flag,0  ;Ҫ��û�����Ļ�
       ;jnz  a40
       jmp a20
 exit:
       mov ax,4c00h            ;;;;����������ֹ��AL=�ӳ����룬AH=���ش��룬00=������ֹ��01=��Ctrl-c��ֹ��02=�����豸������ֹ��03=�ù��ܵ���31H��ֹ
       int 21h
 main endp
;--------------------------------------------------------------------
input_name  proc  near
     mov ah,0ah			;��������������������dx = ��������
     lea dx,stokin1
     int 21h
     
     mov ah,09			;����س�
     lea dx,crlf
     int 21h
     
     sub bh,bh			;bx��λ����
     mov bl,act1		;���������ֵ��ַ����ȴ���bl
     mov cx,21			;��󳤶ȴ���cx
     sub cx,bx          ;dst<-dst-src,cxΪ�������ܼĴ���,cx����ʣ���ַ��ĸ�����Ϊ���ո���׼��
b10:
     mov stokn1[bx],' '   ;��ȫ�ո�
     inc bx
     loop b10
    ret
input_name endp
;--------------------------------------------------------------------
stor_name     proc   near
      lea  si,stokn1
      mov  cx,20
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
     mov cx,9
     sub cx,bx
c10:
     mov stokn2[bx],' '
     inc bx
     loop c10
     ret 
inphone endp
;--------------------------------------------------------------------
stor_phone  proc near
     lea  si,stokn2
     mov  cx,8
     rep  movsb   ;movs ������ָ�� cmps ���Ƚϲ���
     ret
stor_phone endp
;--------------------------------------------------------------------
name_sort  proc near     ;;;;;;;;
     sub  di,28
     mov  endaddr,di
 c1:
     mov  swapped,0
     lea  si,numtable
 c2:
     mov  cx,20
     mov  di,si
     add  di,28
     mov  ax,di
     mov  bx,si   ;cmpsb si-di  movsb di<-si
     repz cmpsb   ;repz ��Ϊ0ʱ�ظ���������repe �����ʱ�ظ���������rep �ظ�������ֱ�������Ĵ���count reg ������Ϊ0Ϊֹ
     jbe  c3     ;CF��ZF=1��С�ڵ�����ת��
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
     jb   c2        ;CF=1����ת�ƣ�С�ڵ�����ת��
     cmp  swapped,0
     jnz  c1    ;�����Ϊ0��ת��
     ret
name_sort endp
;--------------------------------------------------------------------
name_search proc near
      lea  bx,numtable
	  mov  flag,0      ;;;����flag
	  ;mov  flagb,0  
   d: 
      ;mov  flag,0      ;;;����flag
	   ;mov  flagb,0  
      mov  cx,20
	  lea si,stokn1
      mov  di,bx
      repz cmpsb
      jz  d2
      ;jb  dexit
      add bx,28            ;��һ��
      cmp  bx,endaddr   
      jbe  d             ;δ������������
	  ;add flagb,flag
	  sub flag,0  ;Ҫ��û���ҵ��Ļ�
       jz  nof
    jmp  dexit         ;�������˳�
 nof:  lea dx,mess5
       mov ah,09
       int 21h 
  d2:
      mov searchaddr,bx
      ;mov flag,1         ;��־�ҵ���
	  inc flag
	  call printline
	  ; dec flag
	   ;sub flag,0  ;Ҫ��û�����Ļ�
	   add bx,28            ;��һ��
      cmp  bx,endaddr   
      jbe  d             ;δ������������
      jmp  dexit         ;�������˳�
       jnz  d
 dexit:
        ret
name_search endp
;--------------------------------------------------------------------
printline proc  near
       sub flag,0  ;Ҫ��û���ҵ��Ļ�
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
codesg ends
;--------------------------------------------------------------------
end main       

