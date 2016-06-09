#pragma once

// ��������� ������ �����Ϸ���
// ��� �������̽��� ��������� �־�� �Ѵ�.

// �پ��� proxy �������̽��� �θ� �������̽��� ��������.
struct IUnknown_	// COM �Ǵ� CORBA ������� �� �� �ִ� �������̽�
{					// (IUnknown�� MS COM�� �⺻ �������̽�)
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
