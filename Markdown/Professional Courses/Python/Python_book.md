# 第1章 基础知识
## 1.1 如何选择Python版本
```python
>>> import sys
>>> sys.version   #查看Python版本信息
'3.9.2 (tags/v3.9.2:1a79785, Feb 19 2021, 13:44:55) [MSC v.1928 64 bit (AMD64)]'
>>> sys.winver    #查看Python版本号
'3.9'
>>> sys.version_info    #查看Python详情信息
sys.version_info(major=3, minor=9, micro=2, releaselevel='final', serial=0)
```

## 1.2 Python安装与简单实用
#### 利用IDLE调试
创建文件：File $\rightarrow$ New File，保存为.py / .pyw(对于GUI程序)

检查程序：Run $\rightarrow$ Check Module

运行程序：Run $\rightarrow$ Run Module

#### cmd运行Python
cd 进入地址： python 文件名.py

#### IDLE常用快捷键 书p4

## 1.3 使用pip管理Python扩展库
常用pip命令使用方法
|pip命令| 说明|
|--|--|
|pip install SomePackage|  安装SomePackage模块| 
|pip list| 列出当前已安装的所有模块| 
|pip install --upgrade SomePackage| 升级安装SomePackage模块| 
|pip uninstall SomePackage| 卸载安装SomePackage模块| 
|pip install somePackage| whl使用whl文件直接安装安装SomePackage模块| 

## 1.4 Python基础知识
### 1.4.1 Python对象模型
### 1.4.2 Python变量
Python 是强类型编程语言：Python解释器会根据赋值或运算来自动推断变量类型。

Python 是动态类型语言：变量的类型是可以随时变化的。

**type() 和 isinstance()**
```python
x = 3
print(type(x))      #查看变量类型
isinstance(3,int)   #判断变量类型，返回bool类型
```
字符串和元组属于不可变序列，其余是可变序列。

Python允许多个变量指向同一个值。

**id():返回变量地址**

**del x :删除变量**

**查看关键字**
```python
import keyword
keyword.kwlist
```

**dir(__builins__):查看内置模块，类型和函数。**

### 1.4.3 数字
**复数运算**
```python
>>> a = 5 + 2j
>>> b = 3 - 1j
>>> c = a - b
>>> c
(2+3j)
>>> c.real
2.0
>>> c.imag
3.0
>>> c.conjugate()
(2-3j)
>>> a * b
(17+1j)
>>> a / b
(1.2999999999999998+1.0999999999999999j)
```

### 1.4.4 字符串
`''' '''`：支持换行，表示较长的注释

格式化：

raw-string: 在字符串前面加r或R表示原始字符串，其中特殊字符不进行转义，但字符串的最后一个字符不能是\。（主要用于正则表达，也开业用来简化路径或url输入）

转义字符
\n  $\qquad$  换行符    \\"  $\qquad$  双引号
\t  $\qquad$  制表符    \\   $\qquad$  一个\
\r  $\qquad$  回车      \ddd  $\qquad$  3位八进制数对应的字符
\\'  $\qquad$  单引号   \xhh  $\qquad$  2为十六进制数对应的字符

### 1.4.5 运算符与表达式
`x in y;x not in y`  $\qquad$  成员测试运算符
`x is y;x is not y`  $\qquad$  对象实体词同一性测试（地址是否一致：有的值相同，但是地址不相同）

位运算符

| ^ & << >> ~

集合交集、并集、对称差集

Python中用','分割，会产生一个元组

Python

### 1.4.7 对象的删除 del x
可以使用del命令来显示的删除对象，并解除与值之间的指向关系。

del也可以删除列表或其他可变序列中的指定元素，也可以删除整个列表或者其他类型序列对象。

```python
x = (1,2,3)
del x[1]
del x
```

### 1.4.8 基本输入输出
**输入**
input()接受用户的键盘输入。

Python2.x中，该函数返回结果的类型由输入值使用的界定符来决定；而raw_input()返回类型一律为字符串。
```python
>>> x = input("input:")
input: [1,2,3]
>>> print type(x)
<type 'list'>

>>> x = raw_input("input:")
input: [1,2,3]
>>> print type(x)
<type 'str'>
```
Python3.x中，所有返回类型均是str类型。

**输出**
把文件输出到指定文件

Python2.x
```python
>>> fp = open(r'url','a+')
>>> print>>'Hello'
>>> fp.close
```

