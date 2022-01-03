package task2;

public class gsTest {
    public static void main(String[] args) {
        getterAndSetter g1 = new getterAndSetter(1.0, 1);
        System.out.println("对象1");
        System.out.println("x:" + g1.getX() + " y:" + g1.getY());
        getterAndSetter g2 = new getterAndSetter(3.0, 3);
        System.out.println("对象1");
        System.out.println("x:" + g1.getX() + " y:" + g1.getY());
        System.out.println("对象2");
        System.out.println("x:" + g2.getX() + " y:" + g2.getY());
    }
}
