#include<stdio.h>
#include<Windows.h>
#include<string.h>

void reverse_word(char *input, const int start, const int end);

int isRunYear(int year);

int num_days(int year, int month, int day);

int main() {
	//��123456789��ѡ�������������һ����λ��abc������a>b>c
	/*int source[] = {1, 2, 3, 4, 5, 6, 7, 8 ,9};
	int result;
	int i, j, k;
	int count = 0;
	for(i = 0; i < 9; i++) {
		for(j = 0; j < 9; j++) {
			for(k = 0; k < 9; k++) {
				if(source[i] < source[j] && source[j] < source[k]) {
					result = source[i] * 100 + source[j] * 10 + source[k];
					printf("%d - > %d\n", count++, result);
				}
			}
		}
	}*/

	//�ж�һ�����Ƿ��ǻ�����
	/*long long int input;
	long long int output = 0;
	long long int temp;
	scanf("%lld", &input);
	temp = input;
	while(input) {
		output = output * 10 + (input % 10);
		input = input / 10;
	}
	if(temp == output) {
		printf("%lld �ǻ�����\n", temp);
	} else {
		printf("%lld ���ǻ�������\n", temp);
	}*/


	//��תһ�鵥��
	/*char input[500];
	int flag = 0;
	int pre_flag = 0;
	int len_all;
	int start, end;
	int i;
	gets(input);
	len_all = strlen(input);
	reverse_word(input, 0, len_all);
	for(i = 0; i <= len_all; i++) {
		if(input[i] >= 'a' && input[i] <= 'z') {
			flag = 1;
		} else if(input[i] >= 'A' && input[i] <= 'Z') {
			flag = 1;
		} else {
			flag = 0;
		}
		if((pre_flag == 0) && (flag == 1)) {
			start = i;
		}
		if((pre_flag == 1) && (flag == 0)) {
			end = i;
			reverse_word(input, start, end);
		}
		pre_flag = flag;
	}
	printf("%s\n", input);*/


	//�����ַ����еĶ���ո�
	/*char input[500];
	int len_input;
	int i = 0;
	int j = 0;
	int flag = 1;
	gets(input);
	len_input = strlen(input);
	while(j < len_input && i < len_input) {
		if(input[i] == ' ' && input[j] == ' ') {
			j++;
			flag = 1;
			continue;
		}
		if((input[i] != ' ') && (input[j] != ' ')){
			i++, j++;
		}
		if(input[j] != ' ' && input[i] == ' ') {
			if(flag && input[i + 1] == ' ') {
				i++;
			}
			input[i] = input[j];
			input[j] = ' ';
			i++;
			j++;
			flag = 0;
		}
	}
	printf("%s\n", input);*/


	//������һ��ĵڼ��죬�����ڼ�
	/*int year;
	int month;
	int day;
	int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int num_day = 0;
	int num_week = 0;
	int i;
	printf("year:month:day  ->  ");
	scanf("%d:%d:%d", &year, &month, &day);
	for(i = 0; i < month - 1; i++) {
		num_day = num_day + days_in_month[i];
	}
	num_day = num_day + day;
	if(isRunYear(year)) {
		if((month > 2)||(day >= 29 && month >= 2)) {
			num_day++;
		}
	} 
	if(num_day % 7 == 0) {
		num_week = 2;
	} else {
		num_week = (2 + num_day) % 7;
	}
	printf("�����ǽ���ĵ�%d�죬������%d\n", num_day, num_week);*/

	//��������֮�������
	int year1;
	int month1;
	int day1;
	int year2;
	int month2;
	int day2;
	int gap_days = 0;
	int i;
	int days1;
	int days2;
	printf("year1:month1:day1  near->  ");
	scanf("%d:%d:%d", &year1, &month1, &day1);
	putchar('\n');
	printf("year2:month2:day2  far->  ");
	scanf("%d:%d:%d", &year2, &month2, &day2);
	for(i = year1 - 1; i >= year2; i--) {
		if(isRunYear(i)) {
			gap_days += 366;
		} else {
			gap_days += 365;
		}
	}
	days1 = num_days(year1, month1, day1);
	days2 = num_days(year2, month2, day2);
	gap_days = gap_days + days1 - days2;
	printf("�������ڼ������Ϊ%d\n", gap_days);

	system("pause");
	return 0;
}

void reverse_word(char *input, const int start, const int end) {
	int i = start;
	int j = end - 1;
	while(i < j) {
		input[i] = input[i] ^ input[j];
		input[j] = input[i] ^ input[j];
		input[i] = input[i] ^ input[j];
		i++;
		j--;
	}
}

int isRunYear(int year) {
	if(((year % 400) == 0) || (((year % 4) == 0) && ((year % 100) != 0))) {
		return 1;
	} else {
		return 0;
	}
}

int num_days(int year, int month, int day) {
	int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int num_day = 0;
	int i;
	for(i = 0; i < month - 1; i++) {
		num_day = num_day + days_in_month[i];
	}
	num_day = num_day + day;
	if(isRunYear(year)) {
		if((month > 2)||(day >= 29 && month >= 2)) {
			num_day++;
		}
	} 
	return num_day;
}