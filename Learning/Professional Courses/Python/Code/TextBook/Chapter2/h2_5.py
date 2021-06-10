'''编写程序，用户输入一个列表和2个整数作为下标，然后输出列表中介于2个下标之间的元素组成的子列表。例如用户输入[1,2,3,4,5,6]和2,5,程序输出[3,4,5,6]。'''


def cutList(li, x, y):
    if x < 0 or x >= len(li) or y < 0 or y >= len(li):
        print('index is out of range.')
        return
    elif isinstance(x, int) and isinstance(y, int):
        print(li[x:y + 1])
        return


arr = input('please enter a list:')
li = [int(num) for num in arr[1:-1].split(',')]
print(li)
x = input('x:')
y = input('y:')
cutList(li, int(x), int(y))
