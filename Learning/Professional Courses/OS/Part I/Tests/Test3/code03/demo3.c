#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

int main(void)
{
	int i, j;
	printf("<--Father Process-->\nMY PID: %d \nMY_FATHER's PID: %d \n", getpid(),getppid());
	
	for (i = 0; i< 3;i++)
	{
		if (fork() == 0)
			printf("No.%d PID = %d, PPID = %d \n",i,getpid(),getppid());
		else
		{
			j = wait(0);
			printf("No.%d This chlid process %d is closed.\n", i,j);
		}
	}
}
