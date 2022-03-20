"""1. 假设有一段英文，其中有单独的字母I误写为i，请编写程序进行纠正。"""
import re


def correct1(s):
    print(re.sub(r'\bi\b', 'I', s))  # 利用正则替换


s = input("s: ")
correct1(s)
# s: i am a girl. i. i,
# I am a girl. I. I,
