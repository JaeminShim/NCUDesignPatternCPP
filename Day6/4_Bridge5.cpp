// 4_Bridge4

// PIMPL : Pointer to Implementation
// - ��� ���� �� �ٸ� �ҽ��� �������� �ּ�ȭ �Ѵ�.
// - ���� ������ ���� ����� �������� �ʾƵ� �ǹǷ� �ҽ� �ڵ忡 ���� �Ϻ��� ������ ����������.
//   (DLL, bridge header�� ����)
// - ������ �ð� ��ȭ�� (������ �ð� Bridge ����)


// �ҽ��� ����� ���踦 ����غ���.
// �Ʒ� Point.h�� ������ �ٲ�� �Ʒ� �� cpp�� �������� �Ǿ�� ��

// ������ ���� Ŭ����
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


// ����ڰ� ����ϴ� �߰� ��
// Point.h
class PointImpl;	// Ŭ���� ���� ����. ������ ������ ��� (����� ���)
					// ������ ������ ��� ����.
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
