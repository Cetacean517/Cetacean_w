# Java核心类
>### 字符串和编码

## 字符串和编码
### String
在Java中，`String`是一个引用类型，它本身也是一个`class`。但是，可以用"..."表示字符串。
```java
//用"..."表示字符串
    String name = "winnie";
```

实际上字符串在`String`内部是通过一个`char[]`数组表示的。
```java
    //用数组表示String字符串
    String s2 = new String(new char[]{'H','e','l','l','o','!'});
```

Java字符串的一个重要特点就是字符串不可变。这种不可变性是通过内部的`private final char[]`字段，以及没有任何修改`char[]`的方法实现的。

```java
public class Main {
    public static void main(String[] args) {
        String s = "Hello";
        System.out.println(s);
        s = s.toUpperCase();
        System.out.println(s);
    }
}
//
Hello
HELLO
```
??试解释字符串内容是否改变。

### 字符串的比较
区分：`equals()` 和 `==`
- `equals()`比较的是两个字符串的内容；
- `==`比较的是两个字符串的地址。
  
  //当两个字符串内容相同的时候，java编译器在编译期，会自动把所有相同的字符串当做一个对象放入常量池，因此用`==`获得的比较值是相同的。

  ```java
  public class Main{
      public static void main(String[] args){
          String s1 = "hello";
          String s2 = "HELLO";      //若s2 = "hello"则两个输出结果均为true.
          System.out.println(s1==s2);       
          System.out.println(s1.equals(s2));
      }
  }

  //Run
  false
  true
  ```
结论：
  - 两个字符串比较，总是用`equals()`方法。
  - 忽略大小写的比较，使用`equalsIgnoreCase()`方法。

**`String`类搜索子串，提取子串的常用方法：**

**1. 搜索子串的方法**
   - `contains()`方法: 它的方法参数是`CharSequence`是`String`的父类。返回boolean.
   - `indexOf()`方法： 返回第一次子串出现时的引索值（下标）.
   - `lastIndexOf()`方法： 返回最后一次子串出现时的引索值（下标）.
   - `startsWith()`方法： 判断开头，返回boolean.
   - `endsWith()`方法： 判断结尾，返回boolean.
```java
//是否包含子串：
"Hello".contains("ll"); //true
"Hello".indexOf("l"); //2
"Hello".lastIndexOf("l"); //3
"Hello".startsWith("He"); //true
"Hello".endsWith("lo"); //true

```
**2.提取子串的方法**
- substring() 返回提取的字符串。
```java
//提取从引索开始到结尾的子串
"Hello".substring(2);   //"llo"
//截取从引索为2-4的子串
"Hello".substring(2，4);    //"ll"
```

### 去除首位空白字符
1. `trim()`方法：移除字符串首尾空白字符，如\t,\r,\n:

    `trim()`不改变字符串的内容，而是返回了一个新的字符串。
```java
    //trim()
    "\tHello\r\n".trim(); //"Hello"  
```
2. `strip()`方法：去除字符串首尾空白字符，以及unicode编码字符。
   - `stripLeading()`
   - `stripTrailing()`
```java
    //strip()
    "\u3000Hello\u3000".strip();    //"Hello"
    " Hello ".stripLeading(); // "Hello "  末尾加空格？
    " Hello ".stripTrailing(); // " Hello" 开头加空格？
```
3. 判断是否为空和空白字符串
- isEmpty()
- isBlank()

```java
//isEmpty() & isBlank()
"".isEmpty(); // true，因为字符串长度为0
"  ".isEmpty(); // false，因为字符串长度不为0
"  \n".isBlank(); // true，因为只包含空白字符
" Hello ".isBlank(); // false，因为包含非空白字符
```

### 替换子串
1. `replace()`: 根据字符或字符串替换：
```java
String s ="hello";
s.replace('l','w'); //"hewwo",所有的字符'l'被替换为'w'
```
2. `replaceAll()`: 用正则表达式替换：
```java
    s.replaceAll("[\\,\\;\\s]+", ","); // "A,B,C,D"
```

### 分割字符串
1. `split()`方法：传入正则表达式：
```java
String s = "A,B,C,D";
String[] ss = s.split("\\,"); // {"A", "B", "C", "D"}
```

### 凭借字符串
1. `join()`: 用指定的字符串连接字符串数组：
```java
String[] arr = {"A", "B", "C"};
String s = String.join("***", arr); // "A***B***C"
```

### 格式化字符串
1. `formatted()`
2. `format()` 静态方法

传入其他参数，替换占位符，生成新的字符串

