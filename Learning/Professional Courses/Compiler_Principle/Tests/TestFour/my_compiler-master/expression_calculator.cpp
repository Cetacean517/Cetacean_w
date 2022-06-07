//
// Created by Fish on 2022/5/17.
//

#include "expression_calculator.h"

const std::vector<std::pair<Element, std::vector<Element>>>
ExpressionCalculator::production = {    // 文法：产生式
        {null, {Expr}},               //0
        {Expr, {Expr, Plus, Term}},   //1
        {Expr, {Plus, Term}},         //2
        {Expr, {Term}},               //3
        {Term, {Term, Multi, Factor}},//4
        {Term, {Factor}},             //5
        {Factor, {lparen, Expr, rparen}},//6
        {Factor, {ident}},            //7
        {Factor, {number}},           //8
        {Plus, {plus_}},              //9
        {Plus, {minus_}},             //10
        {Multi, {times}},             //11
        {Multi, {slash}}};            //12

const std::vector<std::map<Element, std::pair<Action, int>>> ExpressionCalculator::f = { //LR(0)分析表
        // 0
        {
                {lparen, {Shift, 1}},
                {plus_, {Shift, 2}},
                {minus_, {Shift, 3}},
                {ident, {Shift, 8}},
                {number, {Shift, 9}},
                {Expr, {Goto, 4}},
                {Term, {Goto, 7}},
                {Factor, {Goto, 5}},
                {Plus, {Goto, 6}}},
        // 1
        {
                {lparen, {Shift, 1}},
                {plus_, {Shift, 2}},
                {minus_, {Shift, 3}},
                {ident, {Shift, 8}},
                {number, {Shift, 9}},
                {Expr, {Goto, 10}},
                {Term, {Goto, 7}},
                {Factor, {Goto, 5}},
                {Plus, {Goto, 6}}},
        // 2
        {
                {lparen, {Reduce, 9}},
                {ident, {Reduce, 9}},
                {number, {Reduce, 9}},
        },
        // 3
        {
                {lparen, {Reduce, 10}},
                {number, {Reduce, 10}},
                {ident, {Reduce, 10}}},
        // 4
        {
                {plus_, {Shift, 2}},
                {minus_, {Shift, 3}},
                {null, {Accept, 0}},
                {Plus, {Goto, 11}}},
        // 5
        {
                {rparen, {Reduce, 5}},
                {plus_, {Reduce, 5}},
                {minus_, {Reduce, 5}},
                {times, {Reduce, 5}},
                {slash, {Reduce, 5}},
                {null, {Reduce, 5}}},
        // 6
        {
                {lparen, {Shift, 1}},
                {ident, {Shift, 8}},
                {number, {Shift, 9}},
                {Term, {Goto, 12}},
                {Factor, {Goto, 5}}},
        // 7
        {
                {rparen, {Reduce, 3}},
                {plus_, {Reduce, 3}},
                {minus_, {Reduce, 3}},
                {times, {Shift, 13}},
                {slash, {Shift, 14}},
                {null, {Reduce, 3}},
                {Multi, {Goto, 15}}},
        // 8
        {
                {rparen, {Reduce, 7}},
                {plus_, {Reduce, 7}},
                {minus_, {Reduce, 7}},
                {times, {Reduce, 7}},
                {slash, {Reduce, 7}},
                {null, {Reduce, 7}}},
        // 9
        {
                {rparen, {Reduce, 8}},
                {plus_, {Reduce, 8}},
                {minus_, {Reduce, 8}},
                {times, {Reduce, 8}},
                {slash, {Reduce, 8}},
                {null, {Reduce, 8}}},
        // 10
        {
                {rparen, {Shift, 16}},
                {plus_, {Shift, 2}},
                {minus_, {Shift, 3}},
                {Plus, {Goto, 11}}},
        // 11
        {
                {lparen, {Shift, 1}},
                {ident, {Shift, 8}},
                {number, {Shift, 9}},
                {Term, {Goto, 17}},
                {Factor, {Goto, 5}}},
        // 12
        {
                {rparen, {Reduce, 2}},
                {plus_, {Reduce, 2}},
                {minus_, {Reduce, 2}},
                {times, {Shift, 13}},
                {slash, {Shift, 14}},
                {null, {Reduce, 2}},
                {Multi, {Goto, 15}}},
        // 13
        {
                {lparen, {Reduce, 11}},
                {ident, {Reduce, 11}},
                {number, {Reduce, 11}},
        },
        // 14
        {
                {lparen, {Reduce, 12}},
                {ident, {Reduce, 12}},
                {number, {Reduce, 12}}},
        // 15
        {
                {lparen, {Shift, 1}},
                {ident, {Shift, 8}},
                {number, {Shift, 9}},
                {Factor, {Goto, 18}}},
        // 16
        {
                {rparen, {Reduce, 6}},
                {plus_, {Reduce, 6}},
                {minus_, {Reduce, 6}},
                {times, {Reduce, 6}},
                {slash, {Reduce, 6}},
                {null, {Reduce, 6}}},
        // 17
        {
                {rparen, {Reduce, 1}},
                {plus_, {Reduce, 1}},
                {minus_, {Reduce, 1}},
                {times, {Shift, 13}},
                {slash, {Shift, 14}},
                {null, {Reduce, 1}},
                {Multi, {Goto, 15}}},
        // 18
        {
                {rparen, {Reduce, 4}},
                {plus_, {Reduce, 4}},
                {minus_, {Reduce, 4}},
                {times, {Reduce, 4}},
                {slash, {Reduce, 4}},
                {null, {Reduce, 4}}}};


