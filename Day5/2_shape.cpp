// 1_���������� - 78p

#include <iostream>
#include <vector>
using namespace std;

// ���� ������� ���� ��ü���� ������

// 1. ��� ������ Ÿ��ȭ �ϸ� ���ϴ�.
// 2. ��� ������ ������ �θ� �ִٸ� ��� ������ �� �ִ�.
// 3. ��� ������ ������ Ư¡�� �ݵ�� �θ�(Shape)���� �־�� �Ѵ�.
//    �׷��� �θ�� ��� ����� �� �ش� Ư¡�� ����� �� �ִ�.
//    (LSP : Liskov Substitution Principle)
// 4. �θ��� �Լ��� �ڽ��� ������ �ϰ� �ȴٸ� �ݵ�� �����Լ��� �Ǿ�� �Ѵ�.

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

int main()
{
	vector<Shape*> v;

	while (1)
	{
		int cmd;
		cin >> cmd;

		if		(cmd == 1) v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);
		else if (cmd == 9)
		{
			for (int i = 0; i < v.size(); i++)
				v[i]->Draw();
		}
	}
}
