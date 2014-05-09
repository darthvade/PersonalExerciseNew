#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	if(argc != 2) {
		perror("wrong arguments!");
	}
	unsigned long int i;
	i = strtoul(argv[1], NULL, 0);
	//printf("%lx\n", i);	
	unsigned long int temp;
	int n = 4;
	while(n) {
		temp = i & (0xff000000);
		temp = temp >> 24;
		printf("%ld", temp);
		if(n != 1) {
			putchar('.');
		}
		i = i << 8;
		n--;
	}	
	putchar('\n');
	return 0;
}
