// 2_proxy
#include <iostream>
#include "ioacademy.h"
using namespace std;
using namespace ioacademy;

// client �����ڴ� ���� �����ڿ��Լ� 2�� ������ �ް� �˴ϴ�.
// CalcProxy.dll
// ICalc.h

#include "ICalc.h"

ICalc* LoadProxy()
{
	void* addr = IoLoadModule("CalcProxy.dll");
	typedef ICalc*(*F)();
	F f = (F)IoGetFunctionAddress(addr, "CreateCalcProxy");
	ICalc* pCalc = f();
	return pCalc;
}

// ��ü ������ ���� ����� �ڵ����� �����ϴ� ����Ʈ ������
template <typename T> class sp
{
	T* obj;
public:
	sp(T* p = 0)	: obj(p)		{ obj->AddRef(); }
	sp(const sp& s)	: obj(s.obj)	{ obj->AddRef(); }
	~sp()							{ obj->Release(); }

	// ����Ʈ ������ �⺻: ->�� *
	T* operator->() { return obj; }
	T& operator*() { return *obj; }
};

int main()
{
	/*ICalc* pCalc = LoadProxy();
	pCalc->AddRef();
	cout << pCalc->Add(1, 2) << endl;
	pCalc->Release();*/

	sp<ICalc> pCalc(LoadProxy()); // sp<>: DirectX�� CComPtr<> �� ����
	cout << pCalc->Add(1, 2) << endl;
}