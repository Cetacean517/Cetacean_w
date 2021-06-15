#ifndef __QUICK_SORT_H__
#define __QUICK_SORT_H__

#include "Assistance.h"				// ���������
template <class ElemType>
void QuickSort(ElemType elem[], int low, int high, int n)
// �������:������elem[low .. high]�е�Ԫ�ؽ��п�������
{
    ElemType e = elem[low];				// ȡ����Ԫ�� 
    int i = low, j = high;
	while (i < j)	{
		while (i < j && elem[j] > e)	// ʹj�ұߵ�Ԫ�ز�С������Ԫ��
			j--;
		if (i < j)
            elem[i++] = elem[j];

		while (i < j && elem[i] <= e)	// ʹi��ߵ�Ԫ�ز���������Ԫ��
			i++;
		if (i < j)
            elem[j--] = elem[i];
	}
	elem[i] = e;
    cout << "�������䣺" << low << "--" << high << ";����λ��Ϊ��" << i << endl; 
    Display(elem, n);
    cout << endl;
    if (low < i-1)	QuickSort(elem, low, i - 1, n);		// ���ӱ�elem[low, i - 1]�ݹ�����
	if (i + 1 < high) QuickSort(elem, i + 1, high, n);	// ���ӱ�elem[i + 1, high]�ݹ�����
}

#endif

