#include <iostream>

struct Matrix {
	int **data;
	int row;
	int col;
	void init_array(std::size_t row, std::size_t col);
	void destory_array(Matrix *p);
	void add_array(Matrix *a, Matrix *b, Matrix *c);
	void mut_array(Matrix *a, Matrix *b, Matrix *c);
	void mut_array_x(int x);
	bool equal(Matrix a, Matrix b);
	void print(Matrix a);
};

int main() {

	return 0;
}
	
void Matrix::init_array(std::size_t row, std::size_t col) {
	this->data = new int *[row];
	for(std::size_t ix = 0; ix != row; ix++) {
		data[ix] = new int[col];
	}
}
