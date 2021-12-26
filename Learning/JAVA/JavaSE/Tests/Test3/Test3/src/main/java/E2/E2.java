package E2;

import java.math.BigDecimal;
import java.util.Scanner;

public class E2 {
    public static void triTest(){
        // 1. Triangle类
        // a. 创建对象，初始化
        Scanner s1 = new Scanner(System.in);
        double a,b,c;
        System.out.println("请输入三角形的三边：(示例：1 2 3)");
        a = s1.nextDouble();
        b = s1.nextDouble();
        c = s1.nextDouble();
        Triangle t1 = new Triangle(a,b,c);
        // b. 计算周长，并输出
        System.out.println("周长=" + t1.getCircum());
        // 判断a,b,c是否能够构成三角形
        System.out.println("能否构成三角形？");
        if(t1.isTriangle())
        {
            System.out.println("YES");
        }else{
            System.out.println("NO");
        }
        // c. 修改三角形的三边，并输出结果
        System.out.println("请输入修改后的三角形三边长：(示例：1 2 3)");
        a = s1.nextDouble();
        b = s1.nextDouble();
        c = s1.nextDouble();
        t1.setA(a);
        t1.setB(b);
        t1.setC(c);
        if(t1.isTriangle())
        {
            System.out.println("YES");
        }else{
            System.out.println("NO");
        }
    }

    public static void cirTest(){
        // 2. Circle类
        // a. 创建对象，初始化
        Scanner s1 = new Scanner(System.in);
        double r;
        System.out.println("请输入圆的半径：(示例：1)");
        r = s1.nextDouble();
        Circle c1 = new Circle(r);
        // b. 计算圆的面积，并利用BigDecimal类对得到结果进行四舍五入。
        double s = c1.getS();
        BigDecimal bigDecimal = new BigDecimal(s);
        double round_s = bigDecimal.setScale(2,BigDecimal.ROUND_HALF_UP).doubleValue();
        System.out.println("面积="+round_s);
    }

    public static void coneTest() {
        // 3. Cone类
        // a. 创建对象，初始化
        Scanner s1 = new Scanner(System.in);
        double r, h;
        System.out.println("请依次输入圆的半径, 高：(示例：4 5)");
        r = s1.nextDouble();
        h = s1.nextDouble();
        Circle c = new Circle(r);
        Cone cone = new Cone(c,h);
        // b. 计算圆锥体的面积，并利用BigDecimal类对得到结果进行四舍五入。
        double v = cone.getV();
        BigDecimal bigDecimal = new BigDecimal(v);
        double round_v = bigDecimal.setScale(2,BigDecimal.ROUND_HALF_UP).doubleValue();
        System.out.println("体积="+round_v);
        // c. 修改圆锥体的高，再次计算体积并输出
        System.out.println("请输入修改后圆的半径 (示例：1)");
        r = s1.nextDouble();
        cone.setConeR(r);
        double v1 = cone.getV();
        BigDecimal bigDecimal1 = new BigDecimal(v1);
        double round_v1 = bigDecimal1.setScale(2,BigDecimal.ROUND_HALF_UP).doubleValue();
        System.out.println("体积="+round_v1);
        s1.close();
    }
}
