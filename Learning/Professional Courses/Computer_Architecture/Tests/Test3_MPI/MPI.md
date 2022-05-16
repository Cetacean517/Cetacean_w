# MPI

## 实验要求

![image-20220506091453909](D:\Cetacean517\Cetacean_w\Learning\Professional Courses\Computer_Architecture\Tests\Test3_MPI\Notepic\image-20220506091453909.png)

![image-20220506091521421](D:\Cetacean517\Cetacean_w\Learning\Professional Courses\Computer_Architecture\Tests\Test3_MPI\Notepic\image-20220506091521421.png)

## 使用指南

​	url = https://zhuanlan.zhihu.com/p/355652501

## 安装步骤：Ubuntu 18.04

url =  https://blog.csdn.net/qq_39451578/article/details/107938560

### 1. 查看已经安装如下软件

gcc --version
g++ --version
cmake --version
gfortran --version

没有安装可以用 sudo apt install xxx 安装

### 2. 下载原码

wget https://www.mpich.org/static/downloads/3.0/mpich-3.0.tar.gz

### 3. 解压

sudo tar -zxvf mpich-3.0.tar.gz

### 4. 配置路径

 进入解压缩的文件夹：cd mpich-3.0

配置路径：sudo ./configure -prefix=/home/mpi/mpich3 （提前建好了文件夹）

### 5. 编译和安装

sudo make

sudo make install

### 6. 添加环境变量

sudo gedit ~/.bashrc

文件最后添加以下几句话

```cmake
export MPI_ROOT=/home/mpi/mpich3
export PATH=$MPI_ROOT/bin:$PATH
export MANPATH=$MPI_ROOT/man:$MANPATH
```

# 实验部分

## 1. 测试(实验一)

### 1. 样例文件

​      任意地址，新建一个测试文件mpi_hello.cpp

```c++
#include <iostream>
#include <string.h>
#include <mpi.h>
using namespace std;

const int max_string = 100;

int main ()
{
	int comm_sz;
	int my_rank;
	char greeting[max_string];
	
	MPI_Init(&argc, &argv)； // 函数初始化，获取命令行参数。有两个形参
    MPI_Comm_rank(MPI_COMM_WORLD,&my_rank); 
    						// 获得当前进程的进程标识.参数1：进程当前通信域；参数2：进程返回的进程号 MPI_COMM_WORLD：已定义好，包含所有进程的通信域
    MPI_Comm_size(MPI_COMM_WORLD,&comm_sz);
    						// 获取该通信域内的总进程数。 MPI_COMM_WORLD下，获取总进程数

	 if(my_rank!=0){
		sprintf(greeting,"Greetings from process %d of %d!",my_rank,comm_sz);
		MPI_Send(greeting,strlen(greeting),MPI_CHAR,0,0,MPI_COMM_WORLD);
         					// 发送函数，用于进程间发送消息。
       // int MPI_Send(type* buf, int count, MPI_Datatype, int dest, int tag, MPI_Comm comm) 
       // buf:传参起始地址
       // count：传参长度
       // MPI_Datatype:MPI预定义的数据类型
       // dest:接收的进程号
       // tag：信息标志，同为整型变量，发送和接收需要tag一致。区分同一目的地的不同消息。
	}
	else{
		cout<<"Greetings from process "<<my_rank<<" of "<<comm_sz<<"!"<<endl;
		for(int i=1;i<comm_sz;i++){
			MPI_Recv(greeting,max_string,MPI_CHAR,i,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
       						// MPI的接收函数
       // int MPI_Recv(type* buf, int count, MPI_Datatype, int source, int tag, MPI_Comm comm, MPI_Status *status) 
       // source: 从哪个进程接收消息
       // status: status.MPI_SOURCE  所收到数据发送源的进程号
       //	      status.MPI_TAG     该消息的tag值
       //         status.MPI_ERROR   接收操作的错误代码
			cout<<greeting<<endl;
		}
	}
	
	MPI_Finalize (); // 结束的时候需要调用
	return 0;
}


```

### 2. 终端编译和运行

​	重新打开terminal，进行编译

​    `mpicxx -g -Wall -o mpi_hello.o mpi_hello.cpp`

- mpicc         是编译C程序的
- mpicxx        是编译C++程序的
- -g            允许使用调试器
- -Wall         显示警告（W大写）
- -o outfile.o  编译出可执行的文件，文件名为outfile.o
- -02           告诉编译器对代码进行优化

运行：可由-n后面的数字来调节创建进程数。

`mpirun -n 5 ./mpi_hello.o`

### 3. 运行结果

![image-20220506110835581](D:\Cetacean517\Cetacean_w\Learning\Professional Courses\Computer_Architecture\Tests\Test3_MPI\Notepic\image-20220506110835581.png)



## 2. 实验二：多进程并行程序

改写一个串行代码：

```c++
int sum=0; 
for(int i=0;i<2;i++) 
{ 
    for(int j=0;j<4;j++) 
    { 
        sum=sum+A[i][j]; 
    } 
} 
```



代码：矩阵求和

