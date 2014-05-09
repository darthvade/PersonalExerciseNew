#include<stdio.h>
#include<stdlib.h>

extern char **environ;

int main() {

	int i;
	for(i = 0; environ[i] != NULL; i++) {
		printf("%s\n", environ[i]);
	}

	putchar('\n');

	char *env;
	env = getenv("HOME");
	printf("%s\n", env);

	return 0;
}
