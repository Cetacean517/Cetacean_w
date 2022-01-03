
#include "Assistance.h"			// ���������
#include "LinkQueue.h"
#include "FileQueue.h"

// 1. �����������û����У�ָ������
LinkQueue<string> user_link;
string command_list[] = {"CREATE", "DELETE", "OPEN", "CLOSE", "READ", "WRITE", "BYE"};

// 2. ����������init()��ʼ������
void init(){
    File *now_file;
    for(int i = 0; i<10; i++){
        // 1. �������û�,�û��� file[0-9]
        string username = "user"+to_string(i);
        user_link.EnQueue(username); 
        // 2. �������û����ļ�����                    
        now_file = user_link.GetFile(username, user_link);
        FileQueue *file_link;                                  
        file_link = new FileQueue(now_file);
        // 3. ��ÿ���û�����10�����ļ��������趨��дȨ�ޣ��ļ��� file[0-9]
        for(int j = 0; j<10; j++){
            bool sec[3];
            if(j%3==1){
                sec[0]=false;
            }else sec[0]=true;

            if(j%3==2){
                sec[1]=false;
            }else sec[1]=true;

            if(j%3==0){
                sec[2]=false;
            }else sec[2]=true;

            string filename = "file"+to_string(j);
            int len = 0;

            file_link->EnQueue(filename,sec,len);
        }
    }
}
//3. ��������
void show(string username, FileQueue *file_link, FileQueue *open_file_link){
    // ��ʾ�����ļ����ļ������ʹ��ļ����ļ���
    cout<<"�����ļ�"<<endl;
    file_link->Traverse();
    cout<<endl;
    cout<<"�Ѵ򿪵��ļ�"<<endl;
    open_file_link->Traverse2();
}

bool legal(string command){
    bool legal = false;
    for(int i = 0; i<7;i++){
        if(command_list[i]==command){
            legal = true;
            break;
        }
    }
}

void create(FileQueue *file_link){
    // �����ļ������� �ļ���������Ȩ�ޣ��ļ�����
    string filename;
    cout<<"THE NEW FILE��S NAME(LESS THAN 9 CHARS)?"<<endl;
    cin >> filename;
    cout<<"THE NEW FILE��S PROTECTION CODE?"<<endl;
    bool sec[3];
    int temp;
    for(int i = 0; i<3; i++){
        cin >>temp;
        if(temp==1){
            sec[i]=true;
        }else sec[i]=false;
    }
    int len = 0;
    file_link->EnQueue(filename,sec,len);
}

void close_file(FileQueue *file_link,FileQueue *open_file_link){
    // �ر��ļ����ж� �ļ������Ҵ򿪣���ر��ļ�
    string filename;
    cout<<"������Ҫ�رյ��ļ���"<<endl;
    cin >> filename;
    if(!file_link->Hav(filename,*file_link)){
        cout<<"���ļ�������"<<endl;
    }
    else if(!open_file_link->Hav(filename,*open_file_link)){
        cout<<"���ļ�δ��"<<endl;
    }else{

        open_file_link->DelQueue(filename);
    }
}

void deletes(FileQueue *file_link,FileQueue *open_file_link){
    // ɾ���ļ����ж��ļ����� ���ļ����кʹ��ļ�Ŀ¼��ɾ��
    string filename;
    cout<<"THE DELETE FILE S NAME(LESS THAN 9 CHARS)?"<<endl;
    cin >> filename;
    if(file_link->Hav(filename,*file_link)){
        open_file_link->DelQueue(filename);
        file_link->DelQueue(filename);
    }else{
        cout<<"���ļ�������"<<endl;
    }
}

