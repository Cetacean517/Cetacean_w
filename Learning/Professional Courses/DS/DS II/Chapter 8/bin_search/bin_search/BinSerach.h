#ifndef __BIN_SERACH_H__
#define __BIN_SERACH_H__
#include "Assistance.h"					// ���������

template <class ElemType>
int BinSerach(ElemType elem[], int n, ElemType key)
// �������: �����㷨����������в�����ؼ��ֵ�ֵ����key��Ԫ��,����ҳɹ�,�򷵻ش�Ԫ�ص����,���򷵻�-1
{
	int low = 0, high = n -1;		// ���ò�����������ұ߽�
	int mid;
	
	while (low <= high)	{
		mid = (low + high) / 2;	    // ���������м�λ��

		cout << "��Ԫ��" << elem[mid] << "�Ƚ�" << endl;   // Ϊ���ٲ��ҹ��� 
		
		if (key == elem[mid])	
			return mid;             // ���ҳɹ�
		else if (key <= elem[mid])	
			high = mid - 1;         // ���������������в���
		else	
			low = mid + 1;          // �������Ұ�������в���
	}

	return -1;	                    // ����ʧ��
}

template <class ElemType>
int BinSerach(ElemType elem[], int low, int high, ElemType key)
// �������: �ݹ��㷨����������в�����ؼ��ֵ�ֵ����key��Ԫ��,����ҳɹ�,�򷵻ش�Ԫ�ص����,���򷵻�-1
{
	int mid;
	
	if (low > high)
        mid = -1; // ����ʧ��
    else {
		mid = (low + high) / 2;	    // ���������м�λ��

		cout << "��Ԫ��" << elem[mid] << "�Ƚ�" << endl;  // Ϊ���ٲ��ҹ��� 

		if (key < elem[mid])	
			mid = BinSerach(elem, low, mid - 1, key); // ���������������в���
		else if (key > elem[mid])	
			mid = BinSerach(elem, mid + 1, high, key);// �������Ұ�������в���
	}

	return mid;	                   
}


#endif
