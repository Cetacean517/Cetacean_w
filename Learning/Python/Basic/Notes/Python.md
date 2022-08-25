# Python
## Preparation
### 小结
在Python交互式模式下，可以直接输入代码，然后执行，并立刻得到结果。（用于代码调试）

在命令行模式下，可以直接运行.py文件。

用文本编辑器写Python程序，然后保存为后缀为.py的文件，就可以用Python直接运行这个程序了。

Python的交互模式和直接运行.py文件有什么区别呢？

直接输入python进入交互模式，相当于启动了Python解释器，但是等待你一行一行地输入源代码，每输入一行就执行一行。

直接运行.py文件相当于启动了Python解释器，然后一次性把.py文件的源代码给执行了，你是没有机会以交互的方式输入源代码的。

用Python开发程序，完全可以一边在文本编辑器里写代码，一边开一个交互式命令窗口，在写代码的过程中，把部分代码粘到命令行去验证，事半功倍！前提是得有个27'的超大显示器！

## 1 Python 基础
### 1.1 输入输出
```python
name = input("please enter your name:")
print("hello,",name)
//run
hello xxx
```
- input() 括号中增加输出提示
- print(,)输出。输出时，遇到“，”，则输出空格

### 1.2 数据类型和变量
#### 整数
- 十六进制用`0x`前缀表示：`0xff00`
- 用`_`分割多零数据：`100000000000` 与 `1000_000_000_00`一样

#### 浮点数
- 科学计数法：`1.23e9` = $1.23 \times 10^9$

