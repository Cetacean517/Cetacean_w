# 操作系统
## 成绩考核标准
- 考试
- 平时成绩（考勤）
- 实验成绩
- 平时讨论

# 第一章 操作系统引论
> 主要学习操作系统的四大管理功能
> - CPU
> - 内存
> - I/O设备
> - 外设

操作系统（OS）的定义
- **OS是直接控制和管理计算机硬件、软件资源，合理地对各类*作业*（`例如：打开qq这一动作`）进行调度，以方便用户使用的程序集合**。

OS在计算机中的地位（自底向上）
- 裸机
- 操作系统
- 应用软件

### 1.1 操作系统的目标和作用
1. 操作系统的目标
- 方便性：利用命令，而非使用机器语言
- 有效性：提高系统资源的利用率；提高系统的吞吐量。
- 可扩充性
- 开放性：处理软硬件的兼容问题。

2. 操作系统的作用
- 作为用户和计算机间的接口：`OS处于用户与计算机硬件系统之间`
- 作为计算机系统资源的管理者：`处理机管理、存储器管理、设备管理、文件管理`
- 实现了对计算机资源的抽象

> 用户使用计算机的三种方式：
> - 命令方式
> - 系统调用方式
> - 图标——窗口方式


**作为系统资源的管理者*：
- 执行一个程序前需要将该程序**放到内存中**，才能被CPU处理
- 用 QQ 和朋友视频聊天的过程:
  - Step 1:在各个文件夹中找到 QQ 安装的位置( D :/ Tencent / QQ / Bin )
  - Step 2:双击打开 QQ . exe 
    - `需要把该程序相关数据放入内存`
  - Step 3:QQ程序正常运行 
    - `对应的进程被处理机( CPU )处理 ,找到 QQ.exe 逐层打开文件夹`
  - Step 4:开始和朋友视频聊天 
    - `文件的存放位个程序(可执行需要将摄像头设备分配给进程`

3. 推动操作系统发展的主要动力：
- 不断提高计算机资源利用率（最初）
  - 形成多道批处理系统
- 方便用户
  - 实现人机交互、图形界面
- 器件的不断更新换代
  - 微机OS8位，16位，32位
- 计算机体系结构的不断发展
- 不断提出新的应用需求
  - 实时性：实时系统
  - 多媒体
  - 安全性

### 1.2 操作系统的发展过程
无OS
   1. 人工操作方式
   - 工作方式：
   - 用户：用户是专业人员
   - 输入输出：纸带或卡片
   - 缺点：等待卡带;人工慢
   1. 脱机I/O方式（卡带->磁带）
   - 减少了CPU的空闲时间
   - 提高了I/O速度工作方式

有OS

1. 批处理系统
- 用户使用系统提供的作业控制语言来描述自己对作业运行的控制意图，并将这些控制信息连同作业一起提交给计算机。
- 由OS去控制、调度各作业的运行并输出结果
- 由于作业进入系统后用户不在干预，从而提高了效率。
- 优点：**提高系统资源的使用效率；提高作业吞吐量**。

2. 单道批处理系统
- 一次运行一个作业；一个一个连着完成
- 缺点：CPU没有被充分利用

3. 多道批处理系统

多道程序设计的基本概念 [p7 图1-6 重要!!] 
  - 在多道批处理系统中,用户所提交的作业都先存放在外存上并排成一个队列,称为“**后备队列**”;
  - 然后,由作业调度程序**按一定的算法**从后备队列中选择若干个作业调入**内存**,使它们共享 CPU 和系统中的各种资源
  
主要优点：
- 多道程序**并发**执行，**共享**计算机资源。**资源利用率**大幅提升，CPU和其他资源更能保持“忙碌”状态，**系统吞吐量增大**。

主要缺点：
- **平均周转时间长**`（需要排队一次处理）`
- **没有人机交互功能**

**多道批处理系统需要解决的问题（了解）：*
- 处理机争用问题：满足运行，同时提高利用率
- 内存分配和保护问题
- I/O设备分配问题
- 文件的组织和管理问题：如何读写文件，关于权限。
- 作业管理问题
- 用户和系统的接口问题

