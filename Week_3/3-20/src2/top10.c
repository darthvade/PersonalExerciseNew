#include "sort.h"
#include <time.h>

int main(int argc, char *argv[]) {
	int input[] = {5, 6, 3, 9, 4};
	heap_sort(input, 5);
	printInput(input, 5);	
	return 0;
}
