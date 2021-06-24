#ifndef __BINNARY_TREE_H__
#define __BINNARY_TREE_H__

#include "LinkQueue.h"				// ������
#include "BinTreeNode.h"			// �����������

// ������������
template <class ElemType>
class BinarySortTree
{
protected:
//  ���������������ݳ�Ա:
	BinTreeNode<ElemType> *root;

//	��������:
	BinTreeNode<ElemType> *CopyTree(BinTreeNode<ElemType> *r);	// ������rΪ���Ķ���������
	void Destroy(BinTreeNode<ElemType> * &r);					// ������rΪ���Ķ���������
	void PreOrder(BinTreeNode<ElemType> *r, void (*Visit)(const ElemType &)) const;	// ���������rΪ���Ķ���������
	void InOrder(BinTreeNode<ElemType> *r, void (*Visit)(const ElemType &)) const;	// ���������rΪ���Ķ���������
	void PostOrder(BinTreeNode<ElemType> *r, void (*Visit)(const ElemType &)) const;// ���������rΪ���Ķ���������
    int Height(const BinTreeNode<ElemType> *r) const;	// ����rΪ���Ķ����������ĸ�
	int NodeCount(const BinTreeNode<ElemType> *r) const;// ����rΪ���Ķ����������Ľ����
	BinTreeNode<ElemType> *Parent(BinTreeNode<ElemType> *r, 
		const BinTreeNode<ElemType> *p) const;			// ����rΪ���Ķ�������������p��˫��
	BinTreeNode<ElemType> *Find(const ElemType &key, BinTreeNode<ElemType> *&f) const;	
		// ���ҹؼ���Ϊkey������Ԫ��
	void Delete(BinTreeNode<ElemType> *&p);				// ɾ��pָ��Ľ��

public:
//  �����������������������ر���ϵͳĬ�Ϸ�������:
	BinarySortTree();									// �޲����Ĺ��캯��
	virtual ~BinarySortTree();							// ��������
	BinTreeNode<ElemType> *GetRoot() const;				// ������������ĸ�
	bool IsEmpty() const;								// �ж϶����������Ƿ�Ϊ��
	Status GetElem(BinTreeNode<ElemType> *p, ElemType &e) const;
		// ��e���ؽ������Ԫ��ֵ
	Status SetElem(BinTreeNode<ElemType> *p, const ElemType &e);
		// ����p��ֵ��Ϊe
	void InOrder(void (*Visit)(const ElemType &)) const;	// �������������������	
	void PreOrder(void (*Visit)(const ElemType &)) const;	// �������������������
	void PostOrder(void (*Visit)(const ElemType &)) const;	// �����������ĺ������
	void LevelOrder(void (*Visit)(const ElemType &)) const;	// �����������Ĳ�α���
	int NodeCount() const;									// ������������Ľ�����
	BinTreeNode<ElemType> *Find(const ElemType &key) const;  // ���ҹؼ���Ϊkey������Ԫ��
	bool Insert(const ElemType &e);							// ��������Ԫ��e
	bool Delete(const ElemType &key);						// ɾ���ؼ���Ϊkey������Ԫ��
	BinTreeNode<ElemType> *LeftChild(const BinTreeNode<ElemType> *p) const;
		// ��������������p������
	BinTreeNode<ElemType> *RightChild(const BinTreeNode<ElemType> *p) const;
		// ��������������p���Һ���
	BinTreeNode<ElemType> *Parent(const BinTreeNode<ElemType> *p) const;
		// ��������������p��˫��
	int	Height() const;										// ������������ĸ�
	BinarySortTree(const ElemType &e);						// ������eΪ���Ķ���������
	BinarySortTree(const BinarySortTree<ElemType> &copy);	// ���ƹ��캯��
	BinarySortTree(BinTreeNode<ElemType> *r);				// ������rΪ���Ķ���������
	BinarySortTree<ElemType> &operator=
		(const BinarySortTree<ElemType>& copy);	// ��ֵ�������
};

