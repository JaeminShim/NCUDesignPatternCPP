// 1_thiscall4	// 66p

#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

// 멀티 스레드 개념을 클래스로 캡슐화 해 봅시다

// 아래 클래스가 라이브러리 내부 클래스라고 가정합니다.
class Thread
{
public:
	void run()
	{
		// Parameter로 this를 넘김에 주목
		CreateThread(0, 0, threadMain, this, 0, 0);
	}

	// 1. 아래 함수가 static인 이유를 정확히 알아야 합니다.
	//    CreateThread()에 전달되는 함수는 반드시 void* 인자 한 개가 있어야 합니다.
	// 2. this를 스레드 함수의 인자로 전달해서
	//    static 함수에서는 this를 사용할 수 있게 하는 기술
	static DWORD __stdcall threadMain(void* p)
	{
		//Main();	// 가상함수 호출
		//			// this->Main() => Main(this) 가 되어야 한다.

		// 결국 p가 this이다.
		Thread* pThis = static_cast<Thread*>(p);
		pThis->Main();	// 결국 Main(pThis)가 됩니다.
		return 0;
	}

	virtual void Main()	// void Main(Thread* const this)
	{
	}
};

// 아래 클래스가 라이브러리 사용자 클래스입니다.
class MyThread : public Thread
{
public:
	virtual void Main() override
	{
		cout << "MyThread Main" << endl;
	}
};


int main()
{
	MyThread t;
	t.run();	// 이 순간 스레드가 생성되어서 Main() 가상함수를 실행해야 합니다.
	_getch();
}

//DWORD __stdcall foo(void* p)
//{
//	return 0;
//}
//
//int main()
//{
//	CreateThread(0, 0, foo, "A", 0, 0);
//}