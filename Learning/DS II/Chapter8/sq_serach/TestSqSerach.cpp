#include "SqSerach.h"		// ˳�����ͷ�ļ�

int main(void)
{
	int elem[] = {61, 82, 104, 55, 116, 73, 45, 23, 98};
	int n =9;
	int k, p;
	char c = 'x';
	
	cout << "���ұ�Ϊ��" << endl;
	Display(elem, n);			

	while (c != '0')	{
        cout << endl << "1. ����Ԫ��.";
        cout << endl << "2. ��ʾ���ұ�.";
		cout << endl << "0. �˳�";
		cout << endl << "ѡ����(0~2):";
		cin >> c;
		switch (c) 	{
		    case '1':
            	cout << endl << "����ҪԪ�ص�ֵ:";
			    cin >> k;
				p = SqSerach(elem, n, k);
				if (p >= 0)	// ���ҳɹ�
					cout << "���ҳɹ�,Ԫ��" << k << "��λ��Ϊ:" << p << endl;
				else		// ����ʧ��
					cout << "����ʧ��!" << endl;
			    break;
           	case '2':
			    Display(elem, n);			
			    break;
		}
	}

	system("PAUSE");
	return 0;
}
