#include<stdio.h>
#include<string.h>

#define LEN_STU_NAME 32
#define LEN_STU_MAJOR 32

#define LEN_SCORE_CLASS_NAME 32
#define LEN_SCORE_MAX_CLASS_NUM 4

struct Score {
	char c_name[LEN_SCORE_MAX_CLASS_NUM][LEN_SCORE_CLASS_NAME];
	double c_score[LEN_SCORE_MAX_CLASS_NUM];
	double c_total_avg_score;
};

struct Student {
	int s_id;
	char s_name[LEN_STU_NAME];
	int s_age;
	int s_grade;
	int s_class;
	char s_major[LEN_STU_MAJOR];
	struct Score s_score;
};

struct InfoNode {
	struct Student *i_ps;
	struct InfoNode *next;	
};

typedef struct Student StuInfo;
typedef struct Score ScoreInfo;
typedef struct InfoNode InfoNode;

int main() {
	StuInfo st;
	FILE *fp;

	st.s_id = 1001;
	strcpy(st.s_name, "Kevin");
	st.s_age = 24;
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


	fp = fopen("output.data", "w");
	fprintf(fp, "%d %s %d %d %d %s\n", st.s_id, st.s_name, st.s_age, st.s_grade, st.s_class, st.s_major);
	fprintf(fp, "%s %s %s %s %lf %lf %lf %lf %lf\n", st.s_score.c_name[0], st.s_score.c_name[1], 
													st.s_score.c_name[2], st.s_score.c_name[3], 
											   		st.s_score.c_score[0], st.s_score.c_score[1], 
													st.s_score.c_score[2], st.s_score.c_score[3],
											   		st.s_score.c_total_avg_score);	
	fclose(fp);
	return 0;
}






