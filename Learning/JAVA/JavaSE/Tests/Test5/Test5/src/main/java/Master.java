public class Master extends Student{
    double aver;
    char thesisLevel;

    public void setThesisLevel(char thesisLevel) {
        this.thesisLevel = thesisLevel;
    }

    public char getThesisLevel() {
        return thesisLevel;
    }

    @Override
    public boolean getPass() {
    //根据硕士研究生课程平均分和学位论文两个
    //方面判定，若课程成绩平均分 aver 大于等于 80 分且学位论文等级为’C’及其
    //以上，则满足学位颁发要求，改变学位颁发状态。
        computeAverage();
        if (aver>=80 && thesisLevel != 'D' && thesisLevel != 'E'){
            return true;
        }
        else return false;
    }

    @Override
    public double computeAverage() {
        double sum = 0;
        for (double i:
                this.getScore()) {
            sum += i;
        }
        aver = Math.round(sum/score.length);
        return aver;
    }

    @Override
    public String getDegree() {
        if (getPass()) return "授予硕士学位";
        return "不授予硕士学位";
    }
}