#### 字符串
- 用`""` / `''`标记字符串
- 转义字符；
- 使用`r''`，`''`内部字符串默认不转义
```python
>>> print('\\\t\\')
\       \
>>> print(r'\\\t\\')
\\\t\\
```
- `'''...'''`:表示多行内容
```python
>>> print(```line1
line2
line3''')
line1
line2
line3
```

#### 布尔型
- `True` & `False` (注意均大写)
- `and`,`or`,`not`运算

#### 空值
- `None` : 区别于0，很多类型都有空值。e.g. 空数组，空list，等等。

#### 变量
等号`=`是赋值语句，可以把任意数据类型赋值给变量，同一个变量可以反复赋值，而且可以是不同类型的变量，例如：
```python
a = 123 # a是整数
print(a)
a = 'ABC' # a变为字符串
print(a)
```
这种变量本身类型不固定的语言称之为**动态语言**，与之对应的是静态语言。静态语言在定义变量时必须指定变量类型，如果赋值的时候类型不匹配，就会报错。

##### 理解变量在计算机内存中的表示
当我们写
`a ='ABC'`时，Python解释器干了两件事：
- 在内存中创建了一个'ABC'的字符串；
- 在内存中创建了一个名为a的变量，并把它指向'ABC'。

**Python支持多个变量指向同一个值** 很重要嗷！！！！（python区别于java,c++的地方）

```python
a = 'ABC'
b = a
a = 'XYZ'
print(b)
```
这段代码做了什么？
- 执行`a = 'ABC'`，解释器创建了字符串`'ABC'`和变量`a`，并把`a`指向`'ABC'`
- 执行`b = a`，解释器创建了变量`b`，并把`b`指向`a`指向的字符串`'ABC'`
- 执行a = `'XYZ'`，解释器创建了字符串`'XYZ'`，并把`a`的指向改为`'XYZ'`，但`b`并没有更改
- 最后打印变量`b`的结果自然是`'ABC'`了

#### 常量
- 用全大写的变量名表示

#### python整数的除法是精确的
- `/`：结果均为浮点数
- `//`（地板除）：结果均为整数
- `%`:取余

#### 小结
- Python支持多种数据类型，在计算机内部，可以把任何数据都看成一个“对象”，而变量就是在程序中用来指向这些数据对象的，对变量赋值就是把数据和变量给关联起来。

- 对变量赋值x = y是把变量x指向真正的对象，该对象是变量y所指向的。随后对变量y的赋值不影响变量x的指向。


- 注意：Python的整数没有大小限制，而某些语言的整数根据其存储长度是有大小限制的，例如Java对32位整数的范围限制在-2147483648-2147483647。

- Python的浮点数也没有大小限制，但是超出一定范围就直接表示为inf（无限大）。

### 1.3 字符串和编码
#### Unicode (统一各种语言)
Unicode把所有语言都统一到一套编码里。

ASCII编码和Unicode编码的区别：ASCII编码是1个字节，而Unicode编码通常是2个字节。
>字母A用ASCII编码是十进制的65，二进制的01000001；
>
>汉字'中'已经超出了ASCII编码的范围，用Unicode编码是十进制的20013，二进制的01001110 00101101。
>
>如果把ASCII编码的A用Unicode编码，只需要在前面补0就可以，因此，A的Unicode编码是00000000 01000001。

#### “可变长编码”的UTF-8编码（解决占用内存多的问题）
UTF-8编码把一个Unicode字符根据不同的数字大小编码成1-6个字节，常用的英文字母被编码成1个字节，汉字通常是3个字节，只有很生僻的字符才会被编码成4-6个字节。如果你要传输的文本包含大量英文字符，用UTF-8编码就能节省空间.

|字符|	ASCII|	Unicode	|UTF-8|
|--|--|--|--|
|A|	01000001|00000000 01000001|	01000001
|中|	x	|01001110 00101101	|11100100 10111000 10101101

UTF-8其中包含了ASCII码，可以包容历史遗留问题。

#### 字符编码的工作方式
我们就可以总结一下现在计算机系统通用的字符编码工作方式：

在计算机内存中，统一使用Unicode编码，当需要保存到硬盘或者需要传输的时候，就转换为UTF-8编码。

用记事本编辑的时候，从文件读取的UTF-8字符被转换为Unicode字符到内存里，编辑完成后，保存的时候再把Unicode转换为UTF-8保存到文件。

![avatar](https://www.liaoxuefeng.com/files/attachments/923923787018816/0)

#### Python的字符串
Python使用Unicode编码，所以支持多语言。

`ord()`：获取字符的整数表示。
`chr()`：把编码转换为对应的字符。

如果知道字符的整数编码，还可以用十六进制这么写str：
```python
>>> '\u4e2d\u6587'
'中文'
```

Python对bytes类型的数据用带b前缀的单引号或双引号表示：
`x = b'ABC'`

`encode()`方法：可以编码为制定的bytes.
```python
>>> 'ABC'.encode('ascii')
b'ABC'
>>> '中文'.encode('utf-8')
b'\xe4\xb8\xad\xe6\x96\x87'
```

`decode()`方法：要把bytes变为str
```python
>>> b'ABC'.decode('ascii')
'ABC'
>>> b'\xe4\xb8\xad\xe6\x96\x87'.decode('utf-8')
'中文'
```

如果bytes中只有一小部分无效的字节，可以传入errors='ignore'忽略错误的字节：

>>> b'\xe4\xb8\xad\xff'.decode('utf-8', errors='ignore')
'中'

`len()`:计算str的字符数；计算bytes的字节数
```python
>>> len('ABC')  #字符数
3
>>> len(b'ABC') #字节数
3
```

```python
#!/usr/bin/env python3
# -*- coding: utf-8 -*-
```
- 第一行注释是为了告诉Linux/OS X系统，这是一个Python可执行程序，Windows系统会忽略这个注释；

- 第二行注释是为了告诉Python解释器，按照UTF-8编码读取源代码，否则，你在源代码中写的中文输出可能会有乱码。

#### 格式化

#### %运算符就是用来格式化字符串的。
案例：
```python
>>> 'Hello, %s' % 'world'
'Hello, world'
>>> 'Hi, %s, you have $%d.' % ('Michael', 1000000)
'Hi, Michael, you have $1000000.'
```
在字符串内部，
- %s表示用字符串替换，
- %d表示用整数替换，有几个%?占位符，后面就跟几个变量或者值，顺序要对应好。
- 如果只有一个%?，括号可以省略。

常用占位符

|占位符	|替换内容|
|----|---|
|%d	|整数|
|%f	|浮点数|
|%s	|字符串|
|%x	|十六进制整数|

设置小数位数，指定输出格式：
```python
print('%2d-%02d' % (3, 1))
print('%.2f' % 3.1415926)
#  3-01
# 3.14
```
##### format()

它会用传入的参数依次替换字符串内的占位符{0}、{1}……，不过这种方式写起来比%要麻烦得多：
```
>>> 'Hello, {0}, 成绩提升了 {1:.1f}%'.format('小明', 17.125)
'Hello, 小明, 成绩提升了 17.1%'
```
#### f-string
它和普通字符串不同之处在于，字符串如果包含{xxx}，就会以对应的变量替换：
```
>>> r = 2.5
>>> s = 3.14 * r ** 2
>>> print(f'The area of a circle with radius {r} is {s:.2f}')
The area of a circle with radius 2.5 is 19.62
```
上述代码中，{r}被变量r的值替换，{s:.2f}被变量s的值替换，并且:后面的.2f指定了格式化参数（即保留两位小数），因此，{s:.2f}的替换结果是19.62。

### 1.4 使用list和tuple
#### list []
list是一种有序的集合，可以随时添加和删除其中的元素。
```python
>>> classmates=['Mickey','Winnie','Cetacean']
```

a. 用`len()`可以获得list元素的个数。

b. 用索引[]来访问list中每一个位置的元素，从0开始。
```python
>>> classmates[0]
Mickey
```

若要取最后一个元素，可以用`-x`做索引，直接获取倒数第x个元素。`classmates[-x]`。

当引索超出范围时，Python会报`IndexError`.

c. list是一个可变的有序表，可以往list中追加元素。

- `append()`：追加元素到list末尾。
```python
>>> classmates.append('Wendy')
>>> classmates
['Mickey','Winnie','Cetacean','Wendy']
```
- `insert(i,'string')` :在i索引位置，插入'stirng'。

```python
>>> classmates.insert(1, 'Jack')
>>> classmates
['Michael', 'Jack', 'Bob', 'Tracy', 'Adam']
```

- ` pop()`,`pop(i)`:删除list末尾的元素,删除i索引位置的元素。

```python
>>> classmates.pop()
'Adam'
>>> classmates
['Michael', 'Jack', 'Bob', 'Tracy']
>>> classmates.pop(1)
'Jack'
>>> classmates
['Michael', 'Bob', 'Tracy']
```
- `list[i]`:i引索位置的替换。直接对list[i]赋值。

```python
>>> classmates[1] = 'Sarah'
>>> classmates
['Michael', 'Sarah', 'Tracy']
```

d. list里元素的数据类型可以不同。（类似广义表）
```python
>>> L = ['Apple', 123, True]
>>> s = ['python', 'java', ['asp', 'php'], 'scheme']
>>> len(s)
4
```

e. 空list: list中没有一个元素，长度为0.
```python
>>> L = []
>>> len(L)
0
```

#### tuple ()
a. tuple元组是一种不可修改的有序列表。因此，没有`append()`,`insert()`,也不可以随意的修改元组的元素。

b. tuple的定义

```python
>>> t = (1,2)   #定义一个普通的元组
>>> t = ()      #定义一个空元组
```
对于只有一个元组的定义，区别两种：
```python
>>> t =(1)
>>> t
1           

#此时，定义的是1这个数而不是1.因为，（）可以表示小括号，此时python默认为：按小括号进行计算。

#正确的定义方法：
>>> t = (1,)
>>> t
(1,)
```

c. 可变的tuple
```python
>>> t = ('a', 'b', ['A', 'B'])
>>> t[2][0] = 'X'
>>> t[2][1] = 'Y'
>>> t
('a', 'b', ['X', 'Y'])
```









### 1.5 条件判断
#### 条件判断
`if`,`if···else`,`if···elif···else`

**注：分割用`:`；判断条件没有'()'，在':'后面直接写；结构体用缩进表示**

格式：

```python
if <条件判断1>:
    <执行1>
elif <条件判断2>:
    <执行2>
elif <条件判断3>:
    <执行3>
else:
    <执行4>
# 案例
age = 3
if age >= 18:
    print('adult')
elif age >= 6:
    print('teenager')
else:
    print('kid')

# 缩写版
if x:
    print('True')

#只要x是非零数值、非空字符串、非空list等，就判断为True，否则为False。
```
#### 再议input
**input()默认返回类型是`str`**。
案例：
```python
birth = input('birth: ')
if birth < 2000:
    print('00前')
else:
    print('00后')
#输入1982，结果报错：
# Traceback (most recent call last):
#   File "<stdin>", line 1, in <module>
# TypeError: unorderable types: str() > int()
```

报错原因：input()返回的数据类型是str，str不能直接和整数比较，必须先把str转换成整数。Python提供了int()函数来完成这件事情。

```python
#正确代码：
s = input('birth: ')
birth = int(s)              #类型转换是关键
if birth < 2000:
    print('00前')
else:
    print('00后')
```


### 1.6 循环
#### for...in 循环
a. `for x in...`:依次把list或tuple中的每个元素迭代出来

```python
names = ['Michael', 'Bob', 'Tracy']
for name in names:
    print(name)

# Michael
# Bob
# Tracy
```

b. 利用`for x in...`求1-100的和。
```python
sum = 0
for x in range(101):
    sum = sum + x
print(sum)
```
- range(x):生成一个从0-(x-1)的整数数列。


#### while 循环
计算0-100中所有奇数和：
```python
sum = 0
n = 99
while n > 0:
    sum = sum + n
    n = n - 2
print(sum)
```

#### continue
跳过当前的这次循环，直接开始下一次循环。

#### break
break语句可以提前退出循环。

#### 小结
- 循环是让计算机做重复任务的有效的方法。

- break语句可以在循环过程中直接退出循环，而continue语句可以提前结束本轮循环，并直接开始下一轮循环。这两个语句通常都必须配合if语句使用。

- 要特别注意，不要滥用break和continue语句。break和continue会造成代码执行逻辑分叉过多，容易出错。大多数循环并不需要用到break和continue语句，上面的两个例子，都可以通过改写循环条件或者修改循环逻辑，去掉break和continue语句。

- 有些时候，如果代码写得有问题，会让程序陷入“死循环”，也就是永远循环下去。这时可以用Ctrl+C退出程序，或者强制结束Python进程。


### 1.7 使用dict和set
#### dict {}
a. dict:Python内置字典。全称dictionary，在其他语言中也称map,使用键-值(key-value)存储，具有极快的查找速度。

实现：
```python
>>> d = {'Michael':95,'Bob':75,'Tracy':85}
>>> d['Michael']
```

b. dict查找速度快的原因

因为dict的实现原理和查字典是一样的。假设字典包含了1万个汉字，我们要查某一个字，一个办法是把字典从第一页往后翻，直到找到我们想要的字为止，这种方法就是在list中查找元素的方法，list越大，查找越慢。

第二种方法是先在字典的索引表里（比如部首表）查这个字对应的页码，然后直接翻到该页，找到这个字。无论找哪个字，这种查找速度都非常快，不会随着字典大小的增加而变慢。

dict就是第二种实现方式，给定一个名字，比如'Michael'，dict在内部就可以直接计算出Michael对应的存放成绩的“页码”，也就是95这个数字存放的内存地址，直接取出来，所以速度非常快。

c. dict的存储方式
key-value存储方式，在放进去的时候，必须根据key算出value的存放位置，这样，取的时候才能根据key直接拿到value。

把数据放入dict的方法，除了初始化时指定外，还可以通过key放入：
```python
>>> d['Adam'] = 67
>>> d['Adam']
67
```

由于一个key只能对应一个value，所以，**多次对一个key放入value，后面的值会把前面的值冲掉**：
```python
>>> d['Jack'] = 90
>>> d['Jack']
90
>>> d['Jack'] = 88
>>> d['Jack']
88
```

d. 判断key是否存在

- 通过in判断key是否存在：
``` python
>>> 'Thomas' in d
False
```

- 通过dict提供的get()方法，如果key不存在，可以返回None，或者自己指定的value：
```python
>>> d.get('Thomas')
>>> d.get('Thomas', -1)
-1
```
**注意：返回None的时候Python的交互环境不显示结果**。

e. dict中元素的删除
使用`pop()`方法：删除value-key值
```python
>>> d.pop('Bob')
75
>>> d
{'Michael': 95, 'Tracy': 85}
```

请务必注意，dict内部存放的顺序和key放入的顺序是没有关系的。

和list比较，dict有以下几个特点：

1. 查找和插入的速度极快，不会随着key的增加而变慢；
2. 需要占用大量的内存，内存浪费多。
而list相反：

1. 查找和插入的时间随着元素的增加而增加；
2. 占用空间小，浪费内存很少。
所以，dict是用空间来换取时间的一种方法。

dict可以用在需要高速查找的很多地方，在Python代码中几乎无处不在，正确使用dict非常重要，需要牢记的第一条就是dict的key必须是不可变对象。

这是因为dict根据key来计算value的存储位置，如果每次计算相同的key得出的结果不同，那dict内部就完全混乱了。这个通过key计算位置的算法称为哈希算法（Hash）。

要保证hash的正确性，作为key的对象就不能变。在Python中，字符串、整数等都是不可变的，因此，可以放心地作为key。而list是可变的，就不能作为key
```python
>>> key = [1, 2, 3]
>>> d[key] = 'a list'
# Traceback (most recent call last):
#   File "<stdin>", line 1, in <module>
# TypeError: unhashable type: 'list'
```

#### set([])
set也是一组key的集合，但不存储value。由于key不能重复，所以，在set中，没有重复的key。

a. set的创建
```python
>>> s = set([1, 2, 3])
>>> s
{1, 2, 3}
```
**注意，传入的参数[1, 2, 3]是一个list，而显示的{1, 2, 3}只是告诉你这个set内部有1，2，3这3个元素，显示的顺序也不表示set是有序的**。

重复元素在set中自动被过滤

b. set添加/删除元素
- `add(key)`：添加元素到set中，可以重复添加，但不会有效果。

```python
>>> s.add(4)
>>> s
{1, 2, 3, 4}
>>> s.add(4)
>>> s
{1, 2, 3, 4}
```
- `remove(key)`：删除元素
- 
```python
>>> s.remove(4)
>>> s
{1,2,3}
```

c. set的操作
set可以看成数学意义上的无序和无重复元素的集合，因此，两个set可以做数学意义上的交集、并集等操作。

**交集：&；并集：|**

```python
>>> s1 = set([1, 2, 3])
>>> s2 = set([2, 3, 4])
>>> s1 & s2
{2, 3}
>>> s1 | s2
{1, 2, 3, 4}
```

#### 辨析set与disc
set和dict的唯一区别仅在于没有存储对应的value。

但是，set的原理和dict一样，所以，同样不可以放入可变对象。

因为无法判断两个可变对象是否相等，也就无法保证set内部“不会有重复元素”。试试把list放入set，看看是否会报错。



### 1.8 再议不可变对象
对于可变对象，比如list，对list进行操作，list内部的内容是会变化的，比如：

```python
>>> a = ['c', 'b', 'a']
>>> a.sort()
>>> a
['a', 'b', 'c']
```

而对于不可变对象，比如str，对str进行操作呢：
```python
>>> a = 'abc'
>>> a.replace('a', 'A')
'Abc'
>>> a
'abc'
```

虽然字符串有个replace()方法，也确实变出了'Abc'，但变量a最后仍是'abc'，应该怎么理解呢？

我们先把代码改成下面这样：
```python
>>> a = 'abc'
>>> b = a.replace('a', 'A')
>>> b
'Abc'
>>> a
'abc'
```
它的本质是创建了一个新的字符串"Abc"，而不是修改原本存在的"abc"

#### 小结
使用key-value存储结构的dict在Python中非常有用，选择不可变对象作为key很重要，最常用的key是字符串。

tuple虽然是不变对象，但试试把(1, 2, 3)和(1, [2, 3])放入dict或set中，并解释结果。

```python
>>> t1 = (1,2,3)
>>> t2 = (1,[2,3])
>>> d1 = {t1}
>>> d2 = {t2}
Traceback (most recent call last):
  File "<pyshell#3>", line 1, in <module>
    d2 = {t2}
TypeError: unhashable type: 'list'
>>> s1 = set(t1)
>>> s2 = set(t2)
Traceback (most recent call last):
  File "<pyshell#5>", line 1, in <module>
    s2 = set(t2)
TypeError: unhashable type: 'list'
```
结果：前者可以放入dict/set，而后者不可以。可以放入两者的前提是：有唯一的key值才能够进行hash计算唯一的值，而第二个含有list，list是可变表，因此不能存入。

## 2 函数
Python官方文档：

http://docs.python.org/3/library/functions.html#abs
### 2.1 调用函数
#### abs
```python
>>> help(abs)
Help on built-in function abs in module builtins:

abs(x, /)
    Return the absolute value of the argument.

>>> x = -9
>>> abs(x)
9
```
#### max
```python
>>> help(max)
Help on built-in function max in module builtins:

max(...)
    max(iterable, *[, default=obj, key=func]) -> value
    max(arg1, arg2, *args, *[, key=func]) -> value
    
    With a single iterable argument, return its biggest item. The
    default keyword-only argument specifies an object to return if
    the provided iterable is empty.
    With two or more arguments, return the largest argument.

>>> max(2,3,-1,5)
5
>>> 
```

#### 数据类型转换
```python
>>> int('123')
123
>>> int(12.34)
12
>>> float('12.34')
12.34
>>> str(1.23)
'1.23'
>>> str(100)
'100'
>>> bool(1)
True
>>> bool('')
False
```

函数名其实就是指向一个函数对象的引用，完全可以把函数名赋给一个变量，相当于给这个函数起了一个“别名”：
```python
>>> a = abs # 变量a指向abs函数
>>> a(-1) # 所以也可以通过a调用abs函数
1
```


### 2.2 定义函数
#### 定义函数
在Python中定义一个函数：
- 要使用def语句，
- 依次写出函数名、括号、括号中的参数和冒号:，
- 然后，在缩进块中编写函数体，
- 函数的返回值用return语句返回。

写一个自定义的abs函数
```python
def my_abs(x):
    if x >= 0:
        return x
    else:
        return -x
```
** 导入函数
如果你已经把my_abs()的函数定义保存为abstest.py文件了，那么，可以在该文件的当前目录下启动Python解释器，用from abstest import my_abs来导入my_abs()函数，注意abstest是文件名（不含.py扩展名）：

```python
>>> from abstest import my_abs                    
>>> my_abs(-9)                                    
9                                                 
>>> _                          
```                   
import的用法在后续模块一节中会详细介绍。




#### 空函数
如果想定义一个什么事也不做的空函数，可以用pass语句：

```python
def nop():
    pass
```

pass语句什么都不做，那有什么用？实际上pass可以用来作为占位符，比如现在还没想好怎么写函数的代码，就可以先放一个pass，让代码能运行起来。

pass还可以用在其他语句里，比如：

```python
if age >= 18:
    pass
```

#### 参数检查
试试my_abs和内置函数abs的差别：
```python
>>> my_abs('A')
# Traceback (most recent call last):
#   File "<stdin>", line 1, in <module>
#   File "<stdin>", line 2, in my_abs
# TypeError: unorderable types: str() >= int()
>>> abs('A')
# Traceback (most recent call last):
#   File "<stdin>", line 1, in <module>
# TypeError: bad operand type for abs(): 'str'
```

当传入了不恰当的参数时，内置函数abs会检查出参数错误，而我们定义的my_abs没有参数检查，会导致if语句出错，出错信息和abs不一样。所以，这个函数定义不够完善。

让我们修改一下my_abs的定义，对参数类型做检查，只允许整数和浮点数类型的参数。数据类型检查可以用内置函数isinstance()实现：

```python
def my_abs(x):
    if not isinstance(x, (int, float)):
        raise TypeError('bad operand type')
    if x >= 0:
        return x
    else:
        return -x
```
添加了参数检查后，如果传入错误的参数类型，函数就可以抛出一个错误：
```python
>>> my_abs('A')
# Traceback (most recent call last):
#   File "<stdin>", line 1, in <module>
#   File "<stdin>", line 3, in my_abs
# TypeError: bad operand type
```

#### 返回多个值

比如在游戏中经常需要从一个点移动到另一个点，给出坐标、位移和角度，就可以计算出新的坐标：
```python
import math

def move(x, y, step, angle=0):
    nx = x + step * math.cos(angle)
    ny = y - step * math.sin(angle)
    return nx, ny
```
import math语句表示导入math包，并允许后续代码引用math包里的sin、cos等函数。

然后，我们就可以同时获得返回值：
```python
>>> x, y = move(100, 100, 60, math.pi / 6)
>>> print(x, y)
151.96152422706632 70.0
```
但其实这只是一种假象，Python函数返回的仍然是单一值：

```python
>>> r = move(100, 100, 60, math.pi / 6)
>>> print(r)
(151.96152422706632, 70.0)
```
原来返回值是一个tuple！但是，在语法上，返回一个tuple可以省略括号，而多个变量可以同时接收一个tuple，按位置赋给对应的值，所以，Python的函数返回多值其实就是返回一个tuple，但写起来更方便。

#### 小结
- 定义函数时，需要确定函数名和参数个数；

- 如果有必要，可以先对参数的数据类型做检查；

- 函数体内部可以用return随时返回函数结果；

- 函数执行完毕也没有return语句时，自动return None。

- 函数可以同时返回多个值，但其实就是一个tuple。

### 2.3 函数的参数
#### 位置参数
```python
def power(x):
    return x * x
```
对于power(x)函数，参数x就是一个位置参数。

当我们调用power函数时，必须传入有且仅有的一个参数x。

把power(x)修改为power(x, n)，用来计算xn

```python
def power(x, n):
    s = 1
    while n > 0:
        n = n - 1
        s = s * x
    return s
# >>> power(5, 2)
# 25
# >>> power(5, 3)
# 125
```

对于这个修改后的power(x, n)函数，可以计算任意n次方.

修改后的power(x, n)函数有两个参数：x和n，这两个参数都是位置参数，调用函数时，传入的两个值按照位置顺序依次赋给参数x和n。


#### 默认参数 （x = value; 变化越大放在约前面)
由于我们经常计算x2，所以，完全可以把第二个参数n的默认值设定为2：

```python
def power(x, n=2):
    s = 1
    while n > 0:
        n = n - 1
        s = s * x
    return s
```

这样，当我们调用power(5)时，相当于调用power(5, 2)

从上面的例子可以看出，默认参数可以简化函数的调用。设置默认参数时，有几点要注意：

一是必选参数在前，默认参数在后，否则Python的解释器会报错（思考一下为什么默认参数不能放在必选参数前面）；//因为如果默认参数放在必选参数前面，那么当参数类型一致的时候，机器就无法判断默认参数是使用默认值，还是参数值。

二是如何设置默认参数。

当函数有多个参数时，把变化大的参数放前面，变化小的参数放后面。变化小的参数就可以作为默认参数。

使用默认参数有什么好处？最大的好处是能降低调用函数的难度。

举个例子，我们写个一年级小学生注册的函数，需要传入name和gender两个参数：
```python
def enroll(name, gender):
    print('name:', name)
    print('gender:', gender)
```
这样，调用enroll()函数只需要传入两个参数：

```python
>>> enroll('Sarah', 'F')
name: Sarah
gender: F
```
如果要继续传入年龄、城市等信息怎么办？这样会使得调用函数的复杂度大大增加。

我们可以把年龄和城市设为默认参数：

```python
def enroll(name, gender, age=6, city='Beijing'):
    print('name:', name)
    print('gender:', gender)
    print('age:', age)
    print('city:', city)
```
这样，大多数学生注册时不需要提供年龄和城市，只提供必须的两个参数：

```python
>>> enroll('Sarah', 'F')
name: Sarah
gender: F
age: 6
city: Beijing
```

只有与默认参数不符的学生才需要提供额外的信息：

```python
enroll('Bob', 'M', 7)
enroll('Adam', 'M', city='Tianjin')
```

可见，默认参数降低了函数调用的难度，而一旦需要更复杂的调用时，又可以传递更多的参数来实现。无论是简单调用还是复杂调用，函数只需要定义一个。

有多个默认参数时，调用的时候，既可以按顺序提供默认参数，比如调用`enroll('Bob', 'M', 7)`，意思是，除了name，gender这两个参数外，最后1个参数应用在参数age上，city参数由于没有提供，仍然使用默认值。

也可以不按顺序提供部分默认参数。**当不按顺序提供部分默认参数时，需要把参数名写上**。比如调用`enroll('Adam', 'M', city='Tianjin')`，意思是，city参数用传进去的值，其他默认参数继续使用默认值。

##### 默认参数 入到 list 的大坑

默认参数很有用，但使用不当，也会掉坑里。默认参数有个最大的坑，演示如下：

先定义一个函数，传入一个list，添加一个END再返回：

```python
def add_end(L=[]):
    L.append('END')
    return L
```

当你正常调用时，结果似乎不错：

```python
>>> add_end([1, 2, 3])
[1, 2, 3, 'END']
# >>> add_end(['x', 'y', 'z'])
# ['x', 'y', 'z', 'END']
```

当你使用默认参数调用时，一开始结果也是对的：

```python
>>> add_end()
['END']
```

但是，再次调用add_end()时，结果就不对了：

```python
>>> add_end()
['END', 'END']
>>> add_end()
['END', 'END', 'END']
```

很多初学者很疑惑，默认参数是[]，但是函数似乎每次都“记住了”上次添加了'END'后的list。

原因解释如下：

Python函数在定义的时候，默认参数L的值就被计算出来了，即`[]`，**因为默认参数L也是一个变量，它指向对象`[]`，每次调用该函数，如果改变了L的内容，则下次调用时，默认参数的内容就变了，不再是函数定义时的`[]`了**。

 定义默认参数要牢记一点：**默认参数必须指向不变对象！**

 要修改上面的例子，我们可以用None这个不变对象来实现：

```python
def add_end(L=None):
    if L is None:
        L = []
    L.append('END')
    return L
```

为什么要设计str、None这样的不变对象呢？因为不变对象一旦创建，对象内部的数据就不能修改，这样就减少了由于修改数据导致的错误。此外，由于对象不变，多任务环境下同时读取对象不需要加锁，同时读一点问题都没有。我们在编写程序时，如果可以设计一个不变对象，那就尽量设计成不变对象。

#### 可变参数 （参数前加 *; 接收到的是tuple类型）
```python
def calc(*numbers):
    sum = 0
    for n in numbers:
        sum = sum + n * n
    return sum
```
定义可变参数和定义一个list或tuple参数相比，仅仅在参数前面加了一个*号。在函数内部，参数numbers接收到的是一个tuple，因此，函数代码完全不变。但是，调用该函数时，可以传入任意个参数，包括0个参数：
```
>>> calc(1, 2)
5
>>> calc()
0
```
如果已经有一个list或者tuple，要调用一个可变参数怎么办？可以这样做：
```
>>> nums = [1, 2, 3]
>>> calc(nums[0], nums[1], nums[2])
14
```
这种写法当然是可行的，问题是太繁琐，所以Python允许你在list或tuple前面加一个*号，把list或tuple的元素变成可变参数传进去：
```
>>> nums = [1, 2, 3]
>>> calc(*nums)
14
```
***nums表示把nums这个list的所有元素作为可变参数传进去**。这种写法相当有用，而且很常见。

#### 关键字参数（**kw ;可传入0/n个;接收到的是key:value）
**a. 案例**
可变参数允许你传入0个或任意个参数，这些可变参数在函数调用时自动组装为一个tuple。而关键字参数允许你传入0个或任意个含参数名的参数，这些关键字参数在函数内部自动组装为一个dict。请看示例：
```python
def person(name, age, **kw):
    print('name:', name, 'age:', age, 'other:', kw)
```
**b. 传入的关键字参数可以是任意个数(包括0个)**

函数person除了必选参数name和age外，还接受关键字参数kw。在调用该函数时，可以只传入必选参数：
```python
>>> person('Michael', 30)
name: Michael age: 30 other: {}
```

也可以传入任意个数的关键字参数：

```python
>>> person('Bob', 35, city='Beijing')
name: Bob age: 35 other: {'city': 'Beijing'}
>>> person('Adam', 45, gender='M', job='Engineer')
name: Adam age: 45 other: {'gender': 'M', 'job': 'Engineer'}
```

**c.关键字的作用**

关键字参数有什么用？它可以扩展函数的功能。比如，在person函数里，我们保证能接收到name和age这两个参数，但是，如果调用者愿意提供更多的参数，我们也能收到。试想你正在做一个用户注册的功能，除了用户名和年龄是必填项外，其他都是可选项，利用关键字参数来定义这个函数就能满足注册的需求。

**d. 不同的传入方式**

和可变参数类似，也可以先组装出一个dict，然后，把该dict转换为关键字参数传进去：
```python
>>> extra = {'city': 'Beijing', 'job': 'Engineer'}
>>> person('Jack', 24, city=extra['city'], job=extra['job'])
name: Jack age: 24 other: {'city': 'Beijing', 'job': 'Engineer'}
```

当然，上面复杂的调用可以用简化的写法：
```python
>>> extra = {'city': 'Beijing', 'job': 'Engineer'}
>>> person('Jack', 24, **extra)
name: Jack age: 24 other: {'city': 'Beijing', 'job': 'Engineer'}
```

**extra表示把extra这个dict的所有key-value用关键字参数传入到函数的**kw参数，kw将获得一个dict，注意kw获得的dict是extra的一份拷贝，对kw的改动不会影响到函数外的extra。

#### 命名关键字参数 (*,xxxx,xxxx)
**a. 案例**

命名关键字参数可以限制关键字参数的名字。

例如，只接收city和job作为关键字参数。这种方式定义的函数如下：
```python
def person(name, age, *, city, job):
    print(name, age, city, job)
```

和关键字参数`**kw`不同，命名关键字参数需要一个特殊分隔符`*`，`*`后面的参数被视为命名关键字参数。

调用方式如下：
```python
>>> person('Jack', 24, city='Beijing', job='Engineer')
Jack 24 Beijing Engineer
```

**特殊**

如果函数定义中已经有了一个可变参数，后面跟着的命名关键字参数就不再需要一个特殊分隔符*了：
```python
def person(name, age, *args, city, job):
    print(name, age, args, city, job)
```
命名关键字参数必须传入参数名，这和位置参数不同。如果没有传入参数名，调用将报错：

```python
>>> person('Jack', 24, 'Beijing', 'Engineer')
# Traceback (most recent call last):
#   File "<stdin>", line 1, in <module>
# TypeError: person() takes 2 positional arguments but 4 were given
```
由于调用时缺少参数名city和job，Python解释器把这4个参数均视为位置参数，但person()函数仅接受2个位置参数。

命名关键字参数可以有缺省值，从而简化调用：
```python
def person(name, age, *, city='Beijing', job):
    print(name, age, city, job)
```
由于命名关键字参数city具有默认值，调用时，可不传入city参数：

```python
>>> person('Jack', 24, job='Engineer')
Jack 24 Beijing Engineer
```

使用命名关键字参数时，要特别注意，如果没有可变参数，就必须加一个`*`作为特殊分隔符。如果缺少`*`，Python解释器将无法识别位置参数和命名关键字参数：

```python
def person(name, age, city, job):
    # 缺少 *，city和job被视为位置参数
    pass
```

#### 参数组合
 在Python中定义函数，可以用必选参数、默认参数、可变参数、关键字参数和命名关键字参数，这5种参数都可以组合使用。
 
 但是请注意，
 
 参数定义的顺序必须是：**必选参数、默认参数、可变参数、命名关键字参数和关键字参数**。

 比如定义一个函数，包含上述若干种参数：
```python
def f1(a, b, c=0, *args, **kw):
    print('a =', a, 'b =', b, 'c =', c, 'args =', args, 'kw =', kw)

def f2(a, b, c=0, *, d, **kw):
    print('a =', a, 'b =', b, 'c =', c, 'd =', d, 'kw =', kw)
```
在函数调用的时候，Python解释器自动按照参数位置和参数名把对应的参数传进去。

```python
>>> f1(1, 2)
a = 1 b = 2 c = 0 args = () kw = {}
>>> f1(1, 2, c=3)
a = 1 b = 2 c = 3 args = () kw = {}
>>> f1(1, 2, 3, 'a', 'b')
a = 1 b = 2 c = 3 args = ('a', 'b') kw = {}
>>> f1(1, 2, 3, 'a', 'b', x=99)
a = 1 b = 2 c = 3 args = ('a', 'b') kw = {'x': 99}
>>> f2(1, 2, d=99, ext=None)
a = 1 b = 2 c = 0 d = 99 kw = {'ext': None}
```

最神奇的是通过一个tuple和dict，你也可以调用上述函数：

```python
>>> args = (1, 2, 3, 4)
>>> kw = {'d': 99, 'x': '#'}
>>> f1(*args, **kw)
a = 1 b = 2 c = 3 args = (4,) kw = {'d': 99, 'x': '#'}
>>> args = (1, 2, 3)
>>> kw = {'d': 88, 'x': '#'}
>>> f2(*args, **kw)
a = 1 b = 2 c = 3 d = 88 kw = {'x': '#'}
```

所以，对于任意函数，都可以通过类似func(*args, **kw)的形式调用它，无论它的参数是如何定义的。

#### 小结
Python的函数具有非常灵活的参数形态，既可以实现简单的调用，又可以传入非常复杂的参数。

默认参数一定要用不可变对象，如果是可变对象，程序运行时会有逻辑错误！

要注意定义可变参数和关键字参数的语法：

*args是可变参数，args接收的是一个tuple；

**kw是关键字参数，kw接收的是一个dict。

以及调用函数时如何传入可变参数和关键字参数的语法：

可变参数既可以直接传入：func(1, 2, 3)，又可以先组装list或tuple，再通过*args传入：func(*(1, 2, 3))；

关键字参数既可以直接传入：func(a=1, b=2)，又可以先组装dict，再通过**kw传入：func(**{'a': 1, 'b': 2})。

使用*args和**kw是Python的习惯写法，当然也可以用其他参数名，但最好使用习惯用法。

命名的关键字参数是为了限制调用者可以传入的参数名，同时可以提供默认值。

定义命名的关键字参数在没有可变参数的情况下不要忘了写分隔符*，否则定义的将是位置参数。

### 2.4 递归函数
案例：n!
```python
def fact(n):
    if n==1:
        return 1
    return n * fact(n - 1)
```

递归函数的优点是定义简单，逻辑清晰。理论上，所有的递归函数都可以写成循环的方式，但循环的逻辑不如递归清晰。

使用递归函数需要注意防止栈溢出。在计算机中，函数调用是通过栈（stack）这种数据结构实现的，每当进入一个函数调用，栈就会加一层栈帧，每当函数返回，栈就会减一层栈帧。由于栈的大小不是无限的，所以，递归调用的次数过多，会导致栈溢出。

解决递归调用栈溢出的方法是通过尾递归优化，事实上尾递归和循环的效果是一样的，所以，把循环看成是一种特殊的尾递归函数也是可以的。

尾递归是指，在函数返回的时候，调用自身本身，并且，return语句不能包含表达式。这样，编译器或者解释器就可以把尾递归做优化，使递归本身无论调用多少次，都只占用一个栈帧，不会出现栈溢出的情况。

上面的fact(n)函数由于return n * fact(n - 1)引入了乘法表达式，所以就不是尾递归了。要改成尾递归方式，需要多一点代码，主要是要把每一步的乘积传入到递归函数中：
```python
def fact(n):
    return fact_iter(n, 1)

def fact_iter(num, product):
    if num == 1:
        return product
    return fact_iter(num - 1, num * product)
```

可以看到，return fact_iter(num - 1, num * product)仅返回递归函数本身，num - 1和num * product在函数调用前就会被计算，不影响函数调用。

fact(5)对应的fact_iter(5, 1)的调用如下：
```
===> fact_iter(5, 1)
===> fact_iter(4, 5)
===> fact_iter(3, 20)
===> fact_iter(2, 60)
===> fact_iter(1, 120)
===> 120
```
尾递归调用时，如果做了优化，栈不会增长，因此，无论多少次调用也不会导致栈溢出。

遗憾的是，大多数编程语言没有针对尾递归做优化，Python解释器也没有做优化，所以，即使把上面的fact(n)函数改成尾递归方式，也会导致栈溢出。

### 小结
使用递归函数的优点是逻辑简单清晰，缺点是过深的调用会导致栈溢出。

针对尾递归优化的语言可以通过尾递归防止栈溢出。尾递归事实上和循环是等价的，没有循环语句的编程语言只能通过尾递归实现循环。

Python标准的解释器没有针对尾递归做优化，任何递归函数都存在栈溢出的问题。


## 3 高级特性
### 3.1 切片
#### 引子
取一个list或tuple的部分元素的操作。

思考：如何取以下list前三个元素？
```python
>>> L = ['Michael', 'Sarah', 'Tracy', 'Bob', 'Jack']

# 利用引索值；无法取前n项
>>> [L[0], L[1], L[2]]
['Michael', 'Sarah', 'Tracy']

# 利用循环，解决取前n项；但操作麻烦
>>> r = []
>>> n = 3
>>> for i in range(n):
    r.append(L[i])

>>> r
['Michael', 'Sarah', 'Tracy']

# 利用切片
>>> L[0:3]
['Michael', 'Sarah', 'Tracy']
```

#### 语法和性质
**切片中的引索值是数组下标，n表示第n+1个数；且是范围的闭开区间**。
**参数1：起始 参数2：终止 参数3：step**
a. `L[0:3]`:表示从索引0开始取，直到索引3为止，**但不包括索引3**。即索引0，1，2，正好是3个元素。

b. `L[:3]`:如果第一个索引是0，还可以省略：

```python
>>> L[:3]
['Michael', 'Sarah', 'Tracy']
```
c. `L[-2:]`:支持倒数切片，记住倒数第一个元素的索引是-1。

#### 常用切片
- list的切片

```python
>>> L = list(range(100))
>>> L
[0, 1, 2,..., 98, 99]
# 前十个
>>> L[:10]
[0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
# 倒数10个
>>> L[-10:]
[90, 91, 92, 93, 94, 95, 96, 97, 98, 99]
# 第11~20个
>>> L[10:20]
[10, 11, 12, 13, 14, 15, 16, 17, 18, 19]
# 前10个数，每两个取一个
>>> L[:10:2]
[0, 2, 4, 6, 8]
# 所有数，每5个取1个
>>> L[::5]
[0, 5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95]
# 原样复制一个list
>>> L[:]
[0, 1, 2,..., 98, 99]
```

- tuple的切片
```python
>>> (0, 1, 2, 3, 4, 5)[:3]
(0, 1, 2)
```

- 字符串的切片
```python
>>> 'ABCDEFG'[:3]
'ABC'
>>> 'ABCDEFG'[::2]
'ACEG'
```


## 4 函数式编程
### 高阶函数
- 变量可以指向函数，函数可以接收变量作为参数。
- 函数名的实质：一个变量指向这个函数。
- 把函数作为参数传入，这样的函数称为高阶函数，函数式编程就是指这种高度抽象的编程范式。
#### map()
语法：
- 参数：
  - 参数1：函数
  - 参数2：Iterable (可迭代对象，e.g.list,tuple...)
- 返回值：Iterator(迭代器)
功能：
- map将传入的函数依次作用到序列的每个元素，并把结果作为新的Iterator返回。

案例：
- map()传入的第一个参数是f，即函数对象本身。由于结果r是一个Iterator，Iterator是惰性序列，因此通过list()函数让它把整个序列都计算出来并返回一个list。

```python
'''把list中的每个元素平方，返回'''
>>> def f(x):
...     return x * x
...
>>> r = map(f, [1, 2, 3, 4, 5, 6, 7, 8, 9])
>>> list(r)
[1, 4, 9, 16, 25, 36, 49, 64, 81]

'''把list中的每个元素变成字符串，返回'''
>>> list(map(str, [1, 2, 3, 4, 5, 6, 7, 8, 9]))
['1', '2', '3', '4', '5', '6', '7', '8', '9']
```


## 面向对象编程
### 类和实例
```python
class Student(object)
```

如果不写def __init__(self,args) 函数，则创建实例的时候，可以使用无参数的类创建。
若定义了内置的值，则创建实例的时候，需要传入指定的参数值。