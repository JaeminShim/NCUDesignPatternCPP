// 1_thiscall5

#include <iostream>
#include "ioacademy.h"	// cafe.naver.com/cppmaster

using namespace std;
using namespace ioacademy;

void foo(int id)
{
	cout << "foo" << id << endl;
}

int main()
{
	int n1 = IoSetTimer(500, foo);
	int n2 = IoSetTimer(1000, foo);
	IoProcessMessage();
}