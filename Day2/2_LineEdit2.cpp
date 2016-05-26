// 2_LineEdit2 - 81p

#include <iostream>
#include <string>
#include <conio.h>

using namespace std;


class LineEdit
{
	string data;
public:
	// ���뼺�� �������� �и�
	// ������ �ʴ� �帧���� ���ϴ� �κ��� ã�Ƽ� �����Լ��� �и��Ѵ�.
	virtual bool validate(char c) { return isdigit(c); }

	string getData()
	{
		data.clear();
		while (true)
		{
			char c = _getch();
			if (c == 13) break;

			if (validate(c))	// validation ��å�� ���� �����Լ� ȣ��
			{
				data.push_back(c);
				cout << c;
			}
		}
		cout << endl;
		return data;
	}
};

// �ڽ� Ŭ������ ���� ��å�� �����Ѵ�
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