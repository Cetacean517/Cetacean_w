import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;

public class StudentApplication {
    public static void main(String[] args) throws ParseException {
        SimpleDateFormat strFormat = new SimpleDateFormat("yyyy-dd-MM");
        Student student;
        // 本科生信息
        String name="王小二";
        char gender='男';
        String birthday= "2001-06-01";
        String school="上海大学";
        String stuId="11128981";
        String category="大学本科生";
        double[] score= {89.5, 82, 87, 73};
        boolean status=false;
        // 设置本科生信息
        Undergraduate undergraduate = new Undergraduate();
        undergraduate.setName(name);
        undergraduate.setGender(gender);
        undergraduate.setBirthday(strFormat.parse(birthday));
        undergraduate.setSchool(school);
        undergraduate.setStuId(stuId);
        undergraduate.setCategory(category);
        undergraduate.setScore(score);
        undergraduate.setStatus(status);

        String name1="李燕";
        char gender1='女';
        String birthday1="1999-6-12";
        String school1="上海大学";
        String stuId1="10306";
        String category1="硕士研究生";
        double[] score1={70, 52.5, 95, 88, 89, 91};
        char thesisLevel1= 'B';
        boolean status1=false;

        // 设置研究生信息
        Master master = new Master();
        master.setName(name1);
        master.setGender(gender1);
        master.setBirthday(strFormat.parse(birthday1));
        master.setSchool(school1);
        master.setStuId(stuId1);
        master.setCategory(category1);
        master.setScore(score1);
        master.setThesisLevel(thesisLevel1);
        master.setStatus(status1);

        //
        student = undergraduate;
        StudentDegree studentDegree = new StudentDegree();
        studentDegree.issueDegree(student);
        studentDegree.printStudentInfo(student);

        // master
        student = master;
        StudentDegree studentDegree1 = new StudentDegree();
        studentDegree1.issueDegree(student);
        studentDegree1.printStudentInfo(student);
    }


}
