#pragma once
#include "Assistance.h"

// ����ͼ�ڽӾ�����
template <class ElemType>
class AdjMatrixDirGraph
{
protected:
	//�ڽӾ�������ݳ�Ա
	int vexNum, vexMaxNum, arcNum;
	int **arcs;
	ElemType* vertexes;
	mutable Status* tag;

public:
	AdjMatrixDirGraph(ElemType es[], int vertexNum, int vertexMaxNum = DEFAULT_SIZE);
	// ������es[]Ϊ����,�������ΪvertexNum,����Ķ��������ĿΪvertexMaxNum,����Ϊ0������ͼ
	AdjMatrixDirGraph(ElemType es[], int arc[6][6], int vertexNum, int vertexMaxNum = DEFAULT_SIZE);
	// ������es[]Ϊ����,�������ΪvertexNum,����Ķ��������ĿΪvertexMaxNum,����Ϊ0������ͼ
	AdjMatrixDirGraph(int vertexMaxNum = DEFAULT_SIZE);
	// ��������Ķ��������ĿΪvertexMaxNum,����Ϊ0������ͼ
	~AdjMatrixDirGraph();					// ��������
	void Clear();			              // ���ͼ			 
	bool IsEmpty();                 // �ж�����ͼ�Ƿ�Ϊ�� 
	void Display();	                         // ��ʾ�ڽӾ�������ͼ
	int Findk(int i, int j, int n);
	int Find(int i, int j, int n);

};

template<class ElemType>
AdjMatrixDirGraph<ElemType>::AdjMatrixDirGraph(ElemType es[], int vertexNum, int vertexMaxNum)
// �����������������Ԫ��Ϊes[],�������ΪvertexNum,����Ķ��������ĿΪvertexMaxNum,����Ϊ0������ͼ
{
//�쳣�жϣ�
	if (vertexMaxNum < 0)
		throw Error("����Ķ��������Ŀ����Ϊ��!");        // �׳��쳣

	if (vertexMaxNum < vertexNum)
		throw Error("������Ŀ���ܴ�������Ķ��������Ŀ!");// �׳��쳣

//�������ݣ�����ͼ
	vexMaxNum = vertexMaxNum;
	vexNum = vertexNum;
	arcNum = 0;

	vertexes = new ElemType[vexMaxNum];		//�����㼯��������
	tag = new Status[vexMaxNum];			//��״̬����������
	arcs = (int**) new int* [vexMaxNum];	//�����ڽӾ���
	for (int i = 0; i < vexMaxNum; i++)
		arcs[i] = new int[vexMaxNum];

// ��������,��ʼ����Ϊ0��
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
	//�쳣�жϣ�
	if (vertexMaxNum < 0)
		throw Error("����Ķ��������Ŀ����Ϊ��!");        // �׳��쳣

	if (vertexMaxNum < vertexNum)
		throw Error("������Ŀ���ܴ�������Ķ��������Ŀ!");// �׳��쳣

//�������ݣ�����ͼ
	vexMaxNum = vertexMaxNum;
	vexNum = vertexNum;
	arcNum = 0;

	vertexes = new ElemType[vexMaxNum];		//�����㼯��������
	tag = new Status[vexMaxNum];			//��״̬����������
	arcs = (int**) new int* [vexMaxNum];	//�����ڽӾ���
	for (int i = 0; i < vexMaxNum; i++)
		arcs[i] = new int[vexMaxNum];

	// ��������,��ʼ����Ϊ0��
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
// �������������������������ĿΪvertexMaxNum�Ŀ�����ͼ
{
	if (vertexMaxNum < 0)
		throw Error("����Ķ��������Ŀ����Ϊ��!");// �׳��쳣

	vexNum = 0;
	vexMaxNum = vertexMaxNum;
	arcNum = 0;

	vertexes = new ElemType[vexMaxNum];     // �������ɶ�����Ϣ����
	tag = new Status[vexMaxNum];			      // ���ɱ�־����
	arcs = (int**)new int* [vexMaxNum];    // �����ڽӾ���
	for (int v = 0; v < vexMaxNum; v++)
		arcs[v] = new int[vexMaxNum];
}

template<class ElemType>
AdjMatrixDirGraph<ElemType>::~AdjMatrixDirGraph()
{
	delete[]vertexes;					// �ͷŶ�������
	delete[]tag;						    // �ͷű�־

	for (int v = 0; v < vexMaxNum; v++)	// �ͷ��ڽӾ������
		delete[]arcs[v];
	delete[]arcs;					    // �ͷ��ڽӾ���
}

template<class ElemType>
void AdjMatrixDirGraph<ElemType>::Clear()
// ���������������ͼ�Ķ������ͱ�������Ϊ0.			 
{
	vexNum = 0;
	arcNum = 0;
}

template<class ElemType>
inline bool AdjMatrixDirGraph<ElemType>::IsEmpty()
// ����������������ͼΪ�շ���true,���򷵻�false.
{
	return vexNum == 0;
}

template<class ElemType>
void AdjMatrixDirGraph<ElemType>::Display()
// �������: ��ʾ�ڽӾ�������ͼ
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
//��Ŀ����дһ���㷨�������ڽӾ���ʽ�洢����ͼG�У��󶥵�i��j�Ĳ�����·�ģ�����Ϊk��·������
{
	int count = 0;

	if (n == 1)					//·��Ϊ1ʱ��ֱ���ھ�����Ѱ�Ҵ�i��j��֮���ǲ����л���
	{
		if (arcs[i][j] == 1)
			return 1;
		else
			return 0;
	}
	else if (n > 1)
		for (int v = 0; v < vexNum; v++)
		{
			if (arcs[i][v] == 1 && v!=i)		//�Ҵ�i����Щ������·�����ٽ����Ҵ�v ��ʼ��j��û��·����
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
		throw Error("����·����Ϊ��·�������¼��㡣");
	}

	return (Findk(i, j, n));
}
