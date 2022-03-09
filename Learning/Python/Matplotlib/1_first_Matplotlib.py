# pyplot 模块提供了可以用来绘图的各种函数，
# 比如创建一个画布，在画布中创建一个绘图区域，或是在绘图区域添加一些线、标签等。
import math

import matplotlib.pyplot as plt
import numpy as np

# 获得0-2π之间的ndarray对象
# numpy.arange(start, stop, step, dtype = None)
# 在给定间隔内返回均匀间隔的值。闭开区间
x = np.arange(0, math.pi * 2, 0.05)
y = np.sin(x)

plt.plot(x,y)
plt.xlabel("angle")
plt.ylabel("sine")
plt.title("sine wave")

# 使用show展示图像
plt.show()