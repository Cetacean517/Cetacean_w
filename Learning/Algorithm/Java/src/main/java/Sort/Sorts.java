/**
 * @author Cetacean Wang
 * @version 1.00
 * @time 2022/6/13 16:16
 */

package Sort;

import org.junit.Test;

public class Sorts {
    public static void main(String[] args) {
        int[] nums = {1,1,1,1,2,2,3,4};
        int k = 2;
        _347_BuketSort buketSort = new _347_BuketSort();
        buketSort.topKFrequent(nums,k);
    }
}
