#include "BinaryTree.h"		// ����������

int main(void)
{
	//BinTreeNode<char> *p;
	//char pre[]={'A','B','D','E','G','H','C','F','I'}; // ��������
	//char in[]={'D','B','G','E','H','A','C','F','I'};  // ��������
	int n = 0;
	char pre[1000];
	char in[1000];
	//int n = 9;						                  // ������
	BinaryTree<char> bt;
    char c = 'x';
	
	
	//bt = CreateBinaryTree(pre, in, n);           // ���������
		
	//cout << "������������A,B,D,E,G,H,C,F,I������D,B,G,E,H,A,C,F,I����Ķ�������" << endl;
	cout << "������ʾ��"<<endl<<"(1)7��������������������Ϊ:A,B,D,E,C,F,G; ����Ϊ:D,B,E,A,F,C,G." << endl;
	cout << "(2)6��������ɶ�����������Ϊ:A,B,D,E,C,F; ����Ϊ:D,B,E,A,F,C." << endl;
	cout << "(3)�������������A,B,C,D,E; ����:B,D,C,E,A" << endl;
	DisplayBTWithTreeShape<char>(bt);
	cout << endl;

    while (c != '0')	{
        cout << endl << "1. ����������";
        cout << endl << "2. ��ʾ�������Ŀ��.";
		cout << endl << "0. �˳�";
		cout << endl << "ѡ����(0~7):";
		cin >> c;
		switch (c) 	{
		    case '1':
				cout << endl << "�����봴���������Ľڵ������";
				cin >> n;
				cout << endl << "��������������������˳��";
				for (int i = 0; i < n; i++)
				{
					cin >> pre[i];
				}
				cout << endl << "��������������������˳��";
				for (int i = 0; i < n; i++)
				{
					cin >> in[i];
				}
				bt = CreateBinaryTree(pre, in, n);           // ���������
			    break;	
			    break;
		    case '2':
				cout << "�ö������Ƕ���������ô��" <<endl;
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

