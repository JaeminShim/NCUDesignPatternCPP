// 7_CRTP

class Car
{
	static int cnt;
public:
	Car() { if (++cnt > 5) throw 1; }
	~Car() { --cnt; }
};

int Car::cnt = 0;

int main()
{
	// 자동차를 5대 이상 못 만들게 하고 싶다.
	Car c1[3];
	Car c2[3];
}