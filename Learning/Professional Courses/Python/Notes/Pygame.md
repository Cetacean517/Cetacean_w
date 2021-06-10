# Pygame
## 1. Pygame最小开发框架
### 引入pygame和sys
- sys是Python的标准库
- sys提供Python运行时环境变量的操控
- sys.exit()用于退出：结束游戏并退出

### 初始化init()及设置
对Pygame内部各功能模块进行初始化创建及变量设置，默认调用

```python
pygame.init()
screen = pygame.display.set_mode((600,400))
pygame.display.set_caption("Python游戏之旅")
```
### 获取事件并逐类响应
### 刷新屏幕

## 2.屏幕绘制机制
### 基础内容
- Python.display()控制屏幕
- pygame中只能控制一个屏幕。要显示多个，只能关闭一个之后，重新打开新的屏幕。
- 屏幕依靠笛卡尔坐标系控制方位，左上角为(0,0)，向右x轴，向下y轴。
- 屏幕长宽依靠像素设定。

### 屏幕控制相关基础函数
- **屏幕尺寸和模式**
  - pygame.display.set_mode() 设置相关屏幕模式
  - pygame.display.info() 生成屏幕相关信息
- **窗口标题和图标**
  - pygame.display.set_caption() 设置标题信息
  - pygame.display.set_icon() 设置图标信息
  - pygame.display.get_caption() 获得图标
- **窗口感知和刷新**
  - pygame.display.get_active()
  - pygame.display.flip()
  - pygame.display.update()

### Pygame屏幕尺寸和模式设置
- pygame.display.set_mode(r=(0,0), flags = 0) 设置相关屏幕模式
  - r 是游戏屏幕的分辨率，采用(width,height)方式输入
  - flags用来控制显示类型，可用|组合使用，常用显示标签如下：
    - pygame.RESIZABLE  窗口大小可调
    - pygame.NOFRAME    窗口没有边界显示
    - pygame.FULLSCREEN    窗口全屏显示
  
**注意： 每种显示方式要配合相应的处理机制**
- 对扩张显示界面的刷新
- 对扩张/缩小显示界面的响应


- pygame.display.info() 生成屏幕相关信息
  - 产生一个显示信息对象VideoInfo，表达当前屏幕的参数信息
  - 在.set_mode()之前调用，则显示当前系统显示参数信息。
  - 参数很多，其中有两个十分重要，如下：
    - current_w:    当前显示模式或窗口的像素宽度
    - current_h:    当前显示模式或窗口的像素高度

- pygame.VEDIORESIZE
  - 这是一种窗口大小更改的事件
  - 事件发生后，返回event.size元组，包含新窗口的宽度和高度
  - `.size[0]`宽度，也可以用event.w
  - `.size[1]`宽度，也可以用event.h
  - 返回参数仅在事件发生时有用

### Pygame窗口标题和图标设置
- pygame.display.set_caption(title, icontitle=None) 设置标题信息
  - title设置窗口的标题内容
  - icontitle设置图标话后的小标题。
  - 小标题可选，部分系统没有，一般不设置。
- pygame.display.get_caption() 获得图标
  - 返回当前设置窗口的标题即小标题内容
  - 返回 结构为(title, icontitle)
  - 该函数与游戏交互逻辑配合，可以根据游戏情节修改标题内容
- pygame.display.set_icon(surface) 设置图标信息
  - 设置窗口的图标效果
    - 1. 要利用image.load读入图片
    - 2. 利用set_icon(icon)设置图标
  - 图标是一个Surface对象(当被导入之后以Surface对象表示)
```python
icon = pygame.image.load("ggirl.jpg")
pygame.display.set_icon(icon)
```

### Pygame窗口感知和刷新设置
- pygame.display.get_active()
  - 当窗口在系统中显示为界面（即屏幕绘制/非图表化）时返回True，否则返回False（即图表化/最小化）。
  - 该函数可以用来判断是否游戏窗口被最小化
  - 进一步，判断后可以暂停游戏，改变响应模式等。
  - pygame.display.flip()
    - 把整个屏幕重新绘制
  - pygame.display.update()
    - 重新绘制变化的部分，速度比flip()快
    - 一般情况中，update()使用情况较多
```python
    if pygame.display.get_active():
        ballrect = ballrect.move(speed[0], speed[1])
```

## 3. 事件处理机制
### Pygame的事件处理的 简介
#### 定义
- Pygame中存在一个事件队列存放所有发生的事件。
- 利用事件处理程序，对于接受的事件作出相应的响应。一般FIFO。
- pygame.event.EventType
  - Pygame的事件本质是一种封装后的数据域类型(对象)
  - 是Pygame的一个类，表示事件类型
  - 事件类型只有属性，没有方法
  - 用户可以自定义新的事件类型
  - 
