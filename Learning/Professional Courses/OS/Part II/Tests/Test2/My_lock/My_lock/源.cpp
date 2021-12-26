#include<iostream>
#include<vector>
#include <iomanip>
#include <iterator>
using namespace std;

bool Advance = true;	// 所有进程结束，= false;进程未结束, = true
int reminder = 10;		// reminder=剩余设备的总个数
bool Option;			// 是否采用死锁解决算法

// 定义PCB进程块的数据结构，以及对应的getter和setter方法
class PCB				// 定义PCB进程的数据结构
{
private:
	int PID;			// 进程控制块ID
	bool Finish;		// 进程完成标志；True = 完成, False 未完成
		
public:
	vector<int> Claim;			// 动态申请的进程数 (1,2,3,4)
	int Max;					// 每个进程的最大需要的设备个数 总和
	int Allocation;				// 以及分配到的设备数 (已经有的个数）
	int Need;					
	bool Flag;					// 安全性算法，记录是否finish

	PCB();
	void setPCB(int pid, int all_t, int state, bool finish);
	int getPID(); 
	bool getFinish();
	void setFinish(bool finish);
};
// PCB块的构造函数
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
// PCB中的set函数
void PCB::setPCB(int pid, int all_t = 0, int state = -1, bool finish = false)
{
	PID = pid;
	Finish = finish;
}


/* 银行家算法：
	参数： pcb队列，Option：是否选用死锁处理
*/
void bank_alroightm(vector<PCB> &pcb, vector<PCB> &wait)
{
	cout << endl << "================选项：是否需要选用“防止死锁”算法===============" << endl;
	cout << "1. 选用“防止死锁”算法" << endl;
	cout << "0. 不用“防止死锁”算法" << endl;
	cin >> Option;
	cout << "OPTION：";
	if (Option)
	{
		cout << "选用“防止死锁”算法" << endl;
	}
	else
	{
		cout << "不用“防止死锁”算法" << endl;
	}
	cout << endl << "=============== 进程块信息 ================" << endl;
	cout << endl << "===各进程块需要的资源序列 " << endl;
	// 输出所有进程块，需要分配的资源序列
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
	cout << endl << "==各进程块需要的最大资源数 " << endl;
	// 输出所有进程，最大需要的进程序列
	for (int i = 1; i <= 3; i++)
	{
		int max = pcb[i-1].Max;
		cout << "  PCB" << i << " Max:  " << left << setw(5) << max << endl;
		if (max > 10)
		{
			cout << "--------------------------------------------------------" << endl;
			cout << "ERROR1: 进程" << i << "需要资源数大于资源现有最大资源数。" << endl;
			cout << "--------------------------------------------------------" << endl;
			cout << endl;
			return;
		}
	}

	// 时间片轮转调度进程 
	int count = pcb.size();				// 初始化count= 待运行进程的个数
	cout << left << setw(10) << "PID" << setw(10) << "Allocation" << setw(10) << "Available" << endl;
	while (count)
	{
		it = pcb.begin();

		for (int m = 0; m < pcb.size();m++) {		// 初始化pcb中Need的大小
			pcb[m].Need = pcb[m].Max - pcb[m].Allocation;
		}

		if ((*it).Claim[0] > reminder)	// 1. 申请资源数 > 分配资源数，报错/进行死锁处理
		{
			cout << "--------------------------------------------------------" << endl;
			cout << "ERROR2: 申请资源数 > 可分配资源数。" << endl;
			cout << "--------------------------------------------------------" << endl;
			cout << endl;
			if (Option)
			{
				// 使用进程死锁处理，进入程序
				PCB temp = *it;
				pcb.erase(pcb.begin());
				pcb.push_back(temp);
				cout << (*pcb.begin()).Claim[0] << endl;
			}
			else {
				return;	// 没有进程死锁处理，则直接退出
			}
		}
		else
		{								// 2. 申请资源可以分配，进行安全性判断
			// 安全算法
			(*it).Flag = true;
			int work = reminder + (*it).Allocation;	// 剩余可分配资源
			vector<PCB>::iterator it1;
			for (int i = 0; i < pcb.size(); i++)				// flag初始化
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
						cout << "ERROR3：算法不安全" << endl;
						cout << "--------------------------------------------------------" << endl;
						cout << endl;
						return;
					}
				}
			}

			//分配资源
			reminder -= (*it).Claim[0];
			(*it).Allocation += (*it).Claim[0];
			(*it).Claim.erase((*it).Claim.begin());
			cout << left << setw(10) << (*it).getPID()  << setw(10) << (*it).Allocation << setw(10) << reminder << endl;
			if ((*it).Claim.size() == 0)
			{
				count -= 1;
				(*it).setFinish(true);		// 设置进程
				cout << "--------------进程" << (*it).getPID() << "运行完毕------------" << endl;
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
	cout << "=============== 所有进程均已运行完毕 ===============" << endl;
	return;
}

int main()
{
	int num = 3;
	// 1. 初始化进程控制块
	vector<PCB> pcb;		// 创建PCB的进程队列
	vector<PCB> wait;		// 创建pcb的就绪队列
	vector<int> t(3);		// 创建大小为3的整型数组,用于记录时间片数

	cout << "---- 时间片设置：创建3个进程，请为新建进程设置时间片数。例如：1 2 3 -----" << endl;
	for (int i = 1; i <= 3; i++)
	{
		cin >> t[i - 1];
		PCB p;										// 创建一个新的pcb进程控制块
		p.setPCB(i, t[i - 1], 2, false);			// 初始化进程块的信息
		pcb.push_back(p);							// 把新增pcb加入PCB队列的末端
	}
	copy(pcb.begin(), pcb.end(), back_inserter(wait));	// 将pcb队列全部加载入就绪队列

	cout << "----- 资源设置：为创建进程，添加每次需要的设备个数 -----" << endl;
	for (int i = 1; i <= 3; i++)
	{
		int sum = 0;
		cout << "--- 进程NO:" << i << endl;
		cout << "--- 时间片数:" << t[i - 1] << endl;
		for (int j = 0; j < t[i - 1]; j++)
		{
			int k;
			cin >> k;
			pcb[i-1].Claim.push_back(k);		// 输入每个时间片所需要的进程信息
			sum += k;
		}
		pcb[i-1].Max = sum;					// 输入最大需要输入的总数
		pcb[i-1].Flag = false;				// 进程未完成

	}
	//2. 输出目录
	cout << endl;
	cout << "================开启 银行家算法===============" << endl;
	bank_alroightm(pcb,wait);

}