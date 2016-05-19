// 3_abstract_class2	// 58p

#include <iostream>

using namespace std;

// 기능 확장에 열려있고 (Open)
// 코드 수정에 닫혀 있어야 (Close)
// 한다는 이론 (Principle)
// => OCP

// 미래에 새로운 클래스가 추가 되어도 과거의 코드는 수정 되면 안된다.

class Camera
{
public:
	void Take() { cout << "Take a picture with a camera." << endl; }
};

class Camera2
{
public:
	void Take() { cout << "Take a picture with a camera2." << endl; }
};

class People
{
public:
	void UseCamera(Camera* p) { p->Take(); }
	void UseCamera(Camera2* p) { p->Take(); }
};

int main()
{
	Camera c1;
	People p;
	p.UseCamera(&c1);

	Camera2 c2;
	p.UseCamera(&c2);
}