```c++
#include <iostream>
#include <string.h>
#include <mpi.h>
using namespace std;

int main(int argc, char* argv[]){
    int myid,comm_sz, s=0,s1=0, sum=0, i=0;
    MPI_Status status;

    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&myid);        //得到的变量myid即为当前的进程号
    MPI_Comm_size(MPI_COMM_WORLD,&comm_sz);
    //假设要求和的数组为A={[1,1,1,1],[2,2,2,2]}
    if(myid!=0)
    {
        int A[4] = {myid,myid,myid,myid};   //将数组A全赋值为myid的值
        for(int i=0;i<4;i++)
        {
            cout << A[i] << " ";
            s=s+A[i];
        }
        cout << endl;
        MPI_Send(&s,1,MPI_INT,0,myid,MPI_COMM_WORLD);
        //将求和结果s发送到进程0
    }
    else if(myid == 0)
    {   
        for (i = 1; i < comm_sz; i++){
        MPI_Recv(&s1,1,MPI_INT,i,i,MPI_COMM_WORLD,&status);
        //用s1这个变量来存储从进程1发送来的求和结果
        sum+=s1;
        }
        cout << "total comm:" << comm_sz << endl;
        cout << "sum:" << sum << endl;
    }
    MPI_Finalize();
}
```



编译：mpicxx -g -Wall -o mpi_arrsum.o mpi_arrsum.cpp

运行：mpirun -n 5 ./mpi_arrsum.o

运行结果

![image-20220506135305536](D:\Cetacean517\Cetacean_w\Learning\Professional Courses\Computer_Architecture\Tests\Test3_MPI\Notepic\image-20220506135305536.png)

## 3. 实验三：矩阵乘法并行实现

参考资料：https://blog.csdn.net/xx_123_1_rj/article/details/41151863

编译：mpicxx -g -Wall -o arrmul.o arrmul.cpp

运行：mpirun -n 3 ./arrmul.o

阶数为200的两个矩阵相乘，得到矩阵C求和的结果= 1600000000
$$
A= \begin{bmatrix}
   1 & 2 & 3 ... & n\\
   2 & 3 & 4 ... & n+1\\
   3 & 4 & 5 ... & n+2 \\
   ...\\
   ...\\
   n & n+1 & n+2 ... & 2n-1
   
  \end{bmatrix} \times
 B= \begin{bmatrix}
   1 & 1 & 1 ... & 1\\
   1 & 1 & 1 ... & 1\\
   1 & 1 & 1 ... & 1\\
   ...\\
   ...\\
   1 & 1 & 1 ... & 1
   
  \end{bmatrix}
$$

