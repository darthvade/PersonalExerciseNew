/**
* struct/union/enum
*/

#include<stdio.h>

typedef struct {
	int name;
	int age;
} Student;

typedef union {
	int whole;
	struct {char c1, c2, c3, c4;} byte;
} Num;

typedef enum {
	Monday = 1,
	Tuesday = 2,
	Wednesday = 3,
	Thursday,
	Friday,
	Saturday,
	Sunday
} Week;


int main(){

	Week w;
	w = Sunday;
	printf("Week = %d\n", w);

	Num n;
	n.whole = 65535;
	printf("whole = %d\n", n.whole);
	printf("c1 = %x\n", n.byte.c1);
	printf("c2 = %x\n", n.byte.c2);
	printf("c3 = %x\n", n.byte.c3);
	printf("c4 = %x\n", n.byte.c4);

	return 0;
}
