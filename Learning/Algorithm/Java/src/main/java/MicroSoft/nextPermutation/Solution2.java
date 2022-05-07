package MicroSoft.nextPermutation;
/*
* 整数数组的一个 排列  就是将其所有成员以序列或线性顺序排列。

例如，arr = [1,2,3] ，以下这些都可以视作 arr 的排列：[1,2,3]、[1,3,2]、[3,1,2]、[2,3,1] 。
整数数组的 下一个排列 是指其整数的下一个字典序更大的排列。更正式地，如果数组的所有排列根据其字典顺序从小到大排列在一个容器中，那么数组的 下一个排列 就是在这个有序容器中排在它后面的那个排列。如果不存在下一个更大的排列，那么这个数组必须重排为字典序最小的排列（即，其元素按升序排列）。

例如，arr = [1,2,3] 的下一个排列是 [1,3,2] 。
类似地，arr = [2,3,1] 的下一个排列是 [3,1,2] 。
而 arr = [3,2,1] 的下一个排列是 [1,2,3] ，因为 [3,2,1] 不存在一个字典序更大的排列。
给你一个整数数组 nums ，找出 nums 的下一个排列。

必须 原地 修改，只允许使用额外常数空间。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/next-permutation
*/
public class Solution2 {
    public static  void swap(int[]nums,int a,int b){
        int temp = 0;
        temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
        return;
    }
    public static void reverse(int[] nums, int start) {
        int left = start, right = nums.length-1;
        while (left < right) {
            swap(nums, left, right);
            left++;
            right--;
        }
    }

    public static void nextPermutation(int[] nums) {
        if(nums.length < 2) return;
        for(int i = nums.length-2; i >= 0;i--){
            if(nums[i+1] > nums[i] ) {
                int last = nums.length - 1;
                while (nums[i] >= nums[last]) {
                    last--;
                }
                swap(nums, last, i);
                reverse(nums, i + 1);
                return;
            }
        }
        reverse(nums,0);
        return;
    }
    public static void main(String[] args) {
        int[] nums = new int[]{1,5,1};
        nextPermutation(nums);
    }
}
