package Druid;

import Utils.JDBCUtils;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public class DruidTestUtil {
    public static void main(String[] args) {
        Connection conn = null;
        PreparedStatement pstmt = null;
        try {
//            1. 获取连接对象
            conn = JDBCUtils.getConnection();
//            2. 定义SQL
            String sql = "insert into account values(null,?,?)";
//            3. 获取ptmst对象
            pstmt = conn.prepareStatement(sql);
//            4. 给? 赋值
            pstmt.setString(1,"Candy");
            pstmt.setDouble(2,3000);
//            5. 执行SQL
            int count = pstmt.executeUpdate();
//            6. 处理结果
            System.out.println(count);
        } catch (SQLException throwables) {
            throwables.printStackTrace();
        } finally {
            JDBCUtils.close(pstmt,conn);
        }
    }
}
