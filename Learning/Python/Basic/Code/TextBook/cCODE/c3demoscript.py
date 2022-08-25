#0. 中文注释
#coding:utf-8
#coding:gbk
#coding:utf-8
# -*- coding : gbk -*-

#1. 关系运算符连续使用
def eg1():
    print(1<2<3)
    print(1<2>3)
    print(1<3>2)

#2.条件表达式使用
def eg2():
    #值
    if 3:
        print(5)
    #列表
    a = [1, 2, 3]
    if a:
        print(a)	
    #空列表
    a = []
    if a:
        print(a)
    else:
        print('empty')

#3.条件表达式
def eg3():
    #使用关系表达式作为条件表达式
    i=s=0
    while i<=10:
        s+=i
        i+=1
    print(s)
    #使用常量True作为条件表达式
    i = s = 0
    while True: 
        s += i
        i += 1
        if i > 10:
            break
    print(s)
    #使用range
    s = 0
    for i in range(0, 11, 1):
        s += i
    print(s)

#4.短路惰性
def Join(chList, sep=None):
    return (sep or ',').join(chList)
def eg4():
    chTest = ['1', '2', '3', '4', '5']
    print(Join(chTest))
    print(Join(chTest, ':'))
    print(Join(chTest, ' '))

#5.分支
#单分支
def eg5():
    a,b=eval(input('Input two number:'))
    if a>b:
       a,b=b,a
    print(a,b)
#双分支
def eg6():
    chTest = ['1', '2', '3', '4', '5']
    if chTest:
        print(chTest)
    else:
        print('Empty')
#双分支表达式1
def eg7():
    a = 5
    print(6) if a>3 else print(5)
    print(6 if a>3 else 5)
    b = 6 if a>13 else 9
    print(b)

#双分支表达式2
def eg8():
    x = math.sqrt(9) if 5>3 else random.randint(1, 100)
    print(x)
def eg81():
    import math
    x = math.sqrt(9) if 5>3 else random.randint(1,100) 
    print(x)
    x = math.sqrt(9) if 2>3 else random.randint(1, 100)
    print(x)
def eg82():
    import random
    x = math.sqrt(9) if 2>3 else random.randint(1, 100)
    print(x)
    
# 多分支结构
def eg9(score):
    if score > 100:
        return 'wrong score.must <= 100.'
    elif score >= 90:
        return 'A'
    elif score >= 80:
        return 'B'
    elif score >= 70:
        return 'C'
    elif score >= 60:
        return 'D'
    elif score >= 0:
        return 'E'
    else:
        return 'wrong score.must >0'
def eg91():
    print(eg9(-1))
    print(eg9(50))
    print(eg9(61))
    print(eg9(72))
    print(eg9(83))
    print(eg9(94))

#6.选择结构嵌套
def eg10(score):
    degree = 'DCBAAE'
    if score > 100 or score < 0:
        return 'wrong score.must between 0 and 100.'
    else:
        index = (score - 60)//10
        #print(index)
        if index >= 0:
            return degree[index]
        else:
            return degree[-1]
def eg101():
    print(eg10(-1))
    print(eg10(50))
    print(eg10(61))
    print(eg10(72))
    print(eg10(83))
    print(eg10(94))

##################
##7.分支结构应用
##################
#面试资格
def func1():
    age=24
    subject="计算机"
    college="非重点"
    if (age > 25 and subject=="电子信息工程") or (college=="重点" and subject=="电子信息工程" ) or (age<=28 and subject=="计算机"):
        print("恭喜，你已获得我公司的面试机会!")
    else:
        print("抱歉，你未达到面试要求")
        
#输入分数求和
def func2():
    endFlag = 'yes'
    s = 0
    while endFlag.lower() =='yes':
        x = input("请输入一个正整数: ")
        x = eval(x)
        if isinstance(x, int) and 0<=x<=100:
            s = s + x
        else:
            print('不是数字或不符合要求')
        endFlag = input('继续输入？(yes or no)')
    print('整数之和=', s)
    
#日子计算
def func3(): 
    import time
    date = time.localtime()
    year = date[0]
    month = date[1]
    day = date[2]
    day_month = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    if year%400==0 or (year%4==0 and year%100!=0): #判断是否为闰年
        day_month[1] = 29
    if month==1:
        print(day)
    else:
        print(sum(day_month[:month-1])+day)

#8.循环优化
#非优化
def eg11():
    import time
    digits = (1, 2, 3, 4)   
    start = time.time()
    for i in range(1000):
        result = []
        for i in digits:
            for j in digits:
                for k in digits:
                    result.append(i*100+j*10+k)
    print(time.time()-start)
    print(result)
    
