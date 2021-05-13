#ifndef __BINNARY_TREE_H__
#define __BINNARY_TREE_H__

#include "LinkQueue.h"				// ������
#include "BinTreeNode.h"			// �����������

// ��������
template <class ElemType>
class BinaryTree
{
protected:
//  �����������ݳ�Ա:
	BinTreeNode<ElemType> *root;

//	��������:
	BinTreeNode<ElemType> *CopyTree(BinTreeNode<ElemType> *t);
// ���ƶ�����
	void Destroy(BinTreeNode<ElemType> * &r);	// ɾ����rΪ��������
	void PreOrder(BinTreeNode<ElemType>*r,void(*Visit)(const ElemType&)) const;
		// ���������rΪ���Ķ�����
	void InOrder(BinTreeNode<ElemType>*r,void (*Visit)(const ElemType &)) const;
		// ���������rΪ���Ķ�����
	void PostOrder(BinTreeNode<ElemType>*r,
void (*Visit)(const ElemType &)) const;	// ���������rΪ���Ķ�����
    int Height(const BinTreeNode<ElemType> *r) const;	
// ����rΪ���Ķ������ĸ�
	int NodeCount(const BinTreeNode<ElemType> *r) const;
// ����rΪ���Ķ������Ľ�����
	BinTreeNode<ElemType> *Parent(BinTreeNode<ElemType> *r, 
		const BinTreeNode<ElemType>*p) const;//����rΪ���Ķ���������p��˫��

public:
//  �������������������ر���ϵͳĬ�Ϸ�������:
	BinaryTree();						// �޲����Ĺ��캯��
	BinaryTree(const ElemType &e);		// ������eΪ���Ķ�����
	virtual ~BinaryTree();				// ��������
	BinTreeNode<ElemType> *GetRoot() const;	// ���ض������ĸ�
	bool IsEmpty() const;				// �ж϶������Ƿ�Ϊ��
	Status GetElem(BinTreeNode<ElemType> *p, ElemType &e) const;
		// ��e���ؽ��pԪ��ֵ
	Status SetElem(BinTreeNode<ElemType> *p, const ElemType &e);
		// �����p��ֵ��Ϊe
	void InOrder(void (*Visit)(const ElemType &)) const;// ���������������	
	void PreOrder(void (*Visit)(const ElemType &)) const;// ���������������
	void PostOrder(void (*Visit)(const ElemType &)) const;// �������ĺ������
	void LevelOrder(void (*Visit)(const ElemType &)) const;	// �������Ĳ�α���
	int NodeCount() const;				// ��������Ľ�����
	BinTreeNode<ElemType> *LeftChild(const BinTreeNode<ElemType> *p) const;
		//  ����p������
	BinTreeNode<ElemType> *RightChild(const BinTreeNode<ElemType> *p) const;
		// ����p���Һ���
	BinTreeNode<ElemType> *LeftSibling(const BinTreeNode<ElemType> *p) const;
		// ����p�����ֵ� 
	BinTreeNode<ElemType>*RightSibling(const BinTreeNode<ElemType>*p) const;
		// ����p�����ֵ�
	BinTreeNode<ElemType> *Parent(const BinTreeNode<ElemType> *p) const;
		// ����p��˫��
	BinTreeNode<ElemType> *Find(const ElemType &e) const;
		// ����Ԫ��e�����ҳɹ����ؽ��ָ�룬���򷵻�NULL 
	void InsertLeftChild(BinTreeNode<ElemType> *p, const ElemType &e);
        // ����һ�����e��Ϊp������
	void InsertRightChild(BinTreeNode<ElemType> *p, const ElemType &e);
        // ����һ�����e��Ϊp���Һ���
	void DeleteLeftChild(BinTreeNode<ElemType> *p);	// ɾ��p��������
	void DeleteRightChild(BinTreeNode<ElemType> *p);// ɾ��p��������
	int	Height() const;							    // ��������ĸ�
	BinaryTree(const BinaryTree<ElemType> &t);	// ���ƹ��캯��
	BinaryTree(BinTreeNode<ElemType> *r);			// ������rΪ���Ķ�����
	BinaryTree<ElemType> &operator=(const BinaryTree<ElemType>& t);
		// ��ֵ���������
	int BT_Width()const;
	bool JudgeBinTreeSort(BinTreeNode<ElemType>* r, ElemType& m)const;
	bool JudgeBinTreeSort()const;
};


