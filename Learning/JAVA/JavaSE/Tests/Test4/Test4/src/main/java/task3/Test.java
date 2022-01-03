package task3;

import java.util.Scanner;

public class Test {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        double a,b,m,n;
        System.out.println("请输入两个点的坐标：（示例：1 3 4 5）");
        a = s.nextDouble();
        b = s.nextDouble();
        m = s.nextDouble();
        n = s.nextDouble();

        Point p1 = new Point(a,b);
        Point p2 = new Point(m,n);

        Line l = new Line(p1,p2);

        System.out.println("直线长度为：" + l.getdist());
        s.close();
    }
}
