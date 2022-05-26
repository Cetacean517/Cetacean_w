# Chapter10 Exercise

## 10.6 题目

![image-20220521151043261](D:\Cetacean517\Cetacean_w\Learning\Professional Courses\DataBase\Notepic\image-20220521151043261.png)

1. 试用ORDB的定义语言定义数据库。

```postgresql
CREATE TYPE MyString char varying;
/*定义 faculty类型*/
CREATE TYPE faculty(fno integer, 							/*工号*/
                    fname MyString, 						/*姓名*/
                    languages setof(language MyString),		/*精通的外语*/
                    countries setof(country MyString), 		/*出访过的国家*/
                    works_for ref(department)); 			/*工作部门（单值，引用）*/
/*定义 director类型*/
CREATE TYPE director (dno integer) UNDER faculty;
/*定义 department类型*/    
CREATE TYPE department(university MyString, 				/*大学名*/
                       dname MyString, 						/*系名*/
                       staff setof(ref(faculty)),			/*员工（多值，引用）*/
                       dire ref(director));					/*系主任（单值，引用）*/
/*定义 表*/
CREATE TABLE Faculty of TYPE faculty;
CREATE TABLE Director of TYPE director;
CREATE TABLE Department of TYPE department;
```

2. ORDB SELECT语句

   1. 检索精通俄语的教师工号和姓名。

   ```postgresql
   SELECT F.fno, F.name
   FROM Faculty as F
   WHERE 'Russian' in F.languages;
   ```

   ​		   b. 检索复旦大学出访过瑞士并且精通日语的系主任。

   ```postgresql
   SELECT D.dire.fname
   FROM Department as D
   WHERE D.university = 'Fudan University' AND
   	  'Switzerland' in D.dire.countries AND
         'Japanese' in D.dire.languages;
   ```

## 10.7 题目

![image-20220521151050731](D:\Cetacean517\Cetacean_w\Learning\Professional Courses\DataBase\Notepic\image-20220521151050731.png)

1. 解释对象联系图

   学生（身份证号，姓名，籍贯）

   学习（课程名，成绩，求学地，大学）

   1个学习信息对应一个学生，而1个学生可以有n个学习信息。因此，学生和学习信息是1：N的关系。

2. ORDB定义数据库

```postgresql
CREATE TYPE MyString CHAR VARYING;
CREATE TYPE t_study(coursename MyString, grade float, city MyString, university MyString, student ref(t_student))
CREATE TYPE t_student (sno integer, sname MyString, city MyString, study setof(t_study));
CREATE TABLE Student AS TYPE t_student;
CREATE TABLE Study AS TYPE t_study;
```

3. SELECT 语句

   1. 检索每个学生的学习课程和成绩

   ```postgresql
   /*1NF*/
   SELECT A.sname, B.coursename, B.grade
   FROM student as A, A.study as B;
   
   /*非1NF*/
   SELECT A.sname, set(B.coursename, B.grade)
   FROM student as A, A.study as B
   GROUP BY A.sname;
   ```

   ​			b. 检索至少有一门课程的求学地和籍贯在同一城市的学生学号和姓名。

   ```postgresql
   SELECT A.sno, A.sname
   FROM studnet as A
   WHERE EXISTS(SELECT * FROM A.study as B WHERE B.city = A.city)
   ```

   