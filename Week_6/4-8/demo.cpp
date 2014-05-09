#include<iostream>
#include<cstdlib>

struct Array2 {
	int **p;
	int m;
	int n;
	void init();
	void destory();
};

int main() {

	/*
	int **p = (int **)malloc(5 * sizeof(int *));
	for(size_t i = 0; i != 5; i++) {
		p[i] = (int *)malloc(sizeof(int) * 5);
	}
	p[2][3] = 5;
	std::cout << p[2][3] << std::endl;
	*/

	Array2 arr;
	arr.m = 5;
	arr.n = 4;
	arr.init();
	arr.destory();
}

void Array2::init() {
	p = (int **)malloc(m * sizeof(int *));
	for(size_t i = 0; i != m; i++) {
		p[i] = (int *)malloc(sizeof(int) * n);
	}
}

void Array2::destory() {
	for(size_t i = 0; i != m; i++) {
		free(p[i]);	
	}
	free(p);
}
