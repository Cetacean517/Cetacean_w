import MicroSoft.ClassTable;
import MicroSoft.patOffer48;

public class Entrance {
    public static void main(String[] args) {
//        coffer9();
//        coffer30();
//        coffer270();
        coffer48();
    }

    public static void coffer9(){
        CQueue a = new CQueue();
        a.deleteHead();
        a.deleteHead();
        a.appendTail(7);
        a.show();
    }

    public static void coffer30(){
        MinStack minStack = new MinStack();
        minStack.push(-2);
        minStack.push(0);
        minStack.push(-3);
        System.out.println(minStack.min());
        minStack.pop();
        minStack.top();
        System.out.println(minStack.min());
    }

    public static void coffer270() {
        int[][] exp = {{1,0},{1,2},{0,2},{2,1}};
        ClassTable ct = new ClassTable();
        System.out.println(ct.canFinish(3,exp));
    }

    public static void coffer48() {
        patOffer48 patOffer48 = new patOffer48();
        String str1 = "abcabcbb";
        String str2 = "aab";
        String str3 = "dvdf";
        patOffer48.lengthOfLongestSubstring(str3);
    }

}
