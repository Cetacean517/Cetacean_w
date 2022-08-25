# 柱状图
# 垂直绘制，水平绘制
# 语法
# ax.bar(x, height, width, bottom, align)
# x: 一个标量序列，代表柱状图的x坐标，默认x取值是每个柱状图所在的中点位置，或者也可以是柱状图左侧边缘位置。
# height	一个标量或者是标量序列，代表柱状图的高度。
# width	可选参数，标量或类数组，柱状图的默认宽度值为 0.8。
# bottom	可选参数，标量或类数组，柱状图的y坐标默认为None。
# algin	有两个可选项 {"center","edge"}，默认为 'center'，该参数决定 x 值位于柱状图的位置。

# import matplotlib.pyplot as plt
#
# # 创建图形对象
# fig = plt.figure()
# # 添加子图区域，参数值表示[left, bottom, width, height ]
# ax = fig.add_axes([0, 0, 1, 1])
# # 准备数据
# langs = ['C', 'C++', 'Java', 'Python', 'PHP']
# students = [23, 17, 35, 29, 12]
# # 绘制柱状图
# ax.bar(langs, students)
# plt.show()

# # 绘图2：4组柱状图，每组分为3小组
# import numpy as np
# import matplotlib.pyplot as plt
#
# # 准备数据
# data = [[30, 25, 50, 20],
#         [40, 23, 51, 17],
#         [35, 22, 45, 19]]
# X = np.arange(4)
# fig = plt.figure()
# # 添加子图区域
# ax = fig.add_axes([0, 0, 1, 1])
# # 绘制柱状图
# ax.bar(X + 0.00, data[0], color='b', width=0.25)
# ax.bar(X + 0.25, data[1], color='g', width=0.25)
# ax.bar(X + 0.50, data[2], color='r', width=0.25)
# plt.show()

# 绘图3：柱状堆叠图
import numpy as np
import matplotlib.pyplot as plt

countries = ['USA', 'India', 'China', 'Russia', 'Germany']
bronzes = np.array([38, 17, 26, 19, 15])
silvers = np.array([37, 23, 18, 18, 10])
golds = np.array([46, 27, 26, 19, 17])
# 此处的 _ 下划线表示将循环取到的值放弃，只得到[0,1,2,3,4]
ind = [x for x, _ in enumerate(countries)]
# 绘制堆叠图
plt.bar(ind, golds, width=0.5, label='golds', color='gold', bottom=silvers + bronzes)
plt.bar(ind, silvers, width=0.5, label='silvers', color='silver', bottom=bronzes)
plt.bar(ind, bronzes, width=0.5, label='bronzes', color='#CD853F')
# 设置坐标轴
plt.xticks(ind, countries)
plt.ylabel("Medals")
plt.xlabel("Countries")
plt.legend(loc="upper right")
plt.title("2019 Olympics Top Scorers")
plt.show()
