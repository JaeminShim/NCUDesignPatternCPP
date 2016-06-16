// 6_추상팩토리	// 110p
#include <iostream>
using namespace std;

// QT를 사용하면 -style:osx (linux, gnome, ...) 와 같은 방식으로
// UI 외형을 바꿀 수 있음.
// 그러한 방식의 구현

struct IControl
{
	virtual ~IControl() {}
	virtual void Draw() = 0;
};

struct IButton : public IControl
{
	virtual ~IButton() {}
};

struct IEdit : public IControl
{
	virtual ~IEdit() {}
};

struct WinButton : public IButton
{
	virtual void Draw() override
	{
		cout << "WinButton" << endl;
	}
};

struct WinEdit : public IEdit
{
	virtual void Draw() override
	{
		cout << "WinEdit" << endl;
	}
};

struct OSXButton : public IButton
{
	virtual void Draw() override
	{
		cout << "OSXButton" << endl;
	}
};

struct OSXEdit : public IEdit
{
	virtual void Draw() override
	{
		cout << "OSXEdit" << endl;
	}
};


//int main(int argc, char** argv)
//{
//	IButton* btn;
//
//	if (!strcmp(argv[1], "windows"))
//	{
//		btn = new WinButton;
//	}
//	else
//	{
//		btn = new OSXButton;
//	}
//
//	btn->Draw();
//}


struct IControlFactory
{
	virtual ~IControlFactory() {}
	virtual IButton* CreateButton() = 0;
	virtual IEdit*   CreateEdit()   = 0;
};

// 컨트롤을 만드는 공장
struct WinFactory : public IControlFactory
{
	virtual IButton* CreateButton() override { return new WinButton; }
	virtual IEdit*   CreateEdit()   override { return new WinEdit; }
};
struct OSXFactory : public IControlFactory
{
	virtual IButton* CreateButton() override { return new OSXButton; }
	virtual IEdit*   CreateEdit()   override { return new OSXEdit; }
};


int main(int argc, char** argv)
{
	IControlFactory* factory;

	if (!strcmp(argv[1], "windows"))
	{
		factory = new WinFactory;
	}
	else
	{
		factory = new OSXFactory;
	}

	IButton* btn = factory->CreateButton();
	btn->Draw();
}
