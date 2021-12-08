# Processes in Linux
### 1. execl example
```c
#include<stdio.h>
int main(void){
	execl("/bin/wc","wc","-l","-c","/home/user1234/Documents/Assignment 5/txt.txt",(char *) 0);
	printf("Error\n");
}
```
### 2. execv example
```c
#include<stdio.h>
int main(void){
	// execv for variable number of arguments
	char *cmdargs[] = {"wc","-l","-c","/home/user1234/Documents/Assignment 5/txt.txt",NULL};
	execv("/bin/wc");
}
```
### txt.txt (PATH="/home/user1234/Documents/Assignment 5/txt.txt")
```
hello
frwefkahfikj
fwefhowehf
```
1. Write a program to implement parent child process and explain their concurrent execution.
2. Write a program to implement and explain orphan process.
3. Write a program to implement and explain zombie process.
4. Write a program to implement threads.
