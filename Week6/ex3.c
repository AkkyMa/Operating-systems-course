#include <stdio.h>
#include <signal.h>

void onSIGINT() {
	printf("\nIt seems you just clicked ctrl-c\n");
}

int main() {

	signal(SIGINT, onSIGINT);
	sleep(10);
	return 0;
}
