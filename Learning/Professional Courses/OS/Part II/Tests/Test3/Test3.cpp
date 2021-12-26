#include<iostream>
#include<cstdlib>
#include <algorithm>
#include <ctime>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <iomanip>
using namespace std;

int *random_num = new int[256];     // 随机生成的地址流
int *page_num = new int[256];       // 每个地址对应的页号
int page_scale = 1;                 // 每页大小1kb
int table_all_num = 4;              // 内存有4个页表项
int table_num = 0;                  // 计数器
struct ListNode                     // 自定义的连接点数据结构（用于替换算法）
{
    int value;                      // 
    ListNode *next;                 
};

void get_random_addr() {
    /*
        随机生成地址流：利用 rand()%(n-m+1)+m 产生[m,n)范围内的一个随机数
    */
    int i = 1;          // 计数器
    int m;
    random_num[0] = rand() % (255 - 0 + 1) + 0;      // 产生[0,255)范围内的一个随机数
    m = random_num[0];
    while (i < 256) {
        random_num[i] = ++m;                            // m+1写入数组
        i++;                                            //计数
        if (i >= 256)break;                             //条件判断
        random_num[i] = rand() % (m - 1 - 0 + 1) + 0;   //前地址区 [0,m-1)范围中的一个随机数
        m = random_num[i];
        i++;
        if (i >= 256)break;
        random_num[i] = ++m;
        i++;
        if (i >= 256)break;                             //后地址区域
        random_num[i] = rand() % (255 - m + 2) + m + 1; // [m+1,255)
        m = random_num[i];
        i++;
    }
    for(int i = 0; i < 256; i++){
        random_num[i] *= 128;                       // 模拟真实地址数值
    }
}

void get_page_num(){
    /*
        计算求地址对应的页号。公式：[地址 / 页面大小] = 页号
    */
   // 1. 计算并保存页号
    for(int i = 0; i < 256; i++){
        int page = random_num[i] / (1024 * page_scale);
        page_num[i] = page;
    }

    // 2.结果打印
    int i = 0;
    while(i<256)
    {
        cout<<setfill(' ')<<setw(5)<<"page_num"<<"["<<i<<"]="<<setfill(' ')<<setw(10)<<page_num[i]<<" ";
        i++;
        cout<<setfill(' ')<<setw(5)<<"page_num"<<"["<<i<<"]="<<setfill(' ')<<setw(10)<<page_num[i]<<" ";
        i++;
        cout<<setfill(' ')<<setw(5)<<"page_num"<<"["<<i<<"]="<<setfill(' ')<<setw(10)<<page_num[i]<<" ";
        i++;
        cout<<setfill(' ')<<setw(5)<<"page_num"<<"["<<i<<"]="<<setfill(' ')<<setw(10)<<page_num[i]<<" "<<endl;
        i++;
    }
    
    cout<<"\n vmize=32k"<<setfill(' ')<<setw(18)<<"page_scale="<<page_scale<<endl;
    cout<<"page assigned "<<setfill(' ')<<setw(18)<<"pages_in/total references"<<endl;
}

ListNode *search(ListNode *head, int i){
    int danger =- 1;                      //最后访问i
    ListNode * result =head->next;
    for(ListNode *point =head->next;point != nullptr; point = point->next){
        int i1 = i+1;

        while( i1 < 256 ){
            if(page_num[i1] == point->value){
                break;
            }else{
                i1++;
            }
        }
        if(danger < 0 || i1 > danger){
            result = point;
            danger = i1;
        }
    }
    return result;
}

