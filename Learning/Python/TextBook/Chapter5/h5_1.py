'''多次调用函数并且不为默认参数传递值时，默认参数只在第一次调用时进行解释。'''


def demo(newitem, old_list=[]):
    old_list.append(newitem)
    return old_list


def demo1(newitem, old_list=None):
    if old_list is None:
        old_list = []
    old_list.append(newitem)
    return old_list


if __name__ == '__main__':
    # test demo
    print(demo('5', [1, 2, 3, 4]))
    print(demo('aaa', ['a', 'b']))
    print(demo('a'))
    print(demo('b'))    # 故在第一次调用demo('a')之后，再次调用demo('b')会将原来的['a']作为默认的list.

    # test demo1
    print(demo1('5', [1, 2, 3, 4]))
    print(demo1('aaa', ['a', 'b']))
    print(demo1('a'))
    print(demo1('b'))
