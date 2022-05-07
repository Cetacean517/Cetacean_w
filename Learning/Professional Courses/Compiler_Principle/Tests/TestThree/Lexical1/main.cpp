//基于LL(1)法的条件语句语法语义分析程序
#include <iostream>
#include<fstream>
#include <string>
#include <iomanip>
#include <malloc.h>
#include <cstring>

using namespace std;

enum keyword{ $right_paren,$left_paren,$mul,$div,$add,$sub,$fenhao,
    $equal,$IF,$THEN,$ELSE,$greater,$less,$id,$num,$end};

typedef struct Token
{
    keyword type;
    char ch;
}Token;

typedef enum{JUMP,JG,JL,equal_m,END,add,mul,sub, div_m}OpKind;
typedef struct
{
    int label;               //标号
    OpKind op;               //操作符
    char par1,par2;          //操作数
    union
    {
        char result;         //结果
        int address;         //地址
    };
}Quad;                       //四元式入口

#define MAX_TOKEN 256        //Token表大小
#define MAX_QUAD 256         //四元式数组大小

Token tokentable[MAX_TOKEN];
Quad quad[MAX_QUAD];
int token_index;             //token表索引
int total_len;               //token表有效长度

int quad_len;                //四元式表有效长度
int quad_index;              //四元式索引
Token cur;
Token queue[10];
int label,k,one;             //标记接口
char curchar;                //存储当前待比较字符
char curtocmp;               //存储当前栈顶字符

ifstream ins;
int trueadd,falseadd,end_m;
int table[5][8]={{1,0,0,0,0,1,0,0},
                 {0,1,1,0,0,0,1,1},
                 {1,0,0,0,0,1,0,0},
                 {0,1,1,1,1,0,1,1},
                 {1,0,0,0,0,1,0,0}}; //存储预测分析表，1为有产生式，0为没有
int i,j;
int flag;
struct Lchar
{
    char char_ch;
    struct Lchar *next;
}Lchar,*temp,*top,*base;
int right_m;            //定义开关项


bool initialize(char filename[255]);
bool accidence();
void print();
void backpath(int,int);
//void ERROR();
void sentence();
void boolean();
bool nexttoken();
char newchar();
void push();
char dosome(void);         //算法函数
void pushs(char pchar);    //入栈函数
void pop(void);            //出栈函数
void doforpush(int t);     //根据数组下标计算的值产生式入栈
void changchartoint();     //根据curchar,curtocmp转为数字以判断是否有产生式
void semantic();           //语法语义分析
char LLE1();               //LL(1)文法分析
void printQuad();          //输出四元式
void ERROR(char str[20]);
void AD_ADDRESS(int nlabel,OpKind nop,char npar1,char npar2,int naddress);
void AD_RESULT(int nlabel,OpKind nop,char npar1,char npar2, char nresult);


int main()
{
    cout<<"********************************************************"<<endl
        <<"*                                                      *"<<endl
        <<"*        基于LL(1)法的条件语句语法语义分析程序         *"<<endl
        <<"*                                                      *"<<endl
        <<"********************************************************"<<endl
        <<endl
        <<"                 输入待编译文件名:";
    char fname[100];
    cin>>fname;
    if(!initialize(fname))
        return 0;
    if(!accidence())
        return 0;
    char ch;
    while(1)
    {
        if(ins.eof())
            break;
        ins>>ch;
    }
    cout<<endl<<"词法分析结果如下:"<<endl;
    print();
    cout<<endl;
    cout<<"词法分析结束。"<<endl<<endl<<endl;
    semantic();          //语法语义分析
    cout<<endl<<"输出四元式:"<<endl;
    printQuad();
    if(right_m==1)
        cout<<"分析成功"<<endl;
    else
        cout<<"分析失败"<<endl;
    cout<<"语法语义分析结束"<<endl;
}//main

char newchar()
{   char p;
    p=char(k);
    k++;
    return p;
}

