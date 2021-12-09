/* Program: signal2.c -- Handles SIGINT and SIGTSTP generated from terminal
Requires two [Ctrl-c]s to terminate */
#include <stdio.h>
#include <signal.h>
#include "quit.h"
void tstp_handler(int signo); /* Handler for [Ctrl-z] */
void int_handler(int signo); /* Handler for [Ctrl-c] */
int count = 0;
int main (void) {
	struct sigaction act1, act2, act3;
	act1.sa_handler = tstp_handler; /* Disposition for these two signals */
	act2.sa_handler = int_handler; /* set to enter respective handlers */
	act3.sa_handler = SIG_IGN; /* Disposition set to ignore */
	sigaction(SIGTSTP, &act1, NULL);
	sigaction(SIGINT, &act2, NULL);
	sigaction(SIGQUIT, &act3, NULL);
	fprintf(stderr, "Press [Ctrl-z] first, then [Ctrl-c]\n");
	for (;;)
		pause(); /* Will return on receipt of signal */
	exit(0);
}
void tstp_handler(int signo) {
	fprintf(stderr, "Can’t stop this program\n");
}
void int_handler(int signo) { /* Will terminate program */
	if (++count == 1)
		fprintf(stderr, "Press again\n");
	else
		quit("Quitting", 1);
}
