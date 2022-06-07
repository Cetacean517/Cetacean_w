//
// Created by caozh on 2022/3/23.
//

#ifndef MY_COMPILER_ALPHABET_H
#define MY_COMPILER_ALPHABET_H

#include<unordered_map>
#include <string>
#include <vector>
using namespace std;

class alphabet {
private:
    const static unordered_map<string,string> basic_word;
    const static unordered_map<string,string> operators;
    const static unordered_map<string,string> boundary;
    const static vector<string> bound;
    const static vector<string> operators_list;
public:
    static bool is_basic_word(string& word){return basic_word.end()!=basic_word.find(word);}
    static bool is_operators(string& word){return operators.end()!=operators.find(word);}
    static bool is_boundary(string& word){return boundary.end()!=boundary.find(word);}
    static bool is_num(string& word);
    static vector<string> get_boundary(){return bound;};
    static vector<string> get_operators(){return operators_list;}
    static string get_code(string& word);
};


#endif //MY_COMPILER_ALPHABET_H
