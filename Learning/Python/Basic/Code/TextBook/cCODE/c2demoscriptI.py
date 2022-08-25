# -*- coding: utf-8 -*-
import time

#1列表例示
def eg0():
    print([10, 20, 30, 40])
    print(['crunchy frog', 'ram bladder', 'lark vomit'])
    print(['spam', 2.0, 5, [10, 20]])
    print([['file1', 200,7], ['file2', 260,9]])
#2列表创建
def eg1():
    aList = ['a', 'b', 'mpilgrim', 'z', 'example']
    print(aList)
    aList = list((3,5,7,9,11))
    print(aList)
    aList = list(range(1,10,2))
    print(aList)
    aList = list('hello world')
    print(aList)
    x = list()
    print(x)
    aList = []
    print(aList)
    
#3Xrange
def eg2():
    start = time.time()
    for j in list(range(1000000)):
        1+1
    print(time.time()-start)
    start = time.time()
    for j in range(1000000):
        1+1
    print(time.time()-start)

#4增加列表元素
def eg3():
    # +
    aList = [3,4,5]
    print(aList)
    print(id(aList))
    aList = aList + [7]
    print(aList)
    print(id(aList))
    # append
    aList.append(9)
    print(aList)
    print(id(aList))

#比较
def eg4():
    result = []
    start = time.time()
    for i in range(10000):
        result = result + [i]
    print(len(result), ',', time.time()-start)
    result = []
    start = time.time()
    for i in range(10000):
        result.append(i)
    print(len(result), ',', time.time()-start)

#关于序列修改的内存变化
def eg5():
    a = [1,2,3]
    print(id(a))
    a = [1,2]
    print(id(a))
    a = [1,2,4]
    b = [1,2,3]
    print(a == b)
    print(id(a) == id(b))
    print(id(a[0]) == id(b[0]))
    a = [1,2,3]
    print(id(a))
    a.append(4)
    print(id(a))
    a.remove(3)
    print(a)
    print(id(a))
    a[0] = 5
    print(a)
    print(id(a))
    #extend
    a.extend([7,8,9])
    print(a)
    print(id(a))
    a.extend([11,13])
    print(a)
    print(id(a))
    a.extend((15,17))
    print(a)
    print(id(a))
    #list
    a.insert(3,6)
    print(a)
    print(id(a))
    
#时间消耗比较
def Insert():
    a = []
    for i in range(10000):
        a.insert(0, i)
def Append():
    a = []
    for i in range(10000):
        a.append(i)
def eg6():
    start = time.time()
    for i in range(10):
        Insert()
    print('Insert:', time.time()-start)
    start = time.time()
    for i in range(10):
        Append()
    print('Append:', time.time()-start)

# *
def eg7():
    aList = [3,5,7]
    bList = aList
    print(id(aList))
    print(id(bList))
    aList = aList*3
    print(aList)
    print(bList)
    print(id(aList))
    print(id(bList))
    # *实质
    x = [[None] * 2] * 3
    print(x)
    x[0][0] = 5
    print(x)
    x = [[1,2,3]]*3
    x[0][0] = 10
    print(x)

#5删除
def eg8():
    #del
    aList = [3,5,7,9,11]
    del aList[1]
    print(aList)
    #pop
    aList = list((3,5,7,9,11))
    aList.pop()
    print(aList)
    aList.pop(1)
    print(aList)
    #remove
    aList = [3,5,7,9,7,11]
    aList.remove(7)
    print(aList)
    
#remove 循环
def rvfunc(x):
    for i in x:
        if i == 1:
            x.remove(i)
    return x
###测试例
def eg9():
    x = [1,2,1,2,1,2,1,2,1]
    rvfunc(x)
    print(x)
    x = [1,2,1,2,1,1,1]
    rvfunc(x)
    print(x)
    
###修正
#1
def rvfunc1(x):
    for i in x[::]:
        if i == 1:
            x.remove(i)
    return x
