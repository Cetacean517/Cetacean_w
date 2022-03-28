// select 语句获取ResultSet
package cn.cetacean.jdbc;

import java.sql.*;

public class JDBCDemo6_ResultSet {
    public static void main(String[] args) {
        Connection conn = null;
        Statement stmt = null;
        ResultSet rs = null;
        try {
//            1. 注册驱动
            Class.forName("com.mysql.cj.jdbc.Driver");
//            2. 获取Connection对象
            conn = DriverManager.getConnection("jdbc:mysql:///db3", "root", "root");
//            3. 定义sql语句
            String sql = "select * from account";
//            4. 获取 Statment对象
            stmt = conn.createStatement();
//            5. 执行sql
            rs = stmt.executeQuery(sql);
//            6. 处理结果
//            6.1 游标向下移动一行
            rs.next();
//            6.2 获取数据
            int id = rs.getInt(1);
            String name = rs.getString("name");
            double balance = rs.getDouble(3);
            System.out.println("id: " + id);
            System.out.println("name: " + name);
            System.out.println("balance: " + balance);
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        } catch (SQLException throwables) {
            throwables.printStackTrace();
        } finally {
//            7. 释放资源
//            避免空指针异常
            if(rs != null){
                try {
                    rs.close();
                } catch (SQLException throwables) {
                    throwables.printStackTrace();
                }
            }
            if(stmt != null){
                try {
                    stmt.close();
                } catch (SQLException throwables) {
                    throwables.printStackTrace();
                }
            }
            if( conn!= null){
                try {
                    conn.close();
                } catch (SQLException throwables) {
                    throwables.printStackTrace();
                }
            }
        }
    }
}
