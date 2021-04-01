def time():
    x = input("请输入一个时间（24小时制，包含时、分、秒）")
    h, m, s = x.split(':')
    s = int(s) + 1
    s = str(s)
    h.rjust(2, '0')
    m.rjust(2, '0')
    s.rjust(2, '0')
    print(h + ':' + m + ':' + s)
    return


if __name__ == '__main__':
    time()
