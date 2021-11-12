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
		wait(NULL);
		printf("Child process is terminated successfuly\n");
	}
	else if(pid == 0)
	{
		exit(0);
	}
	else
	{
		printf("Error creating child process");
	}
}
