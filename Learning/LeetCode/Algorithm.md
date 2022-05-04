/

# 算法之旅

## 语法组
### Python类的新增语法
```python
class Solution:
    def arrayPairSum(self, nums: List[int]) -> int:
        return sum(sorted(nums)[0::2])
```
新增的语法，为了说明参数和返回值的数据类型。不过仅仅的给人看的，**实际上程序并不检查是否是相符的**。

## 有趣的题目

### Hanoti 问题

题目：

有三个立柱A、B、C。A柱上穿有大小不等的圆盘N个，较大的圆盘在下，较小的圆盘在上。要求把A柱上的圆盘全部移到C柱上，保持大盘在下、小盘在上的规律（可借助B柱）。每次移动只能把一个柱子最上面的圆盘移到另一个柱子的最上面。请输出移动过程。

输入描述：输入一个整数n

输出描述：输出移动过程

输入样例：
3

输出样例：
a->c
a->b
c->b
a->c
b->a
b->c
a->c

解决方案：http://m.biancheng.net/algorithm/tower-of-hanoi.html

```python
```





## Leetcode题目
### 452.用最少数量的箭引爆气球
在二维空间中有许多球形的气球。对于每个气球，提供的输入是水平方向上，气球直径的开始和结束坐标。由于它是水平的，所以纵坐标并不重要，因此只要知道开始和结束的横坐标就足够了。开始坐标总是小于结束坐标。

一支弓箭可以沿着 x 轴从不同点完全垂直地射出。在坐标 x 处射出一支箭，若有一个气球的直径的开始和结束坐标为 xstart，xend， 且满足  xstart ≤ x ≤ xend，则该气球会被引爆。可以射出的弓箭的数量没有限制。 弓箭一旦被射出之后，可以无限地前进。我们想找到使得所有气球全部被引爆，所需的弓箭的最小数量。

给你一个数组 points ，其中 points [i] = [xstart,xend] ，返回引爆所有气球所必须射出的最小弓箭数。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-number-of-arrows-to-burst-balloons
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#### 要点
- 贪心 + 排序
- Java中二维数组的排序问题。
- 考虑边界的问题
```java
package LeetCodeLab;

/*
* 思路：
* 1. 对二维数组排序
* 2. 统计交叉的个数
* */

import java.util.Arrays;
import java.util.Comparator;

public class FourFiveTwo {
    public static int findMinArrowShots(int[][] points) {
        // Arrays.sort()排序。返回-1 交换；返回1 顺序正确；返回0 两个值相等
        Arrays.sort(points, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                if(o1[1] < o2[1]){
                    return -1;
                }else if(o1[1] > o2[1]){
                    return 1;
                } else{
                    return 0;
                }
            }
        });
        int min = points[0][1], count = 1;
        for(int i = 1;i<points.length;i++){
            if(min < points[i][0]){
                ++count;
                min = points[i][1];
            }
        }
        return count;
    }

    public static void main(String[] args) {
        int[][] points = new int[][]{{-2147483646,-2147483645},{2147483646,2147483647}};
        int[][] points1 = new int[][]{{10,16},{2,8},{1,6},{7,12}};
        int[][] points2 = new int[][]{{9,12},{1,10},{4,11},{8,12},{3,9},{6,9},{6,7}};
        FourFiveTwo.findMinArrowShots(points2);
    }
}
```

## 二分法

### 69. 求开方

#### 方法一：exp + ln() 。 用数学方法，求根号的近似值。

**时间复杂度：O(1)**

**空间复杂度：O(1)**

> 注意: log() 默认自然对数。

``` python
from math import e, log, exp

# log():默认自然对数， int(): 向下取整
class Solution:
    def mySqrt(self, x: int) -> int:
        if x == 0:
            return 0
        ans = int(exp(1/2 * log(x)))
        if (ans+1) ** 2 <= x:
            return ans+1
        return ans
```

#### 方法二： 二分法

**时间复杂度：O(log(x))**

**空间复杂度：O(1)**

**取中间值：mid = ( low + high ) /2 , 此时mid是中间偏左的位置。**

例：查找10的平方根

创造数列：0,1,2,3,4,5,6,7,8,9,10

| round        | low   | high  | mid   | value | action                        |
| ------------ | :---- | ----- | ----- | ----- | ----------------------------- |
| 1（0-10）    | 0     | 10    | 5     | 5     | 25> 10, ans = -1, high左移    |
| 2（0-4）     | 0     | 4     | 2     | 2     | 4 < 10, ans = 2, low右移      |
| **3（3-4）** | **3** | **4** | **3** | **3** | **9 < 10, ans = 3, low右移**  |
| **4（4-4）** | **4** | **4** | **4** | **4** | **16 > 10, ans = 3, low右移** |

```python
class Solution:
    def mySqrt(self, x):
        low = 0
        high = x
        while low <= high:
            mid = (low + high) // 2
            if mid**2 <= x:
                ans = mid # 只有当mid**2 < x的时候，才能够更新ans的值
                low = mid + 1
            else:
                high = mid - 1
        return ans
```

#### 方法三：牛顿迭代

**时间复杂度：O(log(x))**

**空间复杂度：O(1)**

<img src="C:\Users\Fish\AppData\Roaming\Typora\typora-user-images\image-20220315172838263.png" alt="image-20220315172838263" style="zoom: 50%;" />

```python
class Solution:
    def mySqrt(self, x: int) -> int:
        if x == 0:
            return 0
        
        C, x0 = float(x), float(x)
        while True:
            xi = 0.5 * (x0 + C / x0)
            if abs(x0 - xi) < 1e-7:
                break
            x0 = xi
        
        return int(x0)
```

## 排序算法

### 5.1  常用的排序算法

- 快速排序算法

```python
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
```

- 归并排序

```python
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
```

- 插入排序
```python
# 插入排序
def insertion_sort(nums, n):
    for i in range(n):
        j = i
        while j > 0 and nums[j] < nums[j - 1]:
            nums[j], nums[j - 1] = nums[j - 1], nums[j]
            j -= 1
```

- 冒泡排序
```python
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
```

- 选择排序
```python
# 选择排序
def selection_sort(nums, n):
    for i in range(n - 1):
        mid, j = i, i + 1
        while j < n:
            if nums[j] < nums[mid]:
                mid = j
            j += 1
        nums[mid], nums[i] = nums[i], nums[mid]
```