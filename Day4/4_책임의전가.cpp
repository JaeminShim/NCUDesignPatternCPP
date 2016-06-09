// 4_책임의 전가 - 3_GUI에서 가져옴

#include <iostream>
#include <map>
#include <vector>
#include "ioacademy.h"

using namespace std;
using namespace ioacademy;

// GoF's 의 패턴에서 이벤트를 여러곳에 보내는 패턴은 2개 입니다.
// - Observer: 발생한 이벤트를 등록된 모든 관찰자에게 전달
// - Chain of Responsibility: 이벤트를 책임지는 객체가 처리하지 않은 경우
//                            고리에 따라 연결된 다음 객체로 전달

// Chain of Responsibility 패턴 적용 라이브러리
// - 매킨토시 cocoa 라이브러리의 "Responder chain"
// - MFC 라이브러리의 메뉴처리 "명령 라우팅"
// - QT의 signal/slot 개념

class CWnd;
map<int, CWnd*> cwnd_map;

class CWnd
{
	int handle;
	vector<CWnd*> children;	// 자식은 여러명
	CWnd* parent;			// 부모 윈도우는 하나
public:
	void AddChild(CWnd* p)
	{
		children.push_back(p);
		p->parent = this;

		// 실제 GUI상에서 자식 윈도우 붙이는 함수
		IoAddChild(this->handle, p->handle);
	}

public:
	virtual ~CWnd() {}

	void Create()
	{
		handle = IoMakeWindow(HandleMessage);
		cwnd_map[handle] = this;
	}

	// 메세지 처리 함수
	static int HandleMessage(int h, int msg, int a, int b)
	{
		CWnd* pThis = cwnd_map[h];

		switch (msg)
		{
		case WM_LBUTTONDOWN: pThis->FireLButtonDown(); break;
		case WM_KEYDOWN: pThis->OnKeyDown(); break;
		}
		return 0;
	}

	// 아래 함수가 Chain of Responsibility 패턴의 핵심입니다.
	void FireLButtonDown()
	{
		// 1. 자신이 먼저 처리를 시도한다 - 가상함수 호출
		if (OnLButtonDown() == true)
			return;

		// 2. 자신이 처리하지 않은 경우 부모에게 전달
		if (parent)
			parent->FireLButtonDown();
	}

	virtual bool OnLButtonDown() { return false; }
	virtual void OnKeyDown() {}
};

// 위 클래스 사용자 코드입니다.
class MyWindow : public CWnd
{
public:
	bool OnLButtonDown() override { cout << "MyWindow LBUTTON" << endl; return true; }
	void OnKeyDown() override { cout << "MyWindow KEYDOWN" << endl; }
};

class ImageView : public CWnd
{
public:
	bool OnLButtonDown() override { cout << "ImageView LBUTTON" << endl; return false; }
	void OnKeyDown() override { cout << "ImageView KEYDOWN" << endl; }
};

int main(int argc, char* argv[])
{
	MyWindow w;
	w.Create();

	ImageView w2;
	w2.Create();

	w.AddChild(&w2);	// w의 자식으로 w2를 붙인다.

	IoProcessMessage();
}