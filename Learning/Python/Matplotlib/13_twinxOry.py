# 双轴图
# 同时绘制x轴和y轴，且可以设置不同的单位

import matplotlib.pyplot as plt
import numpy as np

fig = plt.figure()
ax1 = fig.add_axes([0, 0, 1, 1])
x = np.arange(1, 11)
ax1.plot(x, np.exp(x))
ax1.set_ylabel('exp')
# 添加双轴
ax2 = ax1.twinx()
# 'ro' 表示红色圆点
ax2.plot(x, np.log(x), 'ro-')
# 绘制对数函数
ax2.set_ylabel('log')
# 绘制图例
fig.legend(labels=('exp1', 'log'), loc='upper left')
plt.show()
