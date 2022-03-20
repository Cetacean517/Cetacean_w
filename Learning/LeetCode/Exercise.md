# Leetcode 习题记录
## 语法组
### Python类的新增语法
```python
class Solution:
    def arrayPairSum(self, nums: List[int]) -> int:
        return sum(sorted(nums)[0::2])
```
新增的语法，为了说明参数和返回值的数据类型。不过仅仅的给人看的，**实际上程序并不检查是否是相符的**。
## 题目
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

