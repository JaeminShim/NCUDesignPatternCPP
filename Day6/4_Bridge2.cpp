// 4_Bridge2
#include <iostream>
using namespace std;

// Bridge 패턴

// ex> 요구사항: 1분 미리듣기 추가해달라.

struct IMP3
{
	virtual ~IMP3() {}
	virtual void Play() = 0;
	virtual void Stop() = 0;

	// 사용자의 요구조건에 따라 "인터페이스에" 기능이 추가되어야 한다.
	virtual void PlayOneMinute() = 0;
};

class IPod : public IMP3
{
public:
	virtual void Play() override { cout << "Play with iPod" << endl; }
	virtual void Stop() override { cout << "Stop with iPod" << endl; }
};

class People
{
public:
	void UseMP3(IMP3* p) { p->Play(); }
};

int main()
{

}
