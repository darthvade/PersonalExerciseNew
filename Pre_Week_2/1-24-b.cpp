/**
* static in C++
*/

#include<iostream>

class Pos {
	public:
		Pos(): x(5), y(5) {

		}
		Pos(const Pos& p){

		}
		~Pos() {

		}
		int x, y;
};

static Pos pb;//initialized first

int main() {
	Pos pa;//initialized second
	return 0;
}
