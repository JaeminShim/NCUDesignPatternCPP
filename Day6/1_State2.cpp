// 1_State

#include <iostream>
using namespace std;

// �ذ�å 1. ���ϴ� ���� �����Լ��� �����
// ������: ���¿� ������ ��� ����ȴ�.
// ���: Ŭ������ ���� �����̴�. ��ü�� �ƴϴ�.
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