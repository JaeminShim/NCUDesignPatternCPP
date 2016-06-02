// SampleGraph.cpp
// 4_observer3.cpp�� ������ ���� DLL�� ������ ����

#include <iostream>
using namespace std;

#include "IGraph.h"

class SampleGraph : public IGraph
{
	virtual void onUpdate(int n) override
	{
		cout << "**** SampleGraph ****" << endl;
		cout << "data: " << n << endl;
		cout << "*********************" << endl;
	}
};

// SampleGraph��� �̸��� DLL�� ���� ����� �˰� �ֽ��ϴ�.
// DLL�� ����ϴ� ����� �𸣹Ƿ� ��ü�� DLL���� ������ �մϴ�.
// ��ü�� ����� �Լ��� ����ؾ� �մϴ�.

extern "C" __declspec(dllexport)	// dll ���� �� �� �ʿ��� ����
IGraph* CreateGraph()
{
	return new SampleGraph();
}