// 5_Factory
// 참고: Factory method pattern과 Abstract factory pattern은 있지만
//      Factory pattern은 없다.

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
};

class Circle : public Shape
{
public:
	virtual void Draw() override { cout << "Draw Circle" << endl; }
};

// 도형을 만드는 공장을 만들자

// 여전히 switch-case를 사용하지만
// 반복 사용 시 변화해야 하는 코드는 최소화 됨 (팩토리만 수정하면 됨)
class ShapeFactory
{
public:
	Shape* Create(int n)
	{
		Shape* p = 0;
		switch (n)
		{
		case 1:
			p = new Rect;
			break;
		case 2:
			p = new Circle;
			break;
		}
		return p;
	}
};


int main()
{
	ShapeFactory factory;
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