void my_lru(){
    double freq = table_all_num;
    int i = 0;
    // 1. 创建空链表，带头结点
    ListNode *head = new ListNode;
    head->value = -1;
    head->next = nullptr;
    // 2. 创建第一个结点
    ListNode * first = new ListNode;
    first->value = page_num[i++];
    first->next= nullptr;
    head->next = first;
    table_num++;
    // 
    while(table_num < table_all_num){
        bool pagefault = true;
        bool special = true;
        ListNode * last = new ListNode;
        ListNode *father = head;
        for(ListNode *point =head->next;point != nullptr; point = point->next, father = father->next){
            if(point->value == page_num[i++]){
                pagefault = false;
                if(point->next != nullptr){
                    father->next = point ->next;
                    last = point;
                    special = false;
                }
                break;
            }
        } //判断page_num[i]在不在当前页表链表中
        if(pagefault){
            ListNode *temp2 = new ListNode;
            temp2->value = page_num[i++];
            for(ListNode *point = head->next;point!=nullptr; point= point->next){
                if(point->next== nullptr){
                    point->next = temp2;
                    temp2->next = nullptr;
                }
            }
            table_num++;
        }
        else{
            if(!special){
                for(ListNode *point = head->next;point!=nullptr; point= point->next){
                    if(point->next== nullptr){
                        point->next = last;
                        last->next = nullptr;
                    }
                }
            }
        }
    }
    for(i; i<256; i++){
        bool pagefault = true;
        bool special = true;
        ListNode * last = new ListNode;
        ListNode *father = head;
        for(ListNode *point =head->next;point != nullptr; point = point->next, father = father->next){
            if(point->value == page_num[i++]){
                pagefault = false;
                if(point->next != nullptr){
                    father->next = point ->next;
                    last = point;
                    special = false;
                }
                break;
            }
        } //判断page_num[i]在不在当前页表链表中
        if(pagefault){
            freq++;
            ListNode *temp2 = new ListNode;
            temp2->value = page_num[i++];
            for(ListNode *point = head->next;point!=nullptr; point= point->next){
                if(point->next== nullptr){
                    point->next = temp2;
                    temp2->next = nullptr;
                }
            }
            head->next = head->next->next;

        }
        else{
            if(!special){
                for(ListNode *point = head->next;point!=nullptr; point= point->next){
                    if(point->next== nullptr){
                        point->next = last;
                        last->next = nullptr;
                    }
                }
            }
        }
    }
    freq = 1-(freq/256);
    cout<<table_all_num<<"                                    "<<freq<<endl;
}

void my_opt(){
    double freq = table_all_num;
    int i = 0;
    // 1. 创建空链表，带头结点
    ListNode *head = new ListNode;
    head->value = -1;
    head->next = nullptr;
    // 2. 插入第一个结点
    ListNode * first = new ListNode;
    first->value = page_num[i++];
    first->next= nullptr;
    head->next = first;
    table_num++;

    // 3. 未满时，判断当前页是否已经调入；若未调入，则调入。直到装满为止
    while(table_num < table_all_num){
        bool pagefault = true;
        //判断page_num[i]在不在当前页表链表中
        for(ListNode *point =head->next;point != nullptr; point = point->next){
            if(point->value == page_num[i++]){
                pagefault = false;
                break;
            }
        } 
        // 已经在，则对后一项进行查找
        if(pagefault){
            ListNode *temp2 = new ListNode;
            temp2->value = page_num[i++];
            temp2->next= head->next;
            head->next = temp2;
            table_num++;
        }
    }
    // 4. 判断是否要替换
    for(i; i<256;i++){
        bool pagefault = true;
        for(ListNode *point =head->next;point != nullptr; point = point->next){
            if(point->value == page_num[i]){
                pagefault = false;
                break;
            }
        }
        if(pagefault){
            freq++;
            search(head,i)->value = page_num[i];
        }
    }
    // 5. 计算频率
    freq = 1-(freq/256);
    cout<<table_all_num<<setfill(' ')<<setw(36)<<freq<<endl;

}
int main(){
    // 1. 生成随机地址流
    get_random_addr();
    int i=0;
    while(i<256)
    {
        cout<<setfill(' ')<<setw(5)<<'a'<<"["<<i<<"]="<<setfill(' ')<<setw(8)<<random_num[i]<<" ";
        i++;
        cout<<setfill(' ')<<setw(5)<<'a'<<"["<<i<<"]="<<setfill(' ')<<setw(8)<<random_num[i]<<" ";
        i++;
        cout<<setfill(' ')<<setw(5)<<'a'<<"["<<i<<"]="<<setfill(' ')<<setw(8)<<random_num[i]<<" ";
        i++;
        cout<<setfill(' ')<<setw(5)<<'a'<<"["<<i<<"]="<<setfill(' ')<<setw(8)<<random_num[i]<<" "<<endl;
        i++;
    }
    cout<<"====================================================================================================="<<endl;
    cout<<"The algorithm is:";
    string alg;
    cin>>alg;
    if(alg=="o")
    {
       while(page_scale<9){
           cout<<"PAGE NUMBER WITH SIZE "<<page_scale<<"k FOR EACH ADDRESS IS:"<<endl;
           get_page_num();

           while(table_all_num*page_scale<=32){
               if(table_all_num*page_scale>27 && page_scale==1)break;
               my_opt();
               table_all_num+=2;
               table_num=0;
           }
           table_all_num=4;
           page_scale*=2;
       }
    }else{
        while(page_scale<9){
            cout<<"PAGE NUMBER WITH SIZE "<<page_scale<<"k FOR EACH ADDRESS IS:"<<endl;
            get_page_num();

            while(table_all_num*page_scale<=32){
                if(table_all_num*page_scale>25 && page_scale==1)break;
                my_lru();
                table_all_num+=2;
                table_num=0;
            }
            table_all_num=4;
            page_scale*=2;
        }
    }
}