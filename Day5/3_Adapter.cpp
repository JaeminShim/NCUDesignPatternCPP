// 3_Adapter
// (����: vector�� ����� stack ����)

#include <iostream>
#include <vector>
using namespace std;

// ������ ���ڿ��� ȭ�鿡 ����� �ִ� Ŭ������ �̹� �־����ϴ�.
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


// StringView�� ���� �����⿡�� ����� �� �ֵ��� �������̽��� �����Ѵ�.
// Show => Draw�� ����

// 1. Ŭ���� �����: Ŭ������ �������̽��� �����ϴ� ��
//                 �Ϲ������� ���� ����� ���·� �����ȴ�.
//                 ���� ��ü�� �䱸 ������ ���� �������̽��� ���� ��� �ް� �ȴ�.
class Text : public StringView, public Shape
{
public:
	Text(string s) : StringView(s) {}

	virtual void Draw() override
	{
		StringView::Show();
	}
};

// ��ü ����͸� ����� ������.
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

// 2. ��ü �����


int main()
{
	//// Ŭ���� �����
	//vector<Shape*> v;
	//v.push_back(new Text("hello"));
	//v[0]->Draw();

	// ��ü �����
	StringView sv("hello");
	Text2 txt(&sv);

	vector<Shape*> v;
	v.push_back(&txt);
	v[0]->Draw();
}
