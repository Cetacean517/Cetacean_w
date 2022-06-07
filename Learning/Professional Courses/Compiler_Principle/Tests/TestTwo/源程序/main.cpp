#include <iostream>
#include "alphabet.h"
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

enum states {
    START, WORD, NUMBER, OPERATOR, BOUND
};

void tokenizer(ifstream &infile, ofstream &outfile) {
    char ch;
    // 设置初始状态
    int prestate = START;
    int state = START;
    string word = "";
    vector<string> words;
    int count_line = 1;
    string error_type = "";
    bool valid = true;
    while ((ch = infile.get()) != EOF) {
        // 大写改小写
        if (ch >= 'A' && ch <= 'Z')ch = tolower(ch);
        // 如果是字母或下划线，认为是单词
        if (isalpha(ch) || ch == '_') {
            prestate = state;
            state = WORD;
            // 如果是非字母状态下连接数字，认为是数字开始
        } else if (isdigit(ch)) {
            prestate = state;
            if (state != WORD)
                state = NUMBER;
            // 切换操作符状态
        } else if (ch == '=' || ch == ':' || ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '#' ||
                   ch == '<' || ch == '>') {
            prestate = state;
            state = OPERATOR;
            // 边界状态
        } else if (ch == '.' || ch == ';' || ch == '(' || ch == ')' || ch == ',') {
            prestate = state;
            state = BOUND;
            // 换行
        } else if (ch == ' ' || ch == '\n' || ch == '\t') {
            if (ch == '\n')count_line++;
            prestate = state;
            state = START;
            // 异常状态，重置到start
        } else {
            cout << "error \"illegal character\" occur at line " << count_line << ": " << ch << endl;
            outfile << "error \"illegal character\" occur at line " << count_line << ": " << ch << endl;
            prestate = state;
            state = START;
        }
        // 遇到字符和数字以外的字符认为是单词结束，如果是非法状态则切换并输出错误
        if(state != WORD && state != NUMBER && !valid){
            valid = true;
            cout << "error \""<<error_type<<"\" occur at line " << count_line << ": " << word << endl;
            outfile << "error \""<<error_type<<"\" occur at line " << count_line << ": " << word << endl;
            word = "";
        }
        if(!valid)word+=ch;
        // 状态切换则认为标识符切换，如果状态是边界则立刻输出，防止两个边界重叠
        if (prestate != state || state == BOUND || (prestate==OPERATOR && word.size()==2)) {
            if(prestate==NUMBER&&state==WORD){
                valid = false;
                error_type = "illegal number";
                word += ch;
                continue;
            }
            if (word != "") {
                // 标识符错误
                if (prestate == OPERATOR && alphabet::is_operators(word)
                    || prestate != OPERATOR) {
                    words.emplace_back(word);
                    // 从map获得对应的标识符类型
                    cout << "(" << alphabet::get_code(word) << ", " << word << ")" << endl;
                    outfile << "(" << alphabet::get_code(word) << ", " << word << ")" << endl;
                }
                else{
                    error_type = "illegal operator";
                    cout << "error \""<<error_type<<"\" occur at line " << count_line << ": " << word << endl;
                    outfile << "error \""<<error_type<<"\" occur at line " << count_line << ": " << word << endl;
                }
            }
            word = "";
        }
        // 非异常状态，拼接新字符
        if (valid && state != START)word += ch;
    }
    // 输出末尾的字符串
    if(word !=""&&valid){
        // 标识符错误
        if (prestate == OPERATOR && alphabet::is_operators(word)
            || prestate != OPERATOR) {
            words.emplace_back(word);
            // 从map获得对应的标识符类型
            cout << "(" << alphabet::get_code(word) << ", " << word << ")" << endl;
            outfile << "(" << alphabet::get_code(word) << ", " << word << ")" << endl;
        }
        else{
            error_type = "illegal operator";
            cout << "error \""<<error_type<<"\" occur at line " << count_line << ": " << word << endl;
            outfile << "error \""<<error_type<<"\" occur at line " << count_line << ": " << word << endl;
        }
        // 如果末尾的标识符是非法数字
    }else if(word!=""){
        cout << "error \""<<error_type<<"\" occur at line " << count_line << ": " << word << endl;
        outfile << "error \""<<error_type<<"\" occur at line " << count_line << ": " << word << endl;
    }
}

int main() {
    for (int i = 1; i < 7; i++) {
        string in = "C:\\Users\\18378\\Desktop\\编译实验\\实验二\\源程序\\test_files\\infile" + to_string(i) + ".txt";
        string out = "output" + to_string(i) + ".txt";
        ifstream infile(in);
        ofstream outfile(out);
        tokenizer(infile, outfile);
        infile.close();
        outfile.close();
    }
    return 0;
}