###测试例
def eg91():
    x = [1,2,1,2,1,1,1]
    rvfunc1(x)
    print(x)

#2
def rvfunc2(x):
    for i in range(len(x)-1,-1,-1):
        if x[i]==1:
            del x[i]
            #x.remove(x[i])
    return x
###测试例
def eg92():
    x = [1,2,1,2,1,1,1]
    rvfunc2(x)
    print(x)

#6访问计数
def eg10():
    aList = [3,5,7,9,11]
    #下标
    aList[3]
    aList[3] = 5.5
    print(aList)
    #print(aList[15])
    #index
    print(aList)
    print(aList.index(7))
    #print(aList.index(100))
    #计数
    print(aList)
    print(aList.count(7))
    print( aList.count(0))
    print(aList.count(8))

#7成员
def eg11():
    aList=[3, 4, 5, 5.5, 7, 9, 11, 13, 15, 17]
    print(3 in aList)
    print(18 in aList)
    bList = [[1], [2], [3]]
    print(3 in bList)
    print(3 not in bList)
    print([3] in bList)
    aList = [3, 5, 7, 9, 11]
    bList = ['a', 'b', 'c', 'd']
    print((3, 'a') in zip(aList, bList))
    print(zip(aList, bList))
    for a, b in zip(aList, bList):
        print(a, b)

