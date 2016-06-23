// 4_Bridge4

// 소스와 헤더의 관계를 고려해보자.
// 아래 Point.h의 내용이 바뀌면 아래 두 cpp가 재컴파일 되어야 함

// Point.h
class Point
{
	int x, y;
public:
	void print();
};

// point.cpp
#include "Point.h"
void Point::print() {}

// main.cpp
#include "Point.h"

int main()
{
	Point p;
	p.print();
}
