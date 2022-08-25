''' 2. 设计一个三位向量类，并实现向量的加法、减法以及向量和标量的乘法和除法运算。'''


class Vector(object):
    __vector = []   # 创建类的私有成员

    def __init__(self, *args):  # 初始化三位向量
        if not args:    # 判断参数是否为空
            self.__vector = []
        elif len(args) > 3: # 向量成员超过3个，不能创建
            print('the member in the victor is bigger than three.')
            return
        else:
            for i in args:  # 判断向量成员，数据类型
                if not self.__IsNumber(i):
                    print('member is not a number')
                    return
                self.__vector = list(args)

    def __IsNumber(self, n):    # 辅助函数，判断数据n是否是一个整型或者浮点数
        if not isinstance(n, int) and not isinstance(n, float):
            return False
        return True

    @property   # 设置get属性
    def vector(self):
        return self.__vector

    @vector.setter  # 设置set属性
    def vector(self, v):
        if not isinstance(v, Vector):
            print('Only receive Vector.')
            return
        self.__vector = v.__vector

    def show(self): # 显示向量数据
        print(self.__vector)

    def __add__(self,v):
        if not isinstance(v,Vector):    # v如果不是Vector类型不提供计算
            print('v is not Vector.')
            return
        elif isinstance(v,Vector):  # v是Vector类型，进行加法计算
            a = Vector()
            for x,y in zip(self.__vector,v.__vector):
                a.__vector.append(x + y)
            return a.__vector
        else:
            print('Not supported')

    def __sub__(self,v):
        if not isinstance(v,Vector):    # v如果不是Vector类型不提供计算
            print('v is not Vector.')
            return
        elif isinstance(v,Vector):  # v是Vector类型，进行减法计算
            a = Vector()
            for x,y in zip(self.__vector,v.__vector):
                a.__vector.append(x - y)
            return a.__vector
        else:
            print('Not supported')

    def __mul__(self,v):
        if isinstance(v,int):   # 标量乘法
            a = Vector()
            for x in self.__vector:
                a.__vector.append(x * v)
            return a.__vector
        elif isinstance(v,Vector):  # 向量乘法
            a = Vector()
            for x,y in zip(self.__vector,v.__vector):
                a.__vector.append(x * y)
            return sum(a.__vector)
        else:
            print('Not supported')

    def __truediv__(self, v):
            if isinstance(v, int):  # 标量除法
                a = Vector()
                for x in self.__vector:
                    a.__vector.append(x / v)
                return a.__vector
            elif isinstance(v, Vector):  # 向量乘法
                a = Vector()
                for x, y in zip(self.__vector, v.__vector):
                    a.__vector.append(x / y)
                return a.__vector
            else:
                print('Not supported')

if __name__ == '__main__':
    v1 = Vector(1, 2, 3)
    v1.show()
    # [1, 2, 3]
    v2 = Vector(4,5,6)
    v2.show()
    # [4, 5, 6]
    # 向量加
    print(v1+v2)
    # [5, 7, 9]
    # 向量减
    print(v1-v2)
    # [-3, -3, -3]
    # 向量乘
    print(v1 * v2)
    # 32
    # 向量标量乘法
    print(v1 * 3)
    # [3, 6, 9]
    # 向量除法
    print(v1 / v2)
    # [0.25, 0.4, 0.5]
    # 向量标量除法
    print(v1 / 2)
    # [0.5, 1.0, 1.5]



