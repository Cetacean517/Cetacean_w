#include "AdjListDirNetwork.h"			// ���������ڽӱ�

int main(void)
{
    try									// ��try��װ���ܳ����쳣�Ĵ���
	{
		int infity = DEFAULT_INFINITY;
		char vexs[] = {'0', '1', '2', '3','4','5','6'};
		int m[7][7] = {
			{infity, 8, infity, 4, 5, infity, infity},
			{infity, infity, 3, infity, infity, infity, infity},
			{infity, infity, infity, infity, infity, infity, 6},
			{infity, infity, infity, infity,1 ,infity, infity},
			{infity, 2, 7, infity, infity, 2, infity},
			{infity, infity, 3, infity, infity, infity, 9},
			{infity, infity, infity, infity, infity, infity, infity}
		};
		char c = 'a', e, e1, e2;
		int n = 7, v, v1, v2, w;

		AdjListDirNetwork<char, int> net(vexs, n);

		for (int v = 0; v < n; v++)
			for (int u = 0; u < n; u++)
				if (m[v][u] != infity) net.InsertArc(v, u, m[v][u]);

	    while (c != '0')	{
            cout << endl << "1. ���������.";
            cout << endl << "2. ��ʾ������.";
            cout << endl << "3. ȡָ�������ֵ.";
            cout << endl << "4. ����ָ�������ֵ.";
            cout << endl << "5. ɾ������.";
            cout << endl << "6. ���붥��.";
            cout << endl << "7. ɾ����.";
            cout << endl << "8. �����.";
            cout << endl << "9. ����ָ���ߵ�Ȩ.";
			cout << endl << "a. BFS����";
			cout << endl << "b. DFS����";
		    cout << endl << "0. �˳�";
		    cout << endl << "ѡ����(0~9):";
		    cin >> c;
		    switch (c) 		{
			    case '1':
			        net.Clear();
				    break;
			    case '2':
                    if (net.IsEmpty())
                        cout << "��������Ϊ�ա�" << endl;
                    else 
			            net.Display();
				    break;
			    case '3':
			        cout << endl << "���붥����ţ��������Ķ�����Ŵ�0��ʼ��:";
			        cin >> v;
		            net.GetElem(v, e);
		            cout << "���Ϊ" << v << "�Ķ���Ϊ" << e;
			        break;
			    case '4':
			        cout << endl << "���붥����ţ��������Ķ�����Ŵ�0��ʼ��:";
			        cin >> v;
			        cout << endl << "����" << v <<"�Ŷ����ֵ:";
			        cin >> e;
		            net.SetElem(v, e);
			        break;
			    case '5':
			        cout << endl << "���뱻ɾ�������ֵ:";
			        cin >> e;
		            net.DeleteVex(e);
			        break;
			    case '6':
			        cout << endl << "������붥���ֵ:";
			        cin >> e;
		            net.InsertVex(e);
			        break;
			    case '7':
			        cout << endl << "�����뱻ɾ���߹�������������ֵ:";
			        cin >> e1 >> e2;
			        v1 = net.GetOrder(e1);
			        v2 = net.GetOrder(e2);
		            net.DeleteArc(v1, v2);
			        break;
			    case '8':
			        cout << endl << "���������߹�������������ֵ�ͱߵ�Ȩֵ:";
			        cin >> e1 >> e2 >> w;
			        v1 = net.GetOrder(e1);
			        v2 = net.GetOrder(e2);
		            net.InsertArc(v1, v2, w);
			        break;
			    case '9':
			        cout << endl << "���������߹�������������ֵ�ͱߵ�Ȩֵ:";
			        cin >> e1 >> e2 >> w;
			        v1 = net.GetOrder(e1);
			        v2 = net.GetOrder(e2);
		            net.SetWeight(v1, v2, w);
			        break;
				case 'a' :
					net.ClearTag();
					cout << endl << "����BFS�����ж�ָ������֮���Ƿ����·��:"<<endl;
					cin >> v1 >> v2;
					cout << net.BFS(v1, v2);
					break;
				case 'b' :
					net.ClearTag();
					cout << endl << "����DFS�����ж�ָ������֮���Ƿ����·��:"<<endl;
					cin >> v1 >> v2;
					cout << net.DFS(v1, v2);
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

