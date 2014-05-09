#include "/usr/lib/MyLibs/header/rio.h"
#include <stdio.h>

int main() {

	char readbuf[1024];

	int fd = open("./input.dat", O_RDONLY);
	rio_t buf;
	rio_readinitb(&buf, fd);
	int  n;
	/*
	n = rio_readlineb(&buf, readbuf, sizeof(readbuf));

	printf("%d\n", n);
	printf("%s\n", readbuf);
	*/
	n = rio_readnb(&buf, readbuf, sizeof(readbuf));

	printf("%d\n", n);
	printf("%s", readbuf);
	
	return 0;
}
