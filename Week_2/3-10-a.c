#include<stdio.h>
#include<sys/types.h>
#include<dirent.h>
int main() {
	DIR *pdir = opendir("../Week_2");
	struct dirent *p;
	while((p = readdir(pdir)) != NULL) {
		printf("%ld --> %ld --> %s\n", p->d_off, telldir(pdir), p->d_name);
	}
	putchar('\n');
	seekdir(pdir, 594842244);
	p = readdir(pdir);
	printf("%ld --> %s\n", telldir(pdir), p->d_name);
	closedir(pdir);
	return 0;		
}
