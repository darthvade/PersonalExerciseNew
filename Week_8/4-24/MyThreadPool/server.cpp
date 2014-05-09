/*没有错误处理
 *
 */

#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstdlib>
#include <cstring>
#include "Threadpool.h"

#include <cerrno>

using namespace std;

typedef sockaddr SA;

int main(int argc, char *argv[]) {


//	Threadpool pool(8);
//	pool.start_threadpool();


	int serverfd;
	serverfd = socket(AF_INET, SOCK_STREAM, 0);


	struct sockaddr_in myaddr;
	bzero(&myaddr, sizeof(myaddr));
	myaddr.sin_family = AF_INET;
	myaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	myaddr.sin_port = htons(atoi(argv[1]));
	bind(serverfd, (SA *)&myaddr, sizeof(myaddr));
	

	listen(serverfd, 1024); //主动套接字->监听套接字

	
	int connfd;
	struct sockaddr_in cliaddr;
	//socklen_t cliaddrlen;
	socklen_t cliaddrlen = sizeof(cliaddr);
	bzero(&cliaddr, sizeof(cliaddr));
	connfd = accept(serverfd, (SA *)&cliaddr, &cliaddrlen);

	cout << "accept --> " << connfd << endl;
	cout << errno << endl;

	//event
	char buf[1024];
	int n;
	Threadpool pool(8);
	pool.start_threadpool();
	cout << "strated pool" << endl;

	while(true) {
		n = read(connfd, buf, 1024);	
//		cout << n << "+++end+++" << endl;
		buf[n - 1] = '\0';
		if(n > 0) {
			Task temp;
			string str(buf, n - 1);
			temp.solve = str;
//			cout << temp.solve << "+++end+++" << endl;
			pool.add_task_queue(temp);
		}
	}

	close(serverfd);
	close(connfd);
	return 0;
}
