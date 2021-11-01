DATAS SEGMENT
	;光标的初始位置
    inity 	db	15
    initx	db	50
    
    ;记录左窗口当前的光标位置，初始化为做窗口的初始位置
    leftx	db	10
    lefty   db  15 
  
    ;记录右窗口当前的光标位置，初始化为做窗口的初始位置
    rightx	db	50
    righty  db  15     
    
    ;记录下窗口当前的光标位置，初始化为下窗口初始位置
	nowx    db   15
	nowy    db   22  
	
	ulrow  	db  0
	ulcow  	db  0
	lrrow  	db  0
	lrcol  	db  0
	windowstat  db   1      ;=1，右边窗口，=2，左边窗口
DATAS ENDS

;宏指令clear清屏（左上行，左上列，右下行，右下列）
clear  macro a,b,c,d
         mov  al,0  ;整个窗口空白（设置上卷行数）
		 mov  bh,7  ;卷入行属性为07，是正常属性（设置卷入行属性）
		 mov  ch,a  ;左上角行号
		 mov  cl,b  ;左上角列号
		 mov  dh,c  ;右下角行号
		 mov  dl,d  ;右下角列号
		 mov  ah,6  ;设置BIOS的功能号
		 int 10h	;显示器驱动程序
endm

;-------------------------------------------------------------宏指令 scroll向上卷动一行 
scroll macro cont,ulrow,ulcol,lrrow,lrcol     
         mov al,cont                ;上卷行数 
		 mov bh,70h                 ;卷入行属性  
		 mov ch,ulrow               ;左上角行号 
         mov cl,ulcol               ;左上角列号 
         mov dh,lrrow               ;右下角行号  
         mov dl,lrcol               ;右下角列号  
         mov ah,6 
         int 10h                    ;BIOS调用，上卷		 
endm 

;--------------------------------------------------------------宏指令locate_n 光标定位
locate_n macro y,x   ;设置光标在 (y，x)位置，设置光标行列位置
					 ;注意这里坐标是（行号，列号）的形式，行号是y，列号是x）
    mov bh,0         ;显示页号
	mov ah,2         
	mov dh,y         ;int10h中，ah=2时，设置光标位置，dh为行号，dl为列号
	mov dl,x         
	int 10h         
	endm
	
;---------------------------------------------------------------在当前窗口和下窗口显示 
show macro 
    mov bh,0     			;显示页
	mov cx,1 				;cx = 字符重复个数，即重复一次
    mov ah,0ah              ;在当前的窗口的光标位置处打印字符和属性 
	int 10h   
	
    locate_n nowy,nowx      ;重新设置当前光标位置到下窗口的正确位置处
	mov bh,0     
	mov cx,1 
    mov ah,0ah              ;在下窗口输出     
	int 10h 
endm 

;----------------------------------------------------------------接收字符并判断 
getchar macro 					;一个一个读入，判断，输出
   input:                    	;输入键盘上的字符  
       mov ah,0 
       int 16h                 	;BIOS调用，从键盘读字符    

       cmp ah,4bh              	;判断输入字符是否为左向键扫描码
       jnz no_left				;输入为左向键时，继续执行；否则跳转no_left  			
       locate_n lefty,leftx  	;向左：光标重新定位到左窗口
       mov windowstat,2     	;更新窗口状态
       jmp input  				;继续输入
       
   no_left:   					;不跳转：已跳转至左窗口/保持在右窗口
       cmp ah,4dh				;判断输入字符是否为右向键
	   jnz no_right             ;输入为右向键时，继续执行；否则跳转no_right
	   locate_n righty,rightx  	;向右：光标重新定位到有窗口
	   mov windowstat,1     	;更新窗口状态
	   jmp input				;继续输入
	   
   no_right: 
       cmp ah,01h               ;判断输入字符是否为ESC     
	   jnz  continue			;没有结束，继续执行
       clear 0,0,24,79          ;屏幕总大小：25*80
	   ret
	   
	continue:
       show  					;不是左右键和ESC,则嵌套调用宏show（显示输入的可打印的字符）
	   inc nowx   				;先显示字符，再将下窗口该行的光标的列号加1，再来比较是否要上卷
	   
       cmp nowx,65              ;判断下窗口是否上卷    
	   jle goright              ;<=65: isright表示下窗口中当前光标行可以向右走
       scroll 1,18,15,22,65     ;>65:  到了一行的最右端，要向上卷一行
	   mov nowx,15              ;置位：上卷一行后，当前列号变为当前窗口最左边的列的列号
	   
   goright:            			;判断左窗口/右窗口的右侧输入         
       cmp windowstat,1         ;判断是否在右窗口     
	   jnz showleft				;在右窗口：showright;否则，showleft
	
   showright:                   ;判断右窗口是否上卷     
       inc rightx				;列数+1
	   cmp rightx,70			
	   jle rightexit            ;<= 70: rightexit表示右窗口中当前光标行可以向右走，不用上卷
       scroll 1,5,50,15,70 		;> 70 : 上卷一行  
	   mov rightx,50   				;置位，恢复列号
	   
   rightexit:                   ;右窗口输出     
      locate_n righty,rightx     	;定位到右窗口的光标位置
	  jmp input 				;继续输入
	  
   showleft:                    ;判断左窗口是否上卷  （同right的操作）   
      inc leftx     				
	  cmp leftx,30     
	  jle leftexit 
      scroll 1,5,10,15,30     
	  mov leftx,10
	      
   leftexit:                    ;左窗口输出     
      locate_n lefty,leftx     
	  jmp input					;继续输入
 
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
		;初始化显示
		clear 0,0,24,79
		
		;利用scroll设置登录时的三个窗口
		scroll 10,5,10,15,30  
		scroll 10,5,50,15,70  
		scroll 4,18,15,22,65 ;上卷4行，是因为下窗口一共能容纳4行，得到一个空内容的窗口
		locate_n inity,initx	;设置初始化的光标位置
		getchar
		ret
	main endp
CODES ENDS
    END START

