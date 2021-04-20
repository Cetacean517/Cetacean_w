#pragma once
#include "parentTreeNode.h"
#include <iostream>
using namespace std;

template<class Elemtype>
class parentTree
{
public:
	parentTree();
	parentTree(Elemtype *v, int *r,int num);	//�вι���
	void Show() const;				//���˫����������
	virtual ~parentTree();
	int getHeight() const; //ͨ��˫��˳��洢��ȡ���ĸ�
	int getLength() const; //ͨ��˫��˳��洢��ȡ���Ķ�
	int getLeaf() const; //ͨ��˫��˳��洢��ȡ����Ҷ�ӽ����

protected:
	   //�������ݳ�Ա��
	parentTreeNode<Elemtype>* nodes;	//�洢���Ľ��
	int num;						//�洢�����
	int maxSize;					//������������
};

template<class Elemtype>
parentTree<Elemtype>::parentTree()
{
	maxSize = 100000;
	nodes = new parentTreeNode<Elemtype>[maxSize];
	num = 0;	//������Ϊ��
}

template<class Elemtype>
parentTree<Elemtype>::parentTree(Elemtype* v, int* r, int number)
{
	//v�Ǵ洢���ݵ����飬r�洢˫�׽���ַ�����飬number�ܵĽ����
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
{	//����γɵ�˫�����鼰������
	cout << "˫�������飺" << endl;
	for (int i = 0; i < num; i++)
	{
		cout << nodes[i].data << "    " << nodes[i].parent << endl;
	}
	cout << "˫�����Ľ��������У�" << num << "����" << endl;
}

template<class Elemtype>
parentTree<Elemtype>::~parentTree()
{
}

template<class Elemtype>
int parentTree<Elemtype>::getHeight() const
{	//˼·�����ÿ���������߶ȣ�ȡ���е����ֵ������˫������Ҷ�ӵ������ҷ��㣬������߶ȣ���ɸѡ���ֵ��
	int count = 1;
	int max = 0;						//�������������߶�	
	int j = 0;
	for (int i = 0; i < num; i++)		//�������н�㣬����߶�
	{
		j = i;							
		count = 1;								//ÿ����1��ÿ����������и߶�
		while (nodes[j].parent != -1)			//�ҵ���������
		{
			j = nodes[j].parent;
			count++;
		}
		if (max < count)						//�����ֵ
		{
			max = count;
		}
	}
	return max;
}

template<class Elemtype>
int parentTree<Elemtype>::getLength() const				
{//˼·���ֱ����ÿ�����Ķȣ���ȵ����ֵ
	int max = 0;
	int* p = new int[num] {};		//��һ�����飬���ÿ������Ķ�		
	//for (int i = 0; i < num; i++)
	//{
	//	p[i] = 0;
	//}
	for (int i = 0; i < num; i++)
	{
		p[nodes[i].parent + 1]++;
	}
	for (int i = 0; i < num; i++)	//������ȵ����ֵ
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
{//��ȡҶ�ӽ�㷽����Ҷ�ӽ��=�ܽ����-���ն˽����
	int* p = new int[num];			//����һ�����飬����к��ӵĽ�㡣
	int count = 0;	//���ն˽�������
	int j = 0;
	for (int i = 0; i < num; i++)		//���ж������һ�� root �ġ�ǰ�̡� p[0]Ҳ��1�ˣ�����p[0]ʵ���ϲ����ڡ�������Ҫ+1
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
