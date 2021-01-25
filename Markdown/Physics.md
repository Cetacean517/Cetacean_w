# Physics 3

## 气体动理论

### 热力学系统

|          | 能量交换 | 物质交换 |
| :------- | :------- | :------- |
| 孤立系统 | false    | false    |
| 封闭系统 | true     | false    |
| 开放系统 | true     | true     |

### 平衡态

- 单一性
- 稳定性
- 热动平衡

### 理想气体物态方程

$1atm=1.013\times10^5Pa=760mmHg\\T=t+273.15$

1. 波义耳定律(T)
   $p_1V_1=p_2V_2$
2. 盖$\cdot$吕萨克定律(P)
   $\frac{V_1}{T_1}=\frac{V_2}{T_2}$
3. 查理定律(V)
   $\frac{p_1}{T_2}=\frac{p_2}{T_2}$

理想气体物态方程：$$pV=\frac{m'}{M}RT\hspace{10ex}\lgroup{ m'=Nm ,~ M=N_Am}\rgroup$$

理想气体压强公式:$$\overline{v^2}=\frac{v_1^2+\ldots+V_n^2}{N}=\frac{1}{N}\sum_{i=1}^{N}{v_i^2}$$

$pV=\frac{m}{M_mol}RT=v RT$

> $m:气体质量(kg)\\M_mol:气体摩尔质量\\R:气体普适常量\\v:摩尔数$

理想气体常数:

$p(atm),V(L),T(K)\Rightarrow R=8.2\times 10^{-2}atm\cdot L/(mol\cdot K)\\p(atm),V(m^3),T(K)\Rightarrow R=8.31 J/(mol\cdot K)$

**_玻尔兹曼常数(k):_** $k=\frac {R}{N_A}$ = $1.38\times 10^{-23} J/K$

$p=nkT \\ p=\frac{2}{3}n \overline{\varepsilon_k}\\\overline{\varepsilon_k}=\frac{1}{2}m\overline{v}^2=\frac{3}{2}kT$

### 能量均分定理（$\frac{1}{2}kT$）

| 自由度($\frac{1}{2}kT$/自由度) |       |
| :----------------------------- | :---- |
| 质点                           | i=3   |
| 刚体                           | i=6   |
| 刚性分子                       | i=t+r |

### 内能

$$E=N_A \overline \varepsilon=N_A \frac {i}{2}kT\Rrightarrow E=\frac{i}{2}RT$$

### 麦克斯韦速率分布律

- **单个**分子速率分布具有**偶然性**
- **大量**分子速率分布具有**规律性**

麦克斯韦分布函数:表示**单位速率区间的分子数占总数的百分比**

$$f(v)=\frac{1}{N}\frac{dN}{dv}$$

$$f(v)=4\pi (\frac{m_0}{2\pi kT})^{3/2}e^{-m_0v^2/2kT}v^2$$

### 三种统计速率

1. 最概然速率
   $$v_p=\sqrt{\frac{2kT}{m}}\approx 1.41\sqrt{\frac{RT}{M}},\approx 1.41\sqrt{\frac{kT}{m}}$$
2. 平均速率
   $$\overline {v}=\frac{1}{N}\sum_{i=1}^n{v_iN_i}=\sqrt{\frac{8kT}{\pi m}}\approx 1.60\sqrt{\frac{RT}{M}},\approx 1.60\sqrt{\frac{kT}{m}}$$
3. 方均根速率$\sqrt{\overline{v}^2}$
   $$\overline{v}^2=\frac{1}{N}\sum_{i=1}^n{v_i^2N_i},\sqrt{\overline{v}^2}=\sqrt{\frac{3kT}{m}}\approx 1.73\sqrt{\frac{RT}{M}},\approx 1.73\sqrt{\frac{kT}{m}}$$

比较:$v_p<\overline{v}<\sqrt{\overline{v}^2}$

归一化条件:

$\hspace{3ex} \int^{0}_{\infty}{f(v)dv}=1\\dS=f(v)dv=\frac{dN}{N}$

### 平均自由程

单位时间内平均碰撞次数:$~\overline{Z}=\sqrt{2}\pi{}d^2vn$

平均自由程:**每两次**碰撞之间，一个分子自由运动的**平均路程**

$$\overline{\lambda}=\frac{kT}{\sqrt{2}\pi{}d^2p}~~~\overline{\lambda{}}\propto\frac{1}{p},T$$

## 热力学

### 热力学过程

系统从**平衡态**到另一**平衡态**的过程

准静止状态:**无限缓慢**,**每个**中间态都可视为**平衡态**

### _p~V_ 图

- 点:一个平衡态
- 线:一个准静态过程

### 系统内能

1. 功(过程量)

   _p~V_ 图与曲线对 _V_ 轴积分所成面积即为功
   $$dW=Fdl=pSdl$$
   $$W=\int_{V1}^{V2}{pdV}$$

   - $W>0~$系统对外界作正功
   - $W<0~$系统对外界作负功

2. 热(过程量)
   - 同:
     1. 过程量:与过程有关
     2. 等效性:对系统热状态改变的作用相同
   - 异:
     1. 功:宏观运动-分子热运动
     2. 热:分子热运动-分子热运动
3. 内能
   $E_2-E_1=W+Q~~~W+Q只与始末状态有关,与过程无关$

### 热力学第一定律

系统吸收的能量,一部分使内能增加,另一部分用于系统对外作功

$$Q=E_2-E_1+W=\Delta{}E+W$$
$$dQ=dE+dW$$
$$Q=E_2-E_1+\int_{V1}^{V2}{pdV}$$
$$C_V=\frac{i}{2}R$$

1. 等容过程

   $$\nu{}=\frac{m}{M_{mol}}$$

   $$Q=E_2-E_1=\nu{}\frac{i}{2}R(T_2-T_1)$$

   系统从外界吸收的热量全部转化为内能的增加

   > 定体摩尔热容$C_V$:1mol 理想气体在等体过程中,温度变化 1 摄氏度所变化的热量

2. 等压过程

   $$\Delta{}E=E_2-E_1=\nu{}C_V\Delta{T}$$

   $$Q=v{}C_V\Delta{T}+\nu{}R\Delta{T}$$

   > 定体摩尔热容$C_p$:1mol 理想气体在等压过程中,温度变化 1 摄氏度所变化的热量

   $$C_p=C_V+R=\frac{i+2}{2}R$$

   比热容比:

   $$\gamma{}=\frac{C_p}{C_V}=\frac{i+2}{i}$$

3. 等温过程

   $$Q_T=W=\int_{V_1}^{V_2}{\frac{m}{M}\frac{Rt}{V}dV}=\boxed{\frac{m}{M}RT\ln\frac{V_2}{V_1}}=\frac{m}{M}RT~\ln{\frac{p_1}{p_2}}$$

4. 绝热过程

   对外界作功,通过系统内能减小完成

   $$
   \begin{aligned}
      V^{\gamma{}-1}T=const\\
      pV^{\gamma}=const\\
      p^{\gamma{}-1}T^{-\gamma}=const
   \end{aligned}
   $$

   - 绝热线:**绝热**过程曲线上任意一点的斜率
   - 等温线:**等温**过程曲线上任意一点的斜率
