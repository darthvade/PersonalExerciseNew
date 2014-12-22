/*
 * 多个TCP连接描述符复用
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
#include <vector>
#include <list>
#include <cstdio>
#include <sys/select.h> //select

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
	
	listen(fd, 20);

	int acfd = 0;

	//define select set
	fd_set read_set, ready_set;
	FD_ZERO(&read_set);
	FD_SET(fd, &read_set);
	
	//描述符池
	list<int> fdpool;
	//将监听描述符放入描述符池
	fdpool.push_back(fd);
	//最大描述符
	int fd_max = fd;

	while(1) {
		ready_set = read_set; //每次调用select之前更新set
		select(fd_max + 1, &ready_set, nullptr, nullptr, nullptr);
		//当监听描述符准备好
		if(FD_ISSET(fd, &ready_set)) {
			acfd = accept(fd, nullptr, nullptr);
			//将连接描述符放入描述符池
			fdpool.push_back(acfd);
			//加入描述符集
			FD_SET(acfd, &read_set);
			//更新最大描述符
			if(acfd > fd_max) {
				fd_max = acfd;
			}
		}
		
		//处理已经准备好的描述符
		for(auto ifd = fdpool.begin(); ifd != fdpool.end(); ++ifd) {
			//不处理监听描述符
			if(*ifd == fd) {
				continue;
			}
			char buffer[1024] = {0};
			int getn = 0;
			if((getn = readn(*ifd, buffer, sizeof(buffer))) > 0) {
				printf("getn=%d\n", getn);	
				printf("%s\n", buffer);
				string s(buffer);	
				cout << "RECEIVED MSG: " << s << endl;
				cout << "RECEIVED MSG LEN: " << s.length() << endl;
			} else { //描述符失效时，可能是客户端断开连接
				close(*ifd);	
				FD_CLR(*ifd, &read_set);
				ifd = fdpool.erase(ifd); //删除元素时，需要更新迭代器！
			}
		}

	}

	return 0;
}
