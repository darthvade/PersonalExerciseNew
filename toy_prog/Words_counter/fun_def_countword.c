#include "head_countword.h"

//从文件获取单词放到单词数组中
void getWords(char *filename, char input[][WORD_MAX_SIZE], int *array_size) {
	freopen(filename, "rb", stdin);
	while(scanf("%s", input[*array_size]) != EOF) {
		(*array_size)++;
	}
	freopen("CON", "rb", stdin);
}

//取得每个单词的哈希码
unsigned int getHashCode(char *str) {
	unsigned int hash = 0;
	while(*str != '\0') {
		hash = hash * SEED_HASH + *str;
		str++;
	}
	return hash % ARRAY_MAX_SIZE;
}

//统计单词词频//链表处理冲突，有问题！！！
void countWords(char input[][WORD_MAX_SIZE], Node *hasharray, const int *array_size) {
	int i = 0;
	int pos;
	Node *cur;
	Node *pre;
	while(i < *array_size) {
		pos = getHashCode(input[i]);
		cur = &hasharray[pos];
		if(hasharray[pos].word == NULL) {
			hasharray[pos].word = input[i];
			hasharray[pos].count = 1;
			i++;
			continue;
		} else if(strcmp(hasharray[pos].word, input[i]) == 0) {
			hasharray[pos].count++;
			i++;
			continue;
		} else if(hasharray[pos].next == NULL) {
			Node *p = (Node *)malloc(sizeof(Node));
			p->count = 1;
			p->word = input[i];
			cur->next = p;
			i++;
			continue;
		}
		while(cur->next != NULL) {
			cur = cur->next;
			if(strcmp(cur->word, input[i]) == 0) {
				cur->count++;
				i++;
				continue;
			} else {
				pre = cur;
				cur = cur->next;
				continue;
			}
		}
		if(cur == NULL) {
			Node *p = (Node *)malloc(sizeof(Node));
			p->count = 1;
			p->word = input[i];
			pre->next = p;
			i++;
			continue;
		}
	}
}

//统计单词词频，线性探测法
void countWords_linear(char input[][WORD_MAX_SIZE], Node *hasharray, const int *array_size, int *unique_words_num) {
	int i = 0;
	int pos;
	int flag = 1;
	while(i < *array_size) {
		if(flag == 1) {
			pos = getHashCode(input[i]);
		}
		if(hasharray[pos].word == NULL) {
			hasharray[pos].word = input[i];
			hasharray[pos].count = 1;
			i++;
			(*unique_words_num)++;
			flag = 1;
			continue;
		} else if(strcmp(hasharray[pos].word, input[i]) == 0) {
			hasharray[pos].count++;
			i++;
			flag = 1;
			continue;
		}
		flag = 0;
		if(pos == ARRAY_MAX_SIZE - 1) {
			pos = 0;
		} else {
			pos = pos + 1;
		}
	}
}

//遍历哈希数组,并存储元素到词频排序数组
void trverseHashArray(Node *hasharray, Node *sortarray, const int hasharray_size, int *unique_words_num) {
	int i;
	int j = 0;
	for(i = 0; i < hasharray_size; i++) {
		Node *p;
		if(hasharray[i].word != NULL) {
			p = hasharray[i].next;
			//printf("%s --> %d\n", hasharray[i].word, hasharray[i].count);
			sortarray[j].count = hasharray[i].count;
			sortarray[j].word = hasharray[i].word;
			(*unique_words_num)++;
			j++;
			while(p != NULL) {
				//printf("%s --> %d\n", p->word, p->count);
				//sortarray[j].count = hasharray[i].count;
				//sortarray[j].word = hasharray[i].word;
				sortarray[j].count = p->count;
				sortarray[j].word = p->word;
				(*unique_words_num)++;
				p = p->next;
				j++;
			}
		}
	}
}

//遍历哈希数组,并存储元素到词频排序数组(线性探测版)
void trverseHashArray_linear(Node *hasharray, Node *sortarray, const int hasharray_size) {
	int i;
	int j = 0;
	for(i = 0; i < hasharray_size; i++) {
		if(hasharray[i].count != 0) {
			sortarray[j].count = hasharray[i].count;
			sortarray[j].word = hasharray[i].word;
			j++;
		}
	}
}

//快速排序
void quicksort(Node *sortarray, const int start, const int end) {
	if(end - 1 > start) {
		const int pivot_pos = partition(sortarray, start, end);
		quicksort(sortarray, start, pivot_pos);
		quicksort(sortarray, pivot_pos + 1, end);
	}
}
int partition(Node *sortarray, const int start, const int end) {
	int i = start;
	int j = end - 1;
	Node temp;
	temp.count = sortarray[i].count;
	temp.word = sortarray[i].word;
	while(i < j) {
		while(i < j && sortarray[j].count >= temp.count) j--;
		sortarray[i].count = sortarray[j].count;
		sortarray[i].word = sortarray[j].word;
		while(i < j && sortarray[i].count <= temp.count) i++;
		sortarray[j].count = sortarray[i].count;
		sortarray[j].word = sortarray[i].word;
	}
	sortarray[i].count = temp.count;
	sortarray[i].word = temp.word;
	return i;
}

//折半插入排序
void binary_insertion_sort(Node *sortarray, const int start, const int end) {
	Node temp;
	int i, j, left, right, mid;
	for(i = start + 1; i < end; i++) {
		temp.count = sortarray[i].count;
		temp.word = sortarray[i].word;
		left = start;
		right = i - 1;
		while(left <= right) {
			mid = (left + right) / 2;
			if(temp.count < sortarray[mid].count) {
				right = mid - 1;
			} else {
				left = mid + 1;
			}
		}
		for(j = i - 1; j >= left; j--) {
			sortarray[j + 1].count = sortarray[j].count;
			sortarray[j + 1].word = sortarray[j].word;
		}
		sortarray[left].count = temp.count;
		sortarray[left].word = temp.word;
	}
}

//输出词频前N高的单词及其词频
void printTopN_frequence(Node *sortarray, const int unique_words_num, int topn) {
	int i;
	int j = 1;
	for(i = unique_words_num - 1; i >= 0 && topn > 0; i--) {
		printf("No.%3d --> num:%6d  --> %s\n", j++, sortarray[i].count, sortarray[i].word);
		topn--;
	}
}

//替换文件中的标点符号并生成新文件
void replace_punctuation(char *filename, char *newfile, char replace) {
	int temp;
	FILE *fp;
	FILE *nfp;
	fp = fopen(filename, "rb");
	nfp = fopen(newfile, "wb");
	while((temp = fgetc(fp)) != EOF) {
		if(ispunct(temp)) {
			fputc(replace, nfp);
		}
		else {
			fputc(temp, nfp);
		}
	}
	fclose(fp);
	fclose(nfp);
}