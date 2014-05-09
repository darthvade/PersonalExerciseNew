/**
* 有问题！
*/

#include<iostream>
#include<string>

using namespace std;

static int objectCount = 0;

class HowMany {
	public:
		HowMany(const HowMany& x) {
			objectCount++;	
			print("HowMany()");
		}	
		void print(const string& msg = "") {
			if(msg.size() != 0) {
				cout << msg << ":";
			}
			cout << "objectCount = " << objectCount << endl;
		}
		~HowMany() {
			objectCount--;
			print("~HowMany()");
		}
}

HowMany fun(HowMany x) {
	cout << "begin of fun" << endl;
	x.print("x argument inside fun()");
	cout << "end of fun" << endl;
	return x;
}

int main() {
	HowMany h;
	h.print("after constructon of h");
	//HowMany h2 = fun(h);
	HowMany h2(h);
	h.print("after call to fun()");
}
