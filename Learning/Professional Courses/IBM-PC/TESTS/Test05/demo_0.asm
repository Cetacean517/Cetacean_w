datas   segment  
        cury   db   15
		curx   db   50  ;����ʼλ��

		lx     db   10  
		ly     db   15  ;��¼�󴰿ڵĵ�ǰ���λ�ã���ʼ��Ϊ�󴰿ڳ�ʼλ��

		rx     db   50  
		ry     db   15  ;��¼�Ҵ��ڵĵ�ǰ���λ�ã���ʼ��Ϊ�Ҵ��ڵĳ�ʼλ��

		dwx    db   15
		dwy    db   22  ;��¼�´��ڵ�ǰ�Ĺ��λ�ã���ʼ��Ϊ�´��ڳ�ʼλ��
		
		ulrow  db    0
		ulcow  db    0
		lrrow  db    0
		lrcol  db     0
		windowflag  db   1      ;=1���ұߴ��ڣ�=2����ߴ���
datas   ends

;��ָ��clear����
clear  macro a,b,c,d
         mov  al,0  ;�Ͼ�����Ϊ0
		 mov  bh,7  ;����������Ϊ07������������
		 mov  ch,a  ;���Ͻ��к�
		 mov  cl,b  ;���Ͻ��к�
		 mov  dh,c  ;���½��к�
		 mov  dl,d  ;���½��к�
		 mov  ah,6  
		 int 10h
endm
;-------------------------------------------------------------��ָ�� scroll���Ͼ�һ�� 
scroll macro cont,ulrow,ulcol,lrrow,lrcol     
         mov al,cont                ;�Ͼ����� 
		 mov bh,70h                 ;����������  
		 mov ch,ulrow               ;���Ͻ��к� 
         mov cl,ulcol               ;���Ͻ��к� 
         mov dh,lrrow               ;���½��к�  
         mov dl,lrcol               ;���½��к�  
         mov ah,6 
         int 10h                    ;BIOS���ã��Ͼ�		 
endm 

;--------------------------------------------------------------��ָ��postc ��궨λ
post_c macro y,x                     ;���ù���� (y��x)λ�ã����ù������λ��        
    mov bh,0             ;ע�����������ǣ��кţ��кţ�����ʽ���к���y���к���x��
	mov ah,2         
	mov dh,y         ;int10h�У�ah=2ʱ�����ù��λ�ã�dhΪ�кţ�dlΪ�к�
	mov dl,x         
	int 10h         
	endm
;---------------------------------------------------------------�ڵ�ǰ���ں��´�����ʾ 
display macro 
    mov bh,0     
	mov cx,1 
    mov ah,0ah              ;�ڵ�ǰ�Ĵ��ڵĹ��λ�ô���ӡ�ַ�     
	int 10h   
	
    post_c dwy,dwx         ;�������õ�ǰ���λ�õ��´��ڵ���ȷλ�ô�
	mov bh,0     
	mov cx,1 
    mov ah,0ah              ;���´������     
	int 10h 
endm 

;----------------------------------------------------------------�����ַ����ж� 
getchar macro 
   input:                   ;��������ϵ��ַ�  
       mov ah,0 
       int 16h                 ;BIOS���ã��Ӽ��̶��ַ�    
   
       cmp ah,4bh              ;�ж������ַ��Ƿ�Ϊ�����  ɨ����
       jnz no_left  
       post_c ly,lx  
       mov windowflag,2     
       jmp input  
   no_left:   
       cmp ah,4dh  
	   jnz no_right            ;�ж������ַ��Ƿ�Ϊ����� 
	   post_c ry,rx  
	   mov windowflag,1     
	   jmp input
   no_right: 
       cmp ah,01h               ;�ж������ַ��Ƿ�ΪESC     
	   ;jz exit  
jnz  continue1
        clear 0,0,24,79             ;��Ļ�ܴ�СΪ25*80��

ret
continue1:
 
       display  ;�������Ҽ���ESC��ô��Ƕ�׵��� ��display ����ʾ����Ŀɴ�ӡ���ַ���

	   inc dwx   ;����ʾ�ַ����ٽ��´��ڸ��еĹ����кż�1�������Ƚ��Ƿ�Ҫ�Ͼ�
       cmp dwx,65              ;�ж��´����Ƿ��Ͼ�     
	   jle isright                ;isright��ʾ�´����е�ǰ����п���������
       scroll 1,18,15,22,65        ;����һ�е����Ҷˣ�Ҫ���Ͼ�һ��
	   mov dwx,15              ;�Ͼ�һ�к󣬵�ǰ�кű�Ϊ��ǰ��������ߵ��е��к�
   isright:                       
       cmp windowflag,1          ;�ж��Ƿ����Ҵ���     
	   jnz displeft   
   dispright:                   ;�ж��Ҵ����Ƿ��Ͼ�     
       inc rx      
	   cmp rx,70
	   jle rightexit             ;rightexit��ʾ�Ҵ����е�ǰ����п��������ߣ������Ͼ�

       scroll 1,5,50,15,70    
	   mov rx,50   
rightexit:                   ;�Ҵ������     
      post_c ry,rx     
	  jmp input 
displeft:                    ;�ж��󴰿��Ƿ��Ͼ�     
      inc lx     
	  cmp lx,30     
	  jle leftexit 
      scroll 1,5,10,15,30     
	  mov lx,10    
leftexit:                    ;�󴰿����     
      post_c ly,lx     
	  jmp input
 
      endm        ;getchar macro endm

;---------------------------------------------------------------------
	
codes segment 
 assume cs:codes,ds:datas 
 start: 
main proc far   
    push ds  
	sub ax,ax  
	push ax   
	mov ax,datas  
	mov ds,ax  
	clear 0,0,24,79  
	scroll 10,5,10,15,30  ;scrollҲ�������ô���make three windows
	scroll 10,5,50,15,70  
	scroll 4,18,15,22,65 ;�Ͼ�4�У�����Ϊ�´���һ��������4�У��õ�һ�������ݵĴ���
	
	post_c cury,curx  
	getchar
    ret
main endp 
codes ends 
   end start 


