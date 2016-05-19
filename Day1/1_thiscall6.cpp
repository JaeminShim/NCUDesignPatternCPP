// 1_thiscall6	// 68p

#include <iostream>
#include "ioacademy.h"	// cafe.naver.com/cppmaster

using namespace std;
using namespace ioacademy;

#include <string>
#include <map>

// 클래스 전방 선언
class Clock;
map<int, Clock*> this_map;

// 타이머 개념을 클래스에 도입해 봅시다.
class Clock
{
	string name;

public:
	Clock(string s) : name(s)
	{
	}

	void Start(int ms)
	{
		int id = IoSetTimer(ms, timerRoutine);
		this_map[id] = this;
	}

	// 아래 함수는 반드시 static 멤버 이어야 합니다
	static void timerRoutine(int id)
	{
		//cout << name << endl;	// this->name이 되어야 합니다.
		Clock* pThis = this_map[id];
		cout << pThis->name << endl;
		
	}
};

int main()
{
	Clock c1("A");
	Clock c2("B");
	c1.Start(500);
	c2.Start(1000);		// 1초에 한 번씩 이름을 출력해야 합니다.
	IoProcessMessage();
}