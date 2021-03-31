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

在字符串内部，
- %s表示用字符串替换，
- %d表示用整数替换，有几个%?占位符，后面就跟几个变量或者值，顺序要对应好。
- 如果只有一个%?，括号可以省略。

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
95
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
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
TypeError: unhashable type: 'list'
```