// 1_객체의수명4
#include <iostream>
using namespace std;

// 참조: www.pocoproject.org
// ./Foundation/include/Poco/RefCountedObject.h

// 참조: objective-c의 ARC(automatic reference count)
//      컴파일러가 포인터를 스마트포인터로 변환하여 사용


// 참조 계수를 사용한 수명 관리
class RefCount
{
	int mCount;
public:
	RefCount() : mCount(0) {}
	virtual ~RefCount() { }

	void AddRef() { ++mCount; }
	void Release() { if (--mCount == 0) delete this; }
};

// Truck도 참조계수로 관리하고 싶다.
// 결론 1. 참조계수 기반으로 수명을 관리하고 싶다면 RefCount의 자식으로 만들면 된다.
class Truck : public RefCount
{
public:
	~Truck() { cout << "~Truck" << endl; }
};

// 객체 내부의 참조 계수를 자동으로 관리하는 스마트 포인터
template <typename T> class sp
{
	T* obj;
public:
	sp(T* p = 0)	: obj(p)		{ obj->AddRef(); }
	sp(const sp& s)	: obj(s.obj)	{ obj->AddRef(); }
	~sp()							{ obj->Release(); }

	// 스마트 포인터 기본: ->와 *
	T* operator->() { return obj; }
	T& operator*() { return *obj; }
};

int main()
{
	sp<Truck> p1 = new Truck;
	sp<Truck> p2 = p1;
}
