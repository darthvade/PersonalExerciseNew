#include "Sys_head_account.h"

extern LinkInfo Lmain;

extern LinkAccount Laccount;

void init_account_list(LinkAccount *L) {
	(*L) = (AccountNode *)malloc(sizeof(AccountNode));
	(*L)->next = NULL;
} /*初始化账户信息表*/

void read_account_from_file(char *filename, LinkAccount Laccount) {
	AccountNode *insert;
	FILE *fp;
	fp = fopen(filename, "r");
	while(1) {
		insert = (AccountNode *)malloc(sizeof(AccountNode));
		if(fscanf(fp, "%s %d %s", 
					insert->u_name, 
					&insert->permission, 
					insert->u_password) != EOF) {} else {
			break;
		}	
		insert->next = Laccount->next;
		Laccount->next = insert;
	}	
	fclose(fp);
} /*读出文件中所有账户信息*/

void write_account_into_file(char *filename, LinkAccount Laccount) {
	FILE *fp;
	fp = fopen(filename, "w");
	if(fp == NULL) {
		printf("can NOT write the Account file!\n");
		return;
	}
	AccountNode *p;
	p = Laccount->next;
	while(p) {
		fprintf(fp, "%s %d %s\n", p->u_name, p->permission, p->u_password);
		p = p->next;
	}
	fclose(fp);
} /*写入所有账户信息到文件*/

void insert_new_account(LinkAccount Laccount, AccountNode *insert_account) {
	AccountNode *insert;
	AccountNode *p = Laccount->next;
	int flag = 0;
	while(p) {
		if(strcmp(p->u_name, insert_account->u_name) == 0) {
			flag = 1;
		}
		p = p->next;
	}
	if(flag == 0) {
		insert = (AccountNode *)malloc(sizeof(AccountNode));
		memcpy(insert, insert_account, sizeof(AccountNode));
		insert->next = Laccount->next;
		Laccount->next = insert;
	} else {
		printf("The username had been used!\n");
	}
}  /*增加新账户*/

void delete_account(LinkAccount Laccount, char *user_name) {
	AccountNode *p = Laccount->next;
	AccountNode *pre = Laccount->next;
	while(p) {
		if(strcmp(p->u_name, user_name) == 0) {
			break;
		} else {
			pre = p;
			p = p->next;
		}
	}
	if(p) {
		pre->next = p->next;
		free(p);
	} else {
		return;
	}
} /*删除账户*/

void update_account(LinkAccount Laccount, char *user_name, AccountNode *update_account) {
	AccountNode *p = Laccount->next;
	while(p) {
		if(strcmp(p->u_name, user_name) == 0) {
			break;
		} else {
			p = p->next;
		}
	}
	if(p) {
		strcpy(p->u_name, update_account->u_name);
		p->permission = update_account->permission;
		strcpy(p->u_password, update_account->u_password);
	} else {
		return;
	}
}  /*更新账户信息*/

void search_account(LinkAccount Laccount, char *user_name, AccountNode *search_account) {
	AccountNode *p = Laccount->next;
	while(p) {
		if(strcmp(p->u_name, user_name) == 0) {
			break;
		} else {
			p = p->next;
		}
	}
	if(p) {
		strcpy(search_account->u_name, p->u_name);
		search_account->permission = p->permission;
		strcpy(search_account->u_password, p->u_password);
	} else {
		return;
	}
} /*查找用户信息*/

void debug_account_list(LinkAccount Laccount) {
	int i = 0;
	AccountNode *p = Laccount->next;
	while(p) {
		printf("%d --> name:%s --> per:%d --> psw:%s\n", 
						i,
						p->u_name,
						p->permission,
						p->u_password);
		p = p->next;
		i++;
	}
	putchar('\n');
}  /*打印所有用户*/

void input_password(char *password) {
	char c;
	int i = 0;
	getchar();
	do {
		c = getchar();
		if (c != '\n') {
			password[i++] = c;
		}
	} while (c != '\n'&& LEN_USER_PASSWORD);
	password[i] = '\0';
}  /*密码输入*/