#### 1.2.4 分时系统
- 一台计算机连接多个终端,用户通过各自的终端把作业送入计算机;计算机又通过终端向各个用户报告其作业的运行情况。
- 计算机以**时间片**为单位**轮流为各个用户/作业服务**
- 终端用户服务,并能及时地对用户服务请求予以响应
- 目标：
  - 对用户的请求及时响应；
  - 尽量提高系统资源的利用率

分时系统的引入
- 人机交互（边运行边调试）
- 共享主机（设备昂贵）

分时系统实现中的关键问题
- 及时接收
- 及时处理

分时系统的特征
- 多路性：即同时性，宏观上同时，微观上轮流
- 独立性：每个用户感觉独占主机
- 及时性：较短时间响应（1-3秒）
- 交互性：用户请求多方面服务

#### 1.2.5 实时系统
- **及时**响应，在**规定时间内**处理

实时系统的类型
- 工业（武器）控制系统
- 信息查询系统

实时任务的类型
- 按周期性划分
  - 周期性实时任务
  - 非周期性实时任务
    - **开始截止时间**：在某时间以前必须开始执行
    - **完成截止时间**：在某时间以前必须完成
- 按照截止时间划分
  - 硬实时任务
  - 软实时任务

实时系统的特征
- 快速的响应时间
- 有限的交互能力
- 高可靠性

||多路性|独立性|及时性|交互性|可靠性|
|--|----|-----|------|-----|-----|
|批处理系统|无|无|差|差|一般|
|分时系统|多终端服务|有|好|好|可靠|
|实时系统|多路采集、多路控制|有|最好|一般|高度可靠|

#### 1.2.6 微机操作系统的发展
单用户单任务操作系统
- CP/M, DOS
单用户多任务操作系统
- Windows
多用户多任务操作系统
- Linux

### 1.3 操作系统的基本特征
#### 1.3.1 并发 Concurrence
并行与并发
- **并发**：指两个或多个时间在**同一时间间隔**内发生
  - 宏观同时，微观交替
- 并行：指两个或多个事件在**同一时刻**发生
- **注意（重要考点）**
  - 单核CPU同一时刻只能执行一个程序，各个程序只能并发地执行
  - 多核CPU同一时刻可以同时执行多个程序，多个程序可以并行执行。
- **并发性是操作系统一个最基本特性**

> 电脑中，同时运行多个程序是并发。

引入进程
- 进程：在系统中能独立运行并作为资源分配的基本单位，它是由一组机器指令、数据、堆栈等组成的，是一个能独立运行的活动实体。

#### 1.3.2 共享 Sharing
互斥共享方式
- **临界资源：一段时间内，只允许一个进程访问**

同时访问方式
- 允许在一段时间内由多个进程“同时”对资源进行访问。

> 互斥共享方式：同时使用QQ和微信视频，同一时间段内摄像头只能分配给其中一个进程。
> 
> 同时访问方式：同时使用QQ和微信发送文件，宏观上同时发送，微观上交替访问内存

**并发和共享的关系：相辅相成**
- 失去并发性，只有单进程进行，共享性无意义。
- 失去共享性，不允许多个进程访问同一个资源，也无法并发。

#### 1.3.3 虚拟 Virtual
> 一个程序需要放入内存，（创建进程）并给它分配CPU才能执行
- 时分复用技术
- 控分复用技术

#### *1.3.4 异步 Asynchronism
进程的执行不是一贯到底的，系统中并发执行的多道程序“走走停停”，已不可预置的速度向前推进。

### 1.4 操作系统的主要功能
#### 1.4.1 处理机管理功能
- 进程控制
- 进程同步
  - 进程互斥方式：`A访问，B就不能访问`
  - 进程同步方式：`进程间 同步完成`
- 进程通信
- 调度
  - 作业调度
  - 进程调度

#### 1.4.2 存储器管理功能
- 内存分配
  - 静态分配方式
  - 动态分配方式
- 内存保护
- 地址映射
- 内容扩充

