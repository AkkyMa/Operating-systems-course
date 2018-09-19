#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define buffer_size 10

int buffer[buffer_size];
int count = 0;

void* fib_calc(void *number) {
	buffer[0] = 1;
	buffer[1] = 2;
}

int main() {

	

}
