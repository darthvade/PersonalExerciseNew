#include "tcp.h"

int main(int argc, char *argv[]) {
	
	int listenfd, connfd, port, clientlen;
	struct sockaddr_in clientaddr;
	char *clientaddress;

	if(argc != 3) {
		fprintf(stderr, "usage: %s <port> <filename>\n", argv[0]);
	}

	port = atoi(argv[1]);

	listenfd = open_listenfd(port);

	while(1) {
		clientlen = sizeof(clientaddr);
		connfd = accept(listenfd, (struct sockaddr *)&clientaddr, (socklen_t *)&clientlen);
		clientaddress = inet_ntoa(clientaddr.sin_addr);
		printf("server connect to %s \n", clientaddress);

		ser_action(connfd, argv[2]);
		
		close(connfd);
	}

	exit(EXIT_SUCCESS);
}
