from MyArray import MyArray

x = MyArray(1, 2, 3, 4, 5, 6)
y = MyArray(6, 5, 4, 3, 2, 1)

print(len(x))
# 6

print(x + 5)
# [6, 7, 8, 9, 10, 11]

print(x * 3)
# [3, 6, 9, 12, 15, 18]

print(x.dot(y))
# 56

x.append(7)
print(x)
# [1, 2, 3, 4, 5, 6, 7]

print(x.dot(y))
# The size must be equal.

'''
x[9] = 8
# Index type error or out of range.
'''

print(x / 2)
# [0.5, 1.0, 1.5, 2.0, 2.5, 3.0, 3.5]

print(x // 2)
# [0, 1, 1, 2, 2, 3, 3]

print(x % 3)
# [1, 2, 0, 1, 2, 0, 1]

print(x[2])
# 3

print('a' in x)
# False

print(x < y)
# True

x = MyArray(1, 2, 3, 4, 5, 6)
print(x + y)
# [7, 7, 7, 7, 7, 7]

print(x)
