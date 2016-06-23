// 어제 소스중 - "메뉴" 복사해오세요
#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
using namespace std;

#define clrscr()  system("cls")   // 화면 지우기..

// 메뉴의 방문자를 만들어 봅시다.

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
		// 방문자에게 자신만 전달한다.
		p->visit(this);
	}



	MenuItem(string s, int n) : BaseMenu(s), id(n) {}

	virtual void command()
	{
		cout << getTitle() << " 메뉴 선택됨" << endl;
		_getch();
	}
};



// 이 디자인의 핵심은 아래 클래스 입니다.
class PopupMenu : public BaseMenu
{
	vector<BaseMenu*> v; // 핵심!!
public:
	PopupMenu(string s) : BaseMenu(s) {}


	void accept(IMenuVisitor* p)
	{
		// 방문자에게 자신만 전달한다.
		p->visit(this);

		for (int i = 0; i < v.size(); i++)
			v[i]->accept(p); // 포함하는 모든 메뉴에게 방문자를 전달한다.
	}



	void addMenu(BaseMenu* p) { v.push_back(p); }

	virtual void command()
	{
		while (1)
		{
			clrscr(); // 화면을 지우고
			int sz = v.size();
			for (int i = 0; i < sz; i++)
				cout << i + 1 << ". " << v[i]->getTitle() << endl;

			cout << sz + 1 << ". 상위 메뉴로" << endl;
			cout << "메뉴를 선택하세요 >> ";
			int cmd;
			cin >> cmd;


			if (cmd < 1 || cmd > sz + 1) // 잘못된 입력
				continue;

			if (cmd == sz + 1) // 상위 메뉴로 선택..
				break; // 또는 return .



			// 선택된 메뉴를 실행한다. 어떤 메뉴일지 조사할필요가 없다.!!핵심!!
			v[cmd - 1]->command(); // 다형성!!
		}
	}
};


//메뉴의 타이틀을 수정하는 방문자
class MenuTitleDecorator : public IMenuVisitor
{
public:
	virtual void visit(MenuItem* p) {} // MenuItem은 타이틀을 변경안함
	virtual void visit(PopupMenu* p)
	{
		string s = p->getTitle();
		s = s + " >> ";
		p->setTitle(s); // 타이틀을 수정한다.
	}
};


class MenuTitleDecorator2 : public IMenuVisitor
{
public:
	virtual void visit(MenuItem* p) {} // MenuItem은 타이틀을 변경안함
	virtual void visit(PopupMenu* p)
	{
		string s = p->getTitle();
		s = "[ " + s + " ]";
		p->setTitle(s); // 타이틀을 수정한다.
	}
};




int main()
{
	PopupMenu* menubar = new PopupMenu("MenuBar");

	PopupMenu* p1 = new PopupMenu("화면 설정");
	PopupMenu* p2 = new PopupMenu("소리 설정");

	menubar->addMenu(p1);
	//menubar->addMenu(p2);
	p1->addMenu(p2);

	p1->addMenu(new MenuItem("해상도 변경", 11));
	p1->addMenu(new MenuItem("색상   변경", 12));
	p1->addMenu(new MenuItem("명도   변경", 13));
	p2->addMenu(new MenuItem("크기   변경", 21));
	p2->addMenu(new MenuItem("음색   변경", 22));


	// 방문자가 방문하면 멤버 data가 수정되는 경우가 많다.
	// 캡슐화 관점에서는 좋지 않은 디자인 이다
	// setTitle()등의 함수가 필요하게 된다.
	MenuTitleDecorator2 mtd;	// 메뉴를 탐색하면서 팝업 메뉴의 타이틀을 꾸며주는 방문자
	menubar->accept(&mtd);


	// 이제 시작하려면 ??
	menubar->command();
}


