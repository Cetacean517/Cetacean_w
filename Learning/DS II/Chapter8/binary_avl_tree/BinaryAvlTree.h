#ifndef __BINNARY_TREE_H__
#define __BINNARY_TREE_H__
#include "Assistance.h"				// ���������
#include "LinkQueue.h"				// ������
#include "LinkStack.h"				// ��ջ
#include "BinAvlTreeNode.h"			// ƽ������������

// ƽ���������
template <class ElemType>
class BinaryAVLTree
{
protected:
//  ƽ������������ݳ�Ա:
	BinAVLTreeNode<ElemType> *root;

//	��������:
	BinAVLTreeNode<ElemType> *CopyTreeHelp(BinAVLTreeNode<ElemType> *copy);	// ����ƽ�������
	void DestroyHelp(BinAVLTreeNode<ElemType> * &r);						// ������rΪ����ƽ�������
	void PreOrderHelp(BinAVLTreeNode<ElemType> *r, void (*Visit)(const ElemType &)) const;	// ���������rΪ����ƽ�������
	void InOrderHelp(BinAVLTreeNode<ElemType> *r, void (*Visit)(const ElemType &)) const;	// ���������rΪ����ƽ�������
	void PostOrderHelp(BinAVLTreeNode<ElemType> *r, void (*Visit)(const ElemType &)) const;	// ���������rΪ����ƽ�������
    int HeightHelp(const BinAVLTreeNode<ElemType> *r) const;				// ����rΪ����ƽ��������ĸ�
	int NodeCountHelp(const BinAVLTreeNode<ElemType> *r) const;				// ����rΪ����ƽ��������Ľ�����
	BinAVLTreeNode<ElemType> *ParentHelp(BinAVLTreeNode<ElemType> *r, 
		const BinAVLTreeNode<ElemType> *p) const;							// ����rΪ����ƽ�����������p��˫��
	BinAVLTreeNode<ElemType> *Find(const ElemType &key, BinAVLTreeNode<ElemType> *&f) const;	
		// ���ҹؼ���Ϊkey������Ԫ��,����ָ��ؼ���Ϊkey��Ԫ�ص�ָ��,��f������˫��. 

	BinAVLTreeNode<ElemType> *Find(const ElemType &key, BinAVLTreeNode<ElemType> *&f,
		LinkStack<BinAVLTreeNode<ElemType> *> &s);
		 // ���ҹؼ���Ϊkey������Ԫ��,����ָ��ؼ���Ϊkey��Ԫ�ص�ָ��,����f������˫��,ջs�洢����·��.
		 
	BinAVLTreeNode<ElemType> *Find(const ElemType &key, BinAVLTreeNode<ElemType> *&f,
		BinAVLTreeNode<ElemType> *&a, BinAVLTreeNode<ElemType> *&af);
		 // ���ҹؼ���Ϊkey������Ԫ��,����ָ��ؼ���Ϊkey��Ԫ�ص�ָ��,����f������˫��,aΪ������������ƽ�����Ӳ�����0�Ľ��,af��a��˫��. 
		 
