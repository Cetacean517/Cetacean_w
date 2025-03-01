# Digital Logic

## 基础

### 二进制 八进制 十进制 十六进制 相互转化

#### 十进制和其他进制的相互转换

1. 其他进制转换为十进制：

   > 各进制数按权展开并相加

2. 十进制转换为其他进制：

   > 1. 整数：除以基数取余，直到商为零，逆序
   > 2. 小数：乘以基数取整， 顺序

#### 二进制 八进制 十六进制 的相互转换

> 以小数点为界向两侧划分，按基数划分组，不够则补零

### 8421BCD 码与十进制之间的转换

> 8421

### 十进制与 原码 反码 补码 之间的转换

> 符号位 0，正数反码补码和原码相同
> 符号位 1，负数反码数值取反，补码在反码最低有效位上加一

### 校验法

1. 奇偶校验码:可以验证传输过程是否产生了错误
   1. 奇校验:为二进制添加一位校验码，使 1 的数量为奇数
   2. 偶校验:为二进制添加一位校验码，使 1 的数量为偶数
2. 海明码：传输过程中错一位概率大，通过海明码可以验证是哪位出错

## 逻辑代数

### 逻辑代数运算法则

#### 逻辑运算

1. $F=A+B~~~(F=A\wedge B)$
   | A | B | F |
   | :-- | :-- | --: |
   | 0 | 0 | 0 |
   | 0 | 1 | 1 |
   | 1 | 0 | 1 |
   | 1 | 1 | 1 |
2. $F=A\cdot B~~~(F=A\vee B)$
   | A | B | F |
   | :-- | :-- | --: |
   | 0 | 0 | 0 |
   | 0 | 1 | 0 |
   | 1 | 0 | 0 |
   | 1 | 1 | 1 |
3. $F=\overline A$
   | A | F |
   | :-- | --: |
   | 0 | 1 |
   | 1 | 0 |

#### 基本定律

|     |                                                |                                         |
| :-- | :--------------------------------------------- | :-------------------------------------- |
| 1   | $A+B=B+A$                                      | $AB=BA$                                 |
| 2   | $A+(B+C)=(A+B)+C$                              | $A(BC)=(AB)C$                           |
| 3   | $A+(BC)=(A+B)(A+C)$                            | $A(B+C)=AB+AC$                          |
| 4   | $A+0=A , A+1=0$                                | $A \cdot 1=A , A \cdot 0=0$             |
| 5   | $A+\overline A =1$                             | $A \cdot \overline A  =0$               |
| 6   | $A+A=A$                                        | $A \cdot A=A$                           |
| 7   |                                                | $\overline{\overline A}=A$              |
| 8   | $\overline{A+B}=\overline A \cdot \overline B$ | $\overline{AB}=\overline A+\overline B$ |

#### 代入规则

#### 反演规则

$$
F\left\{
   \begin{aligned}
      1\Longleftrightarrow 0 \\
      +\Longleftrightarrow \bullet \\
      A \Longleftrightarrow \overline A
   \end{aligned}
\right\}\overline F
$$

#### 对偶规则

$$
F\left\{
   \begin{aligned}
      1\Longleftrightarrow 0 \\
      +\Longleftrightarrow \bullet
   \end{aligned}
\right\} F'
$$

#### 常用公式

### 逻辑函数标准形式

1. 最小项及标准与或式

   最小项:**与项**包含全部 n 个变量，全部以原变量或反变量的形式出现，且只出现一次

   例如:$A\overline{B}C$

   函数简写作:$\sum{m(0,1,2,3\dots)}$

2. 最大项及标准或与式

   最大项:**或项**包含全部 n 个变量，全部以原变量或反变量的形式出现，且只出现一次

   例如:$A+\overline{B}+C$

   函数简写作:$\prod{M(0,1,2,3\dots)}$

3. 两者转换

   1. 代数转换法
      1. 转换到最小项之和
         1. 转换为一般与或式
         2. 将非最小项拓展到最小项
      2. 转换到最大项之积
         1. 转换为一般或与式
         2. 将非最大项转换到最大项
   2. 真值表转换法
      - 1:$\sum{m(0,2,4,6\dots)}$
      - 0:$\prod{M(1,3,5,7\dots)}$

### 逻辑函数化简

1. 代数化简化

   - 与或
     - 并项法$AB+A\overline{B}=A$
     - 吸收法$A+AB=A$
     - 消去法$A+\overline{A}B=A+B$
     - 配项法$A\cdot{1}=1,A+\overline{A}=1$
   - 或与
     - 定理法
     - 求偶得到$F'(与或)$化简再求偶得到 F

2. 卡诺图简化

   | $_{AB}\\^{CD}$ | 00                           | 01                           | 11                | 10                           |
   | -------------: | :--------------------------- | :--------------------------- | :---------------- | :--------------------------- |
   |             00 | $\overline{ABCD}$            | $\overline{A}B\overline{CD}$ | $AB\overline{CD}$ | $A\overline{BCD}$            |
   |             01 | $\overline{ABC}D$            | $\overline{A}B\overline{C}D$ | $AB\overline{C}D$ | $A\overline{BC}D$            |
   |             11 | $\overline{AB}CD$            | $\overline{A}BCD$            | $ABCD$            | $A\overline{B}CD$            |
   |             10 | $\overline{AB}C\overline{D}$ | $\overline{A}BC\overline{D}$ | $ABC\overline{D}$ | $A\overline{B}C\overline{D}$ |

- $~AB+A\overline{B}=A$
- $\overline{A}B\overline{C}+\overline{A}BC+AB\overline{C}+ABC=B\overline{C}+BC=B$

1. 卡诺圈尽量大
2. 卡诺圈个数尽量少
3. 每个 1 可以被多个卡诺圈包含