//文件打开初始化
bool initialize(char filename[100])
{
    one=0;
    token_index=0;
    total_len=0;
    quad_len=0;
    quad_index=0;
    label=0;
    end_m=0;
    k=48;
    ins.open(filename);
    if(ins.fail())
    {
        cout<<"文件打开出错!"<<endl;
        return false;
    }
    return true;
}

//词法分析
bool accidence()
{
    int k=0;
    char buf[16];
    char ch;
    while(1)
    {
        ins>>ch;
        if(ins.fail())
            break;
        while(ch==' ')
        {	ins>>ch;}
        if(ch=='I')
        {
            ins>>buf;
            if(strcmp(buf,"F")==0)
                tokentable[total_len++].type=$IF;
        }
        else if(ch=='T')
        {
            ins>>buf;
            if(strcmp(buf,"HEN")==0)
                tokentable[total_len++].type=$THEN;
        }
        else if(ch=='E')
        {
            ins>>buf;
            if(strcmp(buf,"LSE")==0)
                tokentable[total_len++].type=$ELSE;
        }
        else if(ch=='>')
        {
            tokentable[total_len++].type=$greater;
        }
        else if(ch=='<')
        {
            tokentable[total_len++].type=$less;
        }
        else if(ch=='=')
        {
            tokentable[total_len++].type=$equal;
        }
        else if((ch>='A'&& ch<='Z' )|| (ch>='a' && ch<='z'))
        {
            tokentable[total_len].type=$id;
            tokentable[total_len++].ch=ch;
        }
        else if(ch>='0' && ch<='9')
        {	tokentable[total_len].type=$num;
            tokentable[total_len++].ch =ch;
        }
        else
            switch (ch)
            {case '+' :
                    tokentable[total_len].type=$add;
                    tokentable[total_len++].ch =ch;
                    break;
                case '-' :
                    tokentable[total_len].type=$sub;
                    tokentable[total_len++].ch =ch;
                    break;
                case '/' :
                    tokentable[total_len].type=$div;
                    tokentable[total_len++].ch =ch;
                    break;
                case '*' :
                    tokentable[total_len].type=$mul;
                    tokentable[total_len++].ch =ch;
                    break;
                case ';' :
                    tokentable[total_len].type=$fenhao;
                    tokentable[total_len++].ch =ch;
                    break;
                case '(' :
                    tokentable[total_len].type=$left_paren;
                    tokentable[total_len++].ch =ch;
                    break;
                case ')' :
                    tokentable[total_len].type=$right_paren;
                    tokentable[total_len++].ch =ch;
                    break;
                default:cout<<"!"<<endl;
            }
    }
    return true;

}

//语法语义分析
void semantic()
{
    if(!nexttoken())
        ERROR("s(0)");
    cout<<"开始进行语法语义分析:"<<endl
        <<"所使用的产生式:"<<endl
        <<"<if语句>-> if E then S else S"<<endl
        <<"S->i=E"<<endl
        <<"E->TA"<<endl
        <<"A-> +TA|-TA|e"<<endl
        <<"T->FB"<<endl
        <<"B->*FB|/FB|e"<<endl
        <<"F->M|(E)"<<endl
        <<"M->id|num"<<endl
        <<"语法语义分析过程如下:"<<endl;
    if(cur.type==$IF)
    {
        boolean();            //分析布尔语句
        if(!nexttoken())
            ERROR("S(0)");
        if(cur.type==$THEN)
        {
            backpath(trueadd,quad_len);	           //回填出口
            sentence();        //分析语句
            end_m=quad_len;
            AD_ADDRESS(quad_len,JUMP,'-','-',end_m); //产生跳转地址的四元式
            if(cur.type==$ELSE)
            {
                backpath(falseadd,quad_len);
                sentence();
                backpath(end_m,quad_len);
            }
            else
                ERROR("S(else)");

        }
        else
        {
            ERROR("S(then)");
        }
    }
    else
        ERROR("S(if)");

    AD_RESULT(quad_len,END,0,0,'-');  //产生数值语句的四元式
}

