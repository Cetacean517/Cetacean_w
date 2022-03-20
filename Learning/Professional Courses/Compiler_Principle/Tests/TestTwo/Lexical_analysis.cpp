#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

using namespace std;

// PL0的基本字单词和基本字编码
char basicWords[13][10] = {"begin","call","const","do","end","if","odd","procedure","read","then","var"," while","write"};
char basicCode[13][13] = {"beginsym","callsym","constsym","dosym","endsym"," ifsym","oddsym","proceduresym","readsym","thensym","varsym","whilesym","writesym"};

// 处理方法
void getInputContent(const char *fileName, char *content);
void contentToFile(const char* fileName, char* str);
void clearOutFile(const char* fileName);
bool isLetter(char ch);
bool isNumber(char ch);
bool isOperator(char ch);
bool isBoundary(char ch);
bool isReserved(char ch);
void getOperatorString(const char* outFileName, char *str);
void getBandString(const char* outFileName,char *str);
void Analysis(const char *fileName, const char *outFileName, char *content);

// 主函数入口
int main(){
    char* fN; char* outfN;
    cout << "Please enter the file name:" << endl;
    cin >> fN;
    strcpy(outfN,(char*)"out");
    strcat(outfN,fN);
    clearOutFile(outfN);                    // 清空输出文件的内容     
    char content[100000];
    Analysis(fN,outfN, content);
    return 0;
}

