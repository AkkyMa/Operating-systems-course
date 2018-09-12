#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char command[30];
	while(1) {
		printf("> ");
		scanf("%s", command);
		system(command);
	}
}
