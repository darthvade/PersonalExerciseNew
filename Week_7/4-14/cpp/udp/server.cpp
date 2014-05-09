#include "UDP_server.h"

int main() {
	UDPServer s(8888);
	while(1) {
		std::string str = s.receive();
		s.send(str);
	}
	return 0;
}
