#coding:utf-8
## -*- coding : gbk -*-

from __future__ import print_function
from math import pi as PI
import types
import collections
import random
import math
import fractions

def fib(n):
    a, b = 1, 1
    while a < n:
        print(a, end=' ')
        a, b = b, a+b
    print('\n')
## fib(1000)

def fib1(n):
    '''accept an integer n. return the numbers 
    less than n in Fibonacci sequence.'''
    a, b = 1, 1
    while a < n:
        print(a, end=' ')
        a, b = b, a+b
    print('\n')
## fib1(1000)

#默认参数的使用
def dm1(newitem,old_list=[]):
    old_list.append(newitem)
    return old_list
def eg01():
    print(dm1('5',[1,2,3,4]))
    print(dm1('aaa',['a','b']))
    print(dm1('a'))   
    print(dm1('b'))

def dm2(newitem,old_list=None):
    if old_list is None:
        old_list=[]
    old_list.append(newitem)
    return old_list
def eg02():
    print(dm2('5',[1,2,3,4]))
    print(dm2('aaa',['a','b']))
    print(dm2('a'))   
    print(dm2('b'))
    
#1
def CircleArea(r):
    if isinstance(r,int) or isinstance(r,float):
        #确保接收的参数为数值
        return PI*r*r
    else:
        print('You must give me an integer or float as radius.')
def eg1():
    print(CircleArea(3))

#2
def demo2(*para):
    avg = sum(para)/len(para) 
    g = [i for i in para if i>avg]
    return (avg,)+tuple(g)
def eg2():
    print(demo2(1,2,3,4))

#3
def demo3(s):
    result = [0,0]
    for ch in s:
        if 'a'<=ch<='z':
            result[1] += 1
        elif 'A'<=ch<='Z':
            result[0] += 1
    return result
def eg3():
    print(demo3('aaaabbbbC'))

#4
def demo4(lst,k):
    x = lst[:k]
    x.reverse()
    y = lst[k:]
    y.reverse()
    r = x+y
    r.reverse()
    return r
def eg4():
    lst = list(range(1,21))
    print(lst)
    print(demo4(lst,5))

#5
def demo5():
    x = range(20)
    print(x)
    x = collections.deque(x)
    print(x)
    x.rotate(-3)
    print(x)
    x=list(x)
    print(x)
def eg5():
    demo5()
    
#6
def demo6(t):
    a, b = 1, 1
    while b<t:
        a, b = b, a+b
    else:
        return b
def eg6():
    print(demo6(50))

#7
def demo7(lst):
    m = min(lst)
    result = (m,)
    for index, value in enumerate(lst):
        if value==m:
            result = result+(index,)
    return result
def eg7():
    x = [random.randint(1,20) for i in range(50)]
    print(x)
    print(demo7(x))

#8
def demo8(t):
    print([1])
    print([1,1])
    line = [1,1]
    for i in range(2,t):
        r = []
        for j in range(0,len(line)-1):
            r.append(line[j]+line[j+1])
        line = [1]+r+[1]
        print(line)
def eg8():
    demo8(10)

#9
def IsPrime(n):
    m = int(math.sqrt(n))+1
    for i in range(2, m):
        if n%i==0:
            return False
    return True
def demo90(n):
    if isinstance(n,int) and n>0 and n%2==0:
        for i in range(3, int(n/2)+1):
            if IsPrime(i) and IsPrime(n-i):
                print(i, '+', n-i, '=', n)
def eg9():
    demo90(60)

#10
def demo10(m,n):
    if m>n:
        m, n = n, m
    p = m*n
    while m!=0:
        r = n%m
        n = m
        m = r
    return (int(p/n),n)
def eg10():
    print(demo10(20,30))

def demo11():
    print(fractions.gcd(36,39))
    print(fractions.gcd(20,30))
    print(30*20/fractions.gcd(20,30))
def eg11():
    demo11()
    
#生成器
def fy():
    a, b = 1, 1
    while True:
        yield a
        a, b = b, a+b
def ufy():
    #usage1
    aU = fy()
    print(aU.__next__(), '\n')
    for i in fy():
        print(i, end=' ')
        if i>1000:
            break
    #usage2
    print('\n')
    aU=fy()
    for i in range(10):
        print(aU.__next__(),end=' ')
    print('\n')
    for i in range(10):
        print(aU.__next__(),end=' ')
def eg12():
    ufy()

#嵌套定义
def linear(a, b):
    def result(x):
        return a * x + b
    return result
def eg13():
    taxes = linear(0.3, 2)
    print(taxes(5))

#包含__call__()方法的类的对象都是可调用的
class linear2:
    def __init__(self, a, b):
        self.a, self.b = a, b
    def __call__(self, x):
        return self.a * x + self.b
def eg14():
    taxes = linear2(3, 20)
    print(taxes(5))


def sep():
    print('\n===============')
    print('@@@@@@@@@')
    print('===============\n')

def main():
    fib(1000)
    sep()
    fib1(1000)
    sep()
    eg01()
    sep()
    eg02()
    sep()
    eg1()
    sep()
    eg2()
    sep()
    eg3()
    sep()
    eg4()
    sep()
    eg5()
    sep()
    eg6()
    sep()
    eg7()
    sep()
    eg8()
    sep()
    eg9()
    sep()
    eg10()
    sep()
    eg11()
    sep()
    eg12()
    sep()
    eg13()
    sep()
    eg14()
    
if __name__=='__main__':
    # print('Please use me as a module.')
    eg02()
    eg01()