// 1_��ü�Ǽ���2
#include <iostream>
using namespace std;

// ���� ����� ����� ���� ����
class Car
{
	int refCount;
public:
	Car() : refCount(0) {}
	~Car() { cout << "Car �ı�" << endl; }

	void AddRef() { ++refCount; }
	void Release() { if (--refCount == 0) delete this; }
};

int main()
{
	Car* p1 = new Car;
	p1->AddRef();		// ��Ģ 1. ��ü ���� �� ������� ����
	Car* p2 = p1;
	p2->AddRef();		// ��Ģ 2. ��ü ������ ���� �� ������� ����

	p2->Release();		// ��Ģ 3. ��� �Ŀ��� ������� ����
	p1->Release();
}