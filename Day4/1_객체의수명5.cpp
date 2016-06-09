// 1_객체의수명5
#include <iostream>
using namespace std;

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

#include <memory>

int main()
{
	//sp<int> p1 = new int;	// 될까요?	=> ERROR! sp는 RefCount의 파생클래스만 사용 가능

	// C++ 표준의 스마트 포인터: 모든 타입에 대해 사용 가능
	//							참조계수를 객체 내부가 아닌 외부에 만든다.
	shared_ptr<int> p2(new int);
	shared_ptr<int> p3 = p2;

	struct Car {};
	// 다음 중 좋은 코드는?	(sp가 RefCount를 상속!받았다고 가정)
	sp<Car> p4(new Car);			// 메모리 할당이 1회
	shared_ptr<Car> p5(new Car);	// 메모리 할당이 2회

	// 그래서 예전에는 shared_ptr<>이 있어도 별도의 스마트포인터를 라이브러리가 제공

	// C++11 부터는
	shared_ptr<int> p6(new int);				// 메모리 할당 2회
	shared_ptr<int> p7 = make_shared<int>();	// 메모리 할당 1회 sizeof(int) + sizeof(참조계수)
												// 크기의 메모리를 한 번에 할당
}
