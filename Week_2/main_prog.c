//#include "head_prog.h"
#include "Linklist.h"
int main(int argc, char *argv[]) {

	/*Student s[10] = {{1, "kevin", 14},
		{9, "tom", 19},
		{10, "lucy", 14},
		{2, "mike", 15},
		{5, "july", 14},
		{7, "lili", 17},
		{6, "kate", 14},
		{4, "jack", 12},
		{3, "cri", 14},
		{8, "bug", 10}
	};

	printstudent(s, 10);
	Bubble_sort(s, 0, 10, &cmp);
	printstudent(s, 10);*/

	/*int a[2][2] = {{1, 2}, {2, 3}};
	int b[2][3] = {{1, 2, 3}, {2, 3, 4}};
	int c[2][3];
	MutiMatrix(a, b, c);*/

	//testFunPointer();

	int input[] = {3, 8, 1, 2, 4};

	int get;

	Linklist list;
	init_list(&list);
	//create_list_head(list, input, 5);
	create_list_tail(list, input, 5);
	//insert_element(list, 8, 99);
	insert_element(list, 2, 99);
	debug(list);
	delete_element(list, 2);
	debug(list);

	//printf("%d\n", get_length(list));

	//printf("%d\n", is_empty(list));

	/*get_value(list, 1, &get);
	printf("%d\n", get);*/

	set_value(list, 1, 99);
	debug(list);

	//clear(list);
	//destory(&list);

	reverse(list);
	debug(list);

	system("pause");
	return 0;
}