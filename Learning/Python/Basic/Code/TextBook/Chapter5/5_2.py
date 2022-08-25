def addOne(a):
    print(a)
    a += 1
    print(a)


a = 3
addOne(a)
# 3
# 4
print(a)  # 实参a 没有被修改
# 3


def modify(v):  # 修改列表元素值
    v[0] = v[0] + 1


a = [2]
modify(a)
print(a)


# [3]

def modify(v, item):  # 为列表增加元素值
    v.append(item)


a = [2]
modify(a, 3)
print(a)


# [2, 3]

def modify(d):  # 修改字典元素值或者为字典添加元素
    d['age'] = 38


a = {'name': 'Dong', 'age': 37, 'sex': 'Male'}
modify(a)
print(a)
# {'name': 'Dong', 'age': 38, 'sex': 'Male'}
