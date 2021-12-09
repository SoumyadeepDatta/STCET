/* Program: signal.c -- Waits for 5 seconds for user input and then
generates SIGALRM that has a handler specified */
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#define BUFSIZE 100
#include "quit.h"


void alrm_handler(int signo); /* Prototype declaration */
char buf[BUFSIZE] = "foo\0"; /* Global variable */
int main (void) {
	int n;
	struct sigaction act;
	act.sa_handler = alrm_handler; /* Specify handler */
	if (sigaction(SIGALRM, &act, NULL) == -1) /* Install handler */
		quit("sigalrm", 1);
	fprintf(stderr, "Enter filename: ");
	alarm(5); /* Set alarm clock; will deliver */
	n = read(STDIN_FILENO, buf, BUFSIZE); /* SIGALRM in 5 seconds */
	if (n > 1) /* Will come here if user inputs */
		fprintf(stderr, "Filename: %s\n", buf); /* string within 5 seconds */
	exit(0);
}
void alrm_handler(int signo) {
	fprintf(stderr, "\nSignal %d received, default filename: %s\n", signo, buf);
	exit(1);
}
