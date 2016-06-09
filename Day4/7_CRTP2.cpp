// 7_CRTP2

template <typename T>
class MaxObject
{
	static int cnt;
public:
	MaxObject() { if (++cnt > 5) throw 1; }
	~MaxObject() { --cnt; }
};

template <typename T>
int MaxObject<T>::cnt = 0;

// MaxObject<Truck>�� �� �ڽ��� �̸��� ����ϱ� �����̶�� ���ٴ�
// ������ �θ� ����ϱ� ���� �ڽ��� Ŭ���� �̸��� ����� ����.

// Truck�� 5�븸 �ϰ� �ʹ�.
class Truck : public MaxObject<Truck>
{
};

class Bike : public MaxObject<Bike>
{
};

int main()
{
	// �ڵ����� 5�� �̻� �� ����� �ϰ� �ʹ�.
	Truck c1[3];
	Bike c2[3];
}