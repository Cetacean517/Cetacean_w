// 进程调度算法 多个
#include <iostream>
#include <vector>		// 引入vector容器
#include <algorithm>	// sort()函数的头文件
#include <iomanip>		// 使用setw()

using namespace std;

class PCB				// 定义PCB进程的数据结构
{
private:
	int PID;			// 进程控制块ID
	int Priority;		// 优先权数
	int CPUtime;		// CPU已经运行的时间
	int ALLtime;		// 剩余需要运行的时间
	int State;			// 进程当前的状态；1 运行 2 就绪 3 等待 -1 未初始化
	bool Finish;		// 进程完成标志；True = 完成, False 未完成
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
// PCB块的构造函数
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
// PCB中的set函数
void PCB::setPCB(int pid, int priority, int all_t = 0, int state = -1, bool finish = false)
{
	PID = pid;
	Priority = priority;
	ALLtime = all_t;
	State = state;
	Finish = finish;
}

// sort函数重载，自定义按优先数排序。优先数相同时，按序号排序（先进先出）
bool priority_sort(PCB& p, PCB& q)
{
	if (p.getPriority() == q.getPriority()) return p.getPID() < q.getPID();
	return p.getPriority() > q.getPriority();
}

// 优先级调度算法
void priority_choose(vector<PCB>& pcb, vector<PCB>& wait) {
	/*参数：pcb:进程队列，wait:就绪队列, num:进程的个数*/
	vector<PCB>::iterator it;
	it = pcb.begin();
	int count = pcb.size();		// count = 剩余要运行的进程个数
	while (count)
	{
		wait.erase(wait.begin());	//调入就绪队列中第一个进程

		// 更新pcb的数据
		(*it).setState(1);
		(*it).setPriority((*it).getPriority() - 1);
		if ((*it).getPriority() < 0)	// 当优先级减到0的时候，不再继续减
		{
			(*it).setPriority(0);
		}
		(*it).setCPUtime((*it).getCPUtime() + 1);
		(*it).setALLtime((*it).getALLtime() - 1);

		// 当有进程运行完成，输出结果，并且从两个队列中移除
		if ((*it).getALLtime() == 0)
		{
			count -= 1;				// 剩余进程数-1
			(*it).setFinish(true);
			cout << "--------------进程" << (*it).getPID() << "运行完毕------------" << endl;
			cout << left << setw(10) << (*it).getPID() << setw(10) << (*it).getState() << setw(10) << (*it).getPriority() << setw(10) << (*it).getCPUtime() << setw(10) << (*it).getALLtime() << setw(10) << (*it).getFinish() << endl;
			pcb.erase(pcb.begin());
			sort(wait.begin(), wait.end(), priority_sort);
			sort(pcb.begin(), pcb.end(), priority_sort);
			it = pcb.begin();
		}
		else
		{
			// 当进程没有运行完，输出结果，继续运行
			cout << left << setw(10) << (*it).getPID() << setw(10) << (*it).getState() << setw(10) << (*it).getPriority() << setw(10) << (*it).getCPUtime() << setw(10) << (*it).getALLtime() << setw(10) << (*it).getFinish() << endl;
			(*it).setState(2);		// 进程处于等待状态
			wait.push_back(*it);	// 未运行完的pcb重新插入就绪队列的末尾
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
			cout << "--------------进程" << (*it).getPID() << "运行完毕------------" << endl;
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
	int num = -1; // num:需要被调度的进程个数
	char choice = NULL;
	cout << "===============调度算法目录===============" << endl;
	cout << "A. 优先数调度算法" << endl;
	cout << "B. 时间片轮转调度算法" << endl;
	cout << "请选择想模拟的调度算法:" << endl;
	
	// 输入0 退出
	while (cin >> choice)
	{
		switch (choice)
		{
		case 'A':
		{
									// 增加作用域，可以解决在switch中创建class对象
			// 1. 初始化进程
			vector<PCB> pcb;		// 创建PCB的进程队列

			cout << "===============优先数调度算法===============" << endl;
			cout << "请输入进程的总个数：" << endl;
			cin >> num;

			vector<PCB> wait;	// 创建pcb的就绪队列
			vector<int> a(num);		// 创建大小为num的整型数组,用于记录优先级
			vector<int> b(num);		// 创建大小为num的整型数组,用于记录时间片数
			cout << "创建" << num << "个进程，请为新建进程设置优先数(优先数越大，优先级越高)" << endl;
			cout << "例如：1 2 3 4 5 ，即将5个进程的优先数分别设置为1 2 3 4 5" << endl;
			
			for (int i = 0; i < num; i++)
			{
				cin >> a[i];
			}
			cout << "请为新建进程设置各个需要运行的时间片数" << endl;
			for (int i = 1; i <= num; i++)
			{
				cin >> b[i-1];
				PCB p1;										// 创建一个新的pcb进程控制块
				p1.setPCB(i, a[i - 1], b[i-1], 2,false);	// 初始化进程块的信息
				pcb.push_back(p1);							// 把新增pcb加入PCB队列的末端
			}

			// 利用重载sort函数，对pcb队列进行基于优先数的排序
			// void sort (RandomAccessIterator first, RandomAccessIterator last, Compare comp);
			// 开始，结尾，和排序的顺序
			sort(pcb.begin(),pcb.end(),priority_sort);
			copy(pcb.begin(), pcb.end(), back_inserter(wait));	// 将排序后的pcb队列全部加载入就绪队列

			//2. 输出目录
			cout << endl;
			cout << "=============== 开始运行 ===============" << endl;
			cout << "该进程运行情况如下（Finish=0代表未完成，Finish=1代表已完成）" << endl;
			cout << left << setw(10) << "ID" << setw(10) << "State" << setw(10) << "Priority" << setw(10) << "CPUtime" << setw(10) << "ALLtime " << setw(10) << "Finish" << endl;
			priority_choose(pcb, wait);
			cout << "=============== 所有进程均已运行完毕 ===============" << endl;
			break;
		}
		case 'B':
		{
			// 1. 初始化进程
			vector<PCB> pcb;		// 创建PCB的进程队列

			cout << "===============时间片轮转调度算法===============" << endl;
			cout << "请输入进程的总个数：" << endl;
			cin >> num;

			vector<PCB> wait;	// 创建pcb的就绪队列
			vector<int> t(num);		// 创建大小为num的整型数组,用于记录时间片数
			cout << "创建" << num << "个进程，请为新建进程设置时间片数。例如：1 2 3 2 3" << endl;
			for (int i = 1; i <= num; i++)
			{
				cin >> t[i - 1];
				PCB p2;										// 创建一个新的pcb进程控制块
				p2.setPCB(i, -1, t[i - 1], 2, false);		// 初始化进程块的信息
				pcb.push_back(p2);							// 把新增pcb加入PCB队列的末端
			}			
			copy(pcb.begin(), pcb.end(), back_inserter(wait));	// 将pcb队列全部加载入就绪队列

			//2. 输出目录
			cout << endl;
			cout << "=============== 开始运行 ===============" << endl;
			cout << "该进程运行情况如下（Finish=0代表未完成，Finish=1代表已完成）" << endl;
			cout << left << setw(10) << "ID" << setw(10) << "State" << setw(10) << "Priority" << setw(10) << "CPUtime" << setw(10) << "ALLtime " << setw(10) << "Finish" << endl;
			rr_choose(pcb,wait);
			cout << "=============== 所有进程均已运行完毕 ===============" << endl;
			break;
		}
		default:
			break;
		}
	}
	return 0;
}

