// 1_thiscall8
// 과제 1. 아래 클래스 만들어 오세요
// 제출마감: 6월 2일

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

// 위 클래스 사용자 코드입니다.
class MyWindow : public CWnd
{
public:
	virtual void OnLButtonDown() override { cout << "LBUTTON" << endl; }
};

int main()
{
	MyWindow w;
	w.Create();	// 이 순간 윈도우가 생성되어야 합니다.
				// 마우스의 왼쪽 버튼을 누르면 "LBUTTON"이 나와야 합니다.
	IoProcessMessage();
}