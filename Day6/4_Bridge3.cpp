// 4_Bridge3
#include <iostream>
using namespace std;

// Bridge 패턴

// ex> 요구사항: 1분 미리듣기 추가해달라.

struct IMP3
{
	virtual ~IMP3() {}
	virtual void Play() = 0;
	virtual void Stop() = 0;
};

class IPod : public IMP3
{
public:
	virtual void Play() override { cout << "Play with iPod" << endl; }
	virtual void Stop() override { cout << "Stop with iPod" << endl; }
};

// 사용자가 IMP3를 직접 사용하게 하지 말고 아래 클래스를 사용하게끔 하자.
class MP3
{
	IMP3* pImpl;
public:
	MP3(IMP3* p)
	{
		if (p == 0)
			p = new IPod;
		pImpl = p;
	}
	void Play() { pImpl->Play(); }
	void Stop() { pImpl->Stop(); }

	// 사용자의 요구조건에 따라 기능 추가
	void PlayOneMinute() { pImpl->Play(); pImpl->Stop(); }
};

class People
{
public:
	void UseMP3(MP3* p) { p->Play(); }
};

int main()
{

}
