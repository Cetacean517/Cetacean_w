#ifndef __LK_STACK_H__
#define __LK_STACK_H__

#include "Assistance.h"			// ���������
#include "node.h"				// �����

// ��ջ��
template<class ElemType>
class LinkStack 
{
protected:
//  ��ջ�����ݳ�Ա:
	Node<ElemType> *top;							// ջ��ָ��

public:
//  ��ջ�ĺ�����Ա:
	LinkStack();									// �޲����Ĺ��캯��
	virtual ~LinkStack();							// ��������
	int GetLength() const;							// ��ջ����			 
	bool IsEmpty() const;							// �ж�ջ�Ƿ�Ϊ��
	void Clear();									// ��ջ���
	void Traverse(void (*Visit)(const ElemType &)) const ;	// ����ջ
	Status Push(const ElemType e);					// ��ջ
	Status Top(ElemType &e) const;					// ����ջ��Ԫ��
	Status Pop(ElemType &e);						// ��ջ
	LinkStack(const LinkStack<ElemType> &s);		// ���ƹ��캯��
	LinkStack<ElemType> &operator =(const LinkStack<ElemType> &s); // ��ֵ�������
};


// ��ջ���ʵ�ֲ���
template<class ElemType>
LinkStack<ElemType>::LinkStack()
// �������������һ����ջ��
{
	top = NULL;	
}

template<class ElemType>
LinkStack<ElemType>::~LinkStack()
// �������������ջ
{
	Clear();
}

template <class ElemType>
int LinkStack<ElemType>::GetLength() const
// �������������ջԪ�ظ���
{
	int count = 0;		// ������ 
	Node<ElemType> *p; 
	for (p = top; p != NULL; p = p->next)		// ��p������Ѱÿ��Ԫ��
		count++;		// ͳ����ջ�н����
	return count;
}

template<class ElemType>
bool LinkStack<ElemType>::IsEmpty() const
// �����������ջΪ�գ��򷵻�true�����򷵻�false
{
	return top == NULL;
}

template<class ElemType>
void LinkStack<ElemType>::Clear()
// ������������ջ
{
	Node<ElemType> *p; 
	while (top != NULL) {
		p = top;
		top = top->next;
		delete p;
	}		
}

template <class ElemType>
void LinkStack<ElemType>::Traverse(void (*Visit)(const ElemType &)) const
// �����������ջ����ջ�����ζ�ջ��ÿ��Ԫ�ص��ú���(*visit)���� 
{
	Node<ElemType> *p;		
	for (p = top; p != NULL; p = p->next)	// ��p������Ѱ��ǰջ��ÿ��Ԫ��
		(*Visit)(p->data);		// ��p��ָ���Ԫ�ص��ú���(*visit)���� 
}

template<class ElemType>
Status LinkStack<ElemType>::Push(const ElemType e)
// �����������Ԫ��e׷�ӵ�ջ��,��ɹ��򷵼�SUCCESS,�����綯̬�ڴ��Ѻľ�
//	������OVER_FLOW
{
	Node<ElemType> *p = new Node<ElemType>(e, top);
	if (p == NULL) 	// ϵͳ�ڴ�ľ�
		return OVER_FLOW;
	else	{	// �����ɹ�
		top = p;
		return SUCCESS;
	}
}

template<class ElemType>
Status LinkStack<ElemType>::Top(ElemType &e) const
// �����������ջ�ǿ�,��e����ջ��Ԫ��,��������SUCCESS,����������UNDER_FLOW
{
	if(IsEmpty())	// ջ��
		return UNDER_FLOW;
	else	{	// ջ�ǿ�,�����ɹ�
		e = top->data;				// ��e����ջ��Ԫ��
		return SUCCESS;
	}
}

template<class ElemType>
Status LinkStack<ElemType>::Pop(ElemType &e)
// �����������ջ�ǿ�,ɾ��ջ��Ԫ��,����e����ջ��Ԫ��,��������SUCCESS,����
//	��������UNDER_FLOW
{
	if (IsEmpty())	// ջ��
		return UNDER_FLOW;
	else	{	// �����ɹ�
		Node<ElemType> *p = top;	// ����ԭջ��
		e = top->data;				// ��e����ջ��Ԫ��
		top = top->next;			// �޸�ջ��
		delete p;					// ɾ��ԭջ����� 
		return SUCCESS;
	}
}

template<class ElemType>
LinkStack<ElemType>::LinkStack(const LinkStack<ElemType> &s) 
// �����������ջs������ջ--���ƹ��캯��
{
	if (s.IsEmpty())	// sΪ��
		top = NULL;									// ����һ��ջ
	else 	{	                                    // s�ǿ�,����ջ
		top = new Node<ElemType>(s.top->data);	// ���ɵ�ǰջ��
		Node<ElemType> *q = top;			        // ���õ�ǰջ��ָ��
		for (Node<ElemType> *p = s.top->next; p != NULL; p = p->next){
			q->next = new Node<ElemType>(p->data); // ��ջ��׷��Ԫ��	
			q = q->next;					       // �޸�ջ��ָ�� 
		}
	}
}


template<class ElemType>
LinkStack<ElemType> &LinkStack<ElemType>::operator = (const LinkStack<ElemType> &s)
// �����������ջs��ֵ����ǰջ--��ֵ�������
{
	if (&s != this)	{
		Clear();			// ��յ�ǰջ
   		if (!s.IsEmpty())	{	                            // s�ǿ�,����ջ
			top = new Node<ElemType>(s.top->data);       // ���ɵ�ǰջ��
			Node<ElemType> *q = top;			            // ���õ�ǰջ��ָ��
			for (Node<ElemType> *p = s.top->next; p != NULL; p = p->next){
                q->next = new Node<ElemType>(p->data);      // ��ջ��׷��Ԫ��	
				q = q->next;			                    // �޸�ջ��ָ��
			}
		}
	}
	return *this;
}

#endif
