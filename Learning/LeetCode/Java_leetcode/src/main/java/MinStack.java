import java.util.ArrayList;
import java.util.Arrays;
import java.util.Stack;

/**
 * 题目：
 * 定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，
 * 调用 min、push 及 pop 的时间复杂度都是 O(1)。
 */
class MinStack {
    private int[] stack;
    int top;
    /** initialize your data structure here. */
    public MinStack() {
        top = 0;
        stack = new int[20000];
    }

    public void push(int x) {
        stack[top] = x;
        top++;

    }

    public void pop() {
        top--;
    }

    public int top() {
        return stack[top-1];
    }

    public int min() {
        int pos = top -1;
        int min = stack[pos];
        while(pos >= 0){
            if(min > stack[pos]){
                min = stack[pos];
            }
            pos--;
        }
        return min;
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.min();
 */