	void LeftRotate(BinAVLTreeNode<ElemType> *&subRoot);
		// ����subRootΪ���Ķ���������������,����֮��subRootָ���µ��������,Ҳ������ת����ǰ���������ĸ����
	void RightRotate(BinAVLTreeNode<ElemType> *&subRoot);
		// ����subRootΪ���Ķ���������������,����֮��subRootָ���µ��������,Ҳ������ת����ǰ���������ĸ����
	void DeleteLeftBalance(BinAVLTreeNode<ElemType> *&subRoot, bool &isShorter);
		// ����subRootΪ���Ķ�����ɾ��ʱ����ƽ�⴦��,�����subRootָ���µ��������
	void DeleteRightBalance(BinAVLTreeNode<ElemType> *&subRoot, bool &isShorter);
		// ����subRootΪ���Ķ�����ɾ��ʱ����ƽ�⴦��,�����subRootָ���µ��������
	void DeleteBalance(const ElemType &key, LinkStack<BinAVLTreeNode<ElemType> *> &s);
		// ��ɾ�������ݲ���·�����л���,����ƽ�⴦��
	void DeleteHelp(const ElemType &key, BinAVLTreeNode<ElemType> *&p,
		LinkStack< BinAVLTreeNode<ElemType> *> &s);		// ɾ��pָ��Ľ��

public:
//  ƽ��������������������ر���ϵͳĬ�Ϸ�������:
	BinaryAVLTree();											// �޲����Ĺ��캯��
	virtual ~BinaryAVLTree();									// ��������
	BinAVLTreeNode<ElemType> *GetRoot() const;					// ����ƽ��������ĸ�
	bool IsEmpty() const;										// �ж�ƽ��������Ƿ�Ϊ��
	Status GetElem(BinAVLTreeNode<ElemType> *p, ElemType &e) const;
		// ��e���ؽ������Ԫ��ֵ
	Status SetElem(BinAVLTreeNode<ElemType> *p, const ElemType &e);
		// ����p��ֵ��Ϊe
	void InOrder(void (*Visit)(const ElemType &)) const;		// ƽ����������������	
	void PreOrder(void (*Visit)(const ElemType &)) const;		// ƽ����������������
	void PostOrder(void (*Visit)(const ElemType &)) const;		// ƽ��������ĺ������
	void LevelOrder(void (*Visit)(const ElemType &)) const;		// ƽ��������Ĳ�α���
	int NodeCount() const;										// ��ƽ��������Ľ�����
	BinAVLTreeNode<ElemType> *Find(const ElemType &key) const;	// ���ҹؼ���Ϊkey������Ԫ��
	bool Insert(const ElemType &e);								// ��������Ԫ��e
	bool Delete(const ElemType &key);							// ɾ���ؼ���Ϊkey������Ԫ��
	BinAVLTreeNode<ElemType> *LeftChild(const BinAVLTreeNode<ElemType> *p) const;
		// ����ƽ����������p������
	BinAVLTreeNode<ElemType> *RightChild(const BinAVLTreeNode<ElemType> *p) const;
		// ����ƽ����������p���Һ���
	BinAVLTreeNode<ElemType> *Parent(const BinAVLTreeNode<ElemType> *p) const;
		// ����ƽ����������p��˫��
	int	Height() const;											// ��ƽ��������ĸ�
	BinaryAVLTree(const ElemType &e);							// ������eΪ����ƽ�������
	BinaryAVLTree(const BinaryAVLTree<ElemType> &copy);			// ���ƹ��캯��
	BinaryAVLTree(BinAVLTreeNode<ElemType> *r);					// ������rΪ����ƽ�������
	BinaryAVLTree<ElemType> &operator=(const BinaryAVLTree<ElemType>& copy);	// ��ֵ�������
};

template <class ElemType>
void DisplayBTWithTreeShapeHelp(const BinAVLTreeNode<ElemType> *r, int level);
	//	����״��ʽ��ʾ��rΪ����ƽ���������levelΪ���������������Ĳ����Ϊ1
template <class ElemType>
void DisplayBTWithTreeShape(const BinaryAVLTree<ElemType> &bt);
	//	��״��ʽ��ʾ����ƽ����bt 

// ƽ����������ʵ�ֲ���
template <class ElemType>
BinaryAVLTree<ElemType>::BinaryAVLTree()
// �������������һ����ƽ�������
{
	root = NULL;
}

template <class ElemType>
BinaryAVLTree<ElemType>::~BinaryAVLTree()
// �������������ƽ�������--���캯��
{
	DestroyHelp(root);
}

template <class ElemType>
BinAVLTreeNode<ElemType> *BinaryAVLTree<ElemType>::GetRoot() const
// �������������ƽ��������ĸ�
{
	return root;
}

template <class ElemType>
bool BinaryAVLTree<ElemType>::IsEmpty() const
// ����������ж�ƽ��������Ƿ�Ϊ��
{
	return root == NULL;
}

template <class ElemType>
Status BinaryAVLTree<ElemType>::GetElem(BinAVLTreeNode<ElemType> *p, ElemType &e) const
// �����������e���ؽ��p����Ԫ��ֵ,��������ڽ��p,��������NOT_PRESENT,���򷵻�ENTRY_FOUND
{
	if (p == NULL)	// �����ڽ��p
		return NOT_PRESENT;			// ����NOT_PRESENT
	else	{	    // ���ڽ��p
		e = p->data;				// ��e��������Ԫ��ֵ
		return ENTRY_FOUND;			// ����ENTRY_FOUND
	}
}

template <class ElemType>
Status BinaryAVLTree<ElemType>::SetElem(BinAVLTreeNode<ElemType> *p, const ElemType &e)
// �����������������ڽ��p,�򷵻�FAIL,���򷵻�SUCCESS,�������p��ֵ����Ϊe
{
	if (p == NULL)		   // �����ڽ��p
		return FAIL;	   // ����FAIL
	else	{	           // ���ڽ��p
		p->data = e;	   // �����p��ֵ����Ϊe
		return SUCCESS;	   // ����SUCCESS
	}
}

template <class ElemType>
void BinaryAVLTree<ElemType>::PreOrderHelp(BinAVLTreeNode<ElemType> *r, void (*Visit)(const ElemType &)) const
// ������������������rΪ����ƽ�������
{
	if (r != NULL) 	{
		(*Visit)(r->data);					// ���ʸ����
		PreOrderHelp(r->leftChild, Visit);	// �������r��������
		PreOrderHelp(r->rightChild, Visit);	// �������r��������
	}
}

