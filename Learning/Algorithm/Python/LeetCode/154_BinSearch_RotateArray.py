#!/usr/bin/python3.9
# @Time    : 2022/4/9 12:44
# @Author  : Cetacean
# @File    : 154_BinSearch_RotateArray.py
# @Title    :寻找旋转排序数组中的最小值 II

from typing import List

#
class Solution1:
    def findMin(self, nums: List[int]) -> int:
        start, end = 0, len(nums) - 1
        output = nums[start]
        while start <= end:
            mid = (start + end) // 2
            output = nums[mid] if nums[mid] < output else output
            if nums[mid] == nums[start]:
                start += 1
            elif nums[mid] <= nums[end]:
                # 右区间增序
                output = nums[mid] if nums[mid] < output else output
                end = mid - 1
            else:
                # 左区间增序
                output = nums[start] if nums[start] < output else output
                start = mid + 1
        return output


# 查找最小位置的下标
class Solution:
    def findMin(self, nums: List[int]) -> int:
        start, end = 0, len(nums) - 1
        while start <= end:
            mid = (start + end) // 2
            if nums[mid] > nums[end]:
                start = mid + 1
            elif nums[mid] < nums[end]:
                end = mid
            else:
                end -= 1
        return nums[start]


if __name__ == "__main__":
    s = Solution()
    test1 = [1, 3, 5, 0]
    test2 = [3, 3, 1, 3]
    test3 = [3, 1]
    print(s.findMin(test3))
