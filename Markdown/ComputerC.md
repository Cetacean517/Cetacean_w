# Principle of Computer Composition
## 1.2 计算机的基本组成
### 冯·诺依曼计算机的特点
1. 计算机由五大部件组成：输入、输出、运算器、控制器、存储器
2. 指令和数据以同等地位存于存储器，可按地址寻访
3. 指令和数据用二进制表示
4. 指令由操作码和地址码组成
5. **存储程序**
6. 以运算器为中心

### 指令格式举例
"[]"表示存储在内存中。

指令都以二进制表示。

指令 = 操作码（指明进行说明操作的编号） + 地址码（储存数据/取出指令的地址）

取数 $\alpha  \qquad  \qquad  \qquad   [\alpha] \rightarrow ACC$ 

存数 $\beta   \qquad  \qquad  \qquad \qquad   ACC\rightarrow [\beta]$ 

### 存储器的基本组成
#### 核心： 存储体 + MAR + MDR

- 存储体 - 存储单元 - 存储元件（0 / 1)
  - 存储单元： 存放一串二进制代码 （每个存储单元赋予一个地址，存储单元按地址寻址）
  - 存储字：存储单元中二进制代码的组合
  - 存储字长：存储单元中二进制代码的位数
- MAR（存储器地址寄存器）：反应存储单元的个数（存放存储单元地址编码）
- MDR（存储器数据寄存器）：反应存储字长
  - /要存入CPU的数据
  - /从存储体取出来的数据
  - /要存入存储体的数据

### 运算器的基本组成及操作过程
#### 核心： ALU + （3个寄存器） ：ACC + X + MQ
#### 累加器型运算器的操作过程
|    | ACC（累加器） | MQ |  X  |
|----|--------------|----| --- |
|加法|     被加数$\\$ 和    |    | 加数|
|减法|     被减数$\\$  差  |    | 减数|
|乘法|     乘积高位    |  乘数$\\$ 乘积低位 | 被乘数|
|除法|     被除数$\\$余数    |  商 | 除数|

#### 1. 加法操作过程
**指令** ： 加 + M

“加”为操作方法是加法，M为加数在内存单元的地址。

|状态|操作|说明|
|---|---|---|
|初态|ACC 被加数|在执行加法前需要先用一条取数指令，把被加数存入ACC|
||$[M] \rightarrow X$|取M中的加数存放到X寄存器中|
||$[ACC]+[M] \rightarrow ACC$|用ALU算逻运算单元完成加法，存入累加器ACC|

#### 2. 减法操作过程
**指令** ： 减 + M

“减”为操作方法是减法，M为减数在内存单元的地址。

|状态|操作|说明|
|---|---|---|
|初态|ACC 被减数|在执行加法前需要先用一条取数指令，把被减数存入ACC|
||$[M] \rightarrow X$|取M中的减数存放到X寄存器中|
||$[ACC]-[M] \rightarrow ACC$|用ALU算逻运算单元完成减法，存入累加器ACC|

### 控制器
#### 核心:  控制单元 CU + (两个寄存器）：PC + IR 
#### 功能
- 解释指令
- 保证指令的按序执行
#### 基本组成
完成一条指令：
- 取指令（要知道指令的地址，指令保存在内存单元中。**在PC中存放指令的地址，用PC取指令存入IR。PC自动指向下一条要执行的指令**）
- 分析指令（取指令的操作码部分进行分析，**控制单元可以从IR中将指令的操作码取出来进行分析**）
- **执行指令 （CU 控制单元：控制器的核心）**

PC（程序计数器）：
- 存放当前欲执行指令的地址
- 具有计数功能（PC） + 1 $\rightarrow$ PC （**使指令可以连续的执行**）

IR（指令寄存器）：
- 存放当前欲执行的指令

CU（控制单元）：控制器的核心
- 发送各种控制信号

#### $ax^2 + bx + c$ 程序的运行过程
- 将程序通过输入设备送至计算机
- 程序首地址 $\rightarrow$ PC (设置从哪条开始)
- 启动程序运行（运行程序，即连续运行多条指令）
- 取指令 PC $\rightarrow$ MAR $\rightarrow$ M $\rightarrow$ MDR $\rightarrow$ IR，(PC) + 1 $\rightarrow$ PC
- 分析指令 OP(IR)[表示指令的操作码] $\rightarrow$ CU ：取数操作 把x取到ACC中
- 执行指令 AD(IR)[表示指令的地址码] $\rightarrow$ MAR $\rightarrow$ M $\rightarrow$ MDR $\rightarrow$ ACC
- 乘法指令...
- 打印结果
- 停机