template <class ElemType>
void BinaryAVLTree<ElemType>::PreOrder(void (*Visit)(const ElemType &)) const
// ����������������ƽ�������
{
	PreOrderHelp(root, Visit);	
}	

template <class ElemType>
void BinaryAVLTree<ElemType>::InOrderHelp(BinAVLTreeNode<ElemType> *r, void (*Visit)(const ElemType &)) const
// ������������������rΪ����ƽ�������
{
	if (r != NULL) 	{
		InOrderHelp(r->leftChild, Visit);	// �������r��������
		(*Visit)(r->data);					// ���ʸ����
		InOrderHelp(r->rightChild, Visit);	// �������r��������
	}
}

template <class ElemType>
void BinaryAVLTree<ElemType>::InOrder(void (*Visit)(const ElemType &)) const
// ����������������ƽ�������
{
	InOrderHelp(root, Visit);	
}	

template <class ElemType>
void BinaryAVLTree<ElemType>::PostOrderHelp(BinAVLTreeNode<ElemType> *r, void (*Visit)(const ElemType &)) const
// ������������������rΪ����ƽ�������
{
	if (r != NULL) 	{
		PostOrderHelp(r->leftChild, Visit);	// �������r��������
		PostOrderHelp(r->rightChild, Visit);// �������r��������
		(*Visit)(r->data);					// ���ʸ����
	}
}

template <class ElemType>
void BinaryAVLTree<ElemType>::PostOrder(void (*Visit)(const ElemType &)) const
// ����������������ƽ�������
{
	PostOrderHelp(root, Visit);	
}	

template <class ElemType>
void BinaryAVLTree<ElemType>::LevelOrder(void (*Visit)(const ElemType &)) const
// �����������α���ƽ�������
{
	LinkQueue<BinAVLTreeNode<ElemType> *> q;// ����
	BinAVLTreeNode<ElemType> *t = root;		// �Ӹ���㿪ʼ���в�α���
	
	if (t != NULL) q.EnQueue(t);			// ������ǿ�,�����
	while (!q.IsEmpty())	{	            // q�ǿ�,˵�����н��δ����
		q.DelQueue(t);     
		(*Visit)(t->data);
		if (t->leftChild != NULL)			// ���ӷǿ�
			q.EnQueue(t->leftChild);		// �������
		if (t->rightChild != NULL)			// �Һ��ӷǿ�
			q.EnQueue(t->rightChild);		// �Һ������
	}
}

template <class ElemType>
int BinaryAVLTree<ElemType>::HeightHelp(const BinAVLTreeNode<ElemType> *r) const
// �������������rΪ����ƽ��������ĸ�
{
	if(r == NULL)	// ��ƽ���������Ϊ0
		return 0;
	else	{	    // �ǿ�ƽ���������Ϊ���������ĸߵ����ֵ�ټ�1
		int lHeight, rHeight;
		lHeight = HeightHelp(r->leftChild);		// �������ĸ�
		rHeight = HeightHelp(r->rightChild);	// �������ĸ�
		return 1 + (lHeight > rHeight ? lHeight : rHeight);
			// �ǿ�ƽ���������Ϊ���������ĸߵ����ֵ�ټ�1
	}
}

template <class ElemType>
int BinaryAVLTree<ElemType>::Height() const
// �����������ƽ��������ĸ�
{
	return HeightHelp(root);
}

template <class ElemType>
BinaryAVLTree<ElemType>::BinaryAVLTree(const ElemType &e)
// ���������������eΪ����ƽ�������
{
	root = new BinAVLTreeNode<ElemType>(e);
}

template <class ElemType>
int BinaryAVLTree<ElemType>::NodeCountHelp(const BinAVLTreeNode<ElemType> *r) const
// �������������rΪ����ƽ��������Ľ�����
{
	if (r ==NULL) 
       return 0;	// ��ƽ�������������Ϊ0
	else 
       return 1 + NodeCountHelp(r->leftChild) + NodeCountHelp(r->rightChild);
		// �ǿ�ƽ�����������Ϊ���������Ľ�����֮���ټ�1
}

template <class ElemType>
int BinaryAVLTree<ElemType>::NodeCount() const
// �����������ƽ��������Ľ�����
{
	return NodeCountHelp(root);
}

template <class ElemType>
BinAVLTreeNode<ElemType> *BinaryAVLTree<ElemType>::LeftChild(const BinAVLTreeNode<ElemType> *p) const
// �������������ƽ����������p������
{
	return p->leftChild;
}

