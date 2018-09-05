#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void bubble_sort(int* array_begin, int* array_end) {

	void swap(int *i1, int *i2) {
		*i1 ^= *i2;
		*i2 ^= *i1;
		*i1 ^= *i2;
	}

	bool sorted = false;
	while(!sorted) {
		sorted = true;
		int* curPoint = array_begin;
		while(++curPoint != array_end) {
			if (*(curPoint-1) > *curPoint) {
				swap(curPoint-1, curPoint);
				sorted = false;
			}
		}
	}
}

int main(int argc, char* argv[]) {
	const int size = argc-1;
	int *arr = malloc(size * sizeof(int));
	for (int i = 0; i < size; ++i)
		arr[i] = atoi(argv[i+1]);

	bubble_sort(arr, arr+size);

	for (int i = 0; i < size; ++i)
		printf("%d ", arr[i]);
	printf("\n");

	return EXIT_SUCCESS;
}
