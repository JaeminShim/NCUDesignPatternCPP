// 1_객체의수명2
#include <iostream>
using namespace std;

// 참조 계수를 사용한 수명 관리
class Car
{
	int refCount;
public:
	Car() : refCount(0) {}
	~Car() { cout << "Car 파괴" << endl; }

	void AddRef() { ++refCount; }
	void Release() { if (--refCount == 0) delete this; }
};

int main()
{
	Car* p1 = new Car;
	p1->AddRef();		// 규칙 1. 객체 생성 후 참조계수 증가
	Car* p2 = p1;
	p2->AddRef();		// 규칙 2. 객체 포인터 복사 후 참조계수 증가

	p2->Release();		// 규칙 3. 사용 후에는 참조계수 감소
	p1->Release();
}