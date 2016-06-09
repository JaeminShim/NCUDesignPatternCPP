// 2_proxy
#include <iostream>
#include <conio.h>
#include "ioacademy.h"
using namespace std;
using namespace ioacademy;

// Proxy: ���� ��Ҹ� ����ϴ� Ŭ����
// Remote Proxy: ������ ������ ����ϴ� Ŭ����

// Proxy: �Լ� ȣ���� ��ӵ� ��� �ڵ�(RPC Code)�� �����ؼ� ������ ������ ��.
// Stub: ������ ��� �ڵ�(RPC Code)�� �Լ� ȣ��� ����

// �ᱹ ���� ���μ����� Add()�� ȣ�������� ������ Add()�� ����ȴٴ� ����.
// RPC(Remote Procedure Call), RMI(Remote Method Invocation)

// (�߰� Ȯ���� ��: RPC Code�� ��� ��ü�� ������ �� �־����: Mashalling - UnMashalling)

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