/**
 * 题目：
 * 用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，
 * 分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )
 *
 * 注意： stack 是vector 的子类。不用考虑堆栈会放满。
 * deleteHead 需要考虑把A栈的数据全部放入B栈。 利用B栈pop实现队列的输出
 */

import java.util.Stack;

class CQueue {
    private Stack<Integer> stack1;
    private Stack<Integer> stack2;

    public CQueue() {
        stack1 = new Stack<>();
        stack2 = new Stack<>();
    }

    public void appendTail(int value) {
        stack1.push(value);
    }

    public int deleteHead() {
        if (stack2.isEmpty()){
            while (!stack1.isEmpty()) {
                stack2.push(stack1.pop());
            }
        }
        if(stack2.isEmpty()){
            return -1;
        }else {
            return stack2.pop();
        }
    }
    public void show(){
        System.out.println(stack1);
        System.out.println(stack2);
    }
}

/**
 * Your test9.CQueue object will be instantiated and called as such:
 * test9.CQueue obj = new test9.CQueue();
 * obj.appendTail(value);
 * int param_2 = obj.deleteHead();
 */