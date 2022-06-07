#include <iostream>
#include "alphabet.h"
#include "tokenlizer.h"
#include "expression_analyzer.h"

using namespace std;

int main() {
    for (int i = 1; i < 2; i++) {
        string in = "infile" + to_string(i) + ".txt";
        string out = "output" + to_string(i) + ".txt";
        ifstream infile(in);
        ofstream outfile(out);
        vector<pair<string, string>> token_list;
        // 获取token序列
        token_list = tokenlizer(infile, outfile);
        cout<<"\ntokenize finished.\n\n";
        vector<pair<Element, string>> elements_list;
        int line = 0;
        for (auto token: token_list) {
            if (token.first != "semicolon") { //以;分割行，token是整个文件的token序列
                elements_list.emplace_back(get_type(token.first), token.second);
            } else {
                line++;
                elements_list.emplace_back(null,""); //$
                if (expression_validator(elements_list)) {
                    cout << line << ": OK" << endl;
                } else {
                    cout << " occur at row " << line << endl;
                }
                elements_list.clear();
            }
        }
        infile.close();
        outfile.close();
    }
    return 0;
}