```java
public class Main {
    public static void main(String[] args) {
        String s = "Hi %s, your score is %d!";
        System.out.println(s.formatted("Alice", 80));
        System.out.println(String.format("Hi %s, your score is %.2f!", "Bob", 59.5));
    }
}
```
常用的占位符有：

- %s：显示字符串；
- %d：显示整数；
- %x：显示十六进制整数；
- %f：显示浮点数。

不确定的情况，使用%s占位，因为它不代表任何字符类型。

### 类型转化
1. `valueOf()`方法： 把其他类型转换成字符串
```java
String.valueOf(123); // "123"
String.valueOf(45.67); // "45.67"
String.valueOf(true); // "true"
String.valueOf(new Object()); // 类似java.lang.Object@636be97c
```
2. `Integer.parseInt()`方法：  把字符串转换成int类型
```java
int n1 = Integer.parseInt("123"); // 123
int n2 = Integer.parseInt("ff", 16); // 按十六进制转换，255
```
3. `Boolean.parseBoolean()`方法：把字符串转换为boolean类型：
```java
boolean b1 = Boolean.parseBoolean("true"); // true
boolean b2 = Boolean.parseBoolean("FALSE"); // false
```

4. `Integer.getInteger(String)`方法:它不是将字符串转换为int，而是把该字符串对应的系统变量转换为Integer：
```java
Integer.getInteger("java.version"); // 版本号，11
```
### 转化为char[]
String和char[]类型可以互相转换，方法是：
```java
char[] cs = "Hello".toCharArray(); // String -> char[]
String s = new String(cs); // char[] -> String
```
### 字符编码
`Unicode`编码把世界上主要语言都纳入同一个编码，如中文(`GB2312`)，日文(`Shift_JIS`)，韩文(`EUC-KR`)...。

`Unicode`编码需要两个或更多字节表示。

`UTF-8` 编码： 变长编码。（解决英文字符`unicode`编码高字节总是`00`,包含大量英文文本会浪费空间的问题。）

> 例如：
>
> 'A' --> 0x41       1个字节
> 
>  '中'--> 0xe4b8ad   3个字节

#### 手动把字符串转码
```java
byte[] b1 = "Hello".getBytes(); // 按系统默认编码转换，不推荐
byte[] b2 = "Hello".getBytes("UTF-8"); // 按UTF-8编码转换
byte[] b2 = "Hello".getBytes("GBK"); // 按GBK编码转换
byte[] b3 = "Hello".getBytes(StandardCharsets.UTF_8); // 按UTF-8编码转换
```
**注意：转码编译后，返回`byte`类型的数组。**

也可以把该数组转换成String字符串。
```java
byte[]=...
String s1 = new String(b,"GBK"); //按GBK转换
String s2 = new String(b, StandardCharsets.UTF_8); // 按UTF-8转换
```

### 小结
- Java字符串String是不可变对象；

- 字符串操作不改变原字符串内容，而是返回新字符串；

- 常用的字符串操作：提取子串、查找、替换、大小写转换等；

- Java使用Unicode编码表示String和char；

- 转换编码就是将String和byte[]转换，需要指定编码；

- 转换为byte[]时，始终优先考虑UTF-8编码。

## JavaBean
JavaBean 是一种class,

它符合规范：
- 若干`private`实例字段；
- 通过`public`方法来读写实例字段。

读方法 （`getter`) + 写方法 (`setter`) = 属性
```java
// getter method
public Type getXyz()
public boolean isXyz()
// setter method
public Type setXyz(Type data)
public boolean serXyz(boolean data)

```

只读属性：只有`getter`, 无`setter`; 只写属性(不常用)： 只有`setter`.

### JavaBean的作用
传递数据，便于被IDE工具分析。
idea的快捷键： Alt + Ins(F12键) 可以直接插入getter & setter methods

### 枚举JavaBean属性
使用Java核心库提供的`Introspector`
```java
    public static void main(String[] args) throws IntrospectionException {
        //Introspector use
        BeanInfo beanInfo = Introspector.getBeanInfo(Bags.class);
        for (PropertyDescriptor pd: beanInfo.getPropertyDescriptors())
        {
            System.out.println(pd.getName());
            System.out.println(" " + pd.getReadMethod());
            System.out.println(" " + pd.getWriteMethod());
            //System.out.println(" " + pd.getPropertyType());
        }
    }

    class Bags {
        private int number;
        private String brands;

        public void setBrands(String brands) {
            this.brands = brands;
        }

        public String getBrands() {
            return brands;
        }

        public int getNumber() {
            return number;
        }

        public void setNumber(int number) {
            this.number = number;
        }
    }
```