#### 1.4.3 设备管理功能
- 缓冲管理
- 设备分配
- 设备处理

#### 1.4.4 文件管理功能
- 文件存储空间的管理
- 目录管理
- 文件的读/写管理和保护

#### *1.4.5 操作系统与用户之间的接口
- 用户接口
- 程序接口

#### *1.4.6 现代操作系统的新功能
- 系统安全
  - 认证技术
  - 密码技术
  - 访问控制技术
  - 反病毒技术
- 网络功能和服务
  - 网络通信
  - 资源管理
  - 应用互操作
- 支持多媒体
  - 接纳控制功能
  - 实时调度
  - 多媒体文件的存储

### 1.5 OS结构设计
#### 1.5.1 传统操作系统结构
##### 1. 无结构操作系统
##### 2. 模块化操作系统结构
- 优点
  - 提高了OS设计的正确性、可理解性和可维护性
  - 容易扩充，增强了OS的可适应性
  - 加速了OS的开发过程
- 缺点
  - 模块及接口划分较困难
  - 从功能上划分模块，未区别共享资源和独占资源
  - 由于管理的差异，...
##### 3. 分层式操作系统结构
- 原理：从资源管理观点出发，划分层次。各层模块间只能是单向调用关系，使模块间的调用变为有序性。
- 优点
  - 功能明确，**调用关系清晰（高层对低层单向依赖）**，有利于保证设计和实现的正确性
  - 易扩充
- 缺点
  - 系统效率低

#### ** 操作系统的运行机制
##### 特权指令vs非特权指令
  - CPU设计和生成的时候就划分了特权指令和非特权指令。
  - 应用程序：只能使用非特权指令。
  - 内核程序：会让CPU执行一些特权指令
    - 例如 内存清零

##### 内核态（核心态、管态） vs 用户态（目态）
- 处于**内核态时**，CPU执行**特权指令**
- 处于**用户态时**，CPU执行**非特权指令**
- * CPU中有一个程序状态字寄存器（PSW），有一个二进制位，1表示“内核态”，0表示“用户态”。
- 内核态、用户态的切换
  - **内核态 → 用户态**
    - 执行一条**特权指令**-- **修改PSW的标志位为“用户态”**
    - = 操作系统主动让出CPU使用权
  - **用户态 → 内核态**
    - 由“**中断**”引发，**硬件自动完成变态过程**。
    - = 操作系统将强行夺回CPU的使用权

#### 1.5.4 操作系统的体系结构
##### 操作系统的内核
- 原语
  - 一种特殊的程序，具有原子性。
  - 这段程序的运行必须一气呵成，不被中断。
- 内核是操作系统最基本、最核心的部分
- 实现操作系统的内核功能的那些程序就是内核程序。

大内核 vs 微内核
> 微内核效率一定比大内核高么？ 
> 不一定。因为微内核会频繁进行变态操作。

微内核的OS结构
- 特点：小而精炼
- 灵活性和可扩充性好
- 可靠性高
- ...

##### 客户/服务器模式
- 优点
  - 充分模块化
  - 减少系统的内存需求
  - 高可移植性
- 缺点
  - 各模块与微内核键通过通信机制交互，系统运行效率较低

##### 微内核的基本功能
- 进程（线程）管理
- 低级存储器管理
- 终端和陷入处理

##### 微内核OS的优缺点
- 优点
  - 提高了系统的可扩展性
  - 增强了系统的可靠性
  - 可移植性强
  - 提供了对分布式系统的支持
  - 融入了面对象技术
- 缺点
  - 运行效率低

##### 中断和异常
- 中断的作用
  - **“中断”是让操作系统内核夺回CPU使用权的唯一途径**
- 中断的类型
  - 内中断：与当前执行的指令有关，中断信号来自于CPU内部
  - 外中断：与当前执行的指令无关，中断信号来自于CPU外部
> 补充：陷入指令（非特权指令）：主动地将CPU控制权还给操作系统内核。
> 
> 内中断案例：
> 案例1：在用户态执行特权指令，引发中断
> 案例2：在用户态执行非法程序，例如除法分母为0，引发中断
> 案例3：在用户态执行陷入指令，引发中断
> 
> 外中断案例：
> 案例1：利用时钟部件，每隔30ms给CPU发送一个时钟中断信号。
> 案例2：I/O中断请求

