datasg segment
    mess1 db 'Enter keyword:','$'
    mess2 db 'Enter Sentence:','$'
    mess3 db 'Match at location:','$'
    mess4 db 'No match.',13,10,'$'
    mess5 db 'H of the sentence',13,10,'$'
    mess6 db 13,10,'$'
    keyword label byte
        max1 db 20
        act1 db ?
        kw db 20 dup(?)
    sentence label byte
        max2 db 120
        act2 db ?
        sen db 120 dup(?)
datasg ends

codesg segment
    assume cs:codesg,ds:datasg,es:datasg
start:
main proc far
    push ds
    xor ax,ax
    push ax
    mov ax,datasg
    mov ds,ax
    mov es,ax
    ;;;;;;��ʼ�Զ������
    lea dx,mess1
    mov ah,09
    int 21h         ;����09���ж����mess1
    lea dx,keyword
    mov ah,0ah
    int 21h         ;����0a���жϽ���keyword������
    lea dx,mess6    ;����/�س�
    mov ah,09
    int 21h
recome:
    lea dx,mess2    ;����09���ж����mess1
    mov ah,09
    int 21h
    lea dx,sentence ;����0a���жϽ���sentence������
    mov ah,0ah
    int 21h
    lea dx,mess6    ;����/�س�
    mov ah,09h
    int 21h

    mov ax,0
loop1:
    sub cx,cx   ;;;;
    mov cl,act1  ;�ؼ��ֳ��ȸ�ֵcl
    lea si,kw    ;ԭ���׵�ַkw
    lea bx,sen
    add bl,al
    mov di,bx    ;Ŀ�Ĵ��׵�ַ(���ϱ仯��ax��¼Ŀ�Ĵ�ƫ����)
    cld          ;df=0 ����Ƚ�
    repe cmpsb   ;
    jz match     ;���zf=1,match
    ;
    inc al       ;ax��¼��ƫ����
    cmp al,act2  ;�ж��Ƿ�Խ��,ע��Ҫ����(�����˰��죬д��ax�Ͳ���)
    jnb loop2     ;no match
    jmp loop1    ;��û�Ƚ����

match:
    mov bx,0
    mov bl,al
    add bx,1    ;��Ҫ��1��ʼ����
    lea dx,mess3
    mov ah,09
    int 21h
    ;;;���bx�е�ʮ��������
    mov cl,4
    rol bx,cl
    rol bx,cl
    mov ch,2     ;ch����ѭ����λ
rotate:          ;����ʹ�õ���ѭ��
    mov cl,4     ;cl����ÿ����4λ,rol�Ĳ�����������������
    rol bx,cl    ;ѭ������4λ
    mov ax,bx    
    and al,0fh   ;ȡ����λ
    add al,30H   ;��0��-��9�� ASCII 30H-39H ת��Ϊ
    cmp al,3aH   ;��3aС�������֣���ֱ����ת���
    jb printf    ;����ʹ�õ��˷�֧
    add al,07h   ;�����ټ���07h  ��A��-��F�� ASCII 41H-46H
printf: 
    mov dl,al        
    mov ah,2     ;����2���ж�����ַ���
    int 21h
    dec ch       ;ch-1
    jnz rotate   ;���ch������0������ѭ��
    ;;;;
    lea dx,mess5
    mov ah,09
    int 21h
    lea dx,mess6
    mov ah,09
    int 21h
    jmp recome
    
loop2:
    lea dx,mess4  ;;���NO match
    mov ah,09
    int 21h
    jmp recome
exit:
    ret
main endp
codesg ends
end start

