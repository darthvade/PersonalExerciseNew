#include "matching.h"

int main(int argc, char *argv[]) {
	if(argv[1] == NULL) {
		printf("Please input a file name!\n");
	}
	matching(argv[1]);
	return 0;
}