template <class ElemType>
BinAVLTreeNode<ElemType> *BinaryAVLTree<ElemType>::RightChild(const BinAVLTreeNode<ElemType> *p) const
// �������������ƽ����������p���Һ���
{
	return p->rightChild;
}

template <class ElemType>
BinAVLTreeNode<ElemType> * BinaryAVLTree<ElemType>::ParentHelp(BinAVLTreeNode<ElemType> *r, const BinAVLTreeNode<ElemType> *p) const
// �������������rΪ����ƽ�������������p��˫��
{
	if (r == NULL) 
       return NULL;		// ��ƽ�������
	else if (r->leftChild == p || r->rightChild == p) 
       return r;        // rΪp��˫��
	else	{	        // ����������˫��
		BinAVLTreeNode<ElemType> *tmp;
		
		tmp = ParentHelp(r->leftChild, p);	// ������������p��˫��	
		if (tmp != NULL) 
           return tmp;		                // ˫������������

		tmp = ParentHelp(r->rightChild, p);	// ������������p��˫��	
		if (tmp != NULL) 
           return tmp;			            // ˫������������
		else 
           return NULL;						// ��ʾp��˫��
	}
}

template <class ElemType>
BinAVLTreeNode<ElemType> *BinaryAVLTree<ElemType>::Parent(const BinAVLTreeNode<ElemType> *p) const
// �������������ƽ����������p��˫��
{
	return ParentHelp(root, p);
}

template <class ElemType>
BinAVLTreeNode<ElemType> *BinaryAVLTree<ElemType>::Find(const ElemType &key, BinAVLTreeNode<ElemType> *&f) const
// �������: ����ָ��ؼ���Ϊkey������Ԫ�ص�ָ��,����f������˫��
{
	BinAVLTreeNode< ElemType> *p = GetRoot(); // ָ��ǰ���
	f = NULL;								  // ָ��p��˫��
	
	while (p != NULL && p->data != key)	{	  // ���ҹؼ���Ϊkey�Ľ��
		if (key < p->data)		{	          // key��С,���������Ͻ��в���
			f = p;
			p = p->leftChild;
		}
		else		{	                      // key����,���������Ͻ��в���
			f = p;
			p = p->rightChild;
		}
	}
	
	return p;
}

template <class ElemType>
BinAVLTreeNode<ElemType> *BinaryAVLTree<ElemType>::Find(const ElemType &key)	const 
// �������: ����ָ��ؼ���Ϊkey������Ԫ�ص�ָ��
{
	BinAVLTreeNode<ElemType> *f;			// ָ�򱻲��ҽ���˫��
	return Find(key, f);
}

template <class ElemType>
BinAVLTreeNode<ElemType> *BinaryAVLTree<ElemType>::Find(
	const ElemType &key,	BinAVLTreeNode<ElemType> *&f,
	LinkStack<BinAVLTreeNode<ElemType> *> &s) 
// ���ҹؼ���Ϊkey������Ԫ��,����ָ��ؼ���Ϊkey��Ԫ�ص�ָ��,����f������˫��,ջs�洢����·��.
{
	BinAVLTreeNode<ElemType> *p = GetRoot();// ָ��ǰ���
	f = NULL;		                        // ָ��p��˫��
	s.Clear();
	while (p != NULL && p->data != key)	{	// ��Ѱ�ؼ���Ϊkey�Ľ��
		if (key < p->data)	{	            // key��С,���������Ͻ��в���
			f = p;
			s.Push(p);
			p = p->leftChild;
		}
		else	{	// key����,���������Ͻ��в���
			f = p;
			s.Push(p);
			p = p->rightChild;
		}
	}
	return p;
}

template <class ElemType>
BinAVLTreeNode<ElemType> *BinaryAVLTree<ElemType>::Find(
	const ElemType &key,	BinAVLTreeNode<ElemType> *&f,
	BinAVLTreeNode<ElemType> *&a, BinAVLTreeNode<ElemType> *&af) 
// ���ҹؼ���Ϊkey������Ԫ��,����ָ��ؼ���Ϊkey��Ԫ�ص�ָ��,����f������˫��,aΪ������������ƽ�����Ӳ�����0�Ľ��,af��a��˫��. 
{
	BinAVLTreeNode<ElemType> *p = GetRoot();// ָ��ǰ���
	a = af = f = NULL;		                        // ָ��p��˫��
	while (p != NULL && p->data != key)	{	// ��Ѱ�ؼ���Ϊkey�Ľ��
		if (p->bf != EH) {
            af = f;
		    a = p;
        }    
		if (key < p->data)	{	            // key��С,���������Ͻ��в���
			f = p;
			p = p->leftChild;
		}
		else	{	// key����,���������Ͻ��в���
			f = p;
			p = p->rightChild;
		}
	}
	if (a == NULL)
	   a = GetRoot();
	return p;
}

