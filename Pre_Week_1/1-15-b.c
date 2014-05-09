/**
* A File Copy Program
*/

#include<unistd.h>//read,write,close
#include<fcntl.h>//open
#include<stdlib.h>

int main() {
	char c;//单字节缓冲区
	char buf[1024];//1KB缓冲区
	int in, out;
	int nread;
	
	in = open("file.in", O_RDONLY);	
	out = open("file.out", O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);
	while((nread = read(in, buf, sizeof(buf))) > 0) {
		write(out, buf, nread);
	}
}
