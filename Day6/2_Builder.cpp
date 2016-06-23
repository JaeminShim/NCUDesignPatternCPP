// 2_builder
#include <iostream>
#include <string>
using namespace std;

// Strategy pattern	: �˰����� �и� (Day2 - 2_LineEdit)
// State pattern	: ���¿� ���� ������ �и�
// Builder pattern	: ��ü�� ������ �и� 111p

// �� ������ Ŭ������ �ִٰ� ����
typedef string Hair;
typedef string Uniform;
typedef string Shoes;
typedef string Character;

// �پ��� ����� ĳ���͸� ����� ����
struct IBuilder
{
	virtual ~IBuilder() {}
	virtual void MakeHair() = 0;
	virtual void MakeUniform() = 0;
	virtual void MakeShoes() = 0;
	virtual Character GetCharacter() = 0;
};

// ������ ����ؼ� ĳ���͸� �����, ������ �ʴ� ������ �����ϴ� ������
class Director
{
	IBuilder* pBuilder;
public:
	void SetBuilder(IBuilder* p) { pBuilder = p; }

	// ĳ���͸� ����� �Լ�
	Character Construct()
	{
		pBuilder->MakeHair();
		pBuilder->MakeUniform();
		pBuilder->MakeShoes();
		return pBuilder->GetCharacter();
	}
};

// �پ��� ĳ������ ������ �����Ѵ�.
class Korean : public IBuilder
{
	Character c;
public:
	virtual void MakeHair() override { c += "��\n"; }
	virtual void MakeUniform() override { c += "�Ѻ�\n"; }
	virtual void MakeShoes() override { c += "¤��\n"; }
	virtual Character GetCharacter() override { return c; }
};

int main()
{
	Director d;
	Korean k;
	d.SetBuilder(&k);	// �پ��� ����� ������ ������ �˴ϴ�.

	Character c = d.Construct();
	cout << c << endl;
}