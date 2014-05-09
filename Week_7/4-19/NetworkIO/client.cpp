#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <cstdlib>
#include <arpa/inet.h>
#include <iostream>
#include <unistd.h>
#include <cstring>
#include <string>

using namespace std;

typedef struct sockaddr SA;

int main(int argc, char *argv[]) {

	int clientfd;
	clientfd = socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in seraddr;
	bzero(&seraddr, sizeof(seraddr));
	seraddr.sin_family = AF_INET;
	inet_aton(argv[1], &seraddr.sin_addr);
	seraddr.sin_port = htons(atoi(argv[2]));
	connect(clientfd, (SA *)&seraddr, sizeof(seraddr));

	//event
	char buf[1024];
	string str;
	cin >> str;
	strcpy(buf, str.c_str());
	write(clientfd, buf, strlen(buf) + 1);
	int n = read(clientfd, buf, sizeof(buf));
	cout << buf << n << endl;

	close(clientfd);
	return 0;
}
