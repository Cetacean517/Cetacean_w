# Linpack

## 1. 实验要求

![image-20220511135552067](D:\Cetacean517\Cetacean_w\Learning\Professional Courses\Computer_Architecture\Tests\Test4_Linpack\Notepic\image-20220511135552067.png)

# I. 安装过程

## 前言：Linux安装指南

- wget + 链接 下载安装包
- 下载安装包加镜像 -i http://mirrors.163.com/ubuntu-releases/

指南： url =https://blog.csdn.net/yu_223/article/details/115877063?spm=1001.2101.3001.6650.1&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7Edefault-1-115877063-blog-102289928.pc_relevant_default&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7Edefault-1-115877063-blog-102289928.pc_relevant_default&utm_relevant_index=2

## 1. 安装OpenMPI

sudo apt install mpi-*

## 2. 安装OpenBLAS

sudo apt install libopenblas-*

## 3. 安装HPL

sudo tar -xzvf hpl-2.3.tar.gz -C ~/hpl-2.3

cp setup/Make.Linux_PII_CBLAS ../Make.test

修改Mate.test文件

```shell
# ARCH内容要与刚刚重命名Make后的字段一致
ARCH = test
# TOPdir填写你hpl的解压路径,所以hpl文件在的目录
TOPdir = $(HOME)/hpl-2.3/hpl-2.3
# MPdir填写openmpi的库文件夹，ZorinOS是在/usr/lib/x86_64-linux-gnu/openmpi，有的系统会在/usr/lib/openmpi
# 找不到的话可以用全盘搜索
MPdir = /usr/lib/x86_64-linux-gnu/openmpi
# MPlib填写libmpi链接库的路径，它在openmpi库文件夹的lib下（可以作为搜索openmpi的依据）
MPlib = $(MPdir)/lib/libmpi.so
# LAdir填写openblas的库文件路径
LAdir = /usr/lib/x86_64-linux-gnu/openblas
# LAlib填写libblas静态库路径，它在openmpi库文件夹下（可以作为搜索openblas的依据）
LAlib = $(LAdir)/libblas.a
# CC填写C编译器路径（通过which mpicc查询路径），这里我们不用gcc，而是使用mpicc编译器
CC = /usr/bin/mpicc
# CCFLAGS需要加一个-lpthread，表明编译时添加头文件 pthread.h（和线程有关）
CCFLAGS = $(HPL_DEFS) -fomit-frame-pointer -O3 -funroll-loops -pthread
# LINKER填写连接器路径（which mpif77查询路径），这里使用mpif77连接器
LINKER = /usr/bin/mpif77

```

sudo make arch=test（要给权限）！！！！

sudo sh -c "mpirun --allow-run-as-root -np 4 ./xhpl > 1.txt" （root 跑要加--allow-run-as-root)

# II. 实验二：HPL.dat的配置

参考：Linkpack makefile 的debug部分：https://blog.csdn.net/icefromair/article/details/51520322

