#!/usr/bin/python3.9
# @Time    : 2022/5/3 17:32
# @Author  : Cetacean
# @File    : Hanoti.py

# 经典的汉诺塔问题
from typing import List


def Hanoti(n, src, hlp, dst):
    # 如果仅有一个圆盘，直接从起始柱移动到目标柱
    if n == 1:
        print(src + '->' + dst)
    else:
        # 递归调用 hanoti(),将n - 1个圆盘从起始柱移动到辅助柱上
        hanoti(n - 1, src, dst, hlp)
        # 将起始柱上剩余的最后一个大圆盘移动到辅助柱上
        print(src + '->' + dst)
        # 递归调用 hanoti(), 将辅助柱上的n-1个圆盘移动到目标柱上
        hanoti(n - 1, hlp, src, dst)

# Leetcode上面的汉诺塔
class Solution:
    def hanota(self, A: List[int], B: List[int], C: List[int]) -> None:
        """
        Do not return anything, modify C in-place instead.
        """
        self.hanoti(len(A), A, B, C)
        print(C)

    def hanoti(self, n, A, B, C):
        if n == 1:
            C.append(A.pop())
        else:
            self.hanoti(n - 1, A, C, B)
            C.append(A.pop())
            self.hanoti(n - 1, B, A, C)


if __name__ == "__main__":
    n = input()
    Hanoti(int(n), 'a', 'b', 'c')
    s = Solution()
    s.hanota([2, 1, 0], [], [])