## 1.3 计算机硬件的主要技术指标
#### 1. 机器字长 ：
- CPU一次能处理数据的位数。（通常与CPU中的寄存器位数有关）
#### 2.运算速度
- 主频/时钟周期（f）: $\quad$ 主时钟的频率（非直接）
  - CPU的时钟周期（T） ：T = 1 / f  $\quad$ 单位： us, ns
- 核数，每个核支持的线程数（非直接）
  - **吉普森法（静/动态使用频率）*
- CPU 执行时间： $\quad$  CPU执行一般程序所占用的CPU时间
  - CPU 执行时间 = CPU的时钟周期数 $\times$ CPU的时钟周期
- CPI： $\quad$ $\quad$ $\quad$  $\quad$ 执行一条指令所需的**平均**时钟周期数
  - CPI = 执行某段程序所需的CPU时钟周期数 $\div$ 程序包含的指令条数 
- MIPS： $\quad$ $\quad$ $\quad$ $\;$  平均每秒执行多少百万条定点指令数 
  - MIPS = 指令数 $\div$ （程序执行时间 $\times 10^6$）
- FLOPS： $\quad$ $\quad$  $\quad \;$ 每秒浮点运算次数 （更科学）
  - FLOPS = 程序中浮点操作次数 $\div$ 程序执行时间（s）

#### 3. 存储容量
**存放二进制信息的总位数**
- 主存容量
  - 存储单元个数 $\times$ 存储字长  
    -  如 $\quad$MAR MDR 容量
    -  $\qquad$ 10 $\quad$ 8 $\quad$ 1K * 8位
  - 字节数 
    - 如$\qquad 2^{13}b = 1 KB$
- 辅存容量
  - 字节数   80GB

## 6.1 无符号数和有符合数

#### 有符号数：

真值： 日常中的数据

机器数： 需要存储3部分： 符号 + 小数点位置 + 数据信息

 其中小数点的位置：为约定的方式给出。没有任何硬件标志

 #### 三种机器数的小结（原码，反码，补码）
 - 最高位为符号位，书写上用“，”（整数）或“ . ”（小数）将数值部分和符号位隔开
 - 对于正数，原码＝补码=反码
 - 对于负数，符号位为1，
   - 补码：其数值部分原码初符号位外每位取反，末位加1
   - 反码：其数值部分原码初符号位外每位取反
 - 补码取原码：其数值部分原码初符号位外每位取反，末位加1

例1： 设机器数字长为8位（其中1位为符号位）。对于整数，当其分别代表无符号数、原码、补码和反码时，对应的真值范围各为多少？

解：
-  无符号: 0-255
-  原码 : -127-127
-  反码 : -127-127
-  补码 : -128-127

例2： 已知[y]补， 求[-y]补

解： 包括符号位在内，每位求反，末位加1.

#### 移码表示法
1. 定义 

[x] 移 = 2^n + x (2^n > x >= -2^n)
 
 x 为真值； n 为真值的位数

 注意：
 - 不论正负，都把真值加上2^n
 - 求法类似补码，但是符号位相反
 - 只有整数，无小数（表示浮点小数中的阶码）

2. 移码 vs 补码
   
设 x = 1100100

- 补码：0,1100100

- 移码：1,1100100

设 x = -1100100

- 补码：1,0011100

- 移码：0,0011100

**移码和补码只相差一个符号位。**

### 定点表示和浮点表示
#### 定点机及小数和整数的表示范围
...

#### 浮点表示
问题
- 为什么引入浮点数表示
- 浮点数表示格式是什么
  - 尾数的符号，长度，格式
  - 阶码的符号，长度，格式
- 用那种机器数格式表示尾数和阶码
- 尾数和阶码基值必须是2么？
- 基值大小对浮点数的影响
  - 大小
  - 表示范围
  - 最大值，最小值
- 为什么引入规格化？怎么规格化？
- 浮点数表示格式标准？
  
为什么引入浮点数表示？
- 简化程序员编程难度
- 扩展数的表示范围

一、浮点表示

N = S * $r^j$    
S 尾数 ； j 阶码 ； r 尾数的基值 (r = 2、4、8、16....)

- S 小数、可正可负
- j 整数、可正可负

例： r = 2 时， N = 11.0101 = $0.110101 * 2^{10}$ 规格化数

1. 机器中浮点数的存储

