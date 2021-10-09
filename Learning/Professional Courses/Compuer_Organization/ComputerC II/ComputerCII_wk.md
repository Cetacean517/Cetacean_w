## 3 存储器
### 3.1 主存储器的结构
#### 组成
存储体 + MAR + MDR (用时序控制逻辑控制)
#### 存储体基础
a. 一个**存储体**由多个**存储单元**组成，一个存储单元由多个**存储元**组成

b. 工作有限制，一列绿线同时只能运行一个信号，不然会发生取数的冲突。

如何解决？

增加译码器，原本要存储的所有10000000....信号，通过译码器产生。即n位译码器对应$2^n$位的信号编码

c. 存储字 = 图中的列数（单位：bit 位）

![avatar](https://i.loli.net/2021/04/01/43DAQpj9N8GFegT.png)
#### 主存储其的简单模型
**a. 地址线** ：链接外接给的n位地址
- n位地址线 对应 内存的$2^n$行  (MAR的位数)

**b. 数据线**：连接外界给的数据值
- n位数据线 对应 内存的$2^n$列 (MDR的位数)

**c. 控制电路**：
   - 片选线：高/低电平有效
   - 读写控制线：可以共用一根/两根分开

**d. 总容量**：存储单元个数 $×$ 存储字长 = $2^3 × 8bit = 2^3 × 1Byte = 8B$

常见描述：$8×8$ 位，即 $2^{13} \times 8bit$

![avatar](https://i.loli.net/2021/04/01/UGVCTfD17l2LygW.png)

#### 逻辑模型
译码驱动：使原本只能一次读取一位，增强到读取多位
![avatar](https://i.loli.net/2021/04/01/7NTifUIGSLdKm1h.png)

### 3.2 寻址
#### 按字节、字、半字、双字寻址 
如何按字寻址：求取范围，以X字节为一组，可以求多少组
- 按字节寻址
- 按字寻址：

#### 多字节存放：

把32bit编译成HEX进制编码，每1B存放2位。

大端方式：从低位到高位存放

小端方式：从高位到地位存放

![avatar](https://i.loli.net/2021/04/01/2GRUufK4Z3kmEM1.png)

### 3.1 半导体存储器
#### 3.3.1 半导体存储器RAM
##### 半导体存储芯片的基本结构
![avatar](https://i.loli.net/2021/04/01/VU4HMNl1uGBL7AE.png)

##### 半导体随机存取存储器
![avatar](https://i.loli.net/2021/04/01/yvmIPxXslw6uWDZ.png)
##### DRAM的刷新
![avatar](https://i.loli.net/2021/04/01/VXDa4UspbuntyrI.png)
![avatar](https://i.loli.net/2021/04/01/IerC5JjtolzaxNZ.png)

##### SRAM的读周期
片选线 $\overline{CS}$ ：上划线表示低电平有效（单个二进制位）

地址线 地址：（多个二进制位：用多边形表示）

数据线 $D_{OUT}$ ：（多个二进制位：用多边形表示）

![avatar](https://i.loli.net/2021/04/01/WdzSwsa3q9PhvGD.png)
##### RAM-易失性存储器
![avatar](https://i.loli.net/2021/04/01/CSvdz5ND3JV2h18.png)