template <class ElemType>
void DisplayBTWithTreeShape(BinTreeNode<ElemType> *r, int level);
	//	����״��ʽ��ʾ��rΪ���Ķ�������levelΪ���������������Ĳ����Ϊ1
template <class ElemType>
void DisplayBTWithTreeShape(BinaryTree<ElemType> &bt);
	//	��״��ʽ��ʾ������ 
template <class ElemType>
void CreateBinaryTree(BinTreeNode<ElemType> *&r, ElemType pre[], ElemType in[], 
	int preLeft, int preRight, int inLeft, int inRight);	
	// ��֪����������������pre[preLeft..preRight]����������in[inLeft..inRight]������rΪ����
	// ������
template <class ElemType>
BinaryTree<ElemType> &CreateBinaryTree(ElemType pre[], ElemType in[], int n);
	// ��֪������������й��������



// ���������ʵ�ֲ���
template <class ElemType>
BinaryTree<ElemType>::BinaryTree()
// �������������һ���ն�����
{
	root = NULL;
}

template <class ElemType>
BinaryTree<ElemType>::~BinaryTree()
// ���������ɾ��������--���캯��
{
	Destroy(root);
}

template <class ElemType>
BinTreeNode<ElemType> *BinaryTree<ElemType>::GetRoot() const
// ������������ض������ĸ�
{
	return root;
}

template <class ElemType>
bool BinaryTree<ElemType>::IsEmpty() const
// ����������ж϶������Ƿ�Ϊ��
{
	return root == NULL;
}

template <class ElemType>
Status BinaryTree<ElemType>::GetElem(BinTreeNode<ElemType> *p, ElemType &e) const
// �����������e���ؽ��pԪ��ֵ,��������ڽ��p,��������NOT_PRESENT,���򷵻�ENTRY_FOUND
{
	if (p == NULL)		// �����ڽ��p
		return NOT_PRESENT;			// ����NOT_PRESENT
	else	{	// ���ڽ��p
		e = p->data;				// ��e����Ԫ��ֵ
		return ENTRY_FOUND;			// ����ENTRY_FOUND
	}
}

template <class ElemType>
Status BinaryTree<ElemType>::SetElem(BinTreeNode<ElemType> *p, const ElemType &e)
// �����������������ڽ��p,�򷵻�FAIL,���򷵻�SUCCESS,�������p��ֵ����Ϊe
{
	if (p == NULL)		// �����ڽ��p
		return FAIL;				// ����FAIL
	else	{	// ���ڽ��p
		p->data = e;				// �����p��ֵ����Ϊe
		return SUCCESS;				// ����SUCCESS
	}
}

template <class ElemType>
void BinaryTree<ElemType>::PreOrder(BinTreeNode<ElemType> *r, void (*Visit)(const ElemType &)) const
// ������������������rΪ���Ķ�����
{
	if (r != NULL)	{
		(*Visit)(r->data);				// ���ȷ��ʸ����r
		PreOrder(r->leftChild, Visit);	// �ٱ���r��������
		PreOrder(r->rightChild, Visit);	// ������r��������
	}
}

template <class ElemType>
void BinaryTree<ElemType>::PreOrder(void (*Visit)(const ElemType &)) const
// ����������������������
{
	PreOrder(root, Visit);	
}	

