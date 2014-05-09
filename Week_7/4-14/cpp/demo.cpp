#include <iostream>

using namespace std;

class Data {
	public:
		void setData(const int &data);
		int &getData();
		static void display();
	private:
		int _data;
};

void Data::setData(const int &data) {
	this->_data = data;
}

int &Data::getData() {
	return this->_data;
}

void Data::display() {
	cout << "Display!" << endl;
}

int main() {
	Data d;
	d.setData(89);
	cout << d.getData() << endl;

	void (*pfunc)();
	pfunc = Data::display;
	pfunc();

	return 0;
}
