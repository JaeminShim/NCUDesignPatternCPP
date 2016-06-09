// 2_proxy
#include <iostream>
#include <conio.h>
#include "ioacademy.h"
using namespace std;
using namespace ioacademy;

// Proxy�� ���� �����ڰ� ����� �˴ϴ�.
// ���ο� proxy�� ���͵� ����� �ڵ尡 ����Ǹ� �ȵ˴ϴ�.
// �������̽� ��� ����� �ʿ�

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
	ICalc* pCalc = new Calc;	// ����: ������ Calc�� ���� �� ����
	cout << pCalc->Add(1, 2) << endl;
}