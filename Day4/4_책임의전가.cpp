// 4_å���� ���� - 3_GUI���� ������

#include <iostream>
#include <map>
#include <vector>
#include "ioacademy.h"

using namespace std;
using namespace ioacademy;

// GoF's �� ���Ͽ��� �̺�Ʈ�� �������� ������ ������ 2�� �Դϴ�.
// - Observer: �߻��� �̺�Ʈ�� ��ϵ� ��� �����ڿ��� ����
// - Chain of Responsibility: �̺�Ʈ�� å������ ��ü�� ó������ ���� ���
//                            ���� ���� ����� ���� ��ü�� ����

// Chain of Responsibility ���� ���� ���̺귯��
// - ��Ų��� cocoa ���̺귯���� "Responder chain"
// - MFC ���̺귯���� �޴�ó�� "��� �����"
// - QT�� signal/slot ����

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

		switch (msg)
		{
		case WM_LBUTTONDOWN: pThis->FireLButtonDown(); break;
		case WM_KEYDOWN: pThis->OnKeyDown(); break;
		}
		return 0;
	}

	// �Ʒ� �Լ��� Chain of Responsibility ������ �ٽ��Դϴ�.
	void FireLButtonDown()
	{
		// 1. �ڽ��� ���� ó���� �õ��Ѵ� - �����Լ� ȣ��
		if (OnLButtonDown() == true)
			return;

		// 2. �ڽ��� ó������ ���� ��� �θ𿡰� ����
		if (parent)
			parent->FireLButtonDown();
	}

	virtual bool OnLButtonDown() { return false; }
	virtual void OnKeyDown() {}
};

// �� Ŭ���� ����� �ڵ��Դϴ�.
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

	w.AddChild(&w2);	// w�� �ڽ����� w2�� ���δ�.

	IoProcessMessage();
}