## 组合逻辑电路

### 逻辑门

1. 与门

   符号：$^A_B{\large=}\boxed{\&}\!\!-\!\!{\small F}$

   表达式：$F=A \cdot B$

2. 或门

   符号：$^A_B{\large=}\boxed{\geq{1}}\!\!-\!\!{\small F}$

   表达式:$F=A+B$

3. 非门

   符号：$A{\large-}\boxed{1}{\normalsize\circ}\!\!-\!\!{\small F}$

   表达式:$F=\overline A$

4. 复合逻辑门

   1. 与非门

      符号:$^A_B{\large=}\boxed{\&}{\normalsize\circ} \!\!-\!\!{\small F}$

      表达式:$F=\overline{AB}$

   2. 或非门

      符号:$^A_B{\large=}\boxed{\geq{1}}{\normalsize\circ} \!\!-\!\!{\small F}$

      表达式:$F=\overline{A+B}$

   3. 与或非门

      表达式:$F=\overline{AB+CD}$

   4. 异或门

      符号:$^A_B{\large=}\boxed{={1}} \!\!-\!\!{\small F}$

      表达式:$F=A\oplus{}B=A\overline{B}+\overline{A}B$

      > 同或运算:$F=A\odot{}B=AB+\overline{AB}$

5. 根据输入逐级写出输出
6. 化简逻辑功能
7. 列出真值表
8. 讨论功能

### 逻辑函数实现

$$
\begin{aligned}
   F(A,B,C)=AB+\overline{A}C\\
   =(\overline{A}+B)(A+C)\\
   =\overline{[\overline{(A+C)}+\overline{\overline{(A}+B)}]}\\
   =\overline{(A\overline{B}+\overline{A}~\overline{})}
\end{aligned}
$$

- 与非
  - 化为最简**与或**式
  - 变换为**与非\*2** 式
- 或非
  - 化为最简**或与**式
  - 变换为**或非\*2**式
- 与或非
  - 化为最简**与或**式
  - 变换为**与或非**式
- 异或(部分才能实现,但简单)

### 组合逻辑电路分析
``组合逻辑电路的输出仅取决于该时刻的电路输入->无记忆``

- 输入标字母
- 从输入端按深度一层层写出逻辑函数
- 用前一层输出代入后一层并继续重复
- 简化逻辑函数,判断合理性
- 列出逻辑电路的真值表
- 判断功能并评价完善

### 组合逻辑电路设计

- 根据逻辑要求构建真值表
- 根据真值表写出逻辑函数
- 将逻辑函数化简并转换成适当形式

### 竞争与冒险

原因:信号传输延迟

> 用输入、输出时序图表示

#### 竞争

竞争:输入信号通过不同途径达到输出端的时间不同(随机过程)

- 非临界竞争:不会产生错误
- 临界竞争:导致逻辑错误

#### 冒险

冒险(**暂时**、**瞬态**现象):输出端的尖脉冲

|                | OUT_EXPECTED | OUT_ERROR |
| :------------- | :----------- | :-------- |
| 静态冒险(偏 1) | 1            | 1-0-1     |
| 静态冒险(偏 0) | 0            | 0-1-0     |
| 动态冒险(偏 1) | 0-1          | 0-1-0-1   |
| 动态冒险(偏 0) | 1-0          | 1-0-1-0   |

1. 代数判别法
   - 从**函数表达式结构**判别
   - 条件:
     1. 如果某变量同时以原变量反变量形式存在
     2. 将其他变量可能的取值代入
     3. 如果出现$x+\overline{x}$或$x\overline{x}$则可能产生冒险
2. 卡诺图判别法
   - 条件:
     1. 画出各**与项**对应卡诺圈
     2. 如果两卡诺圈**相切**(存在共用的相邻最小项)则可能产生冒险

## 同步时序电路

### 结构

- 组合电路
- 储存电路

- 输出函数

  $$Z_i=f_i(x_1,\cdots,x_n,y_1,\dots,y_r),~i=1,\cdots,m$$

- 激励函数

  $$Y_j=g_j(x_1,\cdots,x_n,y_1,\cdots,y_r),~j=1,\cdots,r$$

统一的时钟信号(不能太短)来临后,电路状态才改变,且只有一次。

时钟信号起同步作用

|            |      |           |
| :--------- | :--- | :-------- |
| 信号来临前 | 现态 | $y^{n}$   |
| 信号来临后 | 次态 | $y^{n+1}$ |

### 描述

1. 状态表
2. 状态图

### 触发器

- 储存电路
  - 能储存一位二进制数
- 在任一时刻只处于一种**稳态**

#### R-S 触发器

- 基本型(锁存器)
  - 直接 复位-置位
  - 组成:
    - 交叉耦合或非门
    - 交叉耦合与非门
- 时钟型
  - 4\*与非

空翻现象:由于时钟信号宽度而多次翻转,可由主从触发器(串联)解决

#### D 触发器

为了解决 R-S 触发器输入同为 1 时触发器状态不确定问题

- 单输入端
- 输入信号转换为互补信号

#### J-K 触发器

为了解决 R-S 触发器输入同为 1 时触发器状态不确定问题,同时使触发器有两个输入端

#### T 触发器

JK 端合并为 T 端

### 电路分析

### 电路设计

## 异步时序电路

### 特性

### 脉冲异步分析与设计

### 电平异步分析与设计

#### 电平异步竞争与冒险

## 规模集成电路逻辑设计

### 二进制并行加法器

### 数值比较器

### 译码器

### 多路选择器

### 计数器

### 寄存器

### 只读存储器

### 可编程逻辑阵列

### 可编程阵列逻辑

### 通用阵列逻辑

### 高密度可编程逻辑器件
