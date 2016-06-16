// 1_도형편집기 - 78p

#include <iostream>
#include <vector>
using namespace std;

// 도형 편집기로 배우는 객체지향 디자인

// 1. 모든 도형을 타입화 하면 편리하다.
// 2. 모든 도형의 공통의 부모가 있다면 묶어서 관리할 수 있다.
// 3. 모든 도형의 공통의 특징은 반드시 부모(Shape)에도 있어야 한다.
//    그래야 부모로 묶어서 사용할 때 해당 특징을 사용할 수 있다.
//    (LSP : Liskov Substitution Principle)
// 4. 부모의 함수를 자식이 재정의 하게 된다면 반드시 가상함수가 되어야 한다.

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
