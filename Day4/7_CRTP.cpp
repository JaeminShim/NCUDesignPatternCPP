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
	// �ڵ����� 5�� �̻� �� ����� �ϰ� �ʹ�.
	Car c1[3];
	Car c2[3];
}