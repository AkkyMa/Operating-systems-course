#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* thread_info(void *id) {
	printf("Hi I'm thread with id %ld. Pls don't kill me\n", (long)id);
	pthread_exit(NULL);
}

int main() {
	pthread_t threads[10];
	int status;
	for (long i = 1; i <= 10; ++i) {
		status = pthread_create(threads+i-1, NULL, thread_info, (void*)i);
		if (status != 0) {
			printf("Error during creation a thread %d", status);
			exit(1);
		}
		pthread_join(threads[i-1], NULL);
	}

	return 0;
}
