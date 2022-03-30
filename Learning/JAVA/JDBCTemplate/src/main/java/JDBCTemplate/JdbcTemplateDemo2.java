package JDBCTemplate;

import DataSource.Utils.JDBCUtils;
import Domain.Emp;
import org.junit.Test;
import org.springframework.jdbc.core.BeanPropertyRowMapper;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.jdbc.core.RowMapper;

import java.sql.Date;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.List;
import java.util.Map;

public class JdbcTemplateDemo2 {
    // Junit单元测试

    // 1. 获取JDBCTemplate对象
    private JdbcTemplate template = new JdbcTemplate(JDBCUtils.getDs());
    /**
     * 1. 修改1号数据的salary为10000
     */
    @Test
    public void test1(){
        String sql = "update emp set salary = 10000 where id = 1";
        int count = template.update(sql);
        System.out.println(count);
    }

    /**
     * 2. 添加一条记录
     */
    @Test
    public void test2(){
        String sql = "insert into emp(id,ename,joindate,dept_id) values(?,?,?,?)";
        int count = template.update(sql,1015,"孙悟空","2000-3-23",2);
        System.out.println(count);
    }

    /**
     * 3. 删除刚才添加的记录
     */
    @Test
    public void test3(){
        String sql = "delete from emp where id = ?";
        int count = template.update(sql, 1015);
        System.out.println(count);
    }

    /**
     * 4. 查询id为1的记录，将其封装为Map集合
     * 注意：查询的结果集长度只能是1，将列名作为key,将值作为value
     */
    @Test
    public void test4(){
        String sql = "select * from emp where id = ?";
        Map<String, Object> map = template.queryForMap(sql,1);
        System.out.println(map);
        // {id=1, ename=zhangsan, job_id=1, mgr=2000, joindate=2000-10-30, salary=10000.00, bonus=500.34, dept_id=1}

    }

    /**
     * 5.查询所有记录，将其封装为List
     */
    @Test
    public void test5(){
        String sql = "select * from emp";
        List<Map<String, Object>> maps = template.queryForList(sql);
        for (Map<String, Object> map:maps
             ) {
            System.out.println(map);
        }
    }
    /**
     * 6.查询所有记录，将其封装为Emp对象的List集合
     *   自己实现RowMap类
     */
    @Test
    public void test6_1(){
        String sql = "select * from emp";
        List<Emp> list = template.query(sql, new RowMapper<Emp>() {
            @Override
            public Emp mapRow(ResultSet rs, int i) throws SQLException {
                Emp emp = new Emp();
                int id = rs.getInt("id");
                String ename = rs.getString("ename");
                int job_id = rs.getInt("job_id");
                int mgr = rs.getInt("mgr");
                Date joindate = rs.getDate("joindate");
                double salary = rs.getDouble("salary");
                double bonus = rs.getDouble("bonus");
                int dept_id = rs.getInt("dept_id");

                emp.setId(id);
                emp.setEname(ename);
                emp.setJob_id(job_id);
                emp.getMgr(mgr);
                emp.getJoindate(joindate);
                emp.getSalary(salary);
                emp.getBonus(bonus);
                emp.getDept_id(dept_id);

                return emp;
            }
        });
        for (Emp emp: list){
            System.out.println(emp);
        }
    }
    /**
     * 6.查询所有记录，将其封装为Emp对象的List集合
     * 用提供的实现类
     */
    @Test
    public void test6(){
        String sql = "select * from emp";
        List<Emp> list = template.query(sql, new BeanPropertyRowMapper<Emp>(Emp.class));
        for (Emp emp: list){
            System.out.println(emp);
        }
    }
    /**
     * 7.查询总记录数
     */
    @Test
    public void test7(){
        String sql = "select count(id) from emp";
        Long total = template.queryForObject(sql, Long.class);
        System.out.println(total);
    }
}
