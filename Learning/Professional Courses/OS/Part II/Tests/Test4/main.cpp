
#include "Assistance.h"			// 辅助软件包
#include "LinkQueue.h"
#include "FileQueue.h"

// 1. 声明变量：用户队列，指令数组
LinkQueue<string> user_link;
string command_list[] = {"CREATE", "DELETE", "OPEN", "CLOSE", "READ", "WRITE", "BYE"};

// 2. 声明函数：init()初始化函数
void init(){
    File *now_file;
    for(int i = 0; i<10; i++){
        // 1. 创建新用户,用户名 file[0-9]
        string username = "user"+to_string(i);
        user_link.EnQueue(username); 
        // 2. 创建该用户的文件队列                    
        now_file = user_link.GetFile(username, user_link);
        FileQueue *file_link;                                  
        file_link = new FileQueue(now_file);
        // 3. 给每个用户创建10个空文件，并且设定读写权限，文件名 file[0-9]
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
//3. 操作方法
void show(string username, FileQueue *file_link, FileQueue *open_file_link){
    // 显示所有文件的文件名，和打开文件的文件名
    cout<<"所有文件"<<endl;
    file_link->Traverse();
    cout<<endl;
    cout<<"已打开的文件"<<endl;
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
    // 创建文件：设置 文件名，访问权限，文件长度
    string filename;
    cout<<"THE NEW FILE’S NAME(LESS THAN 9 CHARS)?"<<endl;
    cin >> filename;
    cout<<"THE NEW FILE’S PROTECTION CODE?"<<endl;
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
    // 关闭文件：判断 文件存在且打开，则关闭文件
    string filename;
    cout<<"请输入要关闭的文件名"<<endl;
    cin >> filename;
    if(!file_link->Hav(filename,*file_link)){
        cout<<"该文件不存在"<<endl;
    }
    else if(!open_file_link->Hav(filename,*open_file_link)){
        cout<<"该文件未打开"<<endl;
    }else{

        open_file_link->DelQueue(filename);
    }
}

void deletes(FileQueue *file_link,FileQueue *open_file_link){
    // 删除文件：判断文件存在 从文件队列和打开文件目录中删除
    string filename;
    cout<<"THE DELETE FILE S NAME(LESS THAN 9 CHARS)?"<<endl;
    cin >> filename;
    if(file_link->Hav(filename,*file_link)){
        open_file_link->DelQueue(filename);
        file_link->DelQueue(filename);
    }else{
        cout<<"该文件不存在"<<endl;
    }
}

void open_file(FileQueue *file_link,FileQueue *open_file_link){
    // 打开文件：判断文件 可存在可打开且未被打开，则需要输入安全码，才能打开
    string filename;
    cout<<"请输入要打开的文件名"<<endl;
    cin >> filename;
    if(!file_link->Hav(filename,*file_link)){
        cout<<"该文件不存在"<<endl;
    }
    else if(open_file_link->Hav(filename,*open_file_link)){
        cout<<"该文件已打开"<<endl;
    }else if(!file_link->verification(filename,2)){
        cout<<"该文件不允许打开"<<endl;
    }else if(open_file_link->GetLength() >=5 ){
        cout << "打开文件已超过5个。请关闭文件后，再尝试打开" << endl;
    }
    else{
        cout<<"请输入安全码"<<endl;
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
            cout<<"安全码不正确"<<endl;
        }

    }
}

void read(FileQueue *file_link,FileQueue *open_file_link){
    // 读取文件：读入存在且未打开的文件
    string filename;
    cout<<"请输入要读的文件名"<<endl;
    cin >> filename;
    if(!open_file_link->Hav(filename,*open_file_link)){
        cout<<"该文件未打开"<<endl;
    }else if(open_file_link->GetLength() >=5 ){
        cout << "打开文件已超过5个。请关闭文件后，再尝试打开" << endl;
    }else if(file_link->verification(filename,1)){
        cout<<"你成功读了"<<filename<<"文件"<<endl;
    }else{
        cout<<"该文件不允许读"<<endl;
    }
}
void write(FileQueue *file_link,FileQueue *open_file_link){
    // 写入文件：写入存在且未打开的文件
    string filename;
    cout<<"请输入要写的文件名"<<endl;
    cin >> filename;
    if(!open_file_link->Hav(filename,*open_file_link)){
        cout<<"该文件未打开"<<endl;
    }else if(open_file_link->GetLength() >=5 ){
        cout << "打开文件已超过5个。请关闭文件后，再尝试打开" << endl;
    }else if(file_link->verification(filename,0)){
        cout<<"你要写多少字节"<<endl;
        int lens;
        cin >>lens;
        file_link->AddLen(filename,lens);
    }else{
        cout<<"该文件不允许写"<<endl;
    }
}

int main() {
    // 1. 初始化。生成10个用户，以及每个用户10文件
    init();
    // 2. 输入用户名，判断是否在用户列表
    string username;
    cout<<"YOUR NAME ?"<<endl;
    cin>>username;
    while(!user_link.Hav(username,user_link)){
        cout<<"YOUR NAME IS NOT N THE USER NAME TABLE,TRY AGAIN."<<endl;
        cin>>username;
    }
    // 3. 显示目录
    cout<<"YOUR FILE DIRECTORY"<<endl;
    File *file_head;
    file_head = user_link.GetFile(username,user_link);  
    FileQueue file_link(file_head);     // 创建一个主文件目录MFD，存放所有的文件
    FileQueue open_file_link;           // 创建一个打开文件目录AFD，存放所有打开的文件

    // 4. 进行文件操作
    bool end = false;
    while(!end){
        show(username,&file_link,&open_file_link);
        char command;
        cout << endl << "1. 创建文件.";
        cout << endl << "2. 删除文件.";
        cout << endl << "3. 打开文件.";
        cout << endl << "4. 关闭文件.";
        cout << endl << "5. 读出文件.";
        cout << endl << "6. 写入文件.";
        cout << endl << "0. 退出";
        cout << endl << "选择功能(0~6):";

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
                cout<<"请输入0-6的数"<<endl;

        }
    }
}