std::ostream& operator<<(std::ostream& out, const Element& obj)
{
    switch (obj)
    {
        case plus_:
            out << "+";
            break;
        case minus_:
            out << "-";
            break;
        case times:
            out << "*";
            break;
        case slash:
            out << "/";
            break;
        default:
            break;
    }
}
std::ostream& operator<<(std::ostream& out, const Action& act)
{
    switch (act)
    {
        case Accept:
            out << "Accept";
            break;
        case Shift:
            out << "Shift";
            break;
        case Reduce:
            out << "Reduce";
            break;
        case Goto:
            out << "Goto";
            break;
        default:
            break;
    }
    return out;
}
void __printitem(const std::pair<TResult, std::string>& item)
{
    if (item.second == "")
        std::cout << item.first;
    else
        std::cout << item.second;
}

ExpressionException::ExpressionException(Element obj) { msg = (getErrorMessage(obj)); }

std::string ExpressionException::getErrorMessage(Element obj)
{
    std::string msg = "Unexpect ";
    switch (obj)
    {
        case number:
            msg += "number";
            break;
        case ident:
            msg += "ident";
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
            msg += "EOF";
            break;
        default:
            msg = "Unknown Error";
            break;
    }
    msg.push_back('.');
    return msg;
}

std::pair<Action, int> ExpressionCalculator::getNext(int current, Element type)
{   // 通过栈顶数据和读入字符，根据LR(0)分析表，判断下一步Action
    auto it = f[current].find(type);
    if (it == f[current].end()) throw ExpressionException(type);
    return it->second;
}

std::pair<Element, std::vector<Element>> ExpressionCalculator::getReduce(int id)
{   // 生成递归过程依据的文法
    return production[id];
}

TResult ExpressionCalculator::getLexval(Element obj, std::string token)
{
    if (obj == number) return std::stoi(token);
    if (obj < number) return static_cast<TResult>(obj);
    return 0;
}

TResult ExpressionCalculator::calc(TResult lhs, TResult op, TResult rhs)
{   // 计算四则运算，并返回结果。参数：左操作数，运算符，右操作数
    if (op == plus_) return lhs + rhs;
    if (op == minus_) return lhs - rhs;
    if (op == times) return lhs * rhs;
    if (op == slash) return rhs ? lhs / rhs : 0;
    // :(
    std::cout << lhs << op<< rhs << std::endl;
    assert(false);
}

TResult ExpressionCalculator::calc(TResult op, TResult rhs)
{   // 计算正/负值
    if (op == plus_) return +rhs;
    if (op == minus_) return -rhs;
    // :(
    assert(false);
}

