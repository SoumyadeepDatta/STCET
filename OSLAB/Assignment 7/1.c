//Use of SIGKILL (kill child from parent)
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
int main(void)
{
	pid_t ppid,pid,cpid;
	ppid=getpid();
	pid = fork();
	if(ppid==getpid())
		printf("parent");
	else if (cpid==getpid())
		printf("child");
	if(pid > 0)
	{
		int i = 0;
		while(i++ < 5)
		{
			printf("\nIn the parent process.");
			sleep(1);
			if(i==3){
				kill(pid,SIGKILL);
				printf("\nChild killed");
			}
			
		}
	}
	else if (pid == 0)
	{
		int i = 0;
		while(i++ < 5)
		{
			printf("\nIn the child process.");
			sleep(1);

		}
	}
	else
	{
		//something bad happened.
		printf("\nSomething bad happened.");
		exit(EXIT_FAILURE);
	}
	return 0;
}
