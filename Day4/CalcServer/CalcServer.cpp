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
	// Stub: ������ ��� �ڵ�(RPC Code)�� �Լ� ȣ��� ����
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