template <class ElemType>
void DisplayBTWithTreeShapeHelp(const BinTreeNode<ElemType> *r, int level);
	//	����״��ʽ��ʾ��rΪ���Ķ�����������levelΪ���������������Ĳ����Ϊ1
template <class ElemType>
void DisplayBTWithTreeShape(const BinarySortTree<ElemType> &bt);
	//	��״��ʽ��ʾ����������bt 

// �������������ʵ�ֲ���
template <class ElemType>
BinarySortTree<ElemType>::BinarySortTree()
// �������������һ���ն���������
{
	root = NULL;
}

template <class ElemType>
BinarySortTree<ElemType>::~BinarySortTree()
// ������������ٶ���������--���캯��
{
	Destroy(root);
}

template <class ElemType>
BinTreeNode<ElemType> *BinarySortTree<ElemType>::GetRoot() const
// ������������ض����������ĸ�
{
	return root;
}

template <class ElemType>
bool BinarySortTree<ElemType>::IsEmpty() const
// ����������ж϶����������Ƿ�Ϊ��
{
	return root == NULL;
}

template <class ElemType>
Status BinarySortTree<ElemType>::GetElem(BinTreeNode<ElemType> *p, ElemType &e) const
// �����������e���ؽ��p������Ԫ��ֵ,��������ڽ��p,��������NOT_PRESENT,���򷵻�ENTRY_FOUND
{
	if (p == NULL)		
		return NOT_PRESENT;	// �����ڽ��p������NOT_PRESENT
	else  { 
		e = p->data;		// ���ڽ��p����e��������Ԫ��ֵ
		return ENTRY_FOUND;	// ����ENTRY_FOUND
	}
}

template <class ElemType>
Status BinarySortTree<ElemType>::SetElem(BinTreeNode<ElemType> *p, const ElemType &e)
// �����������������ڽ��p,�򷵻�FAIL,���򷵻�SUCCESS,�������p��ֵ����Ϊe
{
	if (p == NULL)
		return FAIL;		// �����ڽ��p������FAIL
	else	{
		p->data = e;				// ���ڽ��p�����p��ֵ����Ϊe
		return SUCCESS;				// ����SUCCESS
	}
}

template <class ElemType>
void BinarySortTree<ElemType>::PreOrder(BinTreeNode<ElemType> *r, void (*Visit)(const ElemType &)) const
// ������������������rΪ���Ķ���������
{
	if (r != NULL) 	{
		(*Visit)(r->data);				// ���ʸ����
		PreOrder(r->leftChild, Visit);	// �������r��������
		PreOrder(r->rightChild, Visit);	// �������r��������
	}
}

template <class ElemType>
void BinarySortTree<ElemType>::PreOrder(void (*Visit)(const ElemType &)) const
// ��������������������������
{
	PreOrder(root, Visit);	
}	

template <class ElemType>
void BinarySortTree<ElemType>::InOrder(BinTreeNode<ElemType> *r, void (*Visit)(const ElemType &)) const
// ������������������rΪ���Ķ���������
{
	if (r != NULL) 	{
		InOrder(r->leftChild, Visit);	// �������r��������
		(*Visit)(r->data);				// ���ʸ����
		InOrder(r->rightChild, Visit);	// �������r��������
	}
}

template <class ElemType>
void BinarySortTree<ElemType>::InOrder(void (*Visit)(const ElemType &)) const
// ��������������������������
{
	InOrder(root, Visit);	
}	

template <class ElemType>
void BinarySortTree<ElemType>::PostOrder(BinTreeNode<ElemType> *r, void (*Visit)(const ElemType &)) const
// ������������������rΪ���Ķ���������
{
	if (r != NULL) 	{
		PostOrder(r->leftChild, Visit);	// �������r��������
		PostOrder(r->rightChild, Visit);// �������r��������
		(*Visit)(r->data);				// ���ʸ����
	}
}

