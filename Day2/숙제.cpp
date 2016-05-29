#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Object
{
	string name;

protected:
	void printTab(int depth) const
	{
		for (int i = 0; i < depth; ++i)
			cout << "    ";
	}

public:
	explicit Object(const string& s)
		: name(s)
	{
	}

	virtual ~Object()
	{
	}

	const string& getName() const
	{
		return name;
	}

	virtual bool contains(Object* object) const
	{
		return false;
	}

	virtual size_t getSize() const = 0;

	virtual void print(int depth = 0) const = 0;
};

class File : public Object
{
	int size;

public:
	File(const string& s, int isize)
		: Object(s), size(isize)
	{
	}

	virtual ~File()
	{
	}

	virtual size_t getSize() const override
	{
		return size;
	}

	virtual void print(int depth = 0) const override
	{
		printTab(depth);
		cout << getName() << " (" << getSize() << " bytes)" << endl;
	}
};

class Folder : public Object
{
	vector<Object*> objects;

public:
	Folder(const string& s)
		: Object(s)
	{
	}

	bool add(Object* pItem)
	{
		if (!pItem)
			return false;
		if (pItem == this)
			return false;
		if (contains(pItem))
			return false;
		objects.push_back(pItem);
		return true;
	}

	virtual bool contains(Object* object) const
	{
		for (const Object* obj : objects)
		{
			if (obj == object || obj->contains(object))
				return true;
		}
		return false;
	}

	virtual size_t getSize() const override
	{
		size_t size = 0;
		for (const Object* obj : objects)
			size += obj->getSize();
		return size;
	}

	virtual void print(int depth = 0) const override
	{
		printTab(depth);
		cout << "[" << getName() << "]" << endl;
		for (const Object* obj : objects)
			obj->print(depth + 1);
	}
};

int main()
{
	File* file1 = new File("a.txt", 10);	// ������ �ڽ��� ũ�Ⱑ �ֽ��ϴ�.
	File* file2 = new File("b.txt", 20);
	File* file3 = new File("c.txt", 30);

	Folder* root = new Folder("ROOT");		// ������ �ڽ��� ũ�Ⱑ �����ϴ�.
	Folder* folder1 = new Folder("A");
	Folder* folder2 = new Folder("B");

	folder1->add(file1);
	folder2->add(file2);
	root->add(file3);
	root->add(folder1);
	root->add(folder2);

	cout << file1->getSize() << endl;		// ������ ũ�⸦ ���� �� �ֽ��ϴ�.
	cout << root->getSize() << endl;		// ������ ũ�⸦ ���� �� �ֽ��ϴ�.

	// print hierarchy
	cout << endl;
	root->print();
}

// ���� ��ü�� ���� ��ü�� ���Ͻ� �ϴ� �Լ���?: getSize()
