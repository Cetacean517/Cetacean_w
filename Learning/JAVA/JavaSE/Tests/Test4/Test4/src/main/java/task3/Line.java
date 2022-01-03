package task3;

public class Line {
    private Point x1;
    private Point x2;

    Line(Point mx1, Point mx2){
        this.x1 = mx1;
        this.x2 = mx2;
    }

    public double getdist(){
        return (Math.sqrt(Math.pow(x1.getX()-x2.getX(),2)+Math.pow(x1.getY()-x2.getY(),2)));
    }
}