template <class ElemType>
void BinaryTree<ElemType>::InOrder(BinTreeNode<ElemType> *r, void (*Visit)(const ElemType &)) const
// ������������������rΪ���Ķ�����
{
	if (r != NULL) 	{
		InOrder(r->leftChild, Visit);	// ���ȱ���r��������
		(*Visit)(r->data);				// �ٷ��ʸ����r
		InOrder(r->rightChild, Visit);	// ������r��������
	}
}

template <class ElemType>
void BinaryTree<ElemType>::InOrder(void (*Visit)(const ElemType &)) const
// ����������������������
{
	InOrder(root, Visit);	
}	

template<class ElemType>
bool BinaryTree<ElemType>::JudgeBinTreeSort(BinTreeNode<ElemType>* r,ElemType &m)const
{
	int flag = true;
	if (r) {
		flag = JudgeBinTreeSort(r->leftChild,m);	// ���ȱ���r��������
		if (!m || r->data < m) {
			return false;
		}
		m = r->data;
		flag = JudgeBinTreeSort(r->rightChild,m);	// ������r��������
	}
	return flag;
}

template<class ElemType>
bool BinaryTree<ElemType>::JudgeBinTreeSort()const
{
	ElemType m;
	return JudgeBinTreeSort(root,m);
}

template <class ElemType>
void BinaryTree<ElemType>::PostOrder(BinTreeNode<ElemType> *r, void (*Visit)(const ElemType &)) const
// ������������������rΪ���Ķ�����
{
	if (r != NULL) 	{
		PostOrder(r->leftChild, Visit);	// ���ȱ���r��������
		PostOrder(r->rightChild, Visit);// �ٱ���r��������
		(*Visit)(r->data);				// �����ʸ����r
	}
}

template <class ElemType>
void BinaryTree<ElemType>::PostOrder(void (*Visit)(const ElemType &)) const
// ����������������������
{
	PostOrder(root, Visit);	
}	

template <class ElemType>
void BinaryTree<ElemType>::LevelOrder(void (*Visit)(const ElemType &)) const
// �����������α���������
{
	LinkQueue<BinTreeNode<ElemType> *> q;	// �������q
	BinTreeNode<ElemType> *p;
	
	if (root != NULL) q.EnQueue(root);		// ������ǿ�,�����
	while (!q.IsEmpty())	{	            // q�ǿ�,˵�����н��δ����
		q.DelQueue(p);                      // ��ͷԪ�س��ӣ�������֮ 
		(*Visit)(p->data);
		if (p->leftChild != NULL)			// ��ͷԪ�����ӷǿ�
			q.EnQueue(p->leftChild);		// �������
		if (p->rightChild != NULL)			// ��ͷԪ���Һ��ӷǿ�
			q.EnQueue(p->rightChild);		// �Һ������
	}
}

template <class ElemType>
int BinaryTree<ElemType>::Height(const BinTreeNode<ElemType> *r) const
// ���������������rΪ���Ķ������ĸ�
{
	if(r == NULL)	// �ն�������Ϊ0
		return 0;
	else	{	// �ǿն�������Ϊ���������ĸߵ����ֵ�ټ�1
		int lHeight, rHeight;
		lHeight = Height(r->leftChild);		// �������ĸ�
		rHeight = Height(r->rightChild);	// �������ĸ�
		return (lHeight > rHeight ? lHeight : rHeight) + 1;
			// �ǿն�������Ϊ���������ĸߵ����ֵ�ټ�1
	}
}

template <class ElemType>
int BinaryTree<ElemType>::Height() const
// ������������ض������ĸ�
{
	return Height(root);
}

template <class ElemType>
BinaryTree<ElemType>::BinaryTree(const ElemType &e)
// ���������������eΪ���Ķ�����
{
	root = new BinTreeNode<ElemType>(e);
}

template <class ElemType>
int BinaryTree<ElemType>::NodeCount(const BinTreeNode<ElemType> *r) const
// ���������������rΪ���Ķ������Ľ�����
{
	if (r ==NULL)
       return 0;			// �ն�����������Ϊ0
	else
       return NodeCount(r->leftChild) + NodeCount(r->rightChild) + 1;
		// �ǿն���������Ϊ���������Ľ�����֮���ټ�1
}