// 方法实现
// 读入处理过的文件内容函数
void getInputContent(const char *fileName, char *content){
    // fileName:读入文件全称，content:处理完的文件字符串
    int ch;
    int i = 0;
    FILE *file;
    file = fopen(fileName,"r");
    while ((ch = fgetc(file)) != EOF)
    {
        if(ch != '\n' && ch != '\t'){
            content[i++] = char(ch);
        } else{
            content[i++] = ' ';
        }
    }
    content[i] = '\0';
    fclose(file);
}
// 将输入内容顺序写入文件
void contentToFile(const char* fileName, char* str){
    FILE *fp;
    fp = fopen(fileName,"a");   // a：顺序写
    fputs(str,fp);
    fclose(fp);
}
// 将输入内容顺序写入文件
void clearOutFile(const char* fileName){
    FILE *fp;
    fp = fopen(fileName,"w");   // a：顺序写
    fputs("",fp);
    fclose(fp);
}
// 判断是否为字母
bool isLetter(char ch){
    return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'));
}
// 判断是否为数字
bool isNumber(char ch){
    return (ch>='0' && ch<='9');
}
// 判断是否为运算符
bool isOperator(char ch){
    string s = "+-*/=#<>=:";
    return ((s.find(ch) >= 0 && s.find(ch) <= 9)? true:false);
}
// 判断是否为边界符
bool isBoundary(char ch){
    string s = "(),;.";
    return ((s.find(ch) >= 0 && s.find(ch) <= 4)? true:false);
}
// 判断是否为保留字，返回保留字序号
int isReserved(char* word){
    int i;
    for(i = 0;i < 13; i++){
        if(!strcmp(word,basicWords[i])){
            return i;
        }
    }
    return -1;
}
// 输出连续的运算符
void getOperatorString(const char* outFileName, char *str){
    int i = 0, len = strlen(str);
    for(i = 0; i< len; i++){
        switch (str[i])
        {
        case '+':
            cout << "(plus,\t+)\n" << endl;
            contentToFile(outFileName,(char*)"(plus,\t+)\n");
            break;
        case '-':
            cout << "(minus,\t-)\n" << endl;
            contentToFile(outFileName,(char*)"(minus,\t-)\n");
            break;
        case '*':
            cout << "(times,\t*)\n" << endl;
            contentToFile(outFileName,(char*)"(times,\t*)\n");
            break;
        case '/':
            cout << "(slash,\t/)\n" << endl;
            contentToFile(outFileName,(char*)"(slash,\t/)\n");
            break;
        case '=':
            cout << "(eql,\t=)\n" << endl;
            contentToFile(outFileName,(char*)"(eql,\t=)\n");
            break;
        case ':':
            // 若非：=结构，则符号非法
            if(( i + 1 ) < len && str[i + 1] == '='){
                cout << "(becomes,\t:=)\n" << endl;
                contentToFile(outFileName,(char*)"(becomes,\t:=)\n");                
            } else {
                cout << "illeagal:  " <<str[i] << str[i+1]  << endl;
                contentToFile(outFileName,(char*)"illegal,\t:?");
                i++;
            }
            break;
        case '>':
            if( i+1 < len && str[i+1] == '='){
                cout << "(geq,\t>=)\n" << endl;
                contentToFile(outFileName,(char*)"(geq,\t>=)\n");
            } else {
                cout << "(gtr,\t>)\n" << endl;
                contentToFile(outFileName,(char*)"(gtr,\t>)\n");                
            }
            break;
        case '<':
            if( i+1 < len && str[i+1] == '='){
                cout << "(leq,\t<=)\n" << endl;
                contentToFile(outFileName,(char*)"(leq,\t<=)\n");
            } else {
                cout << "(lss,\t<)\n" << endl;
                contentToFile(outFileName,(char*)"(lss,\t<)\n");                
            }
        default:
            cout << "illeagal:  " <<str[i] << str[i+1]  << endl;
            contentToFile(outFileName,(char*)"illegal,\t:?");
            break;
        }
    }
}
// 输出连续的边界符
void getBandString(const char* outFileName,char *str){
    int i, len = strlen(str);
    for(i = 0; i < len; i++){
        switch (str[i])
        {
        case '(':
            cout << "(lparen,\t()\n" << endl;
            contentToFile(outFileName,(char*)"(lparen,\t()\n");
            break;
        case ')':
            cout << "(rparen,\t))\n" << endl;
            contentToFile(outFileName,(char*)"(rparen,\t))\n");
            break;
        case ',':
            cout << "(comma,\t,)\n" << endl;
            contentToFile(outFileName,(char*)"(comma,\t,)\n");
            break;
        case ';':
            cout << "(semicolon,\t;)\n" << endl;
            contentToFile(outFileName,(char*)"(semicolon,\t;)\n");
            break;
        case '.':
            cout << "(period,\t.)\n" << endl;
            contentToFile(outFileName,(char*)"(period,\t.)\n");
            break;
        default:
            break;
        }
    }
}
// 词法分析函数
void Analysis(const char *fileName, const char *outFileName, char *content){
    getInputContent(fileName, content);
    cout << content << endl;
    int len = strlen(content),i = 0,j = 0,tempLen,tempPos = 0,wordPos = 0,saveNum = 0;
    char tempWord[100],getWord[100];
    while (i < len){
        // 按照空格分割，每读入一个字符串，进行判断
        j = 0;  // 置位
        // 对于空格，直接跳过
        while(content[i] == ' ' && i < len){  
            i++;
        }
        // 对于非空格内容，进行读入
        while (content[i] != ' ' && i < len)
        {
            tempWord[j++] = content[i++];
        }
        tempWord[j] = '\0'; 
        tempLen = strlen(tempWord); // tempWord的长度
        tempPos = 0;
        while(tempPos < tempLen){
            // 1. 字母字符串：保留字，标识符
            if(isLetter(tempWord[tempPos])){
                while(!isOperator(tempWord[tempPos]) && !isBoundary(tempWord[tempPos]) && tempPos < tempLen){
                    getWord[wordPos++] = tempWord[tempPos++];
                };
                getWord[wordPos] = '\0';
                saveNum = isReserved(getWord);
                if (saveNum > -1){
                    // 单词是保留字
                    char str[25];
                    strcpy(str,"(");
                    strcat(str,basicCode[saveNum]);
                    strcat(str,",\t");
                    strcat(str, basicWords[saveNum]);
                    strcat(str,")\n");
                    cout << str << endl;
                    contentToFile(outFileName,str); // 输出到文档
                    strcpy(getWord,"");
                    wordPos = 0;
                } else {
                    // 单词是标识符
                    char str[15+strlen(getWord)];
                    strcpy(str,"(ident,\t");
                    strcat(str,getWord);
                    strcat(str,")\n");
                    cout << str << endl;
                    contentToFile(outFileName,str); // 输出到文档
                    strcpy(getWord,"");
                    wordPos = 0; 
                }
            }
            else if(isNumber(tempWord[tempPos])){
                // 2. 数字字符串
                while(isNumber(tempWord[tempPos]) && tempPos < tempLen){
                    getWord[wordPos++] = tempWord[tempPos++];
                }
                getWord[wordPos] = '\0';
                char str[15+strlen(getWord)];
                strcpy(str,"(number,\t");
                strcat(str,getWord);
                strcat(str,")\n");
                cout << str << endl;
                contentToFile(outFileName,str); // 输出到文档
                strcpy(getWord,"");
                wordPos = 0;                 
            }
            else if(isOperator(tempWord[tempPos])){
                // 3.运算符字符串
                while(isOperator(tempWord[tempPos]) && tempPos < tempLen){
                    getWord[wordPos++] = tempWord[tempPos++];
                }
                getWord[wordPos] = '\0';
                getOperatorString(outFileName,getWord);
                strcpy(getWord,"");
                wordPos = 0;                 
            }
            else if(isBoundary(tempWord[tempPos])){
                // 4.边界符字符串
                while(isBoundary(tempWord[tempPos]) && tempPos < tempLen){
                    getWord[wordPos++] = tempWord[tempPos++];
                }
                getWord[wordPos] = '\0';
                getBandString(outFileName,getWord);
                strcpy(getWord,"");
                wordPos = 0;                 
            }
        }
        strcpy(tempWord,"");
    }
}