void admin_action() {
	int action;
	while(1) {
		system("clear");
		printf("**Admin MENU**\n");
		putchar('\n');
		putchar('\n');
		printf("1. [Add] New Student Info\n");
		printf("2. [Delete]  Student Info\n");
		printf("3. [Update]  Student Info\n");
		printf("4. [Search]  Student Info\n");
		putchar('\n');
		printf("5. [Add] New User Account\n");
		printf("6. [Delete]  User Account\n");
		printf("7. [Update]  User Account\n");
		printf("8. [Search]  User Account\n");
		putchar('\n');
		printf("9. [LogOut]\n");
		putchar('\n');
		putchar('\n');
		printf("My Option:");
		scanf("%d", &action);
		if(action == 9) {
			break;
		}
		switch(action) {
			case 1:
				system("clear");
				printf("1. [Add] New Student Info\n");
				add_new_stu_info();
				//while(1);//测试用
				break;
			case 2:
				system("clear");
				printf("2. [Delete]  Student Info\n");
				delete_stu_info();
				//while(1);//测试用
				break;
			case 3:
				system("clear");
				printf("3. [Update]  Student Info\n");
				update_stu_info();
				//while(1);//测试用
				break;
			case 4:
				system("clear");
				printf("4. [Search]  Student Info\n");
				search_stu_info(); 
				//while(1);//测试用
				break;
			case 5:
				system("clear");
				printf("5. [Add] New User Account\n");
				//while(1);//测试用
				add_new_user(); 
				break;
			case 6:
				system("clear");
				printf("6. [Delete]  User Account\n");
				delete_user(); 
				//while(1);//测试用
				break;
			case 7:
				system("clear");
				printf("7. [Update]  User Account\n");
				update_user(); 
				//while(1);//测试用
				break;
			case 8:
				system("clear");
				printf("8. [Search]  User Account\n");
				search_user(); 
				//while(1);//测试用
				break;
			/*
			case 9:
				system("clear");
				break;
			*/
		}
	}
} /*管理员行为*/

void user_action() {
	int action;
	while(1) {
		system("clear");
		printf("**User MENU**\n");
		putchar('\n');
		putchar('\n');
		printf("1. [Search]  Student Info\n");
		putchar('\n');
		putchar('\n');
		printf("2. [LogOut]\n");
		putchar('\n');
		putchar('\n');
		printf("My Option:");
		scanf("%d", &action);
		if(action == 2) {
			break;
		}
		switch(action) {
			case 1:
				system("clear");
				printf("1. [Search]  Student Info\n");
				search_stu_info(); 
				//while(1);//测试用
				break;
		}
	}
} /*普通用户行为*/

void add_new_stu_info() {
	putchar('\n');	
	putchar('\n');
	StuInfo input;
	memset(&input, 0, sizeof(StuInfo));
	printf("Please Input Student Information\n");
	printf("\nStudent NAME:");
	scanf("%s", input.s_name);
	printf("\nStudent MAJOR:");
	scanf("%s", input.s_major);
	printf("\nStudent CLASS ONE NAME:");
	scanf("%s", input.s_score.c_name[0]);
	printf("\nStudent CLASS TWO NAME:");
	scanf("%s", input.s_score.c_name[1]);
	printf("\nStudent CLASS THREE NAME:");
	scanf("%s", input.s_score.c_name[2]);
	printf("\nStudent CLASS FOUR NAME:");
	scanf("%s", input.s_score.c_name[3]);

	insert_new_info_into_list(Lmain, &input);
} /*增加学生信息*/

void delete_stu_info() {
	putchar('\n');	
	putchar('\n');
	int del_id;
	printf("Please Input the Student ID:");
	scanf("%d", &del_id);
	delete_info_from_list(Lmain, del_id);
} /*删除学生信息*/

