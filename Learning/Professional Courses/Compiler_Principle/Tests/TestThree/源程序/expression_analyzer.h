//
// Created by Eddie on 2022/5/3.
//

#ifndef MY_COMPILER_EXPRESSION_ANALYZER_H
#define MY_COMPILER_EXPRESSION_ANALYZER_H

#include <map>
#include <vector>
#include <string>
/**
* 尖括号 < > 内包含的为必选项；
* 方括号 [ ] 内包含的为可选项；
* 大括号 { } 内包含的为可重复0至无数次的项；
* 圆括号 ( ) 内包含的所有项为一组，用来控制表达式的优先级；
* 竖线 | 表示在其左右两边任选一项，相当于"OR"的意思；
* ::= 是“被定义为”的意思；
* ...  表示术语符号；
**/

/**
* <expr> ::= [op1]<term>{<op1> <term>}
* <term> ::= <term>{<op2> <factor>}
* <factor> ::= <ident>|<number>|(<expr>)
* <op1> ::= +|-
* <op2> ::= *|/
**/

/** LL(1) 右递归
 * e -> PE | E
 * E -> TE'
 * E' -> PIE' | ε
 * T  -> FT'
 * T' -> MFT' | ε
 * F -> I | (e)
 * I -> i | n
 * P -> + | -
 * M -> * | /
 **/

enum Element {
    // 终结符
    null, // ε
    ident,  // i
    number, // n
    plus_,   // +
    minus_,  // -
    times,  // *
    slash,  // /
    lparen, // (
    rparen, // )
    // 非终结符
    expr_, // e
    Expr,   // E
    expr,   // E'
    Term,   // T
    term,   // T'
    Factor, // F
    Plus,   // P
    Multi,  // M
    Ident,  // I
    // error
    error
};

// <非终结符,<终结符,最左推导的非终结符序列>>
const std::map<Element, std::map<Element, std::vector<Element>>> prediction_table = {
        {expr_,
                {{plus_, {Plus,   Expr}},
                        {minus_, {Plus,   Expr}},
                        {ident,  {Expr}},
                        {number, {Expr}},
                        {lparen, {Expr}}
                }
        },
        {Expr,
                {{ident, {Term,   expr}},
                        {number, {Term,   expr}},
                        {lparen, {Term,   expr}}
                }
        },
        {expr,
                {{plus_, {Plus,   Term, expr}},
                        {minus_, {Plus,   Term, expr}},
                        {rparen, {}},
                        {null,   {}}
                }
        },
        {Term,
                {{ident, {Factor, term}},
                        {number, {Factor, term}},
                        {lparen, {Factor, term}}
                }
        },
        {term,
                {{plus_, {}},
                        {minus_, {}},
                        {times,  {Multi,  Factor, term}},
                        {slash,  {Multi, Factor, term}},
                        {rparen, {}},
                        {null, {}}
                }
        },
        {Factor,
                {{ident, {Ident}},
                        {number, {Ident}},
                        {lparen, {lparen, expr_,  rparen}}
                }
        },
        {Plus,
                {{plus_, {plus_}},
                        {minus_, {minus_}}
                }
        },
        {Multi,
                {{times, {times}},
                        {slash,  {slash}}
                }
        },
        {Ident,
                {{ident, {ident}},
                        {number, {number}}
                }
        }};

Element get_type(const std::string &s);

std::string get_error_type(Element e);

std::vector<Element> next(Element current, Element type);

bool expression_validator(const std::vector<std::pair<Element, std::string>> &elements);

#endif //MY_COMPILER_EXPRESSION_ANALYZER_H
