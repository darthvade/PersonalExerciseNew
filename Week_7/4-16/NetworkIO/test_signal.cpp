#include <csignal>
#include <iostream>

using namespace std;

void callback(int ) {
	cout << "catch the C-t signal!" << endl;
}

int main() {

	signal(SIGINT, callback);
	while(1);
	return 0;
}
