# 图像处理
# image模块提供了加载、缩放和显示图像的功能。
# 该模块只能支持 PNG 格式的图片，如果格式不符，需要对图片的格式进行转换。
# import matplotlib.pyplot as plt
# import matplotlib.image as mpimg
# img = mpimg.imread('mtplogo.png')
# plt.imsave("logo.png", img, cmap = 'gray', origin = 'lower')

import matplotlib.pyplot as plt
import numpy as np

fig = plt.figure()
ax1 = fig.add_subplot(221)
ax2 = fig.add_subplot(222)
ax3 = fig.add_subplot(223)
ax4 = fig.add_subplot(224)
# 准备数据
# 绘制z = sqrt(x^2+y^2)图像
points = np.arange(-5, 5, 0.01)
# meshgrid 接受两个一维数组，然后产生两个二维矩阵
xs, ys = np.meshgrid(points, points)
# 绘制图像
z = np.sqrt(xs ** 2 + ys ** 2)
ax = fig.add_subplot(221)
# 默认
ax.imshow(z)
ax = fig.add_subplot(222)
ax.imshow(z, cmap="gray")
ax = fig.add_subplot(223)
ax.imshow(z, cmap="cool")
ax = fig.add_subplot(224)
ax.imshow(z, cmap="hot")
# 显示图像
plt.show()
