#include <stdio.h>

int main() {
	int i = __INT_MAX__;
	float f = __FLT_MAX__;
	double d = __DBL_MAX__;

	printf("int: size - %ld bytes, max value - %d\n", sizeof(int), i);
	printf("float: size - %ld bytes, max value - %f\n", sizeof(float), f);
	printf("double: size - %ld bytes, max value - %f\n", sizeof(double), d);

	return 0;
}
