// 1_thiscall3	// 66p

#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

// ��Ƽ ������ ������ Ŭ������ ĸ��ȭ �� ���ô�
DWORD __stdcall foo(void* p)
{
	return 0;
}

int main()
{
	CreateThread(0, 0, foo, "A", 0, 0);
}