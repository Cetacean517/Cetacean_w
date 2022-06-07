//
// Created by Eddie on 2022/5/3.
//

#ifndef MY_COMPILER_TOKENLIZER_H
#define MY_COMPILER_TOKENLIZER_H
#include <fstream>
#include <string>
#include <vector>
std::vector<std::pair<std::string,std::string>> tokenlizer(std::ifstream &infile, std::ofstream &outfile);
enum states {
    START, WORD, NUMBER, OPERATOR, BOUND
};
#endif //MY_COMPILER_TOKENLIZER_H