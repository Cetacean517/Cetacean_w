import random


def Ack(m, n):
    if m == 0:
        return n + 1
    elif m > 0 and n == 0:
        return Ack(m - 1, 1)
    elif m > 0 and n > 0:
        return Ack(m - 1, Ack(m, n - 1))


def deleteDb(t, key=None):
    # 对于字典
    if isinstance(t, dict):     # 判断类型
        s = set()               # 建立集合
        for k, v in t.items():  # 获取字典的key-value值
            if v not in s:      # 第一次出现的元素加入集合
                yield k, v      # 利用生成器，生成元素
                s.add(v)
    else:
        s = set()               # 其他都与dict除了方式一致
        for v in t:
            value = v if key is None else key(v)    # 增加对于不可哈希的序列，进行转换。
            if v not in s:
                yield v
                s.add(value)


def show():
    # 列表测试
    d = [random.randint(0, 10) for x in range(20)]
    print('d', d)
    print(list(deleteDb(d)))

    # 字典测试
    a = {i: random.randint(0, 10) for i in range(15)}
    print('a', a)
    new = list(deleteDb(a))
    print(new)


if __name__ == '__main__':
    print(Ack(3, 4))
    show()
