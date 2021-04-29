## Python 实战
### 1.Python 统计单词
#### 把文档读入成str类
读文件:

要以读文件的模式打开一个文件对象，使用Python内置的open()函数，传入文件名和标示符：

```python
>>> f = open('E:\python\python\test.txt', 'r')
```

标示符'r'表示读，这样，我们就成功地打开了一个文件。

如果文件不存在，open()函数就会抛出一个IOError的错误，并且给出错误码和详细的信息告诉你文件不存在：

```python
f=open('E:\python\python\notfound.txt', 'r')
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
FileNotFoundError: [Errno 2] No such file or directory: 'E:\python\python\notfound.txt'
```

如果文件打开成功，接下来，调用read()方法可以一次读取文件的全部内容，Python把内容读到内存，用一个str对象表示：

```python
>>> f.read()
'Hello, python!'
```

最后一步是调用close()方法关闭文件。文件使用完毕后必须关闭，因为文件对象会占用操作系统的资源，并且操作系统同一时间能打开的文件数量也是有限的：

```python
>>> f.close()
```

由于文件读写时都有可能产生IOError，一旦出错，后面的f.close()就不会调用。所以，为了保证无论是否出错都能正确地关闭文件，我们可以使用try ... finally来实现：

```python
try:
    f = open('/path/', 'r')
    print(f.read())
finally:
    if f:
        f.close()
```

每次都这么写实在太繁琐，所以，Python引入了with语句来自动帮我们调用close()方法：

```python
with open('/path/to/file', 'r') as f:
    print(f.read())
```

这和前面的try ... finally是一样的，但是代码更佳简洁，并且不必调用f.close()方法。

 

调用read()会一次性读取文件的全部内容，如果文件有20G，内存就爆了，所以，要保险起见，可以反复调用read(size)方法，每次最多读取size个字节的内容。另外，调用readline()可以每次读取一行内容，调用readlines()一次读取所有内容并按行返回list。因此，要根据需要决定怎么调用。

如果文件很小，read()一次性读取最方便；如果不能确定文件大小，反复调用read(size)比较保险；如果是配置文件，调用readlines()最方便：
```python
for line in f.readlines():
    print(line.strip()) # 把末尾的'\n'删掉
```

### 2.基于值得内存管理方式
#### 整数
```python
# 对于不在-5~256内的整数，不会做数据的缓存。因此，对于不同变量赋相同值变量地址不同。反之相同。
>>> a = -6
>>> b = -6
>>> id(a)
1967091588592
>>> id(b)
1967091588624
>>> x = 10
>>> y = 10
>>> id(x)
1967073552976
>>> id(y)
1967073552976
```
#### 实数
- Python不会对实数进行换成
- 交互模式下同值不同名的变量不共用同一个内存空间

### 3.map()
#### 描述
map() 会根据提供的函数对指定序列做映射。

第一个参数 function 以参数序列中的每一个元素调用 function 函数，返回包含每次 function 函数返回值的新列表。

#### 语法
map() 函数语法：

map(function, iterable, ...)

#### 参数
function -- 函数
iterable -- 一个或多个序列

#### 返回值
Python 2.x 返回列表。

Python 3.x 返回迭代器。

#### 实例
```python
>>> def square(x) :         # 计算平方数
...     return x ** 2
...
>>> map(square, [1,2,3,4,5])    # 计算列表各个元素的平方
<map object at 0x100d3d550>     # 返回迭代器
>>> list(map(square, [1,2,3,4,5]))   # 使用 list() 转换为列表
[1, 4, 9, 16, 25]
>>> list(map(lambda x: x ** 2, [1, 2, 3, 4, 5]))   # 使用 lambda 匿名函数
[1, 4, 9, 16, 25]
>>>
```

### 4.polygon
#### TurtleWorld 模块
TurtleWorld中提供了几个函数来指挥乌龟的运动：
- fd : 前进 (forward)
  - fd(turtle,step(步长))
- bk : 后退 (backward)
- lt : 左转 (left turn)
  - lt(turtle,angle(转的角度，默认为90°))
- rt : 右转 (right turn)