- 中断机制的基本原理
  - 查询“中断向量表”，来执行对应程序

### **OS接口

#### 系统调用与库函数的区别
- 普通应用程序：系统调用 / 调库函数
- 编程语言：向上提供库函数
- 操作系统：向上提供系统调用。
- 裸机
> 系统调用的必要性：
> - 操作系统内核对共享资源进行统一的管理，并向上提供“系统调用”
> - 否则会出现，两个人同时使用打印机，而输出的内容是两个人需求的混合。
> **与共享资源有关的操作，必须通过系统调用完成**

- 分类：
  - 设备管理
  - 文件管理
  - 进程控制
  - 进程通信
  - 内存控制

#### 系统调用的过程
- 传递系统调用参数
- 执行陷入指令（**用户态**）：产生中断信号，请求系统调用
- 执行响应的内请求核程序处理系统调用（**核心态**）
- 返回

# 第二章 进程的描述与控制
## 2.1 前趋图和程序执行
### 2.1.1 前驱图
- 有向无循环图
- 直接前趋，直接后继
- 前驱关系的表示,书p32
- 禁止循环
### 2.1.2 程序顺序执行
#### 1.程序的顺序执行
#### 2. 程序顺序执行时的特征
- **顺序性**
- **封闭性**：计算结果不受外界影响
- **可再现性**：执行结构与执行速度无关，仅与初值有关

### 2.1.3 程序的并分执行
#### 程序的并发执行
- **不存在前驱关系的程序之间才能并发执行**。

#### 程序并发执行时的特征
- 间断性
- 失去封闭性
- 不可再现性

```
举例：
    程序A ：n = n+1
    程序B ：print(n); n = 0;

可能结果：
  A快B慢： n+1 n+1 0
  B快A慢： n 0 1
  AB间隔： n n+1 0
```


## 2.2 进程的描述
### 2.2.1 进程的定义和描述
- 进程：程序关于某个数据集合的一次执行过程
#### 进程控制块 (PCB) 
- 创建进程的时候，就会创建PCB。放在内存PCB区。
- 内容
  - 记录PID (进程ID), UID (用户ID)
  - 记录进程分配了哪些资源 -> 用于对资源的管理
  - 记录进程的运行情况 -> 对进程的控制、调度
- 作用：PCB是进程存在的唯一标志

##### PCB中的信息（要知道，但不会填空）
- 进程标识符
  - 内/外部标识符
- 处理机状态
  - 通用寄存器、指令计数器、PSW、用户栈指针
- 进程调度信息
  - 进程状态、进程优先级、其他信息、事件（阻塞原因）
- 进程控制信息

##### 进程的实体
- **进程的实体 = PCB + 程序段 + 数据段**
- 进程是进程实体的运行过程。
- 进程是系统进行资源分配和调度的一个独立单位。

##### 进程的特征
- 动态性（基本特性）：动态产生、变化和消亡。
- 并发性
- 独立性：独立运行、获得资源、调度
- 异步性

##### 进程与程序的区别

## 2.3 进程控制
### 2.3.1 概念
#### 如何实现进程控制
- 利用PCB中的state表示：1 = 就绪态， 2 = 阻塞态
- 操作：
  - PCB2中state 设为1
  - 将PCB2从阻塞队列放到就绪队列

#### 如何实现原语的“原子性”
- 利用开关中断

### 2.3.2 进程
#### 进程图（有向图）
#### 进程创建
- 进程创建原语Create()
- 创建过程：
  - -> 申请空白PCB 
  - -> 分配资源 
  - -> 初始化进程控制块 
  - -> 将新进程插入就绪队列

引起进程创建的事件
- 用户登录
- 作业调度
- 提供服务
- 应用请求

