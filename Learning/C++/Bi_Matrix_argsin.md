```C
主要有三种方式
void fun(int *a[],int m,int n)//**a
void fun2(int a[][2],int m)//a[2][2]
void fun3(int (*a)[2],int m,int n)//a[2][2];int (*p)[2];p=a;

//c语言中经常需要通过函数传递二维数组，有三种方法可以实现，如下：

//方法一， 形参给出第二维的长度。

#include <stdio.h>

void func(int n, char str[][5])
{
           int i;
           for (i = 0; i < n; i++)
           {
                   printf("\nstr[%d] = %s\n", i, str[i]);
           }
}

void main()
{
           char str[][5] = {"abc", "def", "ghi"};
           func(3, str);
}


//方法二，形参声明为指向数组的指针。

#include <stdio.h>

void func(int n, char (*str)[5])
{
           int i;
           for (i = 0; i < n; i++)
           {
                   printf("\nstr[%d] = %s\n", i, str[i]);
           }
}

void main()
{
           char str[][5] = {"abc", "def", "ghi"};
           func(3, str);
}


//方法三，形参声明为指针的指针。

#include <stdio.h>

void func(int n, char **str)
{
           int i;
           for (i = 0; i < n; i++)
           {
                   printf("\nstr[%d] = %s\n", i, str[i]);
           }
}

void main()
{
           char *p[3];
           char str[][5] = {"abc", "def", "ghi"};
           p[0] = &str[0][0];
           p[1] = str[1];
           p[2] = str[2];
           func(3, p);
}
```