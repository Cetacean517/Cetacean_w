"""6-1 自定义一个数组类，支持数组与数字之间的四则运算数组之间的加法运算、内积运算和大小比较，数组元素访问和修改，以及成员测试等功能"""


class MyArray:
    """All the elements in this array must be numbers"""
    __value = []  # 类的私有对象
    __size = 0

    def __IsNumber(self, n):
        """
        在Python中，可以使用反斜杠(\)将一行语句分为多行解释。但是语句包含的{}、[]、()中的内容不需要使用多行连接符。
        int:整型; float:浮点数; complex:复数
        """
        if (not isinstance(n, int)) and \
                (not isinstance(n, float)) and \
                (not isinstance(n, complex)):
            return False
        return True

    def __init__(self, *args):
        if not args:
            self.__value = []
        else:
            for arg in args:
                if not self.__IsNumber(arg):
                    print('All elemtents must be numbers')
                    return
                self.__value = list(args)

    def __add__(self, n):  # 数组中每个元素都与数字n相加，或两个数组相加
        if self.__IsNumber(n):  # 若传入的参数n是数字
            b = MyArray()
            for v in self.__value:
                b.__value.append(v + n)
            return b
        elif isinstance(n, MyArray):  # 若传入的参数n是数组
            if len(n.__value) == len(self.__value):
                c = MyArray()
                for i, j in zip(self.__value, n.__value):
                    c.__value.append(i + j)
                return c
            else:
                print('Length not equal')
        else:
            print('Not supported')

    def __sub__(self, n):  # 数组中每个元素都与数字n相减，返回新数组
        if not self.__IsNumber(n):
            print('-operating with', type(n), 'and number type is not supported.')
            return
        b = MyArray()
        for v in self.__value:
            b.__value.append(v - n)
        return b

    def __mul__(self, n):  # 数组中每个元素都与数字n相乘，返回新数组
        if not self.__IsNumber(n):
            print('* operating with', type(n), 'and number type is not supported.')
            return
        b = MyArray()
        for v in self.__value:
            b.__value.append(v * n)
        return b

    def __truediv__(self, n):  # 数组中每个元素都与数字n相除，返回新数组
        if not self.__IsNumber(n):
            print(r'/ operating with', type(n), 'and number type is not supported.')
            return
        b = MyArray()
        for v in self.__value:
            b.__value.append(v / n)
        return b

    def __floordiv__(self, n):  # 数组中每个元素都与数字n整除，返回新数组
        if not isinstance(n, int):
            print(n, ' is not an integer')
            return
        b = MyArray()
        for v in self.__value:
            b.__value.append(v // n)
        return b

    def __mod__(self, n):  # 数组中每个元素都与数字n求余数，返回新数组
        if not self.__IsNumber(n):
            print(r'% operating with', type(n), 'and number type is not supported.')
            return
        b = MyArray()
        for v in self.__value:
            b.__value.append(v % n)
        return b

    def __pow__(self, n):  # 数组中每个元素都与数字n进行幂计算，返回新数组
        if not self.__IsNumber(n):
            print('** operating with', type(n), 'and number type is not supported.')
            return
        b = MyArray()
        for v in self.__value:
            b.__value.append(v ** n)
        return b

    def __len__(self):
        return len(self.__value)

    def __repr__(self):  # 直接使用对象作为语句时调用该函数
        # equibalent to return'self.__value)
        return repr(self.__value)

    def __str__(self):  # 使用print()函数输出对象时调用该函数
        return str(self.__value)

    def append(self, v):  # 追加元素
        if not self.__IsNumber(v):
            print('Only number can be appended.')
            return
        self.__value.append(v)

    def __getitem__(self, index):  # 获取指定位置的元素值
        if self.__IsNumber(index) and 0 <= index < len(self.__value):
            return self.__value[index]
        else:
            print('Index out of range.')

    def __setitem__(self, index, v):  # 设置指定位置的元素值
        if not self.__IsNumber(v):
            print(v, 'is not a number')
        elif (not isinstance(index, int) or index < 0 or index >= len(self.__value)):
            print('Index type error or out of range.')
        else:
            self.__value = v

    def __contains__(self, v):  # 成员测试运算符in
        if v in self.__value:
            return True
        return False

    def dot(self, v):  # 模拟向量内积
        if not isinstance(v, MyArray):
            print(v, 'must be an instance of MyArray.')
            return
        if len(v) != len(self.__value):
            print('The size must be equal.')
            return
        b = MyArray()
        for m, n in zip(v.__value, self.__value):
            b.__value.append(m * n)
        return sum(b.__value)

    def __eq__(self, v):  # 关系运算符==
        if not isinstance(v, MyArray):
            print(v, 'must be an instance of MyArray.')
            return False
        if self.__value == v.__value:
            return True
        return False

    def __lt__(self, v):  # 关系运算符<
        if not isinstance(v, MyArray):
            print(v, 'must be an instance of MyArray.')
            return False
        if self.__value < v.__value:
            return True
        return False


if __name__ == '__main__':
    print('Please use me as a module.')
    a = MyArray(1,2,3)
    b= MyArray(4,5,6)
    print(a+b)
    print(type(a+b))
