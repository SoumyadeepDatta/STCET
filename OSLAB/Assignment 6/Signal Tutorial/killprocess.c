/* Program: killprocess.c -- Uses fork and exec to run a user-defined program
and kills it if it doesn’t complete in 5 seconds.*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>
pid_t pid;
int main (int argc, char **argv) {
	int i, status;
	void death_handler(int signo); /* A common signal handler this time */
	struct sigaction act;
	act.sa_handler = death_handler;
	sigaction(SIGCHLD, &act, NULL); /* Disposition for these two signals */
	sigaction(SIGALRM, &act, NULL); /* set to enter a single handler */
	switch (pid = fork()) {
		case -1: 
			fprintf(stderr, "Fork error\n");
		case 0: 
			execvp(argv[1], &argv[1]); /* Execute command */
			perror("exec");
			break;
		default: 
			alarm(5); /* Will send SIGALRM after 5 seconds */
			pause(); /* Will return when SIGCHLD signal is received */
			fprintf(stderr, "Parent dies\n");
	}
	exit(0);
}
void death_handler(int signo) { /* This common handler picks up the */
	int status; /* exit status for normal termination */
	/* but sends the SIGTERM signal if */
	switch (signo) { /* command doesn’t complete in 5 seconds */
		case SIGCHLD: 
			waitpid(-1, &status, 0); /* Same as wait(&status); */
			fprintf(stderr, "Child dies; exit status: %d\n",WEXITSTATUS(status));
			break;	
		case SIGALRM: 
			if (kill(pid, SIGTERM) == 0)
				fprintf(stderr, "5 seconds over, child killed\n");
	}
}