每只乌龟都拿着一支笔，笔可以朝上或朝下：
- pu : 笔朝上 (pen up)
- pd : 笔朝下 (pen down)
**笔朝上，不会绘制出轨迹（用于在到达指定位置前不绘制出轨迹）；笔朝下，会绘制出走过的轨迹**。
#### 前期准备
```python
```python
"""This module contains code from
Think Python by Allen B. Downey
http://thinkpython.com

Copyright 2012 Allen B. Downey
License: GNU GPLv3 http://www.gnu.org/licenses/gpl.html

"""
import math
# 异常处理：判断是否导入库成功
try:
    # see if Swampy is installed as a package
    from swampy.TurtleWorld import *
except ImportError:
    # otherwise see if the modules are on the PYTHONPATH
    from TurtleWorld import *
 ```

#### 画一个正方形

```python 
#  写一个函数square ，接受一个形参 t，用来表示一只乌龟,接受length,表示步长。
# 用来表示一只乌龟利用乌龟来画一个正方形。
#  写一个函数调用传入bob作为实参来调,用 square函数，并再运行一遍程序。
def square(t, length):
    t = Turtle()
    for i in range(4):
        fd(t, length)  # 参数2：步长
        lt(t)  # 参数2：angle 旋转角度，默认为90°

#### 多边形和折线
```python
def polyline(t, n, length, angle):
    """Draws n line segments.

    t: Turtle object
    n: number of line segments
    length: length of each segment
    angle: degrees between segments
    """
    for i in range(n):      # 画n条边，长度为length，每次向左转angle度
        fd(t, length)
        lt(t, angle)


def polygon(t, n, length):
    """Draws a polygon with n sides.

    t: Turtle
    n: number of sides
    length: length of each side.
    """
    angle = 360.0 / n       # 利用360 /n 限定角度，画一个正n边形
    polyline(t, n, length, angle)
```
#### 弧线和圆
```python
def arc(t, r, angle):
    """Draws an arc with the given radius and angle.

    t: Turtle
    r: radius
    angle: angle subtended by the arc, in degrees
    """
    arc_length = 2 * math.pi * r * abs(angle) / 360  # 计算弧度的长度
    n = int(arc_length / 4) + 1     # 把弧度分成n份，即把画弧转化为画n条边
    step_length = arc_length / n    # 计算步长
    step_angle = float(angle) / n   # 计算每次转过的角度

    # making a slight left turn before starting reduces
    # the error caused by the linear approximation of the arc
    lt(t, step_angle / 2)   # 每次向左转转过角度的一半
    polyline(t, n, step_length, step_angle) # 做折线
    rt(t, step_angle / 2)


def circle(t, r):
    """Draws a circle with the given radius.

    t: Turtle
    r: radius
    """
    arc(t, r, 360)  # 画圆是画弧的特殊情况，直接调用即可
```


#### 创意画：
```python
# 画一片花瓣
def petal(t, r, angle):
    # t: turtle;
    # r: radius;
    # angle: related to the thick of a petal
    for i in range(2):          # 画一个往返的弧线，构成一篇花瓣
        arc(t, r, angle)        # 调用arc依照角度画弧的函数
        lt(t, 180 - angle)      # 向左转向180 -angle = 返回


# 画一朵花
def flower(t, n, r, angle):
    """ t: turtle
    n: 花瓣数
    r: radius
    angle:旋转的角度
    """
    for i in range(n):
        petal(t, r, angle)
        lt(t, 360.0 / n)    # n 片花瓣旋转一周，偏转角度为360/n


def move(t, length):        # 利用pu(),pd() 不转向移动turtle的位置
    pu(t)
    fd(t, length)
    pd(t)


def back(t, r, angle):
    pu(t)
    arc_length = 2 * math.pi * r * abs(angle) / 360
    n = int(arc_length / 4) + 1
    step_length = arc_length / n
    step_angle = float(angle) / n
    fd(t, step_length)
    pd(t)


if __name__ == '__main__':
    # 创建世界和乌龟，并加速bob运动的速度
    world = TurtleWorld()
    bob = Turtle()
    bob.delay = 0.001           # 设置乌龟走过路程间隔的速度（提速）
    # 第一朵六片花
    flower(bob, 6, 96, 57)

    # 第二朵花
    move(bob, 200)              # 移动一段位置，避免和第一朵花重叠
    flower(bob, 10, 90, 80)     # 画第二朵花
    rt(bob, 90)                 # 转向，画花茎
    fd(bob, 300)
    lt(bob, 90)                 # 转向，画第一片叶子
    petal(bob, 100, 80)
    lt(bob, 90)                 # 转向，画第二片叶子
    petal(bob, 100, 80)

    wait_for_user()
```

### 5.random库

