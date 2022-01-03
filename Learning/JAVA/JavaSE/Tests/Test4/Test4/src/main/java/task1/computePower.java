package task1;

class computePower {
    public static void comPower1(double a, double b){
        a = a * a;
        b = b * b;
        System.out.println("a的平方：" + a);
        System.out.println("b的平方：" + b);
    }

    public static void comPower2(Parameter p){
        double squ_a = p.a * p.a;
        double squ_b = p.b * p.b;
        p.setA(squ_a+squ_b);
        System.out.println("方法中a:"+p.a);
        System.out.println("方法中a:"+p.b);
    }

    public static class Parameter{
        double a;
        double b;

        Parameter(double a,double b){
            this.a = a;
            this.b = b;
        }
        public void setA(double a) {
            this.a = a;
        }
    }

}
