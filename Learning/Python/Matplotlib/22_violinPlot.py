# 小提琴图（Violin Plot）
# 用来展示数据分布状态以及概率密度的图表。
# 这种图表结合了箱形图和密度图的特征。

import matplotlib.pyplot as plt
import numpy as np

np.random.seed(10)
collectn_1 = np.random.normal(100, 10, 200)
collectn_2 = np.random.normal(80, 30, 200)
collectn_3 = np.random.normal(90, 20, 200)
collectn_4 = np.random.normal(70, 25, 200)
# 创建绘制小提琴图的数据序列
data_to_plot = [collectn_1, collectn_2, collectn_3, collectn_4]
# 创建一个画布
fig = plt.figure()
# 创建一个绘图区域
ax = fig.add_axes([0 ,0 ,1 ,1])
# 创建一个小提琴图
bp = ax.violinplot(data_to_plot)
plt.show()