### 6.numpy库

### 7.二维数组的创建
- 直接创建法
- 列表生成
- numpy创建

```python
    # 直接
    test = [0, 0, 0], [0, 0, 0], [0, 0, 0]]
    # 列表
    test = [[0] * n for _ in range(m)]
    # numpy
    import numpy as np
    test = np.zeros((m, n), dtype=np.int)
```

### 8. turtle 库
Turtle库是Python语言中一个很流行的绘制图像的函数库，想象一个小乌龟，在一个横轴为x、纵轴为y的坐标系原点，(0,0)位置开始，它根据一组函数指令的控制，在这个平面坐标系中移动，从而在它爬行的路径上绘制了图形。

#### turtle绘图的基础知识：
#### 2.1 画布(canvas)
 画布就是turtle为我们展开用于绘图区域，我们可以设置它的大小和初始位置。

- 设置画布大小

`turtle.screensize(canvwidth=None, canvheight=None, bg=None)`
- 参数
  - 画布的宽(单位像素)
  - 高
  - 背景颜色。

##### 案例
```python
turtle.screensize(800,600, "green")

turtle.screensize() #返回默认大小(400, 300)
```

`turtle.setup(width=0.5, height=0.75, startx=None, starty=None)`
- 参数：
  - width, height: 输入宽和高
    - 为整数时, 表示像素; 
    - 为小数时, 表示占据电脑屏幕的比例
  - (startx, starty): 这一坐标表示矩形窗口左上角顶点的位置, 如果为空,则窗口位于屏幕中心。

##### 案例
  +
    ```python
    turtle.setup(width=0.6,height=0.6)

    turtle.setup(width=800,height=800, startx=100, starty=100)
    ```
#### 2.2 画笔的属性

        画笔(画笔的属性，颜色、画线的宽度等)

        1) turtle.pensize()：设置画笔的宽度；

        2) turtle.pencolor()：没有参数传入，返回当前画笔颜色，传入参数设置画笔颜色，可以是字符串如"green", "red",也可以是RGB 3元组。

        3) turtle.speed(speed)：设置画笔移动速度，画笔绘制的速度范围[0,10]整数，数字越大越快。

#### 2.3 绘图命令

操纵海龟绘图有着许多的命令，这些命令可以划分为3种：
 - 运动命令
 - 画笔控制命令
 - 全局控制命令。

**(1)    画笔运动命令**

|命令|说明|
|--|--|
|turtle.forward(distance)|向当前画笔方向移动distance像素长度
|turtle.backward(distance) |向当前画笔相反方向移动distance像素长度
|turtle.right(degree) |顺时针移动degree°
|turtle.left(degree) |逆时针移动degree°
|turtle.pendown() |移动时绘制图形，缺省时也为绘制
|turtle.goto(x,y) |将画笔移动到坐标为x,y的位置
|turtle.penup() |提起笔移动，不绘制图形，用于另起一个地方绘制
|turtle.circle()| 画圆，半径为正(负)，表示圆心在画笔的左边(右边)画圆
|setx( )| 将当前x轴移动到指定位置
|sety( )| 将当前y轴移动到指定位置
|setheading(angle)| 设置当前朝向为angle角度
|home()| 设置当前画笔位置为原点，朝向东。
|dot(r)| 绘制一个指定直径和颜色的圆点

 

**(2)     画笔控制命令**

|命令|说明
|--|--
|turtle.fillcolor(colorstring) |绘制图形的填充颜色
|turtle.color(color1, color2) |同时设置pencolor=color1, fillcolor=color2
|turtle.filling() |返回当前是否在填充状态
|turtle.begin_fill() |准备开始填充图形
|turtle.end_fill() |填充完成
|turtle.hideturtle() |隐藏画笔的turtle形状
|turtle.showturtle() |显示画笔的turtle形状

 

**(3)    全局控制命令**
|命令|说明
|--|--
|turtle.clear()|清空turtle窗口，但是turtle的位置和状态不会改变
|turtle.reset()|清空窗口，重置turtle状态为起始状态
|turtle.undo()|撤销上一个turtle动作
|turtle.isvisible()|返回当前turtle是否可见
|stamp()|复制当前图形
|turtle.write(s [,font=("font-name",font_size,"font_type")])|写文本，s为文本内容，font是字体的参数，分别为字体名称，大小和类型；font为可选项，font参数也是可选项

 

**(4)    其他命令**

