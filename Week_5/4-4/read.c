#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
	char szBuf[128];
	int fdFifo = open("fifo", O_RDONLY);
	if(read(fdFifo, szBuf, sizeof(szBuf)) > 0) {
		puts(szBuf);
	}
	close(fdFifo);
	return 0;
}
