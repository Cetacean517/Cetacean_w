/**
 * @time 2022/6/14 15:55
 * @version 1.00
 * @author Cetacean Wang
 * @title 451. 根据字符出现频率排序
 * @type  桶排序
 */
package Sort;

import java.util.HashMap;
import java.util.Map;

public class _451_BuketSort2 {
    public String frequencySort(String s) {
        int max = 0;            // 统计字符出现的最大次数

        // 1. 频率转换：读入字符串，并统计每个字符出现次数，即max值。
        HashMap<Character, Integer> timeList = new HashMap<>();
        for(char ch:s.toCharArray()){
            Integer times = 1;
            if(timeList.containsKey(ch)){
                times = timeList.get(ch);
                timeList.put(ch,++times);
            } else {
                timeList.put(ch,times);
            }
            max = Math.max(max,times);
        }

        // 2. 第2次桶排序
        // 2.1 创建可变长数组 bucket, 初始化。
        StringBuffer[] bucket = new StringBuffer[max];
        for (int i = 0; i < max; i++) {
            bucket[i] = new StringBuffer();
        }

        // 2.2 根据字符出现次数，把字符装入bucket数组中对应的字符串中。
        for(Map.Entry entry: timeList.entrySet()){
            int fre = (int) entry.getValue();
            int pos = fre - 1;                      // 注意：如果一个字符出现多次，应该第一次就存完
            while (fre-- > 0) {
                bucket[pos].append(entry.getKey());
            }
        }

        // 2.3 倒序输出
        StringBuffer bf = new StringBuffer();
        for (int i = bucket.length - 1; i >= 0; i--) {
            bf.append(bucket[i]);
        }

        return bf.toString();
    }
}
