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

	// �ڽ��� ����� static ��� �Լ��� ���� ���� �����ϴ�.
	static Shape* Create() { return new Rect; }
};

class Circle : public Shape
{
public:
	virtual void Draw() override { cout << "Draw Circle" << endl; }

	// �ڽ��� ����� static ��� �Լ��� ���� ���� �����ϴ�.
	static Shape* Create() { return new Circle; }
};

// Rect�� ����� ��
// 1. new Rect
// 2. Rect::Create()

// ���ڿ� ���� �ٸ� ��ü�� ����� �ʹ�.
//void foo(? p)
//{
//	...
//}
//foo(Rect);	// Ŭ���� �̸��� ���ڷ� ���� �� ������?

// => ���丮 �Լ��� �ѱ���
//void foo(Shape*(*f)())
//{
//	f();
//}
//foo(&Rect::Create);


#include <map>

// ������ ����� ������ ������
class ShapeFactory
{
	typedef Shape*(*CREATOR)();

	// ��ǰ ��ȣ�� ��ǰ ���� �Լ��� ��
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
