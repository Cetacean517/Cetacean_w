package MicroSoft.nextPermutation;

// 只考虑了3个元素的情况，要扩展，用递归
public class Solution1 {
    public static  void swap(int[]nums,int a,int b){
        int temp = 0;
        temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
        return;
    }
    public static void nextPermutation(int[] nums){
        if(nums.length == 1) return ;
        if(nums.length == 2) {
            swap(nums, 0,1);
            return;
        }
        if(nums[1] < nums[2]){
            swap(nums,1,2);
            return;
        } else{
            if(nums[0] < nums[2]){
                swap(nums,1,2);
                swap(nums,0,1);
                return;
            }else{
                if(nums[1]>nums[0]){
                    swap(nums,0,1);
                    swap(nums,1,2);
                    return;
                }else{
                    swap(nums,0,2);
                    return;
                }
            }
        }
    }
    public static void main(String[] args) {
        int[] nums = new int[]{2,3,1};
        nextPermutation(nums);

    }
}
