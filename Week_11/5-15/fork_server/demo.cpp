#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

using namespace std;

void func_waitpid(int i) {
	pid_t pid;
	while((pid = waitpid(-1, NULL, WNOHANG))) {
	
	}
	return;
}

int main() {

	//signal(SIGCHLD, &func_waitpid);

	pid_t pid;

	if((pid = fork()) > 0) {
		cout << "father!" << endl;
		sleep(1000);	
	} else {
		cout << "son!" << endl;
	}

	return 0;
}
