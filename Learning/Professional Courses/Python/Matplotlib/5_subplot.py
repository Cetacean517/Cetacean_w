# 在同一画布上会住多个子图
# plt.subplot(nrows, ncols, index)
# nrows: 几行
# ncols: 几列
# index: 初始值 = 1，

# 如果新建的子图与现有的子图重叠，那么重叠部分的子图将会被自动删除，因为它们不可以共享绘图区域。
# # 绘图1：子图覆盖父图
# import matplotlib.pyplot as plt
#
# # 在原始画布创建一个直线
# plt.plot([1, 2, 3])
# # 创建2行1列的子图，分成上下部分。会覆盖之前的图
# plt.subplot(211)
# plt.plot(range(12))
# plt.subplot(212, facecolor='y')
# plt.plot(range(20))
# plt.show()

# # 绘制2：子图和父图同时存在：在figure对象上同时添加两个子图对象
# import matplotlib.pyplot as plt
#
# fig = plt.figure()
# ax1 = fig.add_subplot(111)
# ax1.plot([1, 2, 3])
# ax2 = fig.add_subplot(224, facecolor='y')
# ax2.plot([1, 4, 6])
# fig.show()

# 绘制3：通过给画布添加 axes 对象可以实现在同一画布中插入另外的图像。
import matplotlib.pyplot as plt
import numpy as np
import math

x = np.arange(0, 2 * math.pi, 0.05)
y1 = np.sin(x)
y2 = np.cos(x)
fig = plt.figure()
# 创建main axes
ax1 = fig.add_axes([0, 0, 1, 1])
ax1.plot(x,y1,'b--')
ax1.set_title('sine')
# 创建sub axes
ax2 = fig.add_axes([0.55,0.55,0.33,0.33])
ax2.plot(x,y2,'r')
ax2.set_title('cosine')
fig.show()