template <class ElemType>
void BinaryAVLTree<ElemType>::LeftRotate(BinAVLTreeNode<ElemType> *&subRoot)
// �������: ����subRootΪ���Ķ���������������,����֮��subRootָ���µ��������,
//	Ҳ������ת����ǰ���������ĸ����
{
	BinAVLTreeNode<ElemType> *ptrRChild;
	ptrRChild = subRoot->rightChild;			// ptrRChildָ��subRoot�Һ���
	subRoot->rightChild = ptrRChild->leftChild;	// ptrRChild������������ΪsubRoot��������
	ptrRChild->leftChild = subRoot;				// subRoot����ΪptrRChild������
	subRoot = ptrRChild;						// subRootָ���µĸ����
}

template <class ElemType>
void BinaryAVLTree<ElemType>::RightRotate(BinAVLTreeNode<ElemType> *&subRoot)
// �������: ����subRootΪ���Ķ���������������,����֮��subRootָ���µ��������,
//	Ҳ������ת����ǰ���������ĸ����
{
	BinAVLTreeNode<ElemType> *pLChild;
	pLChild = subRoot->leftChild;				// pLChildָ��subRoot����
	subRoot->leftChild = pLChild->rightChild;	// pLChild������������ΪsubRoot��������
	pLChild->rightChild = subRoot;				// subRoot����ΪpLChild���Һ���
	subRoot = pLChild;							// subRootָ���µĸ����
}

template <class ElemType>
bool BinaryAVLTree<ElemType>::Insert(const ElemType &e)
// �������: ��������Ԫ��e
{
	BinAVLTreeNode<ElemType> *f, *af, *a, *b, *c;
	if (Find(e, f, a, af) == NULL)	{	    // ����ʧ��, �����ɹ�
		BinAVLTreeNode<ElemType> *p;	    // ������½��
		p = new BinAVLTreeNode<ElemType>(e);// ���ɲ�����
		p->bf = 0;
		if (IsEmpty()){	                    // �ն�����,�½��Ϊ�����
			root = p;
		    return true;
        }		
		if (e < f->data)        // e����˫��С,������Ϊf������
			f->leftChild = p;
		else	                // e����˫�״�,������Ϊf���Һ���
			f->rightChild = p;
			
		switch (a->bf)	{
			case LH:
		        if (a->data > e) { // LL��ת 
                   b = a->leftChild;
                   if (b->data > e) {
		              a->bf = b->bf = EH;// �޸�ƽ������ 
		              a->leftChild = b->rightChild;
		              b->rightChild = a; // �����ת�������ĸ�Ϊb 
                   }
                   else {          // LR��ת
                      c = b->rightChild;
 		              if (c == p) {     // �޸�ƽ������ 
                         a->bf = b->bf = EH;
                      }
                      else if (e < c->data)
                         a->bf = RH;
                      else {
                         a->bf = EH;
                         b->bf = LH;
                      }
                      // ����LR��ת   
                      b->rightChild = c->leftChild;
                      a->leftChild = c->rightChild;
                      c->leftChild = b;
                      c->rightChild = a;
                      b = c;        // �����ת�������ĸ�Ϊb
                   }
                   // �������ת���������뵽ԭ����    
                   if (af == NULL)
                      root = b;    // ʧȥƽ�����С�����ĸ�Ϊ�������ĸ� 
                   else if (e < af->data)
                      af->leftChild = b; // ʧȥƽ�����С����Ϊ��˫�׵������� 
                   else
                      af->rightChild = b;// ʧȥƽ�����С����Ϊ��˫�׵�������   
                }   
                else {
                   a->bf = EH;     // ����ת������Ҫ�޸�ƽ������ 
                   a = a->rightChild;
                   while (a != p) 
                      if (a->data > e){
		                 a->bf = LH;
		                 a = a->leftChild;
                      }
                      else {
                         a->bf = RH;
                         a = a->rightChild;
                      }
                }
                break;
			case EH:				// ����ת������Ҫ�޸�ƽ������
                while (a != p) 
                   if (a->data > e){
		              	a->bf = LH;
		              	a = a->leftChild;
                   }
                	else {
                   		a->bf = RH;
                   		a = a->rightChild;
                }
				break;
			case RH:				
		        if (a->data < e) {          // RR��ת
                   b = a->rightChild;    
                   if (b->data < e) {
		              a->bf = b->bf = EH;   // �޸�ƽ������
		              a->rightChild = b->leftChild;
		              b->leftChild = a;     // �����ת�������ĸ�Ϊb
                   }
                   else {
                      c = b->leftChild;    // RL��ת 
 		              if (c == p) {        // �޸�ƽ������
                         a->bf = b->bf = EH;
                      }
                      else if (e > c->data)
                         a->bf = LH;
                      else {
                         a->bf = EH;
                         b->bf = RH;
                      } 
                      // ����RL��ת  
                      b->leftChild = c->rightChild;
                      a->rightChild = c->leftChild;
                      c->rightChild = b;
                      c->leftChild = a;
                      b = c;           // �����ת�������ĸ�Ϊb
                   }    
                   // �������ת���������뵽ԭ����    
                   if (af == NULL)
                      root = b;    // ʧȥƽ�����С�����ĸ�Ϊ�������ĸ� 
                   else if (e < af->data)
                      af->leftChild = b; // ʧȥƽ�����С����Ϊ��˫�׵������� 
                   else
                      af->rightChild = b;// ʧȥƽ�����С����Ϊ��˫�׵�������   
               }   
                else {               // ����ת������Ҫ�޸�ƽ������
                   a->bf = EH;
                   a = a->leftChild;
                   while (a != p) 
                      if (a->data > e){
		                 a->bf = LH;
		                 a = a->leftChild;
                      }
                      else {
                         a->bf = RH;
                         a = a->rightChild;
                      }
                }
				break;
        }
		return true;		
	}
	else	// ���ҳɹ�, �����ʧ��
		return false;
}

