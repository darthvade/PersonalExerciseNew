#ifndef __TCP_H__
#define __TCP_H__

#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <strings.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <sys/stat.h>

#define LISTENQ 10

int open_clientfd(char *hostaddr, int port); //打开客户端描述符

int open_listenfd(int port); //打开监听描述符

void ser_action(int connfd, const char *filename); //服务器逻辑
	
#endif
