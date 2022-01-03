#include<iostream>
#include<cstring>
using namespace std;


int n,m;
int *Res = new int[m];   //资源总数
struct Process{
    int Had[15];
    int Max[15];
    int Need[15];
    bool IsEnd;


};
struct Process *Processes = new Process[n];
int curProcess;  //选择进程分配资源
int *Req= new int[m];      //选择进程具体需要多少资源
struct Process *tmpProcesses=new Process[n];

bool IsEnd(){
    bool R = true;
    for(int i = 0;i < n; i++){
        if(!Processes[i].IsEnd){
            R = false;
            break;
        }
    }
    return R;
}
bool IstmpEnd(){
    bool R = true;
    for(int i = 0;i < n; i++){
        if(!tmpProcesses[i].IsEnd){
            R = false;
            break;
        }
    }
    return R;
}
bool Legal= false;
bool Banker(){
    Legal = true;
    for(int i = 0;i<m;i++){  //请求资源数大于该进程所需资源数
        if(Req[i] > Processes[curProcess].Need[i]){
            Legal = false;
            cout<<"请求资源数大于该进程所需资源数"<<endl;
           return false;
        }
    }
    for(int i = 0;i < m; i++){   //请求资源数大于剩余资源数
        if(Req[i] > Res[i]){
            Legal = false;
            cout<<"请求资源数大于剩余资源数"<<endl;
            return false;
        }
    }
    int *tmp=new int[m];
    for(int i = 0;i < m; i++){
        tmp[i] = Res[i];
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            tmpProcesses[i].Max[j] = Processes[i].Max[j];
            tmpProcesses[i].Need[j] = Processes[i].Need[j];
            tmpProcesses[i].Had[j] = Processes[i].Had[j];
            tmpProcesses[i].IsEnd = Processes[i].IsEnd;
        }
    }
    for(int i =0;i<m;i++){
        tmpProcesses[curProcess].Had[i]+=Req[i];
        tmpProcesses[curProcess].Need[i]-=Req[i];
        tmp[i]-=Req[i];
    }
    bool IsFind=false;
    do{
        IsFind = false;
        int curRel = -1;
        for(int i = 0;i<n;i++){
            if(!tmpProcesses[i].IsEnd){
                bool IsFF = true;
                for(int j= 0;j<m;j++){
                    if(tmpProcesses[i].Need[j] > tmp[j]){
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
            for(int i = 0;i<m;i++){
                tmp[i]+=tmpProcesses[curRel].Had[i];
                tmpProcesses[curRel].IsEnd = true;
                tmpProcesses[curRel].Had[i] = 0;
                tmpProcesses[curRel].Need[i] = 0;
            }
        }
    }while(!IstmpEnd() && IsFind);
    for(int i = 0;i<m;i++){
        if(!tmpProcesses[i].IsEnd){
            Legal = false;
            break;
        }
    }
    return Legal;
}

int main(){
    memset(Processes,0,sizeof(Processes));
    memset(Res,0,sizeof(Res));
    memset(Req,0,sizeof(Req));
    bool test = false;

    cout<<"请输入进程数:";
    cin >> n ;
    cout<<"请输入资源数:";
    cin>> m;  //m代表操作系统资源数码
    cout<<"请输入"<<m<<"种资源每一种资源的数量:"<<endl;
    for(int i = 0;i < m; i++){
        cout<<"第"<<i+1<<"种:";
        cin >> Res[i];

    }

    for(int i = 0; i < n; i++){
        cout<<"请输入第"<<i+1<<"个进程的具体资源数"<<endl;

        for(int j = 0; j < m; j++){
            cout<<"请输入第"<<j+1<<"种资源的已拥有和最大拥有:";
            cin >> Processes[i].Had[j] >> Processes[i].Max[j];


        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            Processes[i].Need[j] = Processes[i].Max[j] - Processes[i].Had[j];
            Res[j]-=Processes[i].Had[j];
            Processes[i].IsEnd=false;
        }
    }
    do{

        for(int i = 0; i< n; i++){
            cout<<"第"<<i+1<<"个进程"<<" 是否已结束："<<boolalpha<<Processes[i].IsEnd<<endl;
            for(int j = 0; j<m; j++){
                cout<<"最大资源数："<<Processes[i].Max[j]<<" 已有资源数："<<Processes[i].Had[j]<<" 需要资源数："<<Processes[i].Need[j]<<endl;
            }
        }
        for(int i = 0; i<m; i++){

            cout<<"第"<<i+1<<"种剩余数目："<<Res[i]<<" ";
        }

        cout<<endl<<"请输入当前选择的进程编号:";
        cin >> curProcess;
        curProcess--;
        cout<<"请输入每一种资源的请求数目："<<endl;
        for(int i = 0; i < m; i++){
            cout<<"第"<<i+1<<"种：";
            cin >> Req[i];
        }

        Legal = false;
        Banker();
        if(Legal){

            Processes[curProcess].IsEnd = true;
            for(int i = 0; i < m; i++){
                Processes[curProcess].Had[i]+=Req[i];
                Processes[curProcess].Need[i]-=Req[i];
                Res[i]-=Req[i];
                if(Processes[curProcess].Had[i] < Processes[curProcess].Max[i]){
                    Processes[curProcess].IsEnd = false;


                }else{
                    Res[i]+=Processes[curProcess].Had[i];
                }
            }
        }else{
            cout<<"系统处于不安全状态"<<endl;
        }

    }while(!IsEnd());


    cout<<"所有进程已结束"<<endl;
    return 0;
}
