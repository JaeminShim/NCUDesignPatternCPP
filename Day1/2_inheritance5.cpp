// 2_inheritance5	// 49p
// [Up Casting] : ��ü ���� �������� �ٽ� ����

// 1. �θ� �����Ϳ� �ڽ� ��ü �ּҸ� ���� �� �ִ�. - upcasting
// 2. Upcasting�� public ����� ���� �����ϴ�.
// 3. ����(���� �θ��� �ڽ�)�� �����ϴ� �����̳ʸ� ���� �� �ִ�.
// 4. A�� B�� ���� �ʹٸ� ������ ��� Ŭ������ �����ؾ� �Ѵ�. (������ �θ�)
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

	Dog* ar1[10];		// Dog�� ����
	Animal* ar2[10];	// ��� ����(Animal �ڽ�)�� ����
}