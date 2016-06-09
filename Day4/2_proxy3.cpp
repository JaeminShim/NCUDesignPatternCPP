// 2_proxy
#include <iostream>
#include <conio.h>
#include "ioacademy.h"
using namespace std;
using namespace ioacademy;

// Proxy는 서버 설계자가 만들게 됩니다.
// 새로운 proxy가 나와도 사용자 코드가 변경되면 안됩니다.
// 인터페이스 기반 통신이 필요

struct ICalc
{
	virtual int Add(int a, int b) = 0;
	virtual int Sub(int a, int b) = 0;
	virtual ~ICalc() {};
};

class Calc : public ICalc
{
	int server;
public:
	Calc() { server = IoFindServer("Calc"); }

	virtual int Add(int a, int b) override { return IoSendServer(server, 1, a, b); }
	virtual int Sub(int a, int b) override { return IoSendServer(server, 2, a, b); }
};

int main()
{
	ICalc* pCalc = new Calc;	// 문제: 여전히 Calc를 버릴 수 없음
	cout << pCalc->Add(1, 2) << endl;
}