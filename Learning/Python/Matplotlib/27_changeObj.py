# 转换对象
# Matplotlib 是一款轻量级的图形转换框架，
# 它通过转换对象轻松地实现了数据坐标系、轴域坐标系、图形坐标系，以及显示坐标系四者之间的相互转换
# 现有文本“my text”放置在数据点 (x,y) 位置处：

# axes.text(6,6,"my text")
# 通过 Axes 转换对象，我们可以指定文本的位置。使用以下代码，将文本移动至在坐标系的中心位置：
# axes.text(0.5, 0.5, "middle of graph", transform=axes.transAxes)