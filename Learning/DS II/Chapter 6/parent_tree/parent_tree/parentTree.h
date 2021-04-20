#pragma once
#include "parentTreeNode.h"
#include <iostream>
using namespace std;

template<class Elemtype>
class parentTree
{
public:
	parentTree();
	parentTree(Elemtype *v, int *r,int num);	//有参构造
	void Show() const;				//输出双亲树的数组
	virtual ~parentTree();
	int getHeight() const; //通过双亲顺序存储获取树的高
	int getLength() const; //通过双亲顺序存储获取树的度
	int getLeaf() const; //通过双亲顺序存储获取树的叶子结点数

protected:
	   //树的数据成员：
	parentTreeNode<Elemtype>* nodes;	//存储树的结点
	int num;						//存储结点数
	int maxSize;					//树结点的最大个数
};

template<class Elemtype>
parentTree<Elemtype>::parentTree()
{
	maxSize = 100000;
	nodes = new parentTreeNode<Elemtype>[maxSize];
	num = 0;	//结点个数为空
}

template<class Elemtype>
parentTree<Elemtype>::parentTree(Elemtype* v, int* r, int number)
{
	//v是存储数据的数组，r存储双亲结点地址的数组，number总的结点数
	maxSize = 100000;
	num = number;
	nodes = new parentTreeNode<Elemtype>[maxSize];
	for (int i = 0; i < num; i++)
	{
		nodes[i].data = v[i];
		nodes[i].parent = r[i];
	}
}

template<class Elemtype>
void parentTree<Elemtype>::Show() const
{	//输出形成的双亲数组及结点个数
	cout << "双亲树数组：" << endl;
	for (int i = 0; i < num; i++)
	{
		cout << nodes[i].data << "    " << nodes[i].parent << endl;
	}
	cout << "双亲树的结点个数共有：" << num << "个。" << endl;
}

template<class Elemtype>
parentTree<Elemtype>::~parentTree()
{
}

template<class Elemtype>
int parentTree<Elemtype>::getHeight() const
{	//思路：求出每棵树的最大高度，取其中的最大值（利用双亲是由叶子到根查找方便，倒着算高度，再筛选获得值）
	int count = 1;
	int max = 0;						//存放所有书的最大高度	
	int j = 0;
	for (int i = 0; i < num; i++)		//遍历所有结点，计算高度
	{
		j = i;							
		count = 1;								//每次置1，每个结点自身有高度
		while (nodes[j].parent != -1)			//找到根，结束
		{
			j = nodes[j].parent;
			count++;
		}
		if (max < count)						//求最大值
		{
			max = count;
		}
	}
	return max;
}

template<class Elemtype>
int parentTree<Elemtype>::getLength() const				
{//思路：分别求出每个结点的度，求度的最大值
	int max = 0;
	int* p = new int[num] {};		//开一个数组，标记每个几点的度		
	//for (int i = 0; i < num; i++)
	//{
	//	p[i] = 0;
	//}
	for (int i = 0; i < num; i++)
	{
		p[nodes[i].parent + 1]++;
	}
	for (int i = 0; i < num; i++)	//求算结点度的最大值
	{
		if (max < p[i])
		{
			max = p[i];
		}
	}
	return max;
}

template<class Elemtype>
int parentTree<Elemtype>::getLeaf() const
{//求取叶子结点方法，叶子结点=总结点数-非终端结点数
	int* p = new int[num];			//设置一个数组，标记有孩子的结点。
	int count = 0;	//非终端结点计数器
	int j = 0;
	for (int i = 0; i < num; i++)		//其中多计算了一个 root 的“前继” p[0]也置1了，但是p[0]实际上不存在。因此最后要+1
	{
		p[nodes[i].parent + 1] = 1;
	}
	while (j < num)
	{
		cout << j << ":" << p[j] << endl;
		if (p[j] == 1)
		{
			count++;
		}
		j++;
	}
	return (num - count + 1);		
}
