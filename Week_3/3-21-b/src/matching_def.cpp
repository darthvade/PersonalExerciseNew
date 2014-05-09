//#include "matching.h"
#include "../include/matching.h"

void matching(char *filename) {
	if(filename == NULL) {
		return;
	}
	FILE *fp = fopen(filename, "r");
	char temp;
	std::stack<Bracket> st;
	std::stack<Bracket> rst;
	Bracket bt;
	int num_len = 1;
	int num_pos = 0;
	while((temp = fgetc(fp)) != EOF) {
		if(temp == '\n') {
			num_len++;
			num_pos = 0;
		} else if(temp == '\t') {
			num_pos = num_pos + 4;
		} else {
			num_pos++;
		}
		switch(temp) {
			case '(':
				bt.data = '(';
				bt.len = num_len;
				bt.pos = num_pos;
				st.push(bt);
				break;
			case '[':
				bt.data = '[';
				bt.len = num_len;
				bt.pos = num_pos;
				st.push(bt);
				break;
			case '{':
				bt.data = '{';
				bt.len = num_len;
				bt.pos = num_pos;
				st.push(bt);
				break;
			case ')':
				bt.data = ')';
				bt.len = num_len;
				bt.pos = num_pos;
				if(st.empty()) {
					rst.push(bt);
				} else {
					if((st.top()).data != '(') {
						rst.push(st.top());
						st.pop();
					} else {
						st.pop();
					}
				}
				break;
			case ']':
				bt.data = ']';
				bt.len = num_len;
				bt.pos = num_pos;
				if(st.empty()) {
					rst.push(bt);
				} else {
					if((st.top()).data != '[') {
						rst.push(st.top());
						st.pop();
					} else {
						st.pop();
					}
				}
				break;
			case '}':
				bt.data = '}';
				bt.len = num_len;
				bt.pos = num_pos;
				if(st.empty()) {
					rst.push(bt);
				} else {
					if((st.top()).data != '{') {
						rst.push(st.top());
						st.pop();
					} else {
						st.pop();
					}
				}
				break;
			default:
				break;
		}	
	}
	int i = 1;
	int flag = 0;
	if(!rst.empty()) {
		while(!rst.empty()) {
			Bracket temp = rst.top();
			printf("Error_%d_in line %d, %d		No matching --> '%c'\n", i++, temp.len, temp.pos, temp.data);
			rst.pop();
		}
		flag = 1;
	} 
	if(!st.empty()) {
		while(!st.empty()) {
			Bracket temp = st.top();
			printf("Error_%d_in line %d, %d		No matching --> '%c'\n", i++, temp.len, temp.pos, temp.data);
			st.pop();
		}
		flag = 1;
	} 
   	if(flag == 0){
		printf("matching All brackets!\n");
	}
	fclose(fp);
}
