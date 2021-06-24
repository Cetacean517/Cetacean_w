#include "BinaryTree.h"		// 二叉链表类

int main(void)
{
	//BinTreeNode<char> *p;
	//char pre[]={'A','B','D','E','G','H','C','F','I'}; // 先序序列
	//char in[]={'D','B','G','E','H','A','C','F','I'};  // 中序序列
	int n = 0;
	char pre[1000];
	char in[1000];
	//int n = 9;						                  // 结点个数
	BinaryTree<char> bt;
    char c = 'x';
	
	
	//bt = CreateBinaryTree(pre, in, n);           // 构造二叉树
		
	//cout << "范例：由先序：A,B,D,E,G,H,C,F,I和中序：D,B,G,E,H,A,C,F,I构造的二叉树，" << endl;
	cout << "样例提示："<<endl<<"(1)7个结点的满二叉树的先序为:A,B,D,E,C,F,G; 中序为:D,B,E,A,F,C,G." << endl;
	cout << "(2)6个结点的完成二叉树的先序为:A,B,D,E,C,F; 中序为:D,B,E,A,F,C." << endl;
	cout << "(3)随机样例：先序：A,B,C,D,E; 中序:B,D,C,E,A" << endl;
	DisplayBTWithTreeShape<char>(bt);
	cout << endl;

    while (c != '0')	{
        cout << endl << "1. 创建二叉树";
        cout << endl << "2. 显示二叉树的宽度.";
		cout << endl << "0. 退出";
		cout << endl << "选择功能(0~7):";
		cin >> c;
		switch (c) 	{
		    case '1':
				cout << endl << "请输入创建二叉树的节点个数：";
				cin >> n;
				cout << endl << "请输入二叉树的先序遍历顺序：";
				for (int i = 0; i < n; i++)
				{
					cin >> pre[i];
				}
				cout << endl << "请输入二叉树的中序遍历顺序：";
				for (int i = 0; i < n; i++)
				{
					cin >> in[i];
				}
				bt = CreateBinaryTree(pre, in, n);           // 构造二叉树
			    break;	
			    break;
		    case '2':
				cout << "该二叉树是二叉排序树么？" <<endl;
				if (bt.JudgeBinTreeSort()) {
					cout << "yes." << endl;
				}
				else {
					cout << "no." << endl;
				}
				break;
		}
	}

	system("PAUSE");
	return 0;
}

