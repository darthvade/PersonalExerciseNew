#include<stdio.h>
#include<string.h>

int main() {
	char buf[128] = "";
	int iret;
	while(memset(buf, 0, 128), (iret = read(0, buf, 128)) > 0) {
		buf[iret] = '\0';
		char cmd[128] = "";
		sprintf(cmd, "./%s", buf);
		system(cmd);
	}
	return 0;
}
