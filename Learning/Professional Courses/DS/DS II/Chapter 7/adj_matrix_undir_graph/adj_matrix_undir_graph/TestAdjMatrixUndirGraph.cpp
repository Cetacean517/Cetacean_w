#include "AdjMatrixUndirGraph.h"		// �ڽӾ�������ͼ

int main(void)
{
    try									// ��try��װ���ܳ����쳣�Ĵ���
	{
		char vexs[] = {'A', 'B', 'C', 'D', 'E'};
		int m[5][5] = {
			{0, 1, 0, 1, 1},
			{1, 0, 1, 1, 0},
			{0, 1, 0, 1, 1},
			{1, 1, 1, 0, 0},
			{1, 0, 1, 0, 0},
		};
		char c = '0', e, e1, e2;
		int n = 5, v, v1, v2;

		AdjMatrixUndirGraph<char> g(vexs, n, 7);		// n�Ƕ��������7�Ǳ߳�

		for (int u = 0; u < n; u++)
			for (int v = 0; v < n; v++)
				if (m[u][v] == 1) g.InsertArc(u, v);

	    while (c != '9')	{
            cout << endl << "1. ͼ���.";
            cout << endl << "2. ��ʾͼ.";
            cout << endl << "3. ȡָ�������ֵ.";
            cout << endl << "4. ����ָ�������ֵ.";
            cout << endl << "5. ɾ������.";
            cout << endl << "6. ���붥��.";
            cout << endl << "7. ɾ����.";
            cout << endl << "8. �����.";
		    cout << endl << "9. �˳�";
		    cout << endl << "ѡ����(1~9):";
		    cin >> c;
		    switch (c) 		{
			    case '1':
			        g.Clear();
				    break;
			    case '2':
                    if (g.IsEmpty())
                        cout << "��ͼΪ�ա�" << endl;
                    else 
			            g.Display();
				    break;
			    case '3':
			        cout << endl << "���붥����ţ�ͼ�Ķ�����Ŵ�0��ʼ��:";
			        cin >> v;
		            g.GetElem(v, e);
		            cout << "���Ϊ" << v << "�Ķ���Ϊ" << e;
			        break;
			    case '4':
			        cout << endl << "���붥����ţ�ͼ�Ķ�����Ŵ�0��ʼ��:";
			        cin >> v;
			        cout << endl << "����" << v <<"�Ŷ����ֵ:";
			        cin >> e;
		            g.SetElem(v, e);
			        break;
			    case '5':
			        cout << endl << "���뱻ɾ�������ֵ:";
			        cin >> e;
		            g.DeleteVex(e);
			        break;
			    case '6':
			        cout << endl << "������붥���ֵ:";
			        cin >> e;
		            g.InsertVex(e);
			        break;
			    case '7':
			        cout << endl << "�����뱻ɾ���߹�������������ֵ:";
			        cin >> e1 >> e2;
			        v1 = g.GetOrder(e1);
			        v2 = g.GetOrder(e2);
		            g.DeleteArc(v1, v2);
			        break;
			    case '8':
			        cout << endl << "���������߹�������������ֵ:";
			        cin >> e1 >> e2;
			        v1 = g.GetOrder(e1);
			        v2 = g.GetOrder(e2);
		            g.InsertArc(v1, v2);
			        break;
       	      }
         }
	}
	catch (Error err)					// ��׽�������쳣
	{
		err.Show();						// ��ʾ�쳣��Ϣ
	}

	system("PAUSE");					// ���ÿ⺯��system()
	return 0;							// ����ֵ0, ���ز���ϵͳ
}

