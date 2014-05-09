#include "stack.h"

int main() {

	int output;
	int top_elem;
	Stack st;
	init_stack(&st);
	push(st, 89);
	push(st, 77);
	push(st, 56);
	debug(st);
	pop(st, &output);
	debug(st);
	printf("%d\n", top(st, &top_elem));
	debug(st);
	clear(st);
	debug(st);
	destory_stack(&st);
	debug(st);

	system("pause");
	return 0;
}