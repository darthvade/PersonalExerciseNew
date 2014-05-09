#include <stdio.h>
#include <string.h>

#define SQR(X) X*X
int main(int argc, char* argv[])
{
		int a = 10;
		int k = 2;
		int m = 1;a /= SQR(k+m)/SQR(k+m);
		printf("%d\n",a);
		return 0;
}
