// 5_Factory
// ����: Factory method pattern�� Abstract factory pattern�� ������
//      Factory pattern�� ����.

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

// ������ ����� ������ ������

// ������ switch-case�� ���������
// �ݺ� ��� �� ��ȭ�ؾ� �ϴ� �ڵ�� �ּ�ȭ �� (���丮�� �����ϸ� ��)
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
