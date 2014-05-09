#include<stdio.h>
#include<stdlib.h>

int main() {

	while(1) {
		system("clear");
		int manu;
		printf("op 1\n");
		printf("op 2\n");
		printf("exit 5\n");
		printf("Your option:");
		scanf("%d", &manu);
		switch(manu) {
			case 1:
				while(1) {
					system("clear");
					printf("____1____\n");
					int exit;
					printf("choose 1 to exit:");
					scanf("%d", &exit);
					system("clear");
					if(exit == 1) {
						break;
					}
				}
				break;
			case 2:
				while(1) {
					system("clear");
					printf("____2____\n");
					int exit;
					printf("choose 2 to exit:");
					scanf("%d", &exit);
					system("clear");
					if(exit == 2) {
						break;
					}
				}
				break;
			default:
				system("clear");
				printf("___exit___\n");
				break;
		}
		if(manu == 5) {
			break;
		}
	}
	return 0;
}
