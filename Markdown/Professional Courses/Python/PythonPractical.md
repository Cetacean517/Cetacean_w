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
