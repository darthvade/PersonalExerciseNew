#include "UDPserver.h"
#include <string>
#include <iostream>

using namespace std;

int main() {
	string temp;	
	UDPserver ser("127.0.0.1", "8800");
	ser.recvMsg(temp);
	cout << temp <<  "++end++" << endl;
	unsigned int ip = ser.getClientIp();
	unsigned int port = ser.getClientPort();
	ser.sendMsg(ip, port, temp);
	return 0;
}