```c++

#include <stdio.h>
#include  "mpi.h"
#define N 200                     //矩阵的阶数
#define MASTER 0                  //主进程号
#define FROM_MASTER 1             //设置消息类型
#define FROM_WORKER 2             //设置消息类型
MPI_Status status;
int main(int argc,char **argv)
{
    int numtasks,                   //进程总数
         taskid,                    //进程标识
         numworkers,                //从进程数目
         source,                    //消息源
         dest,                      //消息目的地
         mtype,                     //消息类型
         rows,                     
         averow,extra,offset,       //从进程所分的行数
         i,j,k,t,
         count;
   double A[N][N],B[N][N];
   long long C[N][N];
   long long sumand = 0;           //求的乘积矩阵的所有元素的和
   double starttime,endtime;
   MPI_Init(&argc,&argv);   					// 初始化MPI环境
   MPI_Comm_rank(MPI_COMM_WORLD,&taskid);		//标识各个MPI进程 ，告诉调用该函数进程的当前进程号
   MPI_Comm_size(MPI_COMM_WORLD,&numtasks);		//用来标识相应进程组中有多少个进程
   numworkers = numtasks-1;     				//从进程数目
 
/* 程序采用主从模式。第一部分：主进程程序 */
   
if(taskid==MASTER)
{
	printf("--------主进程开始对矩阵A、B初始化\n");
    //任务一：对A矩阵B矩阵 进行初始化赋值
    for(i=0;i<N;i++)
	{
		t = i + 1; 
        for(j=0;j<N;j++)
	    {
           A[i][j]= t ++ ;
           B[i][j]= 1;
	    }
	}
    // 任务二：
	printf("--------主进程开始对从进程发送数据\n");
    /*将数据(A矩阵B矩阵)发送到从进程*/
    averow=N/numworkers;   // 每个从进程所得到的行数
    extra=N%numworkers;
    offset=0;
    mtype=FROM_MASTER;
    for(dest=1;dest<=numworkers;dest++)
    {
        rows=(dest<=extra)?  averow+1:averow;
		//发送标识每个从进程开始寻找数据矩阵的偏移地址
        MPI_Send(&offset,1,MPI_INT,dest,mtype,MPI_COMM_WORLD);
		//发送每个从进程需要计算的行数
        MPI_Send(&rows,1,MPI_INT,dest,mtype,MPI_COMM_WORLD);
		//发送每个从进程 count=rows*N 比特流偏移量
        count=rows*N;
		//发送 矩阵 A
        MPI_Send(&A[offset][0],count,MPI_DOUBLE,dest,mtype,MPI_COMM_WORLD);
         count=N*N;
		 //发送矩阵 B
        MPI_Send(&B,count,MPI_DOUBLE,dest,mtype,MPI_COMM_WORLD);
        offset=offset+rows;
    }
	printf("--------主进程等待从进程计算结果\n");
    
     /*第二部分：等待接收从进程计算结果*/
	starttime = MPI_Wtime(); // 矩阵开始计算的时间
    mtype=FROM_WORKER;
    for(i=1;i<=numworkers;i++)
    {
        source=i; // 主进程 接受 从 从进程上发送的数据 ( C 矩阵)
		printf("主进程接受从进程号为 = %d\n",i);
        MPI_Recv(&offset,1,MPI_INT,source,mtype,MPI_COMM_WORLD,&status);
        MPI_Recv(&rows,1,MPI_INT,source,mtype,MPI_COMM_WORLD,&status);
        count=rows*N;
        MPI_Recv(&C[offset][0],count,MPI_DOUBLE,source,mtype,MPI_COMM_WORLD,&status);
    }
	endtime =  MPI_Wtime(); // 矩阵 结束计算的时间
	printf("********两矩阵相乘的时间为 :=%f\n",endtime - starttime);
 
    /*主进程计算 结果矩阵的 所有元素的和 为验证结果*/
 
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
			sumand += C[i][j];
    }
	printf("--------主进程对矩阵C求和 sumand= %lld\n",sumand); 
}
    
/* 从进程 接受数据 并 计算乘积 */
if(taskid>MASTER)
{
    mtype=FROM_MASTER;
    source=MASTER;
	//接受主进程发送的数据偏移值
	printf("\n++++++++该从进程开始从主进程上接受数据\n");
    MPI_Recv(&offset,1,MPI_INT,source,mtype,MPI_COMM_WORLD,&status);
	printf("++++++++该从进程的偏移量为：=%d\n",offset);
	//接收主进程发送到从进程需要计算的 行数
    MPI_Recv(&rows,1,MPI_INT,source,mtype,MPI_COMM_WORLD,&status);
	printf("++++++++该从进程需要计算的行数为: =%d\n",rows);
 
    count=rows*N;//接受矩阵A
    MPI_Recv(&A,count,MPI_DOUBLE,source,mtype,MPI_COMM_WORLD,&status);
 
    count=N*N;  //接受矩阵B
    MPI_Recv(&B,count,MPI_DOUBLE,source,mtype,MPI_COMM_WORLD,&status);
 
    for(k=0;k<N;k++)  //计算乘积
    for(i=0;i<rows;i++)
    {
        C[i][k]= 0.0;
        for(j=0;j<N;j++)
            C[i][k] = C[i][k] + A[i][j] * B[j][k];
    }
    mtype=FROM_WORKER; // 把从矩阵计算乘积的 结果发送到 主进程上
    MPI_Send(&offset,1,MPI_INT,MASTER,mtype,MPI_COMM_WORLD);
    MPI_Send(&rows,1,MPI_INT,MASTER,mtype,MPI_COMM_WORLD);
    MPI_Send(&C,rows*N,MPI_DOUBLE,MASTER,mtype,MPI_COMM_WORLD);
}
MPI_Finalize();
}
```



## 4. 实现pi 

编译：mpicc -o pi.o pi.c

运行：mpirun -n 6 ./pi.o

代码cpi.c

```c
#include "mpi.h"
#include <stdio.h>
#include <math.h>

double f(double);

double f(double a)
{
    return (4.0 / (1.0 + a * a));
}

int main(int argc, char *argv[])
{
    int n, myid, numprocs, i;
    double PI25DT = 3.141592653589793238462643;
    double mypi, pi, h, sum, x;
    double startwtime = 0.0, endwtime;
    int namelen;
    char processor_name[MPI_MAX_PROCESSOR_NAME];

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);
    MPI_Get_processor_name(processor_name, &namelen);

    fprintf(stdout, "Process %d of %d is on %s\n", myid, numprocs, processor_name);
    fflush(stdout);

    n = 10000;  /* default # of rectangles */
    if (myid == 0)
        startwtime = MPI_Wtime();

    MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);

    h = 1.0 / (double) n;
    sum = 0.0;
    /* A slightly better approach starts from large i and works back */
    for (i = myid + 1; i <= n; i += numprocs) {
        x = h * ((double) i - 0.5);
        sum += f(x);
    }
    mypi = h * sum;

    MPI_Reduce(&mypi, &pi, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    if (myid == 0) {
        endwtime = MPI_Wtime();
        printf("pi is approximately %.16f, Error is %.16f\n", pi, fabs(pi - PI25DT));
        printf("wall clock time = %f\n", endwtime - startwtime);
        fflush(stdout);
    }

    MPI_Finalize();
    return 0;
}

```



![image-20220512225720987](D:\Cetacean517\Cetacean_w\Learning\Professional Courses\Computer_Architecture\Tests\Test3_MPI\Notepic\image-20220512225720987.png)
