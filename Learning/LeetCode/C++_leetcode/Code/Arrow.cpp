#include <stdint.h>
#include <iostream>
using namespace std;

int main(){
    int x = 1;
    int* p1 = &x;   // 指针可以被修改，值也可以被修改
    cout << p1 << x << endl;
    const int* p2 = &x; // 指针可以被修改，值不能被修改 (const int)
    int * const p3 = &x; //指针不能被修改(*const), 值可以被修改
    const int * const p4 = &x; // 指针不可以被修改，值也不可以被修改

}