void update_stu_info() {
	putchar('\n');	
	putchar('\n');
	StuInfo input;
	memset(&input, 0, sizeof(StuInfo));
	int update_id;
	printf("Please Input the Student ID:");
	scanf("%d", &update_id);
	putchar('\n');
	putchar('\n');
	input.s_id = update_id;
	printf("Please Input Student Information\n");
	printf("\nStudent NAME:");
	scanf("%s", input.s_name);
	printf("\nStudent MAJOR:");
	scanf("%s", input.s_major);
	printf("\nStudent CLASS ONE NAME:");
	scanf("%s", input.s_score.c_name[0]);
	printf("\nStudent CLASS TWO NAME:");
	scanf("%s", input.s_score.c_name[1]);
	printf("\nStudent CLASS THREE NAME:");
	scanf("%s", input.s_score.c_name[2]);
	printf("\nStudent CLASS FOUR NAME:");
	scanf("%s", input.s_score.c_name[3]);
	update_info_in_list(Lmain, update_id, &input);
} /*修改学生信息*/

void search_stu_info() {
	putchar('\n');	
	putchar('\n');
	StuInfo input;
	memset(&input, 0, sizeof(StuInfo));
	int search_id;
	printf("Please Input the Student ID:");
	scanf("%d", &search_id);
	search_info_from_list(Lmain, search_id, &input);
	putchar('\n');	
	putchar('\n');
	printf("NAME:%s\n", input.s_name);		
	printf("MAJOR:%s\n", input.s_major);
	while(1) {
		int flag = 0;	
		putchar('\n');	
		putchar('\n');
		putchar('\n');	
		putchar('\n');
		printf("press '1' to RETURN\n");
		scanf("%d", &flag);
		if(flag == 1) {
			break;
		}
	}	
} /*查找学生信息*/

void add_new_user() {
	putchar('\n');	
	putchar('\n');
	//StuInfo input;
	AccountNode input;
	memset(&input, 0, sizeof(AccountNode));
	printf("Please Input User Information\n");
	printf("\nUser NAME:");
	scanf("%s", input.u_name);
	printf("\nUser PERMISSION [admin:1,user:0]:");
	scanf("%d", &input.permission);
	printf("\nUser PASSWORD:");
	scanf("%s", input.u_password);

	insert_new_account(Laccount, &input);

} /*增加账户信息*/

void delete_user() {
	putchar('\n');	
	putchar('\n');
	char del_id[LEN_USER_NAME];
	printf("Please Input the User ID:");
	scanf("%s", del_id);
	delete_account(Laccount, del_id);
} /*删除账户信息*/

void update_user() {
	char update_id[LEN_USER_NAME];
	putchar('\n');	
	putchar('\n');
	AccountNode input;
	memset(&input, 0, sizeof(AccountNode));
	printf("Please Input the User NAME:");
	scanf("%s", update_id);
	putchar('\n');
	putchar('\n');
	printf("Please Input User Information\n");
	printf("\nUser NAME:");
	scanf("%s", input.u_name);
	printf("\nUser PERMISSION:");
	scanf("%d", &input.permission);
	printf("\nUser PASSWORD:");
	scanf("%s", input.u_password);
	update_account(Laccount, update_id, &input);
} /*修改账户信息*/

void search_user() {
	putchar('\n');	
	putchar('\n');
	AccountNode input;
	memset(&input, 0, sizeof(AccountNode));
	char search_id[LEN_USER_NAME];
	printf("Please Input the User ID:");
	scanf("%s", search_id);
	search_account(Laccount, search_id, &input);
	putchar('\n');	
	putchar('\n');
	printf("NAME:%s\n", input.u_name);		
	printf("PERMISSION:%d\n", input.permission);
	while(1) {
		int flag = 0;	
		putchar('\n');	
		putchar('\n');
		putchar('\n');	
		putchar('\n');
		printf("press '1' to RETURN\n");
		scanf("%d", &flag);
		if(flag == 1) {
			break;
		}
	}	
} /*查找账户信息*/










