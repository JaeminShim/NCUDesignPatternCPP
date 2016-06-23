// 4_Bridge
#include <iostream>
using namespace std;

// Bridge ∆–≈œ

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

class People
{
public:
	void UseMP3(IMP3* p) { p->Play(); }
};

int main()
{

}
