#include <stdio.h>

#define print(str) printf("%s", str);
#define println(str) printf("%s\n", str);

typedef char * cstring;

int main() {
	char hehe[] = "hello world!";
	cstring cstr = hehe;
	cstring ko = "doubi";
	print(cstr);
	println(hehe);
	println(ko);
	return 0;
}
