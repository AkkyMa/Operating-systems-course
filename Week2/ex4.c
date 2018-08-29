#include <stdio.h>

void swap(int *i1, int *i2) {
	*i1 ^= *i2;
	*i2 ^= *i1;
	*i1 ^= *i2;
}

int main() {
	int i1, i2;
	scanf("%d %d", &i1, &i2);
	swap(&i1, &i2);
	printf("%d %d\n", i1, i2);

	return 0;
}
