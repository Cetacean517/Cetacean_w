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


import java.util.*;

public class _347_BuketSort {
    public int[] topKFrequent(int[] nums, int k) {
        int max = 0;

//        1. 第1次桶排序: 桶=数值；值=次数
        HashMap<Integer, Integer> numTimes = new HashMap<>();
        for (int num:nums){                                     // 读入数值，统计出现次数
            Integer oldtimes = numTimes.get(num);
            Integer newtimes = numTimes.put(num,oldtimes == null? 1:oldtimes+1);   // 第一次存入，值为1；否则，增1.
        }

//        2. 第2次桶排序: 桶=次数；值=数值
        HashMap<Integer, ArrayList<Integer>> numSort = new HashMap<>();
        for(Map.Entry set: numTimes.entrySet()){                // 将出现次数相同的数，放入同一个桶中。
            Integer key = (Integer) set.getKey();
            Integer value = (Integer) set.getValue();
            max = max < value ? value:max;                      // max = 某数字最大出现次数
            if(numSort.containsKey(value)){                     // 若非第一次添加，则直接添加；否则替换数组。
                numSort.get(value).add( key);
            } else {
                ArrayList<Integer> numlist = new ArrayList<>();
                numlist.add(key);
                numSort.put(value,numlist);
            }
        }

        ArrayList<Integer> outlist = new ArrayList<>();         // 从高到底，输出需要前k个数
        while (outlist.size() < k){
            ArrayList<Integer> out = numSort.get(max);
            if (out != null) {
                outlist.addAll(out);
            }
            max -= 1;

        }

        int[] output = new int[outlist.size()];                 // Arraylist 填充到int[]中
        for(int j = 0; j < outlist.size(); ++j) {
            output[j] = outlist.get(j);
        }

        return output;
    }

}
