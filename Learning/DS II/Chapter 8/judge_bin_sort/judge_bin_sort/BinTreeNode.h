#ifndef __BIN_TREE_NODE_H__
#define __BIN_TREE_NODE_H__

// ������������
template <class ElemType>
struct BinTreeNode
{
// ���ݳ�Ա:
	ElemType data;						// ������
	BinTreeNode<ElemType>  *leftChild;	// ����ָ����
	BinTreeNode<ElemType>  *rightChild;	// �Һ���ָ����

//	���캯��:
	BinTreeNode();		// �޲����Ĺ��캯�� 
	BinTreeNode(const ElemType &d,// ��֪����Ԫ��ֵ,ָ�����Һ��ӵ�ָ�빹��һ�����
		BinTreeNode<ElemType> *lChild = NULL, 
		BinTreeNode<ElemType> *rChild = NULL);
};

// ������������ʵ�ֲ���
template <class ElemType>
BinTreeNode<ElemType>::BinTreeNode()
// �������������һ��Ҷ���
{
	leftChild = rightChild = NULL;	// Ҷ������Һ���Ϊ��
}

template <class ElemType>
BinTreeNode<ElemType>::BinTreeNode(const ElemType &d, 
	BinTreeNode<ElemType> *lChild, BinTreeNode<ElemType> *rChild)
// �������������һ��������Ϊd,����ΪlChild,�Һ���ΪrChild�Ľ��
{	
	data = d;					// ����Ԫ��ֵ
	leftChild = lChild;			// ����
	rightChild = rChild;		// �Һ���
}

#endif

