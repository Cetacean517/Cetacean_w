# grid():
# 1. 开启 / 关闭画布中的网格（是否显示），以及网格的主/次刻度。
# 2. 设置网络颜色，线型以及线宽等
# 语法：
# grid(color='b',ls='-.',lw=0.25)
# color：表示网格线的颜色；
# ls：表示网格线的样式；
# lw：表示网格线的宽度；

import matplotlib.pyplot as plt
import numpy as np

# fig画布；axes子图区域
fig, a = plt.subplots(1, 3, figsize=(12, 4))
x = np.arange(1, 11)
# 窗格1：默认网格
a[0].plot(x, x ** 3, 'g', lw=2)
a[0].grid(True)  # 开启网络
a[0].set_title('default grid')
# 窗格2：设置网格的颜色，线型，线宽
a[1].plot(x, np.exp(x), 'r')
a[1].grid(color='b', ls='-.', lw=0.25)
a[1].set_title('custom grid')
# 窗格3：无网格
a[2].plot(x, x)
a[2].set_title('no grid')
fig.tight_layout()
plt.show()
