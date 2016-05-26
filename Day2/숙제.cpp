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
	File* f1 = new File("a.txt", 10);	// ������ �ڽ��� ũ�Ⱑ �ֽ��ϴ�.
	File* f2 = new File("a.txt", 20);
	File* f3 = new File("a.txt", 30);

	Folder* root = new Folder("ROOT");	// ������ �ڽ��� ũ�Ⱑ �����ϴ�.
	Folder* fo1 = new Folder("A");
	Folder* fo2 = new Folder("B");

	fo1->add(f1);
	fo2->add(f2);
	root->add(f3);
	root->add(fo1);
	root->add(fo2);

	cout << f1->getSize() << endl;		// ������ ũ�⸦ ���� �� �ֽ��ϴ�.
	cout << root->getSize() << endl;	// ������ ũ�⸦ ���� �� �ֽ��ϴ�.
}

// ���� ��ü�� ���� ��ü�� ���Ͻ� �ϴ� �Լ���?
