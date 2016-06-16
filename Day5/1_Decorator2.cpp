// 1_Decorator2
#include <iostream>
using namespace std;

class SpaceShip
{
	int color;
public:
	void Fire() { cout << "^^^" << endl; }
};

// ����� ����� ��� �߰�
// => �������� Ŭ������ ����� �߰��ϴ� ��.
class LeftMissileItem : public SpaceShip
{
public:
	void Fire()
	{
		SpaceShip::Fire();		// ���� ��� ����
		cout << "<<<" << endl;	// ��� �߰�
	}
};

int main()
{
	SpaceShip ss;
	ss.Fire();
	LeftMissileItem lm;
	lm.Fire();
}
