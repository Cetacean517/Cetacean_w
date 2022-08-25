# 散点图
# 表示了因变量随自变量变化的趋势。通俗地讲，它反映的是一个变量受另一个变量的影响程度。

import matplotlib.pyplot as plt

girls_grades = [89, 90, 70, 89, 100, 80, 90, 100, 80, 34]
boys_grades = [30, 29, 49, 48, 100, 48, 38, 45, 20, 30]
grades_range = [10, 20, 30, 40, 50, 60, 70, 80, 90, 100]
fig = plt.figure()
# 添加绘图区域
ax = fig.add_axes([0, 0, 1, 1])
ax.scatter(grades_range, girls_grades, color='r', label="girls")
ax.scatter(grades_range, boys_grades, color='b', label="boys")
ax.set_xlabel('Grades Range')
ax.set_ylabel('Grades Scored')
ax.set_title('scatter plot')
# 添加图例
plt.legend()
plt.show()