j: 阶符（1位）+ 阶码数值部分（整数m位） + S: 数符（1-2位） + 尾数的数值部分（小数n位）

2. 表示范围

- 最小负数

- 最大负数

- 最小正数

- 最大正数

上溢 阶码 > 最大阶码    计算出错

下溢 阶码 < 最小阶码    按机器零处理

** 阶码： 控制数的范围

   尾数： 控制数的精度

3. 对浮点数进行规格化
- 作用：尽可能保证数据的精度
- 做法：小数点后面真值最高位为1. 
    - 例: 0.1011 yes
    -    0.001001 no 
- 基值不一样，规格化不一样。
  - 例： r = 4, 尾数最高2位不全为0.

4. 浮点数规格化

尾数左右移动，并配合阶码增减。

|r|类型|操作|
|--|---|---|
|r=2|左规|尾数左移1位，阶码减1|
|r=2|右规|尾数右移1位，阶码加1|
|r=4|左规|尾数左移2位，阶码减1|
|r=4|右规|尾数右移2位，阶码加1|

基值r越大，表示的浮点数的范围越大，个数越多
基值r越大，表示的浮点数的精度降低

5. 机器零
-  `x,xxxx;0.00···0`: 浮点数的尾数为0，不管阶码的值，按机器零处理。

- `1,00···0;x.xx···x`: 阶码等于或者小于所能表示的最小值。
- `0,0000;0.00···0`:  阶码用移码，尾数用补码表示，机器零为：

6.IEEE754

形式： 数符 + 阶码（含阶符） + [ . ] + 尾数 

规定： 
- 尾数必须用规格化表示，即非“0”的有效位最高位为“1”（隐含）。增大了尾数的尾数。尾数域表示的真值：1.M
- 基数固定为2.
- 阶码用移码表示,偏移值为 127 = $2^8 - 1$


||符号位S | 阶码  | 尾数 | 总位数|
|----|-------|-----|----|---------|
|短实数| 1| 8|23|32|
|长实数| 1|11|52|64|
|临时实数|1|15|64|80|

## 6.3 定点运算 p74
### 一、移位运算（拓展）
#### 意义
小数点并不动，数据相对于小数点左右移动。

左移 绝对值扩大
右移 绝对值缩小

####算术移位规则
- 符号位不变 

| |码制|添补代码|
|--|--|-------|
|正数|原码、补码、反码|0|
|负数|原码|0|
||补码|左移 添0|
|||右移 添1|
||反码|1|

#### 算数移位和逻辑移位
算数移位 有符号位的移位 （最高位不参加）

逻辑移位 无符号位的移位（所有数据域都参与移位）

### 二、加减法运算
#### 补码加减法运算的公式
1. 加法
   
   整数   $[x]_补 + [y]_补 = [x + y]_补$ (mod $2^{n+1}$)

   小数   $[x]_补 + [y]_补 = [x + y]_补$ (mod $2$)
2. 减法
   
   整数 $[x - y]_补 = [x]_补 + [-y]_补$ (mod $2^{n+1}$)

   小数 $[x - y]_补 = [x]_补 + [-y]_补$ (mod $2$)

  **补码的加法运算，连同符号位一起相加，符号位产生进位自动丢掉**。

#### 溢出判断
1. 用一位符号位判断溢出
   - 分析： 异号运算 不会发生溢出；同号运算 可能发生溢出
   - 硬件实现： 最高有效位的进位 $\oplus$ 符号位的进位 = 1

