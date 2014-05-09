#include "tcp.h"

int main(int argc, char *argv[]) {
	int clientfd, port;
	char *hostaddr, buf[1024];

	if(argc != 4) {
		fprintf(stderr, "usage: %s <host> <port>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	
	hostaddr = argv[1];
	port = atoi(argv[2]);

	clientfd = open_clientfd(hostaddr, port);

	//read(clientfd, buf, sizeof(buf));
	
	/*
	while(fgets(buf, sizeof(buf), stdin) != NULL) {
		write(clientfd, buf, strlen(buf) - 1);
		read(clientfd, buf, strlen(buf) - 1);	
		fputs(buf, stdout);
	}
	*/

	/*解决下载进度问题*/
	struct stat file_info;
	read(clientfd, &file_info, sizeof(file_info));
	//printf("%ld\n", file_info.st_size);
	//sleep(10);
	/*解决下载进度问题*/


	time_t timer_begin;
	time_t timer_end;
	double time_used;
	int n;
	int filefd = 0;
	double count = 0;
	if((filefd = open(argv[3], O_RDWR|O_CREAT, S_IRUSR|S_IWUSR)) < 0) {
		printf("open error!");
		return -1;
	} 
	timer_begin = time(NULL); //开始传输时间
	while((n = read(clientfd, buf, sizeof(buf))) != 0) {
		write(filefd, buf, n);	
		//printf("%d\n", n);
		printf("Trans Proessing %.2f %%... \r", (count / (double)file_info.st_size) * 100);
		count = count + n;
	}
	putchar('\n');

	close(filefd);

	timer_end = time(NULL); //结束传输时间
	time_used = difftime(timer_end, timer_begin);
	printf("sum :%d B\n", (int)count);
	printf("sum :%d KB\n", (int)count / 1024);
	printf("sum :%d MB\n", (int)(count / (1024 * 1024)));
	printf("Time used:%.2f s\n", time_used);
	printf("Trans Speed:%.2f KB/s\n", (count / 1024) / time_used);
	printf("Trans Speed:%.2f MB/s\n", (count / (1024 * 1024)) / time_used);


	close(clientfd);
	exit(EXIT_SUCCESS);
}
