#include "BinSerach.h"					// ˳�����ͷ�ļ�

int main(void)
{
	int elem[] = {8, 11, 23, 34, 39, 46, 68, 71, 86};
	int n =9;
	int k, p;
	char c = 'x';
	
	cout << "���ұ�Ϊ��" << endl;
	Display(elem, n);			

	while (c != '0')	{
        cout << endl << "1. �ݹ����Ԫ��.";
        cout << endl << "2. ��������Ԫ��.";
        cout << endl << "3. ��ʾ���ұ�.";
		cout << endl << "0. �˳�";
		cout << endl << "ѡ����(0~3):";
		cin >> c;
		switch (c) 	{
		    case '1':
            	cout << endl << "����ҪԪ�ص�ֵ:";
			    cin >> k;
				p = BinSerach(elem, 0, n - 1, k);	// �ݹ���۰���� 
				if (p >= 0)	// ���ҳɹ�
					cout << "���ҳɹ�,Ԫ��" << k << "��λ��Ϊ:" << p << endl;
				else		// ����ʧ��
					cout << "����ʧ��!" << endl;
			    break;
		    case '2':
            	cout << endl << "����ҪԪ�ص�ֵ:";
			    cin >> k;
				p = BinSerach(elem, n, k);	// �ݹ���۰���� 
				if (p >= 0)	// ���ҳɹ�
					cout << "���ҳɹ�,Ԫ��" << k << "��λ��Ϊ:" << p << endl;
				else		// ����ʧ��
					cout << "����ʧ��!" << endl;
			    break;
           	case '3':
			    Display(elem, n);			
			    break;
		}
	}

	system("PAUSE");
	return 0;

}
