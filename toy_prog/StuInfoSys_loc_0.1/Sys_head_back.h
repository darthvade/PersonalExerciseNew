#ifndef _SYS_HEAD_BACK_H_
#define _SYS_HEAD_BACK_H_

/*-----------------------------------------------------------------------------------*/
/*测试用*/

/*-----------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*-----------------------------------------------------------------------------------*/

#define LEN_STU_NAME 32 /*学生姓名_字符串_最大长度*/
#define LEN_STU_MAJOR 32 /*学生专业_字符串_最大长度*/

#define LEN_SCORE_CLASS_NAME 32 /*学生成绩_课程名_字符串_最大长度*/
#define LEN_SCORE_MAX_CLASS_NUM 4 /*学生成绩_最大课程数*/

#define LEN_INDEX_MAX 1024 /*索引表长度*/

/*-----------------------------------------------------------------------------------*/

struct Score {
	char c_name[LEN_SCORE_MAX_CLASS_NUM][LEN_SCORE_CLASS_NAME]; /*各科课程名*/
	double c_score[LEN_SCORE_MAX_CLASS_NUM]; /*各科成绩*/
	double c_total_avg_score; /*个人平局成绩*/
}; /*学生成绩*/

struct Student {
	int s_id; /*学号*/
	char s_name[LEN_STU_NAME]; /*姓名*/
	int s_age; /*年龄*/
	int s_grade; /*年级*/
	int s_class; /*班级*/
	char s_major[LEN_STU_MAJOR]; /*专业*/
	struct Score s_score; /*成绩*/
}; /*学号信息*/

struct InfoNode {
	struct Student *i_ps; /*指向一个学生信息*/
	struct InfoNode *next;	/*指向下一个信息结点*/
}; /*信息结点*/

struct IndexNode {
	int id; /*学生学号*/
	struct Student *i_ps; /*指向一个学生信息*/
}; /*索引表元素*/

typedef struct Student StuInfo;
typedef struct Score ScoreInfo;
typedef struct InfoNode InfoNode;
typedef struct InfoNode * LinkInfo;
typedef struct IndexNode IndexTable;

IndexTable MainIndex[LEN_INDEX_MAX]; /*存储所有学生信息结点的指针信息*/

/*-----------------------------------------------------------------------------------*/

void init_info_main_list(LinkInfo *L); /*初始化信息总表*/

void read_all_info_from_file(char *filename, LinkInfo Lmain); /*读出文件中的所有信息并插入信息总表*/

void write_all_info_into_file(char *filename, LinkInfo Lmain); /*将所有信息从信息总表写入文件*/

void insert_new_info_into_list(LinkInfo Lmain, StuInfo *insert_info); /*将一个新元素插入信息总表*/

void delete_info_from_list(LinkInfo Lmain, int del_id); /*删除信息总表中指定学号的学生信息*/

void update_info_in_list(LinkInfo Lmain, int del_id, StuInfo *update_info); /*更新信息总表中指定学号的学生信息*/

void search_info_from_list(LinkInfo Lmain, int del_id, StuInfo *search_info); /*查找信息总表中指定学号的学生信息*/

void update_index_table(LinkInfo Lmain, IndexTable *index, int *real_info_len); /*更新索引表信息*/

void reverse_main_list(LinkInfo Lmain); /*逆置信息总表*/

void debug_main_list(LinkInfo Lmain); /*打印信息总表的所有信息*/

void debug_main_index(IndexTable *main_index, int *index_real_len); /*打印信息总索引表链接的所有信息*/

void free_info_main_list(LinkInfo *L); /*销毁内存中学生信息*/

/*-----------------------------------------------------------------------------------*/

#endif