template <class ElemType>
void BinaryAVLTree<ElemType>::DeleteLeftBalance(BinAVLTreeNode<ElemType> *&
subRoot, bool &isShorter)
// �������: ����subRootΪ���Ķ�����ɾ��ʱ����ƽ�⴦��, ɾ��subRoot���������ϵĽ�㣬��
//	���subRootָ���µ��������
{
	BinAVLTreeNode<ElemType> *ptrRChild, *ptrRLChild;	
	ptrRChild  = subRoot->rightChild;	// ptrRChildָ��subRoot�Һ���
	switch (ptrRChild->bf)	{	// ����subRoot����������ƽ����������Ӧ��ƽ�⴦��
	case RH:							// �Ҹߣ���������ת
		subRoot->bf = ptrRChild->bf = EH;// ƽ�����Ӷ�Ϊ0
		LeftRotate(subRoot);			// ����
		isShorter = true;
		break;
	case EH:							// �ȸߣ���������ת
		subRoot->bf = RH;
		ptrRChild->bf = LH;		
		LeftRotate(subRoot);			// ����
		isShorter = false;
		break;
	case LH:							// ���,������������
		ptrRLChild = ptrRChild->leftChild;	// ptrRLChildָ��subRoot���Һ��ӵ��������ĸ�
		switch (ptrRLChild->bf)		{	// �޸�subRoot���Һ��ӵ�ƽ������
		case LH:
			subRoot->bf = EH;
			ptrRChild->bf = RH;
			isShorter = true;
			break;
		case EH:
			subRoot->bf = ptrRChild->bf = EH;
			isShorter = false;
			break;
		case RH:
			subRoot->bf = LH;
			ptrRChild->bf = EH;
			isShorter = true;
			break;
		}
		ptrRLChild->bf = 0;
		RightRotate(subRoot->rightChild);	// ��subRoot����������������
		LeftRotate(subRoot);				// ��subRoot����������
	}
}

template <class ElemType>
void BinaryAVLTree<ElemType>::DeleteRightBalance(BinAVLTreeNode<ElemType> *
&subRoot, bool &isShorter)
// �������: ����subRootΪ���Ķ�����ɾ��ʱ����ƽ�⴦��, ɾ��subRoot���������ϵĽ�㣬��
//	���subRootָ���µ��������
{
	BinAVLTreeNode<ElemType> *ptrLChild, *ptrLRChild;	
	ptrLChild  = subRoot->leftChild;// ptrLChildָ��subRoot����
	switch (ptrLChild->bf)	{	    // ����subRoot����������ƽ����������Ӧ��ƽ�⴦��
	case LH:						// �Ҹߣ���������ת
		subRoot->bf = ptrLChild->bf = EH;// ƽ�����Ӷ�Ϊ0
		RightRotate(subRoot);		// ����
		isShorter = true;
		break;
	case EH:						// �ȸߣ���������ת
		subRoot->bf = LH;
		ptrLChild->bf = RH;			// ƽ�����Ӷ�Ϊ0
		RightRotate(subRoot);		// ����
		isShorter = false;
		break;
	case RH:						// ���,������������
		ptrLRChild = ptrLChild->rightChild;// ptrLRChildָ��subRoot�����ӵ��������ĸ�
		switch (ptrLRChild->bf)
		{	// �޸�subRoot�����ӵ�ƽ������
		case LH:
			subRoot->bf = RH;
			ptrLChild->bf = EH;
			isShorter = true;
			break;
		case EH:
			subRoot->bf = ptrLChild->bf = EH;
			isShorter = false;
			break;
		case RH:
			subRoot->bf = EH;
			ptrLChild->bf = LH;
			isShorter = true;
			break;
		}
		ptrLRChild->bf = 0;
		LeftRotate(subRoot->leftChild);	// ��subRoot����������������
		RightRotate(subRoot);			// ��subRoot����������
	}
}

