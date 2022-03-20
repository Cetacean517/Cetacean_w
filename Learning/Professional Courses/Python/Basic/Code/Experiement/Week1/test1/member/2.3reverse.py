def main():
    #将文件中的单词读出存入列表
    f = open('words.txt',"r",encoding="UTF-8")
    lines = f.readlines()#读取全部内容

    content = [x.strip() for x in lines]

    #找反向对
    for m in content:
        for n in content:
            if m==n[::-1] and content.index(m) <= content.index(m[::-1]):#为了防止重复输出
                print(m,n)

if __name__ == '__main__':
    main()