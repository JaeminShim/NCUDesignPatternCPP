// 7_factory method
#include <iostream>
using namespace std;

// QT를 사용하면 -style:osx (linux, gnome, ...) 와 같은 방식으로
// UI 외형을 바꿀 수 있음.
// 그러한 방식의 구현

struct IButton
{
	virtual ~IButton() {}
	virtual void Draw() = 0;
};

struct IEdit
{
	virtual ~IEdit() {}
	virtual void Draw() = 0;
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


class DialogBase
{
public:
	virtual ~DialogBase() {}

	void Init()
	{
		IButton* pBtn = CreateButton();
		IEdit* pEdit = CreateEdit();

		pBtn->Draw();
		pEdit->Draw();
	}

	virtual IButton* CreateButton() = 0;
	virtual IEdit*   CreateEdit()   = 0;
};

class WinDialog : public DialogBase
{
public:
	virtual IButton* CreateButton() override { return new WinButton; }
	virtual IEdit*   CreateEdit()   override { return new WinEdit; }
};

class OSXDialog : public DialogBase
{
public:
	virtual IButton* CreateButton() override { return new OSXButton; }
	virtual IEdit*   CreateEdit()   override { return new OSXEdit; }
};


int main()
{
	WinDialog wd;
	wd.Init();
}
