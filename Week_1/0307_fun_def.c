#include"0307_head.h"

void String_sort() {
	char input[M][N];
	int count = 0;
	int i;
	while(scanf("%s", input[count++]) != EOF) {}
	Straight_insertion_sort(input, 0, count - 1);
	printStrings(input, 0, count - 1);
}

void Straight_insertion_sort(char a[][N], const int start, const int end) {
	int i;
	int j;
	char temp[N];
	for(i = start + 1; i < end; i++) {
		strcpy(temp, a[i]);
		for(j = i - 1; strcmp(a[j], temp) > 0 && j >= start; j--) {
			strcpy(a[j + 1], a[j]);
		}
		strcpy(a[j + 1], temp);
	}
}

void printStrings(char a[][N], const int start, const int end) {
	int i;
	for(i = 0; i < end; i++) {
		printf("%d --> %s\n", i, a[i]);
	}
}

void searchString(char *filename, char *search) {
	char input[M][N];
	int i = 0;
	int count = 1;
	freopen(filename, "rb", stdin);
	while(scanf("%s", input[i]) != EOF) {
		if(strcmp(input[i], search) == 0) {
			printf("%d --> %d  -->  %s\n", count++, i + 1, input[i]);
		}
		i++;
	}
	freopen("CON", "rb", stdin);
	if(count == 0) {
		printf("No result!\n");
	}
}

void searchString_V2(char *filename, char *search) {
	/*char input[M][N];
	unsigned char signal[M] = {0};
	int i = 0;
	int count = 1;
	freopen(filename, "rb", stdin);
	while(scanf("%s", input[i]) != EOF) {
		if(strcmp(input[i], search) == 0) {
			printf("%d --> %d  -->  %s\n", count++, i + 1, input[i]);
			signal[i] = 1;
		}
		i++;
	}
	freopen("CON", "rb", stdin);
	for(i = 0; i < count; i++) {
		if(signal[i] == 1) {
			printf("%d --> %s\n", i, input[i]);
		}
	}
	if(count == 0) {
		printf("No result!\n");
	}*/
}