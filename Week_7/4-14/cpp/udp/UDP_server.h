#ifndef __UDP_SERVER_H__
#define __UDP_SERVER_H__

#include <iostream>
#include <cstdio>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <cstring>
#include <cstdlib>
#include <unistd.h>

#define BUF_SIZE 1024

typedef struct sockaddr SA;

class UDPServer {
	public:
		UDPServer(int port);
		~UDPServer();
		std::string receive();
		void send(const std::string&);
	private:
		int _sockfd;
		struct sockaddr_in _servaddr;
		struct sockaddr_in _cliaddr;
		int _servport;
		void _bind();
};

#endif
