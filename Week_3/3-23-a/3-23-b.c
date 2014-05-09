#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main() {

	printf("Running ps with execlp\n");
	execlp("../3-21-b/matching", "../3-21-b/matching", "../3-21-b/test_case/test_j_jc.dat", NULL);
	printf("Done!\n");
	exit(0);

}
