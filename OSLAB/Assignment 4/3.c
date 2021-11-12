#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main(void)
{
    pid_t pid;
    for(int i=0;i<8;i++) // loop will run 8 times to create 8 child processes
    {
        pid = fork();
        if(pid == 0)
        {
            printf("PARENT --PID: %d CHILD --PID: %d\n",getppid(),getpid());
            exit(0);
        }
    }
    for(int i=0;i<8;i++) // loop will run 8 times to terminate the child processes
    {
    	wait(NULL);
    } 
}
