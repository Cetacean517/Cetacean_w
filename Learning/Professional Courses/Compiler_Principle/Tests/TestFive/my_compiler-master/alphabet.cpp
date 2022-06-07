//
// Created by caozh on 2022/3/23.
//

#include "alphabet.h"

const unordered_map<string, string> alphabet::basic_word = {
        {"begin",     "beginsym"},
        {"call",      "callsym"},
        {"const",     "constsym"},
        {"do",        "dosym"},
        {"end",       "endsym"},
        {"if",        "ifsym"},
        {"odd",       "oddsym"},
        {"procedure", "proceduresym"},
        {"read",      "readsym"},
        {"then",      "thensym"},
        {"var",       "varsym"},
        {"while",     "whilesym"},
        {"write",     "writesym"}
};

const unordered_map<string, string> alphabet::operators = {
        {"+",         "plus"},
        {"-",         "minus"},
        {"*",         "times"},
        {"/",         "slash"},
        {"=",         "eql"},
        {"#",         "neq"},
        {"<",         "lss"},
        {"<=",        "leq"},
        {">",         "gtr"},
        {">=",        "geq"},
        {":=",        "becomes"}
};

const unordered_map<string,string> alphabet::boundary = {
        {"(",         "lparen"},
        {")",         "rparen"},
        {",",         "comma"},
        {";",         "semicolon"},
        {".",         "period"}
};

const vector<string> alphabet::bound = {"(",")",",",";","."};
const vector<string> alphabet::operators_list = {"+","-","*","/",":=","#","<","<=",">",">=","="};


bool alphabet::is_num(string &word) {
    for(char ch : word){
        if(ch<'0'||ch>'9')return false;
    }
    return true;
}

string alphabet::get_code(string &word) {
    if(is_basic_word(word)){
        return basic_word.find(word)->second;
    }else if(is_operators(word)){
        return operators.find(word)->second;
    }else if(is_boundary(word)){
        return boundary.find(word)->second;
    }else if(is_num(word)){
        return "number";
    }else{
        return "ident";
    }
}