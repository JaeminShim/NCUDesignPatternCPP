// 5_flyweight2
#include <iostream>
#include <string>
#include <map>
#include <Windows.h>
using namespace std;

class Image
{
	static map<string, Image*> image_map;
	string url;

	Image(string s) :url(s)
	{
		cout << "downloading... " << url <<  endl;
		Sleep(5000);
	}

public:
	void Draw()
	{
		cout << "Draw " << url << endl;
	}

	// 자기 자신을 만드는 static 함수는 편리한 경우가 많습니다.
	// iOS의 이미지 로드 방식
	static Image* ImageWithURL(string s)
	{
		if (image_map[s] == 0)
			image_map[s] = new Image(s);
		return image_map[s];
	}
};

map<string, Image*> Image::image_map;

int main()
{
	Image* p1 = Image::ImageWithURL("http://www.naver.com/a.png");
	p1->Draw();
	Image* p2 = Image::ImageWithURL("http://www.naver.com/a.png");
	p2->Draw();
}