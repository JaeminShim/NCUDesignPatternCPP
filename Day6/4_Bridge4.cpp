// 4_Bridge4

// �ҽ��� ����� ���踦 ����غ���.
// �Ʒ� Point.h�� ������ �ٲ�� �Ʒ� �� cpp�� �������� �Ǿ�� ��

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
