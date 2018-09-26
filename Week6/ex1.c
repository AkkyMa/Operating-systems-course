#include <stdio.h>
#include <string.h>

int main() {
	int desc[2];
	pipe(desc);

	char str1[] = "Some text here";
	char str2[100];
	write(desc[1], str1, strlen(str1));
	read(desc[0], str2, 100);
	printf("%s\n", str2);
}