template <class ElemType>
void BinaryAVLTree<ElemType>::DeleteBalance(const ElemType &key, 
LinkStack<BinAVLTreeNode<ElemType> *> &s)
// �������: ���ݲ���·������ɾ�������л���,����ƽ�⴦��
{
	bool isShorter = true;
	while (!s.IsEmpty() && isShorter)	{
		BinAVLTreeNode<ElemType> *ptrCurNode, *ptrParent;
		s.Pop(ptrCurNode);		// ȡ����ƽ��Ľ��
		if (s.IsEmpty())	    // ptrCurNode��Ϊ�����,ptrParentΪ��
			ptrParent = NULL;
		else	                // ptrCurNode��Ϊ�����,ȡ��˫��ptrParent
			s.Top(ptrParent);

		if (key < ptrCurNode->data)		{	// ɾ��ptrCurNode���������ϵĽ��
			switch (ptrCurNode->bf)		{	// ���ptrCurNode��ƽ���
			case LH:						// ���
				ptrCurNode->bf = EH;
				break;
			case EH:						// �ȸ�
				ptrCurNode->bf = RH;
				isShorter = false;
				break;
			case RH:						// �Ҹ�
				if (ptrParent == NULL)	{	// �ѻ��ݵ������
					DeleteLeftBalance(ptrCurNode, isShorter);
					root = ptrCurNode;		// ת����ptrCurNodeΪ�¸�
				}
				else if (ptrParent->leftChild == ptrCurNode)// ptrParent��������ƽ�⴦��
					DeleteLeftBalance(ptrParent->leftChild, isShorter);
				else	// ptrParent��������ƽ�⴦��
					DeleteLeftBalance(ptrParent->rightChild, isShorter);
				break;
			}
		}
		else
		{	// ɾ��ptrCurNode���������ϵĽ��
			switch (ptrCurNode->bf)	   {	// ���ptrCurNode��ƽ���
			case RH: 						// �Ҹ�
				ptrCurNode->bf = EH;
				break;
			case EH: 						// �ȸ�
				ptrCurNode->bf = LH;
				isShorter = false;
				break;
			case LH: 						// ���
				if (ptrParent == NULL)	{	// �ѻ��ݵ������
					DeleteLeftBalance(ptrCurNode, isShorter);
					root = ptrCurNode;		// ת����ptrCurNodeΪ�¸�
				}
				else if (ptrParent->leftChild == ptrCurNode)	// ptrParent��������ƽ�⴦��
					DeleteLeftBalance(ptrParent->leftChild, isShorter);
				else	// ptrParent��������ƽ�⴦��
					DeleteLeftBalance(ptrParent->rightChild, isShorter);
				break;
			}
		}
	}
}

template <class ElemType>
void BinaryAVLTree<ElemType>::DeleteHelp(const ElemType &key, 
BinAVLTreeNode<ElemType> *&p, LinkStack< BinAVLTreeNode<ElemType> *> &s)
// �������: ɾ��pָ��Ľ��
{
	BinAVLTreeNode<ElemType> *tmpPtr, *tmpF;  
	if (p->leftChild == NULL && p->rightChild == NULL)	{// pΪҶ���
		delete p;
		p = NULL;
		DeleteBalance(key, s);
	}
	else if (p->leftChild == NULL)	{	// pֻ��������Ϊ��
		tmpPtr = p;
		p = p->rightChild;
		delete tmpPtr;
		DeleteBalance(key, s);
	}
	else if (p->rightChild == NULL)	{	// pֻ���������ǿ�
		tmpPtr = p;
		p = p->leftChild;
		delete tmpPtr;
		DeleteBalance(key, s);
	}
	else	{	// p������������ 
		tmpF = p;
		s.Push(tmpF);
		tmpPtr = p->leftChild;
		while (tmpPtr->rightChild != NULL)	{// ����p������������ֱ��ǰ��tmpPtr����˫��tmpF
			tmpF = tmpPtr;
			s.Push(tmpF);
			tmpPtr = tmpPtr->rightChild;
		}
		p->data = tmpPtr->data;// ��tmpPtrָ�����Ԫ��ֵ��ֵ����ɾ�����

		if (tmpF->rightChild == tmpPtr)	//  ɾ��tmpPtrָ��Ľ��
			DeleteHelp(key, tmpF->rightChild, s);
		else
			DeleteHelp(key, tmpF->leftChild, s);
	}
}

