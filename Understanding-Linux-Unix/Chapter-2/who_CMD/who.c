/*
 *	显示用户登录状态
 */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <utmp.h>
#include <time.h>

void show_info(struct utmp *);

int main() {
	struct utmp utmpbuf;
	int fd_utmp;

	//打开utmp文件
	if((fd_utmp = open(UTMP_FILE, O_RDONLY)) == -1) {
		perror(UTMP_FILE);
		_exit(1);
	}

	//读取utmp文件
	while(read(fd_utmp, &utmpbuf, sizeof(utmpbuf)) == sizeof(utmpbuf)) {
		show_info(&utmpbuf);	
	}

	close(fd_utmp);

	return 0;
}

//打印用户详细信息
void show_info(struct utmp * input) {
	if(input->ut_type != USER_PROCESS) {
		return;
	}
	printf("%-8.8s ", input->ut_user);	
	printf("%-8.8s ", input->ut_line);	
	printf("%-8s", ctime(&input->ut_tv.tv_sec) + 4);	
	#ifdef SHOW_HOST
	printf("%-8s ", input->ut_host);	
	#endif
	//printf("\n");
}

