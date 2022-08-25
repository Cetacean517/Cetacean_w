"""6.2 方法"""


class Root:
    __total = 0  # 定义类的私有数据成员

    def __init__(self, v):  # 定义私有方法（构造函数）
        self.__value = v
        Root.__total += 1

    def show(self):  # 定义共有方法，self传递一个对象名，确定操作对象
        print('self.__value:', self.__value)
        print('Root.__total:', Root.__total)

    @classmethod  # 类方法的标记
    def classShowTotal(cls):  # 类方法，cls作为第一个参数名
        print(cls.__total)

    @staticmethod
    def staticShowTotal():  # 静态方法
        print(Root.__total)


r = Root(3)
r.classShowTotal()  # 通过对象来调用类方法
# 1
r.staticShowTotal()  # 通过对象来调用静态方法
# 1
r.show()  # 通过对象来调用公有方法
# self.__value: 3
# Root.__total: 1
rr = Root(5)
Root.classShowTotal()  # 通过类名调用类方法
# 2
Root.staticShowTotal()  # 通过类名调用类方法
# 2
# Root.show()  # 试图通过类名直接调用实例方法，失败
# TypeError: show() missing 1 required positional argument: 'self'
Root.show(r)  # 可以通过这种方法来调用方法并访问实例成员
# self.__value: 3
# Root.__total: 2
r.show()
# self.__value: 3
# Root.__total: 2
Root.show(rr)       # 通过类名调用实例方法时为self参数显示传递对象名
# self.__value: 5
# Root.__total: 2
rr.show()
# self.__value: 5
# Root.__total: 2
