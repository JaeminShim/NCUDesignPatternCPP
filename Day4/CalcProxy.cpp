// CalcProxy.cpp
#include "ioacademy.h"
#include "ICalc.h"
using namespace ioacademy;

// build this file with
// "cl CalcProxy.cpp /LD /link user32.lib gdi32.lib kernel32.lib"

class Calc : public ICalc
{
	int server;
	int mCount;

public:
	Calc() : mCount(0) { server = IoFindServer("Calc"); }
	virtual ~Calc() { cout << "~Calc()" << endl; }

	void AddRef() { ++mCount; }
	void Release() { if (--mCount == 0) delete this; }

	virtual int Add(int a, int b) override { return IoSendServer(server, 1, a, b); }
	virtual int Sub(int a, int b) override { return IoSendServer(server, 2, a, b); }
};

extern "C" __declspec(dllexport)
ICalc* CreateCalcProxy()
{
	return new Calc;
}