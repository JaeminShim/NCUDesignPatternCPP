// ���� �ҽ��� - "�޴�" �����ؿ�����
#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
using namespace std;

#define clrscr()  system("cls")   // ȭ�� �����..

// �޴��� �湮�ڸ� ����� ���ô�.

class PopupMenu;
class MenuItem;

struct IMenuVisitor
{
	virtual void visit(PopupMenu* p) = 0;
	virtual void visit(MenuItem * p) = 0;
	virtual ~IMenuVisitor() {}
};

struct IAcceptor
{
	virtual void accept(IMenuVisitor* p) = 0;
	virtual ~IAcceptor() {}
};





class BaseMenu : public IAcceptor
{
	string title;
public:
	BaseMenu(string s) : title(s) {}

	string getTitle() { return title; }

	void setTitle(string s) { title = s; }
	
	virtual void command() = 0;

};
//---------------------------------

class MenuItem : public BaseMenu
{
	int id;
public:

	void accept(IMenuVisitor* p)
	{
		// �湮�ڿ��� �ڽŸ� �����Ѵ�.
		p->visit(this);
	}



	MenuItem(string s, int n) : BaseMenu(s), id(n) {}

	virtual void command()
	{
		cout << getTitle() << " �޴� ���õ�" << endl;
		_getch();
	}
};



// �� �������� �ٽ��� �Ʒ� Ŭ���� �Դϴ�.
class PopupMenu : public BaseMenu
{
	vector<BaseMenu*> v; // �ٽ�!!
public:
	PopupMenu(string s) : BaseMenu(s) {}


	void accept(IMenuVisitor* p)
	{
		// �湮�ڿ��� �ڽŸ� �����Ѵ�.
		p->visit(this);

		for (int i = 0; i < v.size(); i++)
			v[i]->accept(p); // �����ϴ� ��� �޴����� �湮�ڸ� �����Ѵ�.
	}



	void addMenu(BaseMenu* p) { v.push_back(p); }

	virtual void command()
	{
		while (1)
		{
			clrscr(); // ȭ���� �����
			int sz = v.size();
			for (int i = 0; i < sz; i++)
				cout << i + 1 << ". " << v[i]->getTitle() << endl;

			cout << sz + 1 << ". ���� �޴���" << endl;
			cout << "�޴��� �����ϼ��� >> ";
			int cmd;
			cin >> cmd;


			if (cmd < 1 || cmd > sz + 1) // �߸��� �Է�
				continue;

			if (cmd == sz + 1) // ���� �޴��� ����..
				break; // �Ǵ� return .



			// ���õ� �޴��� �����Ѵ�. � �޴����� �������ʿ䰡 ����.!!�ٽ�!!
			v[cmd - 1]->command(); // ������!!
		}
	}
};


//�޴��� Ÿ��Ʋ�� �����ϴ� �湮��
class MenuTitleDecorator : public IMenuVisitor
{
public:
	virtual void visit(MenuItem* p) {} // MenuItem�� Ÿ��Ʋ�� �������
	virtual void visit(PopupMenu* p)
	{
		string s = p->getTitle();
		s = s + " >> ";
		p->setTitle(s); // Ÿ��Ʋ�� �����Ѵ�.
	}
};


class MenuTitleDecorator2 : public IMenuVisitor
{
public:
	virtual void visit(MenuItem* p) {} // MenuItem�� Ÿ��Ʋ�� �������
	virtual void visit(PopupMenu* p)
	{
		string s = p->getTitle();
		s = "[ " + s + " ]";
		p->setTitle(s); // Ÿ��Ʋ�� �����Ѵ�.
	}
};




int main()
{
	PopupMenu* menubar = new PopupMenu("MenuBar");

	PopupMenu* p1 = new PopupMenu("ȭ�� ����");
	PopupMenu* p2 = new PopupMenu("�Ҹ� ����");

	menubar->addMenu(p1);
	//menubar->addMenu(p2);
	p1->addMenu(p2);

	p1->addMenu(new MenuItem("�ػ� ����", 11));
	p1->addMenu(new MenuItem("����   ����", 12));
	p1->addMenu(new MenuItem("��   ����", 13));
	p2->addMenu(new MenuItem("ũ��   ����", 21));
	p2->addMenu(new MenuItem("����   ����", 22));


	// �湮�ڰ� �湮�ϸ� ��� data�� �����Ǵ� ��찡 ����.
	// ĸ��ȭ ���������� ���� ���� ������ �̴�
	// setTitle()���� �Լ��� �ʿ��ϰ� �ȴ�.
	MenuTitleDecorator2 mtd;	// �޴��� Ž���ϸ鼭 �˾� �޴��� Ÿ��Ʋ�� �ٸ��ִ� �湮��
	menubar->accept(&mtd);


	// ���� �����Ϸ��� ??
	menubar->command();
}


