// 1_State

#include <iostream>
using namespace std;

// ��带 ���� �̻� ������ ������ �����̰� �ʹ�.
// ���¿� ���� ������ �ٲ� �ʿ䰡 �ִ�.

class Character
{
	int gold;
public:
	void Run() { cout << "run" << endl; }
	void Attack() { cout << "attack" << endl; }
};

int main()
{
	Character c;
	c.Run();
}