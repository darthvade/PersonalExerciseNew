#include "UDPclient.h"
#include <iostream>
#include "WstringConvertString.hpp"

using namespace std;

int main(int argc, char *argv[]) {
	if(argc != 2) {
		return 1;
	}
	UDPclient cli;
	while(true) {
		string target;
		cin >> target;
		
		//string senttarget = Convert::WstringToString(target);
		//wcout << senttarget.size() << endl;
		string result;
		cli.sendMsg(argv[1], "8800", target);
		cli.recvMsg(result);
		wstring display = Convert::StringToWstring(result);
		wcout << display << endl;
	}
	return 0;
}
