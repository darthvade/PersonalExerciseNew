#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
	fd_set rfds;
	fd_set wfds;

	struct timeval tv;
	int retval;

	FD_ZERO(&rfds);
	FD_SET(0, &rfds);

	FD_ZERO(&wfds);
	FD_SET(1, &wfds);


	tv.tv_sec = 5;
	tv.tv_usec = 0;

	retval = select(2, &rfds, &wfds, NULL, &tv);

/*	
	if(retval == -1) {
		perror("select()");
	} else if (retval) {
		printf("Data is available now.\n");
	} else {
		printf("No data within five seconds.\n");
	}
*/	
	
	char buf[128];
	memset(buf, 0, sizeof(buf));

	while(1) {
		int n = 0;
		if(FD_ISSET(1, &wfds)) {
			n = read(0, buf, 128);				
			//printf("read\n");
			//sleep(1);
			write(1, buf, n);
		} 
		/*
		if(FD_ISSET(1, &wfds)) {
			write(1, buf, n);
			printf("write\n");
			sleep(1);
		}
		*/
	}

	exit(EXIT_SUCCESS);

}
