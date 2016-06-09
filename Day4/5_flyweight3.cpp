// 5_flyweight3
#include <iostream>
#include <string>
#include <map>
#include <Windows.h>
using namespace std;

class Image
{
	friend class ImageFactory;
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
};

// Image 객체를 만드는 클래스를 도입하자 - Factory 개념
class ImageFactory
{
	map<string, Image*> image_map;

	// 외부에서 만들 수 없도록 한다
	ImageFactory() {}
	ImageFactory(const ImageFactory&) = delete;		// 복사 생성자 제거
	void operator=(const ImageFactory&) = delete;	// 대입 연산자 제거

public:
	Image* CreateImage(string url)
	{
		if (image_map[url] == 0)
			image_map[url] = new Image(url);
		return image_map[url];
	}

	// 오직 하나의 객체만 만들어서 리턴하는 정적함수
	static ImageFactory& getInstance()
	{
		static ImageFactory instance;
		return instance;
	}
};


int main()
{
	ImageFactory& factory = ImageFactory::getInstance();

	Image* p1 = factory.CreateImage("http://www.naver.com/a.png");
	p1->Draw();
	Image* p2 = factory.CreateImage("http://www.naver.com/a.png");
	p2->Draw();
}