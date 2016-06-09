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

// MaxObject<Truck>은 꼭 자신의 이름을 사용하기 위함이라기 보다는
// 고유한 부모를 사용하기 위해 자신의 클래스 이름을 사용한 것임.

// Truck도 5대만 하고 싶다.
class Truck : public MaxObject<Truck>
{
};

class Bike : public MaxObject<Bike>
{
};

int main()
{
	// 자동차를 5대 이상 못 만들게 하고 싶다.
	Truck c1[3];
	Bike c2[3];
}