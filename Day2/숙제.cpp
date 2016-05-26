#include <iostream>
#include <string>
using namespace std;


class IStorageItem
{
	string name;
public:
	IStorageItem(const string& s) : name(s) {}
	virtual ~IStorageItem() {}

	virtual int getSize() = 0;
};

class File : public IStorageItem
{
	int size;
public:
	bool add(IStorageItem* pItem);
};

class Folder : public IStorageItem
{
public:
};

int main()
{
	File* f1 = new File("a.txt", 10);	// 파일은 자신의 크기가 있습니다.
	File* f2 = new File("a.txt", 20);
	File* f3 = new File("a.txt", 30);

	Folder* root = new Folder("ROOT");	// 폴더는 자신의 크기가 없습니다.
	Folder* fo1 = new Folder("A");
	Folder* fo2 = new Folder("B");

	fo1->add(f1);
	fo2->add(f2);
	root->add(f3);
	root->add(fo1);
	root->add(fo2);

	cout << f1->getSize() << endl;		// 파일은 크기를 구할 수 있습니다.
	cout << root->getSize() << endl;	// 폴더도 크기를 구할 수 있습니다.
}

// 복합 객체와 개별 객체를 동일시 하는 함수는?
