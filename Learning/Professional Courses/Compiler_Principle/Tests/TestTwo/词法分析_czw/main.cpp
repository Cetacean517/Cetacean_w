#include <iostream>
#include "alphabet.h"
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

void read_input(ifstream &infile,ofstream &outfile){
    string sentence;
    vector<int> bound;
    vector<string> words;
    while(infile>>sentence){
        // 转小写
        transform(sentence.begin(),sentence.end(),sentence.begin(),(int(*)(int))tolower);
        bound.clear();
        words.clear();
        // 寻找操作符位置
        for(const string& split : alphabet::get_operators()){
            string::size_type pos=0;
            while((pos = sentence.find(split, pos))!=string::npos){
                // 找到 = 可能是 := , <= 或 >=
                if(sentence[pos-1]=='<'||sentence[pos-1]=='>'||sentence[pos-1]==':'){
                    pos++;
                    continue;
                }
                bound.emplace_back(pos);
                bound.emplace_back(pos+split.size());
                pos++;
            }
        }
        // 寻找界符位置
        for(const string& split : alphabet::get_boundary()){
            string::size_type pos=0;
            while((pos = sentence.find(split, pos))!=string::npos){
                bound.emplace_back(pos);
                bound.emplace_back(pos+split.size());
                pos++;
            }
        }
        // 得到所有分切位置
        sort(bound.begin(),bound.end());
        int start = 0;
        // 语句切片
        for(int end:bound){
            string sub = sentence.substr(start,end-start);
            if(sub!="")words.emplace_back(sub);
            start = end;
        }
        // 如果不需要切片输入整句
        if(bound.empty())words.emplace_back(sentence);
        // 获取类型
        for(string word: words){
            cout<<"("<<alphabet::get_code(word)<<", "<<word<<")"<<endl;
            outfile<<"("<<alphabet::get_code(word)<<", "<<word<<")"<<endl;
        }
    }
}

int main() {
    ifstream infile("infile2.txt");
    ofstream outfile("output.txt");
    read_input(infile,outfile);
    return 0;
}