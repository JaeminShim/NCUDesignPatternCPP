// 4_관찰자패턴_3 - 104p
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
		// 파일 열거하는 함수
		file::IoEnumFiles("C:\\PlugIn", "*.dll", LoadModule, this);
	}

	static int LoadModule(string name, void* param)
	{
		cout << name << endl;	// 찾은 dll 파일 이름
		
		void* addr = module::IoLoadModule(name);
		typedef IGraph* (*F)();
		F f = (F)IoGetFunctionAddress(addr, "CreateGraph");	// DLL에서 함수 찾기
		IGraph* graph = f();			// CreateGraph()

		Subject* thisptr = (Subject*)param;
		thisptr->attach(graph);
		return 1;	// 계속 찾으라는 의미
	}

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
			if (cin.rdstate())
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
