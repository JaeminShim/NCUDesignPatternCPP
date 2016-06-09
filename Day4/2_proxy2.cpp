// 2_proxy
#include <iostream>
#include <conio.h>
#include "ioacademy.h"
using namespace std;
using namespace ioacademy;

// Proxy: 기존 요소를 대신하는 클래스
// Remote Proxy: 원격지 서버를 대신하는 클래스

// Proxy: 함수 호출을 약속된 명령 코드(RPC Code)로 변경해서 서버에 보내는 것.
// Stub: 도착한 명령 코드(RPC Code)를 함수 호출로 변경

// 결국 현재 프로세스의 Add()를 호출하지만 서버의 Add()가 실행된다는 개념.
// RPC(Remote Procedure Call), RMI(Remote Method Invocation)

// (추가 확인할 것: RPC Code는 모든 객체를 수용할 수 있어야함: Mashalling - UnMashalling)

class Calc
{
	int server;
public:
	Calc() { server = IoFindServer("Calc"); }

	int Add(int a, int b) { return IoSendServer(server, 1, a, b); }
	int Sub(int a, int b) { return IoSendServer(server, 2, a, b); }
};

int main()
{
	Calc* pCalc = new Calc;
	cout << pCalc->Add(1, 2) << endl;
}