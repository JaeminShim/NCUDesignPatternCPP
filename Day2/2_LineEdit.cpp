// 2_LineEdit - 81p

#include <iostream>
#include <string>
#include <conio.h>

using namespace std;


class LineEdit
{
	string data;
public:
	string getData()
	{
		//cin >> data;
		// validation 기능을 추가해보자

		data.clear();
		while (true)
		{
			char c = _getch();
			if (c == 13) break;
			if (isdigit(c))
			{
				data.push_back(c);
				cout << c;
			}
		}
		cout << endl;
		return data;
	}
};

int main()
{
	LineEdit edit;
	while (1)
	{
		string s = edit.getData();
		cout << s << endl;
	}
}