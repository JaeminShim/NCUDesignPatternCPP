// 1_메뉴 이벤트2	// 88p
#include <iostream>
#include <vector>
using namespace std;

// 방법 1. 리스너 개념, java나 안드로이드 앱에서 널리 사용.

// 메뉴를 처리하고 싶은 클래스는 반드시 아래 인터페이스를 구현해야 한다.
struct IMenuListener
{
	// 리슨 이벤트는 호출자의 ID가 필요하다.
	virtual void onCommand(int id) = 0;

	// 부모의 소멸자는 가상 소멸자이어야 한다. C++ 기본 문법
	virtual ~IMenuListener() {}
};

class MenuItem
{
	int id;
	vector<IMenuListener*> listeners;

public:
	MenuItem(int n) : id(n) {}

	void addListener(IMenuListener* p)
	{
		listeners.push_back(p);
	}

	virtual void command()
	{
		// 메뉴가 선택된 사실을 외부에 알려야 한다.
		// 객체가 외부에 이벤트를 발생.
		for (auto pListener : listeners)
			pListener->onCommand(id);	// 외부에 알린다
	}
};

//---------------------------------------------------
class Camera : public IMenuListener
{
public:
	virtual void onCommand(int id) override
	{
		// Switch 문이 필요 => OCP를 만족할 수 없음!
		//switch (id)
		//{
		//}
		cout << "Camera 메뉴 선택 됨 " << id << endl;
	}
};

int main()
{
	Camera cam;
	MenuItem m1(11), m2(22);

	m1.addListener(&cam);	// 메뉴 선택을 처리할 리스너 객체 등록
	m2.addListener(&cam);

	m1.command();
	m2.command();
}