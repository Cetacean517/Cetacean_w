# 在Windows环境让Matplolib显示中文

# 方法一：重写配置文件
# 适用于所有系统，但操作麻烦
# 绘制折线图
# import matplotlib.pyplot as plt
#
# plt.rcParams["font.sans-serif"] = ["SimHei"]  # 设置字体
# plt.rcParams["axes.unicode_minus"] = False  # 正常显示负号
# year = [2017, 2018, 2019, 2020]
# people = [20, 40, 60, 70]
# # 生成图表
# plt.plot(year, people)
# plt.xlabel('年份')
# plt.ylabel('人口')
# plt.title('人口增长')
# # 设置纵坐标刻度
# plt.yticks([0, 20, 40, 60, 80])
# # 设置填充选项：参数分别对应横坐标，纵坐标，纵坐标填充起始值，填充颜色
# plt.fill_between(year, people, 20, color='green')
# # 显示图表
# plt.show()
#
# # 方法二：修改配置文件
# import matplotlib
#
# matplotlib.matplotlib_fname()
# # 到文件中直接修改，具体查看 http://c.biancheng.net/matplotlib/9284.html

# 绘图二：添加中文字的情书
import matplotlib.pyplot as plt
import numpy as np

plt.rcParams["font.sans-serif"] = ["SimHei"]  # 设置字体
plt.rcParams["axes.unicode_minus"] = False  # 正常显示负号
x = np.linspace(-8, 8, 1024)
y1 = 0.618 * np.abs(x) - 0.8 * np.sqrt(64 - x ** 2)
y2 = 0.618 * np.abs(x) + 0.8 * np.sqrt(64 - x ** 2)
fig = plt.figure()
ax = fig.add_axes([0,0,1,1])
ax.set_xticklabels(['','I','L','O','V','E','Y','O','U'])
ax.set_yticklabels(['','I','M','I','S','S','Y','O','U','!'])
ax.plot(x, y1, 'rD')
ax.plot(x, y2, 'rD')
ax.set_title("一个写代码还在想太阳的鱼小姐",fontsize=20,color="k")
ax.set_xlabel('相遇可能性')
ax.set_ylabel('隔离天数')
fig.show()