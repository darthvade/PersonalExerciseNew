#ifndef __UDPCLIENT_H__
#define __UDPCLIENT_H__

#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>
#include <unistd.h>
#include <cstdlib>

#define BUF_SIZE 1024

class UDPclient {
public:
	typedef const std::string cst;
	UDPclient();
	~UDPclient();
	ssize_t recvMsg(std::string &msg); //客户端接受消息
	ssize_t sendMsg(cst &ip, cst &port, cst &msg); //客户端按地址发送消息
private:
	int _fd_client; //客户端socket
	char _buf[BUF_SIZE]; //客户端缓冲区	
	struct sockaddr_in _server_addr; //服务端信息
};

#endif
