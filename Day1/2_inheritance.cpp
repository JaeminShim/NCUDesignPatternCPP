// 2_»ó¼Ó - 45p

#include <iostream>

using namespace std;

class Base
{
public:
	Base()				{ cout << "Base()"		<< endl; }
	Base(int a)			{ cout << "Base(int a)"	<< endl; }
	virtual ~Base()		{ cout << "~Base()"		<< endl; }
};

class Derived : public Base
{
public:
	Derived()					{ cout << "Derived()"		<< endl; }
	// => Derived() : Base()	{ cout << "Derived()" << endl; }
	Derived(int a) : Base(a)	{ cout << "Derived(int a)"	<< endl; }
	virtual ~Derived()			{ cout << "~Derived()"		<< endl; }
	// => ~Derived()			{ cout << "~Derived()" << endl; ~Base(); }
};

int main()
{
	Derived d(5);
}