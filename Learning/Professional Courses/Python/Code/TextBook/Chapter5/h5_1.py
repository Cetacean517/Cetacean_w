'''多次调用函数并且不为默认参数传递值时，默认参数只在第一次调用时进行解释。'''


def demo(newitem, old_list=[]):  # old_list指向的是一个空列表，在第一次初始化的时候，就已经指定了一个地址单元。之后不再被修改。
    old_list.append(newitem)
    return old_list


def demo1(newitem, old_list=None):  # old_list置空，在函数体内再分配内存单元
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

    '''
    [1, 2, 3, 4, '5']
    ['a', 'b', 'aaa']
    ['a']
    ['a', 'b']
    '''

    # test demo1
    print(demo1('5', [1, 2, 3, 4]))
    print(demo1('aaa', ['a', 'b']))
    print(demo1('a'))
    print(demo1('b'))

    '''
    [1, 2, 3, 4, '5']
    ['a', 'b', 'aaa']
    ['a']
    ['b']
    '''