// 1_thiscall4	// 66p

#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

// ��Ƽ ������ ������ Ŭ������ ĸ��ȭ �� ���ô�

// �Ʒ� Ŭ������ ���̺귯�� ���� Ŭ������� �����մϴ�.
class Thread
{
public:
	void run()
	{
		// Parameter�� this�� �ѱ迡 �ָ�
		CreateThread(0, 0, threadMain, this, 0, 0);
	}

	// 1. �Ʒ� �Լ��� static�� ������ ��Ȯ�� �˾ƾ� �մϴ�.
	//    CreateThread()�� ���޵Ǵ� �Լ��� �ݵ�� void* ���� �� ���� �־�� �մϴ�.
	// 2. this�� ������ �Լ��� ���ڷ� �����ؼ�
	//    static �Լ������� this�� ����� �� �ְ� �ϴ� ���
	static DWORD __stdcall threadMain(void* p)
	{
		//Main();	// �����Լ� ȣ��
		//			// this->Main() => Main(this) �� �Ǿ�� �Ѵ�.

		// �ᱹ p�� this�̴�.
		Thread* pThis = static_cast<Thread*>(p);
		pThis->Main();	// �ᱹ Main(pThis)�� �˴ϴ�.
		return 0;
	}

	virtual void Main()	// void Main(Thread* const this)
	{
	}
};

// �Ʒ� Ŭ������ ���̺귯�� ����� Ŭ�����Դϴ�.
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
	t.run();	// �� ���� �����尡 �����Ǿ Main() �����Լ��� �����ؾ� �մϴ�.
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