// SampleGraph.cpp
// 4_observer3.cpp와 연결을 위해 DLL로 빌드할 것임

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

// SampleGraph라는 이름은 DLL을 만든 사람만 알고 있습니다.
// DLL을 사용하는 사람은 모르므로 객체는 DLL에서 만들어야 합니다.
// 객체를 만드는 함수를 약속해야 합니다.

extern "C" __declspec(dllexport)	// dll 만들 때 꼭 필요한 내용
IGraph* CreateGraph()
{
	return new SampleGraph();
}