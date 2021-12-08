#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>


int main(void){
	pid_t pid;
	pid=fork();
	if(pid>0){
		printf("This is inside parent process. PID: %d\n",getpid());
		wait(NULL);
	}
	else if(pid==0){
		printf("This is inside child process. PID: %d PPID: %d\n",getpid(),getppid());
		exit(0);
	}
	else{
		printf("Error...\n");
	}
}
