;����ƥ���ַ���
data segment
	mess1 db 'Enter keyword:$'
    mess2 db 'Enter Sentence:$'
    mess3 db 'Match!$'
    mess4 db 'Match at location:$'
    mess5 db 'H of the sentence.$'
    mess6 db 'No match!$'
    mess7 db 13,10,'$' ;ȡ�����еĻس��������
    ;XLATָ�����裬�������
    tab db 030h,031h,032h,033h,034h,035h,036h,037h,038h,039h,041h,042h,043h,044h,045h,046h
    keyword label byte ;labelαָ�����һ��keyword��������ռ�
    	max1 db 20     ;keyword�����ռ䣬������max1
    	act1 db ?      ;keyword��ʵ�ʾ��룬������act1
    	kw db 20 dup(?);keyword�Ŀռ䴴����20��db�Ŀհ׿ռ�
    sentence label byte
    	max2 db 120
    	act2 db ?
    	sen db 120 dup(?)
    ;string1 db 120,120 dup(?)���������sentence��ͬ����һ��120��ʾ�������������
    ;string2 db 20,20 dup(?)
data ends

code segment
    assume cs:code,ds:data,es:data
start:
main proc far  
    push ds
    sub ax,ax
    push ax
    mov ax,data
    mov ds,ax
    mov es,ax;����ѹջ����
    
    lea dx,mess1
    mov ah,9
    int 21h;�����ʾ��䣺������ؼ���
    lea dx,keyword
    mov ah,0ah
    int 21h;�Ӽ��̶���ؼ��ִ��ڻ��������س�����
    ;sub ch,ch
    ;mov cl,[string2+1];�ؼ��ֳ���
    ;lea si,string2+2;�ؼ�����ʼ�ַ�
    lea dx,mess7
    mov ah,9
    int 21h;�س�����
    
resentence:
    lea dx,mess2
    mov ah,9
    int 21h;�����ʾ��䣺��������ӡ����ӿ����ظ����룬���Ըò��ֿ���ѭ��
    lea dx,sentence
    mov ah,0ah
    int 21h;�Ӽ��̶�����Ӵ��ڻ��������س�����
    ;sub ch,ch
    ;mov ch,[string1+1];���ӳ���
    ;lea di,string1+2;������ʼ�ַ�
    lea dx,mess7
    mov ah,9
    int 21h;�س�����
    
    mov ax,0;���þ��ӿ�ʼ�Ƚϵ�λ�ã���ͷ��ʼ
docompare:
    sub cx,cx
    mov cl,act1  ;�ؼ���ʵ�ʳ��ȣ�����cl
    lea si,kw    ;ȡ�ؼ�����Ч��ַ������si
    lea bx,sen   ;ȡ������Ч��ַ������bx
    add bl,al    ;��ʼ�Ƚϵ�λ��
    mov di,bx    ;�����ӿ�ʼ�Ƚϵ���Ч��ַ������di
    
    ;�������в���ǰ����Ҫ���Ƚϵ��������ֱ����si,di�����Ƚ�λ������cl
    cld          ;df=0 ����Ƚ�
    repe cmpsb   ;�ظ����Ƚϲ���ֱ����ȣ�����match
    jz domatch   ;���zf=1,����match
    
    inc al       ;ax��¼��ƫ����������
    cmp al,act2  ;�ж��Ƿ�Խ�磬al��ʾ�������ھ��ӵĵط���act2��ʾ����ʵ�ʳ���
    jnb notmatch ;al��С��act2��Խ�磬����û��ƥ��
    jmp docompare;����û�Ƚ���ɣ������Ƚ�

domatch:;�ַ���ƥ�䣬���ʮ�����Ƶ�λ��
	lea dx,mess3
    mov ah,9
    int 21h;�����ʾ��䣺ƥ�䣡
    lea dx,mess7
    mov ah,9
    int 21h;�س�����
    
	lea dx,mess4
    mov ah,9
    int 21h;�����ʾ���
    
    add al,1  ;�ҵ�ƥ��λ�ã���Ϊ�����Ĭ�ϴ�0��ʼ����������ʵ��ƥ��λ����al+1
    sub cx,cx
    mov ch,al ;����һ��ƥ��λ�ã���������ʮ�����ƣ���Ҫ������ʾ����Ļ��
	mov bl,al ;��ʾ��һλʮ������
	mov cl,4
	shr bl,cl ;����4λ������λ����1��������������cl�����ƺ��λΪ0����λ��ԭ����ʮ�����Ƹ�λ
	mov al,bl ;�����ƺ�����ݷ���al�����в��������õ��Ľ����ʮ�����Ƹ�λ��Ӧ�����ֵ�ASCII��
	lea bx,tab;�����ƫ�Ƶ�ַ����bx��������ǰ����
	xlat      ;���ָ�����bxΪ�׵�ַ��ƫ�Ƶ�ַΪal�������͵�al
	mov dl,al ;��ʱ����al�е���ʮ�����Ƹ�λ�����ֶ�Ӧ��ASCII��
	mov ah,2
	int 21h   ;��ʱ���������䣬�������Ļ�ϵ���ԭ��Ӧ���������Ļ�ϵ�ʮ�����Ƶĸ�λ
	
	and ch,0fh;ƥ��λ����0fh���õ��Ľ����Ӧ�������ʮ�����Ƶĵ�λ����λΪ0
	mov al,ch
	lea bx,tab
	xlat
	mov dl,al ;���к͸�λһ���Ĳ��������������ʱ��Ļ����ʾ����Ӧ�������ʮ�����Ƶĵ�λ
	mov ah,2
	int 21h
    
    lea dx,mess5
    mov ah,9
    int 21h;�����ʾ���
    lea dx,mess7
    mov ah,9
    int 21h;�س�����
	lea dx,mess7
    mov ah,9
    int 21h;�س�����
    jmp resentence;����Ҫ����ӿ��ظ����룬��������ת��������Ӳ���

notmatch:;�ַ�����ƥ��
	lea dx,mess6
    mov ah,9
    int 21h;�����ʾ��䣺�ַ�����ƥ��
    lea dx,mess7
    mov ah,09
    int 21h;�س�����
    lea dx,mess7
    mov ah,09
    int 21h;�س�����
    jmp resentence;�ظ��������

exit:ret
    
main endp
code ends
end start


