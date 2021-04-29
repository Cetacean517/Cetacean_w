### 第一章 习题
#### 1.简单说明如何选择正确的Python版本？
应根据自己所学习的需求和目的选择最合适的版本。并不一定版本号越大，版本就越新。例如，Python2.7.9比Python3.2.6晚几个月发布。同时，也不一定使用最新的版本就是最合适的，因为有些机器并不一定兼容Python3.x的版本。

而对于不知道如何选择python版本的初学者，可以选择Python3.x的最新版作为学习版本。因为Python3.x是大势所趋，也比较好使用。

#### 2.为什么说Python采用的是基于值的内存管理模式？
因为Python对于不同变量赋相同值，只会在内存中保存一份值的信息。两个变量指向同一个地址单元。

整数

因为对于[-5~256]之间的整数，不同变量但是值相同，则他们的id地址是相同的。但是对于范围外的整数，则无效。
```python
# 范围内
>>> x = -6
>>> y = -6
>>> id(x)
2166372015600
>>> y = -6
>>> id(y)
2166372015504
# 范围外
>>> x = 10
>>> y = 10
>>> id(x)
2166333008464
>>> id(y)
2166333008464
```

复数

对于复数，这个并不成立
```python
>>> x = 3 + 1j
>>> y = 3 + 1j
>>> id(x)
2166372015472
>>> id(y)
2166372015600
```

字符串
```python
>>> x = 'abcsdwef'
>>> y = 'abcsdwef'
>>> id(x)
2166372908144
>>> id(y)
2166372908144
```

Python具有自动内存管理功能，会跟踪所有的值。（有看到资料说：Python会记录每一个变量的引索值，当引索值为0时，则自动删除）

#### 3.解释Python中的运算符/和//的区别。
`/`：得到的结果永远是浮点数，正常除法

