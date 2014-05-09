#ifndef _MACHING_H_
#define _MACHING_H_

#include <iostream>
#include <stack>
#include <Windows.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int is_matching_brackets(const char *input);//判断括号是否匹配@

int calc_re_polish(const char *input);//计算逆波兰表达式@

int **malloc_array(const int x, const int y);//动态分配二维数组

int free_array(int **input, const int x);//动态释放二维数组

#endif