```shell
HPLinpack benchmark input file                       //文件头，说明
Innovative Computing Laboratory, University of Tennessee
HPL.out      output file name (if any)               //如果使用文件保留输出结果，设定文件名
6            device out (6=stdout,7=stderr,file)     //输出方式选择（stdout,stderr或文件）
2            # of problems sizes (N)              	 //指出要计算的矩阵规格有几种
1960  2048Ns                                         //每种规格分别的数值
4            # of NBs								 //指出使用几种不同的分块大小
1 2 3 4      NBs									 //分别指出每种大小的具体值
0            PMAP process mapping (0=Row-,1=Column-major)
3            # of process grids (P x Q)				 //指出用几种进程组合方式
2 1 4        Ps
2 4 1        Qs
16.0         threshold								 //余数的阈值
3            # of panel fact						 //用几种分解方法
0 1 2        PFACTs (0=left, 1=Crout, 2=Right)		 //具体用哪种,0 left,1 crout,2 right
2            # of recursive stopping criterium		 //几种停止递归的判断标准
2 4          NBMINs (>= 1)							 //具体的标准数值（须不小于1）
1            # of panels in recursion				 //递归中用几种分割法
2            NDIVs									 //这里用一种NDIV值为2，即每次递归分成两块
3            # of recursive panel fact.				 //用几种递归分解方法
0 1 2        RFACTs (0=left, 1=Crout, 2=Right)		 //这里每种都用到（左，右，crout分解）
1            # of broadcast							 //用几种广播方法
0            BCASTs (0=1rg,1=1rM,2=2rg,3=2rM,4=Lng,5=LnM) // 指定具体哪种（有1-ring,1-ring
														  // Modified,2-ring,2ring 			
														  // Modified,Long以及long-Modified）
1            # of lookahead depth					 //用几种向前看的步数
0            DEPTHs (>=0)							 //具体步数值（须大于等于0）
2            SWAP (0=bin-exch,1=long,2=mix)	   //哪种交换算法（bin-exchange，long或者二者混合）
64           swapping threshold						 //采用混合的交换算法时使用的阈值 
                                           
0            L1 in (0=transposed,1=no-transposed) form    //L1是否用转置形式
0	U  in (0=transposed,1=no-transposed) form        //U是否用转置形式表示
1            Equilibration (0=no,1=yes)              //是否采用平衡状态
8            memory alignment in double (> 0)        //指出程序运行时内存分配中的采用的对齐方式
```

##        1.实验要求

​			要得到调试出高的性能，必须考虑内存大小，网络类型以及拓扑结构，调试上面的参数，直到得出最高性能。
​    本次实验需要对以下三组参数进行设置：

```shell
2            # of problems sizes (N) //指出要计算的矩阵规格有几种
1960  2048Ns                         //每种规格分别的数值指出要计算的矩阵规格有2种，规格是1960,2048

2            # of NBs                //指出使用几种不同的分块大小
60 80        NBs                     //分别指出每种大小的具体值指出使用2种不同的分块大小，大小为60,80
2            # of process grids (P x Q)    //指出用几种进程组合方式
2   2        Ps           		     //每对PQ具体的值指出用2种进程组合方式，
4   1        Qs    					 //分别为（p＝2，q=2） 和（p＝4，q=1）
		
// 注：p＝2，q=2时需要的进程数是p×q＝2×2＝4，运行时mpirun命令行中指定的进程数必须大于等于4
```


​	以上3组每组有两种情况，组合后一共有8种情况，将得到8个性能测试值，经过不断的调试将会得出一个最大的性能值，这就是得到的最高性能值。
​    以下是其中一个性能测试值，规格为2048，分块是60，p＝2，q=2时，运行时间为：56.14，运算速度为0.8165 Gflops。PASSED代表结果符合要求。

```

============================================================================
T/V                N    NB     P     Q               Time             Gflops
----------------------------------------------------------------------------
W13R2C4         2048    60     2     2              56.14          8.165e-01
----------------------------------------------------------------------------
||Ax-b||_oo / ( eps * ||A||_1  * N        ) =        0.0175089 ...... PASSED
||Ax-b||_oo / ( eps * ||A||_1  * ||x||_1  ) =        0.0035454 ...... PASSED
||Ax-b||_oo / ( eps * ||A||_oo * ||x||_oo ) =        0.0007503 ...... PASSED
============================================================================
```

## 2. 实验结果

1960 

```
--------------------------------------------------------------------------------

- The matrix A is randomly generated for each test.
- The following scaled residual check will be computed:
      ||Ax-b||_oo / ( eps * ( || x ||_oo * || A ||_oo + || b ||_oo ) * N )
- The relative machine precision (eps) is taken to be               1.110223e-16
- Computational tests pass if scaled residuals are less than                16.0

================================================================================
T/V                N    NB     P     Q               Time                 Gflops
--------------------------------------------------------------------------------
WR00L2L2        1960    60     2     2               0.45             1.1090e+01
HPL_pdgesv() start time Wed May 11 06:00:32 2022

HPL_pdgesv() end time   Wed May 11 06:00:32 2022

--------------------------------------------------------------------------------
||Ax-b||_oo/(eps*(||A||_oo*||x||_oo+||b||_oo)*N)=   3.13254665e-03 ...... PASSED
```

