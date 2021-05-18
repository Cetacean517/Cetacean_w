#ifndef __HASH_TABLE_H__
#define __HASH_TABLE_H__


#define DELETE -1				// ɾ����� 
#define EMPTY  0				// �ձ�� 
#define USE    1				// ��Ԫ�ر�� 

#include "Assistance.h"						// ���������

// ɢ�б���
template <class ElemType, class KeyType>
class ClosedHashTable
{
protected:
//  ɢ�б�ĵ����ݳ�Ա:
	ElemType *ht;								// ɢ�б�
	int *tag;								    // ������� 
	int maxSize;								// ɢ�б�����
	int p;										// �����������ĳ���

//	��������:
	int H(KeyType key) const;					// ɢ�к���
	int Collision(KeyType key, int i) const;	// �����ͻ�ĺ���

public:
//  �������������������ر���ϵͳĬ�Ϸ�������:
  	ClosedHashTable(int size, int divisor);			// ���캯��
  	~ClosedHashTable();								// ���캯��
  	void Traverse(void (*Visit)(const ElemType &)) const;	// ����ɢ�б�
	int Search(const KeyType &key) const ;	    // ��Ѱ�ؼ���Ϊkey��Ԫ�ص��±� 
	Status Insert(const ElemType &e);				// ����Ԫ��e
	bool Delete(const KeyType &key);			// ɾ���ؼ���Ϊkey��Ԫ��
  	ClosedHashTable(const ClosedHashTable<ElemType, KeyType> &t);	// ���ƹ��캯��
  	ClosedHashTable<ElemType, KeyType> &operator=
		(const ClosedHashTable<ElemType, KeyType> &t);			// ��ֵ�������
};

// ɢ�б����ʵ�ֲ���
template <class ElemType, class KeyType>
int ClosedHashTable<ElemType, KeyType>::H(KeyType key) const
//�������: ����ɢ�е�ַ
{
	return key % p;
}

template <class ElemType, class KeyType>
int ClosedHashTable<ElemType, KeyType>::Collision(KeyType key, int i) const
//�������: ���ص�i�γ�ͻ��̽���ַ
{
	return (H(key) + i) % maxSize;
}

template <class ElemType, class KeyType>
ClosedHashTable<ElemType, KeyType>::ClosedHashTable(int size, int divisor)
// �������: ��sizeΪɢ�б�����, divisorΪ�����������ĳ�������һ���յ�ɢ���
{
	maxSize = size;						// ��ֵɢ�б�����
	p = divisor;						// ��ֵ����
	ht = new ElemType[maxSize];			// ����Ԫ�ش洢�ռ�
	tag = new int[maxSize];				// ����������洢�ռ�

	for (int i = 0; i < maxSize; i++)   // ������Ԫ���ÿ�
		tag[i] = 0;
}

template <class ElemType, class KeyType>
ClosedHashTable<ElemType, KeyType>::~ClosedHashTable()
// �������: ����ɢ�б�
{
	delete []ht;							// �ͷ�ɢ�б�
	delete []tag;							// �ͷű������ 
}

template <class ElemType, class KeyType>
void ClosedHashTable<ElemType, KeyType>::Traverse(void (*Visit)(const ElemType &)) const
// �������: ���ζ�ɢ�б��ÿ��Ԫ�ص��ú���(*visit)
{
	for (int i = 0; i < maxSize; i++)	// ��ɢ�б��ÿ��Ԫ�ص��ú���(*visit)
		if (tag[i] == DELETE)   	 
           cout << " * ";				// ����Ԫ���Ѿ�ɾ�� 
        else  	if (tag[i] == EMPTY)	
           cout << " # ";  				// ��λ��û��Ԫ��
        else 
			(*Visit)(ht[i]);			// ��λ����Ԫ��
}

