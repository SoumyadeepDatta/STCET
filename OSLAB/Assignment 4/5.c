#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main(void)
{
	pid_t pid;
	pid = fork();
	
	if(pid > 0)
	{
		printf("Parent PID -- %d\nChild PID -- %d\n",getpid(),pid);
		printf("I am parent process. Now I'm dead.\n");
		exit(0);
	}
	else if(pid == 0)
	{
		sleep(10);
		printf("\nI am child process. I ran for 10 seconds without parent process.\n");
		printf("I am an Orphan process. My PID -- %d",getpid());
		exit(0);
	}
	else
	{
		printf("Error creating child process");
	}
}
