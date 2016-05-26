// 1_도형편집기2 - 78p

#include <iostream>
#include <vector>
using namespace std;

// 5. OCP 원칙: 나중에 새로운 요소가 추가되어도 기존 코드는 수정되면 안된다.
//             다형성은 OCP를 만족하는 아주 좋은 코드이다.

// 6. Prototype 디자인 패턴
//    : 기존 객체의 복사를 통한 새로운 객체 생성
//      Java의 모든 클래스는 clonable() 함수가 있습니다.
//      iOS 클래스에는 copy() 함수가 있습니다.

// 7. 리팩토링 용어입니다. 생각해 보세요
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
