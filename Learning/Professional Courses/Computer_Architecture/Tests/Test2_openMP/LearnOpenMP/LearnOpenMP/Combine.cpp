 //归并排序
#include <corecrt_malloc.h>
#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include<time.h>
#include<iostream>
#define NUM_THREADS 8
using namespace std;


//合并两个区间
void merge(int l1, int r1, int r2, int* data, int* temp) {
    int top = l1, p = l1, q = r1;
    while (p < r1 || q < r2) {
        if (q >= r2 || (p < r1 && data[p] <= data[q])) {
            temp[top++] = data[p++];
        }
        else {
            temp[top++] = data[q++];
        }
    }
    for (top = l1; top < r2; top++) {
        data[top] = temp[top];
    }
}

 //串行代码
void merge_sort1(int r, int* data, int N) {
    int i, j, t, * temp;
    temp = (int*)malloc(N * sizeof(int));
    for (i = 0; i < N / 2; i++)
        if (data[i * 2] > data[i * 2 + 1]) {
            t = data[i * 2];
            data[i * 2] = data[i * 2 + 1];
            data[i * 2 + 1] = t;
        }
    for (i = 2; i < r; i *= 2) {
        for (j = 0; j < r - i; j += i * 2) {
            merge(j, j + i, (j + i * 2 < r ? j + i * 2 : r), data, temp);
        }
    }
}

 //并行代码
void merge_sort2(int r, int* data, int N) {
    int i, j, t, * temp;
    temp = (int*)malloc(N * sizeof(int));
    //这里做了一些优化，预处理合并了单个的区间，略微提高的速度
#pragma omp parallel for private(i, t) shared(N, data)
    for (i = 0; i < N / 2; i++)
        if (data[i * 2] > data[i * 2 + 1]) {
            t = data[i * 2];
            data[i * 2] = data[i * 2 + 1];
            data[i * 2 + 1] = t;
        }

    //i代表每次归并的区间长度，j代表需要归并的两个区间中最小的下标
    for (i = 2; i < r; i *= 2) {
#pragma omp parallel for private(j) shared(r, i)
        for (j = 0; j < r - i; j += i * 2) {
            merge(j, j + i, (j + i * 2 < r ? j + i * 2 : r), data, temp);
        }
    }
}

void main()
{
	int N;
	printf("输入产生多少个数进行排序：");
	cin >> N;
	int* Data;
    int* Data1;
	Data = new int[N];
    Data1 = new int[N];
	for (int i = 0; i < N; i++) {
		//0~32765
		Data[i] = rand();
        Data1[i] = Data[i];
	}
	clock_t timep0 = clock();
	merge_sort1(N - 1, Data, N - 1);
	clock_t timeFinish0 = clock();
	printf("非并行快速排序所花时间：%d ms\n", timeFinish0 - timep0);

	clock_t timep = clock();
	omp_set_num_threads(NUM_THREADS);
    merge_sort2(N-1,Data1, N - 1);
	clock_t timeFinish = clock();
	printf("并行快速排序所花时间：%d ms\n", timeFinish - timep);
}