//读下一单词
bool nexttoken()
{
    if(token_index>=total_len)
        return false;
    if(tokentable[token_index].type==$fenhao)
        token_index++;
    cur.type=tokentable[token_index].type;
    cur.ch=tokentable[token_index].ch;
    token_index++;
    return true;
}

//进队列
void push()
{ one=0;
    while(tokentable[token_index].type!=$fenhao)
    {
        queue[one].type=tokentable[token_index].type;
        queue[one].ch=tokentable[token_index].ch;
        cout<<queue[one].ch;
        token_index++;
        one++;
    }
    queue[one].type=$end;
    queue[one].ch='#';
    cout<<queue[one].ch<<endl;
}

//队列下一个字符
void next()
{
    cur.type=queue[one].type;
    cur.ch =queue[one].ch ;
    one++;

}

// 分析E->id < id | id > id语句
void boolean()
{
    char a,b;
    int c;
    if(!nexttoken())
        ERROR("E(0)");
    if(cur.type==$id||cur.type==$num)
    {
        a=cur.ch;
        if(!nexttoken())
            ERROR("E(0)");
        if(cur.type==$greater||cur.type==$less)
        {
            c=cur.type ;
            if(!nexttoken())
                ERROR("E(0)");
            if(cur.type==$id||cur.type==$num)
                b=cur.ch;
            else
                ERROR("E(id/num)");
            if(c==$greater)
            {
                trueadd=quad_len-1;
                falseadd=quad_len;
                AD_ADDRESS(quad_len,JG,a,b,trueadd);
                AD_ADDRESS(quad_len,JUMP,0,0,falseadd);
            }
            else
            {
                trueadd=quad_len;
                falseadd=quad_len+1;
                AD_ADDRESS(quad_len,JL,a,b,trueadd);
                AD_ADDRESS(quad_len,JUMP,0,0,falseadd);
            }
        }
        else
            ERROR("E(id/num)");
    }
    else
        ERROR("E(greater/less)");
}

//分析语句
void sentence()
{   char rtn;
    char c;
    if(!nexttoken())
        ERROR("S(0)");
    if(cur.type==$id)
    {
        c=cur.ch;
        if(!nexttoken())
            ERROR("S(0)");
        if(cur.type!=$equal)
            ERROR("S(equal_m)");
        push();
        one=0;
        rtn=LLE1();                                 //
        AD_RESULT(quad_len,equal_m,rtn,'-',c);
        nexttoken();
        while(cur.type==$id)
        {
            c=cur.ch;
            if(!nexttoken())
                ERROR("S(0)");
            if(cur.type!=$equal)
                ERROR("S(equal_m)");
            push();
            one=0;
            rtn=LLE1();                                   //
            AD_RESULT(quad_len,equal_m,rtn,'-',c);
            nexttoken();
        }
    }

}

//LL(1)文法分析
char LLE1()
{
    right_m=1;                     //开关项为1
    flag=0;
    char t;
    base=(struct Lchar *)malloc(sizeof(Lchar));   //初始化堆栈
    base->next=NULL;
    base->char_ch='#';
    temp=(struct Lchar *)malloc(sizeof(Lchar));
    temp->next=base;
    temp->char_ch='E';
    top=temp;                 //初始化堆栈
    t=dosome();  //开始识别
    if(right_m)    //如果开关项为1
        cout<<"OK!"<<endl;
    else
        cout<<"Error!"<<endl;
    return t;

}

//入栈函数
void pushs(char pchar)
{
    temp=(struct Lchar *)malloc(sizeof(Lchar));
    temp->char_ch=pchar;
    temp->next=top;
    top=temp;
}

//出栈函数
void pop(void)
{
    curtocmp=top->char_ch;
    if(top->char_ch!='#')
        top=top->next;
}

//根据数组下标计算的值产生式入栈
void doforpush(int t)
{
    switch(t)
    {
        case 0:pushs('A');pushs('T');break;
        case 5:pushs('A');pushs('T');break;
        case 11:pushs('A');pushs('T');pushs('+');break;
        case 12:pushs('A');pushs('T');pushs('-');break;
        case 20:pushs('B');pushs('F');break;
        case 25:pushs('B');pushs('F');break;
        case 33:pushs('B');pushs('F');pushs('*');break;
        case 34:pushs('B');pushs('F');pushs('/');break;
        case 40:pushs('i');break;
        case 45:pushs(')');pushs('E');pushs('(');
    }
}

