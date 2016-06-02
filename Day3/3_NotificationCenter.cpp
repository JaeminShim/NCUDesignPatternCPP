// 3_NotificationCenter - 107p
#include <iostream>
#include <functional>
#include <string>
#include <map>
#include <vector>
using namespace std;

void foo() { cout << "foo" << endl; }
void goo() { cout << "goo" << endl; }

class NotificationCenter
{
	typedef function<void()> HANDLER;

	map<string, vector<HANDLER>> notify_map;

public:
	void Register(string&& key, HANDLER func)
	{
		notify_map[move(key)].push_back(func);
	}

	void Register(const string& key, HANDLER func)
	{
		notify_map[key].push_back(func);
	}

	void PostNotificationWithName(string&& key)
	{
		auto& v = notify_map[move(key)];
		for (auto& f : v)
			f();
	}

	void PostNotificationWithName(const string& key)
	{
		auto& v = notify_map[key];
		for (auto& f : v)
			f();
	}

	// global �뺸������ ������ �߰��غ��ô�.
	static NotificationCenter& defaultCenter()
	{
		static NotificationCenter center;
		return center;
	}
};

int main()
{
	//NotificationCenter nc;
	NotificationCenter& nc = NotificationCenter::defaultCenter();
	nc.Register("LOWBATTERY", &foo);
	nc.Register("LOWBATTERY", &goo);

	// ���͸� ��� �ʿ���
	nc.PostNotificationWithName("LOWBATTERY");
}