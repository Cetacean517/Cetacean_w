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