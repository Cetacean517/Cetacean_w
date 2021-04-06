## 第1章 基础知识
### 1.1 如何选择Python版本
```python
>>> import sys
>>> sys.version   #查看Python版本信息
'3.9.2 (tags/v3.9.2:1a79785, Feb 19 2021, 13:44:55) [MSC v.1928 64 bit (AMD64)]'
>>> sys.winver    #查看Python版本号
'3.9'
>>> sys.version_info    #查看Python详情信息
sys.version_info(major=3, minor=9, micro=2, releaselevel='final', serial=0)
```

### 1.2 Python安装与简单实用
#### 利用IDLE调试
创建文件：File $\rightarrow$ New File，保存为.py / .pyw(对于GUI程序)

检查程序：Run $\rightarrow$ Check Module

运行程序：Run $\rightarrow$ Run Module

#### cmd运行Python
cd 进入地址： python 文件名.py

#### IDLE常用快捷键 书p4

### 1.3 使用pip管理Python扩展库
常用pip命令使用方法
|pip命令| 说明|
|--|--|
|pip install SomePackage|  安装SomePackage模块| 
|pip list| 列出当前已安装的所有模块| 
|pip install --upgrade SomePackage| 升级安装SomePackage模块| 
|pip uninstall SomePackage| 卸载安装SomePackage模块| 
|pip install somePackage| whl使用whl文件直接安装安装SomePackage模块| 

### 1.4 Python基础知识
#### 1.4.1 Python对象模型
#### 1.4.2 Python变量
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

#### 1.4.3 数字
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

#### 1.4.4 字符串
`''' '''`：支持换行，表示较长的注释

格式化：

raw-string: 在字符串前面加r或R表示原始字符串，其中特殊字符不进行转义，但字符串的最后一个字符不能是\。（主要用于正则表达，也开业用来简化路径或url输入）

转义字符
\n  $\qquad$  换行符    \\"  $\qquad$  双引号
\t  $\qquad$  制表符    \\   $\qquad$  一个\
\r  $\qquad$  回车      \ddd  $\qquad$  3位八进制数对应的字符
\\'  $\qquad$  单引号   \xhh  $\qquad$  2为十六进制数对应的字符

#### 1.4.5 运算符与表达式
`x in y;x not in y`  $\qquad$  成员测试运算符
`x is y;x is not y`  $\qquad$  对象实体词同一性测试（地址是否一致：有的值相同，但是地址不相同）

位运算符

| ^ & << >> ~

集合交集、并集、对称差集

Python中用','分割，会产生一个元组

Python

#### 1.4.7 对象的删除 del x
可以使用del命令来显示的删除对象，并解除与值之间的指向关系。

del也可以删除列表或其他可变序列中的指定元素，也可以删除整个列表或者其他类型序列对象。

```python
x = (1,2,3)
del x[1]
del x
```

#### 1.4.8 基本输入输出
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

#### 1.4.9 模块导入与使用
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
