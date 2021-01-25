## Camel-Case
驼峰命名法使用前注意事项：

1. 由于Java面向对象编程的特性, 在命名时应尽量选择名词

2. 驼峰命名法（Camel-Case）: 当变量名或函式名是由一个或多个单字连结在一起，而构成的唯一识别字时，首字母以小写开头，每个单词首字母大写（第一个单词除外）。

  *如：myFirstName。*

3. 包名的书写规范 （Package） 推荐使用公司或机构的顶级域名为包名的前缀，目的是保证各公司/机构内所使用的包名的唯一性。包名全部为小写字母，且具有实际的区分意义。


一般要求：

1. 选择有意义的名字，能快速地传达该类的用途。
2. 所有包的命名必须采用小写英文字母。
   
*实际应用：*
- 应用系统中经常应用分层
- Dao层（数据库访问）
- Service层（业务处理）
- Web层（页面控制action类）

1. 包名的前几个为固定名称.
   - 如果是网站的话，采用网站的域名的反写，
   - 如果域名还没有确定的话，采用公司固定的几个名称。
  
    如：`net.vschool`

2. 在包名的接下来一个单词为模块的名称。
    如： 用户模块，包名为`net.vschool.user`
3. 关于模块的访问操作，采用分层形式,\
   一般分为：
   - Dao层操作：一般定义在net.vschool.xxx.dao 中，其中xxx为模块名称。
   - Service层操作：一般定义在net.vschool.xxx.service中。
   - web层操作：一般定义在 net.vschool.xxx.action中。
   - 如下关于用户模块的例子：
     - net.vschool.user。`
     - net.vschool.user.dao。
     - net.vschool.user.action。
     - net.vschool.user.service。