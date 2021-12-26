#include<cstdio>
#include<ctime>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
long n;
struct pcbtype {
    long id, priority, runtime, totaltime;   //id -> PCB唯一标识   priority -> PCB优先级   runtime ->PCB运行时间
    char status;    //R,W,F->运行，就绪，完成
};
long RUN, HEAD, TAIL;  //正在运行的指针，头指针，尾指针

long ChooseAlgo(struct pcbtype *PCB, long *link) {
    char s[128];
    printf("Please type the Algorithm(Priority\\ Round Robin):");
    gets(s);
    if (s[0] == 'P' || s[0] == 'p')
        return 1;
    return 0;

}
void init(struct pcbtype *PCB, long *link) {
    long i;
    for (i = 1; i <= n; i++) {
        PCB[i].id = i;
        PCB[i].priority = rand() % 4 + 1;
        PCB[i].runtime = 0;
        PCB[i].totaltime = rand() % 8 + 1;
        PCB[i].status = 'W';

    }
}

void showit(struct pcbtype *PCB, long *link) {
    long i;
    printf("=====================================================");
    for (i = 1; i <= n; i++)printf("%4ld", PCB[i].id);
    printf("\n%-25s", "PRIORITY//TURNTIME");
    for (i = 1; i <= n; i++)printf("%4ld,", PCB[i].priority);
    printf("\n%-25s", "CPUTIME");
    for (i = 1; i <= n; i++)printf("%4ld,", PCB[i].runtime);
    printf("\n%-25s", "ALLTIME");
    for (i = 1; i <= n; i++)printf("%4ld,", PCB[i].totaltime);
    printf("\n%-25s", "STATUS");
    for (i = 1; i <= n; i++)printf("%4lc,", PCB[i].status);
    printf("\n===================================================");
    if (RUN != -1)printf("RUNNING PROCESS: %ld\n", RUN);
    else printf("RUNNING PROCESS: NULL \n");
    printf("WAITING QUEUE:");
    for (i = HEAD; i != -1; i = link[i])printf("%ld", i);
    printf("\n\n");

}

void main_priority(struct pcbtype *PCB, long *link)
{
    long i, j, k;
    long sort[n + 1];
    init(PCB,link);
    for (i = 1; i <= n; i++)
    {
        sort[i] = i;
    }
    for (i = 1; i <= n; i++)   //将n个进程比较出优先级存在sort里面，sort[i]=1代表优先级最高，优先数越大越优先
    {
        for (j = n; j > i; j--)//每一轮都比较出i位上的顺序
        {
            if (PCB[sort[j]].priority > PCB[sort[j - 1]].priority)
            {
                k = sort[j];
                sort[j] = sort[j - 1];
                sort[j - 1] = k;
            }
        }
    }
    HEAD = sort[1];
    for (i = 1; i < n; i++)
    {
        link[sort[i]] = sort[i + 1];
    }
    TAIL = sort[n];
    link[TAIL] = -1;   //对于n个进程建立一个链表
    RUN = -1;
    RUN = HEAD;
    PCB[RUN].status = 'R';
    HEAD = link[HEAD];
    while (RUN != -1)
    {
        showit(PCB,link);
        PCB[RUN].totaltime--;
        PCB[RUN].priority -= 3;
        PCB[RUN].runtime++;
        if (PCB[RUN].totaltime == 0)
        {
            PCB[RUN].status = 'F';
            RUN = HEAD;
            if (HEAD != -1)
            {
                HEAD = link[HEAD];
                PCB[RUN].status = 'R';
            }
        }
        else
        {
            if (HEAD != -1 && PCB[RUN].priority < PCB[HEAD].priority)
            {
                k = HEAD;
                PCB[RUN].status = 'W';
                while (k != TAIL && PCB[link[k]].priority > PCB[RUN].priority)
                {
                    k = link[k];
                }
                if (k = TAIL)
                {
                    link[k] = RUN;
                    TAIL = RUN;
                    link[RUN] = -1;
                    RUN = HEAD;
                    HEAD = link[HEAD];
                    PCB[RUN].status = 'R';
                }
                else
                {
                    link[RUN] = link[k];
                    link[k] = RUN;
                    RUN = HEAD;
                    HEAD = link[HEAD];
                    PCB[RUN].status = 'R';
                }
            }
        }
    }
    showit(PCB,link);
}

void main_round_robin(struct pcbtype *PCB, long *link) {
    long i;
    init(PCB,link);
    HEAD = 1;
    for (i = 1; i <= n; i++) {
        link[i] = i + 1;
    }
    TAIL = n;
    link[TAIL] = -1;
    RUN = -1;
    RUN = HEAD;
    PCB[RUN].status = 'R';
    HEAD = link[HEAD];
    while (RUN != -1) {
        showit(PCB,link);
        PCB[RUN].totaltime--;
        PCB[RUN].runtime++;
        if (PCB[RUN].totaltime == 0) {
            PCB[RUN].status = 'F';
            RUN = HEAD;
            if (HEAD != -1)
                HEAD = link[HEAD];
            PCB[RUN].status = 'R';
        }
        else {
            if (HEAD != -1 && PCB[RUN].runtime % PCB[RUN].priority == 0){
                PCB[RUN].status = 'W';
                link[TAIL] = RUN;
                link[RUN] = -1;
                TAIL = RUN;
                RUN = HEAD;
                HEAD = link[HEAD];
                PCB[RUN].status = 'R';
            }


        }
    }
    showit(PCB,link);
}

int main() {
    cout<<"请输入进程数：";

    cin>>n;
    struct pcbtype *PCB = new struct pcbtype[n+1];
    long *link = new long[n+1];
    long algo;
    srand(time(NULL));
    algo = ChooseAlgo(PCB,link);
    if (algo == 1) {
        main_priority(PCB,link);
    }
    else {
        main_round_robin(PCB,link);
    }
    printf("SYSTEM_FINISHED\n");
    return 0;
}