## 枚举类
### 常量定义
java中可以用`static final`来定义`string`类型和`int`类型常量。

但使用中会遇到问题：编译器无法自动检测某个值是否在枚举集合内。

```java
public class Weekday {
    public static final int SUN = 0;
    public static final int MON = 1;
    public static final int TUE = 2;
    public static final int WED = 3;
    public static final int THU = 4;
    public static final int FRI = 5;
    public static final int SAT = 6;
}

if (weekday == 6 || weekday == 7) { //weekday中没有定义7，但是编译不报错
    if (tasks == Weekday.MON) {
        // TODO:
    }
}
```

### enum 
enum 样例：
```java
//enum
public class Main {
    public static void main(String[] args) {
        Weekday day = Weekday.SUN;
        if (day == Weekday.SAT || day == Weekday.SUN) {
            System.out.println("Work at home!");
        } else {
            System.out.println("Work at office!");
        }
    }
}

enum Weekday {
    SUN, MON, TUE, WED, THU, FRI, SAT;
}
```
使用的好处：

- `enum`本身带有类型信息：`weekday.Sun`是`Weekday`类型。
- 不可能引用到非枚举的值。（因为无法通过编译）
- 不同类型的枚举不能相互比较或者赋值。

###  enum的比较
 `enum`定义的枚举类是一种引用类型。要使用`equals()`方法比较。
> 区别 `==`比较和`equals()`比较方法：
> `==`方法：比较两个引用类型的变量是否是同一个对象。
> `equals()`方法：比较两个应用类型的变量内容是否相同。

*`enum`类型的每个常量在JVM中只有唯一实例，所以可以用`==`直接比较*

### enum类型
`enum`定义的枚举类和其他`class`没有任何区别。

`enum`类型具有的特点：
- 定义的`enum`类型总是继承自`Java.lang.Enum`,且无法被继承
- 只能定义出`enum`的实例，而无法通过`new`操作费创建`enum`的实例
- 定义的每个实例都是引用类型唯一的实例
- 可以将`enum`类型用于`switch`语句


功能函数：

- name() ： 返回常量名
```java
String s = Weekday.SUN.name(); // "SUN"
```
- ordinal() ： 返回定义的常量的顺序，从0开始计数
``` java
int n = Weekday.Mon.ordinal();  //1 输出结果和顺序有关。
```
若要解决受顺序影响输出结果的问题，可以通过定义`private`的构造方法，因为`enum`本身是`class`。
```java
public class Main {
    public static void main(String[] args) {
        Weekday day = Weekday.SUN;
        if (day.dayValue == 6 || day.dayValue == 0) {
            System.out.println("Work at home!");
        } else {
            System.out.println("Work at office!");
        }
    }
}

enum Weekday {
    MON(1), TUE(2), WED(3), THU(4), FRI(5), SAT(6), SUN(0);

    public final int dayValue;

    private Weekday(int dayValue) {
        this.dayValue = dayValue;
    }
}
```
- `toString()` ： 会返回和`name()`一样额字符串，但是`toString()`可以被复写`Override`。目的是使输出更具可读性。

### 小结
小结
- Java使用enum定义枚举类型，它被编译器编译为final class Xxx extends Enum { … }；

- 通过name()获取常量定义的字符串，注意不要使用toString()；

- 通过ordinal()返回常量定义的顺序（无实质意义）；

- 可以为enum编写构造方法、字段和方法

- enum的构造方法要声明为private，字段强烈建议声明为final；

- enum适合用在switch语句中。

## 记录类

### 不变类
特点：
- 定义class的时候使用`final`， 无法派生子类；
- 每个字段使用`final`，保证创建实例后无法修改任何字段。

### record
```java
public record Point(int x, int y) {}
```

功能：可以一行写出一个不变类。

包含：
- `final`修饰class和每个字段。
- 构造方法，和字段名同名的方法。
- 覆写`toString()`, `equals()`,`hashCode()`方法。

我们不能直接从`Record`派生，只能通过`record`关键字由编译器实现继承。

- 可以编写Compact Constructor对参数进行验证
```java
public final class Point extends Record {
    public Point(int x, int y) {
        // 这是我们编写的Compact Constructor:
        if (x < 0 || y < 0) {
            throw new IllegalArgumentException();
        }
        // 这是编译器继续生成的赋值代码:
        this.x = x;
        this.y = y;
    }
    ...
}
```
- 可以定义静态方法

### 小结
从Java 14开始，提供新的record关键字，可以非常方便地定义Data Class：

- 使用record定义的是不变类；

- 可以编写Compact Constructor对参数进行验证；

- 可以定义静态方法。