#include "BinarySortTree.h"			// ������������

int main(void)
{
	BinarySortTree<int> bt;
	int elem[] = {39, 68, 11, 23, 46, 34, 75, 86, 8, 71};
	int n = 10;
	
	for (int i = 0; i < n; i++)
		bt.Insert(elem[i]);			// ����elem�����е�Ԫ�ع������������

	cout << "ԭ����������:" << endl;
	DisplayBTWithTreeShape(bt);
	cout << endl;
	system("PAUSE");			

    char c = 'x';
    int x;

    while (c != '0')	{
        cout << endl << "1. ����Ԫ��.";
        cout << endl << "2. ����Ԫ��.";
        cout << endl << "3. ɾ��Ԫ��.";
        cout << endl << "4. �������.";
        cout << endl << "5. �������.";
        cout << endl << "6. �������.";
        cout << endl << "7. ��ʾ����������.";
		cout << endl << "0. �˳�";
		cout << endl << "ѡ����(0~7):";
		cin >> c;
		switch (c) 	{
		    case '1':
            	cout << endl << "�������Ԫ�ص�ֵ:";
			    cin >> x;
			    bt.Insert(x);
			    break;
           	case '2':
              	cout << endl << "�������Ԫ�ص�ֵ:";
			    cin >> x;
			    if (bt.Find(x) == NULL)
                   	cout << endl << "Ԫ�ز�����.";
              	else
                   	cout << endl << "Ԫ�ش���.";
			    break;
		    case '3':
              	cout << endl << "����ɾ��Ԫ�ص�ֵ:";
			    cin >> x;
			    bt.Delete(x);
			    break;
	         case '4':
				cout << endl;
				bt.PreOrder(Write<int>);
				break;
	         case '5':
				cout << endl;
				bt.InOrder(Write<int>);
				break;
	         case '6':
				cout << endl;
				bt.PostOrder(Write<int>);
				break;
	         case '7':
				cout << endl;
				DisplayBTWithTreeShape(bt);
				break;
		}
	}

	system("PAUSE");				
	return 0;							
}