#优化
def eg12():
    import time
    digits = (1, 2, 3, 4)   
    start = time.time()
    for i in range(1000):
        result = []
        for i in digits:
            i = i*100
            for j in digits:
                j = j*10
                for k in digits:
                    result.append(i+j+k)
    print(time.time()-start)
    print(result)

#9.局部循环变量
#全局
def eg13():
    import time
    import math
    start = time.time() #获取当前时间
    for i in range(1000000):
        math.sin(i)
    print('Time Used:', time.time()-start) #输出所用时间
#局部
def eg14():
    import time
    import math
    loc_sin = math.sin
    start = time.time()
    for i in range(1000000):
        loc_sin(i)
    print('Time Used:', time.time()-start)

#10.break
#最大素数
def eg15():
    for n in range(100, 1, -1):
        for i in range(2, n):
            if n%i == 0:
                break
        else:
            print(n)
            break	
#所有素数
def eg16():
    for n in range(100, 1, -1):
        for i in range(2, n):
            if n%i == 0:
                break
        else:
            print(n,end=' ')

#11.continue
#死循环
def eg17():
    i=0
    while i<10:
        if i%2==0:
            print(i)
            continue
        print(i)
        i+=1
#修改死循环1
def eg18():
    i=0
    while i<10:
        i+=1
        if i%2==0:
            print(i,end=' ')
            continue
        print(i)
#修改死循环2
def eg19():
    for i in range(10):
        if i%2==0:
            continue
        print(i,end=' ')
#修改死循环3
def eg20():
    for i in range(10):
        print(id(i),':',i)
        if i%2==0:
            i+=1
            print(id(i),':',i)
            continue
        print(id(i),':',i)

#12.应用选讲
##计算1+2+3+…+100 的值
def func4():
    s=0
    for i in range(1,101):
        s=s + i
    print('1+2+3+…+100 = ', s)
    print('1+2+3+…+100 = ', sum(range(1,101)))

##输出序列中的元素
def func5():
    a_list=['a', 'b', 'mpilgrim', 'z', 'example']
    for i,v in enumerate(a_list):
        print('列表的第', i+1, '个元素是：', v)

##求1~100之间能被7整除，但不能同时被5整除的所有整数
def func6():
    for i in range(1,101):
        if i % 7 == 0 and i % 5 != 0:
            print(i,end=' ')
            
##输出“水仙花数”
def func7():        
    for i in range(100,1000):
        ge =  i % 10
        shi = i // 10 % 10
        bai = i // 100
        if ge**3+shi**3+bai**3 == i:
            print(i,end=' ')
            
##求平均分
def func8(): 
    score = [70, 90, 78, 85, 97, 94, 65, 80]
    s = 0
    for i in score:
        s += i
    print(s*1.0/len(score))
    print(sum(score)*1.0/len(score))

##打印九九乘法表
def func9():
    for i in range(1,10):
        for j in range(1,i+1):
            print(i,'*',j,'=',i*j,'\t',end=' ')
        print('\n')

##求200以内能被17整除的最大正整数
def func10():
    for i in range(200,0,-1):
        if i%17 == 0:
            print(i)
            break
        
##判断一个数是否为素数
def func11():
    import math
    n = eval(input("Input an integer:"))
    m = int(math.sqrt(n)+1)
    for i in range(2,m):
        if n%i == 0:
            print(i)
            print('No')
            break
    else:
        print('Yes')

##鸡兔同笼问题：假设共有鸡、兔30只，脚90只
def func12():
    for ji in range(0, 31):
        if 2*ji + (30-ji)*4 == 90:
            print('ji:', ji, ' tu:', 30-ji)

#输出由1、2、3、4这四个数字组成的每位数都不相同的所有三位数
def func13():
    digits = (1, 2, 3, 4)
    for i in digits:
        for j in digits:
            for k in digits:
                if i!=j and j!=k and i!=k:
                    print(i*100+j*10+k,end=' ')               
##优化代码
def func14():
    digits = (1, 2, 3, 4)
    for i in digits:
        for j in digits:
            if j==i:
                continue
            for k in digits:
                if k==i or k==j:
                    continue
                print(i*100+j*10+k,end=' ')
                          
##生成一个含有20个1到100之间随机数的列表，要求所有元素不相同
def func15():
    import random
    x = []
    while True:
        if len(x)==20:
            break
        n = random.randint(1, 100)
        if n not in x:
            x.append(n)
    print(x)
    print(len(x))
    print(sorted(x))

        
