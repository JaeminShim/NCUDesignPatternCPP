// 2_function
#include <iostream>
using namespace std;

class Dialog
{
public:
	void Close() { cout << "Dialog close" << endl; }
};

void foo() { cout << "foo" << endl; }

// C++ ǥ�ؿ��� �������� �Լ� ������ ������ ��ü�� �ֽ��ϴ�.
#include <functional>

int main()
{
	function<void()> f = &foo;
	f();						// �ᱹ foo();

	Dialog dlg;
	f = bind(&Dialog::Close, &dlg);

	f();
}