```python
>>> 5/10
0.5
>>> 10/5
2.0
>>> 1/3
0.3333333333333333
```
`//`(地板除）：结果均是整数,取整数商

```python
>>> 5//10
0
>>> 10//5
2
>>> 50//2
25
```

#### 4.在Python中导入模块中的对象有哪几种方式？
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

#### 5._______是目前比较常用的Python扩展库管理工具。
pip
#### 6.解释Python脚本程序的__name__变量及其作用。
__name__是每个Python脚本程序自带的一个属性。如果脚本作为模块被导入，则其__name__属性的值自动设置为模块名。如果脚本独立运行，则其__name__属性值被自动设置为"__main__"

可以通过这控制，仅执行当本脚本为主线程的程序，而当本脚本为作为模块导入时，则不使用。

案例：
在同一目录下新建两个文件first.py和import_first.py
```python
# first.py
print("I\'am the first")


if __name__ == "__main__"
    print("I\'am the second")
```
```python
# import_first.py
import first
```

运行first.py时输出结果：
```python
I'am the first
I'am the second
```

运行import_first.py时输出结果：
```python
I'am the first
```

原因：运行first.py时，该程序的__name___是main；而后者运行是，则变成了__first__.

#### 7.运算符%______(可以、不可以)对浮点数进行求余数操作。
可以。
```python
>>> 3.5%2
1.5
>>> 4.2 % 1.5
1.2000000000000002
```
#### 8.一个数字5______(是、不是)合法的Python表达式。（p13）
是

#### 9.在Python2.x中，input()函数接收到的数据类型由______确定，而在Python3.x中该函数则认为接收到的用户输入数据一律为________。
输入值使用的界定符；字符串类型。

#### 10.编写程序，用户输入一个三位以上的整数，输出其百位以上的数字。例如用户输入1234，则程序输出12（提示：使用整除运算）
```python
# biggerThanThree.py
def getTop(x=input("Please enter a number(contain at least 4 number:)")):
    print(int(x[::]) // 100)
```

### 第五章 习题
#### 4. 在函数内部可以通过关键字_______来定义全局变量
global

#### 5. 如果函数中没有return语句或者return语句不带任何返回值，那么该函数的返回值为______。
None.

#### 6. 调用带有默认参数的函数时，不能为默认值参数传递任何值，必须使用函数定义时设置的默认值。（判断对错）
错误。在调用有默认值的函数时，如果不给默认值参数传递任何值，则使用设定的默认值；否则，使用传入的值作为默认参数的值。

#### 7. 在Python程序中，局部变量会隐藏同名的全局变量么？请编写代码进行验证。

```python
global a
a = 100


def testGlobal():
    a = 3
    print(a)
    return


if __name__ == '__main__':
    testGlobal()  # 全局变量被局部变量覆盖
    print(a)      # 局部变量a被销毁，全局变量a显示值

    '''
    输出：
        3
        100
    '''
```

#### 8. lambda 表达式只能用来创建匿名函数，不能为这样的函数起名字（判断对错）。
错。

#### 9. 编写函数，可以接收任意多个整数并输出其中的最大值和所有整数之和。
```python
def SumAndMax(*p):
    print(max(p))
    print(sum(p))


if __name__ == "__main__":
    SumAndMax(0, 9, 2, 4, 523, 23)
```

#### 10. 编写函数，模拟内置函数sum()。
```python
'''模拟sum:
描述
sum() 方法对序列进行求和计算。

语法
以下是 sum() 方法的语法:

sum(iterable[, start])
参数
iterable -- 可迭代对象，如：列表、元组、集合。
start -- 指定相加的参数，如果没有设置这个值，默认为0。'''


def my_Sum(p, a=0):
    try:
        from collections.abc import Iterator
        s = 0
        if a != 0 and isinstance(a,int):
            s += a
        elif not isinstance(a,int):
            print('add data type error.')
            return
        if isinstance(iter(p), Iterator):  # 判断传入的参数是一个迭代器类型的参数
            for i in p:
                if isinstance(i, int):     # 判断传入的迭代器中的每个成员都是int类型
                    s += i
                else:
                    print('list member type error.')    # 对于非int类型成员，进行异常处理
                    return 
            print(s)
        return
    except TypeError:
        print('TypeError： object is not iterable.') # 对于非迭代器成员进行异常处理


if __name__ == '__main__':
    l = [1, 2, 3, 4]
    li = (1, 2, 3, 4)
    # 对列表求和测试
    my_Sum(l)
    my_Sum(l, -5)
    # 对元组求和测试
    my_Sum(li)
    # 对range迭代器求和测试
    my_Sum(range(0, 6))
    # 对类型异常进行测试
    my_Sum(0)
    my_Sum([1,2,'a'])
    my_Sum([1,2,3],'a')
```

#### 11.包含______语句的函数可以用来创建生成器。
field

#### 12. 编写函数，模拟内置函数sorted。


### 第六章 习题
#### 1.继承6.5节例6-2中的Person类生成Student类，编写新的函数用来设置学生专业，然后生成该类对象并显示信息。
```python
''' 6.2 在派生类中调用基类方法
    首先设计Person类，然后以Person为基类派生Teacher类，分别创建Person类和Teacher类的对象，
    并在派生类对象中调用基类方法。'''


class Person:
    def __init__(self, name='', age=20, sex='man'):
        self.setName(name)
        self.setAge(age)
        self.setSex(sex)

    def setName(self, name):
        if not isinstance(name, str):
            print('name must be string.')
            return
        self.__name = name

    def setAge(self, age):
        if not isinstance(age, int):
            print('name must be integer.')
            return
        self.__age = age

    def setSex(self, sex):
        if sex != 'man' and sex != 'woman':
            print('sex must be "man" or "woman"')
            return
        self.__sex = sex

    def show(self):
        print('Name', self.__name)
        print('Age', self.__age)
        print('Sex', self.__sex)


class Teacher(Person):  # 派生类
    def __init__(self, name="", age=30, sex='man', department='Computer'):
        super(Teacher, self).__init__(name, age, sex)
        # #or, use another method like below:
        # Person.__init__(self, name, age, sex)
        self.setDepartment(department)

    def setDepartment(self, department):
        if not isinstance(department, str):
            print('department must be a string.')
            return
        self.__department = department

    def show(self):
        # Person.show()
        super(Teacher, self).show()
        print('Department:', self.__department)


class Student(Person):
    def __init__(self, name="", age=18, sex='man', major='Computer Science'):
        super(Student, self).__init__(name, age, sex)
        self.setMajor(major)

    def setMajor(self, major):
        if not isinstance(major, str):
            print('Major must be a string.')
            return
        self.__major = major

    def show(self):
        Person.show(self)
        print('Major', self.__major)


if __name__ == '__main__':
    w = Student()
    w.show()
    w = Student('wendy', 20, 'woman', 'Data Analyse')
    w.show()
''' 输出结果
Name 
Age 18
Sex man
Major Computer Science
Name wendy
Age 20
Sex woman
Major Data Analyse
'''
```

#### 2. 设计一个三位向量类，并实现向量的加法、减法以及向量和标量的乘法和除法运算。
```python
''' 2. 设计一个三位向量类，并实现向量的加法、减法以及向量和标量的乘法和除法运算。'''


class Vector(object):
    __vector = []   # 创建类的私有成员

    def __init__(self, *args):  # 初始化三位向量
        if not args:    # 判断参数是否为空
            self.__vector = []
        elif len(args) > 3: # 向量成员超过3个，不能创建
            print('the member in the victor is bigger than three.')
            return
        else:
            for i in args:  # 判断向量成员，数据类型
                if not self.__IsNumber(i):
                    print('member is not a number')
                    return
                self.__vector = list(args)

    def __IsNumber(self, n):    # 辅助函数，判断数据n是否是一个整型或者浮点数
        if not isinstance(n, int) and not isinstance(n, float):
            return False
        return True

    @property   # 设置get属性
    def vector(self):
        return self.__vector

    @vector.setter  # 设置set属性
    def vector(self, v):
        if not isinstance(v, Vector):
            print('Only receive Vector.')
            return
        self.__vector = v.__vector

    def show(self): # 显示向量数据
        print(self.__vector)

    def __add__(self,v):
        if not isinstance(v,Vector):    # v如果不是Vector类型不提供计算
            print('v is not Vector.')
            return
        elif isinstance(v,Vector):  # v是Vector类型，进行加法计算
            a = Vector()
            for x,y in zip(self.__vector,v.__vector):
                a.__vector.append(x + y)
            return a.__vector
        else:
            print('Not supported')

    def __sub__(self,v):
        if not isinstance(v,Vector):    # v如果不是Vector类型不提供计算
            print('v is not Vector.')
            return
        elif isinstance(v,Vector):  # v是Vector类型，进行减法计算
            a = Vector()
            for x,y in zip(self.__vector,v.__vector):
                a.__vector.append(x - y)
            return a.__vector
        else:
            print('Not supported')

    def __mul__(self,v):
        if isinstance(v,int):   # 标量乘法
            a = Vector()
            for x in self.__vector:
                a.__vector.append(x * v)
            return a.__vector
        elif isinstance(v,Vector):  # 向量乘法
            a = Vector()
            for x,y in zip(self.__vector,v.__vector):
                a.__vector.append(x * y)
            return sum(a.__vector)
        else:
            print('Not supported')

    def __truediv__(self, v):
            if isinstance(v, int):  # 标量除法
                a = Vector()
                for x in self.__vector:
                    a.__vector.append(x / v)
                return a.__vector
            elif isinstance(v, Vector):  # 向量乘法
                a = Vector()
                for x, y in zip(self.__vector, v.__vector):
                    a.__vector.append(x / y)
                return a.__vector
            else:
                print('Not supported')

if __name__ == '__main__':
    v1 = Vector(1, 2, 3)
    v1.show()
    # [1, 2, 3]
    v2 = Vector(4,5,6)
    v2.show()
    # [4, 5, 6]
    # 向量加
    print(v1+v2)
    # [5, 7, 9]
    # 向量减
    print(v1-v2)
    # [-3, -3, -3]
    # 向量乘
    print(v1 * v2)
    # 32
    # 向量标量乘法
    print(v1 * 3)
    # [3, 6, 9]
    # 向量除法
    print(v1 / v2)
    # [0.25, 0.4, 0.5]
    # 向量标量除法
    print(v1 / 2)
    # [0.5, 1.0, 1.5]
```

#### 3. 面向对象程序设计的三要素分别为_______，_______ 和 ________。
封装，继承和多态

#### 4. 简单解释Python中以下划线开头的变量名的特点。
- `_xxx`: 这样的对象叫做保护成员，不能用"from module import *"导入，只有类对象和子类对象能访问这些成员。
- `__xxx__`: 系统定义的特殊成员。
- `__xxx`: 类中的私有成员，只有类对象自己能访问，子类对象也不能访问到这个成员，但在对象外部可以通过“对象名._类名__私有成员名”这样的特殊方式类访问。

#### 5. 与运算符“**”对于的特殊方法名为_______,与运算符“//”对于的特殊方法名为_______。
`__pow__`; `__floordiv__`

#### 6. 假设a为类A的对象且包含一个私有数据成员“__value”， 那么在类的外部通过对象a直接将其私有数据成员“__value”的值设置为3的语句可以写作________。
a._A__value = 3

测试代码：
```python
>> class A:
	__value = 5
	def show(self):
		print(self.__value)

		
>>> a = A()
>>> a.show()
5
>>> a._A__value = 3
>>> a.show()
3
```