//根据curchar,curtocmp转为数字以判断是否有产生式
void changchartoint()
{
    switch(curtocmp)
    {
        case 'A':i=1;break;
        case 'B':i=3;break;
        case 'E':i=0;break;
        case 'T':i=2;break;
        case 'F':i=4;
    }
    switch(curchar)
    {
        case 'i':j=0;break;
        case '+':j=1;break;
        case '-':j=2;break;
        case '*':j=3;break;
        case '/':j=4;break;
        case '(':j=5;break;
        case ')':j=6;break;
        case '#':j=7;
    }
}

//算法函数
char dosome(void)
{
    int t,a=0;
    char bian1,bian2;
    OpKind opa;
    char c='$';
    next();
    for(;;)
    {
        pop();
        if(cur.type!=$id && cur.type!=$num)
            curchar=cur.ch;
        else
            curchar='i';
        cout<<endl<<curchar<<"    "<<curtocmp<<endl;
        if(curtocmp=='#' && curchar=='#')
            break;
        if(curtocmp=='A' || curtocmp=='B' || curtocmp=='E'
           || curtocmp=='T' || curtocmp=='F')   //当前字符为非终结符

        {
            if(curtocmp!='#')//当前比较字符不为'#'
            {
                changchartoint();
                if(j==0)
                {   a++;
                    flag++;
                    if(flag==1)
                    {   if(c=='$')
                            bian1=cur.ch;
                        else
                            bian1=c;


                    }
                    else if(flag==3)
                    {
                        bian2=cur.ch;
                        flag=1;
                        c=newchar();
                        AD_RESULT(quad_len,opa,bian1,bian2,c);//产生四元式

                    }
                }
                else
                {
                    switch(j)
                    {
                        case 1:opa=add;flag++;break;
                        case 2:opa=sub;flag++;break;
                        case 3:opa=mul;flag++;break;
                        case 4:opa=div_m;flag++;
                    }

                }
                if(table[i][j])             //有产生式
                {
                    t=10*i+j;               //计算产生式在数组中的位置
                    doforpush(t);
                    continue;
                }
                else                      //没有产生式
                {
                    right_m=0;                //出错
                    break;
                }
            }
            else                           //当前比较字符为'#'
            if(curtocmp!=curchar)
            {
                right_m=0;               //出错
                break;
            }
            else
                break;               //正确
        }
        else                             //当前字符为终结符
        if(curtocmp!=curchar)
        {
            right_m=0;                //出错
            break;
        }
        else
        {
            next();                  //读取下一个字符
            continue;
        }
    }
    if(a>1)
        return c;
    else
        return bian1;
}

//产生数值语句的四元式
void AD_RESULT(int nlabel,OpKind nop,char npar1,char npar2, char nresult)
{quad[quad_len].label=nlabel;
    quad[quad_len].op=nop;
    quad[quad_len].par1=npar1;
    quad[quad_len].par2=npar2;
    quad[quad_len].result=nresult;
    quad_len++;
}

//产生跳转地址的四元式
void AD_ADDRESS(int nlabel,OpKind nop,char npar1,char npar2,int naddress)
{	quad[quad_len].label=nlabel;
    quad[quad_len].op=nop;
    quad[quad_len].par1=npar1;
    quad[quad_len].par2=npar2;
    quad[quad_len].address=naddress;
    quad_len++;
}

//回填出口
void backpath(int nlabel,int addr)
{
    quad[nlabel].address=addr;
}

//错误处理
void ERROR(char str[20])
{   label++;
    cout<<endl;
    cout<<"error!  "<<str<<endl;
}

