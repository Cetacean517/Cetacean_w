# PyLab 是一个面向 Matplotlib 的绘图库接口
# 另一种导包方式 import pylab
from pylab import *
from numpy import *


x = linspace(-3,3,30) # 返回-3,3的均匀分布的30个数
y = x**2

# # 绘图1：(-3,3)的倒置二次曲线
# #  可以选择画图的线条和颜色
# # 符号：'-'，'--'，'-.'，':'，'.'，','，，o，^，v，<，>，s，+，x，D，d，1，2，3，4，h，H，p，| ，_
# # 颜色：b(蓝色)，g(绿色)，r(红色)，c(青色)，m(品红)，y(黄色)，k(黑色)，w(白色)
# plot(x,y,'m>') # 绘制品红色，>的线
# show()

# 绘图2
plot(x,sin(x))
plot(x,cos(x),'ro')
plot(x,-sin(x),'y+')

show()
clf()
