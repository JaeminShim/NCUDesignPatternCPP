// 2_inheritance3

class Base
{
private:			// 접근 지정자
	int a;
protected:	int b;
public:		int c;
};

class Derived
//	: protected		// 접근 변경자
	: private		// 접근 변경자
	  Base
					// 부모의 접근 권한을 축소할 때 사용
					// 권한을 확장할 수는 없다.
{
};

int main()
{
	Base b;		b.c = 10;	// OK
	Derived d;	d.c = 10;	// ERROR
}