#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
 
typedef struct node                     //节点
{
    char *filename;                     //文件名
    int dir_file;                       //文件夹或者文本文件
    struct node *first_child,*next_sibling;
} tree;                                 //多叉树
 
typedef struct                          //存放树节点的队列
{
    tree * filename;
    int pre;
} Node;
 
typedef struct
{
    Node filename[100];
    int front,rear;
} Queue;
 
Queue que;
 
void height(tree *t)                    // 层序遍历
{
    tree *p = t,*q;
    que.filename[0].filename = p;
    que.filename[0].pre = -1;
    que.front = -1;
    que.rear = 0;
    if(p->first_child == NULL)
        return ;
    while(que.front != que.rear)
    {
        que.front++;
        q = que.filename[que.front].filename->first_child;
        while(q != NULL)
        {
            que.rear++;
            que.filename[que.rear].filename = q;
            que.filename[que.rear].pre = que.front;
            q = q->next_sibling;
        }
    }
}
 
tree *insertTree(char *ch, tree *parent, tree *pre_sibling,int judge)     //插入节点
{
    tree *child = (tree *)malloc(sizeof(tree));
    child->filename = ch;
    child->dir_file = judge;
 
    if (parent != NULL)
    {
        parent->first_child = child;
    }
    if (pre_sibling != NULL)
    {
        pre_sibling->next_sibling = child;
    }
 
    child->first_child = NULL;
    child->next_sibling = NULL;
 
    return child;
}
 
tree *create()                 //创建头节点
{
    tree *root = (tree *)malloc(sizeof(tree));
    root->filename = "root";
    root->dir_file = 1;
    root->first_child = NULL;
    root->next_sibling = NULL;
    return root;
}
 
void insert(Queue q,int index,int tj)           //插入函数
{
    char *name;
    name = new char [10];
    bool judge;
    if(q.filename[index].filename->dir_file == 0)   //文本文件
    {
        cout<<"the current file is "<<q.filename[index].filename->filename<<endl;
        cout<<"input the name :";
        cin>>name;
        cout<<"input \"0\":";
        cin>>judge;
        tree *node = insertTree(name,NULL,q.filename[index].filename,judge);
    }
    else if(q.filename[index].filename->dir_file == 1 && tj == 1)    //要在同一目录下创建另一文件
    {
        cout<<"the current file is "<<q.filename[index].filename->filename<<endl;
        cout<<"input the name :";
        cin>>name;
        cout<<"if it is folder, input \"1\",else input \"0\":";
        cin>>judge;
        tree *node = insertTree(name,NULL,q.filename[index].filename,judge);
    }
    else                                                   //在某一目录下创建文件
    {
        cout<<"the current folder is "<<q.filename[index].filename->filename<<endl;
        cout<<"input the name :";
        cin>>name;
        cout<<"if it is folder, input \"1\",else input \"0\":";
        cin>>judge;
        tree *node = insertTree(name,q.filename[index].filename,NULL,judge);
    }
 
}
 
int main()
{
    int mark = 0;
    int num = 1;
    int tj = 0;
    int temp[100];
    tree *root = create();
    height(root);
    while(mark != -1)
    {
        cout<<"Current No."<<num<<",input the number of file(must be existed):";
        cin>>num;
        cout<<"the same level(the first can't choose Yes) ? 1.Yes 2.No"<<endl;
        cin>>tj;
        if(tj == 1)
            tj = 1;
        else
            tj = 0;
        insert(que,num-1,tj);
        height(root);
        cout<<"Quit input -1 ,continue input 1 :";
        cin>>mark;
    }
    for(int i = 1; i<=que.rear; i++)      //打印路径
    {
        int k = que.filename[i].pre;
        int j = 0;
        while(k != -1)
        {
            temp[j] = k;
            j++;
            k = que.filename[k].pre;
        }
        while(j > 0)
        {
            j--;
            cout<<"/"<<que.filename[temp[j]].filename->filename;
        }
        cout<<"/"<<que.filename[i].filename->filename<<endl;
    }
}
 