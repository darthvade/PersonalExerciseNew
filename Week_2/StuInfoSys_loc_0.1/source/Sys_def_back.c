#include "Sys_head_back.h"

void init_info_main_list(LinkInfo *L) {
	(*L) = (InfoNode *)malloc(sizeof(InfoNode));
	(*L)->i_ps = NULL;
	(*L)->next = NULL;
} /*初始化信息总表*/

void read_all_info_from_file(char *filename, LinkInfo Lmain) {
	InfoNode *insert;
	StuInfo *tempdata;
	FILE *fp;
	fp = fopen(filename, "r");
	if(fp == NULL) {
		fp = fopen("Sys_Database.db", "w");
		fclose(fp);
		fp = fopen("Sys_Database.db", "r");
	}
	if(fp == NULL) {
		printf("can NOT open the file!\n");
		return;
	}
	while(1) {
		insert = (InfoNode *)malloc(sizeof(InfoNode));	
		tempdata = (StuInfo *)malloc(sizeof(StuInfo));
		insert->i_ps = tempdata;
		if(fscanf(fp, "%d %s %d %d %d %s",
					   &tempdata->s_id,
					   tempdata->s_name,
					   &tempdata->s_age,
					   &tempdata->s_grade,
					   &tempdata->s_class,
					   tempdata->s_major) != EOF) {} else {
			break;
		}
		if(fscanf(fp, "%s %s %s %s %lf %lf %lf %lf %lf", 
					   tempdata->s_score.c_name[0],
					   tempdata->s_score.c_name[1],
					   tempdata->s_score.c_name[2],
					   tempdata->s_score.c_name[3],
					   &tempdata->s_score.c_score[0],
					   &tempdata->s_score.c_score[1],
					   &tempdata->s_score.c_score[2],
					   &tempdata->s_score.c_score[3],
					   &tempdata->s_score.c_total_avg_score) != EOF) {} else {
			break;
		}
		insert->next = Lmain->next;
		Lmain->next = insert;	
	}
	fclose(fp);
} /*读出文件中的所有信息并插入信息总表*/

void write_all_info_into_file(char *filename, LinkInfo Lmain) {
	if(Lmain->next != NULL && Lmain->next->next != NULL) {
		if(Lmain->next->i_ps->s_id < Lmain->next->next->i_ps->s_id) {
			reverse_main_list(Lmain);
		}
	}
	FILE *fp;
	fp = fopen(filename, "w");
	if(fp == NULL) {
		printf("can NOT write the DataBase file!\n");
		return;
	}
	InfoNode *p;
	if(Lmain == NULL) {
		printf("This Main List is NOT existed!\n");
		return;
	}
	p = Lmain->next;
	if(Lmain->next == NULL) {
		printf("No element in this list!\n");
		return;
	}
	while(p) {
		fprintf(fp, "%d %s %d %d %d %s\n", p->i_ps->s_id, p->i_ps->s_name, p->i_ps->s_age, p->i_ps->s_grade, p->i_ps->s_class, p->i_ps->s_major);
		fprintf(fp, "%s %s %s %s %lf %lf %lf %lf %lf\n", p->i_ps->s_score.c_name[0], p->i_ps->s_score.c_name[1], 
													p->i_ps->s_score.c_name[2], p->i_ps->s_score.c_name[3], 
											   		p->i_ps->s_score.c_score[0], p->i_ps->s_score.c_score[1], 
													p->i_ps->s_score.c_score[2], p->i_ps->s_score.c_score[3],
											   		p->i_ps->s_score.c_total_avg_score);	
		p = p->next;
	}
	fclose(fp);	
} /*将所有信息从信息总表写入文件*/

void debug_main_list(LinkInfo Lmain) {
	int i = 0;
	InfoNode *p;
	if(Lmain == NULL) {
		printf("This Main List is NOT existed!\n");
		return;
	}		
	p = Lmain->next;
	if(Lmain->next == NULL) {
		printf("No element in this list!\n");
		return;
	}
	while(p) {
		printf("%d --> ID:%d--> name:%s--> age:%d--> grade:%d--> class:%d--> major:%s \n \
--> course1:%s--> score1:%lf--> course2:%s--> score2:%lf--> course3:%s--> score3:%lf--> course4:%s--> score4:%lf \n--> avg_score:%lf \n", i, 
				   p->i_ps->s_id,
				   p->i_ps->s_name,
				   p->i_ps->s_age,
				   p->i_ps->s_grade,
				   p->i_ps->s_class,
				   p->i_ps->s_major,
				   p->i_ps->s_score.c_name[0],
				   p->i_ps->s_score.c_score[0],
				   p->i_ps->s_score.c_name[1],
				   p->i_ps->s_score.c_score[1],
				   p->i_ps->s_score.c_name[2],
				   p->i_ps->s_score.c_score[2],
				   p->i_ps->s_score.c_name[3],
				   p->i_ps->s_score.c_score[3],
				   p->i_ps->s_score.c_total_avg_score); /*end of printf*/
		p = p->next;
		i++;
		putchar('\n');
	}
	putchar('\n');
} /*打印信息总表的所有信息*/

