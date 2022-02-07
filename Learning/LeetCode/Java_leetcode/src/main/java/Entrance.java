public class Entrance {
    public static void main(String[] args) {
//        coffer9();
        coffer30();
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
}
