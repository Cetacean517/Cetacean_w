package E2;

public class Circle {
    private double r;   //半径
    private double s;   //面积

    Circle(double R){
        r = R;
    }
    public void setR(double r) {
        this.r = r;
    }

    public double getS() {
        s = Math.PI * r * r;
        return s;
    }
}
