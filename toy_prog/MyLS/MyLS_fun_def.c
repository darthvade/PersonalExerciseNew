#include "MyLS_head.h"


void list_files(char *filename) {
	DIR *pd;
	pd = opendir(filename);
	struct dirent *fdir;
	int count = 0;
	while((fdir = readdir(pd)) != NULL) {
		if(strcmp(fdir->d_name, ".") && strcmp(fdir->d_name, "..")) {
			count++;
			printf("%s", fdir->d_name);
			printf("  ");
		}
		if(count == 4) {
			putchar('\n');		
		}
	}
	putchar('\n');
	closedir(pd);
}


