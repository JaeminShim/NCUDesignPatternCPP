// 1_Decorator5
#include <iostream>
using namespace std;

// GOF's 23개 패턴 중 재귀적 포함(그릇은 객체 뿐 아니라 그릇 자체도 포함)
// 을 사용한 패턴은 2개 입니다.
// Composite: 재귀적 포함을 사용, 복합 객체 만들기
//            예> Folder, File 관계
// Decorator: 재귀적 포함을 사용, 객체의 기능을 동적으로 추가하기
//            예> 사진 + 액자장식 + 글씨장식
//                java, C#의 Stream객체

//// 예> java, C#의 스트림: Decorator 패턴 사용
//File f;
//f.write();	// 한 바이트 쓰기
//FileStream fs(f);
//fs.write();	// 스트림으로 쓰기


// 포장지는 객체를 포장하지만 포장된 객체도 포장할 수 있다.

// 포장지와 객체는 공통의 부모가 필요하다.
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

// 기능 추가 객체(Decorator)의 공통의 특징을 부모로 묶는다.
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
