// 4_����������_3 - 104p
#include <iostream>
#include <vector>
#include "ioacademy.h"
#include "IGraph.h"
using namespace std;
using namespace ioacademy;

class Subject
{
	vector<IGraph*> v;

public:
	Subject()
	{
		// ���� �����ϴ� �Լ�
		file::IoEnumFiles("C:\\PlugIn", "*.dll", LoadModule, this);
	}

	static int LoadModule(string name, void* param)
	{
		cout << name << endl;	// ã�� dll ���� �̸�
		
		void* addr = module::IoLoadModule(name);
		typedef IGraph* (*F)();
		F f = (F)IoGetFunctionAddress(addr, "CreateGraph");	// DLL���� �Լ� ã��
		IGraph* graph = f();			// CreateGraph()

		Subject* thisptr = (Subject*)param;
		thisptr->attach(graph);
		return 1;	// ��� ã����� �ǹ�
	}

	void attach(IGraph* p) { v.push_back(p); }
	void detach(IGraph* p) {}
	void notify(int n)
	{
		for (auto item : v)
			item->onUpdate(n);
	}
};

// ������ ���
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
			if (cin.rdstate())
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
