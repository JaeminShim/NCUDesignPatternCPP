// 1_thiscall2	// 33p

// 1. 일반 함수 포인터에 멤버 함수의 주소를 담을 수 없다.
// 2. 일반 함수 포인터에 static 멤버 함수의 주소를 담을 수 있다.
// 3. 멤버 함수 포인터를 만들고 사용하는 방법: 아래 main 참고

class Dialog
{
public:
	void Close() {}
};

void foo() {}

int main()
{
	void(*f1)() = &foo;
	//void(*f2)() = &Dialog::Close;	// 될까요?
									// ERROR: this 인자가 있다.

	// 멤버 함수의 주소를 담는 방법
	void(Dialog::*f2)() = &Dialog::Close;

	Dialog dlg;
	(dlg.*f2)();		// dlg.Close();
}