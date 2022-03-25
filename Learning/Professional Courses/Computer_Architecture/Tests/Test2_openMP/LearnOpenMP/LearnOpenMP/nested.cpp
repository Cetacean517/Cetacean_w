///*
//	1. 看看打印输出是否跟您想的一样，如果不一样，为什么？
//	2. 试着禁止嵌套并行;
//*/
//#include <stdio.h>
//#include <omp.h>
//
//int  main()
//{
//	omp_set_nested(1);   // 允许嵌套并行可用 
//
//#pragma omp parallel num_threads(2)
//	{
//		printf("Level 1, thread %d of %d\n", omp_get_thread_num(), omp_get_num_threads());
//
//		#pragma omp parallel num_threads(2)
//		{
//			printf("Level 2, thread %d of %d\n", omp_get_thread_num(), omp_get_num_threads());
//		}
//	}
//	return 0;
//}
