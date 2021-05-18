#include "ClosedHashTable.h"				// ɢ�б���

int main(void)
{
	ClosedHashTable<int, int> ht(20, 19);
	int elem[] = {19, 14, 23, 1, 68, 20, 84, 27, 55, 11, 10, 79};
	int k, n = 12;
	Status state;
	
	for (int i = 0; i < n; i++)
		ht.Insert(elem[i]);				// ������

	cout << "��ʼHash��(#λ�ñ�ʾ�գ�*λ�ñ�ʾɾ����Ԫ��):" << endl;
	ht.Traverse(Write);
	cout << endl;
	
    char c = 'x';
    int x;

    while (c != '0')	{
        cout << endl << "1. ����Ԫ��.";
        cout << endl << "2. ����Ԫ��.";
        cout << endl << "3. ɾ��Ԫ��.";
        cout << endl << "4. ��ʾHash��.";
		cout << endl << "0. �˳�";
		cout << endl << "ѡ����(0~4):";
		cin >> c;
		switch (c) 	{
		    case '1':
            	cout << endl << "�������Ԫ�ص�ֵ:";
			    cin >> x;
			    if ((state = ht.Insert(x)) == SUCCESS)
                  	cout << endl << "����ɹ�.";
              	else if (state == OVER_FLOW)
                   	cout << endl << "������.";
              	else 
                   	cout << endl << "Ԫ���Ѵ���.";
			    break;
           	case '2':
              	cout << endl << "�������Ԫ�ص�ֵ:";
			    cin >> x;
			    if ((k = ht.Search(x)) == -1)
                   	cout << endl << "Ԫ�ز�����.";
              	else
                   	cout << endl << "Ԫ�ص�λ����" << k;
			    break;
		    case '3':
              	cout << endl << "����ɾ��Ԫ�ص�ֵ:";
			    cin >> x;
			    if (ht.Delete(x))
                   	cout << endl << "ɾ���ɹ�.";
              	else
                   	cout << endl << "Ԫ�ز�����.";
			    break;
	         case '4':
				cout << endl;
			    ht.Traverse(Write<int>);
				break;
		}
	}
	
	system("PAUSE");			
	return 0;					
}

