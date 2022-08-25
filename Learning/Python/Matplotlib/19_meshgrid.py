# 等高线图
# 在二维平面显示3D图像的方法

import numpy as np
import matplotlib.pyplot as plt

# 创建xlist,ylist数组
xlist = np.linspace(-3.0, 3.0, 100)
ylist = np.linspace(-3.0, 3.0, 100)
# 将上述数据变成网格数据形式
X, Y = np.meshgrid(xlist, ylist)
# 定义Z与X,Y之间的关系
Z = np.sqrt(X ** 2 + Y ** 2)
fig, ax = plt.subplots(1, 1)
# 填充等高线颜色
cp = ax.contourf(X, Y, Z)
fig.colorbar(cp)  # 给图像添加颜色柱
ax.set_title('Filled Contours Plot')
ax.set_xlabel('x (cm)')
ax.set_ylabel('y (cm)')
# 画等高线
plt.contour(X, Y, Z)
plt.show()

# 左侧图像绘制了两个变量 X、Y ，右侧的颜色柱（colorbar）则表示 X 的取值，颜色越深表示值越小，中间深色部分的圆心点表示 x=0，y=0，z=0。
