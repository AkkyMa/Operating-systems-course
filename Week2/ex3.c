#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	scanf("%d", &n);

	int lb = n-1, rb = n-1;
	char *str = malloc(2*n);
	str[2*n-1] = 0;
	for (int i = 0; i < 2*n-1; ++i)
		str[i] = ' ';

	while (lb>=0) {
		str[lb--] = '*';
		str[rb++] = '*';
		printf("%s\n", str);
	}

	return 0;
}
