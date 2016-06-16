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

// ������ ����� ������ ������
class ShapeFactory
{
public:
	typedef Shape*(*CREATOR)();
private:
	// ��ǰ ��ȣ�� ��ǰ ���� �Լ��� ��
	map<int, CREATOR> create_map;		// Factory				// ���� �Լ� ���
	map<int, Shape*> prototype_map;		// Prototype factory	// ������Ÿ�� ���

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

// ������ �ڵ����� ������ִ� ���� Ŭ����
class RegisterShape
{
public:
	RegisterShape(int n, typename ShapeFactory::CREATOR f)
	{
		ShapeFactory& factory = ShapeFactory::getInstance();
		factory.Register(n, f);
	}
};

//RegisterShape rs(1, &Rect::Create);	// �� ���� ������ ���忡 ��ϵ˴ϴ�.


class Rect : public Shape
{
public:
	virtual void Draw() override { cout << "Draw Rect" << endl; }

	// ��Ģ
	// 1. ��� ������ Create() static �Լ��� �־�� �Ѵ�.
	// 2. ��� ������ static ������ RegisterShape�� �־�� �Ѵ�.
	static Shape* Create() { return new Rect; }
	static RegisterShape rs;
};
RegisterShape Rect::rs(1, &Rect::Create);

// ��� ������ ��Ģ�� ��ũ��ȭ �Ѵ�.
#define DECLARE_DYN_REGISTER(classname)					\
	static Shape* Create() { return new classname; }	\
	static RegisterShape rs 
#define IMPLEMENT_DYN_REGISTER(classname, num)			\
	RegisterShape classname::rs(num, &classname::Create)

class Circle : public Shape
{
public:
	virtual void Draw() override { cout << "Draw Circle" << endl; }

	// �ڽ��� ����� static ��� �Լ��� ���� ���� �����ϴ�.
	DECLARE_DYN_REGISTER(Circle);
};
IMPLEMENT_DYN_REGISTER(Circle, 2);


int main()
{
	ShapeFactory& factory = ShapeFactory::getInstance();

	// further thinkings
	// ���� 3. ������Ÿ�� ���丮
	// ����
	//  - �ߺ� ����� �ڵ��� �� ����.
	//  - ��ü�� �Ӽ��� ������ �߰��غ���.
	Rect* p1 = new Rect("�Ķ���", 10);
	Rect* p2 = new Rect("������", 20);
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
