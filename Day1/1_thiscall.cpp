// 1_thiscall.cpp // 32p

class Point
{
	int x, y;
public:
	void set(int a, int b)	// void set(Point* const this, int a, int b)
	{
		x = a;				// this->x = a;
		y = b;				// this->y = b;
	}

	static void foo(int a)	// void foo(int a)
	{
		x = a;				// this->x = a; 를 하기 원함
	}
};

int main()
{
	Point p1, p2;
	p1.set(10, 20);		// 이 한 줄의 원리를 생각해봅시다.
						// set(&p1, 10, 20)

	Point::foo(10);		// static 멤버 함수는 객체 없이 호출 가능
}