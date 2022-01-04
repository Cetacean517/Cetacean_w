public class StudentDegree {
    public void printStudentInfo(Student student) {
        System.out.println("输出学生的基本信息：");
        System.out.println("姓名：" + student.getName());
        System.out.println("性别：" + student.getGender());
        System.out.println(String.format("出生日期：" + student.getBirthday(), "YYYY-mm-dd"));
        System.out.println("学校：" + student.getSchool());
        System.out.println("学号：" + student.getStuId());
        System.out.println("学生类别：" + student.getCategory());
        System.out.println("平均分：" + student.computeAverage());
    }

    public void issueDegree(Student student) {
        System.out.println("输出学生的学位授予情况：");
        System.out.println(student.getDegree());

    }
}
