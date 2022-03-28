// jdbc 快速入门

package cn.cetacean.jdbc;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.Statement;

public class JDBCDemo1_QuickStart {
    public static void main(String[] args) throws Exception {
//    1. 导入驱动jar包
//    2. 注册驱动
//        Class.forName("com.mysql.cj.jdbc.Driver");      // 注意mysql 8.0版本之后的驱动更换，需要加.cj
//    3. 获取数据库的连接对象
//        Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/db3", "root", "root");
        Connection conn = DriverManager.getConnection("jdbc:mysql:///db3", "root", "root");
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
