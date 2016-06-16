// 5_Factory4

#include <iostream>
#include <vector>
using namespace std;

class Shape
{
public:
	virtual void Draw() = 0;
	virtual Shape* Clone() { return new Shape(*this); }
};

#include <map>

// 도형을 만드는 공장을 만들자
class ShapeFactory
{
public:
	typedef Shape*(*CREATOR)();
private:
	// 제품 번호와 제품 생성 함수의 맵
	map<int, CREATOR> create_map;		// Factory				// 생성 함수 사용
	map<int, Shape*> prototype_map;		// Prototype factory	// 프로토타입 사용

public:
	void Register(int n, CREATOR f)
	{
		create_map[n] = f;
	}

	Shape* Create(int n)
	{
		Shape* p = 0;
		if (create_map[n] != 0)
			p = create_map[n]();
		return p;
	}

	static ShapeFactory& getInstance()
	{
		static ShapeFactory instance;
		return instance;
	}
};

// 도형을 자동으로 등록해주는 헬퍼 클래스
class RegisterShape
{
public:
	RegisterShape(int n, typename ShapeFactory::CREATOR f)
	{
		ShapeFactory& factory = ShapeFactory::getInstance();
		factory.Register(n, f);
	}
};

//RegisterShape rs(1, &Rect::Create);	// 이 순간 도형에 공장에 등록됩니다.


class Rect : public Shape
{
public:
	virtual void Draw() override { cout << "Draw Rect" << endl; }

	// 규칙
	// 1. 모든 도형은 Create() static 함수가 있어야 한다.
	// 2. 모든 도형은 static 변수로 RegisterShape가 있어야 한다.
	static Shape* Create() { return new Rect; }
	static RegisterShape rs;
};
RegisterShape Rect::rs(1, &Rect::Create);

// 모든 도형의 규칙을 매크로화 한다.
#define DECLARE_DYN_REGISTER(classname)					\
	static Shape* Create() { return new classname; }	\
	static RegisterShape rs 
#define IMPLEMENT_DYN_REGISTER(classname, num)			\
	RegisterShape classname::rs(num, &classname::Create)

class Circle : public Shape
{
public:
	virtual void Draw() override { cout << "Draw Circle" << endl; }

	// 자신을 만드는 static 멤버 함수는 좋을 때가 많습니다.
	DECLARE_DYN_REGISTER(Circle);
};
IMPLEMENT_DYN_REGISTER(Circle, 2);


int main()
{
	ShapeFactory& factory = ShapeFactory::getInstance();

	// further thinkings
	// 과제 3. 프로토타입 팩토리
	// 참고
	//  - 견본 등록은 자동일 수 없음.
	//  - 객체의 속성은 적당히 추가해보자.
	Rect* p1 = new Rect("파란색", 10);
	Rect* p2 = new Rect("빨간색", 20);
	factory.Register(p1, 1);
	factory.Register(p2, 2);
	Rect* p3 = factory.CreateShapeWithSample(1);


	vector<Shape*> v;

	while (1)
	{
		int cmd;
		cin >> cmd;

		if (cmd >= 1 && cmd <= 5)
		{
			Shape* p = factory.Create(cmd);
			if (p != 0)
				v.push_back(p);
		}
		else if (cmd == 9)
		{
			for (int i = 0; i < v.size(); i++)
				v[i]->Draw();
		}
	}
}
