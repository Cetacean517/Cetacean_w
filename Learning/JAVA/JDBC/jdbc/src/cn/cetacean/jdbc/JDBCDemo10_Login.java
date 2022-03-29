package cn.cetacean.jdbc;

import cn.cetacean.uitl.JDBCUtils;

import java.sql.*;
import java.util.Scanner;

/**
 * 登录方法
 */
public class JDBCDemo10_Login {
    public static void main(String[] args) {
//        1. 键盘读入
        Scanner scanner = new Scanner(System.in);
        System.out.println("请输入用户名：");
        String username = scanner.nextLine();
        System.out.println("请输入密码：");
        String password = scanner.nextLine();
//        2. 调用方法
        boolean flag = new JDBCDemo10_Login().Login_pre(username, password);
//        3. 登录判断
        if(flag){
            System.out.println("登录成功！");
        } else {
            System.out.println("用户名或密码错误！");
        }

    }
    public boolean Login(String username, String password){
        Connection conn = null;
        Statement stmt = null;
        ResultSet rs = null;
        try {
//            1. 建立连接
            conn = JDBCUtils.getConnection();
//            2. 定义sql
            String sql = "select * from user where username = '"+ username +"' and password = '" + password +"'";
            System.out.println(sql);
//            3. 获取执行sql的对象
            stmt = conn.createStatement();
//            4. 执行sql
            rs = stmt.executeQuery(sql);
//            5.判断登录结果
            return rs.next();
        } catch (SQLException throwables) {
            throwables.printStackTrace();
        } finally {
            JDBCUtils.close(rs,stmt,conn);
        }
        return false;
    }
    public boolean Login_pre(String username, String password){
        Connection conn = null;
        PreparedStatement pstmt = null;
        ResultSet rs = null;
        try {
//            1. 建立连接
            conn = JDBCUtils.getConnection();
//            2. 定义sql
            String sql = "select * from user where username = ? and password = ?";
//            3. 获取执行sql的对象
            pstmt = conn.prepareStatement(sql);
            pstmt.setString(1,username);
            pstmt.setString(2,password);
//            4. 执行sql,不需要传参
            rs = pstmt.executeQuery();
//            5.判断登录结果
            return rs.next();
        } catch (SQLException throwables) {
            throwables.printStackTrace();
        } finally {
            JDBCUtils.close(rs,pstmt,conn);
        }
        return false;
    }

}
