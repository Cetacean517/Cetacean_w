#coding:utf-8
## -*- coding : gbk -*-

##from __future__ import print_function
from math import pi as PI
import types
import collections
import random
import math
import fractions
import os
import copy
import re

def f1():
    print("The number {0:,} in hex is: {0:#x},\
          the number {1} in oct is {1:#o}".format(5555,55))
    print("The number {1:,} in hex is: {1:#x},\
          the number {0} in oct is {0:#o}".format(5555,55))
    print("my name is {name}, my age is {age}, \
    and my QQ is {qq}".\
          format(name = "Dong Fuguo",
    age = 37,qq = "306467355"))
    position = (5,8,13)
    print("X:{0[0]};Y:{0[1]};Z:{0[2]}".format(position))
    weather = [("Monday","rainy"),("Tuesday","sunny"),
               ("Wednesday", "sunny"),("Thursday","rainy"),
               ("Friday","cloudy")]
    formatter = "Weather of '{0[0]}' is '{0[1]}'".format
    print(type(formatter))
    for item in map(formatter,weather):
        print(item)

def f2():
    s="apple,peach,banana,peach,pear"
    print(s.find("peach"))
    print(s.find("peach",7))
    print(s.rfind('peach'))
    print(s.index('peach'))
    print(s.index('peach',7))
    print(s.rindex('peach'))
    
    print(s.count('p'))
    print(s.count('pp'))
    print(s.count('ppp'))

    print(s.find("peach",7,20))
#    print(s.index('peach',7,20))

def f3():
    s="apple,peach,banana,pear"
    print(s)
    a=s.split(",")
    print(a)
    b=s.partition(',')
    print(b)
    c=s.rpartition(',')
    print(c)
    d=s.rpartition('banana')
    print(d)
    
    s = "2014-10-31"
    t=s.split("-")
    print(t)
    x=map(int, t)
    print(list(x))

def f4():
    eval("__import__('os').startfile \
    (r'C:\Windows\\notepad.exe')")
    eval("__import__('os').system('md testtest')")

def f5():
    f=[filename for filename in os.listdir(r'C:\\D\\AAATEA\\R_springPY2017\\aENCRS\\W8\\')  
       if filename.endswith(('.py','.jpg','.txt'))]
    print(f)

def f6():
    example = 'School of Computer Science and \
    Technology, Shanghai University'
    #以S开头的单词
    pattern = re.compile(r'\bS\w+\b') 
    print(pattern.findall(example))
    #以y结尾的单词
    pattern = re.compile(r'\w+y\b')
    print(pattern.findall(example))
    #查找所有含有字母o的单词
    pattern = re.compile(r'\b\w*o\w*\b')
    print(pattern.findall(example))
    #查找3个字母长的单词
    pattern = re.compile(r'\b[a-zA-Z]{3}\b')
    print(pattern.findall(example))
    #从字符串开头开始匹配，所以不成功，没有返回值
    print(pattern.match(example))
    #在整个字符串中搜索，所以成功
    print(pattern.search(example))

def f7():
    example = '''Beautiful is better than ugly.
Explicit is better than implicit.
Simple is better than complex.
Complex is better than complicated.
Flat is better than nested.
Sparse is better than dense.
Readability counts.'''
    pattern = re.compile(r'\bb\w*\b',re.I)
    print(pattern.sub('*',example))
    print('\r')
    print(pattern.sub('*',example,1))
    print('\r')
    pattern = re.compile(r'\bb\w*\b')
    print(pattern.sub('*',example,1))

def f8():
    example = r'one,two,three.four/file\six?seven[eight]nine|ten'
    pattern = re.compile(r'[,./\\?[\]\|]')
    print(pattern.split(example))
    example = r'one1two2three3four4file5six6seven7eight8nine9ten'
    pattern = re.compile(r'\d+')
    print(pattern.split(example))
    example = r'one two    three  four,file.six.seven,eight,nine9ten'
    pattern = re.compile(r'[\s,.\d]+')
    print(pattern.split(example))

def f9():
    telNumber = '''Suppose my Phone No.
    is 0535-1234567,yours is 010-12345678,
    his is 025-87654321.'''
    pattern = re.compile(r'(\d{3,4})-(\d{7,8})')
    print(pattern.findall(telNumber))
    index = 0
    while True:
        matchResult = pattern.search(telNumber, index)
        if not matchResult:
            break
        print('-'*30)
        print('Success:')
        for i in range(3):
            print('Searched content:', matchResult.group(i),
            ' Start from:',matchResult.start(i),
            'End at:',    matchResult.end(i),
            ' Its span is:', matchResult.span(i))
        index = matchResult.end(2)

def f10():
    exampleString = '''There should be one--
and preferably only one --obvious way to do it.
Although that way may not be obvious at first
unless you're Dutch.
Now is better than never.
Although never is often better than right now.'''
    #查找不在句子开头和结尾的单词
    pattern = re.compile(r'(?<=\w\s)never(?=\s\w)')
    matchResult = pattern.search(exampleString)
    print(matchResult.span())
    #查找位于句子末尾的单词
    pattern = re.compile(r'(?<=\w\s)never')
    matchResult = pattern.search(exampleString)
    print(matchResult.span())
    #查找前面是is的better than组合
    pattern = re.compile(r'(?:is\s)better(\sthan)')
    matchResult = pattern.search(exampleString)
    print(matchResult.span())
    #0表示整个模式
    print(matchResult.group(0))
    print(matchResult.group(1))
    
    #查找以n或N字母开头的所有单词
    pattern = re.compile(r'\b(?i)n\w+\b')
    index = 0
    while True:
        matchResult = pattern.search(exampleString,index)
        if not matchResult:
            break
        print(matchResult.group(0), ':', matchResult.span(0))
        index = matchResult.end(0)

    #查找前面没有单词not的单词be
    pattern = re.compile(r'(?<!not\s)be\b')
    index = 0
    while True:
        matchResult = pattern.search(exampleString,index)
        if not matchResult:
            break
        print(matchResult.group(0), ':', matchResult.span(0))
        index = matchResult.end(0)
    print(exampleString[13:20])#验证一下结果是否正确

    #查找具有连续相同字母的单词
    pattern = re.compile(r'(\b\w*(?P<f>\w+)(?P=f)\w*\b)')
    index = 0
    while True:
        matchResult = pattern.search(exampleString, index)
        if not matchResult:
            break
        print(matchResult.group(0),':',matchResult.group(2))
        index = matchResult.end(0) + 1

    #查找具有连续相同字母的单词
    s='aabc abcd abbcd abccd abcdd'
    p = re.compile(r'(\b\w*(?P<f>\w+)(?P=f)\w*\b)')
    print(p.findall(s))

def sep():
    print('\n===============')
    print('@@@@@@@@@')
    print('===============\n')

if __name__ =='__main__':
    f1()
    sep()
    f2()
    sep()
    f3()
    sep()
    f4()
    sep()
    f5()
    sep()
    f6()
    sep()
    f7()
    sep()
    f8()
    sep()
    f9()
    sep()
    f10()
