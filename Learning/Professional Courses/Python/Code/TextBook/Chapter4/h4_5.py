"""5. 编写程序，用户输入一段英文，然后输出这段英文中所有长度为3个字母的单词。"""
import re


def moveRepeat(s):
    """利用正则和字典生成式，生成一个字典。key是单词，value是单词的长度。"""
    for k, v in {x: len(x) for x in re.findall(r'\b\w+\b', s)}.items():
        print(k, end=' ') if v == 3 else print('', end='')


s = input('s:')
moveRepeat(s)
