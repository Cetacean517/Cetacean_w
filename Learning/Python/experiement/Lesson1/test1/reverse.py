with open("D:/Fish 鱼/SHU/Study/Semesters/07 SHU 2nd spring/Python/上机/Python计算实验一/words.txt", 'r') as f:
    lines = f.readlines()  # 读取全部内容
    content = [x.strip() for x in lines]


    def find(x):
        for item in x:
            for m in x:
                a = m[::-1]
                # if len(item)!=len(m):
                #     continue;
                if item == a:
                    print(item, m)
        return

    def find_up(x):
        fr = 0;ba = -1;
        for item in x:
            for m in x:
                if len(item)!=len(m):
                    continue
                while item[fr] == m[ba]:
                    if fr == len(item) - 1:
                        print(item,item[::-1])
                    fr += 1
                    ba -= 1

    if __name__ == '__main__':
        find(content)
