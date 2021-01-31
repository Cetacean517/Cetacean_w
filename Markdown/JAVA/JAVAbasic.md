# JAVA
## 1. 前期准备
### 1.1 命令提示符 cmd
1. 启动：ctrl + R
2. 切换盘符：  ``盘符名称： ``   
3. 进入文件夹:  ``cd文件夹名称``
4. 进入多级文件夹:   ``cd文件夹\ 文件夹2\文件夹3\``
5. 返回上一级: ``cd..``
6. 直接回根路径： ``cd\``
   
   // Tab 键可以切换
7. 查看当前文件夹： ``dir``
8. 清屏：``cls``
9. 退出：``exit``

### 1.2 JDK JRE JVM的关系
JRK = JRE（环境） + 开发工具
JRE = JVM（虚拟机） + Java SE API标准类库

### 1.3 配置环境变量
配置path 环境变量： 我的电脑-属性-高级系统设置-环境变量

创建一个新的PATH 取名为``JAVA_HOME`` 不可随意取值；存放java.exe, javac.exe的路径

将%JAVA_HOME%添加到环境变量中去

**测试**

在cmd中 在d:中调用javac.exe 以及 java.exe.


### 1.4 Hello world *[对一个java程序进行总结]*
1. java程序编写-编译-运行的过程
- 编写： 将编写的java代码保存在以".java"结尾的源文件中
- 编译： 
  - cmd -> cd找到.java文件所在地址
  - 用javac编译成字节码文件     **格式：** *``javac HelloWorld.java``* 或者 *``javac helloworld（源文件名）.java``*
  
- 运行： 使用java.exe命令解释运行字节码文件  **格式：** ``java 类名``

   **注：**
   1. java语言对于英文大小写敏感 [仅支持第一种写法] ；windows系统对大小写不敏感 [可以支持第二种写法]
   2. 编译的时候要写后缀 *``.java``*


2. 
在一个java源文件中可以声明多个class，但只能最多有个一个类声明为public.***且要求public的类的类名必须与源文件名相同***
```java
public class Hello{
   public static void main(String[]args){
      System.out.println("Hello,my world!!!")
   }
}

class Person{

}

class Animal{

}
```
3. 程序的入口是main()方法。格式是固定的，其中只有args可以变化 args-arguments 变量名
4. 输出语句：
   
``System.out.println()`` //先输出，后换行 ‘（）无参数->输出换行’

``System.out.print()`` //仅输出，无换行

5. 执行语句以；结束

6. 编译后会生成一个或多个字节码文件，运行包含主函数的文件
 ### 1.5 注释格式
```java
//单行注释

/*多行注释*/

文档注释（java特有）

      /**
      @author
      @version
      */
      可以被JDK工具javadoc解析
```
