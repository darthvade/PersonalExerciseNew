#include <stdio.h>
#include <pthread.h>

int ticketcount = 10;

pthread_mutex_t lock;

void *salewinds1(void *args) {
	while(1) {
		pthread_mutex_lock(&lock);
		if(ticketcount > 0) {
			printf("windows1 start sale ticket! the ticket is: %d\n", ticketcount);
			sleep(1);
			ticketcount--;
			printf("sale ticket finish! the last ticket is: %d\n", ticketcount);
			putchar('\n');
		}
		else {
			pthread_mutex_unlock(&lock);
			pthread_exit(NULL);
		}
		pthread_mutex_unlock(&lock);
		sleep(1);
	}
}

void *salewinds2(void *args) {
	while(1) {
		pthread_mutex_lock(&lock);
		if(ticketcount > 0) {
			printf("windows2 start sale ticket! the ticket is: %d\n", ticketcount);
			sleep(1);
			ticketcount--;
			printf("sale ticket finish! the last ticket is: %d\n", ticketcount);
			putchar('\n');
		}
		else {
			pthread_mutex_unlock(&lock);
			pthread_exit(NULL);
		}
		pthread_mutex_unlock(&lock);
		sleep(3);
	}
}

int main() {
	pthread_t pth_id1;
	pthread_t pth_id2;
	pthread_mutex_init(&lock, NULL);
	pthread_create(&pth_id1, NULL, salewinds1, NULL);
	pthread_create(&pth_id2, NULL, salewinds2, NULL);
	pthread_join(pth_id1, NULL);
	pthread_join(pth_id2, NULL);
	pthread_mutex_destroy(&lock);
	return 0;
}



