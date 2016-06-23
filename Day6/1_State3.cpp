// 1_State

// Strategy pattern	: �˰����� ��ȭ (Day2 - 2_LineEdit)
// State pattern	: ���¿� ���� ������ ��ȭ
// Builder pattern	: ������ ����...

#include <iostream>
using namespace std;

// �ذ�å 2. ���ϴ� ���� �ٸ� Ŭ������
// ������ ȹ�� �� ���۸� ����ȴ�. ���ϴ� ������ �������̽�
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