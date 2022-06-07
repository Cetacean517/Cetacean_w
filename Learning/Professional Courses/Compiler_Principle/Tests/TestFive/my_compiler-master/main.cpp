#include <iostream>
#include "alphabet.h"
#include "tokenlizer.h"
#include "expression_analyzer.h"
#include "expression_calculator.h"

using namespace std;

int main() {
    for (int i = 8; i < 9; i++) {
        string in = "infile" + to_string(i) + ".txt";
        string out = "output" + to_string(i) + ".txt";
        ifstream infile(in);
        ofstream outfile(out);
        vector<pair<string, string>> token_list;
        // 获取token序列
        token_list = tokenlizer(infile, outfile);

        cout << endl<< "++++++ intermediate code and results ++++" << endl;
        vector<pair<Element, string>> elements_list;
        int line = 0;
        for (auto token: token_list) {
            if (token.first != "semicolon") {
                elements_list.emplace_back(get_type(token.first), token.second);
            } else {
                line++;
                elements_list.emplace_back(null,""); //$
                ExpressionCalculator calculator;
                cout << "==== Line" << line << " ==== " << endl;
                if (expression_validator(elements_list)) {
                    cout << "OK" << endl;
                    cout << calculator.calculate(elements_list) << endl;
                } else {
                    cout << " occur at line: " << line << endl;
                }
                elements_list.clear();
            }
        }
        infile.close();
        outfile.close();
    }
    return 0;
}