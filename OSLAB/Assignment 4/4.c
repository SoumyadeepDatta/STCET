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
		printf("I'm parent process.\nMy PID -- %d My child PID -- %d\nI'm going to sleep for 10 seconds.\n",getpid(),pid);
		sleep(10);	// Parent is sleeping 
		// As they share the same address space 
		// So nothing is happening yet memory is still allocated
		printf("\nI'm parent process. Now I'm back.");
	}
	else if(pid == 0) // Inside child process
	// The child finishes execution but as parent is sleeping for 50 seconds
	// Its address space occupies memory for 50 seconds
	// During this time the child process is Zombie Process
	{
		printf("I am a Zombie process.\nMy PID -- %d & my PPID -- %d\nI'll be a zombie process for 10 seconds.",getpid(),getppid());
		exit(0);
	}
	else
	{
		printf("Error creating child process");
	}
}
