#ifndef __SQ_SERACH_H__
#define __SQ_SERACH_H__
#include "Assistance.h"					// ���������

template <class ElemType>
int SqSerach(ElemType elem[], int n, ElemType key)
// �������: ��˳����в��ҹؼ��ֵ�ֵ����key��Ԫ��,����ҳɹ�,�򷵻ش�Ԫ����˳�����±�,���򷵻�-1
{
	int i;		  // ѭ�����Ʊ��� 
	for (i = 0; i < n && elem[i] != key; i++)
	   		cout << "��Ԫ��" << elem[i] << "�Ƚ�" << endl;  // Ϊ���ٲ��ҹ��� 
	if (i < n)	  
		return i; // ���ҳɹ��������±� 
	else	
		return -1;// ����ʧ�ܣ�����-1
}

#endif