#### 事件类型及属性
- 系统
  - QUIT:   none
  - ACTIVEEVENT:    gain,state
- 键盘
  - KEYDOWN:    unicode,key,mod
  - KEYUP:      key,mod
- 鼠标
  - MOUSEMOTION:    pos,rel,buttons
  - MOUSEBUTTONUP:  pos,button
  - MOUSEBUTTONDOWN:    pos,button
- 游戏杆
  - 略
- 窗口
  - VIDEORESIZE:    size,w,h
  - VIDEOEXPOSE:    none
- 用户定义
  - USEREVENT:  code
  - 
#### 实例：
- 键盘落下事件及属性pygame.event.KEYDOWN
  - event.unicode: 按键的Unicode编码
  - event.key：按键的值
  - event.mod：按键的模式
  - 
#### 处理事件
- pygame.event.get()
- pygame.event.poll()
- pygame.event.clear()
- 
#### 操作事件队列
- pygame.event.set_blocked()
- pygame.event.get_blocked()
- pygame.event.set_allowed()

#### 生成事件
- pygame.event.set()
- pygame.event.event()

### 键盘事件及类型的使用
- 键盘按下事件：pygame.event.KEYDOWN
  - event.unicode: 按键的unicode编码(与平台有关，不建议使用)
  - event.key：按键的常量名称
  - event.mod：按键修饰符的组合值，修饰符的按位或运算

```python
event.mod = KMOD_ALT | KMOD_SHIFT
```

- 键盘释放事件：pygame.event.KEYUP
  - 按下后释放，不操作则不会触发
  - event.key：按键的常量名称
  - event.mod：按键修饰符的组合值

```python
# Unit PYG04: Pygame Event Print
import pygame
import sys

pygame.init()
screen = pygame.display.set_mode((600, 400))
pygame.display.set_caption("Pygame事件处理")

while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            sys.exit()
        elif event.type == pygame.KEYDOWN:
            # 由于不是每一个系统都有unicode编码，因此进行判断，为空时不打印。
            if event.unicode == '':
                print("[KEDYDOWN:]", "#", event.key, event.mod)
            else:
                print("[KEYDOWN]:", event.unicode, event.key, event.mod)

    pygame.display.update()
```

### 鼠标事件及类型的使用
- pygame.event.MOUSEMOTION  鼠标移动事件
  - event.pos 鼠标当前坐标值(x,y)，相对于窗口左上角
  - event.rel 鼠标相对距离(X,Y)，相对于上次事件
  - event.buttons 鼠标按钮状态(a,b,c),对应于鼠标的三个键
    - 鼠标移动时，这三个键处于按下状态，对应的位置值为1，反之则为0.
- pygame.event.MOUSEBUTTIONUP  鼠标释放事件
  - event.pos 鼠标当前坐标值(x,y)，相对于窗口左上角
  - event button 鼠标按下编号n,取值0/1/2，分别对应三个键。左键为1，右键为3，如果带滑轮，则返回任意一个整数值。设备相关
- pygame.event.MOUSEBUTTONDOWN  鼠标按下事件
  - event.pos 鼠标当前坐标值(x,y)，相对于窗口左上角
  - event button 鼠标按下编号n,取值0/1/2，分别对应三个键。左键为1，右键为3，如果带滑轮，则返回任意一个整数值。设备相关

##### 壁球小游戏鼠标型
- 需求
  - 使用鼠标左键摆放壁球，按键按下时，壁球停止移动
  - 按键按下并且移动时，壁球跟随鼠标移动。
  - 当释放按键时，壁球继续移动。

### Pygame事件处理函数
- pygame.event.get()
  - 从事件队列中获得事件列表，即获得所有被队列的事件
  - 可以利用for循环读入事件列表
```python
for event in pygame.event.get():
  if event.type == pygame.QUIT:
    sys.exit()
```
  - 增加参数，获得某类或某些类事件
  - pygame.event.get(type)
  - pygame.event.get(typelist)

- pygame.event.poll()
  - 从事件队列中获得一个事件

```python
While True:
  event = pygame.event.poll()
```

  - 事件获取将从事件队列中删除
  - 如果事件队列为空，则返回event.NOEVENT

- pygame.event.clear()
  - 从事件队列中删除事件，默认删除所有事件
  - 该函数与pygame.event.get()类似，区别仅是不对事件进行处理
  - 可以增加参数，删除某类或某些类事件：
    - pygame.event.clear(type)
    - pygame.event.clear(typelist)

