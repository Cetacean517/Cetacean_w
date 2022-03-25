/*
   1. 变量的作用范围在并行程序设计中非常重要
   2. 如果在并行区域再加一个私有的a变量，想想会发生什么？
*/
#include <iostream>
#include <omp.h>

int main()
{
	int a = -1;
#pragma omp parallel
	{
		// a在并行块内部是共享(默认)的，所有线程都有权操作它(操作的都是同一个变量，没有备份)，而且并行快结束后，块内代码对其的修改有效
		int b;     // 在并行区域外不可见，每个线程有一个备份拷贝
		a = omp_get_thread_num() + 100;
		b = omp_get_thread_num() + 200;
	}
	std::cout << "a = " << a << std::endl;   // 理论上这里的输出是[100+0,100+threads)之间随机的, 得看哪个线程最后执行完
	//	b = 0;   // 对外不可见，这里会发生错误，所以注释
	return 0;
}
