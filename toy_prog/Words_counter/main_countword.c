#include"head_countword.h"
int main(int argn, char *argv[]) {
	int whole_words = 0;
	int unique_words_num = 0;
	clock_t t;
	t = clock();

	replace_punctuation("original.txt", "input.txt", ' ');//�滻�ļ��еı����Ų��������ļ�

	getWords("input.txt", input, &whole_words);//ȡ�����е��ʲ�ͳ���ܴ���

	countWords_linear(input, hasharray, &whole_words, &unique_words_num);//ͳ�Ƶ��ʴ�Ƶ������̽�ⷨ

	trverseHashArray_linear(hasharray, sortarray, ARRAY_MAX_SIZE);//�ӹ�ϣ������ȡ�����д��ڵĵ���

	binary_insertion_sort(sortarray, 0, unique_words_num);//�۰���������Ƶ����

	//quicksort(sortarray, 0, unique_words_num);//���������Ƶ��������

	t = clock() - t;
	printf("This sort took %d clocks (%f seconds). \n", t, ((float)t)/CLOCKS_PER_SEC);

	printTopN_frequence(sortarray, unique_words_num, 200);//�����ƵǰN�ߵĵ��ʼ����Ƶ

	system("pause");
	return 0;
}