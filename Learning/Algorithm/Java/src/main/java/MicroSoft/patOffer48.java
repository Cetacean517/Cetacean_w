package MicroSoft;

import java.util.HashMap;
import java.util.Map;

// 类似于pat的方式，需要记录前一个不同的位置。最好用arraylist取完成
public class patOffer48 {
    public int lengthOfLongestSubstring(String s) {
        Map<Character,Integer> wordDic = new HashMap<>();   // 用于统计字符串中每个字符的位置
        int tmp = 0, max = 0;   // tmp 用于存放前一个的长度，max用于存放最大的（梯台）
        for(int i = 0; i<s.length();i++){
//  String charAt(int index) 获取index位置的字符
//  HashMap getOrDefault() 方法获取指定 key 对应的 value，如果找不到 key ，则返回设置的默认值。
            int pre_pos = wordDic.getOrDefault(s.charAt(i),-1);
            wordDic.put(s.charAt(i),i); // 更新Hash表
            tmp = tmp < i - pre_pos ? tmp + 1 : i - pre_pos;
            max = tmp > max ? tmp : max;
        }
        return max;
    }
}
