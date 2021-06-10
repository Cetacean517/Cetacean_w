global a
a = 100


def testGlobal():
    a = 3
    print(a)
    return


if __name__ == '__main__':
    testGlobal()  # 全局变量被局部变量覆盖
    print(a)      # 局部变量a被销毁，全局变量a显示值
    '''
    输出：
        3
        100
    '''
