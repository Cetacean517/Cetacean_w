#ifndef PROJECT4_FILEQUEUE_H
#define PROJECT4_FILEQUEUE_H

#include "Assistance.h"			// 辅助软件包
#include "Node.h"				// 结点类

// 链队列类
class FileQueue
{
protected:
//  链队列实现的数据成员:
    File *front, *rear;					// 队头队尾指指
public:
    FileQueue();									    // 无参数的构造函数
    FileQueue(File *file);
    virtual ~FileQueue();							    // 析构函数
    bool *GetSec(string filename,const FileQueue &q);   // 获取文件的三位保护码
    int RenLen(string filename,const FileQueue &q);
    void AddLen(string filename, int len);
    int GetLength() const;								// 求队列长度
    bool IsEmpty() const;								// 判断队列是否为空
    void Clear();									    // 将队列清空
    bool Hav(string &e, const FileQueue &q);
    void Traverse() const ;	                            // 遍历队列，输出文件权限
    void Traverse2() const ;	                        // 遍历队列，输出文件名
    Status DelQueue(string &e);				            // 出队操作
    Status GetHead(string &e) const;			        // 取队头操作
    bool verification(string filename,int flag);        // 函数重载，判断不同情况下，文件是否有读写权限
    bool verification(string filename,bool *sec);
    Status EnQueue(const string e, bool *sec, const int len);			   // 入队操作
    FileQueue(const FileQueue &q);		                // 复制构造函数
    FileQueue &operator =(const FileQueue &q);          // 赋值语句重载
};

FileQueue::FileQueue()
// 操作结果：构造一个空队列
{
    rear = front = new File();	// 生成链队列头结点
}

bool *FileQueue::GetSec(string filename,const FileQueue &q)
//返回文件结点三位的保护码
{
    for (File *p = front->next; p != NULL; p = p->next){
        if(p->filename==filename){
            return p->security;
        }
    }
}
//
bool FileQueue::verification(string filename,bool *sec)
//根据传进来的保护码判断打开文件时输入的保护码是不是正确的，如果正确就返回true
{
    for (File *p = front->next; p != NULL; p = p->next){

        if(p->filename==filename){
            bool legal = true;

            for(int i = 0; i<3; i++){

                if(p->security[i] !=sec[i]){
                    legal = false;
                    break;
                }
            }
            if(legal)return true;
            else return false;
        }
    }
}
//
bool FileQueue::verification(string filename,int flag)
//根据flag传进来的值一一判断该文件是否有读写打开等权限
{
    for (File *p = front->next; p != NULL; p = p->next){

        if(p->filename==filename){
            bool legal = true;
            if(flag ==0){
                if(p->security[0] ==false){
                    legal = false;

                }
            }else if(flag ==1){
                if(p->security[1] ==false){
                    legal = false;

                }
            }else {

                if(p->security[2] ==false){
                    legal = false;
                }
            }
            if(legal)return true;
            else return false;
        }
    }
}

int FileQueue::RenLen(string filename,const FileQueue &q)
//返回文件内容的长度
{
    for (File *p = front->next; p != NULL; p = p->next){
        if(p->filename==filename){
            return p->length;
        }
    }
}

void FileQueue::AddLen(string filename, int addLen)
//每一次读内容之后都将长度加上对应数字
{
    for (File *p = front->next; p != NULL; p = p->next){
        if(p->filename==filename){
            p->length+=addLen;
        }
    }
}

bool FileQueue::Hav(string & e,const FileQueue &q) {
//判断文件列表中是否有对应文件
    for (File *p = q.front->next; p != NULL; p = p->next){
        if(p->filename==e){
            return true;
        }
    }
    return false;
}
//
FileQueue::FileQueue(File *file)
// 操作结果：构造一个空队列
{
    front = file;	// 生成链队列头结点
    File *p,*p1=front;
    for (p = front->next; p != NULL; p = p->next){
        p1 =p;
    }
    rear = p1;
}

