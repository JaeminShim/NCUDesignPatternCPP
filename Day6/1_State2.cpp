// 1_State

#include <iostream>
using namespace std;

// 해결책 1. 변하는 것을 가상함수로 만들기
// 문제점: 상태와 동작이 모두 변경된다.
// 상속: 클래스에 대한 변경이다. 객체가 아니다.
class Character
{
	int gold;
public:
	virtual void Run() { cout << "run" << endl; }
	virtual void Attack() { cout << "attack" << endl; }
};

class FastCharacter : public Character
{
public:
	virtual void Run() override { cout << "fast run" << endl; }
	virtual void Attack() override { cout << "power attack" << endl; }
};

int main()
{
	Character* p = new Character;
	p->Run();

	p = new FastCharacter;
	p->Run();
}