template <class ElemType>
bool BinaryAVLTree<ElemType>::Delete(const ElemType &key)
// �������: ɾ���ؼ���Ϊkey�Ľ��
{
	BinAVLTreeNode<ElemType> *p, *f;
	LinkStack< BinAVLTreeNode<ElemType> *> s;
	p = Find(key, f, s);
	if ( p == NULL)	    // ����ʧ��, ��ɾ��ʧ��
		return false;
	else	{	        // ���ҳɹ�, ����ʧ��
		if (f == NULL)	// ��ɾ�����Ϊ�����
			DeleteHelp(key, p, s);
		else if (key < f->data)		// key��˫��С,ɾ��f������
			DeleteHelp(key, f->leftChild, s);
		else	                    // key��˫�״�,ɾ��f���Һ���
			DeleteHelp(key, f->rightChild, s);
		return true;		
	}
}

template <class ElemType>
void BinaryAVLTree<ElemType>::DestroyHelp(BinAVLTreeNode<ElemType> *&r)
// ���������������r��ƽ�������
{
	if(r != NULL)	{	// r�ǿ�,ʵʩ����
		DestroyHelp(r->leftChild);		// ����������
		DestroyHelp(r->rightChild);		// ����������
		delete r;						// ���ٸ����
		r = NULL;
	}
}

template <class ElemType>
BinAVLTreeNode<ElemType> *BinaryAVLTree<ElemType>::CopyTreeHelp(BinAVLTreeNode<ElemType> *copy)
// �������������copyΪ����ƽ����������Ƴ��µ�ƽ�������,������ƽ��������ĸ�
{
	if (copy == NULL)	// ���ƿ�ƽ�������
		return NULL;					// ��ƽ���������Ϊ��	
	else	{	// ���Ʒǿ�ƽ�������
		BinAVLTreeNode<ElemType> *lChild = CopyTreeHelp(copy->leftChild);	// ����������
		BinAVLTreeNode<ElemType> *rChild = CopyTreeHelp(copy->rightChild);	// ����������
		BinAVLTreeNode<ElemType> *r = new BinAVLTreeNode<ElemType>(copy->data, copy->bf, lChild, rChild);
			// ���Ƹ����
		return r;
	}
}

template <class ElemType>
BinaryAVLTree<ElemType>::BinaryAVLTree(const BinaryAVLTree<ElemType> &copy)
// �������������֪ƽ�������������ƽ��������������ƹ��캯��
{
	root = CopyTreeHelp(copy.root);	// ����ƽ�������
}

template <class ElemType>
BinaryAVLTree<ElemType>::BinaryAVLTree(BinAVLTreeNode<ElemType> *r)
// ���������������rΪ����ƽ�������
{	
	root = r;	// ����ƽ�������
}

template <class ElemType>
BinaryAVLTree<ElemType> &BinaryAVLTree<ElemType>::operator=(const BinaryAVLTree<ElemType> &copy)
// �������������֪����ƽ����copy���Ƶ���ǰƽ�������--��ֵ�������
{
	if (&copy != this)	{
		DestroyHelp(root);				// �ͷ�ԭƽ���������ռ�ÿռ�
		root = CopyTreeHelp(copy.root);	// ����ƽ�������
	}
	return *this;
}

template <class ElemType>
void DisplayBTWithTreeShapeHelp(const BinAVLTreeNode<ElemType> *r, int level)
//	�������������״��ʽ��ʾ��rΪ����ƽ���������levelΪ���������������Ĳ����Ϊ1
{
	if(r != NULL)	{	//��������ʽ��ֻ��ʽ�ǿ���
		DisplayBTWithTreeShapeHelp<ElemType>(r->rightChild, level + 1);//��ʾ������
		cout << endl << endl;					//��ʾ����	
		for(int i = 0; i < level - 1; i++)
			cout << "       ";				//ȷ���ڵ�level����ʾ���
		cout << r->data << "(" << r->bf << ")";				//��ʾ���
		DisplayBTWithTreeShapeHelp<ElemType>(r->leftChild, level + 1);//��ʾ������
	}
}

template <class ElemType>
void DisplayBTWithTreeShape(const BinaryAVLTree<ElemType> &bt)
//	�����������״��ʽ��ʾƽ������� 
{
	DisplayBTWithTreeShapeHelp<ElemType>(bt.GetRoot(), 1);	
		// ��״��ʾ��bt.GetRoot()Ϊ����ƽ�������
	cout << endl;
}

#endif
