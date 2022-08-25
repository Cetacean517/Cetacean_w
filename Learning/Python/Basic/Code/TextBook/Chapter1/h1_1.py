''' 例1-1 输入三位数 输出单独数字'''

x = input("请输入一个三位数：")
x = int(x)
g = x % 10
s = (x - g) // 10 % 10
b = x // 100
print('百位：', end='')
print(b)
print('十位：', end='')
print(s)
print('个位：', end='')
print(g)

