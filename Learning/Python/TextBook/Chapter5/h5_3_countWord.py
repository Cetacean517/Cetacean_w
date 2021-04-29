def countWord(s):
    c = [0 for i in range(4)]
    for w in s:
        if 'A' <= w <= 'Z':
            c[0] += 1
        elif 'a' <= w <= 'z':
            c[1] += 1
        elif '0' <= w <= '9':
            c[2] += 1
        else:
            c[3] += 1
    return c


if __name__ == '__main__':
    s = '12345ab67abcdefgAHIJKLM,.,.,.'
    print('大写字母个数：', countWord(s)[0])
    print('小写字母个数：', countWord(s)[1])
    print('数字：', countWord(s)[2])
    print('其他字符个数：', countWord(s)[3])
