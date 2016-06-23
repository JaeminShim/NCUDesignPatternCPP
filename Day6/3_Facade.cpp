// 3_Facade
// Facade : 서브 시스템을 사용하기 쉽게 하기 위한 포괄적 개념의 인터페이스

// (copied from "8_facade2.cpp")
#include <iostream>
using namespace std;

#include <WinSock2.h>
#pragma comment( lib, "ws2_32.lib")

// 단일 책임의 원칙(Single Responsibility Principle)
// 하나의 클래스는 하나의 책임만..

class NetworkInit
{
public:
	NetworkInit()
	{
		WSADATA w;
		WSAStartup(0x202, &w); // 네트워크 라이브러리 초기화
	}
	~NetworkInit()
	{
		WSACleanup();
	}
};



class IPAddress
{
	SOCKADDR_IN addr;
public:
	IPAddress(const char* ip, short port)
	{
		addr.sin_family = AF_INET;
		addr.sin_port = htons(port);
		addr.sin_addr.s_addr = inet_addr(ip);
	}
	SOCKADDR* getRawAddress() { return (SOCKADDR*)&addr; }
};




class Socket
{
	int sock;
public:
	Socket(int type) { sock = socket(PF_INET, type, 0); }

	void Bind(IPAddress* ip)
	{
		// C함수를 다시 호출해서 bind
		::bind(sock, ip->getRawAddress(), sizeof(SOCKADDR_IN));
	}
	void Listen() { ::listen(sock, 5); }
	void Accept()
	{
		SOCKADDR_IN addr2 = { 0 };
		int sz = sizeof(addr2);
		accept(sock, (SOCKADDR*)&addr2, &sz);
	}
};


// Network 개념이 없어도 TCP 서버를 쉽게 만들 수 있도록 하는 클래스
// => Facade 패턴
class TCPServer
{
	NetworkInit init;
	Socket sock;
public:
	TCPServer() : sock(SOCK_STREAM) {}

	void Start(const char* ip, short port)
	{
		IPAddress addr(ip, port);
		sock.Bind(&addr);
		sock.Listen();
		sock.Accept();
	}
};



int main()
{
	TCPServer server;
	server.Start("127.0.0.1", 4000);
}