#pragma once
#include "Assistance.h"

// 有向图邻接矩阵类
template <class ElemType>
class AdjMatrixDirGraph
{
protected:
	//邻接矩阵的数据成员
	int vexNum, vexMaxNum, arcNum;
	int **arcs;
	ElemType* vertexes;
	mutable Status* tag;

public:
	AdjMatrixDirGraph(ElemType es[], int vertexNum, int vertexMaxNum = DEFAULT_SIZE);
	// 以数组es[]为顶点,顶点个数为vertexNum,允许的顶点最大数目为vertexMaxNum,边数为0的有向图
	AdjMatrixDirGraph(ElemType es[], int arc[6][6], int vertexNum, int vertexMaxNum = DEFAULT_SIZE);
	// 以数组es[]为顶点,顶点个数为vertexNum,允许的顶点最大数目为vertexMaxNum,边数为0的有向图
	AdjMatrixDirGraph(int vertexMaxNum = DEFAULT_SIZE);
	// 构造允许的顶点最大数目为vertexMaxNum,边数为0的无向图
	~AdjMatrixDirGraph();					// 析构函数
	void Clear();			              // 清空图			 
	bool IsEmpty();                 // 判断无向图是否为空 
	void Display();	                         // 显示邻接矩阵无向图
	int Findk(int i, int j, int n);
	int Find(int i, int j, int n);

};

template<class ElemType>
AdjMatrixDirGraph<ElemType>::AdjMatrixDirGraph(ElemType es[], int vertexNum, int vertexMaxNum)
// 操作结果：构造数据元素为es[],顶点个数为vertexNum,允许的顶点最大数目为vertexMaxNum,边数为0的无向图
{
//异常判断：
	if (vertexMaxNum < 0)
		throw Error("允许的顶点最大数目不能为负!");        // 抛出异常

	if (vertexMaxNum < vertexNum)
		throw Error("顶点数目不能大于允许的顶点最大数目!");// 抛出异常

//存入数据，构造图
	vexMaxNum = vertexMaxNum;
	vexNum = vertexNum;
	arcNum = 0;

	vertexes = new ElemType[vexMaxNum];		//给定点集开辟数组
	tag = new Status[vexMaxNum];			//给状态集开辟数组
	arcs = (int**) new int* [vexMaxNum];	//生成邻接矩阵
	for (int i = 0; i < vexMaxNum; i++)
		arcs[i] = new int[vexMaxNum];

// 存入数据,初始化变为0；
	for (int i = 0; i < vexNum; i++)
	{
		vertexes[i] = es[i];
		tag[i] = UNVISITED;

		for (int j = 0; j < vexNum; j++)
		{
			arcs[i][j] = 0;
		}
	}

}

template<class ElemType>
AdjMatrixDirGraph<ElemType>::AdjMatrixDirGraph(ElemType es[], int arc[6][6], int vertexNum, int vertexMaxNum)
{
	//异常判断：
	if (vertexMaxNum < 0)
		throw Error("允许的顶点最大数目不能为负!");        // 抛出异常

	if (vertexMaxNum < vertexNum)
		throw Error("顶点数目不能大于允许的顶点最大数目!");// 抛出异常

//存入数据，构造图
	vexMaxNum = vertexMaxNum;
	vexNum = vertexNum;
	arcNum = 0;

	vertexes = new ElemType[vexMaxNum];		//给定点集开辟数组
	tag = new Status[vexMaxNum];			//给状态集开辟数组
	arcs = (int**) new int* [vexMaxNum];	//生成邻接矩阵
	for (int i = 0; i < vexMaxNum; i++)
		arcs[i] = new int[vexMaxNum];

	// 存入数据,初始化变为0；
	for (int i = 0; i < vexNum; i++)
	{
		vertexes[i] = es[i];
		tag[i] = UNVISITED;

		for (int j = 0; j < vexNum; j++)
		{
			arcs[i][j] = arc[i][j];
		}
	}
}

template<class ElemType>
AdjMatrixDirGraph<ElemType>::AdjMatrixDirGraph(int vertexMaxNum)
// 操作结果：构造允许顶点的最大数目为vertexMaxNum的空无向图
{
	if (vertexMaxNum < 0)
		throw Error("允许的顶点最大数目不能为负!");// 抛出异常

	vexNum = 0;
	vexMaxNum = vertexMaxNum;
	arcNum = 0;

	vertexes = new ElemType[vexMaxNum];     // 生成生成顶点信息数组
	tag = new Status[vexMaxNum];			      // 生成标志数组
	arcs = (int**)new int* [vexMaxNum];    // 生成邻接矩阵
	for (int v = 0; v < vexMaxNum; v++)
		arcs[v] = new int[vexMaxNum];
}

template<class ElemType>
AdjMatrixDirGraph<ElemType>::~AdjMatrixDirGraph()
{
	delete[]vertexes;					// 释放顶点数据
	delete[]tag;						    // 释放标志

	for (int v = 0; v < vexMaxNum; v++)	// 释放邻接矩阵的行
		delete[]arcs[v];
	delete[]arcs;					    // 释放邻接矩阵
}

template<class ElemType>
void AdjMatrixDirGraph<ElemType>::Clear()
// 操作结果：把无向图的顶点数和边数设置为0.			 
{
	vexNum = 0;
	arcNum = 0;
}

template<class ElemType>
inline bool AdjMatrixDirGraph<ElemType>::IsEmpty()
// 操作结果：如果无向图为空返回true,否则返回false.
{
	return vexNum == 0;
}

template<class ElemType>
void AdjMatrixDirGraph<ElemType>::Display()
// 操作结果: 显示邻接矩阵无向图
{

	for (int v = 0; v < vexNum; v++)
		cout << "\t" << vertexes[v];
	cout << endl;

	for (int v = 0; v < vexNum; v++) {
		cout << vertexes[v];
		for (int u = 0; u < vexNum; u++)
			cout << "\t" << arcs[v][u];
		cout << endl;
	}
}

template<class ElemType>
int AdjMatrixDirGraph<ElemType>::Findk(int i,int j, int n)
//题目：编写一个算法，在以邻接矩阵方式存储有向图G中，求顶点i到j的不含回路的，长度为k的路径数。
{
	int count = 0;

	if (n == 1)					//路径为1时，直接在矩阵中寻找从i到j的之间是不是有弧。
	{
		if (arcs[i][j] == 1)
			return 1;
		else
			return 0;
	}
	else if (n > 1)
		for (int v = 0; v < vexNum; v++)
		{
			if (arcs[i][v] == 1 && v!=i)		//找从i到哪些顶点有路径，再进而找从v 开始到j有没有路径。
			{
				count += Findk(v, j, n - 1);
			}
		}
			
	return count;
}

template<class ElemType>
int AdjMatrixDirGraph<ElemType>::Find(int i, int j, int n)
{
	if (i == j)
	{
		throw Error("所求路径不为回路，请重新计算。");
	}

	return (Findk(i, j, n));
}
