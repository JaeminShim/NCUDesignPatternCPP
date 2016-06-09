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

// Image ��ü�� ����� Ŭ������ �������� - Factory ����
class ImageFactory
{
	map<string, Image*> image_map;

	// �ܺο��� ���� �� ������ �Ѵ�
	ImageFactory() {}
	ImageFactory(const ImageFactory&) = delete;		// ���� ������ ����
	void operator=(const ImageFactory&) = delete;	// ���� ������ ����

public:
	Image* CreateImage(string url)
	{
		if (image_map[url] == 0)
			image_map[url] = new Image(url);
		return image_map[url];
	}

	// ���� �ϳ��� ��ü�� ���� �����ϴ� �����Լ�
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