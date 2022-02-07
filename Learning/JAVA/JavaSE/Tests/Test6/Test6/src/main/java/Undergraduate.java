import java.text.SimpleDateFormat;

public class Undergraduate extends Student implements Manageable{
    double aver;     // 保存大学生课程成绩的平均值

    @Override
    public double computeAverage() throws UndergraduateException {
        // 计算大学生的平均成绩，并抛出异常UndergraduateException
        double sum = 0;
        for (double i:
                this.getScore()) {
            if(i<0 || i>100){
                throw new UndergraduateException();
            }
            sum += i;
        }
        this.aver = Math.round(sum/score.length);
        return aver;
    }

    @Override
    public boolean getPass() throws Exception {
        // 判断大学生的aver是否大于等于60,根据结果更新status的状态
        computeAverage();
        if(aver >=60){
            this.status = true;
            return true;
        } else {
            this.status = false;
            return false;
        }
    }

    @Override
    public String getDegree() throws Exception {
        // 根据学位颁发状态，确定是否授予学位。
        getPass();
        if (this.status){
            return "授予学士学位";
        } else{
            return "不授予学士学位";
        }
    }

    @Override
    public void printInfo() throws Exception {
        //输出大学生的基本信息（姓名、性别、出生日期、学校、学号、学生类别、各门课程成绩、颁发学位状况）。
        SimpleDateFormat strFormat = new SimpleDateFormat("yyyy-dd-MM");
        System.out.println("输出大学生的基本信息：");
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
