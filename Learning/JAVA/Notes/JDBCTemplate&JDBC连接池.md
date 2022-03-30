# 数据库连接池

1. 概念：本质是一个容器（集合），存放数据库连接的容器。
   - 当系统初始化好后，容器中会申请一些连接对象，当用户来访问数据库的时候，从容器中获取连接对象，用户访问完之后，会将连接对象归还给容器。

2. 好处：

   - 节约资源

   - 用户访问高效

3. 实现
   1. 标准接口：DATASource   javax.sql包下
      1. 获取连接：getConnection()
      2. 归还连接：Connection.close() 
   2. 数据库厂商实现
      1. C3P0：数据库连接池技术
      2. Druid: 数据库连接池实现，由阿里巴巴提供

## C3P0: 数据库实现技术

步骤

1. 导入jar包 （2个）

2. 定义配置文件：

   - 名称：c3p0.properties 或者 c3p0-config.xml

   - 路径：直接将文件放在src目录下即可。

3. 创建核心对象  数据库连接池对象 ComboPooledDataSource
4. 获取连接：getConnection

## Druid: 数据库连接池

步骤

1. 导入jar包 druid-1.0.9.jar
2. 定义配置文件
   1. druid.properties
   2. 名称任意，地址任意
3. 加载配置文件 Properties
4. 获取数据库连接池对象：通过工厂类来获取 DruidDataSourceFactory
5. 获取连接：getConnection

定义工具类

1. 定义一个类 JDBCUtils
2. 提供静态代码块加载配置文件，初始化连接对象
3. 提供方法
   1. 获取连接方法：通过数据库连接池获取连接
   2. 释放资源
   3. 获取连接池的方法

# Spring JDBC

步骤

1. 导入jar包
2. 创建JdbcTemplate对象。依赖于数据源DataSource
3. 调用JdbcTemplate方法完成CRUD的操作
   1. update() : 执行DML，增删改语句
   2. queryForMap(): 查询结果，将结果集封装为map集合
      - 注意：查询的结果集长度只能是1，将列名作为key,将值作为value
  3. queryForList(): 查询结果，将结果集封装为List集合
      - 注意：将每一条记录封装为一个Map集合，再将Map集合装载到List集合中
   4. query(): 查询结果，将结果集封装为JavaBean对象
      - query的参数：RowMapper
        - 一般使用BeanPropertyRowMapper实现类。可以完成数据到JavaBean的自动封装
        - new BeanPropertyRowMapper<类型>(类型. class)
   5. queryForObject(): 查询结果，将结果集封装为对象
      - 用于聚合函数的查询
4. 练习
   1. 修改1号数据的salary为10000
   2. 添加一条记录
   3. 删除刚才添加的记录
   4. 查询id为1的记录，将其封装为Map集合
   5. 查询所有记录，将其封装为List
   6. 查询所有记录，将其封装为Emp对象的List集合
   7. 查询总记录数