#### 进程的终止
终止过程：
  - -> 找出被终止进程的PCB 
  - -> 若进程状态为运行态，置CPU调度标志为真，表示进程终止 
  - -> 若有子孙进程，终止其子孙进程并回收其资源 
  - -> 回收被终止进程的资源 
  - -> 回收被终止进程的PCB

引起进程终止的时间
- 正常结束
- 异常结束
  - 越界错误、非法指令...
- 外界干预
  - Ctrl + Alt + delete
  - 父进程请求
  - 父进程终止

#### 进程阻塞过程
调用阻塞原语block()
- -> 调用阻塞原语

#### 进程唤醒过程
唤醒过程：
- 把阻塞进程从等待该事件的阻塞队列中移出
- 置进程状态为就绪态，将PCB插入到就绪队列中

引起进程阻塞和唤醒的事件
- 请求共享资源失败
- 等待某种操作完成
- 新数据尚未到达
- 新任务尚未到达

#### 进程的挂起和激活
- 调用挂起原语suspend()
进程的挂起过程：


- 调用激活原语actvi

### 小结
- 更新PCB中的信息
  - a. **修改进程状态标志**
  - b. 剥夺当前运行进程的CPU使用权必然需要**保存期运行环境**
  - c. 某进程开始运行前必然要**恢复其运行环境**
- 将PCB插入合适的队列
- 分配/回收资源

## 2.4 进程同步（最重要！！！）
### 2.4.1 基本概念
#### 两种形式的制约关系
进程同步
- 异步性：进程不是一下做完，一步一步进行。
- 同步/直接制约关系：完成某任务后，才能执行。

进程互斥
- 互斥/间接制约关系：多个进程访问某个临界资源需要等待，一个一个访问。（例如：打印机）

#### 临界资源
- 理解资源：一段时间内只允许一个进程访问的资源
- 临界区：每个进程中访问临界资源的那段代码

访问临界区的程序设计：
- 对于访问的临界资源进行坚持
- **进入区**：若此刻未被访问，**设正在访问的标志**
- **临界区**：访问临界资源
- **退出区**：将正在访问的标志恢复为未被访问的标志
- **剩余区**：其余部分

#### 同步机制应遵循的规则
- 空闲让进
- 忙则等待
- 有限等待：等待进程，在有限时间内可以访问。
- 让权等待：进程不能进入临界区时，应立即释放处理机，放置进程忙等待

### 2.4.2 硬件同步机制
#### 关中断

### 信号量机制
- wait(S) = P(S) 申请资源
- signal(S) = V(S) 释放资源

#### 整型信号量
- P操作：< 0 什么都不做；否则-1
- V操作：+1

#### 记录型信号量（重要！！！！）
- P操作：先-1; 再判断 <0 :用block阻塞，使进程从运行态->阻塞态。
  - 因何事阻塞，则因何事唤醒
- V操作：先+1；判断：<=0 :则唤醒

#### AND型信号量
- 一次申请所有的信号量，如果满足则申请，否则不予申请

#### 信号量集
- S：信号量
- t: 下限值
- d: 需求量
- 特殊情况
  - Swait(S,d,d)
  - Swait(S,1,1): 互斥信号量/可控
  - Swait(S,1,0): 可控开关
  
#### 信号量的应用
实现同步
- 设置同步信号量S，初始值为0
- **在"前操作”之后执行V(S)**
- **在"后操作”之前执行P(S)**

```
P1(){
  code 1;
  code 2;
  V(S)    // S++,有资源，给P2放行
  ...
}

P2(){
  P(S);     //先执行到这里，S=0 无可用资源，会被阻塞。
  code 3;
  ...
}
```

实现前驱关系
- 为每一对前驱关系各设置一个同步信号量：0.
- **在"前操作”之后执行V(S)**
- **在"后操作”之前执行P(S)**

### 2.4.5 管程机制
### 条件变量 condition c
- c.wait


## 2.5 经典进程的同步问题
### 2.6.1 消费者-用户问题
#### 记录型信号量
- P操作不可以交换
- V操作可交换

#### AND信号量

#### 总结
- 同步的P操作在前，...

