def save():
    x = input("please input x:")
    y = input("please input y:")
    print("x的地址：" + str(id(x)))
    print("y的地址：" + str(id(y)))
    return id(x) == id(y)


a = 0
while a < 10:
    print(save())
    a += 1
