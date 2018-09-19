#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
int pthread_yield(void*);

#define buffer_size 10

int buffer[buffer_size];
int count = 0;
int free_pos = 0;
int fill_pos = 0;

void* fib_calc(void *number) {
int p1 = 1, p2 = 1;
buffer[0] = p1;
buffer[1] = p2;
free_pos +=2;
count += 2;
*(int*)number -= 2;
while(1) {
	//printf("p1: %d, %d\n", count, *(int*)number);
	while(count != 8 && *(int*)number > 0) {
		p2 = p1 + p2;
		p1 = p2 - p1;
		buffer[free_pos] = p2;
		free_pos = (free_pos + 1) % buffer_size;
		count += 1;
		*(int*)number -= 1;
	}
	if (*(int*)number == 0) pthread_exit(0);
	pthread_yield(NULL);
}
}

void* fib_out(void *number) {
while(1) {
	while(count != 0) {
		printf("%d ", buffer[fill_pos]);
		fill_pos = (fill_pos + 1) % buffer_size;
		count -= 1;
	}
	if (*(int*)number == 0) {
		printf("\n");
		fflush(stdout);
		pthread_exit(0);
	}
	pthread_yield(NULL);
}
}

int main() {
	int number = 20;
	pthread_t calc, out;
	pthread_create(&calc, NULL, fib_calc, (void*)&number);
	pthread_create(&out,  NULL, fib_out,  (void*)&number);
	pthread_join(out, NULL);
}
