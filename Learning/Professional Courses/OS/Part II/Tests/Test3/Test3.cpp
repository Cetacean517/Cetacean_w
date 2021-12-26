#include<iostream>
#include<cstdlib>
#include <algorithm>
#include <ctime>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <iomanip>
using namespace std;

int *random_num = new int[256];     // ������ɵĵ�ַ��
int *page_num = new int[256];       // ÿ����ַ��Ӧ��ҳ��
int page_scale = 1;                 // ÿҳ��С1kb
int table_all_num = 4;              // �ڴ���4��ҳ����
int table_num = 0;                  // ������
struct ListNode                     // �Զ�������ӵ����ݽṹ�������滻�㷨��
{
    int value;                      // 
    ListNode *next;                 
};

void get_random_addr() {
    /*
        ������ɵ�ַ�������� rand()%(n-m+1)+m ����[m,n)��Χ�ڵ�һ�������
    */
    int i = 1;          // ������
    int m;
    random_num[0] = rand() % (255 - 0 + 1) + 0;      // ����[0,255)��Χ�ڵ�һ�������
    m = random_num[0];
    while (i < 256) {
        random_num[i] = ++m;                            // m+1д������
        i++;                                            //����
        if (i >= 256)break;                             //�����ж�
        random_num[i] = rand() % (m - 1 - 0 + 1) + 0;   //ǰ��ַ�� [0,m-1)��Χ�е�һ�������
        m = random_num[i];
        i++;
        if (i >= 256)break;
        random_num[i] = ++m;
        i++;
        if (i >= 256)break;                             //���ַ����
        random_num[i] = rand() % (255 - m + 2) + m + 1; // [m+1,255)
        m = random_num[i];
        i++;
    }
    for(int i = 0; i < 256; i++){
        random_num[i] *= 128;                       // ģ����ʵ��ַ��ֵ
    }
}

void get_page_num(){
    /*
        �������ַ��Ӧ��ҳ�š���ʽ��[��ַ / ҳ���С] = ҳ��
    */
   // 1. ���㲢����ҳ��
    for(int i = 0; i < 256; i++){
        int page = random_num[i] / (1024 * page_scale);
        page_num[i] = page;
    }

    // 2.�����ӡ
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
    int danger =- 1;                      //������i
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
    // 1. ������������ͷ���
    ListNode *head = new ListNode;
    head->value = -1;
    head->next = nullptr;
    // 2. ������һ�����
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
        } //�ж�page_num[i]�ڲ��ڵ�ǰҳ��������
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
        } //�ж�page_num[i]�ڲ��ڵ�ǰҳ��������
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
    // 1. ������������ͷ���
    ListNode *head = new ListNode;
    head->value = -1;
    head->next = nullptr;
    // 2. �����һ�����
    ListNode * first = new ListNode;
    first->value = page_num[i++];
    first->next= nullptr;
    head->next = first;
    table_num++;

    // 3. δ��ʱ���жϵ�ǰҳ�Ƿ��Ѿ����룻��δ���룬����롣ֱ��װ��Ϊֹ
    while(table_num < table_all_num){
        bool pagefault = true;
        //�ж�page_num[i]�ڲ��ڵ�ǰҳ��������
        for(ListNode *point =head->next;point != nullptr; point = point->next){
            if(point->value == page_num[i++]){
                pagefault = false;
                break;
            }
        } 
        // �Ѿ��ڣ���Ժ�һ����в���
        if(pagefault){
            ListNode *temp2 = new ListNode;
            temp2->value = page_num[i++];
            temp2->next= head->next;
            head->next = temp2;
            table_num++;
        }
    }
    // 4. �ж��Ƿ�Ҫ�滻
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
    // 5. ����Ƶ��
    freq = 1-(freq/256);
    cout<<table_all_num<<setfill(' ')<<setw(36)<<freq<<endl;

}
int main(){
    // 1. ���������ַ��
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