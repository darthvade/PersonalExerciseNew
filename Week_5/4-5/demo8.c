#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

int main() {
	char ip[] = "192.168.0.74";
	int r1, r2, r3;
	struct in_addr addr;

	r1 = inet_addr(ip); //返回网络字节序
	if(-1 == r1) {
		printf("inet_addr return -1\n");
	} else {
		printf("inet_addr ip: %d\n", r1);
	}

	r2 = inet_network(ip); //返回主机字节序
	if(-1 == r2) {
		printf("inet_addr return -1\n");
	} else {
		printf("inet_addr ip: %d\n", r2);
		printf("inet_addr ip: %d\n", ntohl(r2));
	}

	

}
