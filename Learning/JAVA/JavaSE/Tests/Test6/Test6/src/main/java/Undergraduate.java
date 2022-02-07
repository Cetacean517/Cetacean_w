public class Undergraduate extends Student{
    double aver;     // 保存大学生课程成绩的平均值

    @Override
    public boolean getPass() {
        computeAverage();
        if(aver >=60){
            return true;
        } else {
            return false;
        }
    }

    @Override
    public double computeAverage() {
        double sum = 0;
        for (double i:
             this.getScore()) {
            sum += i;
        }
        this.aver = Math.round(sum/score.length);
        return aver;
    }

    @Override
    public String getDegree() {
        if (getPass()){
            return "授予学士学位";
        } else{
            return "不授予学士学位";
        }
    }
}
