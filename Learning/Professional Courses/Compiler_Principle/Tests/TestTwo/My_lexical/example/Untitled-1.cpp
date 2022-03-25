#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<cstring>
using namespace std;
 
char stayWord[13][10]={"begin","call","const","do","end","if","odd","procedure","read","then","var"," while","write"};
char enumStayWord[13][15]={"beginsym","callsym","constsym","dosym","endsym"," ifsym","oddsym","proceduresym","readsym","thensym","varsym","whilesym","writesym"};
 
bool isNumber(char ch);
bool isCase(char ch);
bool isCaculationSymbol(char ch);
bool isBandSymbol(char ch);
int  isStayWord(char *str);
void getInputStreamFromFile(const char *fileName, char *str);
void calulationString(char *str);
void bandString(char *str);
void Analysis(const char *InputFileName, char *str);
 
int main()
{
    char str[100000];
    const char *input="demo.c";
        Analysis(input, str);
        return 0;
}
//判断该位置的符号是否是数字
bool isNumber(char ch) {
        if(ch>='0' && ch<='9') {
        return true;
    } else {
        return false;
    }
}
//判断该位置的符号是否是字母
bool isCase(char ch) {
        if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z')) {
        return true;   
    } else {
        return false;  
    }
 
}
//判断该位置是否是运算符的基本单位
bool isCaculationSymbol(char ch) {
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='>' || ch=='<' || ch=='=' || ch=='#' || ch==':') {
        return true;
    } else {
        return false;
    }
 
}
//判断该位置是否是边界符
bool isBandSymbol(char ch) {
        if(ch=='(' || ch==')' || ch==',' || ch==';' || ch=='.') {
        return true;
    } else {
        return false;
    }
 
}
//判断该位置是否是保留字
int isStayWord(char *str) {
        int aa;
        for(aa=0;aa<13;aa++) {
        if(!strcmp(str,stayWord[aa])) {
            break;
        }
    }
    return aa;
 
}
//连续的运算符处理
void calulationString(char *str)
{
        int aa=strlen(str);
        for(int i=0;i<aa;i++)
    {
                if(str[i]=='+') {   
            printf("(plus,\t\t+)\n");
        } else if(str[i]=='-') {  
            printf("(minus,\t\t-)\n");
        } else if(str[i]=='*') {  
            printf("(times,\t\t*)\n");
        } else if(str[i]=='/') {  
            printf("(slash,\t\t/)\n");
        } else if(str[i]=='=') {  
            printf("(eql,\t\t=)\n");
        } else if(str[i]==':') {
            //如果是i位置是 ’:’,若i+1位置不是 ‘=’,那么该符号非法
            if((i+1)<aa && str[i+1]=='=') { 
                printf("(becomes,\t:=)\n");
                i++;
            } else {  
                printf("(%c,\t非法字符！！！)\n",str[i]);  
            }
 
                } else if(str[i]=='>') {
            if(i+1<aa&&str[i+1]=='=') { 
                printf("(geq,\t\t>=)\n");
                i++;
            } else {  
                printf("(gtr,\t\t>)\n");
            }
                } else if(str[i]=='<') {
            if(i+1<aa&&str[i+1]=='=') { 
                printf("(leq,\t\t<=)\n");
                i++;
            } else {  
                printf("(lss,\t\t<)\n");
            }
 
                }
        else  {  
                printf("(%c,\t非法字符！！！)\n",str[i]);  
        }
    }
}
//获取一段连续的边界符号后，依次将其分解开
void bandString(char *str) {
        int i,k=strlen(str);
        for( i=0;i<k;i++) {
            switch(str[i]) {
                case '(':  
                printf("(lparen,\t()\n");
                break;
                    case ')':  
                printf("(rparen,\t))\n");
                break;
                    case ',':  
                printf("(comma,\t\t,)\n");
                break;
                    case ';':  
                printf("(semicolon,\t;)\n");
                break;
                case '.':  
                printf("(period,\t.)\n");
                break;
                    default:   
                break;
        }
        }
}
//从文件中获取将被分析的代码段
void getInputStreamFromFile(const char *fileName, char *str) {
        char ch;
        int i=0;
        FILE *fp;
        fp=fopen(fileName,"r");
        while((ch=fgetc(fp)) != EOF) {
                if(ch!='\n' && (int)ch!='\t') {
            str[i++]=ch;//去掉换行、Tab
        } else {
             
            str[i++]=' ';
        }
        }
        str[i]='\0';
        fclose(fp);
}
//词法分析函数
void Analysis(const char *InputFileName, char *str)
{
    getInputStreamFromFile(InputFileName, str);
    int lenth=strlen(str), i, j, bb, cc, dd, ee;
    char tempStr[100], smallStr[100];
    //每种类型的符号 其连续的个数是有限的……
    i=0;
 
    while(i < lenth)
    {
        j=0;
        //去掉开头的空格符号
        while(str[i]==' ' && i<lenth)
        { 
            i++; 
        }
        //获取两个空格之间的一段代码字符串
            while(str[i]!=' ' && i<lenth)
        { 
            tempStr[j++]=str[i++]; 
        }
            tempStr[j]='\0';
            bb=strlen(tempStr);
            cc=0;
        while(cc < bb)
        {
            //以字母开头
            if(isCase(tempStr[cc]))
            {
                //获取全是字母的一段字符串                     
                while((!isCaculationSymbol(tempStr[cc])) && (!isBandSymbol(tempStr[cc])) && cc<bb)
                {
                        smallStr[dd++]=tempStr[cc++];
                }
                smallStr[dd]='\0';
                cout << smallStr << endl;
                ee=isStayWord(smallStr);
                //字母串是保留字
                if(ee < 13)
                {
                        printf("(%s,\t%s)\n", enumStayWord[ee], stayWord[ee]);
                        strcpy(smallStr,"");
                        dd=0;
                }
                //字符串是标识符
                else
                {
                        printf("(ident,\t\t%s)\n", smallStr);
                        strcpy(smallStr,"");
                        dd=0;
                }
                }
            //以数字开头
            else if(isNumber(tempStr[cc]))
            {
                    while(isNumber(tempStr[cc]) && cc<bb)
                {
                            smallStr[dd++]=tempStr[cc++];
                }
                        smallStr[dd]='\0';
                        printf("(number,\t%s)\n",smallStr);
                        strcpy(smallStr,"");
                        dd=0;
                }
            //以运算符开头
            else if(isCaculationSymbol(tempStr[cc]))
            {
                    while(isCaculationSymbol(tempStr[cc]) && cc<bb)
                {
                        smallStr[dd++]=tempStr[cc++];
                }
                    smallStr[dd]='\0';
                    calulationString(smallStr);//连续的运算符
                    strcpy(smallStr,"");
                    dd=0;
            }
            //如果以边界符开头
            else if(isBandSymbol(tempStr[cc]))
            {
                    while(isBandSymbol(tempStr[cc]) && cc<bb)
                {
                        smallStr[dd++]=tempStr[cc++];
                }
                smallStr[dd]='\0';
                bandString(smallStr);   //l连续的界限符的处理……
                strcpy(smallStr,"");
                dd=0;
            }
            else
            {
                printf("无法识别的符号……\n");
                cc++;
            }
        }
        strcpy(tempStr,"");
    }
    fclose(stdout);
}