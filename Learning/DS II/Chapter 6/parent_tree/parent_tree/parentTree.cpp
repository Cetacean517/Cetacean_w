#include "parentTree.h"
#include "parentTreeNode.h"
#include "Assistance.h"
using namespace std;

int main()
{
	try {
		char* v;
		int* r, number;

		cout << "请输入双亲树结点的个数" << endl;
		cin >> number;
		v = new char[number];		//开辟空间
		r = new int[number];
		cout << "请输入双亲数组的值,对应的根节点下标：" << endl;
		for (int i = 0; i < number; i++)
		{
			cin >> v[i];
			cin >> r[i];
		}
		parentTree<char> T(v, r, number);
		//T.Show();
		//cout << "该树的长度为：" << endl;
		//cout << T.getLength() << endl;
		//cout << "该树的高度为：" << endl;
		//cout << T.getHeight() << endl;
		cout << "该树的叶子结点数为：" << endl;
		cout << T.getLeaf() << endl;
	}
	catch (Error err)
	{
		err.Show();
	}
	return 0;
}