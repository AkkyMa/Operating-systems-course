#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

void* realloc(void* ptr, size_t size) {
	if (size != 0) {
		void* nptr = malloc(size);
		size_t oldsize = malloc_usable_size(ptr);
		size_t clen = size < oldsize ? size : oldsize;
		memcpy(nptr, ptr, clen);
		free(ptr);
		return nptr;
	} else {
		free(ptr);
		return NULL;
	}
}

int main() {
	int N;
	scanf("%d", &N);

	int *arr = malloc(N*sizeof(int));
	for (int i = 0; i < N; ++i)
		arr[i] = i;

	for (int i = 0; i < N; ++i)
		printf("%d ", arr[i]);
	printf("\n");

	int K;
	scanf("%d", &K);

	arr = realloc(arr, K*sizeof(int));
	for (int i = N; i < K; ++i)
		arr[i] = i;

	for (int i = 0; i < K; ++i)
		printf("%d ", arr[i]);
	printf("\n");

	free(arr);
}
