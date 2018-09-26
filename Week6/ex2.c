#include <stdio.h>
#include <string.h>

int main() {
	int desc[2];
	pipe(desc);
	int mainPID = getpid();
	fork();

	if(getpid() == mainPID) {
		char str[] = "String for transfering";
		write(desc[1], str, strlen(str));
	} else {
		char str[100];
		read(desc[0], str, 100);
		printf("%s\n", str);
	}
}
