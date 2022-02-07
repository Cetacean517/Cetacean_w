import java.text.SimpleDateFormat;

public class Master extends Student implements Manageable{
    double aver;
    char thesisLevel;

    public void setThesisLevel(char thesisLevel) {
        this.thesisLevel = thesisLevel;
    }

    public char getThesisLevel() {
        return thesisLevel;
    }

    @Override
    public double computeAverage() throws Exception {
        // 计算研究生的平均成绩，并抛出异常UndergraduateException
        double sum = 0;
        for (double i:
                this.getScore()) {
            if(i<0 || i>100){
                throw new MasterException();
            }
            sum += i;
        }
        this.aver = Math.round(sum/score.length);
        return aver;
    }

    @Override
    public boolean getPass() {
    //根据硕士研究生课程平均分和学位论文两个
    //方面判定，若课程成绩平均分 aver 大于等于 80 分且学位论文等级为’C’及其
    //以上，则满足学位颁发要求，改变学位颁发状态。
        if (aver>=80 && thesisLevel != 'D' && thesisLevel != 'E'){
            this.status = true;
            return true;
        }
        else {
            this.status =false;
            return false;
        }
    }

    @Override
    public String getDegree() {
        getPass();
        if (this.status) return "授予硕士学位";
        return "不授予硕士学位";
    }

    @Override
    public void printInfo() {
        //输出研究生的基本信息（姓名、性别、出生日期、学校、学号、学生类别、各门课程成绩、颁发学位状况）。
        SimpleDateFormat strFormat = new SimpleDateFormat("yyyy-dd-MM");
        System.out.println("输出研究生的基本信息：");
        System.out.println("姓名：" + this.getName());
        System.out.println("性别：" + this.getGender());
        System.out.println("出生日期：" + strFormat.format(this.getBirthday()));
        System.out.println("学校：" + this.getSchool());
        System.out.println("学号：" + this.getStuId());
        System.out.println("学生类别：" + this.getCategory());
        int no = 0;
        for (double i:this.score
        ) {
            no++;
            System.out.println("No"+ no + ":" + i);
        }
        System.out.println("颁发学位状况:" + this.getDegree());
    }
}
