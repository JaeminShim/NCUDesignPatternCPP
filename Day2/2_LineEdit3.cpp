// 2_LineEdit2 - 81p

#include <iostream>
#include <string>
#include <conio.h>

using namespace std;


// 변하는 것을 분리하는 2가지 기술
// 1. 가상함수로
// 2. 변하는 것을 다른 클래스로 교체 => 교체 가능해야 한다 => 약한 결합이 필요
//   => Strategy pattern


//=====================================
// Template method <-> Strategy
//=====================================
// Template method pattern의 장점
// (상속 기반 : 무거움)
//-------------------------------------
// 1. 정책의 은닉(private)화
//=====================================
// Strategy pattern의 장점
// (포함 기반 : 재사용성)
//-------------------------------------
// 1. 정책의 재 사용성
// 2. 실행 시간의 정책 교체
//=====================================


struct IValidator
{
	virtual bool validate(string s, char c) = 0;
	virtual bool iscomplete(string s) { return true; }
};

// 주민번호 : 801  1   확인

class LineEdit
{
	string data;

	//---------------------------------------------------------------
	IValidator* pVal;
public:
	LineEdit() :pVal(0) {}
	void setValidator(IValidator* p) { pVal = p; }
	//---------------------------------------------------------------
public:
	string getData()
	{
		data.clear();
		while (true)
		{
			char c = _getch();
			if (c == 13 && (pVal == 0 || pVal->iscomplete(data))) break;

			if (pVal == 0 || pVal->validate(data, c))
			{
				data.push_back(c);
				cout << c;
			}
		}
		cout << endl;
		return data;
	}
};


// 다양한 validation 정책을 제공하면 됩니다.
class LimitDigitValidator : public IValidator
{
	int value;
public:
	LimitDigitValidator(int n) : value(n) {}

	virtual bool validate(string s, char c)
	{
		return s.size() < value && isdigit(c);
	}

	virtual bool iscomplete(string s)
	{
		return s.size() == value;
	}
};

int main()
{
	LineEdit edit;
	LimitDigitValidator v(5);
	edit.setValidator(&v);

	while (1)
	{
		string s = edit.getData();
		cout << s << endl;
	}
}