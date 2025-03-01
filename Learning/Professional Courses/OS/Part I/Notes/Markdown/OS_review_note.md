# 教材
## 第一章
- 操作系统的特性
- 操作系统的定义
- 批处理的优缺点，单多道的区别
- 分时系统：时间片，时间片轮转算法
- 实时系统：硬实时和软实时的区别，截止时间不同
- 操作系统的四大管理功能（要背）：**处理机、存储器、设备、文件**
- 微内核操作系统的优缺点和功能
  - 客户服务器模式
  - 哪些在内核，哪些不在
  - 效率不一定很高
- 中断分类：内外中断
  - 内中断：CPU内部
  - 外中断：CPU外部
  - 系统调用、特权指令和非特权指令（概念、区别、CPU状态）

## 第二章
- 进程的基本状态的转换（发生什么而转换）
- 引入挂起之后的状态
- 无挂起的三种状态
- 进程控制块PCB中保存的信息
- 原语的定义、操作系统的定义、进程的定义
- 进程、处理机调度
- 临界区的概念、同步机制的4个规则
- 硬件同步机制：3种
- 信号量：记录型信量 pv 操作**必考**
  - 读写者、生产者消费者、哲学家进餐 
  - 进入、退出、临界区的概念
- 管程：只有一个进程可以进入管程
- 同步问题：读写者、生产者消费者
- 进程通信的类型
- 进程和程序，进程和线程的区别  （**至少二选一**）；从进程的基本特性分析
- 线程中的几个模型：1对1，1对n,n对n
- 线程的属性：可以并发...

## 第三章
- 处理机调度的层次，哪几种调度，调度的对象时什么，发生的频率
- 处理机调度算法的衡量机制：平均周转时间....
- 处理机调度算法6个：
  - HRRN... （公式要记）
  - 时间片轮转
  - 优先级（静态和动态 简单了解）
  - **多级反馈队列调度算法**
  - 题型：给表格会算
  - 调度机制
- 死锁发生的原因、可抢占资源和不可抢占资源、死锁的定义（书上为准）
- 死锁的必要条件4个
- 死锁的处理方法
  - 银行家方法
  - 安全性状态检测：max, need, allocation, available （必考）
  - 可以参考书31的例题。

# 实验指导书
- 实验3是重点
- shell的基本概念 书上第九章
- shell 无需定义变量类型