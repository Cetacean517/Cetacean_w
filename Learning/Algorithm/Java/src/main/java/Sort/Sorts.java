/**
 * @author Cetacean Wang
 * @version 1.00
 * @time 2022/6/13 16:16
 */

package Sort;

import org.junit.Test;

public class Sorts {
    public static void main(String[] args) {
//        基础桶排序：347
//        int[] nums = {1,1,1,1, -1,-1,2,2,2,3,4,4,};
//        int k = 4;
//        _347_BuketSort buketSort = new _347_BuketSort();
//        buketSort.topKFrequent(nums,k);


//        进阶桶排序：451
//        String s = "aabcdA";
//        _451_BuketSort2 buketSort2 = new _451_BuketSort2();
//        buketSort2.frequencySort(s);


//        进阶排序：75
        int[] nums = {0,2,2,1,2,0,2,1,2,1,0};
        _75_SortColor sortColor = new _75_SortColor();
        sortColor.sortColors(nums);
    }
}
