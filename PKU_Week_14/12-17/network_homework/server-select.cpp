/*
 * 仅仅复用服务器的标准输入和链接描述符
 *
 */
#include <arpa/inet.h> //inet_pton
#include <sys/socket.h> //socket
#include <netinet/in.h> //struct sockaddr_in
#include <string.h> //bzero
#include <unistd.h> //read & write
#include <sys/wait.h> //waitpid
#include <iostream>
#include <string>
#include <cstdio>
#include <sys/select.h>

using namespace std;

ssize_t readn(int fd, void *vptr, size_t n) {
	size_t nleft = n;
	ssize_t nread = 0;
	char *ptr = static_cast<char *>(vptr);
	while(nleft > 0) {
		if((nread = read(fd, ptr, nleft)) < 0) {
			if(errno == EINTR) {
				nread = 0;
			} else {
				return -1;	
			}
		} else if (nread == 0) {
			break;	
		}
		nleft -= nread;	
		ptr += nread;
	}
	return n - nleft;
}

int main(int argc, char* argv[]) {
	if(argc != 2) {
		return 1;
	}

	
	int fd = socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in addr;
	bzero(&addr, sizeof(addr));
	addr.sin_family = AF_INET;
	inet_pton(AF_INET, argv[1], &addr.sin_addr.s_addr);
	addr.sin_port = htons(8000);

	bind(fd, reinterpret_cast<struct sockaddr *>(&addr), sizeof(addr));
	
	//signal(SIGCHLD, signal_handler);

	listen(fd, 20);

	int acfd = 0;

	//define select set
	fd_set read_set, ready_set;
	FD_ZERO(&read_set);
	FD_SET(STDIN_FILENO, &read_set);
	FD_SET(fd, &read_set);
	
	while(1) {
		ready_set = read_set; //每次调用select之前更新set
		select(fd + 1, &ready_set, nullptr, nullptr, nullptr);
		//当监听描述符准备好
		if(FD_ISSET(fd, &ready_set)) {
			acfd = accept(fd, nullptr, nullptr);
			char buffer[1024] = {0};
			int getn = readn(acfd, buffer, sizeof(buffer));
			printf("getn=%d\n", getn);	
			printf("%s\n", buffer);
			string s(buffer);	
			cout << "RECEIVED MSG: " << s << endl;
			cout << "RECEIVED MSG LEN: " << s.length() << endl;
			close(acfd);	
		}
		//当标准输入准备好
		if(FD_ISSET(STDIN_FILENO, &ready_set)) {
			char buf[64] = {0};
			read(STDIN_FILENO, buf, sizeof(buf));
			printf("%s", buf);
		}		
	}

	return 0;
}
