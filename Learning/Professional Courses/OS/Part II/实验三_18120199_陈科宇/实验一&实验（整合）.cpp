#include<cstdio>
#include<ctime>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
long n,m;
struct pcbtype {
    long id, priority, runtime, totaltime;   //id -> PCBΨһ��ʶ   priority -> PCB���ȼ�   runtime ->PCB����ʱ��
    char status;    //R,W,F->���У����������
};
long RUN, HEAD, TAIL;  //�������е�ָ�룬ͷָ�룬βָ��

int *Res = new int[m+1];   //��Դ����
int *Req = new int[m+1];
int **Had = new int*[n+1];
int **Max = new int*[n+1];
int **Need = new int*[n+1];


long ChooseAlgo(struct pcbtype *PCB, long *link) {
    char s;
    printf("Please type the Algorithm(Priority\\ Round Robin):");
    cin>>s;
    if (s == 'P' || s == 'p')
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

void showit(struct pcbtype *PCB, long *link){
    cout<<"====================================================="<<endl;
    cout<<"id"<<" "<<"���ȼ�"<<" "<<"ʣ��ʱ��"<<" "<<"����ʱ��"<<" "<<
        "״̬"<<" ";
    for(int j = 1; j<=m; j++){
        cout<<"��"<<j<<"�����"<<" "<<"��"<<j<<"����ӵ��"<<" ";
    }
    int cur;
    cout<<endl;
    for(int i = 1; i<=n; i++){
        cout<<PCB[i].id<<"    "<<PCB[i].priority<<"      "<<PCB[i].totaltime<<"       "<<
            PCB[i].runtime<<"      "<<PCB[i].status<<"     ";
        if(PCB[i].status=='R')cur = i;
        for(int j = 1; j<=m; j++){
            cout<<Max[i][j]<<"         "<<Had[i][j]<<"          ";
        }
        cout<<endl;
    }
    cout<<"��ʣ��Դ��"<<endl;
    for(int j = 1; j<=m; j++){
        cout<<"��"<<j<<"��"<<" ";
    }
    cout<<endl;
    for(int j = 1; j<=m; j++){
        cout<<Res[j]<<"     ";
    }
    cout<<endl<<"��"<<cur<<"����������Դ"<<endl;
    for(int j = 1; j<=m; j++){
        cout<<"��"<<j<<"��"<<" ";
    }
    cout<<endl;
    for(int j = 1; j<=m; j++){
        cout<<Req[j]<<"     ";
    }
    cout<<endl;
}

bool IstmpEnd(bool * isEnd){
    bool R = true;
    for(int i = 1;i <= n; i++){
        if(!isEnd[i]){
            R = false;
            break;
        }
    }
    return R;
}

bool require(int id){

    bool Legal = true;
    for(int j = 1;j<=m;j++){  //������Դ�����ڸý���������Դ��
        if(Req[j] > Need[id][j]){
            Legal = false;
            cout<<"������Դ�����ڸý���������Դ��"<<endl;
            return false;
        }
    }
    for(int j = 1;j<=m;j++){   //������Դ������ʣ����Դ��
        if(Req[j] > Res[j]){
            Legal = false;
            cout<<"������Դ������ʣ����Դ��"<<endl;
            return false;
        }
    }
    int *tmp=new int[m+1];
    bool *isEnd = new bool[n+1];
    int **Had2 = new int*[n+1];
    int **Max2 = new int*[n+1];
    int **Need2 = new int*[n+1];

    memset(Had2,0,sizeof(Had2));
    memset(Max2,0,sizeof(Max2));
    memset(Need2,0,sizeof(Need2));
    for(int i = 1; i<=n; i++){

        Had2[i]=new int[m+1];
        Max2[i]=new int[m+1];
        Need2[i] = new int[m+1];
    }
    for(int i = 1; i<=n; i++){

        memset(Had2[i],0,sizeof(Had2[i]));
        memset(Max2[i],0,sizeof(Max2[i]));
        memset(Need2[i],0,sizeof(Need2[i]));
    }
    for(int i = 1;i<=n; i++){
        for(int j = 1; j<=m;j++){

            Max2[i][j] =0;
            Need2[i][j] = Had2[i][j] = 0;
        }
    }

    for(int i = 1;i <= m; i++){
        tmp[i] = Res[i];
    }
    for(int i = 1;i<=n;i++){
        bool end = true;
        for(int j = 1;j<=m;j++){
            Max2[i][j] =Max[i][j];
            Need2[i][j] = Need[i][j];
            Had2[i][j] = Had[i][j];
            if(Need[i][j]!=0)end = false;
        }
        isEnd[i] = end;
    }
    for(int j =1;j<=m;j++){
        Had2[id][j]+=Req[j];
        Need2[id][j]-=Req[j];
        tmp[j]-=Req[j];
    }
    bool IsFind=false;
    do{
        IsFind = false;
        int curRel = -1;
        for(int i = 1;i<=n;i++){
            if(!isEnd[i]){
                bool IsFF = true;
                for(int j= 1;j<=m;j++){  //����i����������Դ�Ƿ�����Ҫ��
                    if(Need2[i][j] > tmp[j]){
                        IsFF = false;
                        break;
                    }
                }
                IsFind = IsFF;
                if(IsFind){
                    curRel = i;
                    break;
                }
            }
        }
        if(IsFind){
            isEnd[curRel]=true;
            for(int j = 1;j<=m;j++){
                tmp[j]+=Had2[curRel][j];

                Had2[curRel][j] = 0;
                Need2[curRel][j] = 0;
            }
        }
    }while(!IstmpEnd(isEnd) && IsFind);
    for(int i = 1;i<=n;i++){
        if(!isEnd[i]){
            Legal = false;
            break;
        }
    }
    if(!Legal){
        cout<<"���������м��㷨"<<endl;
    }
    return Legal;
}

void initReq(int id){
    bool legal = true;
    for(int j = 1; j<=m; j++){
        if(Need[id][j]!=0){
            legal = false;
            break;
        }
    }
    for(int j = 1; j<=m; j++){
        Req[j] = legal?0:rand()%4;
    }
}
void returnRes(int id){
    for(int j = 1; j<=m; j++){
        Res[j]+=Had[id][j];
        Need[id][j]=0;
        Had[id][j]=0;
    }
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
    for (i = 1; i <= n; i++)   //��n�����̱Ƚϳ����ȼ�����sort���棬sort[i]=1�������ȼ���ߣ�������Խ��Խ����
    {
        for (j = n; j > i; j--)//ÿһ�ֶ��Ƚϳ�iλ�ϵ�˳��
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
    link[TAIL] = -1;   //����n�����̽���һ������
    RUN = -1;
    RUN = HEAD;
    PCB[RUN].status = 'R';
    HEAD = link[HEAD];
    while (RUN != -1)
    {

        initReq(PCB[RUN].id);
        showit(PCB,link);
        PCB[RUN].priority -= 3;
        bool Legal = require(PCB[RUN].id);
        if(Legal){
            PCB[RUN].totaltime--;
            PCB[RUN].runtime++;
            for(int j = 1; j<=m; j++){
                Res[j]-=Req[j];
                Need[PCB[RUN].id][j]-=Req[j];
                Had[PCB[RUN].id][j] +=Req[j];
            }
        }

        if (PCB[RUN].totaltime == 0)
        {
            PCB[RUN].status = 'F';
            returnRes(PCB[RUN].id);
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
        initReq(PCB[RUN].id);
        showit(PCB,link);

        bool Legal = require(PCB[RUN].id);
        if(Legal){
            PCB[RUN].totaltime--;
            PCB[RUN].runtime++;
            for(int j = 1; j<=m; j++){
                Res[j]-=Req[j];
                Need[PCB[RUN].id][j]-=Req[j];
                Had[PCB[RUN].id][j] +=Req[j];
            }
        }

        if (PCB[RUN].totaltime == 0) {
            PCB[RUN].status = 'F';
            returnRes(PCB[RUN].id);
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

void initProject(){
    memset(Res,0,sizeof(Res));
    memset(Req,0,sizeof(Req));
    memset(Had,0,sizeof(Had));
    memset(Max,0,sizeof(Max));
    memset(Need,0,sizeof(Need));
    for(int i = 1; i<=n; i++){
        Had[i]=new int[m+1];
        Max[i]=new int[m+1];
        Need[i] = new int[m+1];
    }
    for(int i = 1; i<=n; i++){
        memset(Had[i],0,sizeof(Had[i]));
        memset(Max[i],0,sizeof(Max[i]));

        memset(Need[i],0,sizeof(Need[i]));
    }
    for(int j = 1;j<=m; j++){
        Res[j] = rand()%2+3;
        Req[j]=0;
    }
    for(int i = 1;i<=n; i++){
        for(int j = 1; j<=m;j++){
            Max[i][j] = rand()%2+1;
            Need[i][j]=Max[i][j];
            Had[i][j]=0;
        }
    }
}

int main() {

    cout<<"�������������";
    cin>>n;
    cout<<"��������Դ����";
    cin>>m;
    initProject();
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
