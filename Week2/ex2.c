#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char str[64];
	char rstr[64];
	scanf("%s", str);

	int i=-1, j=strlen(str);
	rstr[j] = 0;
	while(j) {
		rstr[++i] = str[--j];
	}

	printf("%s\n", rstr);
}
