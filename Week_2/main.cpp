#include "head.h"

int main() {

	/*char input[] = "((3 + 3) * 6)) + ((9 + 10))";
	is_matching_brackets(input);*/

	/*char input[] = "623*42/++";
	std::cout << calc_re_polish(input) << std::endl;*/

	int **p;
	
	//int a[10];

	p = malloc_array(3, 4);

	//std::cout << p[2][3] << std::endl;

	//std::cout << sizeof(p)<< std::endl;//输出指针型变量p所占内存空间

	//std::cout << sizeof(a)<< std::endl;//输出a指向的整个内存空间

	std::cout << free_array(p, 3) << std::endl;

	system("pause");
}