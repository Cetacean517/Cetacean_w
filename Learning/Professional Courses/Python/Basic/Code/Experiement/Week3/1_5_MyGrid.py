def tempLine(a, b):
    '''绘画半行模板'''
    print(a, end='')
    for i in range(4):
        print(b, end='')


def endPlusLine():
    """绘制加号后半行"""
    tempLine('+ ', '- ')
    print('+ ')


def endStraightLine():
    """绘制|号后半行"""
    tempLine('| ', '  ')
    print('| ')


def plusLine():
    """绘制加号行"""
    tempLine('+ ', '- ')
    endPlusLine()


def straightLine():
    """绘制竖号行"""
    tempLine('| ', '  ')
    endStraightLine()


def my_grid():
    plusLine()
    for i in range(4):
        straightLine()
    plusLine()
    for i in range(4):
        straightLine()
    plusLine()


my_grid()
