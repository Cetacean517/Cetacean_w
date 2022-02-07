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
    boolean status;
    public abstract String getDegree() throws Exception;

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

    public double[] getScore() { return score;}

    public void setScore(double[] score) {
        this.score = score;
    }

    public boolean isStatus() {
        return status;
    }

    public void setStatus(boolean status) {
        this.status = status;
    }

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
