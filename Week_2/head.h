#ifndef _MACHING_H_
#define _MACHING_H_

#include <iostream>
#include <stack>
#include <Windows.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int is_matching_brackets(const char *input);//�ж������Ƿ�ƥ��@

int calc_re_polish(const char *input);//�����沨�����ʽ@

int **malloc_array(const int x, const int y);//��̬�����ά����

int free_array(int **input, const int x);//��̬�ͷŶ�ά����

#endif