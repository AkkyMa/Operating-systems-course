#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

int main() {
	DIR *dp = opendir("tmp");
	struct dirent *direntry;

	long i_node_numbers[256];
	char filenames[256][30][256];
	int c = 0;
	int cs[256];
	memset(cs, 0, 256);

	while((direntry = readdir(dp)) != NULL) {
		int i;
		for (i = 0; i < c; ++i)
			if(direntry->d_ino == i_node_numbers[i]) break;
		if (i == c)
			i_node_numbers[c++] = direntry->d_ino;
		strcpy(filenames[i][cs[i]++], direntry->d_name);
	}

	for (int i = 0; i < c; ++i)
		if (cs[i] > 1) {
			printf("inode number: %ld\n", i_node_numbers[i]);
			for (int j = 0; j < cs[i]; ++j)
				printf("%s\n", filenames[i][j]);
		}
}
