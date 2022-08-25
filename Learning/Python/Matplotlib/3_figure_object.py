import math

from matplotlib import pyplot as plt
import numpy as np

# figure()对象 参数：
# figsize	指定画布的大小，(宽度,高度)，单位为英寸。
# dpi	    指定绘图对象的分辨率，即每英寸多少个像素，默认值为80。
# facecolor	背景颜色。
# dgecolor	边框颜色。
# frameon	是否显示边框。

x = np.arange(0, 2 * math.pi, 0.05)
y = np.sin(x)

# 创建图像对象
fig = plt.figure()
# add_axes() 将axes轴添加到画布上；左，底，宽度，高度 （0-1)之间
ax = fig.add_axes([0, 0, 1, 1])
# 设置标签，标题
ax.set_title("sine wave")
ax.set_xlabel("angle")
ax.set_ylabel("sine")
# 调用axes对象的plot()方法，绘制xy
ax.plot(x, y)
plt.show()
