#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char command[100];
	while(1) {
		printf("> ");
		fgets(command, 100, stdin);
		strcat(command, "&");
		*strchr(command, '\n') = ' ';
		system(command);
	}
}
