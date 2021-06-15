//#include <iostream>
//using namespace std;
//
//void QuickSort(int elem[], int low, int high) {
//	int e = elem[low];
//	int i = low, j = high;
//	while (i < j) {
//		while (i < j && elem[j] >= e) j--;
//		if (i < j)
//		{
//			elem[i++] = elem[j];
//			//i++;
//		}
//		while (i < j && elem[i] <= e)i++;
//		if (i < j)
//		{
//			elem[j--] = elem[i];
//			//j--;
//		}
//	}
//	elem[i] = e;
//	if (low < i - 1) QuickSort(elem, low, i - 1);
//	if (i + 1 > high)QuickSort(elem, i + 1, high);
//}
//int main() {
//	int a[6] = {23,31,49,31,6,23};
//	for (int i = 0; i < 6; i++) {
//		cout << a[i] <<',';
//	}
//	cout << endl;
//	QuickSort(a, 0, 5);
//	for (int i = 0; i < 6; i++) {
//		cout << a[i] << ',';
//	}
//	return 0;
//}