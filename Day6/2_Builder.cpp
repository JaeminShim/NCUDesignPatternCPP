// 2_builder
#include <iostream>
#include <string>
using namespace std;

// Strategy pattern	: 알고리즘을 분리 (Day2 - 2_LineEdit)
// State pattern	: 상태에 따라 동작을 분리
// Builder pattern	: 객체의 생성을 분리 111p

// 각 파츠별 클래스가 있다고 가정
typedef string Hair;
typedef string Uniform;
typedef string Shoes;
typedef string Character;

// 다양한 모양의 캐릭터를 만드는 빌더
struct IBuilder
{
	virtual ~IBuilder() {}
	virtual void MakeHair() = 0;
	virtual void MakeUniform() = 0;
	virtual void MakeShoes() = 0;
	virtual Character GetCharacter() = 0;
};

// 빌더를 사용해서 캐릭터를 만드는, 변하지 않는 공정을 관리하는 감독관
class Director
{
	IBuilder* pBuilder;
public:
	void SetBuilder(IBuilder* p) { pBuilder = p; }

	// 캐릭터를 만드는 함수
	Character Construct()
	{
		pBuilder->MakeHair();
		pBuilder->MakeUniform();
		pBuilder->MakeShoes();
		return pBuilder->GetCharacter();
	}
};

// 다양한 캐릭터의 빌더를 제공한다.
class Korean : public IBuilder
{
	Character c;
public:
	virtual void MakeHair() override { c += "갓\n"; }
	virtual void MakeUniform() override { c += "한복\n"; }
	virtual void MakeShoes() override { c += "짚신\n"; }
	virtual Character GetCharacter() override { return c; }
};

int main()
{
	Director d;
	Korean k;
	d.SetBuilder(&k);	// 다양한 모양의 빌더를 넣으면 됩니다.

	Character c = d.Construct();
	cout << c << endl;
}