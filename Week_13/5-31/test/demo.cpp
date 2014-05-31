#include <cstdio>
int main() {

	char a[2][2][3] = {{{1, 2, 3}, {4, 5, 6}}, {{7, 8, 9}, {10, 11, 12}}};
	for(int i = 0; i < 12; ++i) {
		printf("%d\n", *((char *)a + i));	
	}

	return 0;
}
