#include "AdjMatrixDirGraph.h"
#include "Assistance.h"
#include <iostream>
using namespace std;

int main() {
	try									// ��try��װ���ܳ����쳣�Ĵ���
	{
	//int num = 4, arcnum = 0;
	//char* es = new char[num];


	//cout << "���������ɾ���Ķ������ n �ͱ��� m:" << endl;
	//cin >> num >> arcnum;

	//int arc[num][num];
	//cout << "�����붨�㼯�ϵ���ĸ(Ĭ������ĸ��ʾ)" << endl;
	//for (int i = 0; i < num; i++)
	//{
	//	cin >> es[i];
	//}

	//cout << "���������Ĺ�ϵ" << endl;
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
		cout << "��ʾʾ������" << endl;
		mine.Display();
		cout << "·����ϵ�� " << endl
			<< "        0 A ##" << endl
			<< "        1 B -> A ; B -> C ; B -> D." << endl
			<< "        2 C -> A ; C -> D" << endl
			<< "        3 D - > A" << endl;
		cout << "���������i,�յ�j���±꣬�Լ��ƶ���·������k:" << endl;
		cout << "i: ";
		cin >> i;
		cout << "j: ";
		cin >> j;
		cout << "k: ";
		cin >> k;
		cout << "�����õ�·�������� " << mine.Find(i, j, k) << endl;
	}
	catch (Error err)					// ��׽�������쳣
	{
		err.Show();						// ��ʾ�쳣��Ϣ
	}

	system("PAUSE");					// ���ÿ⺯��system()
	return 0;							// ����ֵ0, ���ز���ϵͳ
}