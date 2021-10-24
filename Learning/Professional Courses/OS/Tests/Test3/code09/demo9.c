#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<wait.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#define MSGKEY 75
int main(void)
{
	int i,j,k;
	void func();
	signal(18,func);
	if(i=fork())
	{
		j = kill(i,18);
		printf("Parent: signal 18 has been sent to child %d,returned %d.\n",i,j);
		k = wait(0);
		printf("After wait %d, Parent%d:finished.\n",k,getpid());
	}
	else
	{
		sleep(10);
		printf("Child%d: A signal from my parent is received.\n",getpid());
	}
}
void func()
{
	int m;
	m = getpid();
	printf("I am Process %d:It is signal 18 processing function.\n",m);
}
