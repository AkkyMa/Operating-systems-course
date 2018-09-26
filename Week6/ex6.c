#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

int main() {
	int mainpid, child1pid, child2pid;
	int desc[2];
	pipe(desc);
	mainpid = getpid();
	child1pid = fork();
	if (getpid() == mainpid) child2pid = fork();
	if (getpid() == mainpid) printf("Processes created\n");

	if (getpid() == mainpid) {
		char status;
		char buffer[20];
		sprintf(buffer, "%d", child2pid);
		write(desc[1], buffer, strlen(buffer));
		printf("Second child id written\n");
		printf("Main process waiting\n");
		waitpid(child2pid, &status, WUNTRACED);
		printf("Main process waited state change\n");
		exit(0);
	} else if (child1pid == 0) {
		char buffer[20];
		read(desc[0], buffer, 20);
		printf("Second child id read\n");
		child2pid = atoi(buffer);
		printf("First child waiting before stopping\n");
		sleep(2);
		kill(child2pid, SIGSTOP);
		printf("First child stopped its brother\n");
		exit(0);
	} else {
		printf("Second child just chilling\n");
		while(1);
		exit(0);
	}
}
