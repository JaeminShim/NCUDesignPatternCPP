#include <iostream>
#include "ioacademy.h"
using namespace std;
using namespace ioacademy;

int Add(int a, int b)
{
	cout << "Add" << endl;
	return a + b;
}

int Sub(int a, int b)
{
	cout << "Sub" << endl;
	return a - b;
}

int handler(int code, int a, int b)
{
	// Stub: 도착한 명령 코드(RPC Code)를 함수 호출로 변경
	switch (code)
	{
	case 1: return Add(a, b);
	case 2: return Sub(a, b);
	}
	return 0;
}

int main()
{
	IoStartServer("Calc", handler);
}