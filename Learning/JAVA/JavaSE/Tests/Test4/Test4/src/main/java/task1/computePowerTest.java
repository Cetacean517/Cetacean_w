package task1;

public class computePowerTest {
    public static void main(String[] args) {
        // 1. 测试1
        double a,b;
        a = 3.0;
        b = 4.5;
        computePower.comPower1(a,b);
        System.out.println("a:" + a);
        System.out.println("b:" + b);
        // 2. 测试2
        computePower.Parameter p = new computePower.Parameter(1.0,2.0);
        computePower.comPower2(p);
        System.out.println("a:" + p.a);
        System.out.println("b:" + p.b);
    }
}
