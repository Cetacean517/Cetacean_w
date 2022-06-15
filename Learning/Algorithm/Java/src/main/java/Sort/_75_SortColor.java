/**
 * @time 2022/6/15 17:24
 * @version 1.00
 * @author Cetacean Wang
 * @title 75. 颜色分类
 * @type  排序
 * @question:
 * 给定一个包含红色、白色和蓝色、共n 个元素的数组nums，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
 * 我们使用整数 0、1 和 2 分别表示红色、白色和蓝色
 *
 * 输入：nums = [2,0,2,1,1,0]
 * 输出：[0,0,1,1,2,2]
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode.cn/problems/sort-colors
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 *
 */

package Sort;

import java.util.Arrays;

public class _75_SortColor {

    public void swap(int[] arr, int m, int n){
        /* 交换数组中，下标为m和n的数据 */
        int temp = arr[m];
        arr[m] = arr[n];
        arr[n] = temp;
    }

    public void sortColors1(int[] nums) {
        /*冒泡排序*/
        boolean flag = false;
        for (int i = 0; i<nums.length;i++){
            for(int j = 0; j < nums.length - 1;j++){    // 注意内存循环j的起始点。
                if(nums[j] > nums[j+1]){
                    swap(nums,j,j+1);
                    flag = true;
                }
            }
            if (!flag) break;
        }
        for (int i = 0; i < nums.length; i++) {
            System.out.print(nums[i]);
            System.out.print(", ");
        }
    }

    public void sortColors2(int[] nums) {
        /*插入排序*/
        for (int i = 0; i < nums.length; i++) {
            for (int j = i-1; j >= 0 && nums[j] > nums[j+1] ; j--) {
                swap(nums,j,j+1);
            }
        }
        for (int i = 0; i < nums.length; i++) {
            System.out.print(nums[i]);
            System.out.print(", ");
        }
    }

    public void sortColors3(int[] nums) {
        /*选择排序*/
        for (int i = 0; i < nums.length-1; i++) {
            int pos = i;
            for(int j = i+1; j < nums.length ;j++){     // 记录未排序数列，最小值的下标。
                if (nums[j] < nums[pos]){
                    pos = j;
                }
            }
            swap(nums,pos,i);                           // 将最小数排到当前位置
        }

        for (int i = 0; i < nums.length; i++) {
            System.out.print(nums[i]);
            System.out.print(", ");
        }
    }


    public void quickSort(int[] nums,int l, int r){
        if(l+1 > r){
            return;
        }
        int first = l, last = r-1, key = nums[first];
        while(first < last){
            while(first < last && nums[last] >= key){    // 1.从左向右：找第1个比key小的值，将key和基准交换，否则last--.
                last--;
            }
            nums[first] = nums[last];
            while(first < last && nums[first] <= key ){ // 2. 从右向左：找第1个比key大的值，将key和基准交换，否则first++.
                first++;
            }
            nums[last] = nums[first];
        }
        nums[first] = key;                              // 3. 将改变后的nums[first]重新赋予标准值。
        quickSort(nums,l,first);
        quickSort(nums,first+1,r);
    }
    public void sortColors(int[] nums) {
        /*快速排序*/
        quickSort(nums,0,nums.length);
        for (int i = 0; i < nums.length; i++) {
            System.out.print(nums[i]);
            System.out.print(", ");
        }
    }
}








