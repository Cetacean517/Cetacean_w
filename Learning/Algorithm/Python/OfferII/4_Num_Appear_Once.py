#!/usr/bin/python3.9
# @Time    : 2022/5/9 20:46
# @Author  : Cetacean
# @File    : 4_Num_Appear_Once.py
# @Url     : https://leetcode.cn/problems/WGki4K/
from typing import List


class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        num_dict = {}
        for x in nums:
            if not num_dict.get(str(x), False):
                num_dict.update({str(x): 1})
            else:
                num_dict[str(x)] += 1
        num_sort = {k:v for k,v in sorted(num_dict.items(),key = lambda item:item[1],reverse=True)}
        return int(list(num_sort.popitem())[0])


if __name__ == "__main__":
    s = Solution()
    nums = [1,0,1,0,1,0,100]
    print(s.singleNumber(nums))
