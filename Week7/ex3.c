#include <stdio.h>
#include <stdlib.h>

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