void insert_new_info_into_list(LinkInfo Lmain, StuInfo *insert_info) {
	if(Lmain->next != NULL && Lmain->next->next != NULL) {
		if(Lmain->next->i_ps->s_id < Lmain->next->next->i_ps->s_id) {
			reverse_main_list(Lmain);
		}
	}
	InfoNode *insert;
	StuInfo *tempdata;
	insert = (InfoNode *)malloc(sizeof(InfoNode));
	tempdata = (StuInfo *)malloc(sizeof(StuInfo));
	insert->i_ps = tempdata;
	memcpy(tempdata, insert_info, sizeof(StuInfo));
	if(Lmain->next == NULL) {
		tempdata->s_id = 20140001;
	} else {
		tempdata->s_id = Lmain->next->i_ps->s_id + 1;
	}
	insert->next = Lmain->next;
	Lmain->next = insert;	
}  /*将一个新元素-插入-信息总表*/

void delete_info_from_list(LinkInfo Lmain, int del_id) {
	InfoNode *cur;	
	InfoNode *pre;
	if(Lmain->next == NULL) {
		return;
	}
 	cur = Lmain->next;	
	pre = Lmain;
	while(cur && cur->i_ps->s_id != del_id) {
		pre = cur;
		cur = cur->next;
	}
	if(cur == NULL) {
		return;
	}
	if(cur != NULL) {
		pre->next = cur->next;
		free(cur);
	}
} /*-删除-信息总表中指定学号的学生信息*/

void update_info_in_list(LinkInfo Lmain, int del_id, StuInfo *update_info) {
	InfoNode *cur;	
	if(Lmain->next == NULL) {
		return;
	}
 	cur = Lmain->next;	
	while(cur && cur->i_ps->s_id != del_id) {
		cur = cur->next;
	}
	if(cur == NULL) {
		return;
	}
	if(cur != NULL) {
		memcpy(cur->i_ps, update_info, sizeof(StuInfo));
	}
}  /*-更新-信息总表中指定学号的学生信息*/

void search_info_from_list(LinkInfo Lmain, int del_id, StuInfo *search_info) {
	InfoNode *cur;	
	if(Lmain->next == NULL) {
		return;
	}
 	cur = Lmain->next;	
	while(cur && cur->i_ps->s_id != del_id) {
		cur = cur->next;
	}
	if(cur == NULL) {
		return;
	}
	if(cur != NULL) {
		memcpy(search_info, cur->i_ps, sizeof(StuInfo));
	}
} /*-查找-信息总表中指定学号的学生信息*/

void update_index_table(LinkInfo Lmain, IndexTable *index, int *real_info_len) {
	int i = 0;
	InfoNode *p;
	if(Lmain == NULL) {
		printf("This Main List is NOT existed!\n");
		return;
	}		
	p = Lmain->next;
	if(Lmain->next == NULL) {
		printf("No element in this list!\n");
		return;
	}
	while(p) {
		index[i].id = p->i_ps->s_id;
		index[i].i_ps = p->i_ps;
		i++;
		p = p->next;
		(*real_info_len)++;
	}
} /*更新索引表信息*/

void reverse_main_list(LinkInfo Lmain) {
	InfoNode *head;
	InfoNode *tail;
	InfoNode *temp;
	if(Lmain->next == NULL) {
		return;
	}
	head = Lmain->next;
	tail = Lmain->next;
	while(tail->next) {
		tail = tail->next;
	}
	while(tail != head) {
		temp = head;
		Lmain->next = head->next;
		head = head->next;
		temp->next = tail->next;
		tail->next = temp;
	}
} /*逆置信息总表*/

void debug_main_index(IndexTable *main_index, int *index_real_len) {
	int pos;
	for(pos = 0; pos < *index_real_len; pos++) {
		printf("pos:%d --> ID:%d --> NAME:%s\n", 
						pos,
						main_index[pos].id,
						main_index[pos].i_ps->s_name);
	}
} /*打印信息总索引表的所有信息*/