template <class ElemType>
int BinaryTree<ElemType>::NodeCount() const
// ������������ض������Ľ�����
{
	return NodeCount(root);
}

template <class ElemType>
BinTreeNode<ElemType> *BinaryTree<ElemType>::LeftChild(const BinTreeNode<ElemType> *p) const
// ������������ض��������p������
{
	return p->leftChild;
}

template <class ElemType>
BinTreeNode<ElemType> *BinaryTree<ElemType>::RightChild(const BinTreeNode<ElemType> *p) const
// ������������ض��������p���Һ���
{
	return p->rightChild;
}

template <class ElemType>
BinTreeNode<ElemType> *BinaryTree<ElemType>::LeftSibling(const BinTreeNode<ElemType> *p) const
// ������������ض��������p�����ֵ� 
{
    BinTreeNode<ElemType> *r = Parent(root, p);
    if (r == NULL)
       return NULL;
    else if (r->rightChild == p)
	   return r->leftChild;
    else 
       return NULL;
}

template <class ElemType>
BinTreeNode<ElemType> *BinaryTree<ElemType>::RightSibling(const BinTreeNode<ElemType> *p) const
// ������������ض��������p�����ֵ�
{
    BinTreeNode<ElemType> *r = Parent(root, p);
    if (r == NULL)
       return NULL;
    else if (r->leftChild == p)
	   return r->rightChild;
    else 
       return NULL;
}


template <class ElemType>
BinTreeNode<ElemType> * BinaryTree<ElemType>::Parent(BinTreeNode<ElemType> *r, const BinTreeNode<ElemType> *p) const
// ���������������rΪ���Ķ�����, ���p��˫��
{
	if (r == NULL)
       return NULL;		// �ն�����
	else if (r->leftChild == p || r->rightChild == p)
       return r; // rΪp��˫��
	else	{	// ����������˫��
		BinTreeNode<ElemType> *tmp;
		tmp = Parent(r->leftChild, p);	// ������������p��˫��	
		if (tmp != NULL)
           return tmp;			        // ˫������������
  
		tmp = Parent(r->rightChild, p);	// ������������p��˫��	
		if (tmp != NULL)
           return tmp;			        // ˫������������
		else
           return NULL;				    // ��ʾp��˫��
	}
}

template <class ElemType>
BinTreeNode<ElemType> *BinaryTree<ElemType>::Parent(const BinTreeNode<ElemType> *p) const
// ������������ض��������p��˫��
{
	return Parent(root, p);
}

template <class ElemType>
void BinaryTree<ElemType>::InsertLeftChild(BinTreeNode<ElemType> *p, const ElemType &e)
// ��ʼ������p�ǿգ�
// �������������Ԫ��ֵΪe�Ľ��Ϊp�����ӣ����p�����ӷǿգ���pԭ����������Ϊe��������
{
	if (p == NULL)	// p�գ�����
		return;
	else 	{	// ��������
		BinTreeNode<ElemType> *child =  new BinTreeNode<ElemType>(e);// Ԫ��ֵΪe���
		if (p->leftChild != NULL)	// p�����ӷǿ�
			child->leftChild = p->leftChild;	// pԭ����������Ϊe��������
		p->leftChild = child;					// e��Ϊp������
		return;
	}
}

template <class ElemType>
void BinaryTree<ElemType>::InsertRightChild(BinTreeNode<ElemType> *p, const ElemType &e)
// ��ʼ������p�ǿ�
// �������������Ԫ��ֵΪe�Ľ��Ϊp���Һ��ӣ����p���Һ��ӷǿգ���pԭ����������Ϊe��������
{
	if (p == NULL)	// pΪ�գ�����
		return;
	else	{	// �����Һ���
		BinTreeNode<ElemType> *child =  new BinTreeNode<ElemType>(e);// Ԫ��ֵΪe���
		if (p->rightChild != NULL)	// p���Һ��ӷǿ�
			child->rightChild = p->rightChild;	// pԭ����������Ϊe��������
		p->rightChild = child;					// e��Ϊp���Һ���
		return;
	}
}

