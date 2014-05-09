#ifndef _SYS_HEAD_ACCOUNT_H_
#define _SYS_HEAD_ACCOUNT_H_

/*-----------------------------------------------------------------------------------*/
/*测试用*/

/*-----------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Sys_head_back.h"

/*-----------------------------------------------------------------------------------*/

#define LEN_USER_NAME 32 /*用户ID_字符串_最大长度*/
#define LEN_USER_PASSWORD 32 /*用户密码_字符串_最大长度*/

#define PER_ADMIN 1 /*管理员权限*/
#define PER_USER 0 /*用户权限*/

/*-----------------------------------------------------------------------------------*/

struct User_account {
	char u_name[LEN_USER_NAME];
	int permission;
	char u_password[LEN_USER_PASSWORD];
	struct User_account *next;
}; /*账户信息*/

typedef struct User_account AccountNode;
typedef struct User_account * LinkAccount;

/*-----------------------------------------------------------------------------------*/

void init_account_list(LinkAccount *L); /*初始化账户信息表*/

void read_account_from_file(char *filename, LinkAccount Laccount); /*读出文件中所有账户信息*/

void write_account_into_file(char *filename, LinkAccount Laccount); /*写入所有账户信息到文件*/

void insert_new_account(LinkAccount Laccount, AccountNode *insert_account); /*增加新账户*/

void delete_account(LinkAccount Laccount, char *user_name); /*删除账户*/

void update_account(LinkAccount Laccount, char *user_name, AccountNode *update_account); /*更新账户信息*/

void search_account(LinkAccount Laccount, char *user_name, AccountNode *search_account); /*查找用户信息*/

void debug_account_list(LinkAccount Laccount); /*打印所有用户*/

void free_account_list(LinkAccount *L); /*销毁内存中账户信息*/

void input_password(char *password); /*密码输入*/

void admin_action(); /*管理员行为*/

void user_action(); /*普通用户行为*/

void add_new_stu_info(); /*增加学生信息*/

void delete_stu_info(); /*删除学生信息*/

void update_stu_info(); /*修改学生信息*/

void search_stu_info(); /*查找学生信息*/

void add_new_user(); /*增加账户信息*/

void delete_user(); /*删除账户信息*/

void update_user(); /*修改账户信息*/

void search_user(); /*查找账户信息*/

/*-----------------------------------------------------------------------------------*/


#endif








