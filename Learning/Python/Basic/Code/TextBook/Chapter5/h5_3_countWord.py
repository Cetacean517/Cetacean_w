"""3. 编写函数，接受一个字符串，分别统计大写字母、小写字母、数字、其他字符的个数，并以元组的形式返回结果。"""


def countWord(s):
    c = [0 for i in range(4)]  # 初始化存储四个需要统计字符类型的数组
    for w in s:  # 通过 if 语句判断，在范围内 +1
        if 'A' <= w <= 'Z':
            c[0] += 1
        elif 'a' <= w <= 'z':
            c[1] += 1
        elif '0' <= w <= '9':
            c[2] += 1
        else:
            c[3] += 1
    return tuple(c)  # 返回元组类型


if __name__ == '__main__':
    s = '12345ab67abcdefgAHIJKLM,.,.,.'
    print('大写字母个数：', countWord(s)[0])
    print('小写字母个数：', countWord(s)[1])
    print('数字：', countWord(s)[2])
    print('其他字符个数：', countWord(s)[3])
