## Python 实战
### Python 统计单词
#### 把文档读入成str类
读文件:

要以读文件的模式打开一个文件对象，使用Python内置的open()函数，传入文件名和标示符：

```python
>>> f = open('E:\python\python\test.txt', 'r')
```

标示符'r'表示读，这样，我们就成功地打开了一个文件。

如果文件不存在，open()函数就会抛出一个IOError的错误，并且给出错误码和详细的信息告诉你文件不存在：

```python
f=open('E:\python\python\notfound.txt', 'r')
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
FileNotFoundError: [Errno 2] No such file or directory: 'E:\python\python\notfound.txt'
```

如果文件打开成功，接下来，调用read()方法可以一次读取文件的全部内容，Python把内容读到内存，用一个str对象表示：

```python
>>> f.read()
'Hello, python!'
```

最后一步是调用close()方法关闭文件。文件使用完毕后必须关闭，因为文件对象会占用操作系统的资源，并且操作系统同一时间能打开的文件数量也是有限的：

```python
>>> f.close()
```

由于文件读写时都有可能产生IOError，一旦出错，后面的f.close()就不会调用。所以，为了保证无论是否出错都能正确地关闭文件，我们可以使用try ... finally来实现：

```python
try:
    f = open('/path/', 'r')
    print(f.read())
finally:
    if f:
        f.close()
```

每次都这么写实在太繁琐，所以，Python引入了with语句来自动帮我们调用close()方法：

```python
with open('/path/to/file', 'r') as f:
    print(f.read())
```

这和前面的try ... finally是一样的，但是代码更佳简洁，并且不必调用f.close()方法。

 

调用read()会一次性读取文件的全部内容，如果文件有20G，内存就爆了，所以，要保险起见，可以反复调用read(size)方法，每次最多读取size个字节的内容。另外，调用readline()可以每次读取一行内容，调用readlines()一次读取所有内容并按行返回list。因此，要根据需要决定怎么调用。

如果文件很小，read()一次性读取最方便；如果不能确定文件大小，反复调用read(size)比较保险；如果是配置文件，调用readlines()最方便：
```python
for line in f.readlines():
    print(line.strip()) # 把末尾的'\n'删掉
```

### 基于值得内存管理方式
#### 整数
```python
# 对于不在-5~256内的整数，不会做数据的缓存。因此，对于不同变量赋相同值变量地址不同。反之相同。
>>> a = -6
>>> b = -6
>>> id(a)
1967091588592
>>> id(b)
1967091588624
>>> x = 10
>>> y = 10
>>> id(x)
1967073552976
>>> id(y)
1967073552976
```
#### 实数
- Python不会对实数进行换成
- 交互模式下同值不同名的变量不共用同一个内存空间

### map()
#### 描述
map() 会根据提供的函数对指定序列做映射。

第一个参数 function 以参数序列中的每一个元素调用 function 函数，返回包含每次 function 函数返回值的新列表。

#### 语法
map() 函数语法：

map(function, iterable, ...)

#### 参数
function -- 函数
iterable -- 一个或多个序列

#### 返回值
Python 2.x 返回列表。

Python 3.x 返回迭代器。

#### 实例
```python
>>> def square(x) :         # 计算平方数
...     return x ** 2
...
>>> map(square, [1,2,3,4,5])    # 计算列表各个元素的平方
<map object at 0x100d3d550>     # 返回迭代器
>>> list(map(square, [1,2,3,4,5]))   # 使用 list() 转换为列表
[1, 4, 9, 16, 25]
>>> list(map(lambda x: x ** 2, [1, 2, 3, 4, 5]))   # 使用 lambda 匿名函数
[1, 4, 9, 16, 25]
>>>
```