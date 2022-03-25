///*
//  1. 尝试将环境变量改为 OMP_NUM_THREADS=2 和 OMP_NUM_THREADS=3 再编译运行程序试试
//  2. 尝试在 #pragma omp parallel 后添加num_threads(5) 试试
//*/
//#include <stdio.h>
//#include <omp.h>
//
//int main()
//{
//#pragma omp parallel num_threads(5)  // OpenMP 并行区域
//	{
//		// 花括号里的内容会被N个线程同时执行，N定义在环境变量OMP_NUM_THREADS中 
//		printf("Hello from thread %d of %d\n", omp_get_thread_num(), omp_get_num_threads());
//	}
//	return 0;
//}
