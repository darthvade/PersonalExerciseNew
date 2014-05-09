#include "head.h"

int is_matching_brackets(const char *input) {
	int len = strlen(input);
	int i;
	std::stack<char> st;
	for(i = 0; i < len; i++) {
		if(input[i] == '(') {
			st.push(input[i]);
			continue;
		}
		if(input[i] == ')') {
			if(st.empty()) {
				std::cout << "���Ų�ƥ��" << std::endl;
				return 0;
			}
			st.pop();
		}
	}
	if(st.empty()) {
		std::cout << "����ƥ�䣡" << std::endl;
		return 1;
	} else {
		std::cout << "���Ų�ƥ��" << std::endl;
		return 0;
	}
}//�ж������Ƿ�ƥ��@

int calc_re_polish(const char *input) {
	int len = strlen(input);
	int i;
	int result;
	int left, right;
	std::stack<int> st;
	for(i = 0; i < len; i++) {
		if(isdigit(input[i])) {
			st.push(input[i] - '0');
		} 
		else {
			switch(input[i]) {
			case '+':
				left = st.top();
				st.pop();
				right = st.top();
				st.pop();
				result = right + left;
				st.push(result);
				break;
			case '-':
				left = st.top();
				st.pop();
				right = st.top();
				st.pop();
				result = right - left;
				st.push(result);
				break;
			case '*':
				left = st.top();
				st.pop();
				right = st.top();
				st.pop();
				result = right * left;
				st.push(result);
				break;
			case '/':
				left = st.top();
				st.pop();
				right = st.top();
				st.pop();
				result = right / left;
				st.push(result);
				break;
			default:
				break;
			}
		}
	}
	return st.top();
}//�����沨�����ʽ@

int **malloc_array(const int x, const int y) {
	int **p = (int **)malloc(x * sizeof(int *));
	int i;
	for(i = 0; i < x; i++) {
		*(p+i) = (int *)malloc(y * sizeof(int));
	}
	return p;
}//��̬�����ά����

int free_array(int **input, const int x) {
	int i;
	for(i = 0; i < x; i++) {
		free(*(input + i));
	}
	free(input);
	return 1;
}//��̬�ͷŶ�ά����