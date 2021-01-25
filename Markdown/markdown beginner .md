# MD新手村
## 2.1 标题编辑
### 一级
#### 二级
##### 三级
###### 四级

##  2.2正文
正文直接输入

注意：代码中换一行，实际输出重视没有的；要换行应按两次回车

## 2.3. 代码块

干IT的少不了和各种代码，命令行接触；Markdown的代码块功能就非常有用了——

代码块通过两行 ``` 符号框出，如果你写的代码是某种语言，那么可以在第一行末尾加上这个语言的名字，代码块内的代码就会执行对应的高亮语法，例如python

```C++
#include <iostream>
using namespace std;

int main()
{
    ...;
    return 0;
}
```

## 2.4. 行内代码

正文中的代码，则通过输入`` 框出 

``print "Tom and Jerry``

## 2.5 列表
有序列表，输入数字，加一个句点，然后空格即可；可以缩进空置多级列表；

``周末计划``

1. C++
2. JAVA 爬虫
   1. ddl 周五
   2. ...

无序列表，输入 - ,然后空格

``购物清单``
  - 订书机
  - 笔袋
  - ...

## 2.6 加粗和倾斜
**加粗**  
*加斜* 

***加粗和加斜***

## 3.1 图片加入


```Markdown
**语法格式**

![alt 属性文本](图片地址)

![alt 属性文本](图片地址 "可选标题") 

**示例**
![RUNOOB 图标](http://static.runoob.com/images/runoob-logo.png)

![RUNOOB 图标](http://static.runoob.com/images/runoob-logo.png "RUNOOB")

```

![RUNOOB 图标](http://static.runoob.com/images/runoob-logo.png)

![RUNOOB 图标](http://static.runoob.com/images/runoob-logo.png "RUNOOB")

图片地址可以是相对路径，也可以是网上链接