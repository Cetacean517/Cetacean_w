# 第三章 数据链路层
> 重点：3.3 3.6 3.7

## 3.1 数据链路层的基本概念
- 链路 link
- 数据链路 data link
- 数据链路层的简化模型
### 数据链路层的主要功能
- 链路管理
- 封装成帧
- 浏量控制
- 差错控制
  - 纠错：接收方改错。
  - 检错：检错，然后忽略/重传。
- 将数据和控制信息区分开
- 透明传输
- 寻址

## 3.2 组帧
- 组帧：在一段数据的前后分别添加首部和尾部
- 目的：使接收方能准确识别帧的边界（**帧定界**）

### 帧定界（帧同步）的方法
- 字节计数法
- 字符填充法
- 比特填充法
- 违法编码法
#### 1. 字节计数法
- 思想：在帧头设置一个长度域，放置该帧的字节数，当收方收到帧后，通过帧的长度，确定帧的开始。
- 问题：长度域错误，帧同步完全丢失。

#### 2. 字符填充法（掌握）
- 思想：使用特殊ASCII字符，作为首尾定界。
- 问题：如果出现与帧定界符一样的字符，产生区分结束点问题。
- 解决：数据段中的所有字符前，新增填充字符
- 缺点：传输二进制比特不变
```
Start of Header 0x01
End of Transmission 0x04
ESC 0x1B

例：以SOH为开始帧定界符，EOT为结束帧定界符。
SOH // ESC A / ESC A / ESC SOH / ESC C / ESC EOT / ESC ESC // EOT
```
#### 3. 比特填充法（掌握）
- 思想：
  - 以特殊比特模式01111110作为起始和结束标志
  - 发送方边发边查，每连续5个1后，插入0（修改）
  - 接受方边收边查，每联系5个1后，删除0（还原）
- 优点：通用性强

```
例：发送数据
1. 01011111 -> 010111110  //以5个1结尾，要加0
2. 01111100 -> 011111000  //只有5个1，也要加0
```
#### 4.违法编码法
- 思想：若物理截止上由荣誉码字，利用冗余定界。

## 3.3 差错控制
- 前向纠错
- 自动重发请求
- 若发送信息丢失，接收端收不到？
  - -> 发送端引入计数器，计时器时间到期，仍为收到应答。则默认丢失，进行重发。
- 若多发怎么办？ 
  - -> 为避免相同帧多次接收，对帧进行编号。
- 差错如何发现？
  - 检错码：奇偶校验码，CRC（CRC必考）
  - 纠错码：海明码（汉明码）

### 3.3.1 差错控制技术
#### 前向纠错 FEC - Forward Error Correction
- 应用：航天/航空， 没有反向信道或反向传输时间很长的场合
- 优点；实时性好
- 缺点：传送效率低

#### 自动重复请求 ARQ – Automatic Repeat reQFHuest
- 优点：设备简单，只重复无纠错
- 缺点：信息传递连贯性差

### 3.3.2 差错编码技术
#### 差错编码
- 差错编码：数据块中插入冗余信息的过程
- 思想：使数据块中的比特信息形成管理，进行判断

#### 检错码
- 构造
  - 检错码 = 信息位 + 冗余校验位
  - 码字长 n = K (信息位位数) + r (校验位位数)
  - 编码效率 R = K / n

#### 1. 奇偶校验码
- 奇校验：码字中'1'为奇数个。
- 偶校验：码字中'1'为偶数个。
- 奇偶校验码：
  - 水平奇/偶校验码
  - 垂直奇/偶校验码
  - 水平垂直奇/偶校验码（方阵校验）

##### 水平奇/偶校验
- 编码效率： Q/(Q+1) (信息字段占Q个比特)
- 应用：
  - 异步传输：偶校验
  - 同步传输：奇校验

##### 垂直奇/偶校验
```
0111001|
0010101|
0101011|
1010101|
0101101 //校验位
```
- 编码效率：PQ/P(Q+1) （假设信息分组占Q行P列）

##### 水平垂直奇/偶校验
- 编码效率：PQ/(P+1)(Q+1) （假设信息分组占Q行P列）

