# axes 类（轴域类）
# 指定了一个有数值范围限制的绘图区域。
# 在一个给定的画布（figure）中可以包含多个 axes 对象，但是同一个 axes 对象只能在一个画布中使用。
# add_axes( [left, bottom, width, height]):生成一个axes轴域对象
# 它表示添加到画布中的矩形区域的左下角坐标(x, y)，以及宽度和高度。如下所示：

# legend()
# ax.legend(handles, labels, loc)
# labels 是一个字符串序列，用来指定标签的名称；
# loc 是指定图例位置的参数，其参数值可以用字符串或整数来表示；
# handles 参数，它也是一个序列，它包含了所有线型的实例；

import matplotlib.pyplot as plt

y = [1, 4, 9, 16, 25, 36, 49, 64]
x1 = [1, 16, 30, 42, 55, 68, 77, 88]
x2 = [1, 6, 12, 18, 28, 40, 52, 65]
fig = plt.figure()
ax = fig.add_axes([0, 0, 1, 1])

# 使用简写的形式color/标记符/线型
l1 = ax.plot(x1, y, 'ys-')
l2 = ax.plot(x2, y, 'go--')
ax.legend(labels=('tv', 'Smartphone'), loc='lower right')  # legend placed at lower right
ax.set_title("Advertisement effect on sales")
ax.set_xlabel('medium')
ax.set_ylabel('sales')
plt.show()
