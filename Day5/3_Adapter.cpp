// 3_Adapter
// (참고: vector를 사용한 stack 구현)

#include <iostream>
#include <vector>
using namespace std;

// 기존에 문자열을 화면에 출력해 주는 클래스가 이미 있었습니다.
#include <string>
class StringView
{
	string data;
public:
	StringView(string s) : data(s) {}

	void Show() { cout << data << endl; }
};


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


// StringView를 도형 편집기에서 사용할 수 있도록 인터페이스를 변경한다.
// Show => Draw로 변경

// 1. 클래스 어답터: 클래스의 인터페이스를 변경하는 것
//                 일반적으로 다중 상속의 형태로 구현된다.
//                 원본 객체와 요구 조건을 담은 인터페이스를 다중 상속 받게 된다.
class Text : public StringView, public Shape
{
public:
	Text(string s) : StringView(s) {}

	virtual void Draw() override
	{
		StringView::Show();
	}
};

// 객체 어답터를 만들어 보세요.
class Text2 : public Shape
{
	StringView* stringView;
public:
	Text2(StringView* s) : stringView(s) {}

	virtual void Draw()
	{
		stringView->Show();
	}
};

// 2. 객체 어답터


int main()
{
	//// 클래스 어답터
	//vector<Shape*> v;
	//v.push_back(new Text("hello"));
	//v[0]->Draw();

	// 객체 어답터
	StringView sv("hello");
	Text2 txt(&sv);

	vector<Shape*> v;
	v.push_back(&txt);
	v[0]->Draw();
}
