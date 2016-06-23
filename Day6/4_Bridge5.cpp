// 4_Bridge4

// PIMPL : Pointer to Implementation
// - 헤더 변경 시 다른 소스의 컴파일을 최소화 한다.
// - 실제 구현을 담은 헤더를 배포하지 않아도 되므로 소스 코드에 대한 완벽한 은닉이 가능해진다.
//   (DLL, bridge header만 제공)
// - 컴파일 시간 방화벽 (컴파일 시간 Bridge 패턴)


// 소스와 헤더의 관계를 고려해보자.
// 아래 Point.h의 내용이 바뀌면 아래 두 cpp가 재컴파일 되어야 함

// 구현을 담은 클래스
// PointImpl.h
class PointImpl
{
	int x, y;
public:
	void print();
};

// PointImpl.cpp
#include "PointImpl.h"
void PointImpl::print() {}


// 사용자가 사용하는 중간 층
// Point.h
class PointImpl;	// 클래스 전방 선언. 완전한 선언이 없어도 (헤더가 없어도)
					// 포인터 변수는 사용 가능.
class Point
{
	PointImpl* pImpl;
public:
	Point();
	void print();
};

// Point.cpp
#include "PointImpl.h"
#include "Point.h"
Point::Point() { pImpl = new PointImpl; }
void Point::print() { pImpl->print(); }


// main.cpp
#include "Point.h"

int main()
{
	Point p;
	p.print();
}
