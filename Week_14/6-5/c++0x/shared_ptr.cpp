#include <iostream>
#include <memory>

class Pos {
public:
	explicit Pos(int x, int y): _x(x), _y(y) {
	
	}
	~Pos() {
	
	}
	void print() {
		std::cout << "x=" << _x << " y=" << _y << std::endl; 
	}
private:
	int _x;
	int _y;
};

int main() {
	std::shared_ptr<Pos> pPos(new Pos(7, 8));
	std::shared_ptr<Pos> pPos2(pPos);
	pPos->print();
	pPos2->print();
	return 0;
}
