#ifndef __BIN_TREE_NODE_H__
#define __BIN_TREE_NODE_H__

// �����������
template <class ElemType>
struct BinTreeNode
{
// ���ݳ�Ա:
	ElemType data;						// ������
	BinTreeNode<ElemType>  *leftChild;	// ����ָ����
	BinTreeNode<ElemType>  *rightChild;	// �Һ���ָ����

//	���캯��:
	BinTreeNode();		// �޲����Ĺ��캯�� 
	BinTreeNode(const ElemType &val,// ��֪����Ԫ��ֵ,ָ�����Һ��ӵ�ָ�빹��һ�����
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
BinTreeNode<ElemType>::BinTreeNode(const ElemType &val, 
	BinTreeNode<ElemType> *lChild, BinTreeNode<ElemType> *rChild)
// �������������һ��������Ϊval,����ΪlChild,�Һ���ΪrChild�Ľ��
{	
	data = val;					// ����Ԫ��ֵ
	leftChild = lChild;			// ����
	rightChild = rChild;		// �Һ���
}

#endif