template <class ElemType>
void BinarySortTree<ElemType>::PostOrder(void (*Visit)(const ElemType &)) const
// ��������������������������
{
	PostOrder(root, Visit);	
}	

template <class ElemType>
void BinarySortTree<ElemType>::LevelOrder(void (*Visit)(const ElemType &)) const
// �����������α�������������
{
	LinkQueue<BinTreeNode<ElemType> *> q;	// ����
	BinTreeNode<ElemType> *t = root;
	
	if (t != NULL) 
        q.EnQueue(t);			// ������ǿ�,�����
	while (!q.IsEmpty())	{	// q�ǿ�,˵�����н��δ����
		q.DelQueue(t);     
		(*Visit)(t->data);
		if (t->leftChild != NULL)			// ���ӷǿ�
			q.EnQueue(t->leftChild);		// �������
		if (t->rightChild != NULL)			// �Һ��ӷǿ�
			q.EnQueue(t->rightChild);		// �Һ������
	}
}

template <class ElemType>
int BinarySortTree<ElemType>::Height(const BinTreeNode<ElemType> *r) const
// �������������rΪ���Ķ����������ĸ�
{
	if(r == NULL)	// �ն�����������Ϊ0
		return 0;
	else	{	    // �ǿն�����������Ϊ���������ĸߵ����ֵ�ټ�1
		int lHeight, rHeight;
		lHeight = Height(r->leftChild);		// �������ĸ�
		rHeight = Height(r->rightChild);	// �������ĸ�
		return 1 + (lHeight > rHeight ? lHeight : rHeight);
			// �ǿն�����������Ϊ���������ĸߵ����ֵ�ټ�1
	}
}

template <class ElemType>
int BinarySortTree<ElemType>::Height() const
// ���������������������ĸ�
{
	return Height(root);
}

template <class ElemType>
BinarySortTree<ElemType>::BinarySortTree(const ElemType &e)
// ���������������eΪ���Ķ���������
{
	root = new BinTreeNode<ElemType>(e);
}

template <class ElemType>
int BinarySortTree<ElemType>::NodeCount(const BinTreeNode<ElemType> *r) const
// �������������rΪ���Ķ����������Ľ�����
{
	if (r ==NULL) 
        return 0;			// �ն���������������Ϊ0
	else 
        return 1 + NodeCount(r->leftChild) + NodeCount(r->rightChild);
		// �ǿն�������������Ϊ���������Ľ�����֮���ټ�1
}

template <class ElemType>
int BinarySortTree<ElemType>::NodeCount() const
// ���������������������Ľ�����
{
	return NodeCount(root);
}

template <class ElemType>
BinTreeNode<ElemType> *BinarySortTree<ElemType>::LeftChild(const BinTreeNode<ElemType> *p) const
// �����������������������p������
{
	return p->leftChild;
}

template <class ElemType>
BinTreeNode<ElemType> *BinarySortTree<ElemType>::RightChild(const BinTreeNode<ElemType> *p) const
// �����������������������p���Һ���
{
	return p->rightChild;
}

template <class ElemType>
BinTreeNode<ElemType> * BinarySortTree<ElemType>::Parent(BinTreeNode<ElemType> *r, const BinTreeNode<ElemType> *p) const
// ��������� ����rΪ���Ķ���������������p��˫��
{
	if (r == NULL) 
        return NULL;		// �ն���������
	else if (r->leftChild == p || r->rightChild == p) 
        return r; // rΪp��˫��
	else	{	// ����������˫��
		BinTreeNode<ElemType> *tmp;
		
		tmp = Parent(r->leftChild, p); // ������������p��˫��	
		if (tmp != NULL)
           return tmp;	               // ˫������������

		tmp = Parent(r->rightChild, p);// ������������p��˫��	
		if (tmp != NULL) 
           return tmp;	               // ˫������������
		else 
           return NULL;				   // ��ʾp��˫��
	}
}

