// 1_Decorator2
#include <iostream>
using namespace std;

class SpaceShip
{
	int color;
public:
	void Fire() { cout << "^^^" << endl; }
};

// 상속을 사용한 기능 추가
// => 정적으로 클래스에 기능을 추가하는 것.
class LeftMissileItem : public SpaceShip
{
public:
	void Fire()
	{
		SpaceShip::Fire();		// 원래 기능 수행
		cout << "<<<" << endl;	// 기능 추가
	}
};

int main()
{
	SpaceShip ss;
	ss.Fire();
	LeftMissileItem lm;
	lm.Fire();
}
