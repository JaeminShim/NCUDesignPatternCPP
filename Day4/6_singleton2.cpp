// 6_singleton2
#include <iostream>
using namespace std;

// CRTP: Curiosly Recurring Template Pattern
//       미래에 만들어질 파생 클래스의 이름을 부모 클래스 만들 때 미리 사용하는 기술
//       템플릿 인자로 전달 받게 된다.
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

// Mouse도 싱글톤으로 하고 싶다.
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