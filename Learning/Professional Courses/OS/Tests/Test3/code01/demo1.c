#include<unistd.h>
#include<wait.h>
#include<stdlib.h>
#include<stdio.h>
int main(void)
{
    //输出进程的一些ID信息
    printf("PID:%d\n",getpid());
    printf("GID:%d\n",getpgrp());
    printf("UID = %d\n",getuid());

    // 休眠5s
    sleep(5);

    int child_pid;
    child_pid = fork();
    if(child_pid == 0)
    {
       exit(1);
    };
    wait(0);
    printf("Do you want to stop the process?\n");
    char x;
    scanf("%c",&x);
    if ( x == 'y')
    {
	exit(0);
    };
    return 0;
}
