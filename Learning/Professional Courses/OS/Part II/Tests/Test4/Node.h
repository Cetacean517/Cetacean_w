#ifndef PROJECT4_NODE_H
#define PROJECT4_NODE_H
#include "Assistance.h"			// 辅助软件包


// 文件类
struct File
{
// 数据成员:
    string filename;				// 文件名
    bool security[3];               // 保护码
    int length;                     // 文件长度
    File *next;		                // 指针域

// 构造函数:
    File();						    // 无参数的构造函数
    File(string item,bool *security,int length, File *link = NULL);	// 已知数数据元素值和指针建立结构
};

// 用户类
template <class ElemType>
struct Node
{
// 数据成员:
    ElemType data;				// 用户名
    Node<ElemType> *next;		// next用户
    File *file;                 // 文件目录指针

// 构造函数:
    Node();						// 无参数的构造函数
    Node(ElemType item, Node<ElemType> *link = NULL,File *filelink=NULL);	// 已知数数据元素值和指针建立结构
};

// 结点类的实现部分
template<class ElemType>
Node<ElemType>::Node()
// 操作结果：构造指针域为空的结点
{
    file = NULL;
    next = NULL;
}

template<class ElemType>
Node<ElemType>::Node(ElemType item, Node<ElemType> *link, File *links)
// 操作结果：构造一个数据域为item和指针域为link的结点
{
    data = item;
    next = link;
    file = links;
}

File::File()
// 操作结果：构造指针域为空的结点
{
    filename="";
    security[0]=security[1]=security[2]= false;
    length = 0;
    next = NULL;
}

File::File(string item,bool *sec,int len, File *link)
// 操作结果：构造一个数据域为item和指针域为link的结点
{
    filename=item;

    for(int i = 0; i<3; i++){
        security[i] = sec[i];
    }
    length = len;
    next = link;

}

#endif //PROJECT4_NODE_H
