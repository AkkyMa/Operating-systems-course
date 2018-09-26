#include <stdio.h>
#include <signal.h>

void onSIGUSR1() {
	printf("You just sent first custom user signal. Great job!\n");
}

void onSIGSTOP() {
	printf("It seems you intent to stop this process");
}

void onSIGKILL() {
	printf("Why you are so cruel?!");
}

int main() {
	signal(SIGUSR1, onSIGUSR1);
	signal(SIGSTOP, onSIGSTOP);
	signal(SIGKILL, onSIGKILL);

	while(1);
	return 0;
}
