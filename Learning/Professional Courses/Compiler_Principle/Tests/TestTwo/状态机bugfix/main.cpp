#include <iostream>
#include "alphabet.h"
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

enum states{START,WORD,NUMBER,OPERATOR,BOUND};

void tokenizer(ifstream &infile,ofstream &outfile){
    char ch;
    int prestate = START;
    int state = START;
    string word = "";
    vector<string> words;
    while((ch = infile.get())!=EOF){
        if(ch>='A'&&ch<='Z')ch = tolower(ch);
        if(isalpha(ch)||ch=='_'){
            prestate = state;
            state = WORD;
        } else if (isdigit(ch)){
            prestate = state;
            if(state!=WORD)
                state=NUMBER;
        } else if(ch=='='||ch==':'||ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='#'||ch=='<'||ch=='>'){
            prestate = state;
            state = OPERATOR;
        } else if(ch=='.'||ch==';'||ch=='('||ch==')'||ch==','){
            prestate = state;
            state = BOUND;
        } else if(ch==' '||ch=='\n'){
            prestate = state;
            state = START;
        } else{
            prestate = state;
            state = START;
        }
        if(prestate!=state||state==BOUND){
            if(word!="")words.emplace_back(word);
            word = "";
        }
        if(state!=START)word+=ch;
    }
    if(word!="")words.emplace_back(word);
    for(string word:words){
        cout<<"("<<alphabet::get_code(word)<<", "<<word<<")"<<endl;
        outfile<<"("<<alphabet::get_code(word)<<", "<<word<<")"<<endl;
    }
}

int main() {
    ifstream infile("infile3.txt");
    ofstream outfile("output.txt");
    tokenizer(infile,outfile);
    return 0;
}