// 1_thiscall8
// ���� 1. �Ʒ� Ŭ���� ����� ������
// ���⸶��: 6�� 2��

#include <iostream>
#include "ioacademy.h"	// cafe.naver.com/cppmaster

using namespace std;
using namespace ioacademy;

#include <map>

class CWnd
{
public:
	void Create()
	{
		int handle = IoMakeWindow(MsgProc);
		sWindowMap[handle] = this;
	}

	virtual void OnLButtonDown() {}
	virtual void OnKeyDown() {}

private:
	static map<int, CWnd*> sWindowMap;
	static int MsgProc(int h, int msg, int a, int b)
	{
		CWnd* pWindow = sWindowMap[h];
		switch (msg)
		{
		case WM_LBUTTONDOWN:
			pWindow->OnLButtonDown();
			break;
		case WM_KEYDOWN:
			pWindow->OnKeyDown();
			break;
		}
		return 0;
	}
};
map<int, CWnd*> CWnd::sWindowMap;

// �� Ŭ���� ����� �ڵ��Դϴ�.
class MyWindow : public CWnd
{
public:
	virtual void OnLButtonDown() override { cout << "LBUTTON" << endl; }
};

int main()
{
	MyWindow w;
	w.Create();	// �� ���� �����찡 �����Ǿ�� �մϴ�.
				// ���콺�� ���� ��ư�� ������ "LBUTTON"�� ���;� �մϴ�.
	IoProcessMessage();
}