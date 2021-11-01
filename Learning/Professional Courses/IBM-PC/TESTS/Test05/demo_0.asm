datas   segment  
        cury   db   15
		curx   db   50  ;光标初始位置

		lx     db   10  
		ly     db   15  ;记录左窗口的当前光标位置，初始化为左窗口初始位置

		rx     db   50  
		ry     db   15  ;记录右窗口的当前光标位置，初始化为右窗口的初始位置

		dwx    db   15
		dwy    db   22  ;记录下窗口当前的光标位置，初始化为下窗口初始位置
		
		ulrow  db    0
		ulcow  db    0
		lrrow  db    0
		lrcol  db     0
		windowflag  db   1      ;=1，右边窗口，=2，左边窗口
datas   ends

;宏指令clear清屏
clear  macro a,b,c,d
         mov  al,0  ;上卷行数为0
		 mov  bh,7  ;卷入行属性为07，是正常属性
		 mov  ch,a  ;左上角行号
		 mov  cl,b  ;左上角列号
		 mov  dh,c  ;右下角行号
		 mov  dl,d  ;右下角列号
		 mov  ah,6  
		 int 10h
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

;--------------------------------------------------------------宏指令postc 光标定位
post_c macro y,x                     ;设置光标在 (y，x)位置，设置光标行列位置        
    mov bh,0             ;注意这里坐标是（行号，列号）的形式，行号是y，列号是x）
	mov ah,2         
	mov dh,y         ;int10h中，ah=2时，设置光标位置，dh为行号，dl为列号
	mov dl,x         
	int 10h         
	endm
;---------------------------------------------------------------在当前窗口和下窗口显示 
display macro 
    mov bh,0     
	mov cx,1 
    mov ah,0ah              ;在当前的窗口的光标位置处打印字符     
	int 10h   
	
    post_c dwy,dwx         ;重新设置当前光标位置到下窗口的正确位置处
	mov bh,0     
	mov cx,1 
    mov ah,0ah              ;在下窗口输出     
	int 10h 
endm 

;----------------------------------------------------------------接收字符并判断 
getchar macro 
   input:                   ;输入键盘上的字符  
       mov ah,0 
       int 16h                 ;BIOS调用，从键盘读字符    
   
       cmp ah,4bh              ;判断输入字符是否为左向键  扫描码
       jnz no_left  
       post_c ly,lx  
       mov windowflag,2     
       jmp input  
   no_left:   
       cmp ah,4dh  
	   jnz no_right            ;判断输入字符是否为右向键 
	   post_c ry,rx  
	   mov windowflag,1     
	   jmp input
   no_right: 
       cmp ah,01h               ;判断输入字符是否为ESC     
	   ;jz exit  
jnz  continue1
        clear 0,0,24,79             ;屏幕总大小为25*80的

ret
continue1:
 
       display  ;不是左右键和ESC那么就嵌套调用 宏display （显示输入的可打印的字符）

	   inc dwx   ;先显示字符，再将下窗口该行的光标的列号加1，再来比较是否要上卷
       cmp dwx,65              ;判断下窗口是否上卷     
	   jle isright                ;isright表示下窗口中当前光标行可以向右走
       scroll 1,18,15,22,65        ;到了一行的最右端，要向上卷一行
	   mov dwx,15              ;上卷一行后，当前列号变为当前窗口最左边的列的列号
   isright:                       
       cmp windowflag,1          ;判断是否在右窗口     
	   jnz displeft   
   dispright:                   ;判断右窗口是否上卷     
       inc rx      
	   cmp rx,70
	   jle rightexit             ;rightexit表示右窗口中当前光标行可以向右走，不用上卷

       scroll 1,5,50,15,70    
	   mov rx,50   
rightexit:                   ;右窗口输出     
      post_c ry,rx     
	  jmp input 
displeft:                    ;判断左窗口是否上卷     
      inc lx     
	  cmp lx,30     
	  jle leftexit 
      scroll 1,5,10,15,30     
	  mov lx,10    
leftexit:                    ;左窗口输出     
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
	scroll 10,5,10,15,30  ;scroll也可以设置窗口make three windows
	scroll 10,5,50,15,70  
	scroll 4,18,15,22,65 ;上卷4行，是因为下窗口一共能容纳4行，得到一个空内容的窗口
	
	post_c cury,curx  
	getchar
    ret
main endp 
codes ends 
   end start 