Python3.x
```python
>>> fp = open(r'url','a+')
>>> print('Hello',file = fp)
>>> fp.close
```

加“，”不换行的性质
Python2.x
```python
for i in range(10):
    print i,
0 1 2 3 4 5 6 7 8 9
```

Python3.x
```python
for i in range(10,20):
    print(i,end=' ')
10 11 12 13 14 15 16 17 18 19
```

### 1.4.9 模块导入与使用
sys.modules.items()显示所有预加载模块的相关信息。

**import 模块名[as别名]**
```python
>>> import math as m
>>> m.sqrt(9)
3.0
```

**from 模块名 import 对象名[as别名]**
```python
>>> from math import sqrt as f
>>> f(9)
3.0
```

**重新导入模块**
Python2.x中可以使用reload()；Python3.x中可以使用imp模块或importlib模块的reload()函数。

前提：该模块已经被正确加载，即第一次导入和加载模块时不能使用reload方法。

导入模块时，会优先导入相应的.pyc文件，如果相应的.pyc文件与.py文件时间不相符或不存在对应的.pyc文件，则导入.py文件并重新将该模块编译为.pyc文件。

**模块导入顺序**
- 导入Python标准款模块，os,sys,re
- 导入第三方扩展库,如PIL，numpy,scipy
- 导入自己定义和开发的本地模块。

# 第2章 Python序列
## 2.1 列表 []
### 2.1.1 列表创建与删除
```python
list_a = []
list_b = ['a',2,'sirng']
```
可以利用 range 来创建list.

#### range函数
```python
range([start,] stop [,step])
```
参数1 ： 起点（默认0）

参数2 ：终点

参数3 ： 步长

删除列表，使用**del + list**

### 2.1.2 列表元素的增加
#### 1）用"+"增加元素
```python
>>> aList = [3,4,5]
>>> aList = aList + [6]
>>> aList
[3, 4, 5, 6]
```

#### 2）append()方法
**原地修改：内存地址不变，内存单元增加**
```python
>>> aList.append(9)
>>> aList
[3, 4, 5, 6, 9]
```

**比较两个方法**
```python
import time

# 使用+方法，增加list 成员
result = []
start = time.time()
for i in range(10000):
    result = result + [i]
print(len(result), ',', time.time() - start)

# 使用append方法，增加list成员
result = []
start = time.time()
for i in range(10000):
    result.append(i)
print(len(result), ',', time.time() - start)
```
append更快，因为是直接原地增加元素，而不是更改指针指向。

#### 基于内存的管理方式
对于list而言，list中包含的元素值的引用，而不是直接包含元素本身。
- 若直接修改序列变量的值，则地址改变
- 若通过下标修改，地址不变，元素地址改变。
```python
a = [1,2,4]
b = [1,2,3]
a == b
False
a.append(4)
id (a) # 不变
a.remove(4)
id(a) # 不变
```

#### 3）extend()方法
将另一个迭代对象的所有元素添加至该列表对象尾部。

不改变内存首地址，属于**原地操作**。
```python
>>> a = [5,2,3]
>>> id(a)
1862358752576
>>> a.extend([7,8,9])
>>> id(a)
1862358752576
```
#### 4）insert()方法
在列表的任意位置插入元素，但由于列表的自动内存管理功能，该方法会涉及到插入位置之后元素的移动，会影响处理速度。

**尽量避免在列表中间插入和删除元素，建议优先使用append()和pop()方法**

比较append()和insert处理速度的差别：
```python
import time

# 测试：insert插入第一位和append插入最后一位的时间差
# 使用+方法，增加list 成员
def Insert():
    a = []
    for i in range(10000):
        a.insert(0, i)
    print(a)

def Append():
    a = []
    for i in range(10000):
        a.append(i)


start = time.time()
# 做十次
for i in range(10):
    Insert()
print('Insert:', time.time() - start)


start = time.time()
for i in range(10):
    Append()
print('Append:', time.time() - start)

# Insert: 0.370502233505249
# Append: 0.010970830917358398
```
#### 5）用乘法扩展列表对象(适用：list , string, tuple)
将列表整数相乘，生成一个新列表(地址变化)，新列表是原列表的重复。
```python
>>> a = [3,4,5]
>>> b = a
>>> id(a)
2699380239104
>>> a = a * 3  # 注意 a = a * 3时，地址改变；而a * 3时地址不变化
>>> a
[3, 4, 5, 3, 4, 5, 3, 4, 5]
>>> b
[3, 4, 5]
>>> id(a)
2697266430784 #地址改变，创建新列表
>>> id(b)
2699380239104
```