template <class ElemType>
void BinaryTree<ElemType>::DeleteLeftChild(BinTreeNode<ElemType> *p)
// ��ʼ������p�ǿ�
// ���������ɾ��p������
{
	if (p == NULL)	// pΪ��
		return;
	else	// p�ǿ�
		Destroy(p->leftChild);	// ɾ��p������
}

template <class ElemType>
void BinaryTree<ElemType>::DeleteRightChild(BinTreeNode<ElemType> *p)
// ��ʼ������p�ǿ�
// ���������ɾ��p������
{
	if (p == NULL)	// pΪ��
		return;
	else	// p�ǿ�
		Destroy(p->rightChild);	// ɾ��p������
}

template <class ElemType>
BinTreeNode<ElemType> *BinaryTree<ElemType>::Find(const ElemType &e) const
// ������������ض��������p��˫��
{
	LinkQueue<BinTreeNode<ElemType> *> q;	// �������q
	BinTreeNode<ElemType> *p;
	
	if (root != NULL) q.EnQueue(root);		// ������ǿ�,�����
	while (!q.IsEmpty())	{	            // q�ǿ�,˵�����н��δ����
		q.DelQueue(p);                      // ��ͷԪ�س��ӣ�������֮ 
		if (p->data == e)
			return p;
		if (p->leftChild != NULL)			// ��ͷԪ�����ӷǿ�
			q.EnQueue(p->leftChild);		// �������
		if (p->rightChild != NULL)			// ��ͷԪ���Һ��ӷǿ�
			q.EnQueue(p->rightChild);		// �Һ������
	}
	return NULL;
}


template <class ElemType>
void BinaryTree<ElemType>::Destroy(BinTreeNode<ElemType> *&r)
// ���������ɾ����r�Ķ�����
{
	if(r != NULL)	{	// r�ǿ�,ʵʩɾ��
		Destroy(r->leftChild);		// ɾ��������
		Destroy(r->rightChild);		// ɾ��������
		delete r;					// ɾ�������
		r = NULL;
	}
}

template <class ElemType>
BinTreeNode<ElemType> *BinaryTree<ElemType>::CopyTree(BinTreeNode<ElemType> *t)
// �������������tΪ���Ķ��������Ƴ��µĶ�����,�����¶������ĸ�
{
	if (t == NULL)	// ���ƿն�����
		return NULL;					// �ն�������Ϊ��	
	else	{	// ���Ʒǿն�����
		BinTreeNode<ElemType> *lChild = CopyTree(t->leftChild);	// ����������
		BinTreeNode<ElemType> *rChild = CopyTree(t->rightChild);	// ����������
		BinTreeNode<ElemType> *r = new BinTreeNode<ElemType>(t->data, lChild, rChild);
			// ���Ƹ����
		return r;
	}
}

template <class ElemType>
BinaryTree<ElemType>::BinaryTree(const BinaryTree<ElemType> &t)
// �������������֪�����������¶������������ƹ��캯��
{
	root = CopyTree(t.root);	// ���ƶ�����
}

template <class ElemType>
BinaryTree<ElemType>::BinaryTree(BinTreeNode<ElemType> *r)
// ���������������rΪ���Ķ�����
{	
	root = r;	// ���ƶ�����
}

template <class ElemType>
BinaryTree<ElemType> &BinaryTree<ElemType>::operator=(const BinaryTree<ElemType> &t)
// �������������֪������t���Ƶ���ǰ������--��ֵ���������
{
	if (&t != this)	{
		Destroy(root);				// �ͷ�ԭ��������ռ�ÿռ�
		root = CopyTree(t.root);	// ���ƶ�����
	}
	return *this;
}

