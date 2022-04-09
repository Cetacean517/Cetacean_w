#!/usr/bin/python3.9
# @Time    : 2022/4/9 15:32
# @Author  : Cetacean
# @File    : 4_BinSearch_TwoArray.py
# @Title    :寻找两个正序数组的中位数

from typing import List


# 方法1： 合并两个数组，求中位数
class Solution1:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        nums = []
        while nums1:
            if nums2 and nums1[0] <= nums2[0]:  # 当nums2有数，且nums1的第一个数比较小的时候，插入nums1的第一个数。
                nums.append(nums1.pop(0))
            elif nums2:  # 当nums2有数，且nums2的第一个数比较小的时候。插入nums2的第一个数。
                nums.append(nums2.pop(0))
            else:  # 当nums2没有数时，直接插入nums1
                nums.extend(nums1)
                nums1.clear()  # 注意：要清空nums1，否则会进入死循环。
        if nums2:
            nums.extend(nums2)
        mid = (0 + len(nums) - 1) // 2
        return (nums[mid] + nums[mid + 1]) / 2 if len(nums) % 2 == 0 else nums[mid]


# 二分法：求第K个，删除前K个算法
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        def getKthElement(k):
            p1, p2 = 0, 0

            while True:
                if p1 == len(nums1):
                    return nums2[p2 + k - 1]
                if p2 == len(nums2):
                    return nums1[p1 + k - 1]
                if k == 1:
                    return min(nums1[p1],nums2[p2])
                new_p1 = min(p1 + k // 2 - 1, len(nums1)-1)
                new_p2 = min(p2 + k // 2 - 1, len(nums2)-1)
                if nums1[new_p1] <= nums2[new_p2]:
                    k -= new_p1 - p1 + 1
                    p1 = new_p1 + 1
                else:
                    k -= new_p2 - p2 + 1
                    p2 = new_p2 + 1

        totalLength = len(nums1) + len(nums2)
        if totalLength % 2:  # 奇數情況
            return getKthElement((totalLength + 1) // 2)
        else:
            return (getKthElement(totalLength // 2) + getKthElement(totalLength // 2 + 1)) / 2


if __name__ == "__main__":
    s = Solution()
    test1 = [4]
    test2 = [1, 2, 3, 5, 6]
    print(s.findMedianSortedArrays(test2, test1))
