// 2_LineEdit2 - 81p

#include <iostream>
#include <string>
#include <conio.h>

using namespace std;


// ���ϴ� ���� �и��ϴ� 2���� ���
// 1. �����Լ���
// 2. ���ϴ� ���� �ٸ� Ŭ������ ��ü => ��ü �����ؾ� �Ѵ� => ���� ������ �ʿ�
//   => Strategy pattern


//=====================================
// Template method <-> Strategy
//=====================================
// Template method pattern�� ����
// (��� ��� : ���ſ�)
//-------------------------------------
// 1. ��å�� ����(private)ȭ
//=====================================
// Strategy pattern�� ����
// (���� ��� : ���뼺)
//-------------------------------------
// 1. ��å�� �� ��뼺
// 2. ���� �ð��� ��å ��ü
//=====================================


struct IValidator
{
	virtual bool validate(string s, char c) = 0;
	virtual bool iscomplete(string s) { return true; }
};

// �ֹι�ȣ : 801  1   Ȯ��

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


// �پ��� validation ��å�� �����ϸ� �˴ϴ�.
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