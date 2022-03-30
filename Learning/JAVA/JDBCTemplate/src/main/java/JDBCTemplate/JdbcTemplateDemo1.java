package JDBCTemplate;

import DataSource.Utils.JDBCUtils;
import org.springframework.jdbc.core.JdbcTemplate;

/**
 * JdbcTemplate 入门
 */
public class JdbcTemplateDemo1 {
    public static void main(String[] args) {
//        1. 导入jar包
//        2. 创建JDBCTemplate对象
        JdbcTemplate template = new JdbcTemplate(JDBCUtils.getDs());
//        3. 调用方法
        String sql = "update account set balance = 5000 where id = ?";
        int count = template.update(sql, 5);
        System.out.println(count);
    }
}
