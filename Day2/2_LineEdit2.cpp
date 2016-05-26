// 2_LineEdit2 - 81p

#include <iostream>
#include <string>
#include <conio.h>

using namespace std;


class LineEdit
{
	string data;
public:
	// 공통성과 가변성의 분리
	// 변하지 않는 흐름에서 변하는 부분을 찾아서 가상함수로 분리한다.
	virtual bool validate(char c) { return isdigit(c); }

	string getData()
	{
		data.clear();
		while (true)
		{
			char c = _getch();
			if (c == 13) break;

			if (validate(c))	// validation 정책을 담은 가상함수 호출
			{
				data.push_back(c);
				cout << c;
			}
		}
		cout << endl;
		return data;
	}
};

// 자식 클래스를 통해 정책을 변경한다
class AddressEdit : public LineEdit
{
public:
	virtual bool validate(char c) { return true; }
};

int main()
{
	AddressEdit edit;
	while (1)
	{
		string s = edit.getData();
		cout << s << endl;
	}
}