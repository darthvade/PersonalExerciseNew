#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
	pid_t pid;
	char message[128];
	int n;
	pid = fork();
	if(pid < 0) {
		perror("fork failed");
		exit(-1);
	}
	if(pid == 0) {
		strncpy(message, "child", 128);
		n = 6;
	} else {
		strncpy(message, "parent", 128);
		n = 3;
	}
	for(; n > 0; n--) {
		printf("%s\n", message);
		sleep(1);
	}
	return 0;
}