#8切片
#取值
def eg12():
    aList = [3, 4, 5, 6, 7, 9, 11, 13, 15, 17]
    print(aList[::])
    print(aList[::-1])
    print(aList[::2])
    print(aList[1::2])
    print(aList[3::])
    print(aList[3:6])
    print(aList[3:6:1])
    print(aList[0:100:1])
    print(aList[100:])
    #修改内容
    aList = [3, 5, 7]
    print(aList[len(aList):])
    aList[len(aList):] = [9]
    print(aList)
    aList[:3] = [1, 2, 3]
    print(aList)
    aList[:3] = []
    print(aList)
    aList = list(range(10))
    print(aList)
    aList[::2] = [0]*(len(aList)//2)
    print(aList)
    #删除元素
    aList = [3,5,7,9,11]
    del aList[:3]
    print(aList)
          
#返回浅拷贝
def eg13():
    ##正常赋值
    aList = [3, 5, 7]
    bList = aList #bList与aList指向同一个内存
    print(bList)
    bList[1] = 8
    print(aList)
    print(aList == bList)
    print(aList is bList)
    print(id(aList) )
    print(id(bList))
    ##浅复制
    aList = [3, 5, 7]
    bList = aList[::] #浅复制
    print(aList == bList)
    print(aList is bList)
    print(id(aList) == id(bList))
    bList[1] = 8
    print(bList)
    print(aList)
    print(aList == bList)
    print(aList is bList)
    print(id(aList))
    print(id(bList))

#浅复制深复制
def func1():
    import copy
    #原始对象
    a = [1, 2, 3, 'abcde', ['a', 'b']]
    #赋值，传对象的引用  
    b = a
    #对象拷贝，浅拷贝  
    c = copy.copy(a)
    d = a[::]
    #对象拷贝，深拷贝  
    e = copy.deepcopy(a)          
    
    #修改对象a
    a.append(5)                         
    a[3]='abc'
    #修改对象a中的['a', 'b']数组对象  
    a[4].append('c')                 

    print('',a,'\n',b,'\n',c,'\n',d,'\n',e)
    print(id(a), ',id(a[3])=',id(a[3]), ',id(a[4])=',id(a[4]))  
    print(id(b), ',id(b[3])=',id(b[3]), ',id(b[4])=',id(b[4]))  
    print(id(c), ',id(c[3])=',id(c[3]), ',id(c[4])=',id(c[4]))  
    print(id(d), ',id(d[3])=',id(d[3]), ',id(d[4])=',id(d[4]))  
    print(id(e), ',id(e[3])=',id(e[3]), ',id(e[4])=',id(e[4])) 

#8排序
#sort
def eg14():
    aList = [3, 4, 5, 6, 7, 9, 11, 13, 15, 17]
    import random
    random.shuffle(aList)
    print(aList)
    aList.sort()
    aList.sort(reverse = True)
    print(aList)
    aList.sort(key = lambda x:len(str(x)))
    print(aList)
    #sorted
    print(aList)
    sorted(aList)
    sorted(aList,reverse = True)
    #reverse
    aList = [3, 4, 5, 6, 7, 9, 11, 13, 15, 17]
    aList.reverse()
    print(aList)
    #reversed
    aList = [3, 4, 5, 6, 7, 9, 11, 13, 15, 17]
    newList = reversed(aList)
    print(newList)
    list(newList)
    for i in newList:
        print(i,end=' ')
    newList = reversed(aList)
    for i in newList:
        print(i,end=' ')

#9序列内置函数
#cmp
def eg15():
    import operator
    print((1, 2, 3) < (1, 2, 4))
    print(operator.lt((1, 2, 3) , (1, 2, 4)))
    print([1, 2, 3] < [1, 2, 4])
    print(operator.lt([1, 2, 3] , [1, 2, 4]))
    print('ABC' < 'C' < 'Pascal' < 'Python')
    print(operator.lt( 'Pascal', 'Python'))
    print((1, 2, 3, 4) < (1, 2, 4))
    print(operator.lt((1, 2, 3, 4),(1, 2, 4)))
    print((1, 2) < (1, 2, -1))
    print(operator.lt((1, 2), (1, 2, -1)))
    print((1, 2, 3) == (1.0, 2.0, 3.0))
    print(operator.eq((1, 2, 3), (1.0, 2.0, 3.0)))
    print((1, 2, ('aa', 'ab')) < (1, 2, ('abc', 'a'), 4))
    print(operator.gt('a', 'A'))
    print('a'>'A')
#zip
def eg16():
    aList = [1,2,3]
    bList = [4,5,6]
    cList = [7,8,9]
    dList = zip(aList, bList, cList)
    print(dList)
    #enumerate
    for item in enumerate(dList):
        print(item)

#10列表推导式
#定义
def eg17():
    aList = []
    for x in range(10):
        aList.append(x*x)
    print(aList)
    #相当于
    aList = [x*x for x in range(10)]
    print(aList)
    
#功能
def eg18():
    import os
    vec = [[1,2,3], [4,5,6], [7,8,9]] 
    aList = [num for elem in vec for num in elem]
    print(aList)
    ##列出当前文件夹下所有Python源文件
    aList = [filename for filename in os.listdir('.') if filename.endswith('.py')]
    print(aList)
    ##过滤不符合条件的元素
    bList = [-1,-4,6,7.5,-2.3,9,-11]
    aList = [i for i in bList if i>0]
    print(aList)
    
#应用例示
##统计成绩
def func2():
    scores = {"Zhang San": 45, "Li Si": 78, "Wang Wu": 40, "Zhou Liu": 96, "Zhao Qi": 65, "Sun Ba": 90, "Zheng Jiu": 78, "Wu Shi": 99, "Dong Shiyi": 60}
    highest = max(scores.values())
    lowest = min(scores.values())
    print(highest)
    print(lowest)
    average = sum(scores.values())*1.0/len(scores)
    print(average)
    highestPerson = [name for name, score in scores.items() if score == highest]
    print(highestPerson)

def func3():
    #在列表推导式中使用多个循环，实现多序列元素的任意组合，并且可以结合条件语句过滤特定元素
    aList = [(x, y) for x in range(3) for y in range(3)]
    print(aList)
    aList = [(x, y) for x in [1, 2, 3] for y in [3, 1, 4] if x != y]
    print(aList)

def func4():
    #矩阵转置
    matrix = [ [1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12]] 
    aList = [[row[i] for row in matrix] for i in range(4)] 
    print(aList)
    
#使用函数或复杂表达式
def f(v):
    if v%2 == 0:
        v = v**2
    else:
        v = v+1
    return v
def func5():
    print([f(v) for v in [2, 3, 4, -1] if v>0])
    #相当于
    print([v**2 if v%2 == 0 else v+1 for v in [2, 3, 4, -1] if v>0])

def func6():
#文件对象迭代 
    fp = open('123.txt', 'r')
    print([line for line in fp]) 
    fp.close()
    
#生成100以内的所有素数
def func7():
    import math
    aList=[ p for p in range(2, 100) if 0 not in [ p% d for d in range(2, int(math.sqrt(p))+1)] ]
    print(aList)

#创建删除
def eg19():
    a_tuple = ('a', )
    print(a_tuple)
    a_tuple = ('a', 'b', 'mpilgrim', 'z', 'example')
    print(a_tuple)
    a=3
    print(a)
    a=3,
    print(a)
    x = () #空元组
    print(x)
    print(tuple('abcdefg'))
    aList=[-1, -4, 6, 7.5, -2.3, 9, -11]
    print(tuple(aList))
    s = tuple() #空元组
    print(s)

#序列解包
##多变量赋值
def eg20():
    v_tuple = (False, 3.5, 'exp')
    (x, y, z) = v_tuple
    print(x,y,z)
    a=[1,2,3]
    b,c,d=a
    print(b,c,d)
    s={'a':1,'b':2,'c':3}
    b,c,d=s
    print(b,c,d)

##序列遍历
def eg21():
    keys=['a','b','c','d']
    values=[1,2,3,4]
    for k,v in zip(keys,values):
        print(k,v)
    aList = [1,2,3]
    bList = [4,5,6]
    cList = [7,8,9]
    dList = zip(aList, bList, cList)
    for index, value in enumerate(dList):
        print(index, ':', value)

#生成器推导式
def eg22():
    g=((i+2)**2 for i in range(10))
    print(g)
    print(tuple(g))
    print(tuple(g))
    g=((i+2)**2 for i in range(10))
    print(g.__next__())
    for i in g:
        print(i,end=' ')

#12字典
##创建删除
def eg23():
    #赋值
    a_dict = {'server': 'db.diveintopython3.org', 'database': 'mysql'}
    print(a_dict)
    x = {} #空字典
    print(x)
    #已有数据
    keys=['a','b','c','d']
    values=[1,2,3,4]
    dictionary=dict(zip(keys,values))
    print(dictionary)
    x = dict() #空字典
    print(x)
    #dict
    d=dict(name='Dong',age=37)
    print(d)
    #给定键
    adict=dict.fromkeys(['name','age','sex'])
    print(adict)

##元素读取
def eg24():
    #下标
    aDict={'name':'Dong', 'sex':'male', 'age':37}
    print(aDict['name'])
    #get
    print(aDict.get('address'))
    print(aDict.get('address', 'SDIBT'))
    aDict['score'] = aDict.get('score',[])
    aDict['score'].append(98)
    aDict['score'].append(97)
    print(aDict)                               

def eg25():
    #items,keys,values
    aDict={'name':'Dong', 'sex':'male', 'age':37}
    for item in aDict.items():
        print(item)
    for key in aDict:
        print(key)
    for key, value in aDict.items():
        print(key, value)
    print(aDict.keys())
    print(aDict.values())

def eg26():
    ##添加修改
    aDict={'name':'Dong', 'sex':'male'}
    #添加1
    aDict['age'] = 38
    print(aDict)
    aDict['address'] = 'SDIBT'
    print(aDict)
    #添加2
    aDict.items()
    aDict.update({'a':'a','b':'b'})
    print(aDict)

##字典应用
#生成包含1000个字符的随机字符串统计字符出现次数。
#method1
def func8():
    import string
    import random
    x = string.digits #+ string.ascii_letters + string.punctuation
    print(x)
    y = [random.choice(x) for i in range(200)]
    print(y)
    z = ''.join(y)
    print(z)
    d = dict()
    for ch in z:
        d[ch] = d.get(ch, 0) + 1
    print(d)
                               
#method2
def func81():
    import string
    import random
    x = string.digits
    y = [random.choice(x) for i in range(200)]
    z = ''.join(y)
    from collections import defaultdict
    frequences = defaultdict(int)
    print(frequences)
    for item in z:
        frequences[item] += 1
    print(frequences.items())
                               
#method3
def func82():
    import string
    import random
    x = string.digits
    y = [random.choice(x) for i in range(200)]
    z = ''.join(y)
    from collections import Counter
    frequences = Counter(z)
    print(frequences.items())
    print(frequences.most_common(1))
    print(frequences.most_common(3))
                               
#Counter词频统计
def func9():
    from collections import Counter
    cnt = Counter()
    for word in ['red', 'blue', 'red', 'green', 'blue', 'blue']:
        cnt[word] += 1
    print(cnt)

#有序字典
def func10():
    ##无序例
    x = dict() 
    x['a'] = 3
    x['b'] = 5
    x['c'] = 8
    print(x)
    ##有序例
    import collections
    x = collections.OrderedDict() 
    x['a'] = 3
    x['b'] = 5
    x['c'] = 8
    print(x)
                               
#字典推导式
def func11():
    s = {x:x.strip() for x in ('  he  ', 'she    ', '    I')}
    print(s)
    for k, v in s.items():
        print(k, ':', v)

#13集合
def eg27():
    #赋值
    a={3,5}
    a.add(7)
    print(a)
    a_set=set(range(8,14))
    print(a_set)
    b_set=set([0,1,2,3,0,1,2,3,7,8])
    print(b_set)
    c_set = set() #空集合
    print(c_set)

def eg28():
    #删除
    a={1, 4, 2, 3}
    a.pop()
    print(a)
    a.pop()
    print(a)
    a.add(2)
    print(a)
    a.remove(3) #删除指定元素
    print(a)
    #a.pop(2) #pop()方法不接收参数

def eg29():
#操作
    a_set=set(range(8,14))
    print(a_set)
    b_set=set([0,1,2,3,0,1,2,3,7,8])
    print(a_set.union(b_set))
    print(a_set)
    print(b_set)
    print(a_set&b_set)
    print(a_set.intersection(b_set))
    print(a_set.difference(b_set))
    print(a_set.symmetric_difference(b_set))
    print(a_set^b_set)                               

#集合的推导式
def eg30():
    s = {x.strip() for x in ('  he  ', 'she    ', '    I')}
    print(s)

##集合应用
def func12():
    import random
    listRandom = [random.choice(range(20)) for i in range(10)]
    noRepeat = []
    for i in listRandom :
        if i not in noRepeat :
            noRepeat.append(i)
    print(len(listRandom))
    print(len(noRepeat))
    newSet = set(listRandom)
    print(listRandom)
    print(newSet)

def sep():
    print('===============')
    print('@@@@@@@@@')
    print('===============')

def main():
    eg0()
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
    eg91()
    sep()
    eg92()
    sep()
    eg10()
    sep()
    eg11()
    sep()
    eg12()
    sep()
    eg13()
    sep()
    func1()
    sep()
    eg14()
    sep()
    eg15()
    sep()
    eg16()
    sep()
    eg17()
    sep()
    eg18()
    sep()
    func2()
    sep()
    func3()
    sep()
    func4()
    sep()
    func5()
    sep()
    func6()
    sep()
    func7()
    sep()
    eg19()
    sep()
    eg20()
    sep()
    eg21()
    sep()
    eg22()
    sep()
    eg23()
    sep()
    eg24()
    sep()
    eg25()
    sep()
    eg26()
    sep()
    func8()
    sep()
    func81()
    sep()
    func82()
    sep()
    func9()
    sep()
    func10()
    sep()
    func11()
    sep()
    eg27()
    sep()
    eg28()
    sep()
    eg29()
    sep()
    eg30()
    sep()
    func12()
    
if __name__=='__main__':
    print('Please use me as a module.')
