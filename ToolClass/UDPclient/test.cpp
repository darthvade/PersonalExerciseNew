#include "UDPclient.h"
#include <iostream>

using namespace std;

int main() {
	UDPclient cli;
	string result;
	cli.sendMsg("127.0.0.1", "8800", "hehe");
	cli.recvMsg(result);
	cout << result << endl;
	return 0;
}
