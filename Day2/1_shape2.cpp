// 1_����������2 - 78p

#include <iostream>
#include <vector>
using namespace std;

// 5. OCP ��Ģ: ���߿� ���ο� ��Ұ� �߰��Ǿ ���� �ڵ�� �����Ǹ� �ȵȴ�.
//             �������� OCP�� �����ϴ� ���� ���� �ڵ��̴�.

// 6. Prototype ������ ����
//    : ���� ��ü�� ���縦 ���� ���ο� ��ü ����
//      Java�� ��� Ŭ������ clonable() �Լ��� �ֽ��ϴ�.
//      iOS Ŭ�������� copy() �Լ��� �ֽ��ϴ�.

// 7. �����丵 ����Դϴ�. ������ ������
//    "Replace type code with polymorphism."

class Shape
{
public:
	virtual void Draw() const { cout << "Draw Shape" << endl; }
	virtual Shape* Clone() const { return new Shape(*this); }
};

class Rect : public Shape
{
public:
	virtual void Draw() const override { cout << "Draw Rect" << endl; }
	virtual Shape* Clone() const override { return new Rect(*this); }
};

class Circle : public Shape
{
public:
	virtual void Draw() const override { cout << "Draw Circle" << endl; }
	virtual Shape* Clone() const override { return new Circle(*this); }
};

class Triangle : public Shape
{
public:
	virtual void Draw() const override { cout << "Draw Triangle" << endl; }
	virtual Shape* Clone() const override { return new Triangle(*this); }
};

int main()
{
	vector<Shape*> v;

	while (1)
	{
		int cmd;
		cin >> cmd;

		switch (cmd)
		{
		case 1:
			v.push_back(new Rect);
			break;
		case 2:
			v.push_back(new Circle);
			break;
		case 8:
			{
				cout << "�� ��° ������ �����ұ��? >> ";
				int k;
				cin >> k;

				// k��° ������ ���纻�� ����� v�� �߰��Ѵ�.
				// ��� �ұ��? k��°�� �����?
				v.push_back(v[k]->Clone());
			}
			break;
		case 9:
			for (int i = 0; i < v.size(); i++)
			{
				// ������ (polymorphism)
				// ���� �Լ� ȣ���� ��Ȳ(��ü)�� ���� �ٸ� �Լ��� ȣ���ϴ� ��
				v[i]->Draw();
			}
			break;
		}
	}
}
