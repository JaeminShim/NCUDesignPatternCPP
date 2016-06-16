// 7_factory method	// 117p
#include <iostream>
using namespace std;

// QT�� ����ϸ� -style:osx (linux, gnome, ...) �� ���� �������
// UI ������ �ٲ� �� ����.
// �׷��� ����� ����

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


// Style �ɼǿ� ��� ���� �׻� Windows ������� �����ִ� DialogBox
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
