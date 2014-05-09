#include "UDPclient.h"

UDPclient::UDPclient() {
	_fd_client = socket(AF_INET, SOCK_DGRAM, 0);
}

UDPclient::~UDPclient() {
	close(_fd_client);
}

ssize_t UDPclient::recvMsg(std::string &msg) {
	memset(_buf, 0, BUF_SIZE * sizeof(char));	
	recvfrom(_fd_client, _buf, 1024, 0, NULL, NULL);
	std::string temp(_buf, strlen(_buf)); 
	msg = temp;
	return msg.size();
}

ssize_t UDPclient::sendMsg(cst &ip, cst &port, cst &msg) {
	memset(&_server_addr, 0, sizeof(_server_addr));
	_server_addr.sin_family = AF_INET;
	_server_addr.sin_addr.s_addr = inet_addr(ip.c_str());
	_server_addr.sin_port = htons(atoi(port.c_str()));
	sendto(_fd_client, msg.c_str(), msg.size(), 0, (struct sockaddr *)&_server_addr, sizeof(_server_addr));
	return msg.size();
}
