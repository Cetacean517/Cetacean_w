#pragma once

template <class Elemtype>
struct parentTreeNode
{
	//���ݳ�Ա��
	Elemtype data;	//������
	int parent;		//˫��λ����Ϣ

	//���캯����
	parentTreeNode();
	parentTreeNode(Elemtype item, int pt = -1);
};

template<class Elemtype>
parentTreeNode<Elemtype>::parentTreeNode()
{
	parent = -1;
}

template<class Elemtype>
parentTreeNode<Elemtype>::parentTreeNode(Elemtype item, int pt)
{
	data = item;
	parent = pt;
}
