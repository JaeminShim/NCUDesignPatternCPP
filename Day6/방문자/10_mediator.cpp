#include <iostream>
using namespace std;

// 10_mediator :  ������ ���� 

// ��ü���� ��ȣ �ۿ��� ������ ���̸� �����ڸ� �����ض�!!

class CheckBox
{
	bool value;
public:
	CheckBox() : value(0) {}

	void setCheck(bool b) { value = b; changeState(); }
	bool getCheck() { return value; }

	virtual void changeState() {}
};
class Radio
{
	bool value;
public:
	Radio() : value(0) {}

	void setCheck(bool b) { value = b; changeState(); }
	bool getCheck() { return value; }

	virtual void changeState() {}
};
//---------------------------------------
class MyCheck : public CheckBox
{
public:
	virtual void changeState()
	{
		if (getCheck() == true && ����.getCheck() && slider.getCheck())
			cout << "��ư enable" << endl;
	}
};

int main()
{

}






