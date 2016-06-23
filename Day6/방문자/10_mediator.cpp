#include <iostream>
using namespace std;

// 10_mediator :  중재자 패턴 

// 객체간의 상호 작용이 복잡해 보이면 중재자를 도입해라!!

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
		if (getCheck() == true && 라디오.getCheck() && slider.getCheck())
			cout << "버튼 enable" << endl;
	}
};

int main()
{

}






