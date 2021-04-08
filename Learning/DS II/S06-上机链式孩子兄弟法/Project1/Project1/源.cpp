//#include <cstddef>
//typedef struct Node {
//	char data;
//	struct Node* firstchild, * nextsibling;
//}Node,*Tree;
//
//int Height(Tree T)
//{
//	int hc, hs;
//	if (T == NULL) return 0;
//	else {
//		hc = Height(T->firstchild);
//		hs = Height(T->nextsibling);
//		if (hc + 1 > hs)
//			return hc + 1;
//		return hs;
//	}
//}
//
//int main() {
//	char items[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };
//	int parents[] = { -1, 0, 0, 0, 1, 1, 3, 3 };
//	int n = 8;
//}


#define MAXQUEUESIZE 10

#include<iostream>
#include<malloc.h>

using namespace std;

typedef struct CSNode {
	int data;
	int number;
	struct CSNode* firstChild, * nextSibling, * parent;
}CSNode, * CSTree;

int number = 0;
int yon = 0;
int yesOrNo[] = { 1,1,0,0,1,1,1,0,1,0,0,1,0,0,0,0 };
int numData[] = { 1,2,4,3,5,7,8,6 };

CSTree treeParent = NULL;

int OperationTree(CSTree& T) {
	T = (CSTree)malloc(sizeof(CSNode));
	if (!T)
	{
		cout << "空间分配失败(Allocate space failure.)" << endl;
		exit(OVERFLOW);
	}
	T->data = numData[number];
	T->number = number;
	number++;
	T->firstChild = NULL;
	T->nextSibling = NULL;
	T->parent = treeParent;
	return 1;
}

int RecursionEstablishTree(CSTree& T) {
	OperationTree(T);
	treeParent = T;
	if (yesOrNo[yon++])
		RecursionEstablishTree(T->firstChild);
	treeParent = T;
	if (yesOrNo[yon++])
		RecursionEstablishTree(T->nextSibling);
	return 1;
}

void VisitCSTree(CSTree T) {
	cout << "The number of present node is ：" << T->number << ",";
	cout << "and the data is ：" << T->data << ".";
	if (T->firstChild) {
		cout << "This node has child and the number is :" << T->firstChild->number;
		CSTree p = T->firstChild;
		while (p->nextSibling) {
			cout << " , " << p->nextSibling->number;
			p = p->nextSibling;
		}

	}
	cout << endl;
}

//Visit tree use the preorder technique. 
void PreOrderVisitTree(CSTree T) {
	if (T)
	{
		VisitCSTree(T);
		PreOrderVisitTree(T->firstChild);
		PreOrderVisitTree(T->nextSibling);
	}
}

int TreeHeight(CSTree T) {
	int hc, hs;
	if (T == NULL)
		return 0;
	else
	{
		hc = TreeHeight(T->firstChild);
		hs = TreeHeight(T->nextSibling);
		if (hc + 1 > hs)
			return (hc + 1);
		else
			return hs;
	}
}

void Degree(CSTree T, int& max)
{
	if (T == NULL)
		return;
	if (T->firstChild)
	{
		CSTree p = T->firstChild;
		int n;
		n = 1;
		while (p->nextSibling)
		{
			p = p->nextSibling;
			n++;
		}
		if (n > max)
			max = n;
	}
	Degree(T->firstChild, max);
	Degree(T->nextSibling, max);
}

int leafcount(CSTree T)
{
	CSNode *child;
	if (!T->firstChild) return 1;
	else {
		int count = 0;
		for (child = T->firstChild;child != NULL;child = child->nextSibling)
		{
			count += leafcount(child);
			
		}
		return count;
	}
}

void main() {
	int max = 1;
	CSTree T;
	RecursionEstablishTree(T);
	//PreOrderVisitTree(T);
	cout << "高度：" << TreeHeight(T) << endl;
	Degree(T, max);
	cout << "度：" << max<< endl;
	cout << "叶子节点" << leafcount(T) << endl;
}
