#include <arpa/inet.h> //inet_pton
#include <sys/socket.h> //socket
#include <netinet/in.h> //struct sockaddr_in
#include <string.h> //bzero
#include <unistd.h> //read & write
#include <sys/wait.h> //waitpid
#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

void signal_handler(int sig) {
	while(waitpid(-1, 0, WNOHANG) > 0) {}
	return;
}

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
	
	signal(SIGCHLD, signal_handler);

	listen(fd, 20);

	int acfd = 0;
	while(1) {
		acfd = accept(fd, nullptr, nullptr);

		if(fork() == 0) {	
			close(fd);
			char buffer[1024] = {0};
			int getn = readn(acfd, buffer, sizeof(buffer));
			printf("getn=%d\n", getn);	
			printf("%s\n", buffer);
			string s(buffer);	
			cout << "RECEIVED MSG: " << s << endl;
			cout << "RECEIVED MSG LEN: " << s.length() << endl;
			close(acfd);
			exit(0);
		}
		
		close(acfd);	
	}

	return 0;
}
