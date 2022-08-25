import matplotlib.pyplot as plt
import numpy as np

plt.rcParams["font.sans-serif"] = ["SimHei"]  # 设置字体
plt.rcParams["axes.unicode_minus"] = False  # 正常显示负号
x = np.linspace(-8, 8, 1024)
y1 = 0.618 * np.abs(x) - 0.8 * np.sqrt(64 - x ** 2)
y2 = 0.618 * np.abs(x) + 0.8 * np.sqrt(64 - x ** 2)
fig = plt.figure()
ax = fig.add_axes([0, 0, 1, 1])
ax.set_xticklabels(['', 'I', 'L', 'O', 'V', 'E', 'Y', 'O', 'U'])
ax.set_yticklabels(['', 'I', 'M', 'I', 'S', 'S', 'Y', 'O', 'U', '!'])
ax.plot(x, y1, 'rD')
ax.plot(x, y2, 'rD')
ax.set_title("一个写代码还在想太阳的鱼小姐", fontsize=20, color="k")
ax.set_xlabel('相遇可能性')
ax.set_ylabel('隔离天数')
fig.show()
