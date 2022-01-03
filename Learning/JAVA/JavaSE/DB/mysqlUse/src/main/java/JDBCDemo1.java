/*
加载数据库驱动；
建立连接；
创建 Statement 对象，用于向数据库发送 SQL 语句；
获取 ResultSet 对象，取出数据，此对象代表结果集；
释放资源，断开与数据库的连接。
* */

import com.mysql.jdbc.Driver;
import java.sql.*;

public class JDBCDemo1 {

    public static void main(String[] args) throws SQLException, ClassNotFoundException {
        // 1. 加载数据库驱动
//        DriverManager.registerDriver(new Driver());   //会调用两次
        Class.forName("com.mysql.jdbc.Driver");         // 直接调入反射

        // 2. 建立连接
        final String url = "jdbc:mysql://localhost:3306/school";  // 数据库 url
        final String user = "root"; // 数据库用户名
        final String password = "root"; // 数据库密码
        Connection connection = DriverManager.getConnection(url, user, password);
        // 3. 创建 Statement 对象，用于向数据库发送 SQL 语句
        String sql = "SELECT * FROM `s`";
        Statement statement = connection.createStatement();
        ResultSet resultSet = statement.executeQuery(sql);
        // 4. 获取 ResultSet 对象，取出数据，此对象代表结果集
        while (resultSet.next()) {
            int id = resultSet.getInt("xh");
            String username = resultSet.getString("xm");
            String nickname = resultSet.getString("xm");
            String pwd = resultSet.getString("yxh");
            System.out.println("学号=" + id + "; 姓名=" + username + "; nickname=" + nickname + "; 院系号=" + pwd + '\r');
        }
        // 5. 释放资源，断开与数据库的连接（调用close()方法）
        // 5.1 释放 ResultSet
        resultSet.close();
        // 5.2 释放 Statement
        statement.close();
        // 5.3 释放 Connection
        connection.close();
    }
}

