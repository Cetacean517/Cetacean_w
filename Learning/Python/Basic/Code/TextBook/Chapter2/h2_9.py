"""设计一个字典，并编写程序，用户输入内容作为“键”，然后输出字典中对应的“值”，如果用户输入的“键”不存在，则输出“您输入的键不存在”"""


def getValue():
    d = {'a': 0, 'b': 1, 'c': 2, 'd': 3}
    print(d)
    x = input('请输入键值：')
    if d.get(x, -1) == -1:
        print("您输入的键不存在")
    else:
        print(d.get(x))
