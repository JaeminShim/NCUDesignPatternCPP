// 3_GUI - Cafe에서 thiscall_8 소스 가져옴

#include <iostream>
#include <map>
#include <vector>
#include "ioacademy.h"

using namespace std;
using namespace ioacademy;

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

		switch (msg) {
		case WM_LBUTTONDOWN: pThis->OnLButtonDown(); break;
		case WM_KEYDOWN: pThis->OnKeyDown(); break;
		}
		return 0;
	}

	virtual void OnLButtonDown() {}
	virtual void OnKeyDown() {}
};

// 위 클래스 사용자 코드입니다.
class MyWindow : public CWnd
{
public:
	void OnLButtonDown() override { cout << "MyWindow LBUTTON" << endl; }
	void OnKeyDown() override { cout << "MyWindow KEYDOWN" << endl; }
};

class ImageView : public CWnd
{
public:
	void OnLButtonDown() override { cout << "ImageView LBUTTON" << endl; }
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