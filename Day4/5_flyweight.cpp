// 5_flyweight
#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

// Flyweight 패턴: 속성이 동일한 객체는 공유하자.

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