// 2_function
#include <iostream>
using namespace std;

class Dialog
{
public:
	void Close() { cout << "Dialog close" << endl; }
};

void foo() { cout << "foo" << endl; }

// C++ 표준에는 범용적인 함수 포인터 역할의 객체가 있습니다.
#include <functional>

int main()
{
	function<void()> f = &foo;
	f();						// 결국 foo();

	Dialog dlg;
	f = bind(&Dialog::Close, &dlg);

	f();
}