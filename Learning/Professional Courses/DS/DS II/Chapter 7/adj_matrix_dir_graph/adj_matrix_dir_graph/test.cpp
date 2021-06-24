#include "AdjMatrixDirGraph.h"
#include "Assistance.h"
#include <iostream>
using namespace std;

int main() {
	try									// 用try封装可能出现异常的代码
	{
	//int num = 4, arcnum = 0;
	//char* es = new char[num];


	//cout << "请输入生成矩阵的定点个数 n 和边数 m:" << endl;
	//cin >> num >> arcnum;

	//int arc[num][num];
	//cout << "请输入定点集合的字母(默认用字母表示)" << endl;
	//for (int i = 0; i < num; i++)
	//{
	//	cin >> es[i];
	//}

	//cout << "请输入矩阵的关系" << endl;
	//for (int i = 0; i < num; i++)
	//{
	//	for (int j = 0; j < num; j++)
	//	{
	//		cin >> arc[i][j];
	//	}
	//}

		int num = 6, arcnum = 0;
		char es[] = { '0', '1', '2', '3', '4','5'};
		int m[6][6] = {
			{0, 1, 1, 1, 0, 0},
			{0, 0, 0, 0, 1, 1},
			{0, 0, 0, 0, 0, 0},
			{1, 1, 0, 1, 0, 0},
			{1, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 1, 0},
		};

		int num2 = 4;
		char es1[] = { 'A','B','C','D'};
		int n[4][4] = {
			{0,0,0,0},
			{1,0,1,1},
			{1,0,0,1},
			{1,0,0,0},
		};

		int i, j, k;

		AdjMatrixDirGraph<char> mine = AdjMatrixDirGraph<char>(es, m, num);
		cout << "显示示例矩阵：" << endl;
		mine.Display();
		cout << "路径关系： " << endl
			<< "        0 A ##" << endl
			<< "        1 B -> A ; B -> C ; B -> D." << endl
			<< "        2 C -> A ; C -> D" << endl
			<< "        3 D - > A" << endl;
		cout << "请输入起点i,终点j的下标，以及制定的路径长度k:" << endl;
		cout << "i: ";
		cin >> i;
		cout << "j: ";
		cin >> j;
		cout << "k: ";
		cin >> k;
		cout << "输出求得的路径总数： " << mine.Find(i, j, k) << endl;
	}
	catch (Error err)					// 捕捉并处理异常
	{
		err.Show();						// 显示异常信息
	}

	system("PAUSE");					// 调用库函数system()
	return 0;							// 返回值0, 返回操作系统
}