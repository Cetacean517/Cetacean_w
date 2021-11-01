DATAS SEGMENT
	;���ĳ�ʼλ��
    inity 	db	15
    initx	db	50
    
    ;��¼�󴰿ڵ�ǰ�Ĺ��λ�ã���ʼ��Ϊ�����ڵĳ�ʼλ��
    leftx	db	10
    lefty   db  15 
  
    ;��¼�Ҵ��ڵ�ǰ�Ĺ��λ�ã���ʼ��Ϊ�����ڵĳ�ʼλ��
    rightx	db	50
    righty  db  15     
    
    ;��¼�´��ڵ�ǰ�Ĺ��λ�ã���ʼ��Ϊ�´��ڳ�ʼλ��
	nowx    db   15
	nowy    db   22  
	
	ulrow  	db  0
	ulcow  	db  0
	lrrow  	db  0
	lrcol  	db  0
	windowstat  db   1      ;=1���ұߴ��ڣ�=2����ߴ���
DATAS ENDS

;��ָ��clear�����������У������У������У������У�
clear  macro a,b,c,d
         mov  al,0  ;�������ڿհף������Ͼ�������
		 mov  bh,7  ;����������Ϊ07�����������ԣ����þ��������ԣ�
		 mov  ch,a  ;���Ͻ��к�
		 mov  cl,b  ;���Ͻ��к�
		 mov  dh,c  ;���½��к�
		 mov  dl,d  ;���½��к�
		 mov  ah,6  ;����BIOS�Ĺ��ܺ�
		 int 10h	;��ʾ����������
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

;--------------------------------------------------------------��ָ��locate_n ��궨λ
locate_n macro y,x   ;���ù���� (y��x)λ�ã����ù������λ��
					 ;ע�����������ǣ��кţ��кţ�����ʽ���к���y���к���x��
    mov bh,0         ;��ʾҳ��
	mov ah,2         
	mov dh,y         ;int10h�У�ah=2ʱ�����ù��λ�ã�dhΪ�кţ�dlΪ�к�
	mov dl,x         
	int 10h         
	endm
	
;---------------------------------------------------------------�ڵ�ǰ���ں��´�����ʾ 
show macro 
    mov bh,0     			;��ʾҳ
	mov cx,1 				;cx = �ַ��ظ����������ظ�һ��
    mov ah,0ah              ;�ڵ�ǰ�Ĵ��ڵĹ��λ�ô���ӡ�ַ������� 
	int 10h   
	
    locate_n nowy,nowx      ;�������õ�ǰ���λ�õ��´��ڵ���ȷλ�ô�
	mov bh,0     
	mov cx,1 
    mov ah,0ah              ;���´������     
	int 10h 
endm 

;----------------------------------------------------------------�����ַ����ж� 
getchar macro 					;һ��һ�����룬�жϣ����
   input:                    	;��������ϵ��ַ�  
       mov ah,0 
       int 16h                 	;BIOS���ã��Ӽ��̶��ַ�    

       cmp ah,4bh              	;�ж������ַ��Ƿ�Ϊ�����ɨ����
       jnz no_left				;����Ϊ�����ʱ������ִ�У�������תno_left  			
       locate_n lefty,leftx  	;���󣺹�����¶�λ���󴰿�
       mov windowstat,2     	;���´���״̬
       jmp input  				;��������
       
   no_left:   					;����ת������ת���󴰿�/�������Ҵ���
       cmp ah,4dh				;�ж������ַ��Ƿ�Ϊ�����
	   jnz no_right             ;����Ϊ�����ʱ������ִ�У�������תno_right
	   locate_n righty,rightx  	;���ң�������¶�λ���д���
	   mov windowstat,1     	;���´���״̬
	   jmp input				;��������
	   
   no_right: 
       cmp ah,01h               ;�ж������ַ��Ƿ�ΪESC     
	   jnz  continue			;û�н���������ִ��
       clear 0,0,24,79          ;��Ļ�ܴ�С��25*80
	   ret
	   
	continue:
       show  					;�������Ҽ���ESC,��Ƕ�׵��ú�show����ʾ����Ŀɴ�ӡ���ַ���
	   inc nowx   				;����ʾ�ַ����ٽ��´��ڸ��еĹ����кż�1�������Ƚ��Ƿ�Ҫ�Ͼ�
	   
       cmp nowx,65              ;�ж��´����Ƿ��Ͼ�    
	   jle goright              ;<=65: isright��ʾ�´����е�ǰ����п���������
       scroll 1,18,15,22,65     ;>65:  ����һ�е����Ҷˣ�Ҫ���Ͼ�һ��
	   mov nowx,15              ;��λ���Ͼ�һ�к󣬵�ǰ�кű�Ϊ��ǰ��������ߵ��е��к�
	   
   goright:            			;�ж��󴰿�/�Ҵ��ڵ��Ҳ�����         
       cmp windowstat,1         ;�ж��Ƿ����Ҵ���     
	   jnz showleft				;���Ҵ��ڣ�showright;����showleft
	
   showright:                   ;�ж��Ҵ����Ƿ��Ͼ�     
       inc rightx				;����+1
	   cmp rightx,70			
	   jle rightexit            ;<= 70: rightexit��ʾ�Ҵ����е�ǰ����п��������ߣ������Ͼ�
       scroll 1,5,50,15,70 		;> 70 : �Ͼ�һ��  
	   mov rightx,50   				;��λ���ָ��к�
	   
   rightexit:                   ;�Ҵ������     
      locate_n righty,rightx     	;��λ���Ҵ��ڵĹ��λ��
	  jmp input 				;��������
	  
   showleft:                    ;�ж��󴰿��Ƿ��Ͼ�  ��ͬright�Ĳ�����   
      inc leftx     				
	  cmp leftx,30     
	  jle leftexit 
      scroll 1,5,10,15,30     
	  mov leftx,10
	      
   leftexit:                    ;�󴰿����     
      locate_n lefty,leftx     
	  jmp input					;��������
 
      endm        ;getchar macro endm
CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS
START:
	main proc far
		push ds
		sub ax,ax
		push ax
		mov ax,DATAS
		mov ds,ax
		;��ʼ����ʾ
		clear 0,0,24,79
		
		;����scroll���õ�¼ʱ����������
		scroll 10,5,10,15,30  
		scroll 10,5,50,15,70  
		scroll 4,18,15,22,65 ;�Ͼ�4�У�����Ϊ�´���һ��������4�У��õ�һ�������ݵĴ���
		locate_n inity,initx	;���ó�ʼ���Ĺ��λ��
		getchar
		ret
	main endp
CODES ENDS
    END START

