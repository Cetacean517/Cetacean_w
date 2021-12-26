public class Main {
    public static void main(String[] args) {
        String s = "Hello World";
        System.out.println(s);
        s = s.toUpperCase();
        System.out.println(s);
        /**字符串的比较：
         * equals() 比较的是内容；
         * equalsIgnoreCase() 忽略大小写比较
         * == 比较的是是不是在同一个位置
         * */

        String s1 = "hello";
        String s2 = "HELLO".toLowerCase();
        System.out.println(s1 == s2);       // false
        System.out.println(s1.equals(s2));  // true
        System.out.println(s1.equalsIgnoreCase(s2));    //true
    }
}
