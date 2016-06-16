// 1_Decorator4
#include <iostream>
using namespace std;

// �������� ��ü�� ���������� ����� ��ü�� ������ �� �ִ�.

// �������� ��ü�� ������ �θ� �ʿ��ϴ�.
struct Component
{
	virtual ~Component() {}
	virtual void Fire() = 0;
};

class SpaceShip : public Component
{
	int color;
public:
	virtual void Fire() override
	{
		cout << "^^^" << endl;
	}
};

class LeftMissileItem : public Component
{
	Component* pItem;
public:
	LeftMissileItem(Component* p) : pItem(p) {}
	void Fire()
	{
		pItem->Fire();
		cout << "<<<" << endl;
	}
};

class RightMissileItem : public Component
{
	Component* pItem;
public:
	RightMissileItem(Component* p) : pItem(p) {}
	void Fire()
	{
		pItem->Fire();
		cout << ">>>" << endl;
	}
};

int main()
{
	SpaceShip ss;
	//ss.Fire();
	LeftMissileItem lm(&ss);
	//lm.Fire();
	RightMissileItem rm(&lm);
	rm.Fire();
}
