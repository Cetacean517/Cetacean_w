#include <iostream>
#include <string>
#include<stack>
#include<vector>
#include <fstream>

using namespace std;
int flag=0; //记录分析状态
int p=-1;//指针作用 当前扫描单词的下标
stack <int> State;  //状态栈
stack <string> in;  //符号栈
int error=0;//错误处理 当置1时就报错结束分析
//分析的单词，s1为编码，s2为单词符号
struct strs
{
    string s1,s2;
};

strs analystr;//当前分析的单词

//扫描下一个单词
void Advance(strs *S)
{
    p++;
    analystr = S[p];
}
//对应goto表，执行归约后，根据当前状态和符号确定哪一个状态应该进入State中
void Analy_goto()
{
    int state=State.top(); //取当前栈顶状态
    string si=in.top(); //当前符号栈的栈顶符号
    char sii=si[0];  //string->char转换
    switch(state)
    {
        //根据goto表，压入状态的代码
        case 0:
            if(sii=='E') State.push(1);
            else if(sii=='X') State.push(3);
            else if(sii=='Y') State.push(6);
            else if(sii=='A') State.push(2);
            else error=1;
            break;
        case 1:
            if(sii=='A') State.push(17);
            else error=1;
            break;
        case 2:
            if(sii=='X') State.push(10);
            else if(sii=='Y') State.push(6);
            else error=1;
            break;
        case 3:
            if(sii=='C') State.push(11);
            else error=1;
            break;
        case 9:
            if(sii=='E') State.push(14);
            else if(sii=='X') State.push(3);
            else if(sii=='Y') State.push(6);
            else if(sii=='A') State.push(2);
            else error=1;
            break;
        case 10:
            if(sii=='C') State.push(11);
            else error=1;
            break;
        case 11:
            if(sii=='Y') State.push(15);
            else error=1;
            break;
        case 14:
            if(sii=='A') State.push(17);
            else error=1;
            break;
        case 17:
            if(sii=='X') State.push(18);
            else if(sii=='Y') State.push(6);
            else error=1;
            break;
        case 18:
            if(sii=='C') State.push(11);
            else error=1;
            break;
        default:
            error=1;
            break;
    }
}
//对应action表，根据当前栈顶状态和面临的输入字符，进行移进或归约
void Analy_action(strs *S)
{
    int state=State.top();//取当前栈顶状态
    switch(state)
    {
        //根据action表选择操作的代码，下面仅选部分举例说明
        case 0:
            if(analystr.s1=="ident")
            {
                //移进操作
                State.push(7);//将状态7压入状态栈
                in.push(analystr.s2);//将当前符号压入符号栈
                Advance(S);//继续向前扫描
            }
            else if(analystr.s1=="number")
            {
                State.push(8);
                in.push(analystr.s2);
                Advance(S);
            }
            else if(analystr.s2=="(")
            {
                State.push(9);
                in.push(analystr.s2);
                Advance(S);
            }
            else if(analystr.s2=="+")
            {
                State.push(4);
                in.push(analystr.s2);
                Advance(S);
            }
            else if(analystr.s2=="-")
            {
                State.push(5);
                in.push(analystr.s2);
                Advance(S);
            }
            else error=1;
            break;
        case 1:
            if(analystr.s2=="+")
            {
                State.push(4);
                in.push(analystr.s2);
                Advance(S);
            }
            else if(analystr.s2=="-")
            {
                State.push(5);
                in.push(analystr.s2);
                Advance(S);
            }
            else if(analystr.s1=="#")
            {
                //状态1遇见#，扫描完成，成功匹配，将分析状态置1
                flag=1;
                p++;//用于退出main函数中的while循环
            }
            else error=1;
            break;
        case 2:
            if(analystr.s1=="ident")
            {
                State.push(7);
                in.push(analystr.s2);
                Advance(S);
            }
            else if(analystr.s1=="number")
            {
                State.push(8);
                in.push(analystr.s2);
                Advance(S);
            }
            else if(analystr.s2=="(")
            {
                State.push(9);
                in.push(analystr.s2);
                Advance(S);
            }
            else error=1;
            break;
        case 3:
            if(analystr.s2=="*")
            {
                State.push(12);
                in.push(analystr.s2);
                Advance(S);
            }
            else if(analystr.s2=="/")
            {
                State.push(13);
                in.push(analystr.s2);
                Advance(S);
            }
            else if(analystr.s2=="#" || analystr.s2=="+" || analystr.s2=="-" || analystr.s2==")")
            {
                //归约操作
                State.pop();//产生式中归约几个字符，State栈和in栈就pop几次
                in.pop();
                in.push("E");//压入归约后的字符
                Analy_goto();//查询goto表
            }
            else error=1;
            break;
        case 4:
            if(analystr.s1=="ident" || analystr.s1=="number" || analystr.s2=="(")
            {
                State.pop();
                in.pop();
                in.push("A");
                Analy_goto();
            }
            else error=1;
            break;
        case 5:
            if(analystr.s1=="ident" || analystr.s1=="number" || analystr.s2=="(")
            {
                State.pop();
                in.pop();
                in.push("A");
                Analy_goto();
            }
            else error=1;
            break;
        case 6:
            if(analystr.s2==")" || analystr.s2=="+" ||analystr.s2=="-" || analystr.s2=="*" || analystr.s2=="/" || analystr.s2=="#")
            {
                State.pop();
                in.pop();
                in.push("X");
                Analy_goto();
            }
            else error=1;
            break;
        case 7:
            if(analystr.s2==")" || analystr.s2=="+" ||analystr.s2=="-" || analystr.s2=="*" || analystr.s2=="/" || analystr.s2=="#")
            {
                State.pop();
                in.pop();
                in.push("Y");
                Analy_goto();
            }
            else error=1;

            break;
        case 8:
            if(analystr.s2==")" || analystr.s2=="+" ||analystr.s2=="-" || analystr.s2=="*" || analystr.s2=="/" || analystr.s2=="#")
            {
                State.pop();
                in.pop();
                in.push("Y");
                Analy_goto();
            }
            else error=1;
            break;
        case 9:
            if(analystr.s1=="ident")
            {
                State.push(7);
                in.push(analystr.s2);
                Advance(S);
            }
            else if(analystr.s1=="number")
            {
                State.push(8);
                in.push(analystr.s2);
                Advance(S);
            }
            else if(analystr.s2=="(")
            {
                State.push(9);
                in.push(analystr.s2);
                Advance(S);
            }
            else if(analystr.s2=="+")
            {
                State.push(4);
                in.push(analystr.s2);
                Advance(S);
            }
            else if(analystr.s2=="-")
            {
                State.push(5);
                in.push(analystr.s2);
                Advance(S);
            }
            else error=1;
            break;
        case 10:
            if(analystr.s2=="*")
            {
                State.push(12);
                in.push(analystr.s2);
                Advance(S);
            }
            else if(analystr.s2=="/")
            {
                State.push(13);
                in.push(analystr.s2);
                Advance(S);
            }
            else if(analystr.s2=="#" || analystr.s2=="+" || analystr.s2=="-" || analystr.s2==")")
            {
                State.pop();State.pop();
                in.pop();in.pop();
                in.push("E");
                Analy_goto();
            }
            else error=1;
            break;
        case 11:
            if(analystr.s1=="ident")
            {
                State.push(7);
                in.push(analystr.s2);
                Advance(S);
            }
            else if(analystr.s1=="number")
            {
                State.push(8);
                in.push(analystr.s2);
                Advance(S);
            }
            else if(analystr.s2=="(")
            {
                State.push(9);
                in.push(analystr.s2);
                Advance(S);
            }
            else error=1;
            break;
        case 12:
            if(analystr.s1=="ident" || analystr.s1=="number" || analystr.s2=="(")
            {
                State.pop();
                in.pop();
                in.push("C");
                Analy_goto();
            }
            else error=1;
            break;
        case 13:
            if(analystr.s1=="ident" || analystr.s1=="number" || analystr.s2=="(")
            {
                State.pop();
                in.pop();
                in.push("C");
                Analy_goto();
            }
            else error=1;
            break;
        case 14:
            if(analystr.s2==")")
            {
                State.push(16);
                in.push(analystr.s2);
                Advance(S);
            }
            else if(analystr.s2=="+")
            {
                State.push(4);
                in.push(analystr.s2);
                Advance(S);
            }
            else if(analystr.s2=="-")
            {
                State.push(5);
                in.push(analystr.s2);
                Advance(S);
            }
            else error=1;
            break;
        case 15:
            if(analystr.s2==")" || analystr.s2=="+" ||analystr.s2=="-" || analystr.s2=="*" || analystr.s2=="/" || analystr.s2=="#")
            {
                State.pop();State.pop();State.pop();
                in.pop();in.pop();in.pop();
                in.push("X");
                Analy_goto();
            }
            else error=1;
            break;
        case 16:
            if(analystr.s2==")" || analystr.s2=="+" ||analystr.s2=="-" || analystr.s2=="*" || analystr.s2=="/" || analystr.s2=="#")
            {
                State.pop();State.pop();State.pop();
                in.pop();in.pop();in.pop();
                in.push("Y");
                Analy_goto();
            }
            else error=1;
            break;
        case 17:
            if(analystr.s1=="ident")
            {
                State.push(7);
                in.push(analystr.s2);
                Advance(S);
            }
            else if(analystr.s1=="number")
            {
                State.push(8);
                in.push(analystr.s2);
                Advance(S);
            }
            else if(analystr.s2=="(")
            {
                State.push(9);
                in.push(analystr.s2);
                Advance(S);
            }
            else error=1;
            break;
        case 18:
            if(analystr.s2=="*")
            {
                State.push(12);
                in.push(analystr.s2);
                Advance(S);
            }
            else if(analystr.s2=="/")
            {
                State.push(13);
                in.push(analystr.s2);
                Advance(S);
            }
            else if(analystr.s2=="#" || analystr.s2=="+" || analystr.s2=="-" || analystr.s2==")")
            {
                State.pop();State.pop();State.pop();
                in.pop();in.pop();in.pop();
                in.push("E");
                Analy_goto();
            }
            else error=1;
            break;
        default:
            error=1;
            break;
    }
}
int main()
{
    string str,str1;
    int count=1;//记录输入单词的个数，再加上#
    while(cin>>str1){
        if(str1 == "%") break;
        cout << "1" << endl;
        str = str + str1 + ' ';
        count++;
    }//保存输入单词
/*处理输入单词，将所有单词存储在S数组中，方便扫描*/
    strs S[count];
    int len = str.size();
    int a=0,b=0,c=0;
    int j=0;
    cout << "2" << endl;
    for(int i=0;i<len;i++){
        if(str[i]=='(')
        {
            a=i+1;
            do
            {
                i++;
                if(str[i]==',') b=i;
            }while(!(str[i]==')' && str[i+1]==' '));
            c=i-1;
            S[j].s1=str.substr(a,b-a);
            S[j].s2=str.substr(b+1,c-b);
            j++;
        }
    }
    cout <<"3"<< endl;
    S[count-1].s1="#";//最后加上结束符#
    S[count-1].s2="#";
/*         开始分析           */
    int out=count; //保存需要分析的字串长度
    Advance(S);
    State.push(0);
    cout << "4" << endl;
    while(p<out && error==0)   //字串扫描完退出循环
    {
        Analy_action(S);
    }
    cout << "5" << endl;
    //判断分析结果
    if(flag==1) cout<<"Yes,it is correct."<<endl;
    else cout<<"No,it is wrong."<<endl;
    return 0;
}