FileQueue::~FileQueue()
// 操作结果：销毁队列
{
    Clear();
    delete front;
}

int FileQueue::GetLength() const
// 操作结果：返回队列长度
{
    int count = 0;		// 初始化计数器
    for (File *p = front->next; p != NULL; p = p->next)
        count++;		// 统计链队列中的结点数
    return count;
}

bool FileQueue::IsEmpty() const
// 操作结果：如队列为空，则返回true，否则返回false
{
    return rear == front;
}

void FileQueue::Clear()
// 操作结果：清空队列
{
    File *p = front->next;
    while (p != NULL)	{	// 依次删除队列中的元素结点
        front->next = p->next;
        delete p;
        p = front->next;
    }
    rear = front;
}

void FileQueue::Traverse() const
// 操作结果：依次对队列的每个元素调用函数(*visit)，输出文件的安全码
{
    for (File *p = front->next; p != NULL; p = p->next)
        // 对队列每个元素调用函数(*visit)访问
        cout<<p->filename<<"            "<<p->security[0]<<p->security[1]<<p->security[2]<<"            "<<p->length<<endl;

}

void FileQueue::Traverse2() const
// 操作结果：依次对队列的每个元素调用函数(*visit)，输出文件名
{
    for (File *p = front->next; p != NULL; p = p->next)
        // 对队列每个元素调用函数(*visit)访问
        cout<<p->filename<<" ";
    cout<<endl;

}
//
Status FileQueue::DelQueue(string &e)
// 操作结果：如果队列非空，那么删除队头元素，并用e返回其值，函数返回SUCCESS,
//	否则函数返回UNDER_FLOW，
{
    if (!IsEmpty()) 	{	// 队列非空
        File *p;
        File *p1 = front;
        for (p = front->next; p != NULL; p = p->next){

            if(p->filename == e){
                p1->next = p->next;
                break;
            }
            p1=p;
        }

        if (rear == p)	// 出队前队列中只有一个元素，出队后为空队列
            rear = p1;
        delete p;							// 释放出队的元素结点
        return SUCCESS;
    }
    else
        return UNDER_FLOW;
}

Status FileQueue::GetHead(string &e) const
// 操作结果：如果队列非空，那么用e返回队头元素，函数返回SUCCESS,
//	否则函数返回UNDER_FLOW，
{
    if (!IsEmpty()) 	{	            // 队列非空
        e = front->next->filename;		// 用e返回队头元素
        return SUCCESS;
    }
    else
        return UNDER_FLOW;
}

Status FileQueue::EnQueue(const string e, bool *sec, const int len)
// 操作结果：如果系统空间不够，返回OVER_FLOW,
//	否则插入元素e为新的队尾，返回SUCCESS
{
    File *p;
    p = new File(e, sec, len,NULL);	        // 生成一个新结点

    if (p) {
        rear->next = p;	                // 将新结点加在队尾

        rear = rear->next;				// rear指向新队尾
        return SUCCESS;
    }
    else                               //系统空间不够，返回OVER_FLOW
        return OVER_FLOW;
}

FileQueue::FileQueue(const FileQueue &q)
// 操作结果：由队列q构造新队列--复制构造函数
{
    rear = front = new File;	// 生成队列头结点
    for (File *p = q.front->next; p != NULL; p = p->next){}
        // 取q队列每个元素的值,将其在当前队列中作入队列操作
//        EnQueue(p->filename,);
}

FileQueue &FileQueue::operator =(const FileQueue &q)
// 操作结果：将队列q赋值给当前队列--赋值语句重载
{
    if (&q != this)	{
        Clear();       //清除原有队列
        for (File *p = q.front->next; p != NULL; p = p->next){

        }
            // 取q队列每个元素的值,将其在当前队列中作入队列操作
//            EnQueue(p->filename);
    }
    return *this;
}

#endif //PROJECT4_FILEQUEUE_H
