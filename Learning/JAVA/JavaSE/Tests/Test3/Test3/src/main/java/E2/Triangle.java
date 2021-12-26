package E2;

public class Triangle {
    private double a;       // a,b,c为三边长
    private double b;
    private double c;
    private double Circum;  // 三角形周长

    // 构造函数
    Triangle(double ma,double mb, double mc){
        this.a = ma;
        this.b = mb;
        this.c = mc;
    }

    public void setA(double a) {
        this.a = a;
    }

    public void setB(double b) {
        this.b = b;
    }

    public void setC(double c) {
        this.c = c;
    }

    public double getCircum() {
        Circum = a+b+c;
        return Circum;
    }

    public boolean isTriangle(){
        if(a+b>c && a+c>b && b+c>a){
            return true;
        }
        return false;
    }
}
