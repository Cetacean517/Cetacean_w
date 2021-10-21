data segment
	count dw 0;��¼�м�������-����
	temp dw 0 ;�����ݴ�
	telbook db 50 dup(32 dup(' '));����һ��50*32�ĺ��벾
	window1 db 13,10,13,10, '*******|Menu|*******' ,13,10;�˵���ʾ
	        db '1--Insert' , 13,10
	        db '2--Search' , 13,10
	        db '3--List' ,13,10
	        db '4--Quit' ,13,10
	        db '********************' ,13,10
	        db 'Select:' ,'$'
	window2 db 13,10,13,10, '******|Search|******' ,13,10;���Ҳ˵���ʾ
	        db '1--Name' , 13,10
	        db '2--Telephone' , 13,10
	        db '3--Quit' ,13,10
	        db '********************' ,13,10
	        db 'Select:' ,'$'
	str1 db 13,10,13,10, '1--Input name:' , '$'
	str2 db 13,10, '2--Input telephone:' , '$'
	str3 db 13,10,13,10, '--Name--------------Telephone--' ,13,10,13,10, '$'
	str4 db 13,10,13,10, 'Not exist!!!' , 13,10, '$'
	str5 db 13,10,13,10, '-----------------------------' ,13,10,13,10, '$'
	str6 db 13,10,13,10, 'No record!!!' , 13,10, '$'
	error db 13,10,13,10, 'Error!!!You should input 1-4 !' ,13,10, '$'
	error1 db 13,10,13,10, 'Error!!!You should input 1-3 !' ,13,10, '$'
	N_Temp db 21,? ;�������������21
	N_T db 20 dup (' '), ' ';������20��������ռ䣬�Լ����ķָ��ռ�
	T_Temp db 9,?  ;�������������9
	T_T db 8 dup (' '), ' ' ,13,10, '$';�绰���룬8��������ռ䣬���ָ�
data ends

;�����--������ macro ������������ʱ--������ ������
print macro x1;����ַ���
	lea dx,x1
	mov ah,9
	int 21h
endm

input macro x1;�������뵽������
	lea dx,x1
	mov ah,0ah
	int 21h
endm

quhc macro Temp,T        ;ȥ���س���������Temp�����ݸ���һ�ݵ�T��ʱ�򣬲�����Temp�����Ļس���
	sub dx,dx
	mov dl,Temp+1		 ;Temp�е��ַ���
	lea si,T             ;T��ƫ�Ƶ�ַ
	add si,dx            ;Tת�Ƶ�Temp����λ��
	mov byte ptr[si], ' ';�ѱ���Temp�Ļس�λ�õĻس��滻�ɿո�
endm

renew macro nn,cnt;��ԭ���������ݣ�������Ϊ�հ�����������
	local next
	mov cx,cnt    ;��Ϊ�ո��λ����inc�����Զ���cx���Ƚϣ������Զ�����loop
	lea si,nn     ;��ԭnn�����ݣ�������Ϊ�հ�����
	next:mov byte ptr[si], ' '
	     inc si
	     loop next
endm

code segment
	assume cs:code,ds:data
start:
	mov ax,data
	mov ds,ax
	mov es,ax
	lea di,telbook;di��Ϊ���벾��ƫ�Ƶ�ַ
	
	;���˵�����ѡ��
	L1:print window1
	   mov ah,1
	   int 21h
	   cmp al,'1';���ѡ��1�Ź��ܣ�����ת������Insert�ӳ���
	   jne L2    ;���������һ���ж�
	   call Insert
	   jmp L1
	L2:cmp al,'2';���ѡ��2�Ź��ܣ�����ת������Search�ӳ���
	   jne L3    ;���������һ���ж�
	   call Search
	   jmp L1
	L3:cmp al,'3';���ѡ��3�Ź��ܣ�����ת����ʾList�ӳ���
	   jne L4    ;���������һ���ж�
	   call List
	   jmp L1
	L4:cmp al,'4';���ѡ��4�Ź��ܣ�������DOS���������
	   je L5
	   print error;����ѡ�����������ʾ�������������
	   jmp L1
	   
Insert proc;�����ӳ���
	renew N_T,20    ;��ԭ����������
	renew T_T,8
	print str1
	input N_Temp    ;�������������ݴ滺���������س�������
	quhc N_Temp,N_T ;ȥ���س�������
	print str2
	input T_Temp    ;����绰�����ݴ滺���������س�������
	quhc T_Temp,T_T ;ȥ���س�������
	lea si,N_T      ;��������ƫ�Ƶ�ַ������si
	mov cx,20
	cld
	rep movsb       ;��si�е�20���ֽڵ��������ݰ��ֽڴ��͵�di����50*32�ĺ��벾��
	lea si,T_T
	mov cx,12
	cld
	rep movsb       ;��si�е�12���ֽڵĺ������ݰ��ֽڴ��͵�di����50*32�ĺ��벾��
	inc count       ;count��¼�м�����¼
	ret             ;����������
