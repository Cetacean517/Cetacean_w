"""3. 有一段英文文本，其中有单词连续重复了2次，编写程序检查重复的单词并只保留一个。"""
import re


def moveRepeat(s):
    for k in {x: s.count(x) for x in re.findall(r'\b\w+\b', s)}.keys():
        print(k, end=' ')


s = input('s:')
moveRepeat(s)
