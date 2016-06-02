// 1_메뉴 이벤트
#include <iostream>
using namespace std;

// 2. 함수 포인터 방식의 이벤트 처리
// 	C#		- delegate
//	아이폰	- 타겟 액션 패턴
//	MFC		- 메시지 맵
//	QT		- signal/slot
// 모두 이 방식

class MenuItem
{
	int id;

	// 일반 함수 버전 (멤버 함수를 담을 수 없음)
	void(*handler)();

	// 멤버함수 버전 (클래스 타입이 결정됨, 일반 함수 담을 수 없음)
	//void (Dialog::*handler)();
	//Dialog* dlg;
	// (C#: delegate, iOS: selecter)

public:
	MenuItem(int n) : id(n) {}

	virtual void command()
	{
		if (handler)
			handler();	// 등록된 함수 호출
	}
};

int main()
{
	MenuItem m1(11), m2(22);
	m1.command();
}