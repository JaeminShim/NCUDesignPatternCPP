// 1_객체의 수명
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
	delete p;	// 이렇게 해도 될까?
}

int main()
{
	foo();
}