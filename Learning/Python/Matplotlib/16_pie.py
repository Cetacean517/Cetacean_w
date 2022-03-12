# 饼状图
# 功能：用于显示一个数据序列，占的百分比
# 语法：
# pie()
# 参数：
# X	数组序列，数组元素对应扇形区域的数量大小。
# labels	列表字符串序列，为每个扇形区域备注一个标签名字。
# color	为每个扇形区域设置颜色，默认按照颜色周期自动设置。
# autopct	格式化字符串"fmt%pct"，使用百分比的格式设置每个扇形
# 区的标签，并将其放置在扇形区内。


from matplotlib import pyplot as plt

# 添加图形对象
fig = plt.figure()
ax = fig.add_axes([0, 0, 1, 1])
# 使得X/Y轴的间距相等
ax.axis('equal')
# 准备数据
langs = ['C', 'C++', 'Java', 'Python', 'PHP']
students = [23, 17, 35, 29, 12]
# 绘制饼图
ax.pie(students, labels=langs, autopct='%1.2f%%')
plt.show()
