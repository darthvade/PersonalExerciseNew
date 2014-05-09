#include "tcp.h"

int open_clientfd(char *hostaddr, int port) {
	int clientfd;
	struct sockaddr_in serveraddr;
	struct in_addr haddr;
	
	if((clientfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		return -1;
	}

	bzero((void *)&serveraddr, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	if(inet_aton(hostaddr, &haddr) < 0) {
		return -1;
	}
	bcopy((char *)&haddr, (char *)&serveraddr.sin_addr.s_addr, sizeof(haddr));
	serveraddr.sin_port = htons((unsigned short)port);
	
	if(connect(clientfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
		return -1;	
	}

	return clientfd;
} //打开客户端描述符

int open_listenfd(int port) {
	int listenfd, optval = 1;
	struct sockaddr_in serveraddr;

	if((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		return -1;
	}
	
	if(setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, (const void *)&optval, sizeof(int)) < 0) {
		return -1;
	}

	bzero((char *)&serveraddr, sizeof(serveraddr));	
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
	serveraddr.sin_port = htons((unsigned short)port);
	if((bind(listenfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr))) < 0) {
		return -1;
	}

	if(listen(listenfd, LISTENQ) < 0) {
		return -1;
	}
	
	return listenfd;
} //打开监听描述符

void ser_action(int connfd, const char *filename) {
	int n;
	char ser_buf[1024];
	/*
	while((n = read(connfd, ser_buf, sizeof(ser_buf))) != 0) {
		printf("server received %d bytes\n", n);	
		
		int i;
		for(i = 0; i < n; i++) {
			ser_buf[i] = toupper(ser_buf[i]);
		}

		write(connfd, ser_buf, n);
	}	
	*/

	/*解决下载进度问题*/
	struct stat file_info;
	if(stat(filename, &file_info) < 0) {
		printf("stat error!\n");
		return;
	}
	//printf("%ld\n", file_info.st_size);
	write(connfd, &file_info, sizeof(file_info));
	/*解决下载进度问题*/



	time_t timer_begin;
	time_t timer_end;
	double time_used;

	int filefd;
	if((filefd = open(filename, O_RDWR)) < 0) {
		printf("open error!\n");
		return;
	}	
	int count = 0;
	timer_begin = time(NULL); //开始传输时间
	while((n = read(filefd, ser_buf, sizeof(ser_buf))) > 0) {
		write(connfd, ser_buf, n);	
	//	printf("%d\n", n);
		count = count + n;
	}
	timer_end = time(NULL); //结束传输时间
	time_used = difftime(timer_end, timer_begin);
	printf("sum :%d B\n", count);
	printf("sum :%d KB\n", count / 1024);
	printf("sum :%d MB\n", count / (1024 * 1024));
	printf("Time used:%.2f s\n", time_used);
	printf("Trans Speed:%.2f KB/s\n", (count / 1024) / time_used);
	printf("Trans Speed:%.2f MB/s\n", (count / (1024 * 1024)) / time_used);

	close(filefd);



} //服务器逻辑
