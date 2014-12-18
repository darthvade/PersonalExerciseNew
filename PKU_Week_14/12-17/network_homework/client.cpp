#include <sys/socket.h> //socket
#include <netinet/in.h> //struct sockaddr_in
#include <string.h> //bzero
#include <arpa/inet.h> //inet_pton
#include <unistd.h> //write & read
#include <string>
#include <iostream>
#include <cstdio>

using namespace std;

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

	connect(fd, reinterpret_cast<struct sockaddr *>(&addr), sizeof(addr));

	char buffer[6553600] = {1};
	scanf("%s", buffer);
	cout << strlen(buffer) << endl;
	write(fd, buffer, strlen(buffer) + 6553600);	

	return 0;
}
