// 1_State

// Strategy pattern	: 알고리즘이 변화 (Day2 - 2_LineEdit)
// State pattern	: 상태에 따라 동작이 변화
// Builder pattern	: 다음에 설명...

#include <iostream>
using namespace std;

// 해결책 2. 변하는 것을 다른 클래스로
// 아이템 획득 시 동작만 변경된다. 변하는 동작의 인터페이스
struct IState
{
	virtual ~IState() {}
	virtual void Run() = 0;
	virtual void Attack() = 0;
};

class Character
{
	int gold;
	IState* pState;

public:
	void SetState(IState* p) { pState = p; }
	void Run() { pState->Run(); }
	void Attack() { pState->Attack(); }
};

struct NormalState : public IState
{
	virtual void Run() { cout << "run" << endl; }
	virtual void Attack() { cout << "attack" << endl; }
};

struct FastState : public IState
{
	virtual void Run() { cout << "fast run" << endl; }
	virtual void Attack() { cout << "power attack" << endl; }
};

int main()
{
	NormalState sNormal;
	FastState sFast;

	Character* p = new Character;
	p->SetState(&sNormal);
	p->Run();

	p->SetState(&sFast);
	p->Run();
}