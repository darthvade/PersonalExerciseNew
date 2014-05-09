#include<unistd.h>
#include<stdlib.h>
int main() {

	execlp("ls", "ls", "-al", NULL);
	perror("exec ls");
	exit(1);
}
