#include<iostream>
#include<vector>
#include <iomanip>
#include <iterator>
using namespace std;

bool Advance = true;	// ���н��̽�����= false;����δ����, = true
int reminder = 10;		// reminder=ʣ���豸���ܸ���
bool Option;			// �Ƿ������������㷨

// ����PCB���̿�����ݽṹ���Լ���Ӧ��getter��setter����
class PCB				// ����PCB���̵����ݽṹ
{
private:
	int PID;			// ���̿��ƿ�ID
	bool Finish;		// ������ɱ�־��True = ���, False δ���
		
public:
	vector<int> Claim;			// ��̬����Ľ����� (1,2,3,4)
	int Max;					// ÿ�����̵������Ҫ���豸���� �ܺ�
	int Allocation;				// �Լ����䵽���豸�� (�Ѿ��еĸ�����
	int Need;					
	bool Flag;					// ��ȫ���㷨����¼�Ƿ�finish

	PCB();
	void setPCB(int pid, int all_t, int state, bool finish);
	int getPID(); 
	bool getFinish();
	void setFinish(bool finish);
};
// PCB��Ĺ��캯��
PCB::PCB() {
	PID = -1;
	Finish = false;
	Max;
	Allocation = 0;
	Flag = false;
};

int PCB::getPID()
{
	return PID;
}
bool PCB::getFinish()
{
	return Finish;
}
void PCB::setFinish(bool finish)
{
	Finish = finish;
}
// PCB�е�set����
void PCB::setPCB(int pid, int all_t = 0, int state = -1, bool finish = false)
{
	PID = pid;
	Finish = finish;
}


/* ���м��㷨��
	������ pcb���У�Option���Ƿ�ѡ����������
*/
void bank_alroightm(vector<PCB> &pcb, vector<PCB> &wait)
{
	cout << endl << "================ѡ��Ƿ���Ҫѡ�á���ֹ�������㷨===============" << endl;
	cout << "1. ѡ�á���ֹ�������㷨" << endl;
	cout << "0. ���á���ֹ�������㷨" << endl;
	cin >> Option;
	cout << "OPTION��";
	if (Option)
	{
		cout << "ѡ�á���ֹ�������㷨" << endl;
	}
	else
	{
		cout << "���á���ֹ�������㷨" << endl;
	}
	cout << endl << "=============== ���̿���Ϣ ================" << endl;
	cout << endl << "===�����̿���Ҫ����Դ���� " << endl;
	// ������н��̿飬��Ҫ�������Դ����
	vector<PCB>::iterator it;
	for (it = pcb.begin();it!=pcb.end();it++)
	{
		cout << "  PCB" << (*it).getPID() << " :  ";
		for (int j = 0; j < (*it).Claim.size(); j++)
		{
			cout << left << setw(5) << (*it).Claim[j] << " ";
		}
		cout << endl;
	}
	cout << endl << "==�����̿���Ҫ�������Դ�� " << endl;
	// ������н��̣������Ҫ�Ľ�������
	for (int i = 1; i <= 3; i++)
	{
		int max = pcb[i-1].Max;
		cout << "  PCB" << i << " Max:  " << left << setw(5) << max << endl;
		if (max > 10)
		{
			cout << "--------------------------------------------------------" << endl;
			cout << "ERROR1: ����" << i << "��Ҫ��Դ��������Դ���������Դ����" << endl;
			cout << "--------------------------------------------------------" << endl;
			cout << endl;
			return;
		}
	}

	// ʱ��Ƭ��ת���Ƚ��� 
	int count = pcb.size();				// ��ʼ��count= �����н��̵ĸ���
	cout << left << setw(10) << "PID" << setw(10) << "Allocation" << setw(10) << "Available" << endl;
	while (count)
	{
		it = pcb.begin();

		for (int m = 0; m < pcb.size();m++) {		// ��ʼ��pcb��Need�Ĵ�С
			pcb[m].Need = pcb[m].Max - pcb[m].Allocation;
		}

		if ((*it).Claim[0] > reminder)	// 1. ������Դ�� > ������Դ��������/������������
		{
			cout << "--------------------------------------------------------" << endl;
			cout << "ERROR2: ������Դ�� > �ɷ�����Դ����" << endl;
			cout << "--------------------------------------------------------" << endl;
			cout << endl;
			if (Option)
			{
				// ʹ�ý������������������
				PCB temp = *it;
				pcb.erase(pcb.begin());
				pcb.push_back(temp);
				cout << (*pcb.begin()).Claim[0] << endl;
			}
			else {
				return;	// û�н�������������ֱ���˳�
			}
		}
		else
		{								// 2. ������Դ���Է��䣬���а�ȫ���ж�
			// ��ȫ�㷨
			(*it).Flag = true;
			int work = reminder + (*it).Allocation;	// ʣ��ɷ�����Դ
			vector<PCB>::iterator it1;
			for (int i = 0; i < pcb.size(); i++)				// flag��ʼ��
			{
				pcb[i].Flag = false;
			}
			int p = 2;
			while (p > 1)
			{
				for (it1 = pcb.begin(); it1 != pcb.end() && !(*it1).Flag; it1++)
				{
					if (work >= (*it1).Need)
					{
						(*it1).Flag = true;
						work += (*it1).Allocation;
						p = p - 1;
					}
					else
					{
						cout << "--------------------------------------------------------" << endl;
						cout << "ERROR3���㷨����ȫ" << endl;
						cout << "--------------------------------------------------------" << endl;
						cout << endl;
						return;
					}
				}
			}

			//������Դ
			reminder -= (*it).Claim[0];
			(*it).Allocation += (*it).Claim[0];
			(*it).Claim.erase((*it).Claim.begin());
			cout << left << setw(10) << (*it).getPID()  << setw(10) << (*it).Allocation << setw(10) << reminder << endl;
			if ((*it).Claim.size() == 0)
			{
				count -= 1;
				(*it).setFinish(true);		// ���ý���
				cout << "--------------����" << (*it).getPID() << "�������------------" << endl;
				pcb.erase(pcb.begin());
				continue;
			}
			else
			{
				PCB temp = *it;
				pcb.erase(pcb.begin());
				pcb.push_back(temp);
			}
			
		}
	}
	cout << "=============== ���н��̾���������� ===============" << endl;
	return;
}

