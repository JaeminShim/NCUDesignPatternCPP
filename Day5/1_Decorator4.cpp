// 1_Decorator4
#include <iostream>
using namespace std;

// 포장지는 객체를 포장하지만 포장된 객체도 포장할 수 있다.

// 포장지와 객체는 공통의 부모가 필요하다.
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
