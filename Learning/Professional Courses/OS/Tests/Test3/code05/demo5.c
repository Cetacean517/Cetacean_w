#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int glob = 4;
int main(void)
{
	pid_t pid;
	int vari = 5;
	printf("Before fork.\n");
	if ((pid=fork())<0)
	{
		printf("Fork Error!\n");
		exit(0);
	}
	else
		if(pid==0)
		{
			glob ++;
			vari --;
			printf("Child %d changed the vari and glob.\n",getpid());
		}
		else
			printf("Parent %d did not changed the vari and glob.\n",getpid());
	printf("PID = %d, glob = %d, vari = %d\n",getpid(),glob,vari);
	exit(0);
}
