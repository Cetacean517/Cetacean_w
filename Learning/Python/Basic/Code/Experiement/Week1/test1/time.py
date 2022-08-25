def time():
    while 1:
        try:
            x = input("请输入一个时间（24小时制，包含时、分、秒）")
            #  判断输入格式为xx:xx:xx:xx:...超过3个
            if len(x.split(':')) > 3:
                print('输入格式有误。（时间过多）')
                continue
            #  判断时间格式中间不是用“：”连接的情况
            if x[2] != ':' or x[5] != ':':
                print('输入格式有误。（分隔符错误）')
                continue
            # 判断时，分，秒超过24小时制的情况
            if x[0] == '2' and int(x[1]) > 3:
                print('输入格式有误。（小时超过24）')
                continue
            if int(x[3]) > 5:
                print('输入格式有误。（分钟超过60）')
                continue
            if int(x[6]) > 5:
                print('输入格式有误。（秒钟超过60）')
                continue
            h, m, s = x.split(':')

            s = int(s) + 1
            s = str(s)
            # 控制输出格式， 不足两位用“0”补齐
            h.rjust(2, '0')
            m.rjust(2, '0')
            s.rjust(2, '0')
            print(h + ':' + m + ':' + s)
            continue
        except ValueError:
            print("输入的值的类型有误。请重新输入...")
            continue
        return


if __name__ == '__main__':
    time()