### 2.6.2 哲学家进餐问题
> 5个哲学家，五根筷子。（拥有两根筷子才能进餐）
- 分析
  - 相邻两位不能同时进餐
  - 最多两位同时进餐
- 定义互斥信号量组

### 2.6.3 读写者问题
> 读读共享；写写互斥；读写互斥

#### 记录型信号量

### 例题
例1. B0,B1,B3分别可放3，2，2个消息。初始，B0有3个消息。
每次Pi给Bi传消息（i=1,2,3)
用wait,signal写出P0,P1,P2的同步互斥流程
```
semaphore mutex0 = mutex1 = mutex2 = 1
semaphore full0 = 3 semaphore empty0 = 0
semaphore full1 = 0 semaphore empty1 = 2
semaphore full2 = 0 semaphore empty2 = 2

P0(){
  while(1){
    P(full0);
    P(mutex0);
    取数据;
    V(mutex0);
    V(empty0);
    加工模型;
    P(empty1);
    P(mutex1);
    放入商品;
    V(mutex1);
    V(full1);
  }
}
P1(){
  while(1){
    P(full1);
    P(mutex1);
    取数据;
    V(mutex1);
    V(empty1);
    加工模型;
    P(empty2);
    P(mutex2);
    放入商品;
    V(mutex2);
    V(full2);
  }
}

P2(){
  while(1){
    P(full2);
    P(mutex2);
    取数据;
    V(mutex2);
    V(empty2);
    加工数据;
    P(empty0);
    P(mutex0);
    放数据;
    V(mutex0);
    V(full0);
  }
}
```

例2. 有桥如图,车流如箭头所示,桥上不允许两车交会,但允许同方向车辆通行(即桥上可以有多个同方向的车)用 wait , signal 操作实现交通管理,以防桥上堵塞。
```C
int countSN = countNS = 0       // 南向北，北向南的车计数
semaphore mutexSN = mutexNS = 1 // 
semaphore bridge = 1            // 桥上的互斥信号量
StoN(){
  while(1){
    P(mutexSN);
    if(countSN == 0) // 判断是否是第一辆车
      P(bridge);
    countSN++;
    V(mutexSN);

    过桥...;

    P(mutexSN);      // 要先获取权限
    countSN--;
    if(countSN == 0)  //判断是否是最后一辆
      V(bridge);
    V(mutexSN)
  }
}

NtoS(){
  while(1){
    P(mutexNS);
    if(countNS == 0) // 判断是否是第一辆车
      P(bridge);
    countNS++;
    V(mutexNS);

    过桥...;

    P(mutexNS);      // 要先获取权限
    countNS--;
    if(countNS == 0)  //判断是否是最后一辆
      V(bridge);
    V(mutexNS)
  }
}
```

## 2.6 进程通信
- 低级通信
- 高级通信

### 共享存储器系统
- 基于共享
- 特点：低效，只能传输少量数据

### 管道通信
- 基于共享文件（pipe文件）
- 只能实现单向的传输。（某段时间内）互斥访问
- 管道写满时，写进程被阻塞。读完时，读进程被阻塞；没写完，就不允许写，没读空，就不允许写。
- 读进程最多只有一个，读完就被抛弃。

### 消息传递系统
- 利用原语进行数据发送
- 分类
  - 直接通信方式
  - 间接通信方式
#### 直接通信方式
- Send(Receiver,message)
- Receive(Sender,message)

## 2.7 线程
### 2.7.1 线程引入
- 资源分配、调度
  - 传统：
    - 资源分配、调度的基本单位：进程
  - 引入线程：
    - 资源分配的基本单位：进程
    - 调度的基本单位：线程 
#### 线程的属性

## 2.8 线程的实现
- 应用程序执行，利用线程库
- 线程切换：用户态实现
- 用户：多线程；操作系统：only进程， no线程
- 优点：切换无需变态， 开销小
- 缺点：一个用户级线程被阻塞，整个进程都被阻塞。

### 2.8.1 内核级线程
- 线程管理工作：CPU内核实现
- 线程切换：核心态
- 建立TCB
- 优点：一个线程被阻塞，其他线程可运行
- 缺点：需要进程切换