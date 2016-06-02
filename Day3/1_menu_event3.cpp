// 1_�޴� �̺�Ʈ
#include <iostream>
using namespace std;

// 2. �Լ� ������ ����� �̺�Ʈ ó��
// 	C#		- delegate
//	������	- Ÿ�� �׼� ����
//	MFC		- �޽��� ��
//	QT		- signal/slot
// ��� �� ���

class MenuItem
{
	int id;

	// �Ϲ� �Լ� ���� (��� �Լ��� ���� �� ����)
	void(*handler)();

	// ����Լ� ���� (Ŭ���� Ÿ���� ������, �Ϲ� �Լ� ���� �� ����)
	//void (Dialog::*handler)();
	//Dialog* dlg;
	// (C#: delegate, iOS: selecter)

public:
	MenuItem(int n) : id(n) {}

	virtual void command()
	{
		if (handler)
			handler();	// ��ϵ� �Լ� ȣ��
	}
};

int main()
{
	MenuItem m1(11), m2(22);
	m1.command();
}