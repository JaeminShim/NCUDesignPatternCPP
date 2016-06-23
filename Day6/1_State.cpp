// 1_State

#include <iostream>
using namespace std;

// 골드를 일정 이상 먹으면 빠르게 움직이고 싶다.
// 상태에 따른 동작이 바뀔 필요가 있다.

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