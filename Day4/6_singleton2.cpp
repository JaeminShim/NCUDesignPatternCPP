// 6_singleton2
#include <iostream>
using namespace std;

// CRTP: Curiosly Recurring Template Pattern
//       �̷��� ������� �Ļ� Ŭ������ �̸��� �θ� Ŭ���� ���� �� �̸� ����ϴ� ���
//       ���ø� ���ڷ� ���� �ް� �ȴ�.
template <typename T>
class Singleton
{
protected:
	Singleton() {}
	virtual ~Singleton() {}

private:
	Singleton(const Singleton&) = delete;
	void operator=(const Singleton&) = delete;

public:
	static T& getInstance()
	{
		static T instance;
		return instance;
	}
};

// Mouse�� �̱������� �ϰ� �ʹ�.
class Mouse : public Singleton<Mouse>
{
private:
	Mouse() {}
	friend class Singleton<Mouse>;
};

int main()
{
	Mouse& c1 = Mouse::getInstance();
}