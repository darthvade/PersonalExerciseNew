#include </home/kevin/BuildMuduo/build/release-install/include/muduo/net/EventLoop.h>
#include </home/kevin/BuildMuduo/build/release-install/include/muduo/net/TcpServer.h>
#include </home/kevin/BuildMuduo/build/release-install/include/muduo/net/InetAddress.h>
#include </home/kevin/BuildMuduo/build/release-install/include/muduo/base/Singleton.h>

#include <string>
#include <iostream>
#include <functional>

using namespace muduo;
using namespace muduo::net;

class hehe {
public:
	hehe() {
		std::cout << "hehe is created!"  << std::endl;
	}
	void fun() {
		std::cout << "only instance!!!"  << std::endl;
	}
};

void onConnection(const TcpConnectionPtr& conn) {
	if(conn->connected()) {
		Singleton<hehe>::instance().fun();
		conn->shutdown();
	}
}

int main() {
	Singleton<hehe>::instance();
	EventLoop loop;
	TcpServer server(&loop, InetAddress(8800), "Muduo");
	server.setConnectionCallback(onConnection);
	server.start();
	loop.loop();
	return 0;
}


