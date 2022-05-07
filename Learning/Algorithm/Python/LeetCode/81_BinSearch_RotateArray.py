#!/usr/bin/python3.9
# @Time    : 2022/4/6 21:02
# @Author  : Cetacean
# @File    : 81_BinSearch_RotateArray.py
from typing import List


# 方法1：遍历得到拼接的位置。对两个区域分别做二分查找
class Solution1:
    def binSearch(self, nums: List[int], target: int, low: int, high: int) -> bool:
        while low <= high:
            mid = (low + high) // 2
            if nums[mid] == target:
                return True
            else:
                if nums[mid] > target:
                    high = mid - 1
                else:
                    low = mid + 1
        return False

    def search(self, nums: List[int], target: int) -> bool:
        length = len(nums)
        if length == 0: return False
        low = 0
        while low + 1 < length and nums[low] <= nums[low + 1]:
            low += 1
        low = (low + 1) % length
        flag = self.binSearch(nums, target, low, length - 1)
        if (low - 1) > -1 and not flag:
            flag = self.binSearch(nums, target, 0, low - 1)
        return flag


class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        low, high = 0, len(nums) - 1
        while low <= high:
            mid = (low + high) // 2
            if nums[mid] == target:
                return True
            if nums[low] == nums[mid]:
                # 无法得出那个区间是增序的
                low += 1
            elif nums[mid] <= nums[high]:
                # 右区间是增序的
                if nums[high] >= target > nums[mid]:
                    low = mid + 1
                else:
                    high = mid - 1
            else:
                # 左区间是增序的
                if nums[low] <= target < nums[mid]:
                    high = mid - 1
                else:
                    low = mid + 1
        return False


if __name__ == "__main__":
    s = Solution()
    test1 = [1, 4, 5, 6, 7, 8]
    test2 = [1,1,1,1,1,1,1,1,1,13,1,1,1,1,1,1,1,1,1,1,1,1]
    test3 = [2, 2, 2, 3, 2, 2, 2]
    print(s.search(test2, 13))
