// 6_singleton
#include <iostream>
using namespace std;

class Cursor
{
	Cursor() {}
	Cursor(const Cursor&) = delete;
	void operator=(const Cursor&) = delete;

public:
	static Cursor& getInstance()
	{
		static Cursor instance;
		return instance;
	}
};

int main()
{
	Cursor& c1 = Cursor::getInstance();
}