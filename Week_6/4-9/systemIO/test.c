#include "rio.h"
#include <stdio.h>

int main() {

	char input[] = "Hello world!";
	rio_writen(STDIN_FILENO, input, sizeof(input) - 1);

	printf("\n%d\n", sizeof(input));

	int fd = open("input.dat", O_RDONLY);

	ssize_t n;
	n = rio_readn(fd, input, sizeof(input));

	printf("%d\n", n);
	printf("%s\n", input);

	char input2[] = {'a', 'b', '\0', 'c', 'd', '\0', 'd', '\0'};

	printf("%s\n", input2);

	return 0;
}
