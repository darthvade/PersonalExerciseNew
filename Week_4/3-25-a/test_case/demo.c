#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define TOP 10

#define LEN 16

#define UNCERTAIN 100000

void init_files(char *configure) {
	char output[TOP][LEN];
	if(configure == NULL) {
		return;
	}	
	FILE *fp = fopen(configure, "r");
	int i = 0;
	while(fscanf(fp, "%s", output[i]) != EOF) {
		i++;
	}
	int num_file = TOP;
	srand((unsigned)time(NULL));
	while(num_file--) {
		FILE *ffp = fopen(output[num_file], "w");
		int init_num = UNCERTAIN;
		while(init_num--) {
			fprintf(ffp, "%d\n", rand() % UNCERTAIN);	
		}
		fclose(ffp);
	} 	
	fclose(fp);
}

int main(int argc, char *argv[]) {

	init_files(argv[1]);

	return 0;
}
