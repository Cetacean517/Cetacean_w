# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <wait.h>
int main()
{
	int i;
	if (fork())
	{
		i = wait(0);
		printf("This is the parent process.\n");
		printf("The child process, ID number %d, is finished.\n",i);
	}
	else
	{
		printf("This is the child process.\n");
		sleep(10);
		exit(0);
	}
}

