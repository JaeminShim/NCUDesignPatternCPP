// 1_객체의수명3
#include <iostream>
using namespace std;

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

int main()
{
	Truck* p1 = new Truck;
	p1->AddRef();		// 규칙 1. 객체 생성 후 참조계수 증가
	Truck* p2 = p1;
	p2->AddRef();		// 규칙 2. 객체 포인터 복사 후 참조계수 증가

	p2->Release();		// 규칙 3. 사용 후에는 참조계수 감소
	p1->Release();
}