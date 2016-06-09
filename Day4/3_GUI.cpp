// 3_GUI - Cafe���� thiscall_8 �ҽ� ������

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
	vector<CWnd*> children;	// �ڽ��� ������
	CWnd* parent;			// �θ� ������� �ϳ�
public:
	void AddChild(CWnd* p)
	{
		children.push_back(p);
		p->parent = this;

		// ���� GUI�󿡼� �ڽ� ������ ���̴� �Լ�
		IoAddChild(this->handle, p->handle);
	}

public:
	virtual ~CWnd() {}

	void Create()
	{
		handle = IoMakeWindow(HandleMessage);
		cwnd_map[handle] = this;
	}

	// �޼��� ó�� �Լ�
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

// �� Ŭ���� ����� �ڵ��Դϴ�.
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

	w.AddChild(&w2);	// w�� �ڽ����� w2�� ���δ�.

	IoProcessMessage();
}