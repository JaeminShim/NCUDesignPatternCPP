// 1_��ü�Ǽ���6 : �������� �̽� - const, mutable, volatile, thread-safe
#include <iostream>
#include <Windows.h>
using namespace std;

// ���� ����� ����� ���� ����
class RefCount
{
	volatile mutable long mCount;
public:
	RefCount() : mCount(0) {}
	virtual ~RefCount() { }

	// ������� ���� �Լ��� �ݵ�� ��� �Լ� �̾�� �մϴ�.
	void AddRef() const { _InterlockedIncrement(&mCount); }
	void Release() const { if (_InterlockedDecrement(&mCount) == 0) delete this; }
};

// Truck�� ��������� �����ϰ� �ʹ�.
// ��� 1. ������� ������� ������ �����ϰ� �ʹٸ� RefCount�� �ڽ����� ����� �ȴ�.
class Truck : public RefCount
{
public:
	~Truck() { cout << "~Truck" << endl; }
};

int main()
{
	// �Ӽ��� ������ �� ���� Truck ��ü
	const Truck* p1 = new Truck;
	p1->AddRef();
	p1->Release();
}