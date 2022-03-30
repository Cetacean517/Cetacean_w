# JDBC

## 1.JDBC基本概念

概念：Java DataBase Connectivity          Java数据库连接

JDBC本质：

-  官方（sun公司）定义的一套操作所有关系型数据库的规则。即接口。
- 各个数据库厂商实现这套接口，提供数据库驱动jar包
- 。程序员可以使用这套接口（JDBC）编程，真正执行的代码是驱动jar包中的实现类。

## 2. 快速入门

步骤：

1. 导入驱动jar包     mysql-connector-java-5.1.37-bin.jar
   1. 复制 mysql-connector-java-5.1.37-bin.jar 到项目的libs目录下
   2. 右键 -- Add as Library
2. 注册驱动
3. 获取数据库连接对象 Connection
4. 定义sql
5. 获取执行sql语句对象 Statement
6. 执行sql, 接收返回结果
7. 处理结果
8. 释放资源

```java
package cn.cetacean.jdbc;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.Statement;

public class JdbcDemo1 {
    public static void main(String[] args) throws Exception {
//    1. 导入驱动jar包
//    2. 注册驱动
        Class.forName("com.mysql.cj.jdbc.Driver");      // 注意mysql 8.0版本之后的驱动更换，需要加.cj
//    3. 获取数据库的连接对象
        Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/db3", "root", "root");
//    4. 定义sql语句
        String sql = "update account set balance = 500 where id = 1";
//    5. 获取执行sql对象 Statement
        Statement stmt = conn.createStatement();
//    6. 执行sql
        int count = stmt.executeUpdate(sql);
//    7. 处理结果
        System.out.println(count);
//    8. 释放资源
        stmt.close();
        conn.close();
    }
}
```

## 3. JDBC中各接口和类的详解

#### 1. DriverManager  驱动管理对象

功能

 1. 注册驱动

    static void registerDriver(Driver driver) : 注册与给定的驱动程序 DriverManager

    写代码使用：Class.forName("com.mysql.cj.jdbc.Driver");

    通过查看源码发现： 在com.mysql.cj.jdbc.Driver类中存在静态代码块

    ```java
    static {
        try {
            java.sql.DriverManager.registerDriver(new Driver());
        } catch (SQLException E) {
            throw new RuntimeException("Can't register driver!");
        }
    }
    ```

    注意：mysql5之后的驱动jar包可以省略注册驱动的步骤

 2. 获取数据库连接

    方法： static Connection getConnection(String url, String user, String password)

    参数：

     - url：指定连接的路径
       - **语法：jdbc:mysql://ip地址（域名）:端口号/数据库名称**
       - 如果连接本机mysql服务器，且端口默认为3306；则可以写成：`jdbc:mysql:///db3`
     - user：用户名
     - password：密码

#### 2. Connection  数据库连接对象

​	功能

1. 获取执行sql的对象

   - Statement createStatement()
   - PreparedStatment  prepareStatment(String sql) 
2. 管理事务：
   1. 开启事务  void setAutoComit(boolean autoCommit) : 调用方法设置参数为false,即开启事务
   2. 提交事务 void commit()
   3. 回滚事务 void rollback()


####  3. Statement  执行sql对象

1. 执行sql
   1. boolean execute (String sql ):  可以执行任意的sql  【了解】
   2. int executedUpdate(String sql): 执行DML(insert, update , delete),  DDL ( create, alter, drop)
      - 返回值：影响的行数；用于判断DML是否执行成功， 返回值 > 0 则执行成功，反之，失败。
   3. ResultSet executeQuery( String sql ): 执行DQL ( select ) 语句
2. 练习
   1. account表 添加一条记录
   2. account表 修改一条记录
   3. account表 删除一条记录

#### 4. ResultSet  结果集对象，封装查询结果

- next() : 游标向下移动一行，判断当前行是否到最后一行末尾（是否有数据）；有数据时，返回True，无数据时，返回False

- getXxx(参数): 获取数据

  - Xxx: 代表数据类型；e.g.  int   getInt()
  - 参数:  
    1. int : 代表列的编号，从1 开始。 e.g. getString(1)
    2. String:  代表列名。 e.g. getString ("NAME")

- 注意

  - 使用步骤
    1. 游标向下移动一行
    2. 判断是否有数据
    3. 获取数据

```java
while(rs.next()){
    //                循环判断游标是否到达末尾
    //                6.2 获取数据
    int id = rs.getInt(1);
    String name = rs.getString("name");
    double balance = rs.getDouble(3);
    System.out.println("id: " + id);
    System.out.println("name: " + name);
    System.out.println("balance: " + balance);
}
```

练习

定义一个方法，查询emp表的数据将其封装为对象，然后装载集合，返回。

1. 定义Emp 类
2. 定义方法 public List<Emp> findAll(){}
3. 实现方法 select * from emp;

#### 5. PreparedStatement  执行sql对象

1. SQL注入问题：在拼接SQL时，有一些SQL的特殊关键字参与字符串的拼接，会造成安全性问题。
   1. 输入用户名：任意；输入密码：a' or 'a' = 'a
   2. sql: `select * from user where username = 'wienew' and password = 'a' or 'a' = 'a'`
2. 解决SQL注入问题：使用PreparedStatement对象
3. 预编译的SQL：参数使用？作为占位符
4. 步骤
   1. 导入驱动jar包     mysql-connector-java-5.1.37-bin.jar
   2. 注册驱动
   3. 获取数据库连接对象 Connection
   4. 定义sql
      1. 注意：SQL参数使用？作为占位符。e.g. `select * from user where username = ? and password = ?`
   5. 获取执行sql语句对象 PreparedStatement()    Connection.prepareStatement(String sql)
   6. 给？赋值
      1. 方法：setXxx(参数1，参数2)
         1. 参数1：？的位置从1开始
         2. 参数2：？的值
   7. 执行sql, 接收返回结果，不需要传递SQL语句
   8. 处理结果
   9. 释放资源

## 抽取JDBC工具类：JDBCUtils

分析：需要抽取的内容

1. 注册驱动
2. 获取连接对象
3. 释放资源

练习：

​		需求

1. 通过键盘录入用户名和密码
2. 判断用户是否登录成功

​		步骤

1. 创建数据库表 user
2. 创建登录方法

## JDBC控制事务：

1. 事务：一个包含多个步骤的业务操作。如果这个业务操作被事务管理，则这多个步骤要么同时成功，要么同时失败。
2. 操作：
   1. 开启事务
   2. 提交事务
   3. 回滚事务
3. 使用Connection对象来管理事务
   1. 开启事务  void setAutoComit(boolean autoCommit) : 调用方法设置参数为false,即开启事务
   2. 提交事务 void commit()
   3. 回滚事务 void rollback()



