// 1_Decorator
#include <iostream>
using namespace std;

class SpaceShip
{
	int color;
public:
	void Fire() { cout << "^^^" << endl; }
};

int main()
{
	SpaceShip ss;
	ss.Fire();
}
