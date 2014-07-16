#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
	int fd;
	fd = open("./file.in", O_WRONLY);	
	//测试lssk的offset超过文件总长的情况
	lseek(fd, 1000, SEEK_END);
	sync();
	char input[] = "World";
	write(fd, input, 5);
	close(fd);
	return 0;
}
