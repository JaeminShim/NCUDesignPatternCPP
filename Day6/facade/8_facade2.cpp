// 8_facade - 카페에 가면 facade.cpp 있습니다. 다운 받아서 소스 복사해놓으세요
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



int main()
{
	NetworkInit init;
	IPAddress ip("127.0.0.1", 4000);
	Socket sock(SOCK_STREAM); // TCP
	sock.Bind(&ip);
	sock.Listen();
	sock.Accept();
}



