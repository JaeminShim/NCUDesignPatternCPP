// 1_��ü�Ǽ���4
#include <iostream>
using namespace std;

// ����: www.pocoproject.org
// ./Foundation/include/Poco/RefCountedObject.h

// ����: objective-c�� ARC(automatic reference count)
//      �����Ϸ��� �����͸� ����Ʈ�����ͷ� ��ȯ�Ͽ� ���


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

// ��ü ������ ���� ����� �ڵ����� �����ϴ� ����Ʈ ������
template <typename T> class sp
{
	T* obj;
public:
	sp(T* p = 0)	: obj(p)		{ obj->AddRef(); }
	sp(const sp& s)	: obj(s.obj)	{ obj->AddRef(); }
	~sp()							{ obj->Release(); }

	// ����Ʈ ������ �⺻: ->�� *
	T* operator->() { return obj; }
	T& operator*() { return *obj; }
};

int main()
{
	sp<Truck> p1 = new Truck;
	sp<Truck> p2 = p1;
}
