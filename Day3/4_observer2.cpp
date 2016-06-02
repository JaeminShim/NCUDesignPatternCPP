// 4_관찰자패턴 - 137p
#include <iostream>
#include <vector>
using namespace std;

// 모든 그래프의 인터페이스
struct IGraph
{
	virtual void onUpdate(int n) = 0;
	virtual ~IGraph() {}
};

// Table의 data가 변경되어도 관찰자 패턴의 기본 로직은 변하지 않는다.
// 관찰자패턴의 기본 로직을 제공하는 부모를 만들자

// 변하는 것: 가상 함수로자식이 재정의 하도록
// 변하지 않는 것: 부모 클래스로 제공

class Subject
{
	vector<IGraph*> v;

public:
	void attach(IGraph* p) { v.push_back(p); }
	void detach(IGraph* p) {}
	void notify(int n)
	{
		for (auto item : v)
			item->onUpdate(n);
	}
};



// 관찰의 대상
class Table : public Subject
{
	int data;

public:
	void edit()
	{
		while (1)
		{
			cout << "data >> ";
			cin >> data;
			if (cin.rdstate() == ios_base::failbit)
				break;
			notify(data);
		}
	}
};

// 다양한 그래프를 설계한다.
class PieGraph : public IGraph
{
	virtual void onUpdate(int n) override
	{
		cout << "**** PieGraph ****" << endl;
		cout << "data: " << n << endl;
		cout << "******************" << endl;
	}
};

class BarGraph : public IGraph
{
	virtual void onUpdate(int n) override
	{
		cout << "**** BarGraph ****" << endl;
		cout << "data: " << n << endl;
		cout << "******************" << endl;
	}
};

int main()
{
	Table table;
	PieGraph pg; table.attach(&pg);
	BarGraph bg; table.attach(&bg);
	table.edit();
}
