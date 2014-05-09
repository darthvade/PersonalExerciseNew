#include "Sys_head_back.h"
#include "Sys_head_account.h"
//#include <curses.h>

LinkInfo Lmain; /*学生信息总表*/
LinkAccount Laccount; /*账户信息表*/

int main() {
	//LinkAccount Laccount; /*账户信息表*/
	AccountNode login_account; /*当前登录者信息*/
	init_account_list(&Laccount); /*初始化账户信息表*/
	init_info_main_list(&Lmain); /*初始化学生信息总表*/
	read_account_from_file("Account.db", Laccount); /*从文件读取用户信息*/
	read_all_info_from_file("Sys_Database.db", Lmain);
	while(1) {
		system("clear");
		printf("Student Infomation Management System V_0.1\n");
		putchar('\n');
		putchar('\n');
		printf("Login [or Enter \"exit\" to QUIT]:");
		scanf("%s", login_account.u_name);
		if(strcmp(login_account.u_name, "exit") == 0) {
			system("clear");
			break;
		}
		printf("\nPassword:");
		scanf("%s", login_account.u_password);//需要改成密码保护版本
		//这里放置密码输入函数
		//input_password(login_account.u_password);
		AccountNode search_user; /*查询账户信息*/
		memset(&search_user, 0, sizeof(AccountNode));
		search_account(Laccount, login_account.u_name, &search_user);
		if((strcmp(search_user.u_name, login_account.u_name) == 0) && (strcmp(search_user.u_password, login_account.u_password) == 0)) {
			system("clear");
			/*系统内部逻辑*/
			//printf("已进入系统！\n");
			if(search_user.permission == PER_ADMIN) {
				//printf("管理员 已进入系统！\n");
				admin_action();
			}
			if(search_user.permission == PER_USER) {
				//printf("普通用户 已进入系统！\n");
				user_action();
				//while(1);//测试用
			}
			/*系统内部逻辑*/
			//while(1);
		} else {
			continue;
		}
		
		//debug_main_list(Lmain);//测试用
		write_account_into_file("Account.db", Laccount);
		write_all_info_into_file("Sys_Database.db", Lmain);
	}
	return 0;
}
