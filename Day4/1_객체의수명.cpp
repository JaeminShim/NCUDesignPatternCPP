// 1_��ü�� ����
#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Car {};
vector<Car*> v;
list<Car*> s;

void foo()
{
	Car* p = new Car;
	v.push_back(p);
	s.push_back(p);
	delete p;	// �̷��� �ص� �ɱ�?
}

int main()
{
	foo();
}