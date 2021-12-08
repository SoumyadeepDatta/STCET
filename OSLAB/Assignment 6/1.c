#include<stdio.h>
#include<unistd.h>
#include<signal.h>
// handler function to ignore signals
void ignore(){
	printf("Signal Ignored\n");
}

int main(void){
	/*
	 * There are total 64 signals in Ubuntu 18.04 LTS
	 * 2 of them are given for user to make their own signal (SIGUSR1,SIGUSR2)
	 * 2 of them can't be trapped (SIGKILL,SIGSTOP)
	 * Among the other signals, 6 of them are handled here as an example
	 * We used SIGKILL to kill the process from another terminal
	  
	*/
	signal(SIGINT,ignore); 
	signal(SIGQUIT,ignore); 
	signal(SIGTERM,ignore); 
	signal(SIGALRM,ignore);
	signal(SIGTSTP,ignore);
	signal(SIGFPE,ignore);
	
	// Infinite loop
	while(1){
		printf("Hello world\n");
		sleep(5);
	}
}
