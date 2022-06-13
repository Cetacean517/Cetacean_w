/**
 * @author Cetacean Wang
 * @version 1.00
 * @time 2022/6/13 16:18
 * @title 347. 前 K 个高频元素
 * @type  桶排序
 * @question 给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。
 *           你可以按 任意顺序 返回答案。
 */

package Sort;


import java.util.ArrayList;

public class _347_BuketSort {
    public int[] topKFrequent(int[] nums, int k) {
        int[] numTimes = new int[100000];
        int max = 0;
//        1. 第1次桶排序，桶：数值；值：次数
        for (int n : nums) {
            numTimes[n - 1] += 1;
            max = numTimes[n - 1] > max ? numTimes[n - 1] : max;
        }

//        2. 第2次桶排序，桶：次数；值：数值
        ArrayList<ArrayList> numSorts = new ArrayList<>();
        for (int i = 0; i < max; i++) {
            ArrayList<Integer> numItem = new ArrayList<>();
            numSorts.add(numItem);
        }

        for (int i = 0; i < numTimes.length; i++) {
            int pos = numTimes[i] - 1;
            if (pos > -1) {
                numSorts.get(pos).add(i + 1);
            }
        }

        ArrayList<Integer> KNums = new ArrayList<>();
        while (k > 0) {
            for (int i = numSorts.size() - 1; i >= 0; i--) {
                for (int j = 0; j < numSorts.get(i).size(); j++) {
                    KNums.add((Integer) numSorts.get(i).get(j));
                    k -= 1;
                    if(k == 0) break;
                }
                if(k == 0) break;
            }
        }

        System.out.println(KNums);
        int[] output = new int[KNums.size()];
        for (int i = 0; i < KNums.size(); i++) {
            output[i] = KNums.get(i);
        }
        return output;
    }
}
