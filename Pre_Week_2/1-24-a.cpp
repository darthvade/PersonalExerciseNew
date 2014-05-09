/**
* Copy constructor
*/

#include<iostream>
#include<string>

using namespace std;

class A {
public:
	A(){
		print("constructor of A");
	};
	A(const A& a){
		print("copy construscor of A");
	};
	~A(){
		print("destructor of A");
	};
	void print(const string& msg = ""){
		cout << msg << endl;
	}
	int i;

};

int main() {
	A a;
	//A b(a);
	A b = a;
	return 0;
}
