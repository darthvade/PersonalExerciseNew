#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#define MAXLINE 80

int main() {
	int n;
	int fd[2];
	pid_t pid;
	char line[MAXLINE];
	if(pipe(fd) < 0) {
		perror("pipe error\n");
		exit(-1);
	}
	if((pid = fork()) < 0) {
		perror("fork\n");
		exit(-1);
	}
	if(pid > 0) {
		close(fd[0]);
		write(fd[1], "Hello world!\n", 13);
		wait(NULL);	
	} else {
		close(fd[1]);
		n = read(fd[0], line, MAXLINE);
		write(STDOUT_FILENO, line, n);	
	}
	return 0;
}
