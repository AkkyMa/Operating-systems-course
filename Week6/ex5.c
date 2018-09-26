#include <stdio.h>
#include <signal.h>

int main() {
	int mainPID = getpid();
	int childPID = fork();

	if (getpid() == mainPID) {
		sleep(10);
		kill(childPID, SIGTERM);
	} else {
		while(1) {
			printf("I'm alive\n");
			sleep(1);
		}
	}
}
