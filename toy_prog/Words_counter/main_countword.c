#include"head_countword.h"
int main(int argn, char *argv[]) {
	int whole_words = 0;
	int unique_words_num = 0;
	clock_t t;
	t = clock();

	replace_punctuation("original.txt", "input.txt", ' ');//替换文件中的标点符号并生成新文件

	getWords("input.txt", input, &whole_words);//取得所有单词并统计总词数

	countWords_linear(input, hasharray, &whole_words, &unique_words_num);//统计单词词频，线性探测法

	trverseHashArray_linear(hasharray, sortarray, ARRAY_MAX_SIZE);//从哈希数组中取出所有存在的单词

	binary_insertion_sort(sortarray, 0, unique_words_num);//折半插入排序词频数组

	//quicksort(sortarray, 0, unique_words_num);//快速排序词频排序数组

	t = clock() - t;
	printf("This sort took %d clocks (%f seconds). \n", t, ((float)t)/CLOCKS_PER_SEC);

	printTopN_frequence(sortarray, unique_words_num, 200);//输出词频前N高的单词及其词频

	system("pause");
	return 0;
}