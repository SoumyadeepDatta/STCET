# Tutorial on Signal Handling in Linux
### Make sure that *quit.c* & *quit.h* resides in the same directory as *signal.c* & *signal2.c*
quit.h
```c
#include<stdio.h>
#include<stdlib.h>
void quit(char*,int);
void quit(char *message,int exit_status){
	fprintf(stderr,message);
	exit(exit_status);
}
```
quit.c
```c
#include "quit.h"
void quit(char *message,int exit_status){
	fprintf(stderr,message);
	exit(exit_status);
}
```
