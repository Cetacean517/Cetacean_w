#ifndef __ASSISTANCE_H__				// ���û�ж���__ASSISTANCE_H__
#define __ASSISTANCE_H__				// ��ô����__ASSISTANCE_H__

// ���������

#ifdef _MSC_VER						// ��ʾ��VC 
#if _MSC_VER == 1200				// ��ʾVC6.0

// ��׼��ͷ�ļ�
#include <string.h>					// ��׼���Ͳ���
#include <iostream.h>				// ��׼������
#include <limits.h>					// ����
#include <math.h>					// ��ѧ����
#include <fstream.h>				// �ļ��������
#include <ctype.h>				 	// �ַ�����
#include <time.h>				 	// ���ں�ʱ�亯��
#include <stdlib.h>					// ��׼��
#include <stdio.h>					// ��׼�������
#include <iomanip.h>				// �����������ʽ����	
#include <stdarg.h> 				// ֧�ֱ䳤��������	
#include <assert.h>					// ֧�ֶ���

#else								// �����汾��VC++

// ANSI C++��׼��ͷ�ļ�
#include <string>					// ��׼���Ͳ���
#include <iostream>					// ��׼������
#include <limits>					// ����
#include <cmath>					// ��ѧ����
#include <fstream>					// �ļ��������
#include <cctype>					// �ַ�����
#include <ctime>       				// ���ں�ʱ�亯��
#include <cstdlib>					// ��׼��
#include <cstdio>       			// ��׼�������
#include <iomanip>					// �����������ʽ����	
#include <cstdarg> 					// ֧�ֱ䳤��������	
#include <cassert>					// ֧�ֶ���
using namespace std;				// ��׼������������ռ�std��

#endif	// _MSC_VER == 1200
#else								// ��VC 

// ANSI C++��׼��ͷ�ļ�
#include <string>					// ��׼������
#include <iostream>					// ��׼������
#include <limits>					// ����
#include <cmath>					// ���ݺ���
#include <fstream>					// �ļ��������
#include <cctype>					// �ַ�����
#include <ctime>       				// ���ں�ʱ�亯��
#include <cstdlib>					// ��׼��
#include <cstdio>       			// ��׼�������
#include <iomanip>					// �����������ʽ����	
#include <cstdarg> 					// ֧�ֱ䳤��������	
#include <cassert>					// ֧�ֶ���
using namespace std;				// ��׼������������ռ�std��

#endif	// _MSC_VER



// �Զ�������
enum Status {SUCCESS, FAIL, UNDER_FLOW, OVER_FLOW,RANGE_ERROR, DUPLICATE_ERROR,
	NOT_PRESENT, ENTRY_INSERTED, ENTRY_FOUND, VISITED, UNVISITED};

// �궨��
#define DEFAULT_SIZE 1000			// ȱʡԪ�ظ���
#define DEFAULT_INFINITY 1000000	// ȱʡ�����


// ��������������
template <class ElemType >
void Swap(ElemType &e1, ElemType &e2);	// ����e1, e2ֵ֮
template<class ElemType>
void Display(ElemType elem[], int n);	// ��ʾ����elem�ĸ�����Ԫ��ֵ
template <class ElemType>
void Write(const ElemType &e);			// ��ʾ����Ԫ��


// ����������ʵ�� 
template <class ElemType >
void Swap(ElemType &e1, ElemType &e2)
// �������: ����e1, e2ֵ֮
{
	ElemType temp;		// ��ʱ����
	// ѭ����ֵʵ�ֽ���e1, e2
	temp = e1;	e1 = e2;  e2 = temp;
}

template<class ElemType>
void Display(ElemType elem[], int n)
// �������: ��ʾ����elem�ĸ�����Ԫ��ֵ
{
	for (int i = 0; i < n; i++)	// ��ʾ����elem
		cout << elem[i] << "  ";
	cout << endl; 
}

template <class ElemType>
void Write(const ElemType &e)
// �������: ��ʾ����Ԫ��
{
    cout << e << "  ";
}

#endif