#### Pygame事件队列
- 事件队列同时仅能存储128个事件。当队列满时，更多事件将被丢弃。
- 提供了3个管理事件队列的函数，设置事件队列能够缓存事件类型
  - pygame.event.set_blocked(type or typelist)
    - 控制哪些类型事件不允许被保存到事件队列中
  - pygame.event.set_allowed(type or typelist)
    - 控制哪些类型事件允许被保存到事件队列中
  - pygame.event.get_blocked(type)
    - 测试某个事件类型是否被事件队列所禁止
    - 如果事件类型被禁止，则返回True，否则返回False

#### 生成事件
- pygame.event.post(Event)
  - 产生一个事件，并将其放入事件队列
  - 一般用于放置用户自定义事件(pygame.USEREVENT)
  - 也可以用于放置系统定义事件(如鼠标或键盘等)，给定参数

- pygame.event.Event(type, dict)
  - 创建一个给定类型的事件
  - 其中，事件的属性和值采用字典类型复制，属性名采用字符串形式
  - 如果创建已有事件，属性需要一致

## 4. 色彩与绘制机制
### Pygame 色彩机制
- pygame.Color
  - Color类用于表达色彩，使用RGB或RGBA色彩模式，A可选。
  - Color类可以用色彩名字，RGBA值，HTML色彩格式等方式定义。

```python
Color(name)
Color("grey")
Color(r,g,b,a)
Color(190,190,190,255)
Color(rgbvalue)
Color("BEBEBEFF")
```
- pygame.Color类
  - pygame.Color.r  获得Color类的红色值r
  - pygame.Color.g  获得Color类的绿色值g
  - pygame.Color.b  获得Color类的蓝色值b
  - pygame.Color.a  获得Color类的alpha值a
  - pygame.Color.normalize  将RGBA各通道值归一到0-1之间

### Pygame 图像绘制机制
- pygame.draw
  - 图形绘制后，返回一个矩形Rect类表示该形状
- pygame.Rect
  - 表达一个矩形区域的类，用于存储坐标和长度信息
  - Pygame利用Rect类来操作图形/图像元素
  - Rect类提供了如下属性，返回一个数值或一个代表坐标的元组
    - x,y,w,h,size,width,height
    - top,left,bottom,right
    - topleft, bottomleft, topright, bottomright
    - midtop, midleft, midbottom, midright
    - center, centerx, centery
    - 详情参考：`http://www.pygame.org/docs/ref/rect.html`
  - Rect类提供了如下方法，用来操作Rect类
    - .copy(), move(),.inflate(),...
    - 详情参考：`http://www.pygame.org/docs/ref/rect.html`
  - Pygame可以绘制多种图像
    - 矩形，多边形，圆形，椭圆形，椭圆弧形，直线，连续多线，无锯齿线，连续无锯齿线
    - pygame.draw.rect(Surface,color,Rect,width=0) 绘制矩形
      - Surface 矩形的绘制屏幕
      - Color   矩形的绘制颜色
      - Rect    矩形的绘制区域
      - width=0 绘制边缘的宽度，默认为0，即填充图形
    - pygame.draw.polygon(Surface,color,pointlist,width = 0)
      - Surface 多边形的绘制屏幕
      - Color   多边形的绘制颜色
      - pointlist 多边形顶点坐标列表
      - width=0 绘制边缘的宽度，默认为0，即填充图形
    - pygame.draw.circle(Surface,color,pos,radius,width = 0)
      - Surface 圆形的绘制屏幕
      - Color   图形的绘制颜色
      - pos     圆形的圆心坐标
      - radius  圆形的半径
      - width=0 绘制边缘的宽度，默认为0，即填充图形
    - pygame.draw.ellipse(Surface,color,Rect,width=0)
      - Surface 椭圆形的绘制屏幕
      - Color   椭圆形的绘制颜色
      - Rect    椭圆形的绘制区域
      - width=0 绘制边缘的宽度，默认为0，即填充图形
    - pygame.draw.arc(Surface,color,Rect,start_angle,stop_angle,width=0)
      - Surface 椭圆弧形的绘制屏幕
      - Color   椭圆弧形的绘制颜色
      - Rect    椭圆弧形的绘制区域
      - start_angle,stop_angle  弧形绘制起始和结束弧度值；横向右侧为0度
      - width=0 绘制边缘的宽度，默认为0，即填充图形
    - pygame.draw.line(Surface,color,star-pos,end_pos,width = 1)
      - Surface 直线的绘制屏幕
      - Color   直线的绘制颜色
      - start_pos,end_pos 直线的起始和结束坐标
      - width = 1 直线的宽度, 默认值为1
    - pygame.draw.lines(Surface,color,closed,pointlist,width = 1)
      - Surface 连续多线的绘制屏幕
      - Color   连续多线的绘制颜色
      - closed  如果为True，起止节点间自动增加封闭直线
      - width = 1 直线的宽度, 默认值为1
    - 