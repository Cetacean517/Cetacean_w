///*
//	for循环的并行
//*/
//#include <iostream>
//
//int main()
//{
//	const int size = 50;
//	int a[size];
//
//#pragma omp parallel for
//	for (int i = 0; i < size; i++)
//		a[i] = i;                     // 这里的代码是并行执行的
//
//	for (int i = 0; i < size; i++)    // 这里是串行执行的，#pragma omp parallel for作用范围只有紧接着的for循环，当然这个for循环是可以嵌套的.
//		std::cout << a[i] << std::endl;
//
//	return 0;
//}
