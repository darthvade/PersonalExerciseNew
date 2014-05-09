#include "stu_sort.h"

void stu_avg(char *fileinput, char *fileoutput, double *sortarray) {
	if(fileinput == NULL || fileoutput == NULL) {
		return;
	}
	int i = 0;
	char temp[LEN_SCORE];
	FILE *fpin = fopen(fileinput, "r");
	FILE *fpout = fopen(fileoutput, "w");
	while(fgets(temp, LEN_SCORE, fpin) != NULL) {
		int a = 0;
		int b = 0;
	   	int c = 0;
	   	int d = 0;
	   	int e = 0;
		int num = sscanf(temp, "%d %d %d %d %d", &a, &b, &c, &d, &e);	
		sortarray[i] = a + b + c + d + e / num;
		i++;
		fprintf(fpout, "%f --> ID.%d\n", sortarray[i - 1], i);
	}
	fclose(fpin);
	fclose(fpout);
}
