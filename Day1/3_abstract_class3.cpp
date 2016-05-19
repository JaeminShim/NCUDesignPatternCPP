// 3_abstract_class3	// 58p

#include <iostream>

using namespace std;

// ī�޶� �����ڿ� ī�޶� ����� ���̿�
// ���Ѿ� �ϴ� ��Ģ(���, �������̽�)�� ���� ������.

// ��Ģ: "��� ī�޶�� �Ʒ� Ŭ�����κ��� �Ļ��Ǿ�� �Ѵ�." (�ܼ� ����� ����)
//   =>  "��� ī�޶�� �Ʒ� �������̽��� �����ؾ� �Ѵ�." ��� ǥ������.

#define interface struct
interface ICamera
{
	virtual void Take() = 0;
};

// ���� ī�޶�� ������ ��Ģ�� �ִ�.
// ����ڴ� ��Ģ��θ� ����ϸ� �ȴ�.
class People
{
public:
	void UseCamera(ICamera* p) { p->Take(); }
};

// ��� ī�޶� �����ڴ� ��Ģ�� ���Ѿ� �Ѵ�.
class Camera : public ICamera
{
public:
	virtual void Take() override
	{
		cout << "Take a picture with a camera." << endl;
	}
};

class Camera2 : public ICamera
{
public:
	virtual void Take() override
	{
		cout << "Take a picture with a camera2." << endl;
	}
};

int main()
{
	People p;

	Camera c1;
	p.UseCamera(&c1);

	Camera2 c2;
	p.UseCamera(&c2);
}