1960 80

```
================================================================================
T/V                N    NB     P     Q               Time                 Gflops
--------------------------------------------------------------------------------
WR00L2L2        1960    80     2     2               0.37             1.3577e+01
HPL_pdgesv() start time Wed May 11 06:00:43 2022

HPL_pdgesv() end time   Wed May 11 06:00:43 2022

--------------------------------------------------------------------------------
||Ax-b||_oo/(eps*(||A||_oo*||x||_oo+||b||_oo)*N)=   2.92683794e-03 ...... PASSED
```

1960 60 4 1

```
================================================================================
T/V                N    NB     P     Q               Time                 Gflops
--------------------------------------------------------------------------------
WR00R2R2        1960    60     4     1               0.48             1.0415e+01
HPL_pdgesv() start time Wed May 11 06:01:48 2022

HPL_pdgesv() end time   Wed May 11 06:01:49 2022

--------------------------------------------------------------------------------
||Ax-b||_oo/(eps*(||A||_oo*||x||_oo+||b||_oo)*N)=   2.81541239e-03 ...... PASSED
```

1960 80 4 1

```
================================================================================
T/V                N    NB     P     Q               Time                 Gflops
--------------------------------------------------------------------------------
WR00L2L4        1960    80     4     1               0.54             9.3352e+00
HPL_pdgesv() start time Wed May 11 06:01:51 2022

HPL_pdgesv() end time   Wed May 11 06:01:51 2022

--------------------------------------------------------------------------------
||Ax-b||_oo/(eps*(||A||_oo*||x||_oo+||b||_oo)*N)=   3.04119574e-03 ...... PASSED
```

2048 60 22

```
================================================================================
T/V                N    NB     P     Q               Time                 Gflops
--------------------------------------------------------------------------------
WR00R2C4        2048    60     2     2               0.53             1.0824e+01
HPL_pdgesv() start time Wed May 11 06:01:11 2022

HPL_pdgesv() end time   Wed May 11 06:01:11 2022

--------------------------------------------------------------------------------
||Ax-b||_oo/(eps*(||A||_oo*||x||_oo+||b||_oo)*N)=   3.58991437e-03 ...... PASSED
```

2048 80 22

```
================================================================================
T/V                N    NB     P     Q               Time                 Gflops
--------------------------------------------------------------------------------
WR00L2L2        2048    80     2     2               0.75             7.6863e+00
HPL_pdgesv() start time Wed May 11 06:01:15 2022

HPL_pdgesv() end time   Wed May 11 06:01:15 2022

--------------------------------------------------------------------------------
||Ax-b||_oo/(eps*(||A||_oo*||x||_oo+||b||_oo)*N)=   4.32927638e-03 ...... PASSED
```

2048 60 41

```
================================================================================
T/V                N    NB     P     Q               Time                 Gflops
--------------------------------------------------------------------------------
WR00R2R2        2048    60     4     1               0.75             7.6253e+00
HPL_pdgesv() start time Wed May 11 06:02:26 2022

HPL_pdgesv() end time   Wed May 11 06:02:26 2022

--------------------------------------------------------------------------------
||Ax-b||_oo/(eps*(||A||_oo*||x||_oo+||b||_oo)*N)=   3.47355393e-03 ...... PASSED
```

2048 80 41

```
================================================================================
T/V                N    NB     P     Q               Time                 Gflops
--------------------------------------------------------------------------------
WR00L2L2        2048    80     4     1               0.72             7.9385e+00
HPL_pdgesv() start time Wed May 11 06:02:29 2022

HPL_pdgesv() end time   Wed May 11 06:02:29 2022

--------------------------------------------------------------------------------
||Ax-b||_oo/(eps*(||A||_oo*||x||_oo+||b||_oo)*N)=   3.39957597e-03 ...... PASSED
```

# III. 实验三：集群性能调优

配合mpi_集群

共享文件夹地址：cd /home/cetacean/mpi_share

## 1. MPI 集群配置

