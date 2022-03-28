// 插入数据库表中的数据
package cn.cetacean.jdbc;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;

public class JDBCDemo2_Insert {
    public static void main(String[] args) {
        Connection conn = null;
        Statement stmt = null;
        try {
//            1. 注册驱动
            Class.forName("com.mysql.cj.jdbc.Driver");
//            2. 获取Connection对象
            conn = DriverManager.getConnection("jdbc:mysql:///db3", "root", "root");
//            3. 定义sql语句
            String sql = "insert into account values(null,'wangwu',3000)";
//            4. 获取 Statment对象
            stmt = conn.createStatement();
//            5. 执行sql
            int count = stmt.executeUpdate(sql);
//            6. 处理结果
            System.out.println(count);
            if ( count > 0){
                System.out.println("添加成功");
            } else {
                System.out.println("添加失败");
            }
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        } catch (SQLException throwables) {
            throwables.printStackTrace();
        } finally {
//            7. 释放资源
//            避免空指针异常
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
