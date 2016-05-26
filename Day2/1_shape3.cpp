// 1_도형편집기2 - 78p

#include <iostream>
#include <vector>
using namespace std;

// 8. Template method 패턴
//    : 변하지 않는 전체 흐름은 부모가 비가상함수로 제공
//      변해야 하는 부분만 가상함수화 해서
//      자식이 재정의 할 수 있게 하는 패턴

// 객체지향 패턴 중 가장 널리 사용되는 패턴

class Shape
{
public:
	// 변하지 않는 전체적인 흐름에서 변해야 하는 부분을 찾아서 가상함수로 분리한다.
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

		// 연구과제
		// 1. 객체의 생성 과정을 OCP를 만족하게 할 수 없을까?   (factory pattern)
		// 2. 객체 생성에 대해 Undo/Redo 기능을 넣을 수 없을까? (command pattern)
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
				cout << "몇 번째 도형을 복사할까요? >> ";
				int k;
				cin >> k;

				// k번째 도형의 복사본을 만들어 v에 추가한다.
				// 어떻게 할까요? k번째가 뭘까요?
				v.push_back(v[k]->Clone());
			}
			break;
		case 9:
			for (int i = 0; i < v.size(); i++)
			{
				// 다형성 (polymorphism)
				// 동일 함수 호출이 상황(객체)에 따라 다른 함수를 호출하는 것
				v[i]->Draw();
			}
			break;
		}
	}
}
