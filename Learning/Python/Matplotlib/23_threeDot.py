# mpl_toolkts实用的3D绘图工具包

# # 绘图1：第一个三维绘图程序
# import matplotlib.pyplot as plt
# from mpl_toolkits import mplot3d
# import numpy as np
#
# fig = plt.figure()
# # 创建3d绘图区域
# ax = plt.axes(projection='3d')
# # 从三个维度构建
# z = np.linspace(0, 1, 100)
# x = z * np.sin(20 * z)
# y = z * np.cos(20 * z)
# # 调用ax.plot3D创建三位线图
# ax.plot3D(x, y, z, 'gray')
# ax.set_title('3D line plot')
# plt.show()

# # 绘图2:3D散点图
# # 通过 ax.scatter3D() 函数可以绘制 3D 散点图
# from mpl_toolkits import mplot3d
# import numpy as np
# import matplotlib.pyplot as plt
#
# fig = plt.figure()
# # 创建绘图区域
# ax = plt.axes(projection='3d')
# # 构建xyz
# z = np.linspace(0, 1, 100)
# x = z * np.sin(20 * z)
# y = z * np.cos(20 * z)
# c = x + y
# ax.scatter3D(x, y, z, c=c)
# ax.set_title('3d Scatter plot')
# plt.show()

# # 绘图3:3D等高线图
# # ax.contour3D() 可以用来创建三维等高线图，该函数要求输入数据均采用二维网格式的矩阵坐标。
# # 同时，它可以在每个网格点(x,y)处计算出一个 z 值。
# from mpl_toolkits import mplot3d
# import numpy as np
# import matplotlib.pyplot as plt
#
#
# def f(x, y):
#     return np.sin(np.sqrt(x ** 2 + y ** 2))
#
#
# # 构建x、y数据
# x = np.linspace(-6, 6, 30)
# y = np.linspace(-6, 6, 30)
# # 将数据网格化处理
# X, Y = np.meshgrid(x, y)
# Z = f(X, Y)
# fig = plt.figure()
# ax = plt.axes(projection='3d')
# # 50表示在z轴方向等高线的高度层级，binary颜色从白色变成黑色
# ax.contour3D(X, Y, Z, 50, cmap='binary')
# ax.set_xlabel('x')
# ax.set_ylabel('y')
# ax.set_zlabel('z')
# ax.set_title('3D contour')
# plt.show()

# # 绘图4：3D线框图
# # 线框图可以将数据投影到指定的三维表面上，并输出可视化程度较高的三维效果图。
# # 通过 plot_wireframe() 能够绘制 3D 线框图。
# from mpl_toolkits import mplot3d
# import numpy as np
# import matplotlib.pyplot as plt
#
#
# # 要绘制函数图像
# def f(x, y):
#     return np.sin(np.sqrt(x ** 2 + y ** 2))
#
#
# # 准备x,y数据
# x = np.linspace(-6, 6, 30)
# y = np.linspace(-6, 6, 30)
# # 生成x、y网格化数据
# X, Y = np.meshgrid(x, y)
# # 准备z值
# Z = f(X, Y)
# # 绘制图像
# fig = plt.figure()
# ax = plt.axes(projection='3d')
# # 调用绘制线框图的函数plot_wireframe()
# ax.plot_wireframe(X, Y, Z, color='black')
# ax.set_title('wireframe')
# plt.show()

# 绘图5:3D曲面图
# 曲面图表示一个指定的因变量y与两个自变量x和z之间的函数关系。
# 3D 曲面图是一个三维图形，它非常类似于线框图。
# 不同之处在于，线框图的每个面都由多边形填充而成。
# Matplotlib 提供的 plot_surface() 函数可以绘制 3D 曲面图，该函数需要接受三个参数值 x，y 和 z 。
from mpl_toolkits import mplot3d
import numpy as np
import matplotlib.pyplot as plt

# 求向量积(outer()方法又称外积)
x = np.outer(np.linspace(-2, 2, 30), np.ones(30))
# 矩阵转置
y = x.copy().T
# 数据z
z = np.cos(x ** 2 + y ** 2)
# 绘制曲面图
fig = plt.figure()
ax = plt.axes(projection='3d')
# 调用plot_surface()函数
ax.plot_surface(x, y, z, cmap='viridis', edgecolor='none')
ax.set_title('Surface plot')
plt.show()