**使用`*`运算符，创建元素的引用，当修改某一个值的时候，也会被修改。**

**Tricky Part**
```python
# 先构成list: [None,None],再把list作为最外层list的元素，重复三次。
x = [[None] * 2] * 3
print(x)

# x[0][0]修改的是[[None, None], [None, None], [None, None]]中，第一个元素的第一个元素。
# 而该list是又*创建的，因此三个全是对于[None,None]的引用，更改任何一个中的一个元素，其他三个元素均会被修改。
x[0][0] = 5
print(x)

# 原理同上
x = [[1, 2, 3]] * 3
x[0][0] = 10
print(x)
```
### 2.1.3 列表元素的删除
#### 1）del命令
- 可以删除一整个列表
- 可以删除指定位置上的元素（默认删除最后一个元素）

```python
>>> a = [1,2,3]
>>> del a[2]
>>> a
[1, 2]
>>> del a
>>> a
Traceback (most recent call last):
  File "<pyshell#73>", line 1, in <module>
    a
NameError: name 'a' is not defined
```
#### 2）pop()方法
删除元素并返回指定（默认为最后一个）位置上的元素。下标越界，则抛出异常。
```python
>>> a = [1,2,3,4,5]
# 默认最后
>>> a.pop()
5
>>> a
[1, 2, 3, 4]
# 指定下标
>>> a.pop(2)
3
```
#### 3）remove()方法
删除首次出现的指定元素，若不存在，抛出异常。
```python
>>> a = [3,3,5,2,3,7,11]
>>> a.remove(3)
>>> a
[3, 5, 2, 3, 7, 11]
```

**remove 的tricky**
```python
# 样例数组中不含有连续的1
def remove_1():
    x = [1, 2, 1, 2, 1, 2, 1, 2, 1]
    for i in x:
        if i == 1:
            x.remove(i)
    print(x)


# 样例数组中含有连续的1
def remove_2():
    x = [1, 2, 1, 1, 1, 2, 1, 1]
    for i in x:
        if i == 1:
            x.remove(i)
    print(x)

if __name__ == "__main__":
    remove_1()
    # [2, 2, 2, 2]
    remove_2()
#     [2, 2, 1, 1]
'''1删除不干净的原因是：Python会自动对列表内存进行收缩并移动列表元素，以保证所以元素之间没有空隙。
增加列表元素的时候也会移动。
    当读到一个数组中有连续的1的时候，删除前一个1后，下一个1会收缩，向前移。导致下一个1没有被判断到。'''
```

**优化**
```python
# 利用切片修正
der remove_c():
    x = [1, 2, 1, 1, 1, 2, 1, 1]
    for i in x[::]:
        if i == 1:
            x.remove(i)
```

# 第3章 选择与循环
## 3.1 条件表达式
```python
"""Python中，if条件表达式的值只要不是False,0,空
    都可以认为与True等价"""


def if_while_test():
    if 3:
        print(5)
    a = [1, 2, 3]

    if a:
        print(6)
    b = []

    if b:
        print(b)
    else:
        print('empty')

    i = s = 0
    # 1~10求和
    while True:
        s += i
        i += 1
        if i > 10:
            break
    print(s)
    # 1~10求和，range范围：[0,11),步长为1
    s = 0
    for i in range(0, 11, 1):
        s += i
    print(s)


def several_compare():
    print(1 < 2 < 3)
    print(1 < 2 > 3)
    print(1 < 3 > 2)
```
#### 短路运算/惰性求值
``` python
def short_route():
    """逻辑运算符 and 和 or 可以利用短路求值和惰性求值的特点（只计算必须计算的表达式的值），来提高运行效率。
       例：and 运算，只要出现一个0，则值为0，之后其他内容不用计算。
           or 运算，只要出现一,1，则值为1，之后其他内容不用计算。"""
    '''功能：使用用户指定的分隔符将多个字符串连接成一个字符串，如果用户没有指定，则默认使用','。
        join()函数
        
        语法：  'sep'.join(seq)
        
        参数说明:
        sep：分隔符。可以为空
        seq：要连接的元素序列、字符串、元组、字典
        上面的语法即：以sep作为分隔符，将seq所有的元素合并成一个新的字符串

        返回值：返回一个以分隔符sep连接各个元素后生成的字符串'''
    # 定义1.0
    def Join(chList, sep=None):
        return (sep or ',').join(chList)

    # 定义2.0，利用默认参数
    def Join(chList, sep=','):
        return sep.join(chList)
    chTest = ['1', '2', '3', '4', '5']
    print(Join(chTest))
    print(Join(chTest, ':'))

# if条件判断不能使用=
# if a = 3: 会报错
```
- Python条件表达式中不允许使用'='