template<class ElemType>
int BinaryTree<ElemType>::BT_Width() const
{
	LinkQueue <BinTreeNode<ElemType>* > q;	//����һ������queue
	BinTreeNode <ElemType>* p;
	int wmax = 0, cur = 0, beh;				//wmaxΪ���Ŀ�ȣ�cur�ǵ�ǰ�����Ľ������beh����һ��Ľ����
	if (root != NULL)						//�ǿ�����ʱ�򣬸�������
	{
		q.EnQueue(root);
		cur = 1;
		wmax = 1;
	}
	while (!q.IsEmpty())					//�ǿ�����ʱ��������������
	{
		beh = 0;							//����
		for (int i = 0; i < cur; i++)
		{
			q.DelQueue(p);						//���ӣ�����p���س��ӽ���ֵ
			if (p->leftChild != NULL)
			{
				q.EnQueue(p->leftChild);
				beh++;
			}
			if (p->rightChild != NULL)
			{
				q.EnQueue(p->rightChild);
				beh++;
			}
		}
		cur = beh;
		if (beh > wmax)
		{
			wmax = beh;
		}
	}

	return wmax;
}


template <class ElemType>
void DisplayBTWithTreeShape(BinTreeNode<ElemType> *r, int level)
// �������������״��ʽ��ʾ��rΪ���Ķ�������levelΪ���������������Ĳ����Ϊ1
{
	if(r != NULL)	{	// ��������ʽ��ֻ��ʽ�ǿ���
		DisplayBTWithTreeShape<ElemType>(r->rightChild, level + 1);//��ʾ������
		cout << endl;					//��ʾ����	
		for(int i = 0; i < level - 1; i++)
			cout << "  ";				//ȷ���ڵ�level����ʾ���
		cout << r->data;				//��ʾ���
		DisplayBTWithTreeShape<ElemType>(r->leftChild, level + 1);//��ʾ������
	}
}

template <class ElemType>
void DisplayBTWithTreeShape(BinaryTree<ElemType> &bt)
// �����������״��ʽ��ʾ������ 
{
	DisplayBTWithTreeShape<ElemType>(bt.GetRoot(), 1);	
		// ��״��ʾ��bt.GetRoot()Ϊ���Ķ�����
	cout << endl;
}

template <class ElemType>
void CreateBinaryTree(BinTreeNode<ElemType> *&r, ElemType pre[], ElemType in[], 
							int preLeft, int preRight, int inLeft, int inRight)	
// �����������֪����������������pre[preLeft..preRight]����������in[inLeft..inRight]����
//	��rΪ���Ķ�����
{
	if (inLeft > inRight)	// �������޽��,�ն�����
		r = NULL;			// �ն�������Ϊ��
	else	{	// �������н��,�ǿն�����
		r = new BinTreeNode<ElemType>(pre[preLeft]);// ���ɸ����
		int mid = inLeft;
		while (in[mid] != pre[preLeft]) 	// ������������и��������������е�λ�ã������±�
			mid++;
		CreateBinaryTree(r->leftChild, pre, in, preLeft+1, preLeft + mid - inLeft, inLeft, mid - 1);
			// ����������
		CreateBinaryTree(r->rightChild, pre, in, preLeft + mid - inLeft + 1, preRight, mid + 1, 
			inRight);								// ����������
	}
} 

template <class ElemType>
BinaryTree<ElemType> &CreateBinaryTree(ElemType pre[], ElemType in[], int n)
// �����������֪������������й��������
{
	BinTreeNode<ElemType> *r;						// �������ĸ�
	CreateBinaryTree<ElemType>(r, pre, in, 0, n - 1, 0, n - 1);
		// ��������������й�����rΪ���Ķ����� 
	BinaryTree<ElemType> *bt = new BinaryTree<ElemType>(r);	// ���ɶ�����
	return *bt;
}

#endif
