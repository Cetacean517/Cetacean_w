package task2;

public class getterAndSetter {
    private static double x;
    private static int y;

    getterAndSetter(double mx, int my){
        x  = mx;
        y = my;
    }
    public static void setX(double mx) {
        x = mx;
    }

    public static void setY(int my) {
        y = my;
    }

    public static double getX() {
        return x;
    }

    public static int getY() {
        return y;
    }
}
