// 1_Decorator5
#include <iostream>
using namespace std;

// GOF's 23�� ���� �� ����� ����(�׸��� ��ü �� �ƴ϶� �׸� ��ü�� ����)
// �� ����� ������ 2�� �Դϴ�.
// Composite: ����� ������ ���, ���� ��ü �����
//            ��> Folder, File ����
// Decorator: ����� ������ ���, ��ü�� ����� �������� �߰��ϱ�
//            ��> ���� + ������� + �۾����
//                java, C#�� Stream��ü

//// ��> java, C#�� ��Ʈ��: Decorator ���� ���
//File f;
//f.write();	// �� ����Ʈ ����
//FileStream fs(f);
//fs.write();	// ��Ʈ������ ����


// �������� ��ü�� ���������� ����� ��ü�� ������ �� �ִ�.

// �������� ��ü�� ������ �θ� �ʿ��ϴ�.
// [Component]
struct Component
{
	virtual ~Component() {}
	virtual void Fire() = 0;
};

// [Concreate Component]
class SpaceShip : public Component
{
	int color;
public:
	virtual void Fire() override
	{
		cout << "^^^" << endl;
	}
};

//-----------------------------------------------

// ��� �߰� ��ü(Decorator)�� ������ Ư¡�� �θ�� ���´�.
// [Decorator]
class IDecorator : public Component
{
	Component* pParent;
public:
	IDecorator(Component* p) : pParent(p) {}
	virtual void Fire() override { pParent->Fire(); }
};

// [Concreate Decorator]
class LeftMissileItem : public IDecorator
{
public:
	LeftMissileItem(Component* p) : IDecorator(p) {}
	void Fire()
	{
		IDecorator::Fire();
		cout << "<<<" << endl;
	}
};

// [Concreate Decorator]
class RightMissileItem : public IDecorator
{
public:
	RightMissileItem(Component* p) : IDecorator(p) {}
	void Fire()
	{
		IDecorator::Fire();
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