### 3.2 选择结构
#### 3.2.1 单分支选择结构
```python
def single_if():
    x = input('Input two numbers:')
    a, b = map(int, x.split())
    if a > b:
        a, b = b, a
    print(a, b)
```
#### 3.2.2 双分支选择结构
```python
def if_else():
    chTest = ['1', '2', '3', '4', '5']
    if chTest:
        print(chTest)
    else:
        print('empty')
```
- value1 if condition else value2
```python
def v1_if_else_v2():
    """ value1 if condition else value2
        condition的值与True等价时，表达式的值位value1;否则，值为value2
    """
    a = 5
    print(6) if a > 5 else print(5)
    print(6 if a > 3 else 5)
    b = 6 if a > 13 else 9
    print(b)

    # 测试if的惰性，此时没有引入random库，但是由于5 > 3 == True，所以可以输出结果为3.0
    import math
    x = math.sqrt(9) if 5 > 3 else random.randint(1, 100)
    print(x)
    # 测试if的惰性，此时必须引入random库，因为2 > 3 == False，所以需要调用random输出结果
    import random
    x = math.sqrt(9) if 2 > 3 else random.randint(1, 100)
    print(x)
```

#### 3.2.3 多分支选择结构
if...:
elif:
else:
#### 3.2.4 选择结构的嵌套
#### 3.2.5 选择结构的应用案例
```python
def interview():
    age = 24
    subject = "计算机"
    college = "非重点"
    if (age > 25 and subject == "电子信息工程") or (college == '重点' and subject == "电子信息工程") or (
            age <= 28 and subject == "计算机"):
        print('Congratulations!')
    else:
        print('I am sorry.')


def score_input():
    '''用户输入若干个成绩，求所有成绩的总和。每输入一个成绩后询问是否继续输入下一个成绩，回答yes就继续输入下一个成绩，回答no停止输入成绩'''
    '''
    eval()函数
    描述
    eval() 函数用来执行一个字符串表达式，并返回表达式的值。

    语法
    以下是 eval() 方法的语法:

    eval(expression[, globals[, locals]])
    参数
    expression -- 表达式。
    globals -- 变量作用域，全局命名空间，如果被提供，则必须是一个字典对象。
    locals -- 变量作用域，局部命名空间，如果被提供，可以是任何映射对象。
    返回值
    返回表达式计算结果。
    
    raw_input() 和input的区别？？？
'''
    endFlag = 'yes'
    s = 0
    while endFlag.lower() == 'yes':
        x = input('请输入一个正整数：')
        x = eval(x)
        if isinstance(x, int) and 0 <= x <= 100:
            s = s + x
        else:
            print('不是数字或者不符合要求')
        endFlag = raw_input('继续输入？(yes or no)')
        print("整数之和", s)


def CountDay(year, month, day):
    import time

    def demo(year, month, day):
        """编写程序，判断某天是某年第几天。
            本例要点是闰年判断时条件表达式的写法以及关系运算符、逻辑运算符和切片的运用。"""
        day_month = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]  # 每月的天数
        if year % 400 == 0 or (year % 4 == 0 and year % 100 != 0):  # 判断是否为闰年
            day_month[1] = 29  # 闰年2月为29天
        if month == 1:
            return day
        else:
            return sum(day_month[:month - 1]) + day

    date = time.localtime()  # time.localtime()返回的是一个对象<class 'time.struct_time'>
    year, month, day = date[:3]  # date[:3]切片后返回的整体是一个元组，tuple;
    # 可以利用元组给"="左侧的变量赋值，赋值类型和元组中元素类型一致
    print(demo(year, month, day))
    '''date标准库提供了timedelta对象可以很方便的计算指定年，月，日，时，分，秒之前或者之后的日期时间，
        还提供了返回结果包含“今天是今年第几天”，“今天是本周第几天”等答案的timetuple()函数等等'''


def LearningTime():
    import datetime
    Today = datetime.date.today()  # 返回今天的日期 ：年-月—日
    print(Today)
    ''' 原理： 今天日期 - 今年1月1日 + 一天'''
    delta = Today - datetime.date(Today.year, 1, 1) + datetime.timedelta(days=1)  # 今天是今年的第几天
    print(delta)
    test1 = Today.timetuple().tm_yday  # 今天是今年的第几天
    print("输出今天是今年的第几天：", test1)
    test2 = Today.replace(year=2013)  # 替换日期中的年
    print("替换日期中的年：", test2)
    test3 = Today.replace(month=1)  # 替换日期中的月
    print("替换日期中的月：", test3)
    now = datetime.datetime.now()
    print("输出替换后的时间：", now)
    test4 = now.replace(second=30)  # 替换日期中的秒
    print("替换日期中的秒：", test4)
    test5 = now + datetime.timedelta(days=5)    # 计算5天后的日期时间
    print("计算5天后的日期时间", test5)
    test6 = now + datetime.timedelta(weeks=-5)    # 计算5周前的日期时间
    print("计算5周前的日期时间", test6)
```

