package cn.cetacean.jdbc;

import cn.cetacean.uitl.JDBCUtils;

import java.sql.*;

/**
 * 事务操作
 */
public class JDBCDemo11_Event {
    public static void main(String[] args) throws SQLException {
        Connection conn =null;
        PreparedStatement pstmt1 = null;
        PreparedStatement pstmt2 = null;

        try {
//            1. 获取连接
            conn = JDBCUtils.getConnection();
//            开启事务
            conn.setAutoCommit(false);
//            2. 定义sql
//            2.1 张三 - 500
            String sql1 = "update account set balance = balance - ? where id = ?";
//            2.2 李四 + 500
            String sql2 = "update account set balance = balance + ? where id = ?";
//            3. 获取执行sql的对象
            pstmt1 = conn.prepareStatement(sql1);
            pstmt2 = conn.prepareStatement(sql2);
//            4.设置参数
            pstmt1.setInt(1,500);
            pstmt1.setInt(2,1);
            pstmt2.setInt(1,500);
            pstmt2.setInt(2,2);
//            5. 执行sql
            pstmt1.executeUpdate();
//            手动制造错误
            int num = 3 /0;
            pstmt2.executeUpdate();
//            提交事务
            conn.commit();
        } catch (Exception throwables) {
//            事务回滚
            if(conn!=null){
                conn.rollback();
            }
            throwables.printStackTrace();
        } finally {
            JDBCUtils.close(pstmt1,conn);
            JDBCUtils.close(pstmt2,null);
        }
    }

}