Insert endp

Search proc;�����ӳ���
;------------------------����������-----------------------;
	T0:print window2
	   mov ah,1
	   int 21h
	   cmp al,'1'      ;����������
	   jne T1          ;���������һ���ж�
	   print str1
	   renew N_Temp,20 ;�������������
	   input N_Temp    ;���������������ڻ�����
	   quhc N_Temp,N_T ;�����������ȥ���س���������
;************************����������************************;	   
	   mov cx,count            ;�����벾�д��ڵļ�¼�����浽cx��
	   mov Temp,offset telbook ;��Temp��¼���뱡��ƫ�Ƶ�ַ
	F3:push cx      ;cx��ջ���棬�����еļ�¼����
	   mov si,Temp  ;si��¼���뱡��ƫ�Ƶ�ַ
	   lea bx,N_T   ;���ո������������ƫ�Ƶ�ַ������bx��
	   mov cx,20    ;cx�б������������ֵ20
	F2:mov dl,[si]  ;���뱡��¼������dl
	   cmp dl,[bx]  ;���뱡�еļ�¼��ո�������������Ƚ�
	   jne F1       ;���������F1���ƶ����뱡�Ŀ�ʼλ��
	   inc si
	   inc bx       ;���������һλ�����Ƚ���һ���ֽ�
	   loop F2      ;cx��ʼֵΪ20��ÿ��loop������һ����0��������ʾ�����������Ƚ�
;*************cxΪ0��������20���ֽ�ȫ���Ƚ���ɣ���û������JNE������ƥ�䣬����ҵ��ļ�¼**************;
	   print str3   ;�ҵ��������¼
	   mov dx,Temp  ;��������¼���
	   mov ah,9
	   int 21h
	   print str5
	   pop cx       ;cx��ջ����غ��뱡�ļ�¼����
	   jmp F0       ;���ҽ������ҵ�������������
;*************�����ֲ�ƥ�䣬������һ�����ֿ�ʼ�ĵط���ֱ�����뱡�����м�¼���꣬���û�ҵ�************;
	F1:add Temp,32  ;��32���ֽڵ���һ��������ʼ��λ��
	   pop cx
	   loop F3      ;�ظ����Ҳ�����ֱ��cxΪ0ʱ������ע���ʱ��cx�ǳ�ջ���cx�������뱡��¼������
	   print str4   ;����loop����������ʱ����ʾ���뱡�еļ�¼���Ƚ���ɣ�û���ҵ�
	   jmp F0       ;���ҽ�����û�ҵ�������������

;------------------------���������-------------------------;
	T1:cmp al,'2'
	   jne T2          ;���������һ���ж�
	   print str2
	   renew T_Temp,8  ;��պ��뻺����
	   input T_Temp
	   quhc T_Temp,T_T ;�����뵽�������ĺ���ȥ���س�������
;--------------��������ң���������밴������ͬ��-----------;
	   mov cx,count
	   mov Temp,offset telbook
	K3:push cx
	   mov si,Temp
	   add si,20    ;��si��λ���Ƶ����뿪ʼ��λ�ã���Ϊ����ռ20���ֽڣ����Լ���20
	   lea bx,T_T
	   mov cx,8     ;����ռ8���ֽ�
	K2:mov dl,[si]
	   cmp dl,[bx]
	   jne K1       ;����Ⱦ�������һ�����뿪ʼ��λ�ã����¿�ʼ�Ƚ�
	   inc si
	   inc bx
	   loop K2
;----------------�ҵ����룬ƥ�䣬���������¼---------------;	   
	   print str3
	   mov dx,Temp
	   mov ah,9
	   int 21h
	   print str5
	   pop cx
	   jmp F0
;------------������һ�����룬ֱ�����м�¼�����ȹ�-----------;
	K1:add Temp,32
	   pop cx
	   loop K3
	   print str4   ;���м�¼û���ҵ������������ 
	   jmp F0
	T2:cmp al,'3'   ;��������������ѡ����
	   je F0
	   print error1 ;���϶������ϣ�����������������⣬�����ʾ��䲢�������ز��Ҳ˵�
	   jmp T0
	F0:ret
Search endp

List proc;��ʾ���뱡�ӳ���
	print str3
	cmp count,0
	je Z2          ;���countΪ0�����ʾ���뱡��û�м�¼
	mov cx,count   ;����Ҫ����ļ�¼���������浽cx������loopѭ������
	lea si,telbook ;�����뱡ƫ�Ƶ�ַ���浽si
 Z1:mov dx,si
	mov ah,9
	int 21h
	add si,32      ;����32��������һ����¼�ظ��������
	loop Z1
	jmp Z3
 Z2:print str6
 Z3:print str5
    ret
List endp

L5:mov ah,4ch      ;����DOS���������
   int 21h

code ends
end start