template <class ElemType>
BinTreeNode<ElemType> *BinarySortTree<ElemType>::Parent(const BinTreeNode<ElemType> *p) const
// �����������������������p��˫��
{
	return Parent(root, p);
}

template <class ElemType>
BinTreeNode<ElemType> *BinarySortTree<ElemType>::Find(const ElemType &key, 
	BinTreeNode<ElemType> *&f) const
// �������: ��ָ��ؼ���Ϊkey������Ԫ�ص�ָ��,��f������˫��
{
	BinTreeNode< ElemType> *p = GetRoot();	// ָ��ǰ���
	f = NULL;								// ָ��p��˫��
	
	while (p != NULL && p->data != key)	{	// ���ҹؼ���Ϊkey�Ľ��
		if (key < p->data)	{	// key��С,���������Ͻ��в���
	        cout << "��" << p->data << "С" << endl;
			f = p;
			p = p->leftChild;
		}
		else		{	// key����,���������Ͻ��в���
	        cout << "��" << p->data << "��" << endl;
			f = p;
			p = p->rightChild;
		}
	}
	return p;
}

template <class ElemType>
BinTreeNode<ElemType> *BinarySortTree<ElemType>::Find(const ElemType &key)	const 
// �������: ����ָ��ؼ���Ϊkey������Ԫ�ص�ָ��
{
	BinTreeNode<ElemType> *f;			// ָ�򱻲��ҽ���˫��
	return Find(key, f);
}

template <class ElemType>
bool BinarySortTree<ElemType>::Insert(const ElemType &e)
// �������: ��������Ԫ��e
{
	BinTreeNode<ElemType> *f;		// ָ�򱻲��ҽ���˫��

	cout << "��������Ԫ��" << e <<"���������̣�" << endl;
	if (Find(e, f) == NULL)	{	    // ����ʧ��, ����ɹ�
		BinTreeNode<ElemType> *p;	// ������½��
		p = new BinTreeNode<ElemType>(e);
		if (IsEmpty())	            // �ն�����,�½��Ϊ�����
			root = p;
		else if (e < f->data)	    // eС����˫��,������Ϊf������
			f->leftChild = p;
		else	                    // e������˫��,������Ϊf���Һ���
			f->rightChild = p;
		return true;		
	}
	else	// ���ҳɹ�, ����ʧ��
		return false;
}

template <class ElemType>
void BinarySortTree<ElemType>::Delete(BinTreeNode<ElemType> *&p)
// �������: ɾ��pָ��Ľ��
{
	BinTreeNode<ElemType> *tmpPtr, *tmpF;  
	if (p->leftChild == NULL && p->rightChild == NULL)	{	// pΪҶ���
		delete p;
		p = NULL;
	}
	else if (p->leftChild == NULL)	{	// pֻ��������Ϊ��
		tmpPtr = p;
		p = p->rightChild;
		delete tmpPtr;
	}
	else if (p->rightChild == NULL)	{	// pֻ���������ǿ�
		tmpPtr = p;
		p = p->leftChild;
		delete tmpPtr;
	}
	else	{	// p�����ӷǿ�
		tmpF = p;
		tmpPtr = p->leftChild;
		while (tmpPtr->rightChild != NULL)	{	// ����p������������ֱ��ǰ��tmpPtr����˫��tmpF,ֱ��tmpPtr������Ϊ��
			tmpF = tmpPtr;
			tmpPtr = tmpPtr->rightChild;
		}
		p->data = tmpPtr->data;
			// ��tmpPtrָ���������Ԫ��ֵ��ֵ��tmpFָ���������Ԫ��ֵ

		// ɾ��tmpPtrָ��Ľ��
		if (tmpF->rightChild == tmpPtr)	// ɾ��tmpF���Һ���
			Delete(tmpF->rightChild);
		else    // ɾ��tmpF������
			Delete(tmpF->leftChild);
	}
}