//输出单词表
void print()
{
    for(token_index=0;token_index<total_len;token_index++)
    {   if(token_index%4==0)
            cout<<endl;
        if(tokentable[token_index].type==$IF)
            cout<<setw(10)<<"IF";
        if(tokentable[token_index].type==$ELSE)
            cout<<setw(10)<<"ELSE";
        if(tokentable[token_index].type==$THEN)
            cout<<setw(10)<<"THEN";
        if(tokentable[token_index].type==$id)
            cout<<setw(10)<<tokentable[token_index].ch;
        if(tokentable[token_index].type==$num)
            cout<<setw(10)<<tokentable[token_index].ch;
        if(tokentable[token_index].type==$equal)
            cout<<setw(10)<<'=';
        if(tokentable[token_index].type==$greater)
            cout<<setw(10)<<'>';
        if(tokentable[token_index].type==$less)
            cout<<setw(10)<<'<';
        if(tokentable[token_index].type==$add)
            cout<<setw(10)<<'+';
        if(tokentable[token_index].type==$sub)
            cout<<setw(10)<<'-';
        if(tokentable[token_index].type==$mul)
            cout<<setw(10)<<'*';
        if(tokentable[token_index].type==$div)
            cout<<setw(10)<<'/';
        if(tokentable[token_index].type==$fenhao)
            cout<<setw(10)<<';';
        if(tokentable[token_index].type==$left_paren)
            cout<<setw(10)<<'(';
        if(tokentable[token_index].type==$right_paren)
            cout<<setw(10)<<')';
    }
    token_index=0;
}

//输出四元式
void printQuad()
{
    for(int i=0;i<quad_len;i++)
    {
        if(quad[i].label>-1)
            cout<<"L"<<quad[i].label<<":";
        else cout<<endl;
        if(quad[i].op==JG)
        {
            cout<<"J>,"<<quad[i].par1<<","<<quad[i].par2<<",L"<<quad[i].address<<endl;
        }
        else if(quad[i].op==JL)
        {
            cout<<"J<,"<<quad[i].par1<<","<<quad[i].par2<<",L"<<quad[i].address<<endl;
        }
        else if(quad[i].op==JUMP)
        {
            cout<<"J ,"<<"-,-,L"<<quad[i].address<<endl;
        }
        else if(quad[i].op==equal_m)
        {
            if(quad[i-1].result==quad[i].par1)
                cout<<"= ,"<<"T"<<quad[i].par1<<",-,"<<quad[i].result<<endl;
            else
                cout<<"= ,"<<quad[i].par1<<",-,"<<quad[i].result<<endl;
        }
        else if(quad[i].op==END)
        {
            cout<<"-,-,-,-"<<endl;
        }
        else if(quad[i].op==add)
        {  if(quad[i].result>='0' && quad[i].result<='9')
                cout<<"+ ,"<<quad[i].par1<<","<<quad[i].par2<<","<<"T"<<quad[i].result<<endl;
            else
                cout<<"+ ,"<<quad[i].par1<<","<<quad[i].par2<<","<<quad[i].result<<endl;
        }
        else if(quad[i].op==sub)
        {  if(quad[i].result>='0' && quad[i].result<='9')
                cout<<"- ,"<<quad[i].par1<<","<<quad[i].par2<<","<<"T"<<quad[i].result<<endl;
            else
                cout<<"- ,"<<quad[i].par1<<","<<quad[i].par2<<","<<quad[i].result<<endl;
        }
        else if(quad[i].op==div_m)
        {
            if(quad[i].result>='0' && quad[i].result<='9')
                cout<<"/ ,"<<quad[i].par1<<","<<quad[i].par2<<","<<"T"<<quad[i].result<<endl;
            else
                cout<<"/ ,"<<quad[i].par1<<","<<quad[i].par2<<","<<quad[i].result<<endl;
        }
        else if(quad[i].op==mul)
        {   if(quad[i].result>='0' && quad[i].result<='9')
                cout<<"* ,"<<quad[i].par1<<","<<quad[i].par2<<","<<"T"<<quad[i].result<<endl;
            else
                cout<<"* ,"<<quad[i].par1<<","<<quad[i].par2<<","<<quad[i].result<<endl;
        }
    }
}