''' 编写拥有a、对象成员hour,minute和second的时间类Time；'''


class Time:
    __hour = 0
    __minute = 0
    __second = 0

    def __init__(self, h=0, m=0, s=0):
        try:
            if 0 <= h < 24:
                self.__hour = h
            else:
                raise ValueError
            if 0 <= m < 60:
                self.__minute = m
            else:
                raise ValueError
            if 0 <= s < 60:
                self.__second = s
            else:
                raise ValueError
        except ValueError as e:
            print('%02d:%02d:%02d' % (h, m, s), 'TypeError: Time is not correct.')

    # 调用print()函数时，输出__str__返回的内容
    def __str__(self):
        return '%02d:%02d:%02d' % (self.__hour, self.__minute, self.__second)

    def __add__(self, t):
        if isinstance(t, Time):
            new = Time()
            new.__hour = self.__hour + t.__hour
            new.__minute = self.__minute + t.__minute
            new.__second = self.__second + t.__second

            # 对于两个时间产生的进位进行处理
            while new.__second >= 60:
                new.__second -= 60
                new.__minute += 1
            while new.__minute >= 60:
                new.__minute -= 60
                new.__hour += 1
            while new.__hour >= 24:
                new.__hour -= 24
        else:
            print('TypeError: Only accept Time.')
            raise TypeError
        return new

    def time2int(self):
        """把事件对象转换为秒数。"""
        return (self.__hour * 60 + self.__minute) * 60 + self.__second

    def printtime(self):
        print('%02d:%02d:%02d' % (self.__hour, self.__minute, self.__second))

    def isafter(self, t):
        """ 判断两个事件对象的先后"""
        try:
            if isinstance(t, Time):
                if t.__hour > self.__hour:
                    print(t, "is after")
                    return t
                elif t.__minute > self.__minute:
                    print(t, "is after")
                    return t
                elif t.__second > self.__second:
                    print(t, "is after")
                    return t
                else:
                    print(self, "is after")
                    return self
            else:
                raise TypeError
        except TypeError as e:
            print('TypeError: Only accept Time.')

    def increment(self, i):
        try:
            if i > 0 or isinstance(i, Time):
                import math
                h = i // 3600
                m = (i - h * 3600) // 60
                s = i - h * 3600 - m * 60
                t = Time(h, m, s)
                return self.__add__(t)
            else:
                raise ValueError
        except ValueError as e:
            print('ValueError: seconds less than zero.')

    def changeTimeErro(self):
        self.__hour = 25
        self.__minute = 66
        self.__second = 70

    def isvalid(self):
        if 0 <= self.__hour < 24 and 0 <= self.__minute < 60 and 0 <= self.__second < 60:
            print('Time is legal.')
        else:
            print('Time is illegal.')


if __name__ == '__main__':
    # 测试 构造函数
    print('--测试 构造函数--')
    t0 = Time(0, 0, 0)
    t1 = Time(1, 2, 3)
    t2 = Time(4, 5, 6)
    t3 = Time(4, 5, 7)
    h_error = Time(24, 2, 2)
    m_error = Time(12, 67, 2)
    s_error = Time(12, 24, 88)
    # 测试 __str__重载：
    print('--测试 __str__重载--')
    print('t0:', t0)
    # 测试 __add__重载
    print('--测试 __add__重载--')
    print(t1, '+', t2)
    print(t1 + t2)
    # 测试 time2int
    print('--测试 t1 + t2--')
    print('time:', t0, 'second:', t0.time2int())
    print('time:', t1, 'second:', t1.time2int())
    # 测试 printtime
    print('--测试 printtime--')
    t1.printtime()
    # 测试 isafter
    print('--测试 isafter()--')
    print('cmp:', t1, 'and', t2)
    t1.isafter(t2)
    t2.isafter(t3)
    # 测试 increment
    print('--测试 increment()--')
    print('time:', t1, 'add:', t1.increment(3670))
    # 测试 isvalid
    print('--测试 isvalid()--')
    t1.changeTimeErro()
    print(t1)
    t1.isvalid()
