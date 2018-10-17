#include <stdio.h>
#include <string.h>

int main() {
	FILE *file = fopen("Lab 09 input.txt", "r");

	int frames;
	scanf("%d", &frames);

	int page_numbers[frames];
	memset(page_numbers, 0, frames*sizeof(int));
	int page_counters[frames];
	memset(page_counters, -1, frames*sizeof(int));

	int page;
	int hits = 0, misses = 0, total = 0;
	int free_pos = 0;
	while (fscanf(file, "%d", &page) != EOF) {
		++total;
		for (int i = 0; i < frames; ++i)
			page_counters[i] >>= 1;
		char found = 0;
		for (int i = 0; i < frames; ++i)
			if (page == page_numbers[i]) {
				++hits;
				page_counters[i] |= 1 << (sizeof(int)*8 - 1);
				found = 1;
				break;
			}
		if (found) continue;
		++misses;
		if (free_pos < frames) {
			page_numbers[free_pos] = page;
			page_counters[free_pos] = 1 << (sizeof(int)*8 - 1);
			++free_pos;
		} else {
			int min_pos = page_numbers[0];
			int min = page_counters[0];
			for (int i = 1; i < frames; ++i)
				if (page_counters[i] < min) {
					min = page_counters[i];
					min_pos = i;
				}
			page_numbers[min_pos] = page;
			page_counters[min_pos] = 1 << (sizeof(int)*8 - 1);
		}
	}
	printf("Hit/Miss ratio: %f\n", (double)hits/misses);
	return 0;
}
