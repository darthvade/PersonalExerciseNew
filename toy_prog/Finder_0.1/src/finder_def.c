#include "../include/finder.h"

void printdir(const char *dir, const int depth) {
	DIR *dp;
	struct dirent *entry;//存储目录项
	struct stat statbuf;//存储文件项
	if((dp = opendir(dir)) == NULL) {
		fprintf(stderr, "can NOT open directory : %s\n", dir);
		return;	
	}
	chdir(dir);
	while((entry = readdir(dp)) != NULL) {
		lstat(entry->d_name, &statbuf); //读取文件项信息
		if(S_ISDIR(statbuf.st_mode)) {
			/*忽略当前目录和父目录*/
			if(strcmp(entry->d_name, ".") == 0||
			   strcmp(entry->d_name, "..") == 0) {
				continue;
			}
			printf("%*s%s/\n", depth, "", entry->d_name);
			/*递归搜索*/	
			printdir(entry->d_name, depth + 4);
		} else {
			printf("%*s%s\n", depth, "", entry->d_name);
		}
	}
	chdir("..");
	closedir(dp);
}

void find(const char *dir, const char *find_file) {
	DIR *dp;
	struct dirent *entry;//存储目录项
	struct stat statbuf;//存储文件项
	if((dp = opendir(dir)) == NULL) {
		fprintf(stderr, "can NOT open directory : %s\n", dir);
		return;	
	}
	chdir(dir);
	while((entry = readdir(dp)) != NULL) {
		lstat(entry->d_name, &statbuf); //读取文件项信息
		if(S_ISDIR(statbuf.st_mode)) {
			/*忽略当前目录和父目录*/
			if(strcmp(entry->d_name, ".") == 0||
			   strcmp(entry->d_name, "..") == 0) {
				continue;
			}
			//printf("%*s%s/\n", depth, "", entry->d_name);
			if(strcmp(entry->d_name, find_file) == 0) {
				printf("This dir is exiting in this dirctory.\n");
			}
			/*递归搜索*/	
			//printdir(entry->d_name, depth + 4);
			find(entry->d_name, find_file);
		} else {
			//printf("%*s%s\n", depth, "", entry->d_name);
			if(strcmp(entry->d_name, find_file) == 0) {
				printf("This file is exiting in this dirctory.\n");
			}
		}
	}
	chdir("..");
	closedir(dp);
}