#### 2. 循环冗余码 CRC Cyclic Redundancy Check
> - 使用最广泛的检错码
> - 漏检率低，实现简单
- 思想：
  - 发送方，接收方实现约定一个除数K
  - 约定发送数据能被K整除
  - 接收方检测，若被K整除，则无差错；反之，出错。
- CRC（多项式编码）：每一串0和1，都和对应多项式的系数。
  - 101101 $\rightleftarrows {x^5 + x^3 + x^2 + 1}$


##### 冗余码的计算
- 除数：生成多项式P（确定的）
- 被除数：在数据位后面添加n个0，其中n是生成多项式位数-1(即最高幂次)
- 除法：做二进制除法，把减法当做模二加法，不进位。
- 冗余码：即余数，位数也是n位。把余数作为冗余码添加上在最后。
- 传输数据：源数据 + 冗余码

##### 发送方用P生成冗余位
- 注意发送的是0 / 1序列，还是多项式

##### 接收方用P进行校验
- T(X) 传输帧多项式 /P(X) 生成多项式 
  - ≠0(除不尽)，则有错（1）
  - =0(除尽)，则无错或漏检（2）
- 漏检
  - 只要选择位数足够的P，可以使得差错的概率足够小。

##### P的确定方法
- 采用国际标准、

##### CRC算法思路
```
1. 已知：信息多项式M(X)，生成多项式P(X)
   求：传送的信息序列
  + 多项式与二进制代码的对应关系
  + 求出余数
    - 根据P(X)得到n 
    - 二进制除法

2. 【求某个比特出错时，接收方能否检验出来
  - 用接收到的序列/生成多项式，看余数是否为0
```

#### 3.信源编码和信道编码
- 信源编码：无失真的压缩信息
- 信道编码

##### 汉明码
- 汉明码属于**信道编码**，是**纠错码**
- 码距（汉明码距离）：不同二进制的位数个数
- 编码系统的码距：整个编码系统中任意两个码字的最小距离。

##### 两个结论
- 如果要检测出d个比特的错，则编码的汉明距离至少为d+1。
- 如果要纠正d个比特的错，则编码集的汉明距离至少因为2d+1。

```
1. 对于3位的汉明码，若要检测出1个比特的错，汉明编码的距离至少为2.（留空间）
  例：000,011,101...都有着不同的含义。如果有一位写错，000变为001，则001并不是有效的汉明编码。因此可以检错。如果只有一位，那么每一个编码都是有效位，则无法检测出错误。
2.（可二分）只有对于存在距离更近的汉明码，才能够实现纠错。
```

##### 发送方冗余位计算
- $2^r >= K + r + 1$

```
若k = 5, 则 r = 4
```

##### 汉明码计算
- 确定校验比特和信息比特的位置
- 将每个信息比特的位置写成2的次幂之和的形式

## 3.4 点对点协议 PPP
### 组成
- 链路控制协议 LCP
- 网络控制协议 NCP

### 透明传输问题
- 字节填充法
- 出现每一个(7D5E = 7E), (7D5D = 7D)

```
编码后数据：
7D 5E EE FE 26 7D 5D 5D 7D 5D 7D 5E
(7E) EE FE 26 (7D) 5D (7D) (7E)
```
-比特填充法

...

## 3.5 使用广播信道的数据链路层
### 局域网的数据链路层
- 特点
- 优点

### 局域网信道分配策略
### 动态分配
- 随机接入
- 受控接入
#### 随机接入
- 适合负载较轻的网络，信道的利用率一般不高，但网络延迟较短
- 应用：以太网和卫星通信
#### 受控接入
- 应用

### 代表性的媒体访问控制方式
CSMA/CD Carrier Sense Multiple Access with Collision Detection(要记！！！！ 会考)
- 真用协议
  - ALOHA协议
  - CSMA/CD 协议
#### CSMA/CD 协议
> 相比ALOHA协议进行优化：
> - 有人发送，要等待，无人发送，可以发送。
> - 但不能完全避免碰撞。
> 例如：从A->B发送数据，数据从A发送的过程中，B端也发送数据，会产生冲突。

