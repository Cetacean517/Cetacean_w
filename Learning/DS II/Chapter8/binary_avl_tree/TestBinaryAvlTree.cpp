#include "BinaryAvlTree.h"				// ����ƽ������

int main(void)
{
    try									// ��try��װ���ܳ����쳣�Ĵ���
	{
		BinaryAVLTree<int> bt;
		int elem[] = {11, 39, 23, 68, 85, 8, 3, 46, 27, 50};
		int n = 10;
		
		cout << "�ӿ�����ʼ���β���Ԫ��{11, 39, 23, 68, 85, 8, 3, 46, 27, 50}���������ƽ������" << endl;		
		for (int i = 0; i < n; i++) {
			cout << "�����" << i + 1 << "Ԫ��" << elem[i] << endl; 
			bt.Insert(elem[i]);			// ������
            DisplayBTWithTreeShape(bt);
		    cout << endl;
		    system("PAUSE");				// ���ÿ⺯��system()
        }

		cout << "����Ķ���ƽ�����������ڵ�����Ϊ����ƽ������:" << endl;
		DisplayBTWithTreeShape(bt);
		cout << endl;
		system("PAUSE");				// ���ÿ⺯��system()
 
		cout << "�����:" << bt.NodeCount();
		cout << endl;
		system("PAUSE");				// ���ÿ⺯��system()

		cout << "�������:" << endl;
		bt.PreOrder(Write<int>);
		cout<<endl;
		system("PAUSE");				// ���ÿ⺯��system()

		cout << "�������:" << endl;
		bt.InOrder(Write<int>);
		cout<<endl;
		system("PAUSE");				// ���ÿ⺯��system()

		cout << "�������:" << endl;
		bt.PostOrder(Write<int>);
		cout<<endl;
		system("PAUSE");				// ���ÿ⺯��system()

		cout << "��α���:" << endl;
		bt.LevelOrder(Write<int>);
		cout<<endl;
		system("PAUSE");				// ���ÿ⺯��system()

		bt.Insert(25);					
		cout << "��������Ԫ��25��:" << endl;
		DisplayBTWithTreeShape(bt);
		cout << endl;
		system("PAUSE");				// ���ÿ⺯��system()

		bt.Delete(23);					
		cout << "ɾ������Ԫ��23��:" << endl;
		DisplayBTWithTreeShape(bt);
		cout << endl;
		system("PAUSE");				// ���ÿ⺯��system()

		bt.Delete(8);					
		cout << "ɾ������Ԫ��8��:" << endl;
		DisplayBTWithTreeShape(bt);
		cout << endl;
	}
	catch (Error err)					// ��׽�������쳣
	{
		err.Show();						// ��ʾ�쳣��Ϣ
	}

	system("PAUSE");					// ���ÿ⺯��system()
	return 0;							// ����ֵ0, ���ز���ϵͳ
}

