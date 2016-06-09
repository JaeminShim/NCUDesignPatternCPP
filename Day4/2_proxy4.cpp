// 2_proxy
#include <iostream>
#include "ioacademy.h"
using namespace std;
using namespace ioacademy;

// client 제작자는 서버 제작자에게서 2개 파일을 받게 됩니다.
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

// 객체 내부의 참조 계수를 자동으로 관리하는 스마트 포인터
template <typename T> class sp
{
	T* obj;
public:
	sp(T* p = 0)	: obj(p)		{ obj->AddRef(); }
	sp(const sp& s)	: obj(s.obj)	{ obj->AddRef(); }
	~sp()							{ obj->Release(); }

	// 스마트 포인터 기본: ->와 *
	T* operator->() { return obj; }
	T& operator*() { return *obj; }
};

int main()
{
	/*ICalc* pCalc = LoadProxy();
	pCalc->AddRef();
	cout << pCalc->Add(1, 2) << endl;
	pCalc->Release();*/

	sp<ICalc> pCalc(LoadProxy()); // sp<>: DirectX의 CComPtr<> 과 동일
	cout << pCalc->Add(1, 2) << endl;
}