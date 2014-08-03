#include <stdio.h>
#include <curses.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/select.h>

int main(int argc, char *argv[]) {
	if(argc != 2) {
		return 1;
	}
	int i = 0;
	int flag = 0;
	initscr();
	clear();
	for(;;) {
		struct timeval tc;
		tc.tv_sec = 0;
		tc.tv_usec = atoi(argv[1]);
		move(i, i * 2);
		if(i % 2 == 1) {
			standout();
		}
		addstr("Hello World!");
		if(i % 2 == 1) {
			standend();
		}
		refresh();
		//sleep(atoi(argv[1]));
		select(0, NULL, NULL, NULL, &tc);
		move(i, i * 2);
		addstr("            ");
		if(i == LINES) {
			flag = 1;
		}
		if(i == 0) {
			flag = 0;
		}
		if(flag == 0) {
			i++;
		} else {
			i--;
		}
	}
	endwin();
	return 0;
}
