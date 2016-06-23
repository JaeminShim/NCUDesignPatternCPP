#include <iostream>
using namespace std;

// 10_mediator :  ������ ���� 


// ������ ���� : ������(collegue) ���� ���� ������ ��� �����ڸ� ������..

// �����ڰ��� M:N �� ���踦 �����ڿ� ������ ���� M : 1�� ����� �ٲٴ� ����

// ��ü���� ��� ���谡 �����ھȿ� �ڵ�� ǥ���ȴ�.
// ���踦 �ľ��ϰ� �����ϱ� ���� ����.

// "�뺸����" �� ��ǥ���� ������ �Դϴ�.




// ������ �������̽�
#include <string>
struct IMediator
{
	virtual void changeObjectState(string name) = 0;
};

class CheckBox
{
	IMediator* pMediator; // ������ ������
	bool value;
public:
	void setMediator(IMediator* p) { pMediator = p; }

	CheckBox() : value(0) {}

	void setCheck(bool b) { value = b; changeState(); }
	bool getCheck() { return value; }

	// �ڽ��� ���� ������ �����ڿ� �˷��ش�.
	virtual void changeState() 
	{
		pMediator->changeObjectState("checkBox"); 
	}
};
//-----------------------
// GUI ��Ʈ���� ��ȭ�� �����ϴ� ������
class GUIMediator : public IMediator
{
	// �ٽ� 1. ��� ��Ʈ���� ����(������)�� �־�� �Ѵ�.
	// CheckBox x, Radio r, Slider s;
public:
	void changeObjectState(string name)
	{
		// ��� ��Ʈ��(������)�� ��ȣ �ۿ��� �� �Ѱ��� ���� �ȴ�.
		if (check.getState() && radio.getState() && slider.getState())
			cout << "��ư enable" << endl;
	}
};

int main()
{
	CheckBox c; Radio r; Slider s;
	GUIMediator m(&c, &r, &s);
	c.setCheck(true);
}






