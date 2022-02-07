import java.util.Date;

public abstract class Student {
    // 抽象类Student的数据成员
    String name;
    char gender;
    Date birthday;
    String school;
    String stuId;
    String category;
    double[] score;

    // 3个抽象方法：判定是否满足学位颁发条件、计算学生课程平均值、以及判定是否颁发学位。
    public abstract boolean getPass();
    public abstract double computeAverage();
    public abstract String getDegree();

    // getter and setter 方法
    public Date getBirthday() {
        return birthday;
    }

    public String getSchool() {
        return school;
    }

    public void setSchool(String school) {
        this.school = school;
    }

    public String getStuId() {
        return stuId;
    }

    public void setStuId(String stuId) {
        this.stuId = stuId;
    }

    public String getCategory() {
        return category;
    }

    public void setCategory(String category) {
        this.category = category;
    }

    public double[] getScore() {
        return score;
    }

    public void setScore(double[] score) {
        this.score = score;
    }

    public boolean isStatus() {
        return status;
    }

    public void setStatus(boolean status) {
        this.status = status;
    }

    boolean status;

    public void setName(String name) {
        this.name = name;
    }
    public String getName() {
        return name;
    }
    public void setGender(char gender) {
        this.gender = gender;
    }
    public char getGender() {
        return gender;
    }

    public void setBirthday(Date birthday) {
        this.birthday = birthday;
    }
}