参考：https://blog.csdn.net/qq_41472037/article/details/105234920?spm=1001.2101.3001.6661.1&utm_medium=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7ECTRLIST%7Edefault-1-105234920-blog-82854669.pc_relevant_default&depth_1-utm_source=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7ECTRLIST%7Edefault-1-105234920-blog-82854669.pc_relevant_default&utm_relevant_index=1

### A. 配置环境

环境 ： root

卸载: sudo apt-get --purge remove mpi-*; sudo apt autoremove

虚拟机信息：

VM ware Ubuntu 18.04

192.168.139.140	master

192.168.139.141	slave

### B. 安装MPICH

1. 进入放置安装包的目录：	cd /home/cetacean/Downloads

2. 从官网下载安装包：            wget http://www.mpich.org/static/downloads/3.3.2/mpich-3.3.2.tar.gz
3. 在/home/cetacean/Downloads 目录下，解压缩文件：tar -zxvf mpich-3.3.2.tar.gz
4. 进入解压后的文件夹：	    cd mpich-3.3.2 #进入解压后的文件夹内
5. 设定配置文件：                     ./configure  --prefix=/usr/local/mpich-3.3.2
6. 编译：make
7. 安装：make install
8. 修改配置：vim ~/.bashrc

```bash
export PATH="/usr/local/mpich-3.3.2/bin:$PATH" 
export MANPATH=$MPI_ROOT/man:$MANPATH
```

### C. 实现虚拟机ssh互通

具体步骤同实验一

1. 修改文件权限：chmod 600 ~/.ssh/authorized_keys

2. 安装ssh-askpass：sudo apt install ssh-askpass

3. 添加信息：

   ```
   ssh-keyscan -H 192.168.139.141 >> ~/.ssh/known_hosts
   ssh-keyscan -H 192.168.139.140 >> ~/.ssh/known_hosts
   ```

Notice：修改主机名和 master slave一致（不然会出现识别异常）

### D. 建立共享目录

1. 在所有节点中建立相同路径下的相同目录：mkdir /home/cetacean/mpi_share

2. 安装nfs
   1. 主节点master:  sudo apt-get install nfs-kernel-server
   2. 子节点slave: sudo apt install nfs-common

3. 主节点master的操作：
   1. sudo vi /etc/exports或sudo gedit /etc/exports

​								修改配置文件如下，格式：共享目录 IP（权限），这里加入的是master\node1\node2的IP:

<img src="D:\Cetacean517\Cetacean_w\Learning\Professional Courses\Computer_Architecture\Tests\Test4_Linpack\Notepic\image-20220512215119280.png" alt="image-20220512215119280" style="zoom: 33%;" />

​		4. 子节点操作：sudo gedit /etc/rc.local 加入下面语句，或者手动挂载（每次）

```shell
 sudo mount -t nfs master:/home/cetacean/mpi_share /home/cetacean/mpi_share

```

### E. 运行指令

**a) MPI指令**

mpirun -np 4 -f mpi_config ./编译后文件

参数：-np 指定 进程数； -f 指定配置文件（用于多节点运行）

mpi_config的内容: 

其中 master 是 cetacean@master中， @后面的主机名)

```
master:1
slave:1
```

b) MPI 运行 HPL指令

在有HPL.DAT 和 xhpl的文件下运行：

mpirun -np 4 -f mpi_config ./xhpl >> 1.txt

## 2. 运行脚本

linux中的脚本

