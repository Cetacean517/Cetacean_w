///*
//   程序说明： 我们会发现打印在控制台的内容是乱的，这是因为在一个线程还没输出完成时，另一个线程就抢着要输出了！
//*/
//#include <iostream>
//#include <sstream>
//#include <omp.h>
//
//int main()
//{
//#pragma omp parallel
//	{
//		std::cout << "Hello from thread " << omp_get_thread_num() << " of " << omp_get_num_threads() << std::endl;
//	}
//	return 0;
//}
