// 5_Factory4

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Shape
{
public:
	virtual void Draw() const = 0;
	virtual Shape* Clone() const = 0;	/*{ return new Shape(*this); }*/
};

class ShapeFactory
{
public:
	void Register(int id, Shape* f)
	{
		prototype_map[id] = f;
	}

	Shape* Create(int id)
	{
		Shape* p = nullptr;
		if (prototype_map[id] != nullptr)
			p = prototype_map[id]->Clone();
		return p;
	}

	static ShapeFactory& getInstance()
	{
		static ShapeFactory instance;
		return instance;
	}

private:
	map<int, Shape*> prototype_map;		// Prototype factory	// 프로토타입 사용
};

//// 도형을 자동으로 등록해주는 헬퍼 클래스
//class RegisterShape
//{
//public:
//	RegisterShape(int n, typename ShapeFactory::CREATOR f)
//	{
//		ShapeFactory& factory = ShapeFactory::getInstance();
//		factory.Register(n, f);
//	}
//};
//
////RegisterShape rs(1, &Rect::Create);	// 이 순간 도형에 공장에 등록됩니다.


// 모든 도형의 규칙을 매크로화 한다.
#define DECLARE_SHAPE_BODY(classname)										\
	public: virtual Shape* Clone() const { return new classname(*this); }	\
	static Shape* Create() { return new classname; }


class Rect : public Shape
{
	DECLARE_SHAPE_BODY(Rect);

public:
	virtual void Draw() const override { cout << "Draw Rect" << endl; }
};

class Circle : public Shape
{
	DECLARE_SHAPE_BODY(Circle);

public:
	virtual void Draw() const override { cout << "Draw Circle" << endl; }
};


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
