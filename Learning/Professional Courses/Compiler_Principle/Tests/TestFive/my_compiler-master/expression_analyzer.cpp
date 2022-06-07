//
// Created by Eddie on 2022/5/3.
//

#include "expression_analyzer.h"
#include <iostream>
#include <algorithm>
#include <stack>

Element get_type(const std::string& s) {
    if (s == "ident") return ident;
    if (s == "number") return number;
    if (s == "plus") return plus_;
    if (s == "minus") return minus_;
    if (s == "times") return times;
    if (s == "slash") return slash;
    if (s == "lparen") return lparen;
    if (s == "rparen") return rparen;
    return error;
}

std::string get_error_type(Element e) {
    std::string msg = "Unexpected ";
    switch (e) {
        case ident:
            msg += "ident";
            break;
        case number:
            msg += "number";
            break;
        case plus_:
            msg += "operator \"+\"";
            break;
        case minus_:
            msg += "operator \"-\"";
            break;
        case times:
            msg += "operator \"*\"";
            break;
        case slash:
            msg += "operator \"/\"";
            break;
        case lparen:
            msg += "delimiter \"(\"";
            break;
        case rparen:
            msg += "delimiter \")\"";
            break;
        case null:
            msg += "stop";
            break;
        default:
            msg += "error";
            break;
    }
    return msg;
}

std::vector<Element> next(Element current, Element type) {
    auto t = prediction_table.find(current)->second; //对于非终结符cur，能够接受的终结符类型map
    if (t.find(type) == t.end()) { // 如果token的type不包含在该map中，则出错
        std::cout << get_error_type(type);
        return {error};
    }
    /* 最左推导
     * e -> PE | E
     * 若type为plus_
     * 栈:expr_ $ -> Plus Expr $
     * */
    std::vector<Element> res = t.find(type)->second; // res代表分析的展开
    /*
     * prediction_table->second为正序，入栈应该倒序
     * */
    std::reverse(res.begin(), res.end());
    return res;
}

bool expression_validator(const std::vector<std::pair<Element, std::string>> &elements) {
    std::stack<Element> s;
    s.push(null); //$
    s.push(expr_);
    int counter = 0;
    // 输入一个token
    for (auto &token: elements) {
        ++counter;
        // 如果不是终结符则循环
        while (s.top()>=expr_) {
            auto cur = s.top(); // 拿栈顶
            s.pop(); // 出栈
            auto t = next(cur, token.first); // cur->非终结符 token.first->当前token的类型
            if (!t.empty() && t.at(0) == error)return false; // 错误处理
            for (auto &it: t) s.push(it); // 入栈
        }
        if (s.top() != token.first) { // 如果token类型和顶部（此时为终结符）不匹配，出错
            std::cout << counter << ':';
            std::cout << get_error_type(token.first) << '\n';
            return false;
        }
        s.pop();
    }
    return true;
}