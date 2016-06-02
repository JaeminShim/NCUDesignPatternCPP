// 4_����������
#include <iostream>
#include <vector>
using namespace std;

// ��� �׷����� �������̽�
struct IGraph
{
	virtual void onUpdate(int n) = 0;
	virtual ~IGraph() {}
};

// ������ ���
class Table
{
	vector<IGraph*> v;

public:
	void attach(IGraph* p) { v.push_back(p); }
	void detach(IGraph* p) {}
	void notify(int data)
	{
		for (auto item : v)
			item->onUpdate(data);
	}

	void edit()
	{
		while (1)
		{
			int data;
			cout << "data >> ";
			cin >> data;
			if (cin.rdstate() == ios_base::failbit)
				break;
			notify(data);
		}
	}
};

// �پ��� �׷����� �����Ѵ�.
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