template <class ElemType, class KeyType>
int ClosedHashTable<ElemType, KeyType>::Search(const KeyType &key) const
// �������: ��Ѱ�ؼ���Ϊkey��Ԫ�ص�ֵ,������ҳɹ�,����Ԫ����������±�,���򷵻�-1. 
{
	int c = 0;							// ��ͻ����
	int i = H(key);						// Ԫ�صĹ�ϣ����ֵ 

	while (c < maxSize &&	((tag[i] == USE && ht[i] != key) || tag[i] == DELETE))					
		// ��ͻ����ӦС��maxSize��Ԫ��ht[pos]�ǿ��ҹؼ���ֵ����
		i = Collision(key, ++c);		// �����һ��̽���ַ

	if (c >= maxSize || tag[i] == EMPTY)
		return -1;						// ����ʧ�ܣ�����-1 
	else 	
		return i;						// ���ҳɹ�������Ԫ���������е��±� 
}

template <class ElemType, class KeyType>
Status ClosedHashTable<ElemType, KeyType>::Insert(const ElemType &e)
// �������: ��ɢ�б��в�������Ԫ��e,����ɹ�����true,���򷵻�false
{
   int c = 0;							// ��ͻ����
   int i = H(e);						// Ԫ�صĹ�ϣ����ֵ 
   int k = -1;                     	// ����λ�� 

   while (c < maxSize &&	((tag[i] == USE && ht[i] != e) || tag[i] == DELETE)) {					
      // ��ͻ����ӦС��maxSize��Ԫ��ht[i]�ǿ��ҹؼ���ֵ����
      if (k == -1 && tag[i] == DELETE)
         k = i;
      i = Collision(e, ++c);		//�����һ��̽���ַ
   }

	if (c >= maxSize && k == -1)	   // ��ͻ����Ӧ���ڵ���maxSize��˵����ϣ���Ѿ����� 
		 return OVER_FLOW;
	else  if (tag[i] == USE && ht[i] == e)
     return ENTRY_FOUND;
  else  {		// ����ʧ�ܣ������Ԫ�� 
     if (k == -1)
        k = i;
     ht[k] = e;
     tag[k] = USE; 
		 return SUCCESS;
  }
}

template <class ElemType, class KeyType>
bool ClosedHashTable<ElemType, KeyType>::Delete(const KeyType &key)
// �������: ɾ���ؼ���Ϊkey������Ԫ��,ɾ���ɹ�����true,���򷵻�false
{
  int i = Search(key);
	if (i == -1)	                 // ����ʧ��,˵��Ԫ�ز����ڡ� 
		return false; 
	else	{	                       
		tag[i] = DELETE;				     // ����ɾ����� 
		return true;                 // ɾ���ɹ�
	}
}

template <class ElemType, class KeyType>
ClosedHashTable<ElemType, KeyType>::ClosedHashTable(const ClosedHashTable<ElemType, KeyType> &t)
// �����������ɢ�б�t������ɢ�б�--���ƹ��캯��
{
	maxSize = t.maxSize;										// ɢ�б�����
	p = t.p;										// �����������ĳ���
	ht = new ElemType[maxSize];							// ����洢�ռ�
	tag = new int[maxSize];							// ����洢�ռ�

	for (int i = 0; i < maxSize; i++)	{	// ��������Ԫ��
		ht[i] = t.ht[i];		// ����Ԫ��
		tag[i] = t.tag[i];// ����Ԫ���Ƿ�Ϊ��ֵ
	}
}

template <class ElemType, class KeyType>
ClosedHashTable<ElemType, KeyType> &ClosedHashTable<ElemType, KeyType>::
operator=(const ClosedHashTable<ElemType, KeyType> &t)
// �����������ɢ�б�t��ֵ����ǰɢ�б�--��ֵ�������
{
	if (&t != this)	{
		delete []ht;								// �ͷŵ�ǰɢ�б�洢�ռ�
		delete []tag;
		maxSize = t.maxSize;						// ɢ�б�����
		p = t.p;									// �����������ĳ���
		ht = new ElemType[maxSize];					// ����洢�ռ�
		tag = new int[maxSize];						// ����洢�ռ�

		for (int i = 0; i < maxSize; i++)		{	// ��������Ԫ��
			ht[i] = t.ht[i];	// ����Ԫ��
			tag[i] = t.tag[i];// ����Ԫ���Ƿ�Ϊ��ֵ
		}
	}
	return *this;
}

#endif
