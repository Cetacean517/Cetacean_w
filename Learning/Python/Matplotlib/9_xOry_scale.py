# axes对象的`xscale`或`yscale`属性来实现对坐标轴的格式设置

# 绘图1：对数关系图
import matplotlib.pyplot as plt
import numpy as np

fig, axes = plt.subplots(1, 2, figsize=(10, 4))
x = np.arange(1, 5)
axes[0].plot(x, np.exp(x))
axes[0].plot(x, x ** 2)
axes[0].set_title("Normal scale")
axes[1].plot(x, np.exp(x))
axes[1].plot(x, x ** 2)
# 设置y轴
axes[1].set_yscale("log")
axes[1].set_title("Logarithmic scale (y)")
axes[0].set_xlabel("x axis")
axes[0].set_ylabel("y axis")
axes[0].xaxis.labelpad = 10  # 设置标签的padding
# 设置x、y轴标签
axes[1].set_xlabel("x axis")
axes[1].set_ylabel("y axis")
plt.show()

# 绘图2：设置边界周的颜色，和显示状态
import matplotlib.pyplot as plt

fig = plt.figure()
ax = fig.add_axes([0, 0, 1, 1])
# 为左侧轴，底部轴添加颜色
ax.spines['bottom'].set_color('blue')
ax.spines['left'].set_color('red')
ax.spines['left'].set_linewidth(2)
# 将侧轴、顶部轴设置为None
ax.spines['right'].set_color(None)
ax.spines['top'].set_color(None)
ax.plot([1, 2, 3, 4, 5])
plt.show()
