//
// Created by Fish on 2022/5/17.
//

#ifndef __EXPRESSIONCALCULATOR_H__
#define __EXPRESSIONCALCULATOR_H__

#include <algorithm>
#include <cassert>
#include <exception>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include "expression_analyzer.h"

/**
 * BNF:
 * expr -> [_plus] term {_plus term}
 * term -> factor {_times factor}
 * factor -> ident | number | lparen _expr rparen
 * _plus -> plus | minus
 * _times -> times | slash
*/

/**
 * SLR(1):
 * S -> E       {print(E.val)}
 * E -> E'PT    {E.val:=P.val(E'.val,T.val)}
 * E -> PT      {E.val:=P.val(T.val)}
 * E -> T       {E.val:=T.val}
 * T -> T'MF    {T.val:=M.val(T'.val,F.val)}
 * T -> F       {T.val:=F.val}
 * F -> (S)     {F.val:=S.val}
 * F -> n       {F.val:=n.lexval}
 * F -> i       {F.val:=i.lexval}
 * P -> +       {P.val:=+.lexval}
 * P -> -       {P.val:=-.lexval}
 * M -> *       {M.val:=*.lexval}
 * M -> /       {M.val:=/.lexval}
*/

enum Action
{   // 动作
    Accept, // acc
    Shift,  // S移进
    Reduce, // r规约
    Goto    // 遇非终结符，状态跳转
};

class NoSuchElementException : public std::exception
{
public:
    const char* what() const noexcept
    {
        return "No Such Element";
    }
};

class ExpressionException : public std::exception
{
private:
    std::string msg;

public:
    ExpressionException(Element obj);
    static std::string getErrorMessage(Element object);
    const char* what() const noexcept
    {
        return msg.c_str();
    }
};

typedef int TResult;
Element getElement(const std::string& s);
void __printitem(const std::pair<TResult, std::string>& item);

class ExpressionCalculator
{
private:
    // Gramma
    static const std::vector<std::pair<Element, std::vector<Element>>> production;
    static const std::vector<std::map<Element, std::pair<Action, int>>> f;
    static std::pair<Action, int> getNext(int current, Element type);
    static std::pair<Element, std::vector<Element>> getReduce(int id);

    // Semantic
    static TResult getLexval(Element obj, std::string);
    static TResult calc(TResult lhs, TResult op, TResult rhs);
    static TResult calc(TResult op, TResult rhs);
    static void print(Element op, std::pair<TResult, std::string> lhs, std::pair<TResult, std::string> rhs, std::pair<TResult, std::string> res);
    static void print(Element op, std::pair<TResult, std::string> rhs, std::pair<TResult, std::string> res);

public:
    TResult calculate(const std::vector<std::pair<Element, std::string>>& objects) const;
};

#endif