void open_file(FileQueue *file_link,FileQueue *open_file_link){
    // ���ļ����ж��ļ� �ɴ��ڿɴ���δ���򿪣�����Ҫ���밲ȫ�룬���ܴ�
    string filename;
    cout<<"������Ҫ�򿪵��ļ���"<<endl;
    cin >> filename;
    if(!file_link->Hav(filename,*file_link)){
        cout<<"���ļ�������"<<endl;
    }
    else if(open_file_link->Hav(filename,*open_file_link)){
        cout<<"���ļ��Ѵ�"<<endl;
    }else if(!file_link->verification(filename,2)){
        cout<<"���ļ��������"<<endl;
    }else if(open_file_link->GetLength() >=5 ){
        cout << "���ļ��ѳ���5������ر��ļ����ٳ��Դ�" << endl;
    }
    else{
        cout<<"�����밲ȫ��"<<endl;
        bool sec[3];
        int temp;
        for(int i = 0; i<3; i++){
            cin >>temp;
            if(temp==1){
                sec[i]=true;
            }else sec[i]=false;
        }

        if(file_link->verification(filename,sec)){
            int length = 0;
            open_file_link->EnQueue(filename,sec,length);
        }else{
            cout<<"��ȫ�벻��ȷ"<<endl;
        }

    }
}

void read(FileQueue *file_link,FileQueue *open_file_link){
    // ��ȡ�ļ������������δ�򿪵��ļ�
    string filename;
    cout<<"������Ҫ�����ļ���"<<endl;
    cin >> filename;
    if(!open_file_link->Hav(filename,*open_file_link)){
        cout<<"���ļ�δ��"<<endl;
    }else if(open_file_link->GetLength() >=5 ){
        cout << "���ļ��ѳ���5������ر��ļ����ٳ��Դ�" << endl;
    }else if(file_link->verification(filename,1)){
        cout<<"��ɹ�����"<<filename<<"�ļ�"<<endl;
    }else{
        cout<<"���ļ��������"<<endl;
    }
}
void write(FileQueue *file_link,FileQueue *open_file_link){
    // д���ļ���д�������δ�򿪵��ļ�
    string filename;
    cout<<"������Ҫд���ļ���"<<endl;
    cin >> filename;
    if(!open_file_link->Hav(filename,*open_file_link)){
        cout<<"���ļ�δ��"<<endl;
    }else if(open_file_link->GetLength() >=5 ){
        cout << "���ļ��ѳ���5������ر��ļ����ٳ��Դ�" << endl;
    }else if(file_link->verification(filename,0)){
        cout<<"��Ҫд�����ֽ�"<<endl;
        int lens;
        cin >>lens;
        file_link->AddLen(filename,lens);
    }else{
        cout<<"���ļ�������д"<<endl;
    }
}

int main() {
    // 1. ��ʼ��������10���û����Լ�ÿ���û�10�ļ�
    init();
    // 2. �����û������ж��Ƿ����û��б�
    string username;
    cout<<"YOUR NAME ?"<<endl;
    cin>>username;
    while(!user_link.Hav(username,user_link)){
        cout<<"YOUR NAME IS NOT N THE USER NAME TABLE,TRY AGAIN."<<endl;
        cin>>username;
    }
    // 3. ��ʾĿ¼
    cout<<"YOUR FILE DIRECTORY"<<endl;
    File *file_head;
    file_head = user_link.GetFile(username,user_link);  
    FileQueue file_link(file_head);     // ����һ�����ļ�Ŀ¼MFD��������е��ļ�
    FileQueue open_file_link;           // ����һ�����ļ�Ŀ¼AFD��������д򿪵��ļ�

    // 4. �����ļ�����
    bool end = false;
    while(!end){
        show(username,&file_link,&open_file_link);
        char command;
        cout << endl << "1. �����ļ�.";
        cout << endl << "2. ɾ���ļ�.";
        cout << endl << "3. ���ļ�.";
        cout << endl << "4. �ر��ļ�.";
        cout << endl << "5. �����ļ�.";
        cout << endl << "6. д���ļ�.";
        cout << endl << "0. �˳�";
        cout << endl << "ѡ����(0~6):";

        cin>>command;

        switch (command){
            case '1':
                create(&file_link);
                break;
            case '2':
                deletes(&file_link,&open_file_link);
                break;
            case '3':
                open_file(&file_link,&open_file_link);
                break;
            case '4':
                close_file(&file_link,&open_file_link);
                break;
            case '5':
                read(&file_link,&open_file_link);
                break;
            case '6':
                write(&file_link,&open_file_link);
                break;
            case '0':
                end = true;
                break;
            default:
                cout<<"������0-6����"<<endl;

        }
    }
}
