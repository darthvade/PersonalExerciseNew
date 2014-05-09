#ifndef _SEARCH_H_
#define _SEARCH_H_
#include<stdio.h>
#include<Windows.h>
#include<string.h>

#define N 20
#define M 500

void String_sort();

void Straight_insertion_sort(char a[][N], const int start, const int end);

void printStrings(char a[][N], const int start, const int end);

void searchString(char *filename, char *search);

void searchString_V2(char *filename, char *search);

#endif