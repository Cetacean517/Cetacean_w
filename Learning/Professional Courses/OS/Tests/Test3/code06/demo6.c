#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>
int main(void)
{
	int i,r,j,k,l,pro1,pro2,fd[2];
	char buf[50],s[50];
	pipe(fd);
	while((pro1=fork())==-1);
	if(pro1==0)
	{
		lockf(fd[1],1,0);
		sprintf(buf,"Child process Process1 is sending messages!\n");
		printf("Child process Process1!\n");
		write(fd[1],buf,50);
		lockf(fd[1],0,0);
		sleep(5);
		j = getpid();
		k = getppid();
		printf("Process1 %d is weakup. MY PPID is %d.\n",j,k);
		exit(0);
	}
	else
	{
		while((pro2=fork())==-1);
		if(pro2==0)
		{
			lockf(fd[1],1,0);
			sprintf(buf,"Child process Process2 is sending messages!\n");
			printf("Child process Process2!\n");
			write(fd[1],buf,50);
			lockf(fd[1],0,0);
			sleep(5);
			j = getpid();
			k = getppid();
			printf("Process2 %d is weakup. MY PPID is %d.\n",j,k);
			exit(0);
		}
		else
		{
			l = getpid();
			wait(0);
			if(r=read(fd[0],s,50)==-1)
				printf("Can't read pipe.\n");
			else
				printf("Parent %d:%s \n",l,s);
			wait(0);
			if(r = read(fd[0],s,50)==-1)
				printf("Can't read pipe.\n");
			else
				printf("Parent %d:%s\n",l,s);
			exit(0);
		}
	}
}
