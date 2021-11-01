# 第五章 运输层  
## 5.1 运输层协议概述
- 提供应用进程的相互通信
- 第一个端到端的通信层
- 运输层的报文中可以有**多个**应用进程的数据
- 重要功能：分用和复用
- 对数据进程差错检验

### TCP和UDP的可靠性
- TCP可靠信道(Transmission Control Protocol)
  - 管道中运输：无差错、按序、无丢失、无重复
- UDP不可靠信道(User Datagram Protocol)
  - 不保证交付
> 不可靠：只是可能出现无序，重复丢失。不可靠 ≠ 有差错。有差错，指的是内容有误。

### 5.1.3 运输层的端口
- 软件端口
- 硬件端口

#### 分类
- 服务器端
  - 熟知端口/系统端口：
  - 登记端口(1024-49151)
- 客户端(49152-65535)

```
服务端的熟知端口号（要记！！！！）：
FTP(21)、Telnet (23)、SMTP (25)、DNS(53)、TFTP(69)、HTTP(80)、SNMP (161)
```
## 5.2 用户数据报协议UDP
- 端口的功能
- 差错检测

### 优点
- 无连接
- 不需要维持复杂的连接状态表
- 首部仅8个字节
- 传输速率快，不受拥塞干扰

### 面向报文的UDP
> 题目1：从应用层的数据封装在UDP中，发送给IP数据包。需要分片，分成4片。网络层接手时，先接受1和2，再接受3和4。问能否直接拼装？

- 不能。因为重传后标识字段不统一。不可以直接拼装。
> 题目2：一个UDP的数据部分是8192个字节，在以太网上传输要分片么？要的话要分几片？
- 要

### TCP

``` C++
get:
while(1):
{
P(f_out)；
P(s_in);
将数从f取出放入s;
V(f_in);
V(s_out);
}
copy:
while(1):
{
P(s_out)；
P(t_in);
将数从s取出放入t;
V(s_in);
V(t_out);
}
put:
while(1):
{
P(t_out)；
P(g_in);
将数从s取出放入t;
V(t_in);
V(g_out);
}

```

```
/**
 * P、Q、R共享一个缓冲区，P、Q构成一对生产者-消费者，R即为生产者又为消费者，
 * 使用P、V操作实现其同步。
 */

typedef int semaphore;
semaphore mutex=1,empty=n,full=0;

void P()
{
    while(true)
    {
        wait(empty);//如果缓冲区已满，则阻塞
        wait(mutex);
        生产一个产品；
        signal(mutex);
        signal(full);//如果消费者被阻塞，则唤醒消费者
    }
}

void Q()
{
    while(true)
    {
        wait(full);//如果缓冲区为空，则阻塞
        wait(mutex);
        消费者取出一个产品
        signal(mutex);
        signal(empty);//如果生产者已经阻塞，则唤醒生产者
    }
}

void R()
{
    if(empty==n)//执行生产者的功能
    {
        wait(empty);
        wait(mutex);
        生产一个产品；
        signal(mutex);
        signal(full);
    }
    if(full==n)//执行消费者的功能
    {
        wait(full);
        wait(mutex);
        消费者取出一个产品
        signal(mutex);
        signal(empty);
    }
}
```


