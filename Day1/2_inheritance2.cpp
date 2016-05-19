// 2_inheritance2 // 45p

// protected 생성자:
//	자신은 만들 수 없지만 (추상적인 개념)
//	파생 클래스는 만들 수 있게 하겠다 (구체적인 개념)
//	는 디자인 기법 - 46p

class Animal
{
//public:
protected:	// 추상적인 클래스
	Animal() {}
};

class Dog : public Animal
{
public:
	Dog() {}
};

int main()
{
	// 다음 중 에러를 모두 고르시오
	Animal	a;	// 1. ERROR
	Dog		d;	// 2. OK
}
