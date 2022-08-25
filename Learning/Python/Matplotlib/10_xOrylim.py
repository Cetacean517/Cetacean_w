# set_xlim()和set_ylim()对x、y轴的数值范围进行设置。
# 对照组

import matplotlib.pyplot as plt
import numpy as np

# 获取数据
x = np.arange(1, 10)
# 分割子图
fig, a = plt.subplots(1, 2, figsize=(10, 4))
# 对照组
a[0].plot(x, np.exp(x))
a[0].set_title('exp')
# 设置组，设置x,y轴的范围
a[1].plot(x, np.exp(x), 'r')
a[1].set_title('exp_set_xlim')
a[1].set_ylim(0, 10000)
a[1].set_xlim(0, 10)
fig.show()