|命令|说明
|--|--
|turtle.mainloop()或turtle.done()|启动事件循环 -调用Tkinter的mainloop函数。必须是乌龟图形程序中的最后一个语句。
|turtle.mode(mode=None)|设置乌龟模式（“standard”，“logo”或“world”）并执行重置。如果没有给出模式，则返回当前模式。模式初始龟标题正角度
|standard|向右（东）逆时针
|logo|向上（北）顺时针
|turtle.delay(delay=None)|设置或返回以毫秒为单位的绘图延迟。
|turtle.begin_poly()|开始记录多边形的顶点。当前的乌龟位置是多边形的第一个顶点。
|turtle.end_poly()|停止记录多边形的顶点。当前的乌龟位置是多边形的最后一个顶点。将与第一个顶点相连。
|turtle.get_poly()|返回最后记录的多边形。

 

#### 3. 命令详解

##### 3.1 turtle.circle(radius, extent=None, steps=None)

- 描述：以给定半径画圆

- 参数：
  - radius(半径)：半径为正(负)，表示圆心在画笔的左边(右边)画圆；
  - extent(弧度) (optional)；
  - steps (optional) (做半径为radius的圆的内切正多边形，多边形边数为steps)。

举例:
+ ```python
    circle(50) # 整圆;

    circle(50,steps=3) # 三角形;

    circle(120, 180) # 半圆
    ```

### 9.Koch_snowflake 科赫雪花

#### 定义
设想一个边长为1的等边三角形，取每边中间的三分之一，接上去一个形状完全相似的但边长为其三分之一的三角形，结果是一个六角形。现在取六角形的每个边做同样的变换，即在中间三分之一接上更小的三角形，以此重复，直至无穷。外界的变得原来越细微曲折，形状接近理想化的雪花。它的名字叫科克曲线

