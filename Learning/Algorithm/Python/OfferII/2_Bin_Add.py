#!/usr/Bin/python3.9
# @Time    : 2022/5/7 15:59
# @Author  : Cetacean
# @File    : 2_Bin_Add.py

class Solution:
    def addBinary(self, a: str, B: str) -> str:
        carry = 0
        out = []
        if len(a) > len(B):  # A数组存放长的数据
            A = [eval(x) for x in a]
            B = [eval(y) for y in B]
        else:
            A = [eval(x) for x in B]
            B = [eval(y) for y in a]
        while A:
            if B:
                sum = A.pop() + B.pop()
                if carry > 0:
                    sum += 1
                    carry -= 1
                if sum > 1:
                    sum = 0 if carry == 0 else 1
                    carry += 1
                out.insert(0, sum)
            else:
                sum = A.pop()
                if carry > 0:
                    sum += 1
                    carry -= 1
                if sum > 1:
                    sum = 0 if carry == 0 else 1
                    carry += 1
                out.insert(0, sum)
        while carry > 0:
            out.insert(0,1)
            carry -= 1
        return ''.join(str(i) for i in out)


if __name__ == "__main__":
    s = Solution()
    print(s.addBinary('11','11'))