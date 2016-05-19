// 1_thiscall7

#include <iostream>
#include "ioacademy.h"	// cafe.naver.com/cppmaster

using namespace std;
using namespace ioacademy;

int foo(int h, int msg, int a, int b)
{
	switch (msg)
	{
	case WM_LBUTTONDOWN:	cout << "LBUTTON" << endl; break;
	case WM_KEYDOWN:		cout << "KEYDOWN" << endl; break;
	}
	return 0;
}

int main()
{
	int h1 = IoMakeWindow(foo);
	int h2 = IoMakeWindow(foo);
	IoProcessMessage();
}