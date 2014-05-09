/**
* exercise of some C's feature
*/
#include<stdio.h>
#include<string.h>
int main(){
	int i = 0;
	char *s = "Hello";
	printf("%d\n", strlen(s));	
	//printf("%d\n", sizeof(*s));	
	while(*s != '\0'){
		i = i + sizeof(*s);
		s++;
	}
	printf("%d\n", i);	
}
