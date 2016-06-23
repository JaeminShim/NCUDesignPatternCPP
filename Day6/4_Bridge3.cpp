// 4_Bridge3
#include <iostream>
using namespace std;

// Bridge ����

// ex> �䱸����: 1�� �̸���� �߰��ش޶�.

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

// ����ڰ� IMP3�� ���� ����ϰ� ���� ���� �Ʒ� Ŭ������ ����ϰԲ� ����.
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

	// ������� �䱸���ǿ� ���� ��� �߰�
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
