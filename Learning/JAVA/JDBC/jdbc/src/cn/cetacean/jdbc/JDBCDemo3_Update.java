// 修改数据库表中的数据
package cn.cetacean.jdbc;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;

public class JDBCDemo3_Update {
    public static void main(String[] args) {
        Connection conn = null;
        Statement stmt = null;

        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            conn = DriverManager.getConnection("jdbc:mysql:///db3", "root", "root");
            stmt = conn.createStatement();
            String sql = "update account set balance = 1500 where NAME = 'wangwu'";
            int count = stmt.executeUpdate(sql);
            System.out.println(count);
            if (count > 0){
                System.out.println("修改成功");
            } else {
                System.out.println("修改失败");
            }
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        } catch (SQLException throwables) {
            throwables.printStackTrace();
        } finally {
            if (stmt != null){
                try {
                    stmt.close();
                } catch (SQLException throwables) {
                    throwables.printStackTrace();
                }
            }
            if (conn != null){
                try {
                    conn.close();
                } catch (SQLException throwables) {
                    throwables.printStackTrace();
                }
            }
        }
    }
}