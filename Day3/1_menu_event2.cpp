// 1_�޴� �̺�Ʈ2	// 88p
#include <iostream>
#include <vector>
using namespace std;

// ��� 1. ������ ����, java�� �ȵ���̵� �ۿ��� �θ� ���.

// �޴��� ó���ϰ� ���� Ŭ������ �ݵ�� �Ʒ� �������̽��� �����ؾ� �Ѵ�.
struct IMenuListener
{
	// ���� �̺�Ʈ�� ȣ������ ID�� �ʿ��ϴ�.
	virtual void onCommand(int id) = 0;

	// �θ��� �Ҹ��ڴ� ���� �Ҹ����̾�� �Ѵ�. C++ �⺻ ����
	virtual ~IMenuListener() {}
};

class MenuItem
{
	int id;
	vector<IMenuListener*> listeners;

public:
	MenuItem(int n) : id(n) {}

	void addListener(IMenuListener* p)
	{
		listeners.push_back(p);
	}

	virtual void command()
	{
		// �޴��� ���õ� ����� �ܺο� �˷��� �Ѵ�.
		// ��ü�� �ܺο� �̺�Ʈ�� �߻�.
		for (auto pListener : listeners)
			pListener->onCommand(id);	// �ܺο� �˸���
	}
};

//---------------------------------------------------
class Camera : public IMenuListener
{
public:
	virtual void onCommand(int id) override
	{
		// Switch ���� �ʿ� => OCP�� ������ �� ����!
		//switch (id)
		//{
		//}
		cout << "Camera �޴� ���� �� " << id << endl;
	}
};

int main()
{
	Camera cam;
	MenuItem m1(11), m2(22);

	m1.addListener(&cam);	// �޴� ������ ó���� ������ ��ü ���
	m2.addListener(&cam);

	m1.command();
	m2.command();
}