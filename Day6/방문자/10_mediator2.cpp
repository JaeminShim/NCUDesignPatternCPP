#include <iostream>
using namespace std;

// 10_mediator :  중재자 패턴 


// 중재자 패턴 : 협력자(collegue) 간의 관계 복잡한 경우 중재자를 만들어라..

// 협력자간에 M:N 의 관계를 협력자와 중재자 간의 M : 1의 관계로 바꾸는 패턴

// 객체간의 모든 관계가 중재자안에 코드로 표현된다.
// 관계를 파악하고 수정하기 편리해 진다.

// "통보센터" 가 대표적인 중재자 입니다.




// 중재자 인터페이스
#include <string>
struct IMediator
{
	virtual void changeObjectState(string name) = 0;
};

class CheckBox
{
	IMediator* pMediator; // 중재자 포인터
	bool value;
public:
	void setMediator(IMediator* p) { pMediator = p; }

	CheckBox() : value(0) {}

	void setCheck(bool b) { value = b; changeState(); }
	bool getCheck() { return value; }

	// 자신의 상태 변경을 중재자에 알려준다.
	virtual void changeState() 
	{
		pMediator->changeObjectState("checkBox"); 
	}
};
//-----------------------
// GUI 컨트롤의 변화를 중재하는 중재자
class GUIMediator : public IMediator
{
	// 핵심 1. 모든 콘트롤의 참조(포인터)가 있어야 한다.
	// CheckBox x, Radio r, Slider s;
public:
	void changeObjectState(string name)
	{
		// 모든 컨트롤(협력자)의 상호 작용이 이 한곳에 집중 된다.
		if (check.getState() && radio.getState() && slider.getState())
			cout << "버튼 enable" << endl;
	}
};

int main()
{
	CheckBox c; Radio r; Slider s;
	GUIMediator m(&c, &r, &s);
	c.setCheck(true);
}






