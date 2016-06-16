// 5_Factory2

#include <iostream>
#include <vector>
using namespace std;

class Shape
{
public:
	virtual void Draw() = 0;
};

class Rect : public Shape
{
public:
	virtual void Draw() override { cout << "Draw Rect" << endl; }

	// 자신을 만드는 static 멤버 함수는 좋을 때가 많습니다.
	static Shape* Create() { return new Rect; }
};

class Circle : public Shape
{
public:
	virtual void Draw() override { cout << "Draw Circle" << endl; }

	// 자신을 만드는 static 멤버 함수는 좋을 때가 많습니다.
	static Shape* Create() { return new Circle; }
};

// Rect를 만드는 법
// 1. new Rect
// 2. Rect::Create()

// 인자에 따라 다른 객체를 만들고 싶다.
//void foo(? p)
//{
//	...
//}
//foo(Rect);	// 클래스 이름을 인자로 보낼 수 있을까?

// => 팩토리 함수를 넘기자
//void foo(Shape*(*f)())
//{
//	f();
//}
//foo(&Rect::Create);


#include <map>

// 도형을 만드는 공장을 만들자
class ShapeFactory
{
	typedef Shape*(*CREATOR)();

	// 제품 번호와 제품 생성 함수의 맵
	map<int, CREATOR> create_map;

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
};


int main()
{
	ShapeFactory factory;

	factory.Register(1, &Rect::Create);
	factory.Register(2, &Circle::Create);

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