input 和 raw_input的区别
time库
### 3.3 循环结构
- while循环一般用于循环次数难以提前确定的情况
- for循环一般用于循环次数可以提前确定的情况
- 优先考虑for循环


- 循环的else子句
  - 循环自热结束时执行else结构中的else语句
```python
"""3.3.2 循环结构优化"""
from pip._vendor.msgpack.fallback import xrange


def LoopAdvanced1():
    """尽量减少循环内部不必要的计算，将于循环变量无关的计算尽可能的提取到循环之外。
        尤其对于多重循环的情况。"""
    import time
    digits = (1, 2, 3, 4)

    start = time.time()
    for i in range(1000):
        result = []
        for i in digits:
            for j in digits:
                for k in digits:
                    result.append(i * 100 + j * 10 + k)
    print(time.time() - start)
    print(result)

    start = time.time()
    for i in range(1000):
        result = []
        for i in digits:
            i = i * 100
            for j in digits:  # 循环语句中的j并不受循环体中赋值的影响。
                j = j * 10
                for k in digits:
                    result.append(i + j + k)
    print(time.time() - start)
    print(result)


def LoopAdvanced2():
    """在循环中尽量引用局部变量，因为局部变量的查询和访问速度比全局变量略快。
        在使用模块中的方法时，可以通过将其转换为局部变量来提高运行速度。"""
    import time
    import math
    # method 1.1 直接使用
    start = time.time()  # 获取当前时间
    for i in range(10000000):
        math.sin(i)
    print('Time Used:', time.time() - start)  # 输出所用时间

    # method 1.2 利用局部变量转换
    loc_sin = math.sin  # 将模块的某一个方法变成局部变量
    start = time.time()
    """xrange() 函数用法与 range 完全相同，所不同的是生成的不是一个数组，而是一个生成器。"""
    for i in xrange(10000000):
        loc_sin(i)
    print('Time Used:', time.time() - start)  # 输出所用时间

    """利用另一种导入和使用模块成员的方法,只导入所需要的模块也可以提升运行效率"""
    # method 2.1 直接使用
    import time
    from math import sin as sin
    start = time.time()
    for i in range(10000000):
        sin(i)
    print('Time Used:', time.time() - start)  # 输出所用时间

    # method 2.2 利用局部变量转换
    loc_sin = math.sin  # 将模块的某一个方法变成局部变量
    start = time.time()
    for i in range(10000000):
        loc_sin(i)
    print('Time Used:', time.time() - start)  # 输出所用时间
```

##### 循环语句中的j并不受循环体中赋值的影响。
for语句中的i循环值为：1,2,3,4;

而for循环中的i值为100,200,...

```python
    start = time.time()
    for i in range(1000):
        result = []
        for i in digits:
            i = i * 100
            for j in digits:        # 循环语句中的j并不受循环体中赋值的影响。
                j = j * 10
                for k in digits:
                    result.append(i + j + k)
    print(time.time() - start)
    print(result)
    ```