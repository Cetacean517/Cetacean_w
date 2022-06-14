# Tips

标准输出 ： sout

for 循环： 6.fori

# Java 内存

## 5个部分

1. 栈 Stack：
   - 存储方法的局部变量。**运行方法一定在栈中。**
   - 局部变量：方法对的参数 / 方法体内的变量。
   - 作用域：一旦超出作用域，立即从栈中消失。
2. 堆 Heap：
   - **存储new 申请得到的东西。**
   - 地址值：16进制；堆内数据均有默认值。

| 类型     | 默认值   |
| -------- | -------- |
| 整数     | 0        |
| 浮点数   | 0.0      |
| 字符     | "\u0000" |
| 布尔     | false    |
| 引用类型 | null     |

3. 方法区 Method Area：存储.class相关信息，包含方法的信息。
4. 本地方法栈 Native Method Stack：与OS相关。
5. 寄存器 pc Register：与CPU相关。

# 数组操作
## 遍历数组
1. 用for循环遍历数组
```java
	public static void main(String[] args) {
		int array[]={1,3,5,7,9,2,3,4};
		for(int i =0;i<array.length;i++)
		{
			System.out.println(array[i]);
		}
	}
```
2. 用for-each遍历数组
   
   for-each每次直接获取数组的值进行迭代，但无法获取数组的引索。
 ```java
 	public static void main(String[] args) {
		String s[]={"A","E","I","O","U"};
		for (String ar:s)
		{
			System.out.print(ar+" ");
		}
	}
 ```
## 打印数组
1. 用for-each进行时数组打印，可以输出想要的数组格式
```java
	public static void main(String[] args) {
		int ns[]={1,2,3,4,2,4,5};
		for(int num:ns)
		{
			System.out.print(num+" ");
		}
	}
```
2. 用java自带的Arrays.toSring类打印，但是会输出"[]"
```java
//Arrays.toString
	public static void main(String[] args) {
		String s[] = {"hello","world","!"};
		System.out.println(Arrays.toString(s));
	}
```

*直接打印数组会获取到数组所在的地址内容。*



## 数组排序

1. 冒泡排序（简单优化）
 ```java
 //优化后的冒泡排序
	public static void main(String[] args) {
		int ns[]={1,2,5,3,6,5,76,4,231,3,2};
		System.out.println("Original Arrays: " + Arrays.toString(ns));
		boolean flag = true;						//冒泡排序优化，用flag判断该轮循环中是否有交换。没有交换则排序已经完成。

		for (int i =0;i< ns.length-1;i++)
		{
			if(flag) {
				flag = false;						//每开始一个新的排序，将flag标志初始化为false.若进入循环才置为true.
				for (int j = 0; j < ns.length - i - 1; j++) {
					if (ns[j] > ns[j + 1]) {
						int temp;
						temp = ns[j + 1];
						ns[j + 1] = ns[j];
						ns[j] = temp;
						flag = true;
					}
				}
			}
			else break;
		}
	}
 ```
 2. Sort排序方法的调用
```java
//Java自带的排序方法sort
	public static void main(String[] args) {
		int ns [] = {1,5,2,3,6,4,5};
		Arrays.sort(ns);
		System.out.println(Arrays.toString(ns));
	}
```

### 小结

常用的排序算法有冒泡排序、插入排序和快速排序等；

冒泡排序使用两层for循环实现排序；

交换两个变量的值需要借助一个临时变量。

可以直接使用Java标准库提供的Arrays.sort()进行排序；

对数组排序会直接修改数组本身。

## ArrayList<E> 可变长数组

支持泛型。

$>$ JDK 1.5自动装箱：基本类型 ---> 包装类型  ; 自动拆箱: 包装类型 --> 基本类型

| 基本类型 | 包装类（引用类型，位于java.lang) |
| -------- | -------------------------------- |
| byte     | Byte                             |
| short    | Short                            |
| int      | **Integer**                      |
| long     | Long                             |
| float    | Float                            |
| double   | Double                           |
| char     | **Character**                    |
| boolean  | Boolean                          |

直接打印：输出内容

常用方法：add(),	get(),	remove() [ 返回删除内容 ],	size() [ 返回元素个数 ]

遍历集合

```java
for (int i = 0; i < list.size(); i++) {
    System.out,println(list.get(i))
}
```

# MAP 集合

## 常用子类

HashMap : 哈希表；存取顺序不一致

LinkedHashMap：哈希表 + 链表；存取顺序一致

Hashtable：key + value 都不能为null；单线程 (properties仍在用)

## 常用方法

put ( key, value ) : key重复，返回新的value；key 不重复，返回空。

get ( key )：获取value；没有值，返回空。

remove (key)：删除value

contiansKey(key)：判断键值是否存在，返回boolean.

keySet()：遍历

entrySet()：遍历

### 遍历Map类型

1. KeySet方法：

迭代器方法

```java
    public static void main(String[] args) {
        Map<String, Integer> map = new HashMap<>();
        map.put("aa",11);
        map.put("bb",22);
        map.put("cc",33);

        // 1. 获取key集合
        Set<String> keySet = map.keySet();
        // 2. 遍历集合获取值
        Iterator<String> iterator = keySet.iterator();
        while(iterator.hasNext()){
            String key = iterator.next();
            Integer value = map.get(key);
            System.out.println(key + "=" + value);
        }
    }
```

增强for循环

```java
    public static void main(String[] args) {
        Map<String, Integer> map = new HashMap<>();
        map.put("aa",11);
        map.put("bb",22);
        map.put("cc",33);

        // 使用增强for循环
        for(String key:map.keySet()){
            Integer value = map.get(key);
            System.out.println(key + "=" + value);
        }
    }
```

2. EntrySet 遍历键值对：

   entrySet(); getKey(); getValue()

## 自定义存储类型

Map集合必须保证key是唯一的：

- 作为KEY的元素，必须重写hashCode方法和equals方法（保证key唯一）
