// ���̵����㷨 ���
#include <iostream>
#include <vector>		// ����vector����
#include <algorithm>	// sort()������ͷ�ļ�
#include <iomanip>		// ʹ��setw()

using namespace std;

class PCB				// ����PCB���̵����ݽṹ
{
private:
	int PID;			// ���̿��ƿ�ID
	int Priority;		// ����Ȩ��
	int CPUtime;		// CPU�Ѿ����е�ʱ��
	int ALLtime;		// ʣ����Ҫ���е�ʱ��
	int State;			// ���̵�ǰ��״̬��1 ���� 2 ���� 3 �ȴ� -1 δ��ʼ��
	bool Finish;		// ������ɱ�־��True = ���, False δ���
public:
	PCB();
	void setPCB(int pid, int priority, int all_t, int state, bool finish);
	int getPID();
	int getPriority();
	void setPriority(int priority);
	int getCPUtime();
	void setCPUtime(int cpu_t);
	int getALLtime();
	void setALLtime(int all_t);
	int getState();
	void setState(int state);
	bool getFinish();
	void setFinish(bool finish);
	
};
// PCB��Ĺ��캯��
PCB::PCB() {
	PID = -1;
	Priority = -1;
	CPUtime = 0;
	ALLtime = -1;
	State = -1;
	Finish = false;
};

