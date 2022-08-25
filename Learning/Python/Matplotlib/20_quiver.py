# 振动图
# x	一维、二维数组或者序列，表示箭头位置的x坐标。
# y	一维、二维数组或者序列，表示箭头位置的y坐标。
# u	一维、二维数组或者序列，表示箭头向量的x分量。
# v	一维、二维数组或者序列，表示箭头向量的y分量。
# c	一维、二维数组或者序列，表示箭头颜色。


import matplotlib.pyplot as plt
import numpy as np
x,y = np.meshgrid(np.arange(-2, 2, 0.2), np.arange(-2, 2, 0.25))
z = x*np.exp(-x**2 - y**2)
#计算数组中元素的梯度
v, u = np.gradient(z, 0.2, 0.2)
fig, ax = plt.subplots()
q = ax.quiver(x,y,u,v)
plt.show()