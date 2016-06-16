// 7_factory method	// 117p
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


// Style 옵션에 상관 없이 항상 Windows 모양으로 보여주는 DialogBox
class WinDialog
{
public:
	void Init()
	{
		WinButton* pBtn = new WinButton;
		WinEdit* pEdit = new WinEdit;

		pBtn->Draw();
		pEdit->Draw();
	}
};

class OSXDialog
{
public:
	void Init()
	{
		OSXButton* pBtn = new OSXButton;
		OSXEdit* pEdit = new OSXEdit;

		pBtn->Draw();
		pEdit->Draw();
	}
};


int main()
{
	WinDialog wd;
	wd.Init();
}
