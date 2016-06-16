// 1_Decorator3
#include <iostream>
using namespace std;

class SpaceShip
{
	int color;
public:
	void Fire() { cout << "^^^" << endl; }
};

// 포함을 사용한 기능 추가
// => 실행 시간에 동적으로 기능을 추가
//    클래스가 아닌 객체에 기능 추가
class LeftMissileItem
{
	SpaceShip* pShip;	// 핵심: 값 타입이 아닌 포인터 타입
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
