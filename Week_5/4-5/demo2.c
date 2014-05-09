#include <stdio.h>
#include <pthread.h>

int ticketcount = 10;

void *salewinds1(void *args) {
	while(ticketcount > 0) {
		printf("windows1 start sale ticket! the ticket is: %d\n", ticketcount);
		sleep(1);
		ticketcount--;
		printf("sale ticket finish! the last ticket is: %d\n", ticketcount);
		putchar('\n');
	}
}

void *salewinds2(void *args) {
	while(ticketcount > 0) {
		printf("windows2 start sale ticket! the ticket is: %d\n", ticketcount);
		sleep(2);
		ticketcount--;
		printf("sale ticket finish! the last ticket is: %d\n", ticketcount);
		putchar('\n');
	}
}

int main() {
	pthread_t pth_id1;
	pthread_t pth_id2;
	pthread_create(&pth_id1, NULL, salewinds1, NULL);
	pthread_create(&pth_id2, NULL, salewinds2, NULL);
	pthread_join(pth_id1, NULL);
	pthread_join(pth_id2, NULL);
	return 0;
}
