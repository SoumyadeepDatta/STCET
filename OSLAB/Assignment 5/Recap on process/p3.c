#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
	int p=fork();
	if(p==0){
		printf("Child process\n");
		sleep(5);
		printf("Orphan process\n");
		exit(0);
	}
	else if(p>0){
		printf("Parent Process\n");
		exit(0);
	}
	return 1;
}