template <class ElemType>
bool BinarySortTree<ElemType>::Delete(const ElemType &key)
// �������: ɾ���ؼ���Ϊkey������Ԫ��
{
	BinTreeNode<ElemType> *p, *f;
	p = Find(key, f);
	if ( p == NULL)	// ����ʧ��, ɾ��ʧ��
		return false;
	else	// ���ҳɹ�, ����ʧ��
		if (f == NULL)	// ��ɾ�����Ϊ�����
			Delete(p);
		else if (key < f->data)	// elem.key��С,ɾ��f������
			Delete(f->leftChild);
		else	// elem.key����, ɾ��f���Һ���
			Delete(f->rightChild);
		return true;		
}

template <class ElemType>
void BinarySortTree<ElemType>::Destroy(BinTreeNode<ElemType> *&r)
// ���������������r�Ķ���������
{
	if(r != NULL)	{	// r�ǿ�,ʵʩ����
		Destroy(r->leftChild);		// ����������
		Destroy(r->rightChild);		// ����������
		delete r;						// ���ٸ����
		r = NULL;
	}
}

template <class ElemType>
BinTreeNode<ElemType> *BinarySortTree<ElemType>::CopyTree(BinTreeNode<ElemType> *copy)
// �������������copyΪ���Ķ������������Ƴ��µĶ���������,�����¶����������ĸ�
{
	if (copy == NULL)	// ���ƿն���������
		return NULL;					// �ն�����������Ϊ��	
	else	{	// ���Ʒǿն���������
		BinTreeNode<ElemType> *lChild = CopyTree(copy->leftChild);	// ����������
		BinTreeNode<ElemType> *rChild = CopyTree(copy->rightChild);	// ����������
		BinTreeNode<ElemType> *r = new BinTreeNode<ElemType>(copy->data, lChild, rChild);
			// ���Ƹ����
		return r;
	}
}

template <class ElemType>
BinarySortTree<ElemType>::BinarySortTree(const BinarySortTree<ElemType> &copy)
// �������������֪���������������¶����������������ƹ��캯��
{
	root = CopyTree(copy.root);	// ���ƶ���������
}

template <class ElemType>
BinarySortTree<ElemType>::BinarySortTree(BinTreeNode<ElemType> *r)
// ���������������rΪ���Ķ���������
{	
	root = r;	// ���ƶ���������
}

template <class ElemType>
BinarySortTree<ElemType> &BinarySortTree<ElemType>::operator=(const BinarySortTree<ElemType> &copy)
// �������������֪����������copy���Ƶ���ǰ����������--��ֵ�������
{
	if (&copy != this)	{
		Destroy(root);				// �ͷ�ԭ������������ռ�ÿռ�
		root = CopyTree(copy.root);	// ���ƶ���������
	}
	return *this;
}

template <class ElemType>
void DisplayBTWithTreeShapeHelp(const BinTreeNode<ElemType> *r, int level)
//	�������������״��ʽ��ʾ��rΪ���Ķ�����������levelΪ���������������Ĳ����Ϊ1
{
	if(r != NULL)	{	//��������ʽ��ֻ��ʽ�ǿ���
		DisplayBTWithTreeShapeHelp<ElemType>(r->rightChild, level + 1);//��ʾ������
		cout << endl << endl;					//��ʾ����	
		for(int i = 0; i < level - 1; i++)
			cout << "   ";				//ȷ���ڵ�level����ʾ���
		cout << r->data;				//��ʾ���
		DisplayBTWithTreeShapeHelp<ElemType>(r->leftChild, level + 1);//��ʾ������
	}
}

template <class ElemType>
void DisplayBTWithTreeShape(const BinarySortTree<ElemType> &bt)
//	�����������״��ʽ��ʾ���������� 
{
	DisplayBTWithTreeShapeHelp<ElemType>(bt.GetRoot(), 1);	
		// ��״��ʾ��bt.GetRoot()Ϊ���Ķ���������
	cout << endl;
}

#endif
