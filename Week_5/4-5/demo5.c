#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <semaphore.h>

int ticketcount = 10;

sem_t lock;

void *chk1(void *args) {
	while(1) {
		sem_wait(&lock);
		if(ticketcount > 0) {
			printf("windows1 start sale ticket! the ticket is: %d\n", ticketcount);
			ticketcount--;
			sleep(3);
			printf("sale ticket finish!, the last ticket is: %d\n", ticketcount);
		} else {
			sem_post(&lock);
			sleep(1);
		}
		sem_post(&lock);
		sleep(1);
		putchar('\n');
	}
	pthread_exit(NULL);
}


void *chk2(void *args) {
	while(1) {
		sem_wait(&lock);
		if(ticketcount > 0) {
			printf("windows2 start sale ticket! the ticket is: %d\n", ticketcount);
			ticketcount--;
			sleep(3);
			printf("sale ticket finish!, the last ticket is: %d\n", ticketcount);
		} else {
			sem_post(&lock);
			sleep(1);
		}
		sem_post(&lock);
		sleep(1);
		putchar('\n');
	}
	pthread_exit(NULL);
}

int main() {
	pthread_t pthid1, pthid2;
	sem_init(&lock, 0, 1);
	pthread_create(&pthid1, NULL, chk1, NULL);
	pthread_create(&pthid2, NULL, chk2, NULL);
	pthread_join(pthid1, NULL);
	pthread_join(pthid2, NULL);
	sem_destroy(&lock);
}

