// 1_thiscall6	// 68p

#include <iostream>
#include "ioacademy.h"	// cafe.naver.com/cppmaster

using namespace std;
using namespace ioacademy;

#include <string>
#include <map>

// Ŭ���� ���� ����
class Clock;
map<int, Clock*> this_map;

// Ÿ�̸� ������ Ŭ������ ������ ���ô�.
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

	// �Ʒ� �Լ��� �ݵ�� static ��� �̾�� �մϴ�
	static void timerRoutine(int id)
	{
		//cout << name << endl;	// this->name�� �Ǿ�� �մϴ�.
		Clock* pThis = this_map[id];
		cout << pThis->name << endl;
		
	}
};

int main()
{
	Clock c1("A");
	Clock c2("B");
	c1.Start(500);
	c2.Start(1000);		// 1�ʿ� �� ���� �̸��� ����ؾ� �մϴ�.
	IoProcessMessage();
}