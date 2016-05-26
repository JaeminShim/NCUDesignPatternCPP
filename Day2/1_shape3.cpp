// 1_����������2 - 78p

#include <iostream>
#include <vector>
using namespace std;

// 8. Template method ����
//    : ������ �ʴ� ��ü �帧�� �θ� �񰡻��Լ��� ����
//      ���ؾ� �ϴ� �κи� �����Լ�ȭ �ؼ�
//      �ڽ��� ������ �� �� �ְ� �ϴ� ����

// ��ü���� ���� �� ���� �θ� ���Ǵ� ����

class Shape
{
public:
	// ������ �ʴ� ��ü���� �帧���� ���ؾ� �ϴ� �κ��� ã�Ƽ� �����Լ��� �и��Ѵ�.
	virtual void DrawImpl() const
	{
		cout << "Draw Shape" << endl;
	}

	void Draw() const
	{
		cout << "mutex lock" << endl;
		DrawImpl();
		cout << "mutex unlock" << endl;
	}

	virtual Shape* Clone() const { return new Shape(*this); }
};

class Rect : public Shape
{
public:
	virtual void DrawImpl() const override { cout << "Draw Rect" << endl; }
	virtual Shape* Clone() const override { return new Rect(*this); }
};

class Circle : public Shape
{
public:
	virtual void DrawImpl() const override { cout << "Draw Circle" << endl; }
	virtual Shape* Clone() const override { return new Circle(*this); }
};

class Triangle : public Shape
{
public:
	virtual void DrawImpl() const override { cout << "Draw Triangle" << endl; }
	virtual Shape* Clone() const override { return new Triangle(*this); }
};

int main()
{
	vector<Shape*> v;

	while (1)
	{
		int cmd;
		cin >> cmd;

		// ��������
		// 1. ��ü�� ���� ������ OCP�� �����ϰ� �� �� ������?   (factory pattern)
		// 2. ��ü ������ ���� Undo/Redo ����� ���� �� ������? (command pattern)
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