##### 如何检测冲突
争用期
- 争用期（碰撞窗口）：2τ 【用于确定最短有效帧长】
- 最短有效帧长：2τ * 带宽 (M bps)
- 无效帧：长度小于最短有效帧长的帧
> 以太网的争用期：51.2μs

##### 检测到碰撞后处理
- 强化碰撞

二进制指数退避算法
1. 令基本退避时间T=2τ （即争用期）；
2. k=min[重传次数，10]； 
3. r=在 [0, 1, …, (2k-1)] 中随机取一个数；
4. 退避时间=rT。
##### 小结
特点
- 先听后讲
- 边讲边听
- 冲突停止
- 随机等待

判断
- CSMA/CD一定可以减少争用型总线上的冲突（×）

#### 以太网的信道利用率
- 参数a= τ (传播时延) / T0 (发送时间)
- T0 = L ( bit 帧长) / C ( bit/s 数据发送速率)
- a越小，利用率越高
- 判断：
  - 当数据率一定时，以太网的连线的长度受到
限制，否则 τ 的数值会太大。
  - 以太网的帧长不能太短，否则 T0 的值会太小，
使 a 值太大。

## 3.6 以太网的MAC层
### 3.6.1 以太网的标准
####  1. IEEE802标准
层次结构
- 物理层
- 数据链路层
  - 逻辑链路控制LLC子层
  - 媒体接入控制MAC子层

#### 2. 适配器的作用
网卡作用
- 进行串行/并行转换。
- 对数据进行缓存。
- 实现以太网协议。
- 在计算机的操作系统安装设备驱动程序。

#### 3. MAC层的硬件地址
- 硬件地址 = 物理地址 = MAC地址
- 网卡地址或网卡标识符常写为：EUI-48
- 网卡检查MAC地址

MAC 帧格式
- 最常用以太网V2的格式
- MAC帧 = 【同步码】（8）+ 目的地址（6）+ 源地址（6）+ 类型 （2）+ 数据字段 （46 -1500）+FCS（4）
  - 类型：标志上一层用的是什么协议
  - 数据字段：最短46 = 64（以太网的最短有效帧）-18（必有）
  - 同步码：实现比特同步
- 无效MAC帧：直接丢弃，无需重传。

最小帧间隔
- 最小间隔为 9.6 μs，相当于 96 bit 的发送时间。

```
格式无需默写，需要知道
```

## 3.7 扩展的以太网
### 3.7.1 局域网互联与互联设备
#### 1. 局域网互联
- 本质：不同的协议层次上实现协议的彼此转换。
- 互联设备
  - 交换机（重点）

##### 物理层设备
中继器（重发器）
- 连接两个同轴电缆以太网，将信号放大整形后，以延伸网络的传输距离。
- 不具有信号通路的选择功能

集线器
- 多个站点连接在同一个总线上。
- 冲突域（碰撞域）：同一时间，仅有一个站发送数据
- 优点：
  - 不同碰撞域的局域网上的计算机能互联互通
- 缺点：
  - 总吞吐量没有提高。
  - 数据率不一致，不能连接。
  - 不能交换。

##### 数据链路层设备
网桥和交换机
- 交换机接口 -> 主机； 网桥接口 -> 网段。

网桥分类
- 固定路由网桥
- 透明网桥（使用最多）
- 源路由网桥

以太网交换机
- 实质：多接口的网桥
- 工作在全双工方式
- 并行性：能同时连通多对接口，使多对主机能同时通信。
- 特点：
  - 即插即用设备，其内部的帧交换表（又称为地址表）是通过自学习算法自动地逐渐建
立起来的。
- 优点：
  - 用户独享带宽，增加了总容量
- 交换方式
  - 存储转发方式
  - 直通方式
- **以太网交换机的自学习功能**
  - 生成树协议STP：解决回路问题


虚拟局域网VLAN
- MAC帧格式：目的地址 + 源地址 + **VLAN标记(4 bytes)** +...
  - VLAN标记：长度/类型 = 802.1Q标记类型(2字节) + 标记控制信息(2字节)
- 优点：
  - 安全性好
  - 网络分段：逻辑分段，与物理位置无关。
  - 灵活性好

## 3.8 高速以太网

