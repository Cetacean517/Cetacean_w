//#include<stdio.h>
//#include<omp.h>
//#include<time.h>
//
//
//void comput(float* A, float* B, float* C)//两个矩阵for并行后优化方法
//{
//	 printf("thread = %d\n", omp_get_thread_num());
//	int x, y;
//	for (y = 0; y < 4; y++)
//	{
//		for (x = 0; x < 4; x++)
//		{
//			C[4 * y + x] = A[4 * y + 0] * B[4 * 0 + x] + A[4 * y + 1] * B[4 * 1 + x] +
//				A[4 * y + 2] * B[4 * 2 + x] + A[4 * y + 3] * B[4 * 3 + x];
//		}
//	}
//}
//
//int main()
//{
//	double  duration;
//	clock_t s, f;
//	int x = 0;
//	int y = 0;
//	int n = 0;
//	int k = 0;
//	float A[] = {
//		1,  2,  3,  4,
//		5,  6,  7,  8,
//		9,  10, 11, 12,
//		13, 14, 15, 16 };
//	float B[] = {
//		0.1f,   0.2f,  0.3f,   0.4f,
//		0.5f,   0.6f,  0.7f,   0.8f,
//		0.9f,   0.10f, 0.11f,  0.12f,
//		0.13f,  0.14f, 0.15f,  0.16f };
//	float C[16];
//
//
//	 test omp ///
//#pragma omp parallel for
//	for (int i = 0; i < 10; i++)
//	{
//		printf("Hello World %d from thread = %d\n", i, omp_get_thread_num());
//	}
//
//	 原始组  ///
//	s = clock();	//clock()：返回从“开启这个程序进程”到“程序中调用此函数时之间
//								的CPU时钟计时单元（clock tick）数
//	for (n = 0; n < 1000000; n++) 	comput(A, B, C);
//	f = clock();
//	duration = (double)(f - s) / CLOCKS_PER_SEC;
//	printf("Serial     :%f\n", duration);
//
//	 dynamic
//	s = clock();
//#pragma omp parallel for schedule(dynamic,500) num_threads(2)		//并行执行，且根据当前CPU负载动态分配线程(chunk_size,每个线程共执行几个for语句）
//	for (n = 0; n < 1000000; n++) {
//		if (n == 0) {
//			printf("totaltheads:%d\n", omp_get_num_threads());
//		}
//		comput(A, B, C);
//	}
//	f = clock();
//	duration = (double)(f - s) / CLOCKS_PER_SEC;
//	printf("500dynamic2:%f\n", duration);
//
//	s = clock();
//#pragma omp parallel for schedule(dynamic,500) num_threads(3)
//	for (n = 0; n < 1000000; n++) {
//		if (n == 0) {
//			printf("totaltheads:%d\n", omp_get_num_threads());
//		}
//		comput(A, B, C);
//	}
//	f = clock();
//	duration = (double)(f - s) / CLOCKS_PER_SEC;
//	printf("500dynamic8:%f\n", duration);
//
//	s = clock();
//#pragma omp parallel for schedule(dynamic,500)
//	for (n = 0; n < 1000000; n++) {
//		if (n == 0) {
//			printf("totaltheads:%d\n", omp_get_num_threads());
//		}
//		comput(A, B, C);
//	}
//	f = clock();
//	duration = (double)(f - s) / CLOCKS_PER_SEC;
//	printf("500dynamic8:%f\n", duration);
//
//	 static /// 
//	s = clock();
//#pragma omp parallel for schedule(static,500) num_threads(2)		//并行执行，且根据当前CPU负载动态分配线程
//	for (n = 0; n < 1000000; n++) {
//		if (n == 0) {
//			printf("totaltheads:%d\n", omp_get_num_threads());
//		}
//		comput(A, B, C);
//	}
//	f = clock();
//	duration = (double)(f - s) / CLOCKS_PER_SEC;
//	printf("static500:%f\n", duration);
//
//#pragma omp parallel for schedule(static,500) num_threads(3)		//并行执行，且根据当前CPU负载动态分配线程
//	for (n = 0; n < 1000000; n++) {
//		if (n == 0) {
//			printf("totaltheads:%d\n", omp_get_num_threads());
//		}
//		comput(A, B, C);
//	}
//	f = clock();
//	duration = (double)(f - s) / CLOCKS_PER_SEC;
//	printf("static500:%f\n", duration);
//
//
//
//
//	return 0;
//}
