// 2_inheritance5	// 49p
// [Up Casting] : 객체 지향 디자인의 핵심 원리

// 1. 부모 포인터에 자식 객체 주소를 담을 수 있다. - upcasting
// 2. Upcasting은 public 상속일 때만 가능하다.
// 3. 동종(동일 부모의 자식)을 저장하는 컨테이너를 만들 수 있다.
// 4. A와 B를 묶고 싶다면 공통의 기반 클래스를 설계해야 한다. (공통의 부모)
class Animal
{
public:
	void Cry() {}
};

class Dog : public Animal
{
};

void foo(Animal* p) { p->Cry(); }

int main()
{
	Animal	a;	foo(&a);	// OK
	Dog		d;	foo(&d);	// OK: Upcasting

	Dog* ar1[10];		// Dog만 저장
	Animal* ar2[10];	// 모든 동물(Animal 자식)을 저장
}