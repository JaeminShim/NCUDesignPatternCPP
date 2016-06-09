// 1_��ü�Ǽ���3
#include <iostream>
using namespace std;

// ���� ����� ����� ���� ����
class RefCount
{
	int mCount;
public:
	RefCount() : mCount(0) {}
	virtual ~RefCount() { }

	void AddRef() { ++mCount; }
	void Release() { if (--mCount == 0) delete this; }
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
	Truck* p1 = new Truck;
	p1->AddRef();		// ��Ģ 1. ��ü ���� �� ������� ����
	Truck* p2 = p1;
	p2->AddRef();		// ��Ģ 2. ��ü ������ ���� �� ������� ����

	p2->Release();		// ��Ģ 3. ��� �Ŀ��� ������� ����
	p1->Release();
}