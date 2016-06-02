// 1_메뉴 이벤트
#include <iostream>
using namespace std;

class Dialog
{
public:
	void Close() { cout << "Dialog close" << endl; }
};

void foo() { cout << "foo" << endl; }

//---------------------------------------------------

struct ICommand
{
	virtual ~ICommand() {}
	virtual void Execute() = 0;
};

// 일반 함수 포인터를 관리하는 클래스
class FunctionCommand : public ICommand
{
public:
	typedef void(*HANDLER)();
private:
	HANDLER handler;

public:
	FunctionCommand(HANDLER h)
		: handler(h)
	{
	}

	virtual void Execute() override
	{
		handler();
	}
};

// 멤버 함수 포인터를 관리하는 클래스
template <class T>
class MemberCommand : public ICommand
{
public:
	typedef void (T::*HANDLER)();
private:
	HANDLER handler;
	T*  target;

public:
	MemberCommand(HANDLER h, T* p)
		: handler(h), target(p)
	{
	}

	virtual void Execute() override
	{
		(target->*handler)();
	}
};

// 클래스 템플릿은 암시적 추론이 되지 않아서 항상 어려워 보입니다.
// 이럴 때는 암시적 추론이 가능한 함수 템플릿을 도입하면 됩니다.
template <class T>
MemberCommand<T>* CreateCommand(typename MemberCommand<T>::HANDLER f, T* p)
{
	return new MemberCommand<T>(f, p);
}

// FunctionCommand를 만들어 주는 cmd
FunctionCommand* CreateCommand(typename FunctionCommand::HANDLER f)
{
	return new FunctionCommand(f);
}


int main()
{
	// 일반 함수 포인터
	//FunctionCommand fc(&foo);	// foo 주소를 관리하는 객체
	//fc.Execute();				// 결국 foo()
	//ICommand* pfc = &fc;

	// 멤버 함수 포인터
	Dialog dlg;
	//MemberCommand<Dialog> mc(&dlg, &Dialog::Close);
	//mc.Execute();
	//ICommand* pmc = &mc;

	// 템플릿 헬퍼 함수 사용
	ICommand* p1 = CreateCommand(&Dialog::Close, &dlg);
	p1->Execute();

	ICommand* p2 = CreateCommand(&foo);
	p2->Execute();
}

//template<typename T> T square(T  a) { return a * a; }
//// 다음 중 쉬운 것은?
//square(3);			// 암시적 추론 (컴파일러)
//square<int>(3);		// 명시적 추론 (사용자)
//
//// 클래스 템플릿은 암시적 추론이 불가능
//list<int> s(10, 3);	// 10개를 3으로