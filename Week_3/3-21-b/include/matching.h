#ifndef _MATCHING_H_
#define _MATCHING_H_

#include <stdio.h>
#include <iostream>
#include <stack>

struct Bracket {
	char data;
	int len;
	int pos;
};

typedef struct Bracket Bracket;

void matching(char *filename);

#endif
