/**
*	practice of curses.h
*/

#include<curses.h>
#include<string.h>

int main(){
	char* one = " XXOO ";
	char* scan_ptr;
	
	initscr();
	move(5,15);
	attron(A_STANDOUT);
	printw("%s", "Hello World!");
	attroff(A_STANDOUT);
	refresh();
	sleep(1);
	
	attron(A_DIM);
	scan_ptr = one + strlen(one) - 1;
	while(scan_ptr != one){
		move(10,10);
		insch(*scan_ptr--);
		sleep(1);
		refresh();
	}
	attroff(A_DIM);
	while(1);
	endwin();
	return 0;
}
