#include "parentTree.h"
#include "parentTreeNode.h"
#include "Assistance.h"
using namespace std;

int main()
{
	try {
		char* v;
		int* r, number;

		cout << "������˫�������ĸ���" << endl;
		cin >> number;
		v = new char[number];		//���ٿռ�
		r = new int[number];
		cout << "������˫�������ֵ,��Ӧ�ĸ��ڵ��±꣺" << endl;
		for (int i = 0; i < number; i++)
		{
			cin >> v[i];
			cin >> r[i];
		}
		parentTree<char> T(v, r, number);
		//T.Show();
		//cout << "�����ĳ���Ϊ��" << endl;
		//cout << T.getLength() << endl;
		//cout << "�����ĸ߶�Ϊ��" << endl;
		//cout << T.getHeight() << endl;
		cout << "������Ҷ�ӽ����Ϊ��" << endl;
		cout << T.getLeaf() << endl;
	}
	catch (Error err)
	{
		err.Show();
	}
	return 0;
}