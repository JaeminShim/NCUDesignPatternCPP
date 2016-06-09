// 1_객체의수명6 : 문법적인 이슈 - const, mutable, volatile, thread-safe
#include <iostream>
#include <Windows.h>
using namespace std;

// 참조 계수를 사용한 수명 관리
class RefCount
{
	volatile mutable long mCount;
public:
	RefCount() : mCount(0) {}
	virtual ~RefCount() { }

	// 참조계수 관리 함수는 반드시 상수 함수 이어야 합니다.
	void AddRef() const { _InterlockedIncrement(&mCount); }
	void Release() const { if (_InterlockedDecrement(&mCount) == 0) delete this; }
};

// Truck도 참조계수로 관리하고 싶다.
// 결론 1. 참조계수 기반으로 수명을 관리하고 싶다면 RefCount의 자식으로 만들면 된다.
class Truck : public RefCount
{
public:
	~Truck() { cout << "~Truck" << endl; }
};

int main()
{
	// 속성을 변경할 수 없는 Truck 객체
	const Truck* p1 = new Truck;
	p1->AddRef();
	p1->Release();
}