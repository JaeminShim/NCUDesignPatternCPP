// 5_menu - 86p

#include <iostream>
#include <string>
#include <conio.h>
#include <vector>
using namespace std;

// 복합객체는 개별객체 뿐 아니라 복합객체 자신도 보관한다.
// 복합객체와 개별객체는 동일 부모가 있어야 한다.

// 복합객체와 개별객체의 사용법이 동일시 되어야 한다.
// 동일시하는 함수(command)는 부모에 있어야 한다.

// "Composite pattern": 객체의 포함에 관련된 패턴


#define clrscr() system("cls");

// 모든 메뉴의 부모 메뉴
class BaseMenu
{
	string title;
public:
	BaseMenu(const string& s) : title(s) {}
	virtual ~BaseMenu() {}

	const string& getTitle() const { return title; }

	// 모든 메뉴는 선택될 수 있다. 구현은 자식이 해야 한다.
	virtual void command() = 0;
};

class MenuItem : public BaseMenu
{
	int id;
public:
	MenuItem(const string& s, int n) : BaseMenu(s), id(n) {}
	virtual ~MenuItem() {}

	virtual void command() override
	{
		cout << getTitle() << " 메뉴가 선택됨" << endl;
		_getch();
	}
};

class PopupMenu : public BaseMenu
{
	vector<BaseMenu*> v;	// 핵심!!!
public:
	PopupMenu(const string& s) : BaseMenu(s) {}
	virtual ~PopupMenu() {}

	void appendMenu(BaseMenu* p)
	{
		v.push_back(p);
	}

	virtual void command() override
	{
		while (true)
		{
			clrscr();

			int sz = v.size();
			for (int i = 0; i < sz; ++i)
				cout << i + 1 << ". " << v[i]->getTitle() << endl;
			cout << sz + 1 << ". 상위 메뉴로" << endl;

			cout << "메뉴를 선택하세요 >> " << endl;
			int cmd;
			cin >> cmd;

			// 선택한 메뉴를 실행한다. 어떻게 할까요?
			if (0 < cmd && cmd <= sz)
				v[cmd - 1]->command();	// 다형성
			else if (cmd == sz + 1)
				break;
		}
	}
};

int main()
{
	PopupMenu* menuBar = new PopupMenu("메뉴바");
	PopupMenu* p1 = new PopupMenu("고객관리");
	PopupMenu* p2 = new PopupMenu("Tape관리");

	menuBar->appendMenu(p1);
	menuBar->appendMenu(p2);

	p1->appendMenu(new MenuItem("고객 추가", 11));
	p1->appendMenu(new MenuItem("고객 삭제", 12));
	p2->appendMenu(new MenuItem("Tape 추가", 21));
	p2->appendMenu(new MenuItem("Tape 삭제", 22));

	menuBar->command();
}