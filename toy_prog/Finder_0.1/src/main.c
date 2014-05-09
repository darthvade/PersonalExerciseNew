#include "../include/finder.h"

int main(int argc, char *argv[]) {
	int opt;
	char findname[LEN_FILE_NAME];
	while((opt = getopt(argc, argv, "p:f:n:")) != -1) {
		switch(opt) {
			case 'p':
				printdir(optarg, 0);
				break;
			case 'n':
				strcpy(findname, optarg);	
			case 'f':
				find(optarg, findname);
				break;
			case ':':
				printf("option neeeds a dirname ! \n");
				break;
			case '?':
				printf("unknown option: %c \n", optopt);
				break;
		}
	}
	exit(0);
}
