package cn.cetacean.jdbc;

import cn.cetacean.domain.Emp;
import cn.cetacean.uitl.JDBCUtils;

import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public class JDBCDemo9_JDBCUtil_Select {
    public static void main(String[] args) {
        List<Emp> list = new JDBCDemo9_JDBCUtil_Select().findAll();
        System.out.println(list);
        System.out.println(list.size());
    }
    /**
     * 查询所有emp对象
     * @return
     */
    public List<Emp> findAll(){
        Connection conn = null;
        Statement stmt = null;
        ResultSet rs = null;
        List<Emp> list = null; // 返回结果
        try {
//        1. 注册驱动
//        2. 获取连接
            conn = JDBCUtils.getConnection();
//        3. 定义sql
            String sql = "select * from emp";
//        4. 获取执行sql的对象
            stmt = conn.createStatement();
//        5. 执行sql
            rs = stmt.executeQuery(sql);
//        6. 遍历结果集，封装对象，装载集合
            Emp emp = null;
            list = new ArrayList<Emp>();
            while(rs.next()){
//              获取数据
                int id = rs.getInt("id");
                String ename = rs.getString("ename");
                int job_id = rs.getInt("job_id");
                int mgr = rs.getInt("mgr");
                Date joindate = rs.getDate("joindate");
                double salary = rs.getDouble("salary");
                double bonus = rs.getDouble("bonus");
                int dept_id = rs.getInt("dept_id");
//              创建emp对象，并赋值
                emp = new Emp();
                emp.setId(id);
                emp.setEname(ename);
                emp.setJod_id(job_id);
                emp.setMgr(mgr);
                emp.setJoindate(joindate);
                emp.setSalary(salary);
                emp.setBonus(bonus);
                emp.setDept_id(dept_id);
//              装载集合
                list.add(emp);
            }
        } catch (SQLException throwables) {
            throwables.printStackTrace();
        } finally {
            JDBCUtils.close(rs,stmt,conn);
        }
        return list;
    }
}
