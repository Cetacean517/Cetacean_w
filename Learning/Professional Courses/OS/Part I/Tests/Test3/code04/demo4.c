#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

int main(void)
{
	int child_p1, child_p2, child_p3;
	int pid, status; setbuf(stdout,NULL);
	child_p1 = fork();
	if (child_p1 == 0)
	{
		execlp("echo", "echo", "Hello World!", (char *)0);
		perror("exec1 error.\n");
		exit(1);
	}
	
	child_p2 = fork();
	if (child_p2 == 0)
	{
		execlp("man", "man","ls", (char *)0);
		perror("exec2 error.\n");
		exit(2);
	}

	child_p3 = fork();
	if (child_p3 == 0)
	{
		execlp("date","date", (char *)0);
		perror("exec3 error.\n");
		exit(3);
	}
	puts("Parent process is waiting for child process to return.");
	while((pid=wait(&status))!=-1)
	{
		if(child_p1 == pid)
			printf("Child_process_one terminated with status %d\n",(status >> 8));
		else
		{
			if(child_p2 == pid)
				printf("Child_process_two terminated with status %d\n",(status >> 8));
			else
			{
				
				if(child_p3 == pid)
				printf("Child_process_three terminated with status %d\n",(status >> 8));
			}
		}
	}
	puts("ALL PROCESSES ARE TERMINATED.");
	puts("PARENT PROCESS IS TERMINATED.");
	exit(0);
}
