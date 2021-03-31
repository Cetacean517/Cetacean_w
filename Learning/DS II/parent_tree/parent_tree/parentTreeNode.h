#pragma once

template <class Elemtype>
struct parentTreeNode
{
	//数据成员：
	Elemtype data;	//数据域
	int parent;		//双亲位置信息

	//构造函数：
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
