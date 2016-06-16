// 1_Decorator3
#include <iostream>
using namespace std;

class SpaceShip
{
	int color;
public:
	void Fire() { cout << "^^^" << endl; }
};

// ������ ����� ��� �߰�
// => ���� �ð��� �������� ����� �߰�
//    Ŭ������ �ƴ� ��ü�� ��� �߰�
class LeftMissileItem
{
	SpaceShip* pShip;	// �ٽ�: �� Ÿ���� �ƴ� ������ Ÿ��
public:
	LeftMissileItem(SpaceShip* p) : pShip(p) {}
	void Fire()
	{
		pShip->Fire();
		cout << "<<<" << endl;
	}
};

int main()
{
	SpaceShip ss;
	ss.Fire();
	LeftMissileItem lm(&ss);
	lm.Fire();
}
