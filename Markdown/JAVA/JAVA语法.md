
# 控制流程
## 输出
``` Java
//格式化输出
public class Main {
    public static void main(String[] args) {
        double d = 3.1415926;
        System.out.printf("%.2f\n", d); // 显示两位小数3.14
        System.out.printf("%.4f\n", d); // 显示4位小数3.1416
    }
}

```
占位符	说明
%d	格式化输出整数
%x	格式化输出十六进制整数
%f	格式化输出浮点数
%e	格式化输出科学计数法表示的浮点数
%s	格式化字符串

```java
//练习
/**
 * 输入上次考试成绩（int）和本次考试成绩（int），然后输出成绩提高的百分比，保留两位小数位（例如，21.75%）
 */
public class Main {

	public static void main(String[] args) {
		int prev = 80;
		int score = 90;
		double percent = 0.1;
		double co = ((score-prev)/percent/percent)/prev;
		System.out.printf("%.2f%%",co);
		//两个%%表示一个%，printf中前一个参数传入输出的格式要求。
//		System.out.println("%");
	}

}

```

Java提供的输出包括：``System.out.println()`` / ``print()`` / ``printf()``，其中``printf()``可以格式化输出；

Java提供Scanner对象来方便输入，读取对应的类型可以使用：``scanner.nextLine() / nextInt() / nextDouble() / ...``

## if 条件判断
要判断引用类型的变量内容是否相等，必须使用equals()方法：
```java
public class Main {
    public static void main(String[] args) {
        String s1 = "hello";
        String s2 = "HELLO".toLowerCase();
        System.out.println(s1);
        System.out.println(s2);
        if (s1.equals(s2)) {
            System.out.println("s1 equals s2");
        } else {
            System.out.println("s1 not equals s2");
        }
    }
}

```
** 如果用==进行判断，所实现的过程是：判断s1和s2指向的对象是否是同一个位置。例：若对上述代码进行判断，则返回值为false。因为尽管s1,s2字符串中的内容都是hello，但是他们所在的存储单元并非是同一个，因此报错。

### 小结
- if ... else可以做条件判断，else是可选的；

- 不推荐省略花括号{}；

- 多个if ... else串联要特别注意判断顺序；

- 要注意if的边界条件；

- 要注意浮点数判断相等不能直接用==运算符；

- 引用类型判断内容相等要使用equals()，注意避免NullPointerException。

## Switch 语法

switch语句根据switch (表达式)计算的结果，跳转到匹配的case结果，然后继续执行后续语句，直到遇到break结束执行。

### 编译检查


使用IDE时，可以自动检查是否漏写了break语句和default语句，方法是打开IDE的编译检查。


在Idea中，选择Preferences - Editor - Inspections - Java - Control flow issues，将以下检查标记为Warning：

Fallthrough in 'switch' statement
'switch' statement without 'default' branch
### switch表达式
使用switch时，如果遗漏了break，就会造成严重的逻辑错误，而且不易在源代码中发现错误。从Java 12开始，switch语句升级为更简洁的表达式语法，使用类似模式匹配（Pattern Matching）的方法，保证只有一种路径会被执行，并且不需要break语句：
```java
//switch
public class Main {
    public static void main(String[] args) {
        String fruit = "apple";
        switch (fruit) {
        case "apple" -> System.out.println("Selected apple");
        case "pear" -> System.out.println("Selected pear");
        case "mango" -> {
            System.out.println("Selected mango");
            System.out.println("Good choice!");
        }
        default -> System.out.println("No fruit selected");
        }
    }
}

```

### 小结
switch语句可以做多重选择，然后执行匹配的case语句后续代码；

switch的计算结果必须是整型、字符串或枚举类型；

从Java 14开始，switch语句正式升级为表达式，不再需要break，并且允许使用yield返回值。

## while 循环
### 小结
while循环先判断循环条件是否满足，再执行循环语句；

while循环可能一次都不执行；

编写循环时要注意循环条件，并避免死循环。

## Do-while循环
在Java中，while循环是先判断循环条件，再执行循环。而另一种do while循环则是先执行循环，再判断条件，条件满足时继续循环，条件不满足时退出。它的用法是：

```java
do {
    执行循环语句
   } while (条件表达式);
   ```
可见，do while循环会至少循环一次。

## For循环
### 小结
for循环通过计数器可以实现复杂循环；

for each循环可以直接遍历数组的每个元素；

最佳实践：计数器变量定义在for循环内部，循环体内部不修改计数器；

## Break 和 Continue
### break
break语句通常都是配合if语句使用。要特别注意，**break语句总是跳出自己所在的那一层循环**。

例如：
```java
//break
public class Main {
    public static void main(String[] args) {
        for (int i=1; i<=10; i++) {
            System.out.println("i = " + i);
            for (int j=1; j<=10; j++) {
                System.out.println("j = " + j);
                if (j >= i) {
                    break;
                }
            }
            // break跳到这里
            System.out.println("breaked");
        }
    }
}
```
### continue
``break``会跳出当前循环，也就是整个循环都不会执行了。而``continue``则是提前结束本次循环，直接继续执行下次循环。
```java
public class Main {
    public static void main(String[] args) {
        int sum = 0;
        for (int i=1; i<=10; i++) {
            System.out.println("begin i = " + i);
            if (i % 2 == 0) {
                continue; // continue语句会结束本次循环,然后继续做下一个循环
            }
            sum = sum + i;
            System.out.println("end i = " + i);
        }
        System.out.println(sum); // 25
    }
}
```

### 小结
break语句可以跳出当前循环；

break语句通常配合if，在满足条件时提前结束整个循环；

break语句总是跳出最近的一层循环；

continue语句可以提前结束本次循环；

continue语句通常配合if，在满足条件时提前结束本次循环。