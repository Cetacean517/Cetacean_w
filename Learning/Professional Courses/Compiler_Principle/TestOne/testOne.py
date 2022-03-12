# 导入库
import re

SAVE = ['var', 'const', 'procedure']  # 建立保留字数组
count = {}  # 计数字典
splitSen = []  # 程序分割后的语句
params = []  # 标识符存储数组
sentence = []  # 存储语句的数组


filename = input('please enter filename:')
# 1. 读入文件
with open(filename) as f:
#     大小写不敏感，故统一大小写，一行一句
    content = f.read().lower().split('\n')
    for line in content:
        line = line.strip()  # 去除空格
        if len(line) != 0:
            # 注释跳过
            if line[0] == '{':
                continue
            # 替换保留字
            if line[0:3] == 'var' or line[0:5] == 'const' or line[0:9] == 'procedure':
                if 'var' in line:
                    line = line.replace('var', '')
                if 'const' in line:
                    line = line.replace('const', '')
                if 'procedure' in line:
                    line = line.replace('procedure','')
                line.replace(' ','')
                para = line.split(',')
                for p in para:
                    x = p.split('=')
                    count[x[0].rstrip(';').replace(' ','')] = 0
#                    存储字符串
                    params.append(x[0].rstrip(";").replace(' ', ''))
    for line in content:
        line = line.strip()
        if len(line) != 0:
            # 注释跳过
            if line[0] == '{':
                continue
            for param in params:
                # 正则匹配  [^a-z]为非字母
                matchObj = re.match(r'.*[^a-z]' + param + '[^a-z^0-9]', line, re.M | re.I)
                a = -1
                while matchObj:
                    count[param] = count[param] + 1
                    a = matchObj.end() - 2
                    matchObj = re.match(r'.*[^a-z]' + param + '[^a-z^0-9]', line[:matchObj.end() - 2], re.M | re.I)
                matchObj = re.match(r'' + param + '[^a-z^0-9]', line[:a], re.M | re.I)
                while matchObj:
                    count[param] = count[param] + 1
                    matchObj = re.match(r'' + param + '[^a-z^0-9]', line[:matchObj.end() - 2], re.M | re.I)
    with open('out_'+filename, 'w') as f:
        for i in params:
            f.write("(" + i + ":\t" + str(count[i]) + ")\n")




