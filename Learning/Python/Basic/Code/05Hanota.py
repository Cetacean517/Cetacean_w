# '''汉诺塔问题：请编写move(n, a, b, c)函数，
# 它接收参数n，表示3个柱子A、B、C中第1个柱子A的盘子数量，
# 然后打印出把所有盘子从A借助B移动到C的方法'''

def move(n, a, b, c):
    if n == 1:
        print(a + '--->' + c)
    else:
        # 把第一歌柱子上n-1个挪到b柱子上
        move(n - 1, a, c, b)
        # 把剩下的最后一个挪到b柱子上
        move(1, a, b, c)
        # 把B柱子上的n-1个挪到c柱子上
        move(n - 1, b, a, c)
    return


move(3, 'A', 'B', 'C')
