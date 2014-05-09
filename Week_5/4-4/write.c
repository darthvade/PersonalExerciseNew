#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
	int fdFifo = open("fifo", O_WRONLY);
	write(fdFifo, "Hello world", 12);
	close(fdFifo);
	return 0;
}