int PCB::getPID()
{
	return PID;
}
int PCB::getPriority()
{
	return Priority;
}
void PCB::setPriority(int priority)
{
	Priority = priority;
}
int PCB::getCPUtime()
{
	return CPUtime;
}
void PCB::setCPUtime(int cpu_t)
{
	CPUtime = cpu_t;
}
int PCB::getALLtime()
{
	return ALLtime;
}
void PCB::setALLtime(int all_t)
{
	ALLtime = all_t;
}
int PCB::getState()
{
	return State;
}
void PCB::setState(int state)
{
	State = state;
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
void PCB::setPCB(int pid, int priority, int all_t = 0, int state = -1, bool finish = false)
{
	PID = pid;
	Priority = priority;
	ALLtime = all_t;
	State = state;
	Finish = finish;
}

// sort�������أ��Զ��尴������������������ͬʱ������������Ƚ��ȳ���
bool priority_sort(PCB& p, PCB& q)
{
	if (p.getPriority() == q.getPriority()) return p.getPID() < q.getPID();
	return p.getPriority() > q.getPriority();
}

// ���ȼ������㷨
void priority_choose(vector<PCB>& pcb, vector<PCB>& wait) {
	/*������pcb:���̶��У�wait:��������, num:���̵ĸ���*/
	vector<PCB>::iterator it;
	it = pcb.begin();
	int count = pcb.size();		// count = ʣ��Ҫ���еĽ��̸���
	while (count)
	{
		wait.erase(wait.begin());	//������������е�һ������

		// ����pcb������
		(*it).setState(1);
		(*it).setPriority((*it).getPriority() - 1);
		if ((*it).getPriority() < 0)	// �����ȼ�����0��ʱ�򣬲��ټ�����
		{
			(*it).setPriority(0);
		}
		(*it).setCPUtime((*it).getCPUtime() + 1);
		(*it).setALLtime((*it).getALLtime() - 1);

		// ���н���������ɣ������������Ҵ������������Ƴ�
		if ((*it).getALLtime() == 0)
		{
			count -= 1;				// ʣ�������-1
			(*it).setFinish(true);
			cout << "--------------����" << (*it).getPID() << "�������------------" << endl;
			cout << left << setw(10) << (*it).getPID() << setw(10) << (*it).getState() << setw(10) << (*it).getPriority() << setw(10) << (*it).getCPUtime() << setw(10) << (*it).getALLtime() << setw(10) << (*it).getFinish() << endl;
			pcb.erase(pcb.begin());
			sort(wait.begin(), wait.end(), priority_sort);
			sort(pcb.begin(), pcb.end(), priority_sort);
			it = pcb.begin();
		}
		else
		{
			// ������û�������꣬����������������
			cout << left << setw(10) << (*it).getPID() << setw(10) << (*it).getState() << setw(10) << (*it).getPriority() << setw(10) << (*it).getCPUtime() << setw(10) << (*it).getALLtime() << setw(10) << (*it).getFinish() << endl;
			(*it).setState(2);		// ���̴��ڵȴ�״̬
			wait.push_back(*it);	// δ�������pcb���²���������е�ĩβ
			sort(wait.begin(), wait.end(), priority_sort);
			sort(pcb.begin(), pcb.end(), priority_sort);
		}
	}
}

void rr_choose(vector<PCB>& pcb, vector<PCB>& wait)
{
	vector<PCB>::iterator it;
	int count = pcb.size();
	while (count)
	{
		it = pcb.begin();
		wait.erase(wait.begin());
		(*it).setState(1);
		if ((*it).getALLtime() < 3)
		{
			count -= 1;
			(*it).setCPUtime((*it).getALLtime());
			(*it).setALLtime(0);
			(*it).setFinish(true);
			cout << "--------------����" << (*it).getPID() << "�������------------" << endl;
			cout << left << setw(10) << (*it).getPID() << setw(10) << (*it).getState() << setw(10) << (*it).getPriority() << setw(10) << (*it).getCPUtime() << setw(10) << (*it).getALLtime() << setw(10) << (*it).getFinish() << endl;
			pcb.erase(pcb.begin());
			continue;
		}
		else
		{
			(*it).setCPUtime((*it).getCPUtime() + 2);
			(*it).setALLtime((*it).getALLtime() - 2);
			cout << left << setw(10) << (*it).getPID() << setw(10) << (*it).getState() << setw(10) << (*it).getPriority() << setw(10) << (*it).getCPUtime() << setw(10) << (*it).getALLtime() << setw(10) << (*it).getFinish() << endl;
			(*it).setState(2);
			wait.push_back(*it);
			PCB temp = *it;
			pcb.erase(pcb.begin());
			pcb.push_back(temp);
		}
	}
}

int main()
{
	int num = -1; // num:��Ҫ�����ȵĽ��̸���
	char choice = NULL;
	cout << "===============�����㷨Ŀ¼===============" << endl;
	cout << "A. �����������㷨" << endl;
	cout << "B. ʱ��Ƭ��ת�����㷨" << endl;
	cout << "��ѡ����ģ��ĵ����㷨:" << endl;
	
	// ����0 �˳�
	while (cin >> choice)
	{
		switch (choice)
		{
		case 'A':
		{
									// ���������򣬿��Խ����switch�д���class����
			// 1. ��ʼ������
			vector<PCB> pcb;		// ����PCB�Ľ��̶���

			cout << "===============�����������㷨===============" << endl;
			cout << "��������̵��ܸ�����" << endl;
			cin >> num;

			vector<PCB> wait;	// ����pcb�ľ�������
			vector<int> a(num);		// ������СΪnum����������,���ڼ�¼���ȼ�
			vector<int> b(num);		// ������СΪnum����������,���ڼ�¼ʱ��Ƭ��
			cout << "����" << num << "�����̣���Ϊ�½���������������(������Խ�����ȼ�Խ��)" << endl;
			cout << "���磺1 2 3 4 5 ������5�����̵��������ֱ�����Ϊ1 2 3 4 5" << endl;
			
			for (int i = 0; i < num; i++)
			{
				cin >> a[i];
			}
			cout << "��Ϊ�½��������ø�����Ҫ���е�ʱ��Ƭ��" << endl;
			for (int i = 1; i <= num; i++)
			{
				cin >> b[i-1];
				PCB p1;										// ����һ���µ�pcb���̿��ƿ�
				p1.setPCB(i, a[i - 1], b[i-1], 2,false);	// ��ʼ�����̿����Ϣ
				pcb.push_back(p1);							// ������pcb����PCB���е�ĩ��
			}

			// ��������sort��������pcb���н��л���������������
			// void sort (RandomAccessIterator first, RandomAccessIterator last, Compare comp);
			// ��ʼ����β���������˳��
			sort(pcb.begin(),pcb.end(),priority_sort);
			copy(pcb.begin(), pcb.end(), back_inserter(wait));	// ��������pcb����ȫ���������������

			//2. ���Ŀ¼
			cout << endl;
			cout << "=============== ��ʼ���� ===============" << endl;
			cout << "�ý�������������£�Finish=0����δ��ɣ�Finish=1��������ɣ�" << endl;
			cout << left << setw(10) << "ID" << setw(10) << "State" << setw(10) << "Priority" << setw(10) << "CPUtime" << setw(10) << "ALLtime " << setw(10) << "Finish" << endl;
			priority_choose(pcb, wait);
			cout << "=============== ���н��̾���������� ===============" << endl;
			break;
		}
		case 'B':
		{
			// 1. ��ʼ������
			vector<PCB> pcb;		// ����PCB�Ľ��̶���

			cout << "===============ʱ��Ƭ��ת�����㷨===============" << endl;
			cout << "��������̵��ܸ�����" << endl;
			cin >> num;

			vector<PCB> wait;	// ����pcb�ľ�������
			vector<int> t(num);		// ������СΪnum����������,���ڼ�¼ʱ��Ƭ��
			cout << "����" << num << "�����̣���Ϊ�½���������ʱ��Ƭ�������磺1 2 3 2 3" << endl;
			for (int i = 1; i <= num; i++)
			{
				cin >> t[i - 1];
				PCB p2;										// ����һ���µ�pcb���̿��ƿ�
				p2.setPCB(i, -1, t[i - 1], 2, false);		// ��ʼ�����̿����Ϣ
				pcb.push_back(p2);							// ������pcb����PCB���е�ĩ��
			}			
			copy(pcb.begin(), pcb.end(), back_inserter(wait));	// ��pcb����ȫ���������������

			//2. ���Ŀ¼
			cout << endl;
			cout << "=============== ��ʼ���� ===============" << endl;
			cout << "�ý�������������£�Finish=0����δ��ɣ�Finish=1��������ɣ�" << endl;
			cout << left << setw(10) << "ID" << setw(10) << "State" << setw(10) << "Priority" << setw(10) << "CPUtime" << setw(10) << "ALLtime " << setw(10) << "Finish" << endl;
			rr_choose(pcb,wait);
			cout << "=============== ���н��̾���������� ===============" << endl;
			break;
		}
		default:
			break;
		}
	}
	return 0;
}

