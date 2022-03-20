# 实验二：词法分析

## 1. 变量声明

- basicWords : PL/0基本字单词
- basicCode: PL/0 基本字编码

## 2. 函数方法

- 读取内容：[void getInputContent(const char **fileName*, char **content*);](# 2.1 读取内容：**getInputContent(const char* fileName,  char*content)** )
- 输出内容：[void contentToFile(const char* *fileName*, char* *str*);](# 2.2 输出内容：void contentToFile(const char* *fileName*, char* *str*);)
- 初始化输出文件：[void clearOutFile(const char* *fileName*);](# 2.3 初始化输出文件：void clearOutFile(const char* *fileName*);)
- 判断字母：[bool isLetter(char *ch*);](# 2.4 判断是否为字母：**bool isLetter(char ch)**)
- 判断数字：[bool isNumber(char *ch*);](# 2.5 判断数字：bool isNumber(char *ch*);)
- 判断运算符：[bool isOperator(char *ch*);](# 2.6 判断运算符：bool isOperator(char *ch*);)
- 判断边界符：[bool isBoundary(char *ch*);](# 2.7 判断边界符：bool isBoundary(char *ch*);)
- 判断保留字：[bool isReserved(char *ch*);](# 2.8 判断保留字：bool isReserved(char *ch*);)
- 输出操作符串：[void getOperatorString(const char* *outFileName*, char **str*);](# 2.9 输出操作符串：void getOperatorString(const char* *outFileName*, char **str*);)
- 输出边界符串：[void getBandString(const char* *outFileName*,char **str*);](# 2.10 输出边界符串：void getBandString(const char* *outFileName*,char **str*);)
- 词法分析函数：[void Analysis(const char **fileName*, const char **outFileName*, char **content*);](# 2.11 词法分析函数：void Analysis(const char **fileName*, const char **outFileName*, char **content*);)


#### 2.1 读取内容：**getInputContent(const char* fileName,  char*content)** 

从文件读入内容，并进行处理。将换行和tab用' '（空格）替换

```c++
// 读入处理过的文件内容
void getInputContent(const char *fileName, char *content){
    char ch;
    int i = 0;
    FILE *file;
    file = fopen(fileName,"r");
    while ((ch = fgetc(file)) != EOF)
    {
        if(ch != '\n' && ch != '\t'){
            content[i++] = ch;
        } else{
            content[i++] = ' ';
        }
    }
    content[i] = '\0';
    fclose(file);
}
```

#### 结果

输入

```PL/0
const a=10;
var b,c;
begin
read(b);
c:=a+b;
write(c)
end.
```

输出

```C++
const a=10; var b,c; begin read(b); c:=a+b; write(c) end.
```
#### 2.2 输出内容：void contentToFile(const char* *fileName*, char* *str*);

FILE类的IO操作，“a"表示顺序写入。如果为“w”，则每次写入文件都会被清空。

```C++
// 将输入内容顺序写入文件
void contentToFile(const char* fileName, char* str){
    FILE *fp;
    fp = fopen(fileName,"a");   // a：顺序写
    fputs(str,fp);
    fclose(fp);
}
```

#### 2.3 初始化输出文件：void clearOutFile(const char* *fileName*);

```C++
// 清空输出文件中的内容
void clearOutFile(const char* fileName){
    FILE *fp;
    fp = fopen(fileName,"w");    // w：重置写
    fputs("",fp);
    fclose(fp);
}
```

#### 2.4 判断是否为字母：**bool isLetter(char ch)**
```C++
bool isLetter(char ch){
    return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'));
}
```
#### 2.5 判断数字：bool isNumber(char *ch*);

```C++
bool isNumber(char ch){
    return (ch>='0' && ch<='9');
}
```

#### 2.6 判断运算符：bool isOperator(char *ch*);

利用string类的find()函数进行判断。若出现在字符串长度内，则判断为运算符。

```C++
bool isOperator(char ch){
    string s = "+-*/=#<>=:";
    return ((s.find(ch) >= 0 && s.find(ch) <= 9)? true:false);
}
```

#### 2.7 判断边界符：bool isBoundary(char *ch*);

```c++
bool isBoundary(char ch){
    string s = "(),;.";
    return ((s.find(ch) >= 0 && s.find(ch) <= 4)? true:false);
}
```

#### 2.8 判断保留字：bool isReserved(char *ch*);

strcmp(): 若匹配一致，返回0；否则返回其他数字。

若为保留字，返回保留字的数组下标，否则返回-1。

```C++
int isReserved(char* word){
    int i;
    for(i = 0;i < 13; i++){
        if(!strcmp(word,basicWords[i])){
            return i;
        }
    }
    return -1;
}
```

#### 2.9 输出操作符串：void getOperatorString(const char* *outFileName*, char **str*);

```C++
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
```

#### 2.10 输出边界符串：void getBandString(const char* *outFileName*,char **str*);

```C++
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
```

#### [2.11 词法分析函数：void Analysis(const char **fileName*, const char **outFileName*, char **content*);](# 2. 函数方法)

```C++
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
```

## 3. 实现逻辑

1. 读入代码，去除换行制表符，用空格替代。
2. 用空格作为分割，读入连续字符串，并对字符串的类型进行判断（根据开头的字符类型）。
3. 字母字符串：保留字 / 标识符。
4. 数字字符串：数字
5. 符号字符串：单个符号，和连续符号组和
6. 边界字符串
7. 输出到文件