# 刻度定位器和格式化器（两个内建类）
# 对于将刻度设置为：“英语数字形式”，“大写阿拉伯数字”
# 语法
# ax.set_xticks([2,4,6,8,10])  设置x轴上的刻度标记
# set_xticklabels(['zero','two','four','six']) 设置x轴上的刻度标签

import matplotlib.pyplot as plt
import numpy as np
import math
x = np.arange(0, math.pi*2, 0.05)
#生成画布对象
fig = plt.figure()
#添加绘图区域
ax = fig.add_axes([0.1, 0.1, 0.8, 0.8])
y = np.sin(x)
ax.plot(x, y)
#设置x轴标签
ax.set_xlabel('angle')
ax.set_title('sine')
ax.set_xticks([0,2,4,6])
#设置x轴刻度标签
ax.set_xticklabels(['zero','two','four','six'])
#设置y轴刻度
ax.set_yticks([-1,0,1])
# ax.set_yticklabels(['minus one','zero','one'])
plt.show()