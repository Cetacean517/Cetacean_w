# 先构成list: [None,None],再把list作为最外层list的元素，重复三次。
x = [[None] * 2] * 3
print(x)

# x[0][0]修改的是[[None, None], [None, None], [None, None]]中，第一个元素的第一个元素。
# 而该list是又*创建的，因此三个全是对于[None,None]的引用，更改任何一个中的一个元素，其他三个元素均会被修改。
x[0][0] = 5
print(x)

# 原理同上
x = [[1, 2, 3]] * 3
x[0][0] = 10
print(x)
