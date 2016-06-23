// 3_Facade
// Facade : ���� �ý����� ����ϱ� ���� �ϱ� ���� ������ ������ �������̽�

// (copied from "8_facade2.cpp")
#include <iostream>
using namespace std;

#include <WinSock2.h>
#pragma comment( lib, "ws2_32.lib")

// ���� å���� ��Ģ(Single Responsibility Principle)
// �ϳ��� Ŭ������ �ϳ��� å�Ӹ�..

class NetworkInit
{
public:
	NetworkInit()
	{
		WSADATA w;
		WSAStartup(0x202, &w); // ��Ʈ��ũ ���̺귯�� �ʱ�ȭ
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
		// C�Լ��� �ٽ� ȣ���ؼ� bind
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


// Network ������ ��� TCP ������ ���� ���� �� �ֵ��� �ϴ� Ŭ����
// => Facade ����
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