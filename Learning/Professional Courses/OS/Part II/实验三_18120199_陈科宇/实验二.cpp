#include<iostream>
#include<cstring>
using namespace std;


int n,m;
int *Res = new int[m];   //��Դ����
struct Process{
    int Had[15];
    int Max[15];
    int Need[15];
    bool IsEnd;


};
struct Process *Processes = new Process[n];
int curProcess;  //ѡ����̷�����Դ
int *Req= new int[m];      //ѡ����̾�����Ҫ������Դ
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
    for(int i = 0;i<m;i++){  //������Դ�����ڸý���������Դ��
        if(Req[i] > Processes[curProcess].Need[i]){
            Legal = false;
            cout<<"������Դ�����ڸý���������Դ��"<<endl;
           return false;
        }
    }
    for(int i = 0;i < m; i++){   //������Դ������ʣ����Դ��
        if(Req[i] > Res[i]){
            Legal = false;
            cout<<"������Դ������ʣ����Դ��"<<endl;
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

    cout<<"�����������:";
    cin >> n ;
    cout<<"��������Դ��:";
    cin>> m;  //m�������ϵͳ��Դ����
    cout<<"������"<<m<<"����Դÿһ����Դ������:"<<endl;
    for(int i = 0;i < m; i++){
        cout<<"��"<<i+1<<"��:";
        cin >> Res[i];

    }

    for(int i = 0; i < n; i++){
        cout<<"�������"<<i+1<<"�����̵ľ�����Դ��"<<endl;

        for(int j = 0; j < m; j++){
            cout<<"�������"<<j+1<<"����Դ����ӵ�к����ӵ��:";
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
            cout<<"��"<<i+1<<"������"<<" �Ƿ��ѽ�����"<<boolalpha<<Processes[i].IsEnd<<endl;
            for(int j = 0; j<m; j++){
                cout<<"�����Դ����"<<Processes[i].Max[j]<<" ������Դ����"<<Processes[i].Had[j]<<" ��Ҫ��Դ����"<<Processes[i].Need[j]<<endl;
            }
        }
        for(int i = 0; i<m; i++){

            cout<<"��"<<i+1<<"��ʣ����Ŀ��"<<Res[i]<<" ";
        }

        cout<<endl<<"�����뵱ǰѡ��Ľ��̱��:";
        cin >> curProcess;
        curProcess--;
        cout<<"������ÿһ����Դ��������Ŀ��"<<endl;
        for(int i = 0; i < m; i++){
            cout<<"��"<<i+1<<"�֣�";
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
            cout<<"ϵͳ���ڲ���ȫ״̬"<<endl;
        }

    }while(!IsEnd());


    cout<<"���н����ѽ���"<<endl;
    return 0;
}