```
import os
from tqdm import tqdm #这个库需要用pip先安装一下
class MPIRun:
    def __init__(self,Ns,NB,P,Q):
        self.Ns = Ns
        self.NB = NB
        self.P = P
        self.Q = Q
        self.HPLDAT = '''HPLinpack benchmark input file
Innovative Computing Laboratory, University of Tennessee
HPL.out      output file name (if any)
6            device out (6=stdout,7=stderr,file)
1            # of problems sizes (N)
%d           Ns
1            # of NBs
%d           NBs
0            PMAP process mapping (0=Row-,1=Column-major)
1            # of process grids (P x Q)
%d       Ps
%d       Qs
16.0         threshold
3            # of panel fact
0 1 2        PFACTs (0=left, 1=Crout, 2=Right)
2            # of recursive stopping criterium
2 4          NBMINs (>= 1)
1            # of panels in recursion
2            NDIVs
3            # of recursive panel fact.
0 1 2        RFACTs (0=left, 1=Crout, 2=Right)
1            # of broadcast
0            BCASTs (0=1rg,1=1rM,2=2rg,3=2rM,4=Lng,5=LnM)
1            # of lookahead depth
0            DEPTHs (>=0)
2            SWAP (0=bin-exch,1=long,2=mix)
64           swapping threshold
0            L1 in (0=transposed,1=no-transposed) form
0            U  in (0=transposed,1=no-transposed) form
1            Equilibration (0=no,1=yes)
8            memory alignment in double (> 0)'''%(Ns,NB,P,Q)
    
    def run(self):
        HPLDAT_FILE = open("./HPL.dat","w",encoding="utf-8")
        HPLDAT_FILE.write(self.HPLDAT)
        HPLDAT_FILE.close()
        cmd = "mpirun -np %d -f mpi_config ./xhpl > %d-%d-%d-%d.txt"%(self.P*self.Q,self.Ns,self.NB,self.P,self.Q)
        print("\r",cmd,end="",flush=True)
        os.system(cmd)


if __name__=="__main__":
    script_deal = open("./script.txt","r",encoding="utf-8")
    lines = script_deal.readlines()
    for line in tqdm(lines):
        runlist = [int(i) for i in line.split(" ")]
        Ns,NB,P,Q = runlist[0],runlist[1],runlist[2],runlist[3]
        mpirun = MPIRun(Ns,NB,P,Q)
        mpirun.run()


```

##  3. 运行结果分析

参考 ：https://blog.csdn.net/yu_223/article/details/115983923

### a. 进程分配选择：控制矩阵规模，分块数不变

T/V：WR00L2L2      模式：S= 单机 C=集群

| 模式  | N        | NB     | P     | Q     | Time     |
| ----- | -------- | ------ | ----- | ----- | -------- |
| S     | 1960     | 60     | 1     | 2     | 1.30     |
| **C** | **1960** | **60** | **1** | **2** | **0.28** |
| C     | 1960     | 60     | 1     | 4     | 0.75     |
| C     | 1960     | 60     | 2     | 2     | 9.75     |
|       |          |        |       |       |          |
| **C** | **1960** | **80** | **1** | **2** | **0.24** |
| C     | 1960     | 80     | 1     | 4     | 0.87     |
| C     | 1960     | 80     | 2     | 2     | 9.92     |
|       |          |        |       |       |          |

从表中可以发现，1*2 的分配方式效率最好

<img src="D:\Cetacean517\Cetacean_w\Learning\Professional Courses\Computer_Architecture\Tests\Test4_Linpack\Notepic\image-20220514151003700.png" alt="image-20220514151003700" style="zoom:33%;" />

### b. 分块大小分析：控制矩阵规模，进程分配不变



<img src="D:\Cetacean517\Cetacean_w\Learning\Professional Courses\Computer_Architecture\Tests\Test4_Linpack\Notepic\NB 分块性能测试.png" alt="NB 分块性能测试" style="zoom:33%;" />



### c. 矩阵规模大小分析：控制进程，程序分配不变

<img src="D:\Cetacean517\Cetacean_w\Learning\Professional Courses\Computer_Architecture\Tests\Test4_Linpack\Notepic\NS 矩阵规模 性能测试.png" alt="NS 矩阵规模 性能测试" style="zoom:33%;" />

### Echart 代码附录

分块性能测试

