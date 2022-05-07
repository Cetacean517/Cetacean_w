package stlClass;

import java.util.HashMap;
import java.util.Iterator;

/* Map key-value 集合
* 两个实现类:HashMap 和 TreeMap
* HashMap: 按哈希算法存取键对象
* TreeMap: 对键对象进行排序
*
* 常用方法：
* get(key):获取 value
* put(key,value)： 增加数据
* remove(key)：删除数据
* entrySet()：返回所有key-value的集合
* keySet(): 返回多有键对象的集合
* */
public class Map {
    public static void main(String[] args) {
        HashMap hashMap = new HashMap();
        hashMap.put("a","A");
        hashMap.put("b","B");
        hashMap.put("c","C");
        hashMap.put("d","D");
        System.out.println("======keySet======");
        System.out.println(hashMap.keySet());
        System.out.println(hashMap.entrySet());
        hashMap.remove("a");
        System.out.println(hashMap.get("b"));;
        System.out.println(hashMap.entrySet());
        /* 运行结果
        ======keySet======
        [a, b, c, d]
        [a=A, b=B, c=C, d=D]
        B
        [b=B, c=C, d=D]
        */
    }
}
