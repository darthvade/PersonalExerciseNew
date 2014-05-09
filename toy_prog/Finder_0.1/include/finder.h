#ifndef _FINDER_H_
#define _FINDER_H_

#include<unistd.h>
#include<stdio.h>
#include<dirent.h>
#include<string.h>
#include<sys/stat.h>
#include<stdlib.h>

#define LEN_FILE_NAME 32

void printdir(const char *dir, const int depth);

void find(const char *dir, const char *find_file);

#endif
