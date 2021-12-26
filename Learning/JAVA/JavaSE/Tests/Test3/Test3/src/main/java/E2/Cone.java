package E2;

public class Cone {
    private Circle circle;  //圆类型
    private double height;  //高
    private double v;       //体积

    Cone(Circle c,double h){
        circle = c;
        height = h;
    }

    public void setConeR(double R) {
        this.circle.setR(R);
    }

    public double getV() {
        v=  circle.getS() * height / 6;
        return v;
    }
}
