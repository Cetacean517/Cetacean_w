//#include<stdio.h>
//#include<stdlib.h>
//#include<omp.h>
//#include<time.h>
//#include<iostream>
//#define NUM_THREADS 4
//using namespace std;
//
//int Partition(int* data, int p, int r)
//{
//	int x, i, j, tmp;
//	//即A[r]
//	x = data[r];
//	i = p - 1;
//	for (j = p; j < r; j++)
//		if (data[j] <= x)
//		{
//			i++;
//			//exchange A[i] and A[j]
//			tmp = data[i];
//			data[i] = data[j];
//			data[j] = tmp;
//		}
//	//exchange A[i+1] and A[r]
//	tmp = data[i + 1];
//	data[i + 1] = data[r];
//	data[r] = tmp;
//
//	return i + 1;
//}
//void QuickSort_parallel(int* Data, int p, int r)
//{
//	int q;
//	if (p < r)
//	{
//		q = Partition(Data, p, r);
//#pragma omp parallel 
//		{
//#pragma omp sections nowait
//			{
//#pragma omp section
//				QuickSort_parallel(Data, p, q - 1);
//#pragma omp section
//				QuickSort_parallel(Data, q + 1, r);
//			}
//		}
//	}
//	return;
//}
//void QuickSort(int* Data, int p, int r)
//{
//	int q;
//	if (p < r)
//	{
//		q = Partition(Data, p, r);
//		{
//			{
//				QuickSort(Data, p, q - 1);
//				QuickSort(Data, q + 1, r);
//			}
//		}
//	}
//	return;
//}
//void main()
//{
//	int N;
//	printf("输入产生多少个数进行排序：");
//	cin >> N;
//	int* Data;
//	int* Data1;
//	Data = new int[N];
//	Data1 = new int[N];
//	for (int i = 0; i < N; i++) {
//		//0~32765
//		Data[i] = rand();
//		Data1[i] = Data[i];
//	}
//	clock_t timep0 = clock();
//	QuickSort(Data, 0, N - 1);
//	clock_t timeFinish0 = clock();
//	printf("非并行快速排序所花时间：%d ms\n", timeFinish0 - timep0);
//
//	clock_t timep = clock();
//	omp_set_num_threads(NUM_THREADS);
//	QuickSort_parallel(Data1, 0, N - 1);
//	clock_t timeFinish = clock();
//	printf("并行快速排序所花时间：%d ms\n", timeFinish - timep);
//}