```html
option = {
  title: {
    text: 'NB 分块性能测试',
  },
  tooltip: {
    trigger: 'axis'
  },
  legend: {
    top:'4%',
    data: ['1960-32-1-2', '1960-60-1-2','1960-64-1-2', '1960-80-1-2', '1960-96-1-2', '1960-128-1-2','1960-160-1-2','1960-192-1-2','1960-224-1-2','1960-256-1-2'],
    bottom:'3%'
  },
  grid: {
    top:'15%',
    left: '3%',
    right: '4%',
    bottom: '3%',
    containLabel: true
  },
  toolbox: {
    feature: {
      saveAsImage: {}
    }
  },
  xAxis: {
    type: 'category',
    boundaryGap: false,
    data: ['1', '2', '3', '4', '5', '6','7','8','9','10','11','12','13','14','15','16','17']
  },
  yAxis: {
    type: 'value'
  },
  series: [
    {
      name: '1960-32-1-2',
      type: 'line',
      data: [0.64, 0.53, 0.61, 0.51, 0.51, 0.47, 0.29, 0.28, 0.23, 0.29, 0.29, 0.28, 0.26, 0.29, 0.29, 0.27, 0.25]
    },
    {
      name: '1960-60-1-2',
      type: 'line',
      data: [0.26, 0.26, 0.26, 0.26, 0.27, 0.28, 0.27, 0.26, 0.25, 0.26, 0.29, 0.27, 0.29, 0.29, 0.27, 0.26, 0.32]
    },
    {
      name: '1960-64-1-2',
      type: 'line',
      data: [0.36, 0.22, 0.25, 0.24, 0.25, 0.27, 0.23, 0.22, 0.21, 0.36, 0.27, 0.21, 0.21, 0.21, 0.36, 0.22, 0.22]
    },
    {
      name: '1960-80-1-2',
      type: 'line',
      data: [0.28, 0.26, 0.27, 0.27, 0.27, 0.26, 0.27, 0.26, 0.25, 0.27, 0.26, 0.26, 0.25, 0.25, 0.25, 0.26, 0.26]
    },
    {
      name: '1960-80-1-2',
      type: 'line',
      data: [0.28, 0.26, 0.27, 0.27, 0.27, 0.26, 0.27, 0.26, 0.25, 0.27, 0.26, 0.26, 0.25, 0.25, 0.25, 0.26, 0.26]
    },
    {
      name: '1960-80-1-2',
      type: 'line',
      data: [0.28, 0.26, 0.27, 0.27, 0.27, 0.26, 0.27, 0.26, 0.25, 0.27, 0.26, 0.26, 0.25, 0.25, 0.25, 0.26, 0.26]
    },
    {
      name: '1960-96-1-2',
      type: 'line',
      data: [0.25, 0.21, 0.21, 0.31, 0.24, 0.20, 0.20, 0.24, 0.32, 0.24, 0.37, 0.43, 0.27, 0.25, 0.25, 0.28, 0.25]
    },
    {
      name: '1960-128-1-2',
      type: 'line',
      data: [0.41, 0.45, 0.56, 0.33, 0.33, 0.31, 0.32, 0.27, 0.30, 0.26, 0.24, 0.22, 0.26, 0.26, 0.29, 0.25, 0.25]
    },
    {
      name: '1960-160-1-2',
      type: 'line',
      data: [0.25, 0.24, 0.25, 0.25, 0.21, 0.24, 0.22, 0.23, 0.25, 0.21, 0.22, 0.22, 0.22, 0.23, 0.22, 0.23, 0.23]
    },
    {
      name: '1960-192-1-2',
      type: 'line',
      data: [0.22, 0.23, 0.27, 0.24, 0.23, 0.27, 0.23, 0.25, 0.23, 0.22, 0.23, 0.23, 0.29, 0.27, 0.24, 0.26, 0.26]
    },
    {
      name: '1960-224-1-2',
      type: 'line',
      data: [0.23, 0.25, 0.26, 0.24, 0.25, 0.27, 0.26, 0.24, 0.24, 0.24, 0.23, 0.23, 0.24, 0.22, 0.24, 0.23, 0.23]
    },
    {
      name: '1960-256-1-2',
      type: 'line',
      data: [0.24, 0.27, 0.26, 0.29, 0.29, 0.27, 0.28, 0.31, 0.32, 0.32, 0.27, 0.30, 0.26, 0.29, 0.27, 0.27, 0.29]
    },
  ]
};
```



矩阵规模

