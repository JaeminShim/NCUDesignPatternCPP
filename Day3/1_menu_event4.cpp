// 1_�޴� �̺�Ʈ
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

// �Ϲ� �Լ� �����͸� �����ϴ� Ŭ����
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

// ��� �Լ� �����͸� �����ϴ� Ŭ����
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

// Ŭ���� ���ø��� �Ͻ��� �߷��� ���� �ʾƼ� �׻� ����� ���Դϴ�.
// �̷� ���� �Ͻ��� �߷��� ������ �Լ� ���ø��� �����ϸ� �˴ϴ�.
template <class T>
MemberCommand<T>* CreateCommand(typename MemberCommand<T>::HANDLER f, T* p)
{
	return new MemberCommand<T>(f, p);
}

// FunctionCommand�� ����� �ִ� cmd
FunctionCommand* CreateCommand(typename FunctionCommand::HANDLER f)
{
	return new FunctionCommand(f);
}


int main()
{
	// �Ϲ� �Լ� ������
	//FunctionCommand fc(&foo);	// foo �ּҸ� �����ϴ� ��ü
	//fc.Execute();				// �ᱹ foo()
	//ICommand* pfc = &fc;

	// ��� �Լ� ������
	Dialog dlg;
	//MemberCommand<Dialog> mc(&dlg, &Dialog::Close);
	//mc.Execute();
	//ICommand* pmc = &mc;

	// ���ø� ���� �Լ� ���
	ICommand* p1 = CreateCommand(&Dialog::Close, &dlg);
	p1->Execute();

	ICommand* p2 = CreateCommand(&foo);
	p2->Execute();
}

//template<typename T> T square(T  a) { return a * a; }
//// ���� �� ���� ����?
//square(3);			// �Ͻ��� �߷� (�����Ϸ�)
//square<int>(3);		// ����� �߷� (�����)
//
//// Ŭ���� ���ø��� �Ͻ��� �߷��� �Ұ���
//list<int> s(10, 3);	// 10���� 3����