"""编写程序，运行后用户输入4位整数作为年份，判断其是否为闰年。如果年份能被400整除，则为闰年；如果年份能被4整除但不能被100整除也为闰年。"""


def isLunar(year):
    if year % 400 == 0 or (year % 4 == 0 and year % 100 != 0):  # 判断是否为闰年
        print(year, '是闰年')
        return
    else:
        print(year, '不是闰年')


year = input('请输入年份（4位）：')
isLunar(int(year))
