//#include <stdio.h>
//#include <omp.h>
//#include <time.h>
////reduction
//
//
//void Multi() {
//	int i, n, chunk;
//	float a[100000], b[100000], result;
//	//some initializations
//	n = 100000;
//	result = 0.0;
//	for (i = 0; i < n; i++) {
//		a[i] = i * 1.0;
//		b[i] = i * 2.0;
//	}
//
//	for (i = 0; i < n; i++)
//		result = result + (a[i] * b[i]);
//
//	printf("%f\n", result);
//}
//
//void Multi_pll() {
//	int i, n, chunk;
//	float a[100000], b[100000], result;
//	//some initializations
//	n = 100000;
//	chunk = 500;
//	result = 0.0;
//	for (i = 0; i < n; i++) {
//		a[i] = i * 1.0;
//		b[i] = i * 2.0;
//	}
//#pragma omp parallel for default(shared)private(i)schedule(static,chunk)reduction(+:result)
//
//	for (i = 0; i < n; i++)
//		result = result + (a[i] * b[i]);
//
//	printf("%f\n", result);
//}
//int main() {
//	clock_t timep0 = clock();
//	Multi();
//	clock_t timeFinish0 = clock();
//	printf("非并行快速排序所花时间：%d ms\n", timeFinish0 - timep0);
//
//	clock_t timep = clock();
//	omp_set_num_threads(2);
//	Multi_pll();
//	clock_t timeFinish = clock();
//	printf("并行快速排序所花时间：%d ms\n", timeFinish - timep);
//}