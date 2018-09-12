#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>

int main() {
	pid_t pid = getpid();
	int n;

	fork();

	if (pid == getpid()) {
		printf("Hello from parent [%d - %d]\n", pid, n);
	}
	else {
		printf("Hello from child [%d - %d]\n", getpid(), n);
	}
}
