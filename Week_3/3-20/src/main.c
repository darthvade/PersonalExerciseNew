#include "sort.h"
#include "quicksort.h"

int input[N];

int main(int argc, char *argv[]) {
	int count = 0;
	if(argc == 2 || argc == 1) {
		return 1;
	}
	FILE *fp = fopen(argv[1], "r+");
	while(fscanf(fp, "%d", &input[count++]) != EOF) {
	};
	switch(argv[2][0]) {
		case 'b':
			printf("Bubble_sort!\n\nresult:\n");	
			Bubble_sort(input, 0, count);
			printInput(input, count);
			break;
		case 's':
			printf("Sample_selection_sort!\n\nresult:\n");	
			Sample_selection_sort(input, 0, count);
			printInput(input, count);
			break;
		case 'i':
			printf("Straight_insertion_sort!\n\nresult:\n");	
			Straight_insertion_sort(input, 0, count);
			printInput(input, count);
			break;
		case 'h':
			printf("Shell_sort!\n\nresult:\n");	
			Shell_sort(input, 0, count);
			printInput(input, count);
			break;
		case 'q':
			printf("quick_sort!\n\nresult:\n");	
			quick_sort(input, 0, count);
			printInput(input, count);
			break;
		case 'p':
			printf("heap_sort!\n\nresult:\n");
			heap_sort(input, count);
			printInput(input, count);
			break;
		case '-':
			printf("'b' --> Bubble_sort\n");	
			printf("'s' --> Sample_selection_sort\n");	
			printf("'i' --> Straight_insertion_sort\n");	
			printf("'h' --> Shell_sort\n");	
			printf("'q' --> quick_sort\n");	
			printf("'p' --> heap_sort\n");	
			break;
	}
	fclose(fp);
}