#### 实现原理
先定义单边的科赫曲线，在0阶的时候科赫曲线时一条直线；当阶数大于0的时候，每条边增加一个折，即一条边变为3条边。可以利用递归算法实现。
![20180823182059779.png](https://i.loli.net/2021/04/22/IZN6epPwm7FLHX3.png)
#### 成果
可以实现自定义阶数的科赫雪花。以下仅展示0~4阶的科赫雪花图样。(N表示阶数)
#### 代码样例
+ 
  ```python
    # 科赫雪花
    import turtle


    def kehe(len, n):
        if n == 0:
            turtle.fd(len)  # 0阶时，走直线，长度为len
        else:
            for i in [0, 60, -120, 60]:  # 依次向左转指定角度调用n-1阶的kehe函数
                turtle.left(i)
                kehe(len / 3, n - 1)


    def Koch(level):
        turtle.speed(0)  # 设置乌龟的速度
        turtle.penup()  # 拿起画笔
        turtle.goto(-200, 100)  # 设置初始点（-100，100）
        turtle.pensize(2)  # 设置笔的粗细
        turtle.color('blue')  # 设置笔的颜色为蓝色
        turtle.pendown()  # 放下画笔

        for i in range(3):
            kehe(lenth, level)  # 转向画3次
            turtle.right(du)

        turtle.hideturtle()  # 隐藏乌龟（即箭头）
        turtle.done()


    if __name__ == '__main__':
        lenth = 500
        du = 120
        level = (input('please enter a number:'))
        level = int(level)
        Koch(level)
    ```

### 10. 可缩减单词
参照验证实验1中，反序词实现的例示代码，设计Python 程序找出words.txt 中最长的“可缩减单词”（所谓“可缩减单词”是指：每次删除单词的一个字母，剩下的字母依序排列仍然是一个单词，直至单字母单词’a’或者‘i'）。
**提示：**
> 可缩减单词例示：sprite —〉spite —〉spit—〉pit—〉it—〉i
> 如果递归求解，可以引入单词空字符串’’作为基准。
> 一个单词的子单词不是可缩减的单词，则该单词也不是可缩减单词。因此，记录已经查找到的可缩减单词可以提速整个问题的求解。

#### 技术重点
-	数据结构的选择
    +  优先考虑字典/集合的存储方式，由于集合不能涵盖两个相同的元素。故选择字典。
    + 利用列表传入从文件中读取的每个单词
-	算法的构思：
    + 参考了同学基于树的深度搜索的思想，探索实践完成了本题的代码。
-	对于n位的单词，如何存储随机减少一位后产生的n-1位的单词
    + 想法1 利用string.replace()对长度内的每个位置的字母进行遍历，并替换成“”。
	在调试中，发现问题。由于python基于内存的管理方式，replace会将字符串中出现的所有相同的字母都替换成“”，导致结果异常。
	例：apple 删除第2位的’p’会得到’ale’
    + 想法2 利用切片分割字符串，再拼接。每次取[:i]+[i+1:]的字符，i在字符串长度内遍历。注意，切片的范围是开闭区间。经过测试，该方法可以避免上述问题的产生，故使用切片方法。

#### 实现原理
1）初始化
	从word.txt中读取文件生成一个t 列表，在使用t列表生成一个对应的字典t1。t1中农的每个value值初始化为0。

2）getwords(w)函数
	参数：w是传入的单词。
	返回值：t1.get(w,-1) 在字典中查找单词w，找到返回对应的value值，否则返回-1。

i. 判断传入的单词的长度是否为1，为1则在字典中将它的value设置为1，返回t1.get(w,-1)；

ii. 对于单词长度大于2的情况,先判断是否能在字典中找到它，若找得到，则生成它对应的切片。

iii. 对于切片中的每个元素，重复i,ii两步
。
iv. 判断元素在字典中的值是否大于0，即是否存在从原始n位单词到最后一个字母均为单词的情况。若如此，则把它的value值置为：它的字符串长度，把它上一级的值也置为对应的字符串长度。

v. 排序输出结果
    利用max函数和lambda()函数输出最大值的结果。

#### 代码
```python
"""可缩减单词："""

import time


def getwords(w):
    """
    :param w: 单词（字符串）
    :return: t1.get(w,-1) 在字典中查找单词w，找到返回对应的value值，否则返回-1.
    """
    if len(w) == 1:  # 只有单词只有一个字母时
        t1[w] = 1
    elif t1.get(w, -1) == 0 and len(w) > 0:  # 单词大于一个字母时
        # minus = [w.replace(w[i], "") for i in range(len(w))]  # 把每一个减少一位的单词存入数组再查找 # 对于apple中，删除p会把两个p同时删除。
        minus = [w[:i] + w[i + 1:] for i in range(len(w))]  # 把每一个减少一位的单词存入数组再查找
        # print(w, '的子单词：', minus)

        # 对于每一个子单词，判断子单词在字典中，继续查找
        for k in minus:
            getwords(k)
            if t1.get(k, -1) > 0:
                t1[k] = len(k)
                t1[w] = len(w)
    return t1.get(w, -1)


with open('words.txt') as f:
    # dict1 = {x.strip() for x in f}
    # t = ['apple', 'split', 'spit', 'pit', 'it','abc','ab','ap','sit']
    # t1 = {x: 0 for x in t}

    start = time.time()
    t = [x.strip() for x in f]
    t1 = {x.strip(): 0 for x in t}
    for i in t:
        getwords(i)
    # print('change dict:', t1)
    for key in max(t1.items(), key=lambda x: x[1]):
        print(key)
    print('Time:', time.time() - start)

'''complecting
11
Time: 1.9192843437194824'''
```


### 11.zip() 函数
#### 描述
- zip() 函数用于将可迭代的对象作为参数，将对象中对应的元素打包成一个个元组，然后返回由这些元组组成的列表。

- 如果各个迭代器的元素个数不一致，则返回列表长度与最短的对象相同，利用 * 号操作符，可以将元组解压为列表。

- zip 方法在 Python 2 和 Python 3 中的不同：在 Python 3.x 中为了减少内存，zip() 返回的是一个对象。如需展示列表，需手动 list() 转换。

- 如果需要了解 Pyhton3 的应用，可以参考 Python3 zip()。

#### 语法
- zip([iterable, ...])
#### 参数说明：
- iterabl -- 一个或多个迭代器;
- 返回值
- 返回元组列表。

#### 实例
以下实例展示了 zip 的使用方法：
```python
>>>a = [1,2,3]
>>> b = [4,5,6]
>>> c = [4,5,6,7,8]
>>> zipped = zip(a,b)     # 打包为元组的列表
[(1, 4), (2, 5), (3, 6)]
>>> zip(a,c)              # 元素个数与最短的列表一致
[(1, 4), (2, 5), (3, 6)]
>>> zip(*zipped)          # 与 zip 相反，*zipped 可理解为解压，返回二维矩阵式
[(1, 2, 3), (4, 5, 6)]
```