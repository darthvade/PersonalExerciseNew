#include<unistd.h>
#include<stdlib.h>
int main() {
	if(write(1, "hello world!\n", 13) != 13) {
		write(2, "some error", 20);		
	}		
	return 0;
}
