#!/usr/bin/env python
# -*-coding:utf-8-*-
# @Time: 4/13/2021 5:26 PM
# @File: autoreply.py
# @Author: Chasing
# @Email: chasing1020@gmail.com
# @Software: PyCharm


import requests
import re
query_url = 'https://www.youlai.cn'


def getCause(question):
    # 查找答案列表
    # find_times = 0
    # match_result = None
    # while find_times < 10 and match_result is None:
    #     find_times += 1
    #     print('查询中:' + str(find_times))
    html = requests.get(query_url + "/cse/search?q=" + question + "&page=", 0)  # + str(find_num))
    match_result = re.search(r'.<a.*href="(.*ask/[^"]*)".*', html.text, re.M | re.I)
    if match_result is not None:
        the_text = match_result.group(1)
        # 获取第一个答案详情
        html = requests.get(query_url + the_text)
        match_result = re.search(r'<div class=\"text\">([^div]*)</div>', html.text, re.M | re.I | re.DOTALL)
        if match_result is None:
            match_result = re.search(r'<div class=\"p_text\">([^div]*)</div>', html.text, re.M | re.I | re.DOTALL)
        if match_result is None:
            match_result = re.search(r'<div class=\"docYes\">.*<p>([^</p>]*)</p>', html.text, re.M | re.I | re.DOTALL)
        if match_result is not None:
            the_text = match_result.group(1)
            the_text = re.sub(r'<[^>]+>', '', the_text)
            return the_text.strip().strip(' '), True
    return "针对当前问题暂时没有很好的解答", False


if __name__ == '__main__':
    q = "程序员颈椎不好"
    answer, ok = getCause(q)
    print(answer)
