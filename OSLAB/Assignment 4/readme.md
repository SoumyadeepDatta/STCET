# Process management in C (Using Linux Platform)
How to run .c files in Linux
```
gcc filename
./a.out
```
E.g. Important informations regarding a process.
```c
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(void){
	//Process ID, Parent Process ID
	printf("PID : %4d, PPID : %4d\n",getpid(),getppid());
	//User ID, Group ID
	printf("UID : %4d, GID : %4d\n",getuid(),getgid());
	//Effective User ID, Effective Group ID (Effect occurs after masking or hiding of any process)
	printf("EUID : %4d, EGID : %4d\n",geteuid(),getegid());
	//PATH Environmental Variable
	printf("PATH=%s\n",getenv("PATH"));	
	exit(0);
}
```
E.g. Fork a process
```c
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main(void)
{
	pid_t pid;
	
	printf("Before fork\n");
	pid = fork();			// Replicate current process
	
	if(pid > 0)
	{
		sleep(1);	// In the process make sure that parent doesn't die before child
		printf("PARENT -- PID: %d PPID: %d, CHILD PID: %d\n",getpid(),getppid(),pid);
	}
	else if(pid == 0)		// In the child process
	{
		printf("CHILD -- PID: %d PPID: %d\n",getpid(),getppid());
	}
	else
	{
		printf("Fork error\n");	// PID must be -1 here (-ve)
		exit(1);
	}
	printf("Both processes continue from here\n");	// In both processes
	exit(0);
}
```
1. Write a C program to call a program from another program.
2. Write a C program to print message when child process dies.
3. Create 8 child processes with minimum number of fork calling.
4. Create a Zombie process.
5. Create an Orphan process.