void ExpressionCalculator::print(Element op,
                                 std::pair<TResult, std::string> lhs,
                                 std::pair<TResult, std::string> rhs,
                                 std::pair<TResult, std::string> res)
{
    std::cout << '(' << op << ',';
    __printitem(lhs);
    std::cout << ',';
    __printitem(rhs);
    std::cout << ',';
    __printitem(res);
    std::cout << ')' << std::endl;
}

void ExpressionCalculator::print(Element op,
                                 std::pair<TResult, std::string> rhs,
                                 std::pair<TResult, std::string> res)
{
    std::cout << '(' << op << ',';
    __printitem(rhs);
    std::cout<<", ";
    std::cout << ',';
    __printitem(res);
    std::cout << ')' << std::endl;
}

TResult ExpressionCalculator::calculate(const std::vector<std::pair<Element, std::string>>& elements) const
{
    // state, token, result, id
    int counter = 0;
    std::stack<std::tuple<int, Element, std::pair<TResult, std::string>>> s;    // 状态，符号，计算值，id 栈
    s.push(std::make_tuple(0, null, std::make_pair(0, "")));    // 初始状态入栈：(0，#，(0，“”))
    for (auto&& [element, token] : elements)    // 对读入行进行分析计算
    {
        if(element == error){
            std::cout << "illegal operator, please rewrite your testing files" << std::endl;
        }
        for (;;)
        {
            auto action = getNext(std::get<0>(s.top()), element);
            // 根据获取的Action类型，进行下一步分析。
            if (action.first == Shift)
            {   // 移进,(状态，符号，(计算值，token))入栈
                s.push(std::make_tuple(action.second, element,
                                       std::make_pair(getLexval(element, token), token)));
                break;
            }
            else if (action.first == Reduce)
            {   // 规约
                auto it = getReduce(action.second);   //获取规约文法
                auto reduce = it.second;    // 从右往左，出栈
                std::reverse(reduce.begin(), reduce.end());
                static std::pair<TResult, std::string> buffer[3];   // 存放中间状态
                static int sz;
                sz = 0;
                for (auto&& r : reduce)
                {
                    assert(r == std::get<1>(s.top())); // 判断弹出的element是否和规约式一致
                    buffer[sz++] = std::get<2>(s.top());    // 栈顶的计算值压入buffer暂存
                    s.pop();    // 出栈
                }
                std::pair<TResult, std::string> res;
                if (sz == 1) {
                    auto temp = buffer[0];
                    res = buffer[0];    // buffer仅有单个元素，直接返回该元素。
                    if(reduce[0]==number){
                        buffer[0].second="t"+std::to_string(++counter);
                        res = buffer[0];
                    std::cout << "(:=" << ',';
                    __printitem(temp);
                    std::cout << ", ";
                    std::cout << ",t"+std::to_string(counter);
                    std::cout << ')' << std::endl;}
                }
                else if (sz == 2)
                {   // buffer有2个元素，计算结果，并输出中间代码。
                    res = std::make_pair(calc(buffer[1].first, buffer[0].first), "t" + std::to_string(++counter));
                    print(static_cast<Element>(buffer[1].first), buffer[0], res);
                }
                else if (sz == 3)
                {   // buffer有3个元素，分类讨论。
                    if (buffer[2].second == "(" && buffer[0].second == ")") // 含括号情况，直接返回中间值。
                        res = buffer[1];
                    else
                    {   // 3元计算式，计算结果，并输出中间代码。
                        res = std::make_pair(calc(buffer[2].first, buffer[1].first, buffer[0].first), "t" + std::to_string(++counter));
                        print(static_cast<Element>(buffer[1].first), buffer[2], buffer[0], res);    // 输出四元组
                    }
                }
                else //:(
                    assert(false);
                auto go = getNext(std::get<0>(s.top()), it.first);  // 获取下一步Action
                assert(go.first == Goto);   // Action仅能为Goto!
                s.push(std::make_tuple(go.second, it.first, res));  // 状态入栈，继续分析。
            }
            else if (action.first == Accept)
                return std::get<2>(s.top()).first;
            else // :(
                assert(false);
        }
    }
    // ：(
    assert(false);
}