int main()
{
	int num = 3;
	// 1. ��ʼ�����̿��ƿ�
	vector<PCB> pcb;		// ����PCB�Ľ��̶���
	vector<PCB> wait;		// ����pcb�ľ�������
	vector<int> t(3);		// ������СΪ3����������,���ڼ�¼ʱ��Ƭ��

	cout << "---- ʱ��Ƭ���ã�����3�����̣���Ϊ�½���������ʱ��Ƭ�������磺1 2 3 -----" << endl;
	for (int i = 1; i <= 3; i++)
	{
		cin >> t[i - 1];
		PCB p;										// ����һ���µ�pcb���̿��ƿ�
		p.setPCB(i, t[i - 1], 2, false);			// ��ʼ�����̿����Ϣ
		pcb.push_back(p);							// ������pcb����PCB���е�ĩ��
	}
	copy(pcb.begin(), pcb.end(), back_inserter(wait));	// ��pcb����ȫ���������������

	cout << "----- ��Դ���ã�Ϊ�������̣����ÿ����Ҫ���豸���� -----" << endl;
	for (int i = 1; i <= 3; i++)
	{
		int sum = 0;
		cout << "--- ����NO:" << i << endl;
		cout << "--- ʱ��Ƭ��:" << t[i - 1] << endl;
		for (int j = 0; j < t[i - 1]; j++)
		{
			int k;
			cin >> k;
			pcb[i-1].Claim.push_back(k);		// ����ÿ��ʱ��Ƭ����Ҫ�Ľ�����Ϣ
			sum += k;
		}
		pcb[i-1].Max = sum;					// ���������Ҫ���������
		pcb[i-1].Flag = false;				// ����δ���

	}
	//2. ���Ŀ¼
	cout << endl;
	cout << "================���� ���м��㷨===============" << endl;
	bank_alroightm(pcb,wait);

}