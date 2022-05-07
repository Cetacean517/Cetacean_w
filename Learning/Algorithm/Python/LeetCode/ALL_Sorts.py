#!/usr/bin/python3.9
# @Time    : 2022/5/2 16:36
# @Author  : Cetacean
# @File    : ALL_Sorts.py
from typing import List


# 快速排序:左闭右闭的二分写法
# 算法思想：找一个基数。从右侧遍历，比基数小的第一个数和基数交换；再从左侧遍历，比基数大的第一个数和基数交换。
# 分界：直到坐标first = last时停止。
# 对基数两侧进行同样的操作，直到l+1 >= r
def quick_sort(num_v, l, r) -> List[int]:
    if l + 1 >= r:
        return
    first, last = l, r - 1
    key = num_v[first]
    while first < last:
        while first < last and num_v[last] >= key:
            last -= 1
        num_v[first] = num_v[last]
        while first < last and num_v[first] <= key:
            first += 1
        num_v[last] = num_v[first]
    num_v[first] = key
    quick_sort(num_v, l, first)
    quick_sort(num_v, first + 1, r)


# 归并排序
def merge_sort(nums, l, r, temp):
    if l + 1 >= r:
        return
    # divide
    m = l + (r - l) // 2
    merge_sort(nums, l, m, temp)
    merge_sort(nums, m, r, temp)
    # conquer
    p, q, i = l, m, l
    while p < m or q < r:
        if q >= r or (p < m and nums[p] <= nums[q]):
            temp.insert(i, nums[p])
            i, p = i + 1, p + 1
        else:
            temp.insert(i, nums[q])
            i, q = i + 1, q + 1
    for i in range(r):
        nums[i] = temp[i]


# 插入排序
def insertion_sort(nums, n):
    for i in range(n):
        j = i
        while j > 0 and nums[j] < nums[j - 1]:
            nums[j], nums[j - 1] = nums[j - 1], nums[j]
            j -= 1


# 冒泡排序
def bubble_sort(nums, n):
    for i in range(n):
        swapped = False
        for j in range(n - i - 1):
            if nums[j] < nums[j - 1]:
                nums[j], nums[j - 1] = nums[j - 1], nums[j]
                swapped = True
        if not swapped:
            break


# 选择排序
def selection_sort(nums, n):
    for i in range(n - 1):
        mid, j = i, i + 1
        while j < n:
            if nums[j] < nums[mid]:
                mid = j
            j += 1
        nums[mid], nums[i] = nums[i], nums[mid]


if __name__ == "__main__":
    nums = [47, 29, 71, 99, 78, 19, 24, 47]
    temp = []
    selection_sort(nums, len(nums))
    # bubble_sort(nums, len(nums))
    # insertion_sort(nums, len(nums))
    # merge_sort(nums, 0, len(nums), temp)
    # quick_sort(nums, 0, len(nums))
    print(nums)
