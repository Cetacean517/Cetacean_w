
#include "Assistance.h"			// ���������
#include "LinkQueue.h"
#include "FileQueue.h"


LinkQueue<string> user_link;
string command_list[] = {"CREATE", "DELETE", "OPEN", "CLOSE", "READ", "WRITE", "BYE"};

void init(){
    File *now_file;
    for(int i = 0; i<10; i++){
        string username = "user"+to_string(i);

        user_link.EnQueue(username);
        now_file = user_link.GetFile(username, user_link);
        FileQueue *file_link;
        file_link = new FileQueue(now_file);
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
void init2(string username, FileQueue *file_link, FileQueue *open_file_link){

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
    string filename;
    cout<<"THE NEW FILE S NAME(LESS THAN 9 CHARS)?"<<endl;
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
    }else{
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
    string filename;
    cout<<"������Ҫ�����ļ���"<<endl;
    cin >> filename;
    if(!open_file_link->Hav(filename,*open_file_link)){
        cout<<"���ļ�δ��"<<endl;
    }else if(file_link->verification(filename,1)){
        cout<<"��ɹ�����"<<filename<<"�ļ�"<<endl;
    }else{
        cout<<"���ļ��������"<<endl;
    }
}
void write(FileQueue *file_link,FileQueue *open_file_link){
    string filename;
    cout<<"������Ҫд���ļ���"<<endl;
    cin >> filename;
    if(!open_file_link->Hav(filename,*open_file_link)){
        cout<<"���ļ�δ��"<<endl;
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
    init();
    string username;
    cout<<"YOUR NAME ?"<<endl;
    cin>>username;
    while(!user_link.Hav(username,user_link)){
        cout<<"YOUR NAME IS NOT N THE USER NAME TABLE,TRY AGAIN."<<endl;
        cin>>username;
    }
    cout<<"YOUR FILE DIRECTORY"<<endl;
    File *file_head;
    file_head = user_link.GetFile(username,user_link);
    FileQueue file_link(file_head);
    FileQueue open_file_link;

    bool end = false;
    while(!end){
        init2(username,&file_link,&open_file_link);
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