```
option = {
  title: {
    text: 'NS 矩阵规模 性能测试',
  },
  tooltip: {
    trigger: 'axis'
  },
  legend: {
    top:'4%',
    data: ['1960-32-1-2','2048-32-1-2','3000-32-1-2','6000-32-1-2','9000-32-1-2'],
    bottom:'3%'
  },
  grid: {
    top:'15%',
    left: '3%',
    right: '4%',
    bottom: '3%',
    containLabel: true
  },
  toolbox: {
    feature: {
      saveAsImage: {}
    }
  },
  xAxis: {
    type: 'category',
    boundaryGap: false,
    data: ['1', '2', '3', '4', '5', '6', '7','8','9','10','11','12','13','14','15','16','17']
  },
  yAxis: {
    type: 'value'
  },
  series: [
    {
      name: '1960-32-1-2',
      type: 'line',
      data: [0.64, 0.53, 0.61, 0.51, 0.51, 0.47, 0.29, 0.28, 0.23, 0.29, 0.29, 0.28, 0.26, 0.29, 0.29, 0.27, 0.25]
    },
    {
      name: '2048-32-1-2',
      type: 'line',
      data: [0.38, 0.40, 0.39, 0.42, 0.40, 0.41, 0.43, 0.41, 0.44, 0.42, 0.42, 0.40, 0.40, 0.39, 0.37, 0.39, 0.37]
    },
    {
      name: '3000-32-1-2',
      type: 'line',
      data: [0.96, 0.98, 0.97, 0.97, 1.02, 0.97, 1.05, 0.99, 1.00, 1.09, 1.13, 1.04, 1.03, 0.85, 0.95, 0.80, 0.81]
    },
    {
      name: '6000-32-1-2',
      type: 'line',
      data: [5.30, 5.26, 5.20, 5.12, 5.17, 5.21, 6.08, 5.98, 5.87, 6.01, 5.79, 5.85, 5.78, 5.88, 5.65, 5.35, 5.22]
    },
    {
      name: '9000-32-1-2',
      type: 'line',
      data: [16.30, 16.26, 17.58, 16.22, 16.29, 16.30, 22.44, 25.59, 22.07, 16.18, 16.30, 16.45, 16.30, 16.85, 16.21, 16.38, 16.36]
    },
  ]
};
```

菜鸟echarts中运行
```
<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8">
    <title>第一个 ECharts 实例</title>
    <!-- 引入 echarts.js -->
    <script src="https://cdn.staticfile.org/echarts/4.3.0/echarts.min.js"></script>
</head>
<body>
    <!-- 为ECharts准备一个具备大小（宽高）的Dom -->
    <div id="main" style="width: 600px;height:400px;"></div>
    <script type="text/javascript">
        // 基于准备好的dom，初始化echarts实例
        var myChart = echarts.init(document.getElementById('main'));

//绘图代码，复制到echarts官网可直接画出图，记得修改data数组
var data = [
    [[1,1,0.25,'0.25'],[1,2,0.25,'0.25'],[1,4,0.71,'0.71'],[2,1,1.08,'1.08'],[2,2,10.10,'10.10'],[4,1,12.11,'12.11'],[1,8,2.79,'2.79'],[2,4,18.82,'18.82'],[4,2,39.56,'39.56'],[8,1,53.86,'53.86'],[1,16,4.24,"4.24"],[2,8,35.15,"35.15"],[4,4,75.14,"75.14"],[8,2,121.24,"121.24"]],
];

option = {
    xAxis: {
        name:"P"
    },
    yAxis: {
        scale: true,
        name:"Q"
    },
    series: [{
        data: data[0],
        type: 'scatter',
        symbolSize: function (data) {
            return data[2];
        },
        emphasis: {
            focus: 'self'
        },
        labelLayout: {
            y: 20,
            align: 'center',
            hideOverlap: true,
            moveOverlap: 'shiftX'
        },
        labelLine: {
            show: true,
            length2: 5,
            lineStyle: {
                color: '#bbb'
            }
        },
        label: {
            show: true,
            formatter: function (param) {
                return param.data[3];
            },
            minMargin: 10,
            position: 'top'
        }
    }]
};

 
        // 使用刚指定的配置项和数据显示图表。
        myChart.setOption(option);
    </script>
</body>
</html>
```



