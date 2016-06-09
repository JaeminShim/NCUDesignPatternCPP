#pragma once

// 참조계수로 수명을 관리하려면
// 모든 인터페이스에 참조계수가 있어야 한다.

// 다양한 proxy 인터페이스의 부모 인터페이스를 설계하자.
struct IUnknown_	// COM 또는 CORBA 기술에서 볼 수 있는 인터페이스
{					// (IUnknown은 MS COM의 기본 인터페이스)
	virtual void AddRef() = 0;
	virtual void Release() = 0;
	virtual ~IUnknown_() {}
};

struct ICalc : IUnknown_
{
	virtual int Add(int a, int b) = 0;
	virtual int Sub(int a, int b) = 0;
	virtual ~ICalc() {};
};
