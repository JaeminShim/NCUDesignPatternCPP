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

	// �ڱ� �ڽ��� ����� static �Լ��� ���� ��찡 �����ϴ�.
	// iOS�� �̹��� �ε� ���
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