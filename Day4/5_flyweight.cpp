// 5_flyweight
#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

// Flyweight ����: �Ӽ��� ������ ��ü�� ��������.

class Image
{
	string url;
public:
	Image(string s) :url(s)
	{
		cout << "downloading... " << url <<  endl;
		Sleep(5000);
	}

	void Draw()
	{
		cout << "Draw " << url << endl;
	}
};

int main()
{
	Image* p1 = new Image("http://www.naver.com/a.png");
	Image* p2 = new Image("http://www.naver.com/a.png");
}