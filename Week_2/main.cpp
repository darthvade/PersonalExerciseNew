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

	//std::cout << sizeof(p)<< std::endl;//���ָ���ͱ���p��ռ�ڴ�ռ�

	//std::cout << sizeof(a)<< std::endl;//���aָ��������ڴ�ռ�

	std::cout << free_array(p, 3) << std::endl;

	system("pause");
}