2. 两位符号位判断溢出
   $$
   [x]_{补'} = 
   \begin{cases}
   x, & \text{1 > x $\ge$ 0}    \\[3ex]
   x + 4, & \text{-1 $\ge$ x $\gt$ 0 （mod 4）}
   \end{cases}
   $$  

- 判读标准
  - 结果的双符号位相同   未溢出
  - 结果的双符号位不同    溢出    10， xxxx; 01,xxxx
- 最高符号位代表： 真正的符号； 后者代表：溢出部分

   
#### 补码加减法的硬件配置

### 三、乘法运算
#### 计算机中二进制乘法的原理
- 乘法运算可用加和移位实现： n = 4, 加4次，右移4次
- 乘数末尾决定是否与原部分积相加/加0. 右移之后，高位用乘法结果右移丢失的最低位添补。
- 被乘数只与部分积的高位相加
- 3个寄存器，2个具有移位功能

#### 原码的乘法
1） 原码一位乘运算规则：符号位进行 $\oplus$ ，小数部分取绝对值进行计算

2）原码一位乘递推公式：部分积进行逻辑右移，其余类似乘法运算公式的操作。

特点：
1. 绝对值运算
2. 移位过程中，采取逻辑移位，左侧补零。
3. 用移位次数判断乘法是否结束，n次加法,n次移位。

#### 计算机中的除法运算
- 符号单独处理，剩余部分做除法；
- 被除数不为0， 为0时，直接判断= 0；
- 小数除法的结果仍为小数；整数除法结果＞1

#### 除法运算方法
1） 恢复余数法
- 余数为正 上商 1
- 余数为负 上商 0，恢复余数
  
2） 加减交替法（不恢复余数法）
- 余数为正 上商 1   余数左移 $+ [-|y|]_补$
- 余数为负 上商 0   余数左移 $+ [|y|]_补$

特点：
- 上商 n + 1 次
- 第一次上商判溢出
- 移n次，加 n + 1 次

## 7.1 机器指令
### 一、指令的一般格式
#### 操作码字段（地址可以分开存放） + 地址码字段

#### 1. 操作码：
反映机器对什么类型的数据，做什么操作。指明操作数的寻址方式。
   - 长度固定：用于指令字长较长的情况 （译码操作方便）
   - 长度可变：操作码分散在指令字的不同字段中
   - 扩展操作码技术：操作码位数随地址数的减少而增加
     - 保留扩展标志的扩展方式。
     - 例：指令格式：$OP + A_1 + A_2 + A_3$ ，其中OP 和 $A_i$都为4位。OP可以由（0000~1110）表示，此时三地址指令操作码共15种。）OP = 1111时，$A_1$ = （0000~1110），可表示15种二地址码指令。以此类推...
   - 短操作码一般表示常用指令，长操作码一般表示非常用指令。

#### 2.地址码
1. 四地址： $OP + A_1 + A_2 + A_3 + A_4$
   - $A_1$ 第一操作数地址
   - $A_2$ 第二操作数地址
   - $A_3$ 结果的地址
   - $A_4$ 下一条指令地址
  
    $(A_1)OP(A_2) \rightarrow A_3$， 共4次访存（取指令+取两个操作数+存放结果）

    设指令字长为32 位，操作码固定8位，则寻址范围$2^6 = 64$。范围过小。

2. 三地址： $OP + A_1 + A_2 + A_3$
   - $A_1$ 第一操作数地址
   - $A_2$ 第二操作数地址
   - $A_3$ 结果的地址
   - *$A_4$ 用PC代替
  
    $(A_1)OP(A_2) \rightarrow A_3$， 共4次访存

    设指令字长为32 位，操作码固定8位，则寻址范围$2^8 = 256$。

3. 二地址： $OP + A_1 + A_2$
   - $A_1$ 第一操作数地址
   - $A_2$ 第二操作数地址
   - *用$A_1 / A_2$ 代替 $A_3$ 结果的地址
   - *$A_4$ 用PC代替 
  
     $(A_1)OP(A_2) \rightarrow A_1$ 
    
    或  $\quad (A_1)OP(A_2) \rightarrow A_2$， 共4次访存

    设指令字长为32 位，操作码固定8位，则寻址范围$2^{12} = 4K$。

4. 一地址： $OP + A_1$
   - $A_1$ 第一操作数地址
   - *$A_2$ 第二操作数地址默认保存在内存中的某个位置（例如 ACC）
   - *用$A_1 / A_2$ 代替 $A_3$ 结果的地址
   - *$A_4$ 用PC代替 
  
     $(ACC)OP(A_1) \rightarrow ACC$ ， 共2次访存（对于ACC的操作，不需要访存，省去两次）

    设指令字长为32 位，操作码固定8位，则寻址范围$2^{24} = 16M$。

5. 零地址： $OP$

例如： 
- 给ACC清零（ACC可以隐含取值）
- 给ACC中数据取反
- 停机指令

### 二、指令字长
#### 决定因素：
- 操作码的字长
- 操作码地址的长度
- 操作码地址的个数

#### 1. 指令字长固定
   
指令字长 = 储存字长

#### 2. 指令字长可变
按字节的倍数变化

## 7.2操作数类型和操作种类
### 一、操作数类型
地址 $\qquad$ 无符号整数

数字 $\qquad$ 定点数、浮点数、十进制数

字符 $\qquad$ ASCII

逻辑数  $\quad$ 逻辑运算

### 二、数据在存储器中的存放方式
#### 字节编址，数据在存储器中的存放方式
  - 从任意位置开始存储
    - 优点：不浪费存储空间
    - 缺点：所有类型的数据都要浪费两个存储周期的时间。读写控制复杂
  - 从一个存储字的起点位置开始访问
    - 优点：无论访问何种类型数据，均可在一个周期内完成，读写控制简单。
    - 缺点：浪费存储资源。
  - 边界对准方式：从地址的整数倍位置开始访问

### 三、操作类型
#### 1. 数据传送
类型：
||||||
|--|--|--|--|--|
|源  |寄存器 |寄存器 |存储器|存储器|
|目的|寄存器|存储器 |寄存器| 存储器|
|类型|RR型|RS型|SR型|SS型|
|例如|MOVE |STORE $\\$ MOVE$\\$PUSH |LOAD$\\$ MOVE$\\$POP|MOVE|

基础操作：

传送 $\qquad$ MOV $\quad\; \;$ 清零 $\qquad$ CLA

存数 $\qquad$ STO $\qquad$ 置1 $\qquad$ SET

取数 $\qquad$ LAD $\qquad$ 进栈 $\qquad$ PUS

交换 $\qquad$ EXC $\qquad$ 退栈 $\qquad$ POP
#### 2.算术逻辑操作
算术运算：

加法 $\qquad$ ADD $\qquad$ 绝对值 $\quad$ ABS

减法 $\qquad$ SUB $\qquad$ 变负 $\qquad$ NEG

乘法 $\qquad$ MUL $\qquad$ 增量 $\qquad$ INC

除法 $\qquad$ DIV $\qquad$ 减量 $\qquad$ DEC

逻辑运算：

与 $\qquad$ AND $\quad$ 测试 $\qquad$ TES

或 $\qquad$ OR $\qquad$ 比较 $\qquad$ COM

非 $\qquad$ NOT $\qquad$ 

异或 $\quad$ XOR $\qquad$ 


#### 3.移位操作
算术移位 $\qquad$ 逻辑移位
循环移位（带进位和不带进位）ROT
#### 4.转移
- 无条件转移 JMP
- 有条件转移 JZ JO JC
- 调用和返回
- 陷阱与陷阱指令（意外事故的终端，由硬件自动完成）
- 输入输出 
  - 入 $\qquad$ 端口中的内容$\rightarrow$ CPU的寄存器
  - 出 $\qquad$ CPU的寄存器$\rightarrow$ 端口中的内容

## 7.3 寻址方式
寻址方式：（找操作数/指令的地址）
- 确定 本条指令的操作数地址
- 确定 下一条要执行指令的指令地址

### 一、指令寻址
#### 顺序寻址 $\quad$ (PC) + 1 $\rightarrow$ PC
#### 跳跃寻址 $\quad$ 由转移指令指出

### 二、数据寻址
形式地址$\quad$ 指令字中的地址

有效地址$\quad$ 操作数的真实地址

约定$\quad$ 指令字长=存储字长=机器字长

格式：
|操作码|寻址特征|形式地址A|
|--|--|--|

#### 1.立即寻址
形式地址A ： 操作数

格式： `OP + # + A`
- \# ：立即数寻址的特征
- A：立即数：可正可负 补码
- 取操作数：取A
- 指令执行阶段访存：0次

#### 2.直接寻址
EA = A $\quad$ 有效地址由形式地址直接给出

格式： `LDA + 寻址特征 + A`
- A：有效地址
- 取操作数：地址A的内存$\rightarrow$ 操作数
- 缺点
  - 操作数的地址不易修改（必须修改A，不利于指令循环）
- 指令执行阶段访存：1次
  
#### 3.隐含寻址
一个操作数的地址隐含在OP（操作数）中

格式： `ADD + 寻址特征 + A`
- A：直接寻址
- 取操作数：
  - 一个操作数：A的直接寻址
  - 另一个操作数隐含在 ACC 中
- 指令字减少了一个地址字段，缩短指令字长
- 指令执行阶段访存：1次

#### 4.间接寻址
EA = (A) $\quad$ 有效地址由形式地址间接提供

格式： `OP + @ + A`

a. 一次间址 
- @ ：间接寻址的特征
- 取操作数：A地址所在内存 $\rightarrow$ 有效地址EA $\rightarrow$ EA地址所在内存 $\rightarrow$ 操作数
- 优点
  - 扩大寻址范围： [A 可以很短，EA可以较长。]
  - 便于编程，可以只修改EA。
- 指令执行阶段访存：2次

a. 多次间址 
- A：包含可以寻找到操作数的中间地址。
- 多次进行一次间址过程。
- 指令执行阶段访存：多次

#### 5.寄存器寻址
EA = R$_i \quad$ 有效地址：寄存器编号

格式： OP + 寻址特征 + R$_i$
- R$_i$：操作数
- 取操作数：寄存器 $\rightarrow$ 操作数
- 优点：
  - 只访问寄存器，执行速度快。
  - 寄存器个数有限，可缩短指令字长。
- 指令执行阶段访存：0次
  
#### 6.寄存器间接寻址
EA = (R$_i) \quad$ 有效地址：寄存器编号。

格式： OP + 寻址特征 + R$_i$
- R$_i$：操作数的地址。操作数存放在内存单元。
- 取操作数：寄存器 $\rightarrow$ 内存地址 $\rightarrow$ 内存单元 $\rightarrow$ 操作数
- 优点
  - 便于指令循环操作
- 指令执行阶段访存：1次

#### 7.基址寻址
a. 采用专用寄存器作基址寄存器

EA = (BR) + A $\quad$ BR为基址寄存器。

格式： OP + 寻址特征 + A$
- A: 偏移量
- 取操作数：(BR) + A  $\rightarrow$ 地址值  $\rightarrow$ （地址值）
- 优点
  - 可扩大寻址范围
  - 有利于多道程序
  - BR内容由操作系统或管理程序确定
  - 程序执行过程中BR内容不变，形式地址A可变


b. 采用通用寄存器作基址寄存器

EA = (R$_0$) + A $\quad$ BR为基址寄存器。

格式： OP + 寻址特征 + R$_0$ + A
- A: 偏移量
- 取操作数：(R$_0$) + A  $\rightarrow$ 地址值  $\rightarrow$ （地址值）


#### 8.基址寻址
EA = (IX) + A $\quad$ IX 为专用变址寄存器

$\qquad \qquad \qquad$ 通用寄存器也可以作为变址寄存器

格式： OP + 寻址特征 + A$
- A: 偏移量
- 取操作数：(IX) + A  $\rightarrow$ 地址值  $\rightarrow$ （地址值）
- 优点
  - 可扩大寻址范围
  - 有利于多道程序
  - A固定，IX可以被修改（和基址相反）。[便于数组操作：A作为数组起点，IX为数组下标]

#### 9.相对寻址
EA = (PC) + A $\quad$ A 是相对于当前指令的位移量（可正可负，补码）

格式： OP + 寻址特征 + A$
- A: 要执行指令和当前指令的 相对距离
- 取操作数：(PC) + A  $\rightarrow$ 地址值  $\rightarrow$ （地址值）
- 优点
  - 程序浮动

#### 10.堆栈寻址
1. 堆栈的特点
- 硬堆栈  $\quad$ 多个寄存器
- 软堆栈  $\quad$ 指定的存储空间

先进后出（一个入出口） **栈顶地址**由SP指出(一般栈顶是低地址。底是高地址，越往下，地址越大)

进栈 (SP) - 1 $\rightarrow$ SP

出栈 (SP) + 1 $\rightarrow$ SP

2. SP的修改与主存编址方法有关
- 按字编址 $\quad$(SP) + / -1 
- 按字节编址
  - 储存字长16位 $\quad$(SP) + / -2 
  - 储存字长32位 $\quad$(SP) + / -4 

## 7.4 指令格式举例
### *一、设计时需要考虑的因素
#### 1. 指令系统的兼容性
#### 2. 其他因素
- 操作类型： 指令个数及操作难易度
- 数据类型： 哪些类型
- 指令格式：
  - 指令字长是否固定
  - 操作码位数、是否采用扩展操作码技术
  - 地址码位数、地址个数、寻址方式类型
- 寻址方式：指令寻址、操作数寻址
- 寄存器个数：直接影响指令的执行时间

### 7.5 RISC技术
#### 一、RISC的产生和发展
RISC (Reduced Instruction Set Computer)
CISC (Complex Instruction Set Computer)

2-8规律： 典型程序中80%的语句仅仅使用处理机中20%的指令

#### 二、RISC的主要特征
- 选用使用频度较高的一些简单指令，复杂指令的功能由简单指令来组合
- 指令 长度固定、指令格式种类少、寻址方式少
- 只有 LOAD/STORE 指令访存
- CPU中有多个通用寄存器
- 采用流水技术 一个时钟周期内完成一条指令
- 采用组合逻辑实现控制器

#### 三、CISC的主要特征

#### 四、RISC和CISC的比较