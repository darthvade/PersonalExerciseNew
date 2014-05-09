#include "Sys_head_back.h"
//#include "Sys_head_account.h"



int main() {

	int index_real_len = 0;
	LinkInfo Lmain; //信息总表
	init_info_main_list(&Lmain); //初始化信息总表
	read_all_info_from_file("Sys_Database.db", Lmain); //从文件读数据

/*测试---------------------------------------------------------------------*/

	StuInfo input;

/*
	StuInfo	st;

	st.s_id = 1111;
	strcpy(st.s_name, "Nora");
	st.s_age = 23;
	st.s_grade = 5;
	st.s_class = 3;
	strcpy(st.s_major, "Opto-e");

	strcpy(st.s_score.c_name[0], "math");
	st.s_score.c_score[0] = 97;

	strcpy(st.s_score.c_name[1], "science");
	st.s_score.c_score[1] = 87;

	strcpy(st.s_score.c_name[2], "history");
	st.s_score.c_score[2] = 67;

	strcpy(st.s_score.c_name[3], "writing");
	st.s_score.c_score[3] = 87;

	//update_index_table(Lmain, MainIndex, &index_real_len);

	//debug_main_index(MainIndex, &index_real_len);

	//update_info_in_list(Lmain, 1005, &st);

	//delete_info_from_list(Lmain, 20140001);

	insert_new_info_into_list(Lmain, &st); //插入新学生信息

	strcpy(st.s_name, "Kevin");

	insert_new_info_into_list(Lmain, &st);

	strcpy(st.s_name, "xxxxx");

	insert_new_info_into_list(Lmain, &st);

	//delete_info_from_list(Lmain, 1024);

	//search_info_from_list(Lmain, 1011, &st);
	//printf("%d ---> %s ---> %s\n", st.s_id, st.s_name, st.s_major);

*/
/*测试---------------------------------------------------------------------*/

	while(1) {
	putchar('\n');  
    putchar('\n');
    StuInfo input;
    memset(&input, 0, sizeof(StuInfo));
    printf("Please Input Student Information\n");
    //getchar(); 
    printf("\nStudent NAME:");
    scanf("%s", input.s_name);
    //getchar();
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

	write_all_info_into_file("Sys_Database.db", Lmain); // 向文件写入数据
	}
	//debug_main_list(Lmain);
	return 0;
}






