// 3_abstract_class3	// 58p

#include <iostream>

using namespace std;

// 카메라 제작자와 카메라 사용자 사이에
// 지켜야 하는 규칙(약속, 인터페이스)을 먼저 만들자.

// 규칙: "모든 카메라는 아래 클래스로부터 파생되어야 한다." (단순 상속의 느낌)
//   =>  "모든 카메라는 아래 인터페이스를 구현해야 한다." 라고 표현하자.

#define interface struct
interface ICamera
{
	virtual void Take() = 0;
};

// 실제 카메라는 없지만 규칙이 있다.
// 사용자는 규칙대로만 사용하면 된다.
class People
{
public:
	void UseCamera(ICamera* p) { p->Take(); }
};

// 모든 카메라 제작자는 규칙을 지켜야 한다.
class Camera : public ICamera
{
public:
	virtual void Take() override
	{
		cout << "Take a picture with a camera." << endl;
	}
};

class Camera2 : public ICamera
{
public:
	virtual void Take() override
	{
		cout << "Take a picture with a camera2." << endl;
	}
};

int main()
{
	People p;

	Camera c1;
	p.UseCamera(&c1);

	Camera2 c2;
	p.UseCamera(&c2);
}