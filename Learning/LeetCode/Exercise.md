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


### 763. 