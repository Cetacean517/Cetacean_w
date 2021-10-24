#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
	int i, pid;
	
	for(i = 0; i< 5;i++)
	{
		if(pid == fork())
		{
			printf("No.%d PID: %d \n",i,getpid());
			break;
		}
	}
}
