// 5_Factory
// 과제 3. 프로토타입 팩토리
// 참고
//  - 견본 등록은 자동일 수 없음.
//  - 객체의 속성은 적당히 추가해보자.

#include <iostream>
#include <vector>
#include <map>
using namespace std;

///////////////////////////////////////////////////////////////////////////////

typedef unsigned char BYTE;

struct Color
{
	union
	{
		struct
		{
			BYTE R;
			BYTE G;
			BYTE B;
			BYTE A;
		};
		BYTE bytes[4];
		unsigned long value;
	};

	Color(BYTE r, BYTE g, BYTE b, BYTE a = static_cast<BYTE>(-1))
		: R(r), G(g), B(b), A(a)
	{}

	Color(const Color& other)
		: value(other.value)
	{}

	Color& operator=(const Color& other)
	{
		value = other.value;
		return *this;
	}

	bool operator==(const Color& other) const
	{
		return value == other.value;
	}

	bool operator!=(const Color& other) const
	{
		return value != other.value;
	}

	void Print() const
	{
		if      (White == *this) cout << "White";
		else if (Red   == *this) cout << "Red";
		else if (Green == *this) cout << "Green";
		else if (Blue  == *this) cout << "Blue";
		else if (Black == *this) cout << "Black";
		else
		{
			for (int i = 0; i < _countof(bytes); ++i)
			{
				if (i > 0)
					cout << ", ";
				cout << static_cast<int>(bytes[i]);
			}
		}
	}

	static const Color White;
	static const Color Red;
	static const Color Green;
	static const Color Blue;
	static const Color Black;
};

const Color Color::White = Color(255, 255, 255);
const Color Color::Red   = Color(255,   0,   0);
const Color Color::Green = Color(  0, 255,   0);
const Color Color::Blue  = Color(  0,   0, 255);
const Color Color::Black = Color(  0,   0,   0);

///////////////////////////////////////////////////////////////////////////////

struct Vec2D
{
	int X;
	int Y;

	Vec2D(int x, int y)
		: X(x), Y(y)
	{}

	Vec2D(const Vec2D& other)
		: X(other.X), Y(other.Y)
	{}

	Vec2D& operator=(const Vec2D& other)
	{
		X = other.X;
		Y = other.Y;
		return *this;
	}

	void Print() const
	{
		cout << X << ", " << Y;
	}
};

///////////////////////////////////////////////////////////////////////////////

class Shape
{
public:
	Shape() : color(Color::White), pos(0, 0) {}
	Shape(const Color& c, const Vec2D& p) : color(c), pos(p) {}
	virtual ~Shape() {}

	virtual void Draw() const = 0;
	virtual Shape* Clone() const = 0;	/*{ return new Shape(*this); }*/

protected:
	Color color;
	Vec2D pos;
};

///////////////////////////////////////////////////////////////////////////////

class ShapeFactory
{
public:
	~ShapeFactory()
	{
		ShapeMap::iterator it = prototype_map.begin();
		while (it != prototype_map.end())
		{
			Shape* pShape = it->second;
			it = prototype_map.erase(it);
			if (pShape)
				delete pShape;
		}
	}

	void Register(Shape* f, int id)
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
	typedef map<int, Shape*> ShapeMap;
	ShapeMap prototype_map;
};


///////////////////////////////////////////////////////////////////////////////

// 모든 도형의 규칙을 매크로화 한다.
#define DECLARE_SHAPE_BODY(classname)	\
	public: virtual Shape* Clone() const { return new classname(*this); }

class Rect : public Shape
{
	DECLARE_SHAPE_BODY(Rect);

public:
	Rect(const Color& c, Vec2D p, Vec2D s)
		: Shape(c, p), size(s)
	{}

	Rect(const Color& c, int x, int y, int w, int h)
		: Shape(c, Vec2D(x, y)), size(Vec2D(w, h))
	{}

	Rect(const Rect& other)
		: Shape(other.color, other.pos), size(other.size)
	{}

	virtual void Draw() const override
	{
		cout << "Draw Rectangle(Pos: ";
		pos.Print();
		cout << " / Size: ";
		size.Print();
		cout << " / Color: ";
		color.Print();
		cout << ")" << endl;
	}

private:
	Vec2D size;
};

class Circle : public Shape
{
	DECLARE_SHAPE_BODY(Circle);

public:
	Circle(const Color& c, Vec2D p, int r)
		: Shape(c, p), radius(r)
	{}

	Circle(const Color& c, int x, int y, int r)
		: Shape(c, Vec2D(x, y)), radius(r)
	{}

	Circle(const Circle& other)
		: Shape(other.color, other.pos), radius(other.radius)
	{}

	virtual void Draw() const override
	{
		cout << "Draw Circle(Pos: ";
		pos.Print();
		cout << " / Radius: " << radius;
		cout << " / Color: ";
		color.Print();
		cout << ")" << endl;
	}

private:
	int radius;
};

///////////////////////////////////////////////////////////////////////////////

int main()
{
	ShapeFactory& factory = ShapeFactory::getInstance();

	factory.Register(new Rect(Color::Blue, 0, 0, 100, 100),   1);
	factory.Register(new Rect(Color::Red, 50, 50, 200, 50),   2);
	factory.Register(new Circle(Color::White, 50, 50, 50),    3);
	factory.Register(new Circle(Color::Green, 100, 100, 100), 4);
	factory.Register(new Rect(Color::Black, 10, 20, 30, 40),  5);

	vector<Shape*> v;

	while (1)
	{
		int cmd;
		cout << "- Input a command (0 ~ 9. Quit otherwise): ";
		cin >> cmd;

		if (cin.fail())
			break;

		if (cmd >= 1 && cmd <= 5)
		{
			Shape* p = factory.Create(cmd);
			if (p != nullptr)
			{
				v.push_back(p);
				cout << "Item " << cmd << " is added" << endl;
			}
		}
		else if (cmd == 9)
		{
			system("cls");
			for (int i = 0; i < v.size(); i++)
				v[i]->Draw();
			cout << endl;
		}
	}

	while (!v.empty())
	{
		Shape* pShape = v.back();
		v.pop_back();
		if (pShape)
			delete pShape;
	}
}
